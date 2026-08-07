# CNC-frezen — van Fusion-model naar gecontroleerde eerste snede

## Welk probleem lost dit op?

Een model wordt pas een veilig en voorspelbaar freesprogramma wanneer stock, nulpunt,
gereedschap, opspanning, banen, simulatie en postprocessor dezelfde werkelijkheid beschrijven.
Deze workflow voert één eenvoudig 2.5D-onderdeel door die hele keten.

Open [`index.html`](./index.html) en druk op **Afspelen** voor de volgorde.

## Waarom dit voor jouw werkplaats telt

Je ontwerpt al 2D in Fusion; zie
[`docs/workshop-profile.md`](../../docs/workshop-profile.md). Exacte CNC, spindel, controller,
werkbereik en frezen zijn nog niet bevestigd. Daarom geeft deze gids een deterministische
inbedrijfstelroute en een rekenvoorbeeld, geen universele voeding of snedediepte.

## Benodigdheden

- Fusion 360 Personal Use;
- exact machine- en controllermodel plus handleiding;
- materiaal met gemeten afmetingen;
- frees waarvan diameter, aantal snijkanten en aanbevolen startgegevens bekend zijn;
- passende collet, opspanning en spoilboard;
- schuifmaat;
- [`eerste-snee-log.md`](./eerste-snee-log.md).

## Eerst bevestigen

Noteer vóór CAM:

- XYZ-werkbereik en positieve richtingen;
- spindeltoerentalbereik en maximaal toegestane collet/frees;
- controller en juiste Fusion-postprocessor;
- werkelijke freesdiameter, snijlengte, aantal snijkanten en materiaaladvies;
- stockmateriaal en -dikte;
- opspanmethode en locaties van klemmen/schroeven;
- waar het werkstuknulpunt fysiek wordt gezet.

## Stappenplan

### 1. Maak het onderdeel als 3D-body

Ook voor een vlak onderdeel is een body met werkelijke dikte duidelijker dan alleen lijnen.

1. Geef plaatdikte en hoofdafmetingen benoemde User Parameters.
2. Extrudeer de buitenvorm tot de gemeten materiaaldikte.
3. Modelleer gaten en pockets op hun echte diepte.
4. Controleer binnenhoeken: een ronde frees kan geen perfecte scherpe binnenhoek maken.
5. Bewaar dit Fusion-bestand als ontwerpbron.

### 2. Maak een Manufacture Setup

1. Ga naar de werkruimte **Manufacture**.
2. Kies **Setup → New Setup** en **Milling**.
3. Selecteer alleen de bedoelde body als **Model**.
4. Definieer onder **Stock** de werkelijk beschikbare plaat, niet een willekeurige standaard.
5. Zet de **WCS Orientation** gelijk aan de assen van de echte machine.
6. Kies een herkenbaar **Stock point** als nulpunt, bijvoorbeeld bovenzijde/voorste linkerhoek,
   maar alleen als je dat punt fysiek reproduceerbaar kunt meten.

Controleer de rode X-, groene Y- en blauwe Z-pijl. Een verkeerde pijl maakt iedere latere baan
netjes verkeerd.

### 3. Voeg opspanning toe aan het model

Modelleer of selecteer klemmen en andere fixtures in de Setup wanneer dat kan. Houd schroeven,
klemmen en vacuümzones buiten de freesbaan. Opspanning moet zijdelingse snijkracht én opwaartse
kracht van een up-cut frees kunnen weerstaan.

Voer vóór CAM een handtest uit: stock mag onder stevige handkracht niet schuiven, kantelen of
veren. Dat bewijst nog niet dat hij freesbelasting houdt, maar een werkstuk dat met de hand
beweegt is sowieso niet klaar.

### 4. Maak één correct Tool-record

Vul in de Tool Library geen gok in. Controleer:

- diameter;
- aantal snijkanten;
- snijlengte en totale uitsteek;
- toerental;
- cutting feed en plunge/ramp feed;
- toolnummer dat bij de machineworkflow past.

De samenhang heet spaandikte per tand:

```text
spaandikte = voeding ÷ (toerental × aantal snijkanten)
voeding = spaandikte × toerental × aantal snijkanten
```

Rekenvoorbeeld, **geen instelling voor jouw machine**: 0,05 mm/tand × 18.000 rpm × 1 snijkant
= 900 mm/min. Gebruik voor de echte eerste test het gereedschapsadvies, begrensd door stijfheid,
spindel en materiaal, en leg iedere afwijking vast.

### 5. Programmeer binnenwerk vóór de buitencontour

Voor een eenvoudig plaatdeel:

1. **Face** alleen als de bovenkant werkelijk gevlakt moet worden.
2. **2D Pocket** voor kamers en uitsparingen.
3. **Bore/Drill** of passende strategie voor gaten.
4. **2D Contour** voor de buitenkant, als laatste.
5. Zet bij de buitencontour **Tabs** aan wanneer de restplaat het onderdeel anders loslaat.

Controleer per bewerking de tabbladen **Tool**, **Geometry**, **Heights**, **Passes** en
**Linking**. Let vooral op bovenhoogte, bodemhoogte, maximale stepdown, ramp/entry en eventuele
stock to leave. Een groene baan is geen bewijs dat de diepte klopt.

### 6. Genereer en simuleer de hele Setup

1. Selecteer de Setup of alle bewerkingen.
2. Klik **Actions → Simulate**.
3. Toon stock en toolpath.
4. Kijk vanaf begin tot eind, niet alleen naar de mooie snijbeweging.
5. Controleer de lijst met collisions/issues.
6. Kijk of gaten/pockets vóór de buitencontour komen.
7. Controleer retracts, klemmen, houder, bodemdiepte en restmateriaal.

