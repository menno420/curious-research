# Filamentweger — van loadcell naar een herhaalbare voorraadcontrole

> **Status:** bouwroute gereed · hardware en Arduino-sketch nog niet op de echte opstelling
> geverifieerd · nauwkeurigheid is een meetresultaat, geen vaste productspecificatie

## Welk probleem lost dit op?

Een loadcell meet het totale gewicht van spoel plus filament. Na kalibratie en aftrek van het
**zelf gemeten** lege-spoelgewicht krijg je een praktische schatting van de resterende
hoeveelheid filament.

Dit project is bedoeld als een momentopname vóór een print. Het belooft geen universele
nauwkeurigheid en ook geen waarde die dagenlang zonder opnieuw tareren geldig blijft.

## Waarom is dit nuttig voor deze werkplaats?

Het project verbindt drie vaardigheden die ook elders bruikbaar zijn:

1. een sensor mechanisch correct monteren;
2. ruwe meetwaarden met een bekende massa kalibreren;
3. herhaalbaarheid meten voordat je een getal vertrouwt.

De uitkomst kan helpen bij de vraag *"is er waarschijnlijk genoeg filament voor deze print?"*.
De veiligheidsmarge bepaal je pas nadat je de spreiding op de eigen opstelling hebt gemeten.

## Wat is al onderbouwd en wat nog niet?

| Onderdeel | Status | Betekenis |
|---|---|---|
| Kalibratie met `tare()`, `refreshDataSet()` en `getNewCalibration()` | **Geverifieerd** | Dit is de route uit de officiële `HX711_ADC`-bibliotheek. |
| Draadfuncties `E+`, `E-`, `A+` en `A-` | **Geverifieerd** | Alleen de interfacefuncties zijn bekend; de **kleuren van jouw loadcell zijn niet bekend**. |
| Montage, stabilisatietijd en opnieuw tareren | **Praktijkadvies** | Dit zijn goede startstappen, maar het resultaat hangt af van de echte cel, constructie en omgeving. |
| Resolutie, drift en bruikbare foutmarge | **Experiment** | Meet die met [`meetlog.md`](meetlog.md); neem geen vaste `±5 g` over. |
| Sketch op het eigen Arduino-bord | **Nog bevestigen** | Bord, core, modules en bibliotheekversies zijn nog niet geïnventariseerd; de sketch is hier niet gecompileerd. |

## Benodigde onderdelen en informatie

- een Arduino-compatibel bord waarvan exact model en logicaspanning bekend zijn;
- een HX711-module;
- een vier- of zesdraads loadcell met voldoende capaciteit voor platform + volle spoel + marge;
- een stijve basis en platform volgens de montagerichting van de loadcell;
- een bekende massa die onafhankelijk is gewogen;
- Arduino IDE en `HX711_ADC` van Olav Kallhovd;
- optioneel: knop en SSD1306-I²C-OLED, met eigen datasheet;
- multimeter voor voedingscontrole en diagnose.

De huidige voorbeeldsketch gebruikt digitale pin 4 voor `DOUT`, pin 5 voor `SCK` en pin 6 voor
de optionele knop. Dat is een **softwarekeuze**, geen bewijs dat deze pinnen of 5 V bij ieder
Arduino-bord en iedere module passen.

## Leg deze gegevens eerst vast

Maak foto's van opschriften en zoek, waar mogelijk, de officiële datasheets op.

| Gegeven | Waarom nodig? |
|---|---|
| exact Arduino-bord | bepaalt logicaspanning, I²C-pinnen, boardprofiel en ondersteunde libraries |
| merk/type/capaciteit van de loadcell | bepaalt maximale belasting, montage, draadtoewijzing en verwachte output |
| draadfunctie per kleur | voorkomt dat een kleurconventie van een ander model wordt overgenomen |
| type HX711-print en toegestane voeding | bepaalt veilige voeding en pinlabels |
| OLED-type, voedingsspanning en I²C-adres | voorkomt gokken met 5 V, `0x3C` of `0x3D` |
| massa van het kalibratievoorwerp | bepaalt de kalibratiefactor |
| leeggewicht van iedere echte spoel | nodig voor `resterend = totaal - lege spoel` |
| gewenste beslismarge | bepaalt wanneer de meting bruikbaar genoeg is voor een print |

