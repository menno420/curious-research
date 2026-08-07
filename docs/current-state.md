# Huidige staat van curious-research

*Agent-facing statusdocument. Laatst inhoudelijk gecontroleerd: 2026-08-07. Gebruik geen oude
aantallen uit commits of gesprekken; bepaal inventaris altijd uit de huidige mappen en
`guides/README.md`.*

## Rol van de repository

Dit is een Nederlandse kennislaag voor een ervaren hobby-maker, niet alleen een verzameling
researchnotities. Claude hoort eerst de werkplaatscontext te lezen, daarna relevante bestaande
kennis en pas dan een antwoord of wijziging te maken.

De bronnen zijn gescheiden:

| Soort waarheid | Enige thuisbasis |
|---|---|
| Eigenaar, hardware, software, vaardigheid en onbekende gegevens | [`workshop-profile.md`](workshop-profile.md) |
| Gedrag van Claude in deze repository | [`../CLAUDE.md`](../CLAUDE.md) |
| Bewijsniveaus en promotie van claims | [`knowledge-policy.md`](knowledge-policy.md) |
| Guideformat en uitlegkwaliteit | [`teaching-style.md`](teaching-style.md) |
| Actieve gidsinventaris en compatibele oude paden | [`../guides/README.md`](../guides/README.md) |
| Ruwe researchprovenance | [`../research/dossiers/README.md`](../research/dossiers/README.md) |
| Korte gepubliceerde kenniskaarten | `KENNIS` in [`../site/kennis.html`](../site/kennis.html) |

Dupliceer werkplaatsfeiten niet in gidsen. Voeg ontbrekende hardwaregegevens eerst aan het profiel
toe, met herkomst en bewijsniveau.

## Giftklare gebruikersroute

De normale route is volledig Nederlands:

1. [`../README.md`](../README.md) — cadeau-ingang en kaart van de repository;
2. [`../site/github-en-ai.html`](../site/github-en-ai.html) — hetzelfde actuele profiel aan
   Claude of ChatGPT geven, zonder eigen GitHub-account;
3. [`../guides/begin-hier/`](../guides/begin-hier/) — contextcontrole en eerste echte vraag;
4. [`claude-usage-guide.md`](claude-usage-guide.md) — website + chat als hoofdroute, met
   projectupload en lokale repository als latere opties;
5. [`../site/projecten.html`](../site/projecten.html) — projectuitleg vóór broncode;
6. [`../site/kennis.html`](../site/kennis.html) — korte antwoorden met vijf bewijslabels.

Oude Engelstalige guidepaden voor start, infill, speling en armwerkgebied bestaan alleen als
compatibele verwijzing naar de Nederlandse bron. De actieve Bambu-, Fusion-, Arduino-, robotarm-,
laser- en CNC-gidsen zijn herschreven als uitvoeringsroutes.

## Inhoud die nu beschikbaar is

### Bambu Lab en 3D-printen

- één overkoepelende Bambu Studio-diagnose voor A1/A1 mini;
- eerste laag zonder generieke handmatige Z-offset;
- stringing met vocht/temperatuur/retraction als afzonderlijke proeven;
- temperatuurreeks met controle dat de temperatuur echt verandert;
- onderdeelkoeling met vorm én laaghechting als criteria;
- vulling, speling en lithofaan van proef naar gemeten ontwerpwaarde.

Normale materialen, nozzlevarianten en eigen profielafwijkingen zijn nog niet bevestigd. Guides
moeten daarom vanuit het echte geselecteerde profiel werken.

### Fusion en productie

- Python-script maken en uitvoeren in de huidige Fusion-interface;
- lasersnijden: Fusion-schets → DXF → importcontrole → kerf-/passingcoupon → proefsnede →
  assemblage;
- CNC: body → Manufacture Setup/WCS → toolrecord → banen → simulatie → postprocess → air cut →
  eerste snede.

Exact lasermodel, laserprincipe/software, CNC-machine, controller, spindel en frezen zijn nog
onbekend. Daarom staan er geen universele snelheden, vermogens, postprocessors of feeds/speeds in
het profiel.

### Arduino

De gids `arduino-zonder-blokkeren` bevat een uitvoerbare `millis()`-workflow en voorbeeldsketch.
Het exacte Arduino-bord en gebruikte sensorinventaris zijn nog niet vastgelegd; bordspanning en
pinmogelijkheden mogen niet worden aangenomen.

