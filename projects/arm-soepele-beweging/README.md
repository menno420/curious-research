# Soepele beweging — doelhoeken gecontroleerd opbouwen

**Wat dit is:** een Arduino-sketch die doelhoeken volgens een lineair profiel of S-curve
opbouwt, plus een meetroute om te bepalen wat dat op de echte arm verandert.

> **Status:** de maker heeft de arm al met een controller gebruikt. Deze specifieke sketch is
> nog niet tegen dat werkende controller-, pin- en voedingssysteem gecompileerd of getest.
> Bewaar de bestaande werkende configuratie daarom als referentie en upload dit experiment pas
> nadat de verschillen zijn vastgelegd.

> **Bekijk het eerst:** open [`index.html`](./index.html) in je browser. Daar zie je drie
> keer exact dezelfde opdracht naast elkaar — één doelsprong, gelijke tussenstappen en een
> S-curve — met onderin de afgeleide van het opgedragen positieprofiel. De animatie is geen
> meting van de echte servo.

---

## Het probleem, in één zin

De gebruikte Arduino `Servo`-API geeft `write()` een doelhoek, maar geen afzonderlijke
snelheidsparameter.

Als je dit schrijft:

```cpp
servo.write(140);
```

vervang je de laatst ingestelde doelhoek door 140°. Hoe snel, hard en nauwkeurig de echte servo
daarop reageert, wordt bepaald door zijn interne regeling, belasting, voeding en mechanica. Een
plotselinge grote doelsprong **kan** daardoor een abrupte armbeweging geven; “vol gas” en “twee
snelheden” zijn geen gemeten eigenschappen van deze onbekende servovariant.

Deze sketch onderzoekt daarom of kleinere, tijdgestuurde doelsprongen de zichtbare beweging op
deze arm rustiger maken.

---

## De oplossing in drie lagen

Elke laag maakt het **opgedragen profiel** geleidelijker dan de vorige. Of dat fysiek beter is,
blijft onderdeel van de vergelijking op de arm.

### Laag 1 — stuur veel doelen die dichtbij liggen

In plaats van één keer `write(140)`, berekent de sketch met een vast interval een tussendoel:
90, 91, 92, 93… Daardoor wordt het **opgedragen positieprofiel** geleidelijker. Of de werkelijke
as even geleidelijk volgt, moet je aan de arm observeren of meten.

**Waarom beginnen bij 20 milliseconden?** De officiële Arduino Servo-library gebruikt een
minimaal refresh-interval van 20.000 microseconden. Dat onderbouwt de timing van de uitgaande
pulstrein van die library; het bewijst niet hoe vaak iedere MG996R-klasse servo intern meet of
regelt. Zie 20 ms daarom als een controleerbaar softwarestartpunt, niet als universele
servospecificatie.

### Laag 2 — laat alle gewrichten tegelijk aankomen

Als de basis 90 graden moet draaien en de pols maar 10, en beide doen 1 graad per stapje,
dan is de pols na 10 stapjes klaar terwijl de basis nog 80 te gaan heeft. Dat ziet er
hakkelig uit, ook al beweegt elke servo op zichzelf netjes.

De sketch kijkt daarom eerst welk gewricht het **verst** moet. Dat bepaalt de geplande looptijd.
Alle andere gewrichten krijgen dezelfde commandoduur. Hun laatste doel wordt dus tegelijk
verstuurd; zonder positieterugmelding bewijst dit niet dat de echte assen tegelijk aankomen.

### Laag 3 — optrekken en afremmen (dit is de grote)

Verdeel je het opdrachtprofiel in **gelijke** stapjes, dan springt de berekende
commandosnelheid aan het begin van nul naar een vaste waarde en aan het eind terug naar nul.
De hypothese is dat die overgang aan een zichtbare of voelbare tik kan bijdragen.

De sketch verdeelt daarom níet gelijk: **kleine stapjes aan het begin, grote in het midden,
weer kleine aan het eind.** Eén regel rekenwerk doet dat:

```cpp
float sBocht(float t) {
  return t * t * (3.0 - 2.0 * t);      // 3t² - 2t³
}
```

Je stopt er de voortgang in als getal van 0 tot 1 (0 = net begonnen, 1 = klaar), en er komt
een voortgang uit die traag start, versnelt, en weer afremt.

