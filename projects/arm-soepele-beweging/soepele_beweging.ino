// ============================================================================
//  soepele_beweging.ino  --  vloeiende, beheerste bewegingen voor de 6-servo arm
//  Onderdeel van: curious-research / projects/arm-soepele-beweging
// ----------------------------------------------------------------------------
//  WAT DIT OPLOST
//  Een hobbyservo heeft GEEN snelheidsingang. Er is geen manier om hem te
//  vertellen "ga langzaam". Als je schrijft:
//
//      servo.write(140);
//
//  dan betekent dat: "sta NU op 140 graden". De servo geeft vol gas, knalt
//  ernaartoe, en staat stil. Vandaar het schokkerige, plotselinge gedrag: de
//  arm heeft maar twee snelheden -- vol gas en stilstand.
//
//  De truc is dus niet een instelling die je aanzet. Het is: JIJ stuurt een
//  reeks doelen die steeds een klein stukje verder liggen, netjes verdeeld
//  over de tijd. De servo jaagt telkens een doel na dat vlakbij is, en dan
//  beweegt hij rustig. De vloeiendheid zit in JOUW code, niet in de servo.
//
//  Deze sketch doet drie dingen bovenop dat basisidee:
//
//    1. SOEPEL OPTREKKEN EN AFREMMEN (het belangrijkste).
//       Verdeel je een beweging in gelijke stapjes, dan gaat de snelheid in
//       een klap van 0 naar vol aan het begin, en van vol naar 0 aan het eind.
//       Dat schokje aan de uiteinden voel en zie je -- de arm "tikt" aan bij
//       start en stop. We rekenen daarom niet lineair, maar met een S-bocht:
//       traag beginnen, versnellen, en weer afremmen naar het doel.
//
//    2. GELIJKTIJDIG AANKOMEN. Alle gewrichten krijgen DEZELFDE looptijd. Het
//       gewricht dat het verst moet bepaalt hoe lang de hele beweging duurt;
//       de rest doet rustiger aan. Anders is de ene servo al klaar terwijl de
//       andere nog loopt, en dat ziet er hakkelig uit ook al is elke servo op
//       zichzelf soepel.
//
//    3. EEN SNELHEIDSLIMIET die je in graden per seconde opgeeft, niet in
//       "hoeveel milliseconden per stapje". Zo blijft een korte beweging even
//       rustig aanvoelen als een lange.
//
// ----------------------------------------------------------------------------
//  VEILIGHEID -- dit zijn regels, geen adviezen (zie CLAUDE.md sectie 2)
//
//    * VUL EERST DE GRENZEN IN. Hieronder staat JOINT_MIN / JOINT_MAX. Zolang
//      daar niet JOUW opgemeten waarden staan, laat deze sketch de arm met
//      opzet nauwelijks bewegen -- zie de opmerking bij die tabel. Elke hoek
//      die naar een servo gaat loopt door clampDegrees(). Er is geen andere
//      weg naar een servo toe tijdens de normale bewegingsroute. Dit begrenst
//      hoekgetallen; het detecteert geen botsingen en bewijst niet dat de
//      startupstand veilig is.
//      Opmeten: guides/arm-werkgebied/guide.md
//
//    * SERVOVOEDING IS EEN APARTE VOEDING, met gedeelde massa, een zekering en
//      een schakelaar die je kunt bereiken. NOOIT de 5V-pin van de Arduino.
//      De gecombineerde piek- en blokkeerstroom is voor deze arm nog niet
//      geverifieerd. Stel de exacte servovariant vast, controleer de primaire
//      specificatie en meet onder begeleide belasting; neem geen generieke
//      "MG996R"-waarde als voedingsontwerp over.
//
//    * ER KIJKT ALTIJD IEMAND MEE, met de hand bij de schakelaar. Niets hier is
//      ooit "veilig als je even weg bent". Eerst stroom eraf, dan pas kijken
//      wat er misging.
// ============================================================================

#include <Servo.h>

// ---------------------------------------------------------------------------
//  1 - JOUW ARM. Pas deze drie tabellen aan en verder niets.
// ---------------------------------------------------------------------------

const int JOINT_COUNT = 6;

// LEGACY PLACEHOLDERS: bord, pinondersteuning en fysieke volgorde zijn nog niet
// op de echte arm bevestigd. Niet bekrachtigen voordat deze mapping klopt.
const int SERVO_PIN[JOINT_COUNT] = { 3, 5, 6, 9, 10, 11 };

// Ook deze namen zijn schema-aannames; bevestig de zes fysieke actuatoren.
const char* JOINT_NAME[JOINT_COUNT] = {
  "basis", "schouder", "elleboog", "pols_kantel", "pols_draai", "grijper"
};

