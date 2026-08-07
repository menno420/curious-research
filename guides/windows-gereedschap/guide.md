# Windows-gereedschap — installeer alleen wat de volgende stap nodig heeft

## Welk probleem lost dit op?

Deze repository bevat HTML, Arduino-sketches, OpenSCAD-modellen, Fusion-scripts en enkele lokale
Python-tools. Je hoeft niet alles vooraf te installeren. Deze route koppelt ieder programma aan
een concreet bestand en een succescontrole.

Open [`index.html`](./index.html) voor de keuzehulp.

## Waarom dit voor jouw werkplaats telt

Windows, Bambu Studio, Fusion 360 Personal Use en Arduino IDE horen bij het werkplaatsprofiel.
Claude Code is de aanbevolen manier om de hele map als context te gebruiken. OpenSCAD en lokale
Python zijn alleen nodig voor specifieke bestaande projecten.

## Benodigdheden

- Windows-pc en internet voor installatie;
- rechten om programma's op die pc te installeren;
- de uitgepakte repositorymap;
- het concrete bestand of project dat je als volgende wilt gebruiken.

## Stappenplan

### 1. Claude Code — voor vragen met de hele map als context

Volg één keer [`docs/claude-usage-guide.md`](../../docs/claude-usage-guide.md). Daar staat de
actuele WinGet-opdracht, login met Claude Pro, start vanuit de juiste map en contextcontrole. Houd
installatie-instructies op die ene plek om drift te voorkomen.

### 2. Bambu Studio — voor A1 en A1 mini

Download of update via <https://bambulab.com/en/download/studio>. Controleer na starten dat A1,
A1 mini, werkelijk nozzleformaat en fysieke plaat als profielen beschikbaar zijn.

**Geslaagd als:** een STL/3MF opent, `Slice Plate` werkt en Preview wanden, support en
kleurwissels toont.

### 3. Arduino IDE — voor `.ino`-bestanden

Download via <https://www.arduino.cc/en/software>. Kies de actuele 64-bit Windows-installer die
bij jouw Windows-versie hoort.

1. Sluit het board via USB aan.
2. Kies in de IDE het **werkelijke** board en de poort; het boardmodel is nog niet canoniek
   vastgelegd.
3. Open eerst [`arduino-zonder-blokkeren/zonder_delay.ino`](../arduino-zonder-blokkeren/zonder_delay.ino)
   of een andere sketch zonder aangesloten actuator.
4. Klik **Verify** en daarna **Upload**.

**Geslaagd als:** de IDE zonder compileerfout uploadt en de Serial Monitor op de ingestelde baud
de verwachte banner toont.

### 4. OpenSCAD — alleen voor bestaande `.scad`-projecten

Download via <https://openscad.org/downloads.html>. Open bijvoorbeeld
[`projects/tolerance-test-coin/tolerance-test-coin.scad`](../../projects/tolerance-test-coin/tolerance-test-coin.scad),
druk **F6** en kies **File → Export → Export as STL**.

OpenSCAD is niet de ontwerpstandaard voor nieuw Fusion-werk. Het blijft nuttig omdat bestaande
projectmodellen als tekst zijn opgeslagen en daardoor direct door Claude kunnen worden aangepast.

**Geslaagd als:** Bambu Studio de geëxporteerde STL opent en de maat overeenkomt met de
SCAD-parameter.

### 5. Lokale Python — alleen voor een Python-projecttool

Een Fusion-Python-script draait in Fusion en vereist geen losse Python-installatie. De
penplottertool `teach_and_replay.py` draait wél lokaal en heeft Python plus de gebruikte packages
nodig. Installeer Python pas wanneer dat project aan de beurt is, via
<https://www.python.org/downloads/windows/>, en controleer de project-README eerst.

**Geslaagd als:** `python --version` in PowerShell een versie toont en de betreffende tool in
dry-run start. Sluit geen armhardware aan om alleen de installatie te controleren.

### 6. Teksteditor — optioneel

Kladblok is voldoende voor kleine wijzigingen. Een editor zoals Notepad++ of VS Code is alleen
handig als je graag regelnummering, zoeken en syntaxkleur wilt. Git is niet nodig om vandaag te
vragen en testen; maak zonder GitHub wel een kopie van de gewijzigde lokale map.

## Zo controleer je het resultaat

Installeer per sessie maar één programma en bewijs één keten, bijvoorbeeld:

- `guide.md` en `index.html` lokaal openen;
- STL openen → slicen → Preview;
- `.ino` verifiëren → uploaden → Serial-banner;
- `.scad` renderen → STL-maat controleren;
- Claude Code starten → werkplaatscontext correct laten samenvatten.

## Veelgemaakte fouten

- Alle hulpmiddelen installeren voordat er een concrete taak is.
- Claude vanuit `Downloads` starten in plaats van uit de uitgepakte repositorymap.
- Een Arduino-board of COM-poort raden.
- Denken dat Fusion-scripts de lokale Python-installatie gebruiken.
- Een lokaal gewijzigd bestand als online back-up behandelen.
- Servo's aansluiten om alleen een software-installatie te testen.

## Wanneer vraag je Claude?

- *"Welk ene programma heb ik voor dit bestand nodig, en hoe controleer ik de installatie?"*
- *"Lees de project-README en geef alleen de Windows-stappen die vóór een dry-run nodig zijn."*
- *"Welke software heb ik al volgens het werkplaatsprofiel?"*
- *"Help deze compileerfout lezen zonder pinnen of boardmodel te verzinnen."*

## Bronnen en bewijsniveau

- Officiële downloads: [Bambu Studio](https://bambulab.com/en/download/studio),
  [Arduino IDE](https://www.arduino.cc/en/software),
  [OpenSCAD](https://openscad.org/downloads.html),
  [Python voor Windows](https://www.python.org/downloads/windows/) — **Onderbouwd**; controleer
  de actuele versie en systeemvereisten op de pagina.
- Claude Code-installatie — één canonieke bron in
  [`docs/claude-usage-guide.md`](../../docs/claude-usage-guide.md).