| voortgang in de tijd | 0 | 0,25 | 0,5 | 0,75 | 1 |
|---|---|---|---|---|---|
| gelijke stapjes | 0 | 0,25 | 0,5 | 0,75 | 1 |
| met de s-bocht | 0 | 0,16 | 0,5 | 0,84 | 1 |

Het verschil in **positie** lijkt klein. Het verschil in **snelheid** is het hele punt — en
dat zie je in de animatie.

De afgeleide van deze S-curve piekt op 1,5 keer de gemiddelde snelheid. De sketch maakt een
S-curvebeweging daarom 1,5 keer zo lang als een lineaire beweging met dezelfde ingestelde
pieksnelheid. Zonder die correctie zou `maxSnelheid` bij de S-curve geen echte softwarelimiet
zijn. Dit begrenst nog steeds alleen het opdrachtprofiel, niet de gemeten mechanische snelheid.

---

## Aan de slag

### Eerst: dit programma beweegt direct na startup

De sketch koppelt in `setup()` alle zes servo's aan, stuurt de waarden uit `JOINT_HOME` en
begint daarna automatisch tussen twee standen heen en weer te bewegen. De meegeleverde waarden
85–95° en `JOINT_HOME = 90°` zijn **geen gemeten waarden van deze arm**. Een klein bereik rond
een onbevestigde middenstand is niet automatisch veilig: 90° kan door montage, hoornstand,
kabels of gereedschap al onbruikbaar zijn.

> Gebruik de sketch niet met servovoeding aan voordat pinvolgorde, min/max en iedere home-waarde
> op de echte arm zijn gecontroleerd. De clamp begrenst de normale bewegingsroute; hij ziet geen
> obstakels en bewijst niet dat startup veilig is.

### Stap 1 · Meet eerst je grenzen op

Bovenin de sketch staat een tabel `JOINT_MIN` / `JOINT_MAX`. Daar staan placeholders van
85 tot 95 graden in — een kleine band rond een nog onbevestigde 90°-stand. Die kleine band
beperkt de grootte van de automatische testbeweging, maar maakt de stand niet bewezen veilig.

Vervang ze door je eigen opgemeten waarden. Hoe je die meet staat in
[`guides/arm-werkgebied/guide.md`](../../guides/arm-werkgebied/guide.md).
Meet met marge: blijf een paar graden weg van waar een gewricht mechanisch klem loopt.

### Stap 2 · Controleer je bedrading

⚠️ **Servovoeding is een aparte voeding.** Nooit de 5V-pin van de Arduino. Gebruik gedeelde
massa, een passende zekering en een schakelaar die je direct kunt bereiken. De exacte
gecombineerde piek- en blokkeerstroom is hier niet geverifieerd: stel eerst de werkelijke
servovariant vast, controleer de specificatie bij de fabrikant of leverancier en meet de arm
onder begeleide belasting. Ontwerp de voeding niet op één internetwaarde voor “MG996R”.

### Stap 3 · Zet de pinnen goed

```cpp
const int SERVO_PIN[JOINT_COUNT] = { 3, 5, 6, 9, 10, 11 };
```

Pas aan naar de pinnen waar jouw signaaldraden op zitten.

### Stap 4 · Upload en kijk

Test de rekenlogica eerst met de servovoeding uit. Open daarna
[`soepele_beweging.ino`](./soepele_beweging.ino) in de Arduino IDE, kies je bord en klik op
Upload. Open **Tools → Serial Monitor** op **115200** en lees de startupmelding.

Na bekrachtiging gaat de arm automatisch heen en weer tussen twee standen.
**Hand bij de uitschakeling, ogen erbij; stop bij brommen, klemmen, reset of onverwachte
richting.**

---

## Nu het leuke deel — draai aan de knoppen

Dit is geen sketch om te draaien en dan te vergeten. Er zitten drie knoppen in waarmee je
kunt voelen wat er gebeurt.

### `maxSnelheid` — maximale opgedragen hoeksnelheid

```cpp
float maxSnelheid = 60.0;
```

| waarde | hoe het voelt |
|---|---|
| `30` | lage opgedragen hoeksnelheid; eerste experiment na veilige startup |
| `60` | middelste vergelijkingswaarde |
| `120` | hogere vergelijkingswaarde; alleen als voeding en mechanica rustig blijven |
| `300` | zeer korte profieltijd; niet gelijk aan een gemeten servosnelheid |

