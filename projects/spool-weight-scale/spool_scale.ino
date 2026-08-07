// ============================================================================
//  spool_scale.ino  --  experimentele filamentweger
//  Part of: curious-research / projects/spool-weight-scale
// ----------------------------------------------------------------------------
//  WHAT THIS IS
//  Een loadcell wordt via een HX711 door een Arduino uitgelezen. Na kalibratie
//  en aftrek van het ZELF GEMETEN lege-spoelgewicht volgt een schatting van de
//  resterende massa. Resolutie, drift en bruikbare marge zijn geen vaste
//  getallen: meet ze op de eigen constructie met README.md en meetlog.md.
//
//  Bench words (one line each):
//    load cell    = a metal bar with a strain gauge inside that bends a tiny,
//                   measurable amount under weight.
//    HX711        = the amplifier + analog-to-digital chip that turns the load
//                   cell's microscopic voltage change into a number.
//    calibration  = the one-time "weigh a known mass" step that turns raw
//                   counts into real grams (the calibration factor).
//    tare         = subtracting a known weight (the empty spool) so the reading
//                   is filament-only.
//
// ----------------------------------------------------------------------------
//  YOU NEED ONE LIBRARY (two more for Stage 3). In the Arduino IDE:
//    Sketch > Include Library > Manage Libraries...  then search & Install:
//      * "HX711_ADC" by Olav Kallhovd    (used by all three stages)
//    For Stage 3 (the OLED screen) also install:
//      * "Adafruit SSD1306" by Adafruit  (click "Install All" if it offers deps)
//      * "Adafruit GFX Library" by Adafruit
//
// ----------------------------------------------------------------------------
//  BEDRADING. Controleer eerst de toegestane spanning van bord, HX711-module
//  en optioneel OLED. Werk spanningsloos; de volledige route staat in README.
//
//    LOADCELLFUNCTIE -> HX711 (kleur volgt ALLEEN uit het eigen datablad):
//        excitatie+ -> E+        excitatie- -> E-
//        signaal+   -> A+        signaal-   -> A-
//    HX711 board -> Arduino:
//        VCC -> bevestigde bordspanning     GND -> GND
//        DT  -> pin 4  (data)      SCK -> pin 5  (clock)
//    STAGE 3 EXTRAS:
//        Read button: one leg -> pin 6, other leg -> GND (uses the chip's
//                     built-in pull-up; no resistor needed)
//        SSD1306 OLED (I2C): gebruik voedingsspanning, SDA/SCL en adres uit de
//                     documentatie van het concrete bord en de module.
//
//    MONTAGE: volg de pijl en montagetekening van het concrete loadcellmodel.
//    Een single-ended beam heeft vaak een vaste en belastbare zijde, maar dat
//    is geen universele regel voor ieder celtype. Voorkom torsie, nevencontact,
//    overbelasting en te hoog aanhaalmoment.
// ============================================================================

// ---------------------------------------------------------------------------
//  PICK YOUR STAGE  --  change this ONE number, re-upload, watch what happens.
//    1 = CALIBRATE       : find your calibration factor with a known weight.
//    2 = GRAMS REMAINING : report total - saved empty-spool weight, in Serial.
//    3 = OLED STANDALONE  : press the button to show grams on the little screen.
// ---------------------------------------------------------------------------
#define STAGE 1

#include <HX711_ADC.h>
#if STAGE == 3
  #include <Wire.h>
  #include <Adafruit_GFX.h>
  #include <Adafruit_SSD1306.h>
#endif

// ---------------------------------------------------------------------------
//  YOUR CALIBRATION FACTOR
//  Stage 1 prints this number for you. Copy the value it gives into the line
//  below, then Stages 2 and 3 report real grams. (Starts at 1.0 = uncalibrated.)
// ---------------------------------------------------------------------------
float calibrationFactor = 1.0;   // <-- paste YOUR Stage-1 number here

// ---------------------------------------------------------------------------
//  YOUR KNOWN WEIGHT (Stage 1 only)
//  De onafhankelijk vastgestelde massa, in gram, van het kalibratievoorwerp.
//  Neem inhoud of een etiket niet automatisch als exacte totale massa over.
// ---------------------------------------------------------------------------
float knownMassGrams = 0.0;     // <-- vul jouw onafhankelijk bekende massa in

