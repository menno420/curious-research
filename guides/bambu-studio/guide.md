# Bambu Studio — van foutbeeld naar één gerichte test

## Welk probleem lost dit op?

Veel online 3D-printeradvies begint bij handmatig bednivelleren, Z-offset en pressure advance.
Dat is niet de goede start voor de A1-serie. Deze workflow scheidt wat de printer meet van de
keuzes die jij nog steeds zelf maakt.

Open [`index.html`](./index.html) voor de korte animatie van meten → kiezen → controleren.

## Waarom dit voor jouw werkplaats telt

Het bevestigde printerpark staat in
[`docs/workshop-profile.md`](../../docs/workshop-profile.md). Gebruik in Bambu Studio het echte
printer-, plaat-, nozzle- en filamentprofiel. Verander niet vijf instellingen tegelijk: laat
eerst de standaard kalibraties draaien en beoordeel daarna één zichtbaar probleem.

De A1-serie gebruikt geen LiDAR-scan zoals sommige andere Bambu-modellen. Advies dat een
LiDAR-kalibratielijn of handmatige Z-offset veronderstelt, hoort dus niet bij deze workflow.

## Benodigdheden

- Bambu Studio op Windows;
- het juiste A1- of A1-mini-printerprofiel;
- het juiste build-plate- en nozzleprofiel;
- een bekend filamentprofiel, of het etiket en datablad van onbekend filament;
- een klein representatief testonderdeel, geen productieprint van zes uur.

## Stappenplan

### 1. Leg het foutbeeld vast vóór je iets wijzigt

Maak één overzichtsfoto en één close-up. Noteer:

- printer: A1 of A1 mini;
- plaatsoort en nozzlemaat;
- materiaal, merk en kleur;
- waar het defect zit: eerste laag, naad, brug, overhang, maatvoering of kleurwissel;
- of hetzelfde bestand eerder wel goed ging.

### 2. Controleer de vier profielen

Kijk in Bambu Studio of geselecteerd zijn:

1. het juiste **Printer**-profiel;
2. de gemonteerde **Nozzle diameter**;
3. de echte **Build Plate**;
4. het passende **Filament**-profiel per AMS Lite-positie.

**Stop hier** als een profiel niet overeenkomt met de machine. Een instellingentest op het
verkeerde profiel leert niets.

### 3. Laat de normale voorprintmetingen aan

Laat bij een normale diagnose de automatische bedmeting en flow-dynamics-kalibratie
ingeschakeld. Maak de plaat schoon volgens de aanwijzingen voor die plaat en verwijder
filamentresten aan de nozzle vóór de meting.

Gebruik geen papiertest of algemene handleiding om handmatig een Z-offset te zetten. Als de
eerste laag slecht is, controleer eerst plaatkeuze, reinheid, nozzle, hotendmontage en of de
automatische meting werkelijk is uitgevoerd.

### 4. Classificeer het probleem vóór je aan een knop draait

| Wat je ziet | Eerste test |
|---|---|
| Loslatende of onderbroken eerste laag | Reinig plaat en nozzle; print hetzelfde kleine bestand opnieuw met kalibratie. |
| Draadjes tussen losse delen | Droogte en passend filamentprofiel controleren; daarna pas temperatuur/retractie testen. |
| Doorzakkende brug of overhang | Oriëntatie en onderdeelkoeling vergelijken op een klein teststuk. |
| Scheur bij gat of belasting | Oriëntatie en extra wanden testen vóór meer vulling. |
| Ondermaatse passing | Een passingcoupon meten; niet het hele ontwerp op gevoel verschuiven. |
| Veel purge bij AMS Lite | Aantal kleurwissels in Preview bekijken en het kleurontwerp per hoogte groeperen. |

### 5. Maak een A/B-test

Dupliceer het kleine testonderdeel. Houd model, materiaal, plaat en alle overige instellingen
gelijk. Verander in versie B maar **één** hypothese, bijvoorbeeld:

- één extra wand;
- een andere oriëntatie;
- één temperatuurstap binnen het filamentbereik;
- een aangepaste supportafstand;
- minder kleurwissels door een ander ontwerp.

Geef beide objecten in Bambu Studio een duidelijke naam, bijvoorbeeld `A_standaard` en
`B_5-wanden`.

### 6. Controleer Preview vóór Print

Klik **Slice Plate** en open **Preview**. Controleer laag voor laag:

- begint het model op de plaat;
- lopen wanden en topvlakken door;
- staat support waar je hem verwacht;
- hoeveel materiaal- en kleurwissels zijn er;
- kloppen tijd- en filamentverschil tussen A en B.

Start daarna zelf de print en bekijk de eerste lagen.

## Zo controleer je het resultaat

Noteer per A/B-paar:

- foto van dezelfde plek;
- maat met schuifmaat als passing of vervorming telt;
- printtijd en materiaal uit Preview;
- welk onderdeel brak, boog, paste of losliet.

De test is geslaagd als één versie meetbaar beter is en je kunt zeggen **welke ene wijziging**
het verschil waarschijnlijk veroorzaakte. Geen verschil is ook informatie: zet de instelling
terug en test de volgende hypothese.

## Veelgemaakte fouten

- Handmatig Z-offsetadvies van een ander printertype volgen.
- Aannemen dat de A1 LiDAR gebruikt.
- Printer-, plaat-, nozzle- of filamentprofiel niet controleren.
- Vijf slicerwaarden tegelijk veranderen.
- Meer infill kiezen terwijl laagoriëntatie of wanddikte de zwakke plek bepaalt.
- Onbekend/nat filament proberen te repareren met alleen retractie.
- Een AMS Lite-afvalprobleem pas na het slicen bekijken in plaats van al bij het ontwerp.

## Wanneer vraag je Claude om hulp?

- *"Lees het werkplaatsprofiel. Welke drie oorzaken passen bij dit specifieke foutbeeld?"*
- *"Maak een A/B-test in Bambu Studio met maar één veranderde instelling."*
- *"Welke laagweergave in Preview bewijst dat mijn support/wand/kleurwissel klopt?"*
- *"Vergelijk deze twee foto's en zeg welke meting jouw diagnose kan weerleggen."*
- *"Welke Bambu-handleiding ondersteunt deze stap en wat is alleen praktijkadvies?"*

## Bronnen en bewijsniveau

- Bambu Lab A1-product- en kalibratie-informatie: <https://bambulab.com/en-eu/a1> —
  **Onderbouwd**; officiële pagina, maar bronweergave kon op 2026-08-07 niet volledig worden
  uitgelezen in de linkcontrole.
- Bambu Lab A1 mini-documentatie:
  <https://wiki.bambulab.com/en/a1-mini/manual/intro-a1-mini> — **Onderbouwd**.
- A/B-testen, foutclassificatie en één variabele tegelijk — **Praktijkadvies**; verifieer op
  de eigen machine en leg het resultaat vast.