**Het experiment:** vergelijk eerst 30 en 60 met exact dezelfde korte route. Verhoog pas daarna.
De S-curve duurt bij dezelfde limiet langer omdat hij tijd gebruikt om op en af te bouwen. Bij
een hogere ingestelde limiet bevat dezelfde verplaatsing minder updatepunten. Noteer wat
werkelijk zichtbaar en hoorbaar verandert.

### `gebruikSbocht` — aan of uit

```cpp
bool gebruikSbocht = true;
```

Zet hem op `false`, upload, en noteer of vertrek en aankomst anders aanvoelen of klinken. Zet
hem weer op `true`. Alleen die A/B-vergelijking laat zien wat laag 3 op deze arm doet.

### `UPDATE_MS` — hoe vaak je een nieuw doel stuurt

```cpp
const unsigned long UPDATE_MS = 20;   // startpunt gelijk aan Servo-library-refresh
```

Vergelijk bijvoorbeeld `60`, `20` en `5`. Bij 60 ms zijn de opgedragen hoekstappen groter. Bij
5 ms berekent de sketch vaker een nieuw tussendoel dan het 20 ms-refresh-interval van de
huidige Arduino Servo-library. De library gebruikt steeds de laatst geschreven waarde; welk
zichtbaar verschil overblijft hangt af van bord, timing en echte servo. Meet het in plaats van
vooraf “geen verschil” te beloven.

---

## Iets om over na te denken

Een echte open vraag, waar we het antwoord niet van weten voor jouw arm:

> De **schouder** tilt het hele gewicht van de arm op. De **basis** draait alleen maar rond,
> vlak, zonder iets omhoog te hoeven duwen. Zouden die twee wel dezelfde snelheidslimiet
> moeten hebben?

En daar bovenop: omhoog bewegen is zwaar, omlaag helpt de zwaartekracht juist mee. Dezelfde
opdracht levert dus niet dezelfde beweging op, afhankelijk van welke kant je op gaat.

Eén snelheidslimiet **per gewricht** in plaats van één voor de hele arm is een paar regels
code. Je hebt de arm om het uit te proberen — en dat is precies het soort ding waar dit
schriftje voor is. Vraag het gerust:

```
Ik wil een aparte snelheidslimiet per gewricht in soepele_beweging.ino
```

---

## Wat dit níet oplost

Eerlijk zijn helpt meer dan mooi doen:

- **Slop blijft slop.** Speling in de tandwielen en de beugels wordt hier niet minder van.
  De beweging wordt netter, niet nauwkeuriger.
- **Herhaalbaarheid is een ander probleem.** De eindpositie kan afhankelijk zijn van de
  aanrijrichting door speling en deadband. Meet dat apart; een S-curve bewijst geen verbetering.
- **Doorbuiging onder gewicht blijft mogelijk.** Een uitgestrekte arm kan onder belasting
  zakken. Het opdrachtprofiel compenseert dat niet automatisch.

Het doel is een **rustiger opgedragen bewegingsprofiel**, niet automatisch een preciezere arm.
Minder zichtbare schok is observeerbaar; minder trilling, overshoot of stroompiek is pas een
resultaat nadat het met dezelfde route en belasting is vergeleken.

## Welke gegevens ontbreken nog voor een echte armtest?

Leg vóór upload vast:

- merk en exact type van de bestaande controller;
- de werkende sketch/firmware en versie die nu als referentie dient;
- pinmapping en draairichting per fysiek gewricht;
- werkende voeding, beveiliging en gedeelde-massa-opbouw;
- huidig startupgedrag en homepositie;
- gemeten min/midden/max per gewricht;
- servomerk/variant per as, voor zover te herkennen.

Daarna kan Claude de bestaande werkende configuratie met `soepele_beweging.ino` vergelijken
zonder de arm opnieuw te ontwerpen.

## Bronnen en bewijsniveau

- [Arduino Servo-library, `Servo.h`](https://github.com/arduino-libraries/Servo/blob/master/src/Servo.h)
  — `write()` zet een hoekwaarde en de library gebruikt een refresh-interval van 20.000 µs,
  **Geverifieerd**, gecontroleerd 2026-08-07.
- Het effect van de S-curve op deze arm — **Experiment** tot dezelfde route lineair en met
  S-curve onder gelijke omstandigheden is gemeten.
- Stroom, overshoot en mechanische trilling — **Nog bevestigen** zonder stroommeting of
  positiemeting op de echte opstelling.