// ---------------------------------------------------------------------------
//  YOUR SPOOL LIBRARY  (Stages 2 and 3)
//  grams-remaining = total-on-scale  -  this spool's EMPTY weight.
//  Het leeggewicht is werkplaatsspecifiek. WEEG IEDERE ECHTE SPOEL LEEG en vul
//  alleen eigen metingen in. Er staan bewust geen merk- of cataloguswaarden in.
// ---------------------------------------------------------------------------
struct Spool {
  const char* name;       // shows in the Serial Monitor / on the OLED
  float       emptyGrams; // this spool's weight with NO filament on it
};

Spool spoolLibrary[] = {
  { "SPOEL 1 - zelf meten", 0.0 },
  { "SPOEL 2 - zelf meten", 0.0 },
  { "SPOEL 3 - zelf meten", 0.0 },
};

const unsigned int SPOOL_COUNT = sizeof(spoolLibrary) / sizeof(spoolLibrary[0]);

// Which spool from the list above is on the scale right now (0 = your own).
#define ACTIVE_SPOOL 0

// ---------------------------------------------------------------------------
//  PINS  (match the wiring comment at the top)
// ---------------------------------------------------------------------------
const int HX711_dout  = 4;
const int HX711_sck   = 5;
const int READ_BUTTON = 6;   // Stage 3 only

HX711_ADC LoadCell(HX711_dout, HX711_sck);

#if STAGE == 3
  #define SCREEN_WIDTH  128
  #define SCREEN_HEIGHT 64
  #define OLED_ADDR     0x3C   // voorbeeldwaarde: bevestig met datasheet of I2C-scan
  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
#endif

// ===========================================================================
//  SETUP
// ===========================================================================
void setup() {
  Serial.begin(57600);
  delay(300);
  Serial.println();
  Serial.println("filamentweger -- startup");

  LoadCell.begin();
  // Let the cell settle, and tare (zero) it with NOTHING on the platform.
  unsigned long stabilizingTime = 2000;  // ms to let the reading settle
  boolean doTare = true;                 // zero the empty platform at startup
  LoadCell.start(stabilizingTime, doTare);

  if (LoadCell.getTareTimeoutFlag() || LoadCell.getSignalTimeoutFlag()) {
    Serial.println("FOUT: HX711 reageert niet. Controleer DOUT/DT, SCK en de pinmapping.");
    while (true) { }   // stop here -- nothing works until the wiring is fixed
  }

  LoadCell.setCalFactor(calibrationFactor);
  Serial.println("Startup klaar. Houd het platform leeg totdat om massa wordt gevraagd.");

#if STAGE == 2 || STAGE == 3
  if (calibrationFactor == 1.0) {
    Serial.println("FOUT: calibrationFactor staat nog op de onbevestigde standaardwaarde 1.0.");
    Serial.println("Voer eerst fase 1 uit en vul de gemeten factor in.");
    while (true) { }
  }
  if (ACTIVE_SPOOL >= SPOOL_COUNT) {
    Serial.println("FOUT: ACTIVE_SPOOL wijst buiten spoolLibrary.");
    while (true) { }
  }
  if (spoolLibrary[ACTIVE_SPOOL].emptyGrams <= 0.0) {
    Serial.println("FOUT: meet en vul eerst het lege gewicht van de actieve spoel in.");
    while (true) { }
  }
#endif

#if STAGE == 1
  if (knownMassGrams <= 0.0) {
    Serial.println("FOUT: vul eerst knownMassGrams in met een onafhankelijk bekende massa.");
    while (true) { }
  }
  Serial.println();
  Serial.println("=== FASE 1: KALIBREREN ===");
  Serial.println("1) Laat het platform leeg. 2) Stuur 't' + Enter om te tareren.");
  Serial.print("3) Plaats de bekende massa (");
  Serial.print(knownMassGrams);
  Serial.println(" g). 4) Stuur 'r' + Enter voor de kalibratiefactor.");
#endif

#if STAGE == 3
  pinMode(READ_BUTTON, INPUT_PULLUP);  // pressing the button connects the pin to GND
  startOLED();
#endif
}