Heb je geen datasheet van de loadcell, gok dan niet op draadkleur. Geef Claude een scherpe foto
van alle opschriften en eventueel de zes weerstandsmetingen tussen de vier draden. Zo'n meting kan
kandidaatparen aanwijzen, maar hoeft niet eenduidig te bewijzen welk paar excitatie of signaal is.
Laat dus expliciet noteren wat ambigu blijft en behandel de mapping als **Nog bevestigen** totdat
zij met modelspecifieke informatie of een gecontroleerde test is bewezen.

## Stapsgewijze workflow

### 1. Monteer de loadcell

1. Lees de pijl, `LOAD`-markering of montagetekening van het concrete model.
2. Bevestig de daarvoor bedoelde vaste zijde star aan de basis.
3. Bevestig het platform aan de belastbare zijde.
4. Controleer dat het platform niets anders raakt en de cel niet tordeert.
5. Plaats nog geen spoel en sluit nog geen voeding aan.

### 2. Maak eerst de functiemapping

De HX711 verwacht deze vier brugfuncties:

| Functie loadcell | HX711-label |
|---|---|
| positieve excitatie | `E+` |
| negatieve excitatie | `E-` |
| positief meetsignaal | `A+` |
| negatief meetsignaal | `A-` |

Gebruik voor de linkerkolom het datablad of de markering van **jouw** loadcell. Rood, zwart,
groen en wit zijn geen universele functienamen. Een negatieve uitlezing kan met polariteit te
maken hebben, maar is op zichzelf geen bewijs dat alleen twee signaaldraden omgewisseld moeten
worden.

### 3. Sluit HX711 en Arduino aan

Doe dit spanningsloos.

1. Verbind `GND` met `GND`.
2. Verbind `DOUT`/`DT` met de in de sketch ingestelde pin 4.
3. Verbind `SCK`/`CLK` met de in de sketch ingestelde pin 5.
4. Verbind de voeding pas nadat bord- en modulehandleiding dezelfde toegestane spanning geven.
5. Controleer alle verbindingen nogmaals en sluit dan pas USB aan.

Voor een ander bord mag je pin 4 en 5 wijzigen. Noteer de nieuwe mapping boven in de sketch en
in het meetlog.

### 4. Installeer de bibliotheek

1. Open in Arduino IDE **Sketch → Include Library → Manage Libraries…**.
2. Zoek `HX711_ADC`.
3. Installeer **HX711_ADC by Olav Kallhovd**.
4. Installeer voor fase 3 ook **Adafruit SSD1306** en **Adafruit GFX Library**.
5. Kies het exacte boardprofiel; laat `STAGE` voorlopig op `1` staan.

### 5. Kalibreer in fase 1

1. Zet `knownMassGrams` gelijk aan de onafhankelijk bekende massa.
2. Upload met `#define STAGE 1`.
3. Open Serial Monitor op `57600` baud.
4. Laat het lege platform stabiliseren.
5. Stuur `t` en wacht op `tare done`.
6. Plaats de bekende massa gecentreerd en wacht opnieuw tot de waarde stabiel wordt.
7. Stuur `r`.
8. Kopieer de getoonde factor naar `calibrationFactor` en upload opnieuw.

Gebruik niet automatisch “500 ml water = precies 500 gram”. Weeg het complete voorwerp op een
geschikte referentieweegschaal en gebruik die gemeten massa.

### 6. Meet herhaalbaarheid vóór je een spoel berekent

1. Laat hetzelfde bekende gewicht vijf keer stabiliseren.
2. Neem het gewicht na iedere meting volledig weg en plaats het opnieuw.
3. Noteer alle waarden in [`meetlog.md`](meetlog.md).
4. Bereken het gemiddelde, de grootste afwijking en de spreiding `maximum - minimum`.
5. Herhaal na opwarming en, indien relevant, bij een andere omgevingstemperatuur.

Pas daarna kies je een bruikbare veiligheidsmarge. Het aantal bits van de HX711, het bereik van
de loadcell en één internetvoorbeeld voorspellen de nauwkeurigheid van deze complete constructie
niet.

