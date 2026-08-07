# Robotarm — herhaalbaarheid meten vóór je preciezer programmeert

## Welk probleem lost dit op?

De besturing kent de gevraagde servohoeken, maar voor deze arm is geen onafhankelijke
positieterugmelding bevestigd. Deze test meet daarom wat werkelijk telt: hoe dicht het
gereedschap na herhaalde bewegingen bij hetzelfde punt terugkomt.

Open [`index.html`](./index.html) en druk op **Afspelen** om de A → B → A-test te zien.

## Waarom dit voor jouw werkplaats telt

De armcontext staat in
[`docs/workshop-profile.md`](../../docs/workshop-profile.md). Meer decimalen in code maken
speling, doorbuiging en zwaartekracht niet kleiner. Een herhaaltest vertelt of een penplot,
pick-and-place of camerabeweging haalbaar is en of een mechanische of softwarewijziging echt
verbetering brengt.

## Benodigdheden

- de gemonteerde arm en bereikbare voedingsschakelaar;
- bevestigde, gemeten gewrichtslimieten;
- een vaste pen/punt aan de arm;
- vastgeplakt ruitjespapier of meetplaat;
- schuifmaat of liniaal;
- telefoon op vaste steun voor optionele video;
- tabel uit deze gids.

## Eerst bevestigen

De huidige voorbeeldsketches sturen tijdens startup een `JOINT_HOME`/90°-stand. Lees
[`arm/README.md`](../../arm/README.md). Voer deze test alleen uit wanneer de gebruikte sketch,
pinvolgorde, thuisstand en startup op de echte arm onder toezicht zijn gecontroleerd. Een
softwareclamp vervangt deze gate niet.

## Stappenplan

### 1. Kies één relevante pose

Kies geen uiterste stand. Neem een positie die lijkt op het echte project en minstens enkele
graden binnen iedere gemeten grens ligt. Bevestig de pen of meetpunt zonder speling.

### 2. Maak twee benaderingspunten

- **A:** het meetpunt waar de arm moet eindigen.
- **B:** een duidelijke andere pose, zodat de tandwielen en belasting van richting veranderen.

Gebruik dezelfde bewegingstijd en hetzelfde pad voor iedere cyclus.

### 3. Markeer de eerste A-positie

1. Start de gecontroleerde workflow langzaam en onder toezicht.
2. Beweeg naar A.
3. Laat de arm een vaste tijd uittrillen, bijvoorbeeld één seconde.
4. Laat de punt het papier licht markeren zonder zijwaartse kracht.
5. Noem deze markering `A0`.

### 4. Herhaal A → B → A tien keer

Voor cyclus 1 t/m 10:

1. beweeg A naar B;
2. wacht dezelfde vaste tijd;
3. beweeg B naar A via hetzelfde pad;
4. wacht dezelfde vaste tijd;
5. zet één kleine markering;
6. verander tussendoor geen snelheid, last, bevestiging of code.

### 5. Meet de spreiding

Kies `A0` als referentie. Meet per markering de horizontale en verticale afwijking.

| Cyclus | ΔX mm | ΔY mm | Opmerking |
|---:|---:|---:|---|
| 1 | | | |
| 2 | | | |
| 3 | | | |
| 4 | | | |
| 5 | | | |
| 6 | | | |
| 7 | | | |
| 8 | | | |
| 9 | | | |
| 10 | | | |

Bereken de grootste afstand tot `A0` of omsluit alle punten met de kleinste praktische cirkel.
Dat is de herhaalspreiding voor **deze pose, last, snelheid en benaderingsrichting**.

### 6. Test één hypothese

Kies daarna één wijziging:

- lagere snelheid;
- altijd vanuit dezelfde richting naderen;
- kortere uitsteek van het gereedschap;
- minder last;
- stijvere bevestiging;
- langere uittriltijd.

Herhaal exact dezelfde tien cycli en vergelijk de spreiding, niet de mooiste losse markering.

## Zo controleer je het resultaat

De test is geslaagd als:

1. alle omstandigheden zijn vastgelegd;
2. tien cycli hetzelfde pad gebruiken;
3. afwijkingen in millimeters zijn gemeten;
4. de vereiste projecttolerantie vooraf bekend is;
5. een wijziging alleen “beter” heet wanneer de hele spreiding kleiner wordt.

Een penplot mag meer spreiding verdragen dan een klein onderdeel grijpen. Er bestaat dus geen
universeel goed aantal millimeters.

## Veelgemaakte fouten

- Gevraagde servohoek als gemeten gereedschapspositie behandelen.
- A telkens vanuit een andere richting benaderen.
- Tegelijk snelheid, last en pad veranderen.
- De arm of het papier tussen cycli verschuiven.
- Alleen gemiddelde fout rapporteren en één grote uitschieter verbergen.
- Nauwkeurigheid (juist doelpunt) en herhaalbaarheid (steeds hetzelfde punt) verwarren.
- Startupbeweging buiten de test laten terwijl die de mechanica al belast.

## Wanneer vraag je Claude om hulp?

- *"Bereken uit deze ΔX/ΔY-tabel de maximale spreiding en laat uitschieters zichtbaar."*
- *"Ontwerp een A/B-test met alleen lagere snelheid als wijziging."*
- *"Welke mechanische speling past bij dit patroon van richtingsafhankelijke fouten?"*
- *"Welke projecttolerantie moet ik vooraf kiezen voor penplotten versus grijpen?"*
- *"Zet dit bevestigde meetresultaat op één plek zonder het als algemene MG996R-specificatie te schrijven."*

## Bronnen en bewijsniveau

- Geen externe specificatie kan de herhaalbaarheid van deze samengestelde arm bevestigen.
  De uitkomst is een **Experiment** en wordt pas werkplaatsbewijs na de beschreven meting.
- Servoachtergrond: [`research/dossiers/servos.md`](../../research/dossiers/servos.md) en
  [`research/dossiers/servos-gemini.md`](../../research/dossiers/servos-gemini.md) — ruwe
  research; opnieuw beoordelen volgens het bewijsbeleid.