// ===========================================================================
//  MAIN LOOP  --  one behaviour per stage
// ===========================================================================
void loop() {
  LoadCell.update();  // must be called often -- keeps fresh data flowing in

#if STAGE == 1
  loopCalibrate();
#elif STAGE == 2
  loopGramsRemaining();
#elif STAGE == 3
  loopOledStandalone();
#endif
}

// ---------------------------------------------------------------------------
//  STAGE 1  --  find your calibration factor with a known weight
// ---------------------------------------------------------------------------
#if STAGE == 1
void loopCalibrate() {
  // Print a live raw reading a couple times a second so you can watch it settle.
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 500) {
    lastPrint = millis();
    Serial.print("uitlezing (nog geen gram vóór kalibratie): ");
    Serial.println(LoadCell.getData());
  }

  // Single-character commands typed into the Serial Monitor.
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == 't') {
      LoadCell.tareNoDelay();      // zero the empty platform
      Serial.println(">> tareren... houd het platform leeg");
    }
    if (c == 'r') {
      // With the known mass sitting on the platform, compute the factor.
      LoadCell.refreshDataSet();   // average a fresh set of readings with the mass on
      float newCal = LoadCell.getNewCalibration(knownMassGrams);
      Serial.println();
      Serial.print(">> JOUW KALIBRATIEFACTOR = ");
      Serial.println(newCal);
      Serial.println(">> Kopieer dit getal naar 'calibrationFactor' bovenin");
      Serial.println(">> de sketch, zet STAGE op 2 en upload opnieuw.");
      Serial.println();
    }
  }

  // Announce when a tare finishes.
  if (LoadCell.getTareStatus()) {
    Serial.println(">> tareren klaar. Plaats de bekende massa en stuur 'r'.");
  }
}
#endif

// ---------------------------------------------------------------------------
//  STAGE 2  --  grams of filament remaining, in the Serial Monitor
// ---------------------------------------------------------------------------
#if STAGE == 2
void loopGramsRemaining() {
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 1000) {
    lastPrint = millis();

    float total     = LoadCell.getData();                  // whole spool, grams
    float empty     = spoolLibrary[ACTIVE_SPOOL].emptyGrams;
    float remaining = total - empty;                       // filament only
    if (remaining < 0) remaining = 0;                      // never show negative

    Serial.print(spoolLibrary[ACTIVE_SPOOL].name);
    Serial.print(" | totaal ");   Serial.print(total, 0);
    Serial.print(" g  - leeg ");  Serial.print(empty, 0);
    Serial.print(" g  = ~");      Serial.print(remaining, 0);
    Serial.println(" g filament resterend");
  }
}
#endif

// ---------------------------------------------------------------------------
//  STAGE 3  --  press the button, read grams on the little screen (no PC needed)
// ---------------------------------------------------------------------------
#if STAGE == 3
void startOLED() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("FOUT: OLED niet gevonden. Controleer voeding, SDA/SCL en OLED_ADDR.");
    while (true) { }
  }
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("filamentweger");
  display.println("druk knop");
  display.display();
}

void showReading(float remaining, float total) {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(spoolLibrary[ACTIVE_SPOOL].name);
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print(remaining, 0);
  display.println(" g");
  display.setTextSize(1);
  display.setCursor(0, 52);
  display.print("totaal ");
  display.print(total, 0);
  display.println("g meting");
  display.display();
}

void loopOledStandalone() {
  // The button pulls the pin LOW when pressed (INPUT_PULLUP).
  static bool wasPressed = false;
  bool pressed = (digitalRead(READ_BUTTON) == LOW);

  if (pressed && !wasPressed) {
    // Een verse, gemiddelde dataset dempt ruis. Of de meting bruikbaar is,
    // volgt alleen uit de herhaalbaarheidsproef in meetlog.md.
    LoadCell.refreshDataSet();
    float total     = LoadCell.getData();
    float empty     = spoolLibrary[ACTIVE_SPOOL].emptyGrams;
    float remaining = total - empty;
    if (remaining < 0) remaining = 0;
    showReading(remaining, total);
  }
  wasPressed = pressed;
}
#endif