Autodesk waarschuwt dat simulatie zonder machinemodel minder nauwkeurig is voor echte
machinebewegingen. Behandel “geen botsing gevonden” daarom niet als garantie.

### 7. Postprocess met de juiste machinevertaler

1. Zorg dat alle gekozen bewerkingen gegenereerd zijn.
2. Klik **Actions → Post Process**.
3. Kies de postprocessor die bij controller én machine hoort.
4. Kies bestandsnaam en uitvoermap.
5. Controleer de waarschuwingen van de postprocessor.

Fusion Personal Use verwijdert echte rapid-moves uit output en kan geen programma met
automatische wissels voor meerdere gereedschappen posten. Gebruik je meerdere frezen, post dan
per gereedschap een afzonderlijk bestand en voer de fysieke wissel/nulpuntprocedure bewust uit.

### 8. Doe een air-cut boven het materiaal

Voer het nieuwe programma eerst uit zonder materiaal te raken, bijvoorbeeld met een tijdelijk
Z-nulpunt boven de stock volgens de veilige procedure van de eigen controller.

Controleer:

- assen gaan de verwachte kant op;
- nulpunt ligt op de bedoelde hoek;
- baan blijft binnen werkbereik;
- frees en houder blijven vrij van klemmen;
- spindel-/toolcommando's passen bij de machine.

Hoe een air-cut exact wordt ingesteld is controllerafhankelijk. Volg de machinehandleiding;
improviseer niet met een onbekende Z-offset.

### 9. Maak de eerste echte snede onder toezicht

1. Zet het echte XYZ-nulpunt opnieuw volgens de machineprocedure.
2. Controleer collet, uitsteek, stock en klemmen nogmaals.
3. Start met het geteste, conservatieve gereedschapsrecord.
4. Houd hand bij stop/feed-hold.
5. Kijk en luister naar de eerste insteek en eerste volledige baan.
6. Stop bij verschuiving, oplopend geluid, stof in plaats van passende spanen, smelten,
   verbranden of chatter.
7. Meet het proefkenmerk vóór de buitencontour het onderdeel losmaakt.

## Zo controleer je het resultaat

De eerste-snee-workflow is geslaagd als:

1. stock- en modelmaten in Fusion overeenkomen met de schuifmaat;
2. WCS-pijlen en fysiek nulpunt dezelfde richting/hoek beschrijven;
3. simulatie geen onverklaarde botsing of overtravel meldt;
4. air-cut vrij blijft van stock en opspanning;
5. het eerste gat/pocket meetbaar binnen de projecttolerantie valt;
6. log, Fusion-bestand, postprocessor en NC-bestand dezelfde revisie hebben.

## Veelgemaakte fouten

- Een “vergelijkbare” postprocessor kiezen zonder controller/machine te bevestigen.
- Stockdikte uit de verpakking gebruiken in plaats van meten.
- X/Y/Z-pijlen niet vergelijken met de echte machine.
- Industriële feeds/speeds rechtstreeks op een flexibele hobbyrouter zetten.
- Langzamer voeren zonder toerental aan te passen, waardoor de frees wrijft in plaats van snijdt.
- Buitencontour te vroeg frezen of tabs vergeten.
- Alleen toolpunt simuleren en houder/klemmen vergeten.
- Denken dat simulatie een air-cut overbodig maakt.

## Wanneer vraag je Claude om hulp?

- *"Welke machine-, controller- en freesgegevens ontbreken nog voordat je een Tool-record kunt beoordelen?"*
- *"Controleer mijn WCS en stock op basis van deze screenshots; verzin geen machine-asrichting."*
- *"Bereken spaandikte uit deze vier gemeten waarden en vergelijk alleen met de fabrikanttabel."*
- *"Loop mijn toolpaths in bewerkingsvolgorde na en zoek losraken, verkeerde hoogtes en klemrisico."*
- *"Maak van deze eerste snede een A/B-test met één veranderde parameter."*

## Bronnen en bewijsniveau

- Autodesk Manufacture-workflow:
  <https://help.autodesk.com/view/fusion360/ENU/?guid=GUID-BEC5DEA9-AC3E-4FA8-998E-4AE8CD0D0B1E>
  — **Geverifieerd**, gecontroleerd 2026-08-07.
- Autodesk 2D Contour en tabs:
  <https://help.autodesk.com/view/fusion360/ENU/?guid=GUID75B6821B-DE26-4E3B-AF10-4A54131CD9E4>
  — **Geverifieerd**, gecontroleerd 2026-08-07.
- Autodesk simulatie:
  <https://help.autodesk.com/view/fusion360/ENU/?contextId=MFG-REF-SIMULATION> —
  **Geverifieerd**, gecontroleerd 2026-08-07.
- Autodesk postprocessen:
  <https://help.autodesk.com/view/fusion360/ENU/?contextId=MFG-POST-PROCESS-OPERATIONS> —
  **Geverifieerd**, gecontroleerd 2026-08-07.
- Autodesk Personal Use-beperkingen:
  <https://help.autodesk.com/view/fusion360/ENU/?caas=caas%2Fsfdcarticles%2Fsfdcarticles%2FFusion-360-Free-License-Changes.html>
  — **Geverifieerd**, gecontroleerd 2026-08-07.
- Feeds, speeds, stepdown en opspanning voor de onbekende eigen machine — **Nog bevestigen**;
  leg de eerste proef vast voordat een waarde werkplaatskennis wordt.

