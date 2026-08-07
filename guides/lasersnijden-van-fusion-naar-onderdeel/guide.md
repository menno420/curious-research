# Lasersnijden — van Fusion-schets naar passend onderdeel

## Welk probleem lost dit op?

Een goede Fusion-schets is nog geen goed lasersnijbestand. Deze workflow brengt één vlak
onderdeel gecontroleerd door DXF-export, materiaalcontrole, kerfmeting, proefsnede en montage.

Open [`index.html`](./index.html) en druk op **Afspelen** voor de hele keten.

## Waarom dit voor jouw werkplaats telt

Fusion 360 is de ontwerpbron; zie
[`docs/workshop-profile.md`](../../docs/workshop-profile.md). Het exacte lasermodel,
laserprincipe, vermogen en de besturingssoftware zijn nog niet bevestigd. Daarom geeft deze
gids geen universele snelheid, kleurcode of kerfwaarde. Hij laat je die waarden betrouwbaar
voor de eigen machine en plaatbatch vastleggen.

## Benodigdheden

- Fusion 360 Personal Use;
- de software die bij de eigen lasersnijder hoort;
- de handleiding en materiaallijst van die machine;
- een geïdentificeerde, toegestane plaat plus reststuk uit dezelfde batch;
- schuifmaat;
- afzuiging volgens de machinehandleiding;
- [`testlog.md`](./testlog.md).

## Eerst bevestigen

Schrijf vóór de eerste stap op:

- machinefabrikant en exact model;
- CO₂-, diode- of fiberlaser;
- lens/focusmethode en gebruikte software;
- materiaalhandelsnaam, leverancier, werkelijke dikte en batch;
- waar kerfcompensatie wordt toegepast: ontwerp **of** machinesoftware.

Onbekend kunststof, onbekend schuim, PVC/vinyl, PTFE/Teflon, PVB en epoxy-/fenolhoudende
plaat gaan niet in de machine. De eigen machinehandleiding kan méér materialen uitsluiten.

## Stappenplan

### 1. Maak één vlakke exportschets

1. Open het parametrische Fusion-model.
2. Maak of toon één schets die alleen de uiteindelijke 2D-contouren bevat.
3. Verwijder hulplijnen uit de zichtbare export of zet ze op **Construction**.
4. Controleer dat buitencontouren, gaten en sleuven gesloten zijn.
5. Voeg één controlemaat toe die je na import gemakkelijk kunt meten, bijvoorbeeld 100 mm
   tussen twee herkenbare punten.

Houd ontwerpwaarden zoals `plaatdikte`, `passing` en eventueel `kerf` als benoemde User
Parameters. Pas kerf niet tegelijk in Fusion en de lasersoftware toe.

### 2. Exporteer de schets als DXF

1. Zoek de schets links in de **Browser**.
2. Klik er met rechts op.
3. Kies **Export DXF**.
4. Kies de bedoelde zichtbare geometrie en eenheid.
5. Geef het bestand een naam met onderdeel, plaatdikte en revisie, bijvoorbeeld:

```text
zijpaneel_berk-3mm_v03.dxf
```

6. Bewaar het Fusion-bestand als master; het DXF is afgeleide uitvoer.

### 3. Controleer de import in de lasersoftware

1. Importeer het DXF in een leeg document.
2. Meet onmiddellijk de controlemaat. Is 100 mm geen 100 mm, stop dan en corrigeer de
   importeenheid; schaal niet op het oog.
3. Zoek dubbele lijnen door één contour tijdelijk te verplaatsen of de softwarecontrole te
   gebruiken.
4. Controleer open contouren, kleine losse segmenten en splines.
5. Wijs snijden, graveren en markeren toe volgens **jouw software**. Een universele
   rood/blauw-regel bestaat niet.
6. Controleer dat interne gaten vóór de buitencontour worden gesneden, als de software die
   volgorde ondersteunt.

### 4. Meet kerf op een reststuk

Kerf is de breedte materiaal die de snede verwijdert. Maak een eenvoudige coupon met een
getekende buitenmaat, bijvoorbeeld een vierkant, en snijd hem zonder softwarecompensatie.

1. Meet de getekende buitenmaat in Fusion.
2. Snijd de coupon met de machinefabrikantwaarde als proefstart.
3. Laat het materiaal afkoelen en meet dezelfde buitenmaat op meerdere plekken.
4. Als de software op de middenlijn sneed en geen compensatie gebruikte:

```text
kerf ≈ getekende buitenmaat − gemeten buitenmaat
```

