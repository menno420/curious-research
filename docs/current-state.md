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
2. [`../guides/begin-hier/`](../guides/begin-hier/) — eerste contextcontrole en echte vraag;
3. [`claude-usage-guide.md`](claude-usage-guide.md) — Claude Pro en Claude Code op Windows;
4. [`../site/index.html`](../site/index.html) — gidsen gegroepeerd per werkplaatstype;
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

### Robotarm

Bevestigd:

- zelfgebouwde 6-DOF-arm;
- MG996R-klasse servo's;
- projecten voor penplotter, soepele beweging, herhaalbaarheid en verwisselbaar gereedschap.

Nog niet bevestigd:

- exacte fabrikant/variant per servo;
- pinvolgorde en draairichting op de echte arm;
- gemeten min/max/midden per gewricht;
- voedingsspanning, continue/piekstroom, zekering en draadcapaciteit;
- echte payload en herhaalbaarheid;
- veilig gecontroleerde startupstand.

Kritisch broncodefeit: `projects/arm-pen-plotter/pen_plotter_arm.ino` koppelt in `setup()` alle
servo's aan en schrijft 90° voordat gemeten limieten zijn ontvangen. De laptoptool vereist een
geldig kalibratiebestand vóór **gecontroleerde bediening**, maar dat verhindert deze fysieke
startupopdracht niet. De smooth-motion-sketch stuurt eveneens direct zijn `JOINT_HOME` en begint
daarna automatisch te bewegen. Negentig graden is geen bewezen gezamenlijke startupstand.

Zie [`../arm/README.md`](../arm/README.md) en gebruik geen powered armproject voordat startup,
pinvolgorde en homewaarden op de echte arm onder toezicht zijn opgelost en vastgelegd.

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
gereedschap. Diepere bron-README's kunnen historische Engelstalige ontwerpnotities bevatten; zij
zijn niet de eerste gebruikerservaring en mogen geen sterkere veiligheidsclaim maken dan de
Nederlandse projectroute.

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

## Claude en persistentie

[`claude-usage-guide.md`](claude-usage-guide.md) beschrijft twee routes:

- Claude Code starten vanuit de uitgepakte repositorymap;
- relevante bestanden uploaden als Claude Project knowledge.

We claimen geen automatische repositorymemory. Chatantwoorden wijzigen geen bestand; lokale
automatische notities zijn niet automatisch gedeeld of geback-upt. Een getest resultaat wordt
pas durable kennis na gecontroleerde bestandswijziging en back-up/publicatie.

## Site en navigatie

De statische site heeft geen hardgecodeerd totaal aantal gidsen of projecten in de kop. De
kennisbank telt kaarten dynamisch uit het `KENNIS`-object. Nieuwe gidsen worden in
`guides/README.md` én `site/index.html` opgenomen; oude dubbele bronnen worden als alias behouden
of verwijderd, niet apart verder onderhouden.

GitHub Pages assembleert `site/` plus de HTML onder `guides/`. Markdown blijft leesbaar via de
repository. Na wijzigingen aan site of gidsen moet de Pages-deploy afzonderlijk worden
gecontroleerd; een groene linkcheck bewijst niet dat de openbare site al is bijgewerkt.

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
- geen claim dat chat, Claude Projects of lokale auto-memory de repository automatisch bijwerkt;
- links en navigatie vanaf `site/index.html`, `site/projecten.html` en `guides/README.md`.

De verplichte `substrate-gate` installeert OpenSCAD en voert de rendercontrole bij iedere PR en
push naar `main` opnieuw uit. Arduino-sketches kunnen pas betrouwbaar tegen een boardprofiel worden
gecompileerd nadat het exacte board en de benodigde libraries zijn vastgelegd.

## Vragen die alleen de maker kan sluiten

1. Welke materialen, nozzleformaten en eigen Bambu-profielen gebruikt hij normaal?
2. Welk exact lasermerk/model, principe, lens/focusmethode en software gebruikt hij?
3. Welke CNC, controller, spindel, collets en frezen staan er?
4. Welke Arduino-borden en veelgebruikte sensoren liggen er?
5. Welke exacte servovarianten, pinvolgorde en voeding heeft de arm?
6. Wat zijn de gemeten gewrichtslimieten, homewaarden en startupresultaten?

Zodra een antwoord is gemeten of uit een primaire bron komt: werk eerst
`workshop-profile.md` bij, voeg datum/herkomst toe en laat gidsen ernaar verwijzen.