// ---------------------------------------------------------------------------
//  DE GRENZEN. Dit is het belangrijkste blok in het hele bestand.
//
//  De waarden 85/95 zijn alleen placeholders rond een onbevestigde 90 graden.
//  Ze beperken de grootte van de testbeweging, maar maken die stand NIET veilig
//  voor deze montage. Koppel geen servovoeding aan voordat min, max en home per
//  gewricht op de echte arm zijn gecontroleerd.
//
//  Vervang ze door je eigen opgemeten waarden (guides/arm-werkgebied/)
//  en de normale route gebruikt dat gemeten numerieke bereik. Meet met marge: blijf een paar
//  graden weg van waar het gewricht mechanisch klem loopt.
// ---------------------------------------------------------------------------
const int JOINT_MIN[JOINT_COUNT] = { 85, 85, 85, 85, 85, 85 };
const int JOINT_MAX[JOINT_COUNT] = { 95, 95, 95, 95, 95, 95 };

// De startupstand waar de arm direct na attach() naartoe wordt gestuurd.
// 90 graden is een PLACEHOLDER en niet als veilige gezamenlijke stand bewezen.
const int JOINT_HOME[JOINT_COUNT] = { 90, 90, 90, 90, 90, 90 };

// ---------------------------------------------------------------------------
//  2 - DE KNOPPEN OM AAN TE DRAAIEN. Hier zit het plezier.
// ---------------------------------------------------------------------------

// Hoe snel mag het snelste gewricht maximaal? In graden per seconde.
// De getallen hieronder zijn experimentele softwarewaarden, niet de gemeten
// snelheid van deze arm. Begin laag na een gecontroleerde startup.
float maxSnelheid = 60.0;

// Begininterval voor nieuwe doelhoeken. De Arduino Servo-library ververst rond
// 20 ms; de werkelijke mechanische respons van deze servo's moet worden gemeten.
const unsigned long UPDATE_MS = 20;   // 20 ms = 50 Hz

// Zet dit op false om te zien wat de S-bocht nou eigenlijk doet: dan wordt er
// lineair gerekend (gelijke stapjes) en voel je het schokje aan begin en eind
// terug. Aan- en uitzetten en het verschil bekijken is het hele experiment.
bool gebruikSbocht = true;

// ---------------------------------------------------------------------------
//  3 - VANAF HIER HOEF JE NIETS MEER AAN TE PASSEN.
// ---------------------------------------------------------------------------

Servo servo[JOINT_COUNT];

float startHoek[JOINT_COUNT];    // waar de beweging begon
float doelHoek[JOINT_COUNT];     // waar hij heen gaat
float huidigeHoek[JOINT_COUNT];  // wat er als laatste verstuurd is

unsigned long bewegingStart = 0; // millis() toen de beweging begon
unsigned long bewegingDuur  = 0; // hoe lang de hele beweging mag duren, in ms
bool          bezig         = false;
unsigned long laatsteUpdate = 0;

// ---------------------------------------------------------------------------
//  DE CLAMP. Elke hoek die naar een servo gaat komt hier eerst langs.
//  clampDegrees(200, 20, 120) -> 120. Een te groot getal wordt teruggeknipt
//  naar de gemeten numerieke rand. Dit ziet geen obstakels of startupbeweging.
// ---------------------------------------------------------------------------
int clampDegrees(float waarde, int laag, int hoog) {
  int afgerond = (int)(waarde + 0.5);      // netjes afronden, niet afkappen
  if (afgerond < laag) return laag;
  if (afgerond > hoog) return hoog;
  return afgerond;
}

// ---------------------------------------------------------------------------
//  DE S-BOCHT.  smoothstep: 3t^2 - 2t^3
//
//  Je stopt er de voortgang in als getal van 0 tot 1 (0 = net begonnen,
//  1 = klaar) en er komt een voortgang uit die traag start, in het midden
//  versnelt, en weer afremt.
//
//      t (de tijd)     0    0.25   0.5   0.75    1
//      lineair         0    0.25   0.5   0.75    1     <- gelijke stapjes
//      s-bocht         0    0.16   0.5   0.84    1     <- traag, snel, traag
//
//  Het verschil in POSITIE lijkt klein. Het verschil in SNELHEID is het punt:
//  lineair begin je meteen op volle snelheid, met de s-bocht bouw je die op.
//  Precies dat opbouwen is wat "schokkerig" verandert in "beheerst".
//
//  Wil je nog zachter? Probeer smootherstep: 6t^5 - 15t^4 + 10t^3. Die begint
//  en eindigt nog vlakker. Een regel code, meteen te voelen -- probeer maar.
// ---------------------------------------------------------------------------
float sBocht(float t) {
  if (t <= 0.0) return 0.0;
  if (t >= 1.0) return 1.0;
  return t * t * (3.0 - 2.0 * t);
}