5. Herhaal of gebruik meerdere sneden als de meting te veel varieert.
6. Noteer machine, materiaalbatch, dikte, focus, snelheid, vermogen, passages en gemiddelde
   kerf in [`testlog.md`](./testlog.md).

Dit is een machine-/materiaalmeting, geen vaste eigenschap van “3 mm multiplex”.

### 5. Maak een passingcoupon

Voor verbindingen is een directe passingtest nuttiger dan alleen rekenen.

1. Maak vijf sleuven rond de gemeten plaatdikte, in kleine gelijke stappen.
2. Label iedere sleuf in het ontwerp.
3. Snijd een bijpassende tong uit hetzelfde materiaal en dezelfde richting.
4. Test klem, nauw, schuivend en los.
5. Kies de passing die bij het doel hoort en sla die meetwaarde op, niet alleen de naam
   “strak”.

### 6. Doe een kleine proefsnede vóór de volledige plaat

1. Controleer materiaalidentiteit en machinehandleiding opnieuw.
2. Zet afzuiging/air assist aan zoals voorgeschreven.
3. Focus volgens de machineprocedure.
4. Snijd één klein representatief hoekje, gat en sleuf.
5. Blijf bij de machine en houd stopmogelijkheid bereikbaar.
6. Beoordeel: volledig door, randbreedte, verkoling/smelt, maat en passing.
7. Verander daarna maar één parameter per test. Trotec adviseert bij parametertests eveneens
   één variabele tegelijk.

### 7. Snijd en monteer

Nest de onderdelen pas nadat schaal, contouren, kerf en passing zijn gecontroleerd. Bewaar het
DXF, de machinejob en het testlog bij dezelfde ontwerprevisie. Past de montage niet, wijzig dan
de parametrische bron of de gekozen centrale compensatie en genereer opnieuw.

## Zo controleer je het resultaat

De workflow is geslaagd als:

1. de controlemaat na DXF-import exact klopt;
2. er geen dubbele of open snijlijnen zijn;
3. een coupon volledig doorsnijdt met aanvaardbare rand;
4. kerf en gekozen passing meetbaar zijn vastgelegd;
5. het proefhoekje en de sleuf passen vóór de volledige plaat wordt gebruikt;
6. het log duidelijk zegt voor welke machine, lens/focus en materiaalbatch de waarde geldt.

## Veelgemaakte fouten

- DXF importeren en de schaal op het oog herstellen.
- Kerf zowel in Fusion als in de lasersoftware compenseren.
- Spotmaat van de laser verwarren met werkelijke kerf door de plaat.
- “Multiplex” als voldoende materiaalidentificatie behandelen.
- Snij- en graveerrollen aan universele lijnkleuren koppelen.
- De volledige plaat starten zonder coupon uit dezelfde batch.
- Denken dat afzuiging een verboden materiaal toegestaan maakt.

## Wanneer vraag je Claude om hulp?

- *"Controleer deze DXF-workflow op dubbele kerfcompensatie; neem geen kerfwaarde aan."*
- *"Maak een parametrische passingcoupon voor mijn gemeten plaatdikte en vijf testwaarden."*
- *"Welke gegevens uit mijn machinehandleiding ontbreken nog vóór je instellingen adviseert?"*
- *"Zet mijn couponmetingen in het testlog en scheid meting van vuistregel."*
- *"Vergelijk deze snijranden en kies welke ene parameter ik daarna test."*

## Bronnen en bewijsniveau

- Autodesk, **Export DXF** vanuit een schets:
  <https://help.autodesk.com/view/fusion360/ENU/?caas=caas%2Fsfdcarticles%2Fsfdcarticles%2FHow-to-Save-Sketch-as-DXF-in-Fusion-360.html>
  — **Geverifieerd**, gecontroleerd 2026-08-07.
- Trotec, verboden materialen:
  <https://www.troteclaser.com/static/pdf/q-series/8060-Q400-operating-manual-EN.pdf> —
  **Geverifieerd voor die handleiding**, gecontroleerd 2026-08-07; de eigen machinehandleiding
  blijft leidend.
- Trotec, één parameter tegelijk testen:
  <https://www.troteclaser.com/en-us/helpcenter/materials/laser-parameter/laser-parameter-basics-settings>
  — **Geverifieerd**, gecontroleerd 2026-08-07.
- Kerf- en passingmethode — **Experiment**; pas geverifieerd voor de eigen combinatie na de
  vastgelegde couponmeting.