Het filamentwegerproject heeft een Nederlandse uitvoeringsgids en leeg meetlog. Universele
`±5 g`-resolutie, vaste loadcelldraadkleuren, aangenomen Uno/Nano-bezit en vooraf ingevulde
merkgewichten zijn verwijderd. Kalibratie volgt de officiële `HX711_ADC`-route; prestaties en
drift blijven experimenten op de echte constructie. De sketch is niet gecompileerd zolang exact
board, core en libraries ontbreken.

### Robotarm

Bevestigd:

- zelfgebouwde 6-DOF-arm;
- MG996R-klasse servo's;
- de arm is volgens de maker al met een controller gebruikt (bevestigd 2026-08-07);
- projecten voor penplotter, soepele beweging, herhaalbaarheid en verwisselbaar gereedschap.

Nog niet bevestigd:

- exacte fabrikant/variant per servo;
- pinvolgorde en draairichting op de echte arm;
- gemeten min/max/midden per gewricht;
- voedingsspanning, continue/piekstroom, zekering en draadcapaciteit;
- echte payload en herhaalbaarheid;
- exact controllermodel en werkende firmware/sketch;
- veilig gecontroleerde startupstand van de repositorysketches.

Kritisch broncodefeit: `projects/arm-pen-plotter/pen_plotter_arm.ino` koppelt in `setup()` alle
servo's aan en schrijft 90° voordat gemeten limieten zijn ontvangen. De laptoptool vereist een
geldig kalibratiebestand vóór **gecontroleerde bediening**, maar dat verhindert deze fysieke
startupopdracht niet. De smooth-motion-sketch stuurt eveneens direct zijn `JOINT_HOME` en begint
daarna automatisch te bewegen. Negentig graden is geen bewezen gezamenlijke startupstand.

Zie [`../arm/README.md`](../arm/README.md). De arm is niet als ongebruikt of onbeproefd
gedocumenteerd: de bestaande controllerroute dient als referentie. Upload geen meegeleverde
repositorysketch voordat startup, pinvolgorde en homewaarden daarmee zijn vergeleken en onder
toezicht zijn vastgelegd.

De smooth-motionuitleg behandelt 20 ms als refresh-interval van de Arduino Servo-library, niet
als bewezen interne regelsnelheid van iedere MG996R-variant. Rustiger opdrachtprofiel is een
experiment; stroompiek, overshoot en trilling vragen afzonderlijke metingen. De sketch corrigeert
de S-curveduur met factor 1,5, zodat `maxSnelheid` ook voor smoothstep de berekende piek van het
opdrachtprofiel begrenst.

### OpenSCAD-modellen

Op 2026-08-07 zijn alle huidige `.scad`-bronnen met OpenSCAD 2021.01 gerenderd. De controle omvat
de standaardconfiguraties en relevante alternatieve parameterpaden die in
`.github/scripts/check_openscad.sh` staan. Alle exports zijn eenvoudige manifold STL-meshes zonder
waarschuwingen. De grijper had aanvankelijk nul-diktecontact tussen tanden en tandvoet; een
expliciete overlap in de bron heeft dat meshprobleem opgelost.

Deze status bewijst syntactisch en geometrisch renderbare bron, niet de fysieke maatvoering,
sterkte, passing, tandingreep, slicing of printkwaliteit. Er worden daarom geen gegenereerde STL's
als bewezen onderdelen gepubliceerd. De parametrische `.scad`-bestanden blijven de master.

## Projectarchitectuur

De maker landt vanuit de site op [`../site/projecten.html`](../site/projecten.html), niet direct
op een GitHub-directory. Ieder project heeft daar:

- wat het is en doet;
- waarom het nuttig is;
- benodigdheden;
- bouwstappen;
- testcriterium;
- mogelijke verbetering;
- pas daarna links naar bronbestanden.

Die pagina behandelt de pasmunt, filamentweger, penplotter, soepele armbeweging en verwisselbaar
gereedschap. Diepere bron-README's kunnen historische ontwerpnotities bevatten; zij zijn niet de
eerste gebruikerservaring en mogen geen sterkere veiligheidsclaim maken dan de Nederlandse
projectroute. De filamentweger-README is volledig Nederlands en bevat hardware-inventaris,
functiebedrading en meetcriteria.

## Vertrouwen en provenance

De site gebruikt uitsluitend:

- `verified` / **Geverifieerd**;
- `supported` / **Onderbouwd**;
- `practical` / **Praktijkadvies**;
- `confirm` / **Nog bevestigen**;
- `experimental` / **Experiment**.