// ---------------------------------------------------------------------------
//  Een nieuwe beweging plannen. Zet alleen doelen klaar -- er beweegt hier nog
//  niets. Het bewegen zelf gebeurt beetje bij beetje in werkBeweging().
// ---------------------------------------------------------------------------
void beweegNaar(const int doelen[JOINT_COUNT]) {
  float grootsteAfstand = 0.0;

  for (int i = 0; i < JOINT_COUNT; i++) {
    startHoek[i] = huidigeHoek[i];
    // Meteen clampen: dan klopt de looptijd met wat er ECHT gaat bewegen.
    doelHoek[i]  = clampDegrees(doelen[i], JOINT_MIN[i], JOINT_MAX[i]);

    float afstand = fabs(doelHoek[i] - startHoek[i]);
    if (afstand > grootsteAfstand) grootsteAfstand = afstand;
  }

  // Het gewricht dat het verst moet bepaalt de looptijd. Alle andere krijgen
  // dezelfde tijd, dus ze komen samen aan.
  //     tijd (s) = afstand (graden) / snelheid (graden per seconde)
  bewegingDuur = (unsigned long)((grootsteAfstand / maxSnelheid) * 1000.0);

  if (bewegingDuur < UPDATE_MS) bewegingDuur = UPDATE_MS;  // nooit door nul
  bewegingStart = millis();
  bezig = true;
}

// ---------------------------------------------------------------------------
//  Eén stapje van de lopende beweging. Deze functie blokkeert NIET: hij kijkt
//  hoe laat het is, rekent uit waar de arm nu hoort te staan, stuurt dat, en
//  geeft de besturing terug. Daardoor kan loop() ondertussen ook nog naar
//  knoppen of de seriële poort luisteren -- iets wat met delay() niet kan.
// ---------------------------------------------------------------------------
void werkBeweging() {
  if (!bezig) return;

  unsigned long nu = millis();
  if (nu - laatsteUpdate < UPDATE_MS) return;   // nog te vroeg, servo luistert toch niet
  laatsteUpdate = nu;

  float t = (float)(nu - bewegingStart) / (float)bewegingDuur;
  if (t > 1.0) t = 1.0;

  float voortgang = gebruikSbocht ? sBocht(t) : t;

  for (int i = 0; i < JOINT_COUNT; i++) {
    float hoek = startHoek[i] + (doelHoek[i] - startHoek[i]) * voortgang;
    huidigeHoek[i] = hoek;
    servo[i].write(clampDegrees(hoek, JOINT_MIN[i], JOINT_MAX[i]));  // ENIGE weg naar de servo
  }

  if (t >= 1.0) {
    bezig = false;
    Serial.println(F("beweging klaar"));
  }
}

// ---------------------------------------------------------------------------
//  Een klein rondje om het verschil te kunnen zien. Steeds van de ene kant van
//  het toegestane bereik naar de andere en terug.
// ---------------------------------------------------------------------------
int stapInRondje = 0;

void volgendeStap() {
  int doelen[JOINT_COUNT];

  for (int i = 0; i < JOINT_COUNT; i++) {
    // Blijf 10% van de randen weg: de grens is de grens, daar wil je niet
    // tegenaan tikken bij elke herhaling.
    float marge = (JOINT_MAX[i] - JOINT_MIN[i]) * 0.10;
    doelen[i] = (stapInRondje % 2 == 0) ? (JOINT_MIN[i] + marge)
                                        : (JOINT_MAX[i] - marge);
  }

  Serial.print(F("naar stand "));
  Serial.print(stapInRondje % 2 == 0 ? F("A") : F("B"));
  Serial.print(F("  (snelheid "));
  Serial.print(maxSnelheid, 0);
  Serial.print(F(" gr/s, s-bocht "));
  Serial.print(gebruikSbocht ? F("aan") : F("uit"));
  Serial.println(F(")"));

  beweegNaar(doelen);
  stapInRondje++;
}

// ---------------------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  while (!Serial && millis() < 3000) { /* wacht kort op de USB-verbinding */ }

  Serial.println(F("soepele_beweging -- vloeiende bewegingen voor de arm"));

  bool grenzenIngevuld = false;
  for (int i = 0; i < JOINT_COUNT; i++) {
    if (JOINT_MAX[i] - JOINT_MIN[i] > 20) grenzenIngevuld = true;
  }
  if (!grenzenIngevuld) {
    Serial.println(F("LET OP: de grenzen staan nog op ONBEVESTIGDE placeholders."));
    Serial.println(F("De beweging is klein, maar 90 graden is niet bewezen veilig."));
    Serial.println(F("Meet je eigen bereik op: guides/arm-werkgebied/"));
  }

  Serial.println(F("STARTUP: servo's worden nu gekoppeld en naar JOINT_HOME gestuurd."));
  Serial.println(F("JOINT_HOME moet vooraf op deze echte arm zijn gecontroleerd."));
  for (int i = 0; i < JOINT_COUNT; i++) {
    servo[i].attach(SERVO_PIN[i]);
    huidigeHoek[i] = clampDegrees(JOINT_HOME[i], JOINT_MIN[i], JOINT_MAX[i]);
    servo[i].write((int)huidigeHoek[i]);
  }

  delay(600);          // even laten zakken naar de ruststand voor we beginnen
  volgendeStap();
}

void loop() {
  werkBeweging();

  // Beweging klaar? Even wachten en dan de andere kant op.
  if (!bezig) {
    static unsigned long klaarSinds = 0;
    if (klaarSinds == 0) klaarSinds = millis();
    if (millis() - klaarSinds > 800) {
      klaarSinds = 0;
      volgendeStap();
    }
  }
}