### 7. Meet het lege spoelgewicht

1. Weeg de werkelijk lege spoel die je later wilt herkennen.
2. Vervang in `spoolLibrary` de naam en `0.0` door die eigen meting.
3. Kies de juiste regel met `ACTIVE_SPOOL`.
4. Zet `STAGE` op `2` en upload.
5. Plaats de gevulde spoel en controleer zowel totaalgewicht als berekende restmassa.

De sketch bevat bewust geen vooraf ingevulde merkgewichten. Twee spoelen van hetzelfde merk
kunnen verschillen en een cataloguswaarde is geen werkplaatsmeting.

### 8. Voeg het OLED pas als laatste toe

1. Controleer de voeding, I²C-pinnen en het adres in de documentatie van bord en scherm.
2. Sluit de knop tussen de ingestelde pin 6 en `GND` aan; de sketch gebruikt `INPUT_PULLUP`.
3. Pas `OLED_ADDR` aan als de gedocumenteerde of gescande waarde anders is.
4. Zet `STAGE` op `3`, upload en vergelijk de schermwaarde met Serial Monitor.

## Hoe controleer je succes?

De bouw is technisch geslaagd als:

1. de HX711 zonder timeout nieuwe waarden levert;
2. de nul na opnieuw tareren binnen jouw gemeten spreiding terugkomt;
3. vijf herplaatsingen van de referentiemassa binnen de vooraf gekozen foutmarge vallen;
4. een tweede bekende massa geen onverwacht grote schaalfout laat zien;
5. het berekende filamentgewicht het **zelf gemeten** lege-spoelgewicht gebruikt;
6. de omstandigheden en uitkomsten in `meetlog.md` staan.

“De waarde ziet er rustig uit” is niet genoeg. Een zwaar gefilterde maar fout gekalibreerde
waarde kan ook rustig zijn.

## Veelgemaakte fouten

- draadkleuren van een andere loadcell als standaard behandelen;
- capaciteit of voeding kiezen zonder totaalgewicht en datasheet te controleren;
- kalibreren terwijl het platform iets raakt of de basis doorbuigt;
- één plaatsing meten en dat “nauwkeurigheid” noemen;
- een afgerond merkgewicht als leeggewicht opslaan;
- filteren gebruiken om een mechanisch probleem te verbergen;
- het OLED toevoegen voordat HX711 + Serial aantoonbaar werken;
- de sketch als gecompileerd beschrijven terwijl exact board en libraries nog ontbreken.

## Wanneer vraag je Claude of ChatGPT?

- *“Dit zijn merk, typenummer en datasheet van mijn loadcell. Maak een mapping naar E+, E-, A+
  en A- en citeer de exacte tabel.”*
- *“Hier zijn vijf herhaalde metingen en de referentiemassa. Bereken gemiddelde, bias en
  spreiding zonder meer precisie te tonen dan de data ondersteunt.”*
- *“Mijn uitlezing verandert bij belasting de verkeerde kant op. Geef hypothesen in
  testvolgorde; neem niet aan dat draadkleuren standaard zijn.”*
- *“Controleer deze sketch voor mijn exacte Arduino-board en bibliotheekversies. Wijzig nog
  niets aan de hardwaremapping zonder mij de aanname te tonen.”*

## Bronnen

- [`HX711_ADC` en de kalibratiefuncties](https://github.com/olkal/HX711_ADC) — officiële
  bibliotheekbron, **Geverifieerd**, gecontroleerd 2026-08-07.
- [Load Cell Wiring Guide van ANYLOAD](https://www.anyload.com/wiring-guide/) — fabrikant legt
  uit dat draadkleurcodes kunnen verschillen en dat het modelspecifieke datablad leidend is,
  **Geverifieerd voor die algemene waarschuwing**, gecontroleerd 2026-08-07.
- [Load Cell Wiring Made Easy van Morehouse](https://mhforce.com/load-cell-wiring/) — laat zien
  wat weerstandsmetingen wel en niet eenduidig identificeren bij een onbekende vierdraads cel,
  **Onderbouwd voor de diagnoseroute**, gecontroleerd 2026-08-07.
- Alle prestaties van deze specifieke bouw — **Experiment** tot het meetlog is ingevuld.