Een bronlink alleen is onvoldoende voor **Geverifieerd**; de geopende primaire bron moet precies
de claim dragen en een controledatum hebben. Onbevestigde servo-, voeding-, laser- en CNC-waarden
blijven expliciet meetwerk.

De bestanden in `research/dossiers/` zijn ongewijzigde uitvoer van onderzoeksruns. De
provenancetabel vermeldt tool, onderwerp en corroboratiestatus. Lasersnijden heeft maar één
onafhankelijke run en verdient extra controle. Oude labels in ruwe dossiers zijn geen huidige
goedkeuring; iedere claim wordt opnieuw beoordeeld voordat hij in een gids of kenniskaart komt.

## AI en persistentie

[`claude-usage-guide.md`](claude-usage-guide.md) beschrijft drie oplopende routes:

- website + gewone Claude- of ChatGPT-chat als directe hoofdroute;
- relevante bestanden als projectkennis uploaden wanneer de gekozen dienst dat aanbiedt;
- de repository later lokaal downloaden/clonen en desgewenst Claude Code gebruiken.

De publieke pagina `site/github-en-ai.html` laadt het canonieke werkplaatsprofiel rechtstreeks
uit GitHub en biedt een kopieerbare fallback. We claimen geen automatische repositorymemory:
een AI moet de URL werkelijk openen of de tekst ontvangen. Chatantwoorden wijzigen geen bestand;
een getest resultaat wordt pas duurzame kennis na gecontroleerde bestandswijziging en merge.

## Site en navigatie

De statische site heeft geen hardgecodeerd totaal aantal gidsen of projecten in de kop. De
kennisbank telt kaarten dynamisch uit het `KENNIS`-object. Nieuwe gidsen worden in
`guides/README.md` én `site/index.html` opgenomen; oude dubbele bronnen worden als alias behouden
of verwijderd, niet apart verder onderhouden.

GitHub Pages assembleert `site/` plus de HTML onder `guides/`. Markdown blijft leesbaar via de
repository. `github-en-ai.html` verwijst voor het profiel naar het ene canonieke Markdownbestand
op `main`, zodat geen tweede handmatig bijgehouden hardwareprofiel ontstaat. Na wijzigingen aan
site of gidsen moet de Pages-deploy afzonderlijk worden gecontroleerd; een groene linkcheck
bewijst niet dat de openbare site al is bijgewerkt.

## Validatie vóór publicatie

Voer minimaal uit:

```bash
python3 .github/scripts/check_links.py
python3 -m py_compile projects/arm-pen-plotter/teach_and_replay.py
bash .github/scripts/check_openscad.sh
```

Controleer daarnaast:

- JavaScript-syntax van iedere HTML-`script`;
- alle actieve guidepagina's hebben `lang="nl"`;
- geen oude labels `ZEKER`, `MEESTAL` of `BETWIST` meer als kennisstatus;
- geen vaste inventarisaantallen in gebruikersdocumentatie;
- geen claim “geen kalibratie = geen fysieke beweging”;
- geen claim dat chat, projectuploads of lokale auto-memory de repository automatisch bijwerkt;
- links en navigatie vanaf `site/index.html`, `site/projecten.html` en `guides/README.md`.

De verplichte `substrate-gate` installeert OpenSCAD en voert de rendercontrole bij iedere PR en
push naar `main` opnieuw uit. Arduino-sketches kunnen pas betrouwbaar tegen een boardprofiel worden
gecompileerd nadat het exacte board en de benodigde libraries zijn vastgelegd.

## Vragen die alleen de maker kan sluiten

1. Welke materialen, nozzleformaten en eigen Bambu-profielen gebruikt hij normaal?
2. Welk exact lasermerk/model, principe, lens/focusmethode en software gebruikt hij?
3. Welke CNC, controller, spindel, collets en frezen staan er?
4. Welke Arduino-borden en veelgebruikte sensoren liggen er?
5. Welk exact controllermodel, welke werkende firmware/sketch, servovarianten, pinvolgorde en
   voeding gebruikt de arm?
6. Wat zijn de gemeten gewrichtslimieten, homewaarden en startupresultaten van die werkende
   configuratie en van iedere nieuwe repositorysketch?
7. Welk exact Arduino-bord, loadcellmodel, HX711-module en optioneel OLED wordt voor de
   filamentweger gekozen?

Zodra een antwoord is gemeten of uit een primaire bron komt: werk eerst
`workshop-profile.md` bij, voeg datum/herkomst toe en laat gidsen ernaar verwijzen.
