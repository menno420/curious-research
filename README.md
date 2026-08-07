# curious-research 🔬

> ## Een werkplaatsassistent als cadeau 🎁
>
> Deze map is gemaakt voor jouw Bambu-printers, Fusion 360-werk, Arduino-projecten en
> 6-DOF-robotarm. De website maakt de kennis leesbaar; het openbare werkplaatsprofiel geeft
> Claude of ChatGPT steeds dezelfde gecontroleerde basiscontext.

## Begin hier

1. Open de [website met gidsen, projecten en naslag](https://menno420.github.io/curious-research/).
2. Kies **GitHub + AI** en kopieer de actuele werkplaatscontext naar Claude of ChatGPT.
3. Gebruik [de Nederlandse rondleiding](guides/begin-hier/guide.md) voor een eerste echte vraag.
4. Lees indien nodig [AI gebruiken met deze werkplaatskennis](docs/claude-usage-guide.md).

Een eigen GitHub-account, clone of lokale AI-installatie is voor deze eerste route niet nodig.

## Wat Claude al over de werkplaats weet

De ene bron van waarheid is [docs/workshop-profile.md](docs/workshop-profile.md). Daarin staan:

- Bambu Lab A1, A1 mini en AMS Lite met Bambu Studio;
- Fusion 360 Personal Use, lasersnijden en CNC-frezen/routeren;
- Arduino, sensoren en hobbyrobotica;
- een zelfgebouwde 6-DOF-arm met MG996R-klasse servo's;
- Windows, Nederlands als standaardtaal en weinig code-ervaring maar sterke technische
  redeneervaardigheid;
- expliciet welke machine-, materiaal-, servo- en voedingsdetails nog **niet** bevestigd zijn.

Hardwarefeiten horen alleen in dat profiel. Gidsen verwijzen ernaar in plaats van dezelfde
gegevens te kopiëren.

## Zo stel je een bruikbare vraag

Goed:

```text
Mijn A1-print trekt linksvoor los. Lees eerst het werkplaatsprofiel, geef maximaal drie
hypotheses en maak één kleine test waarbij maar één variabele verandert.
```

```text
Ik wil dit Fusion-onderdeel uit plaat maken. Vergelijk laser en CNC voor deze geometrie en
noem eerst welke machine-, materiaal- en tolerantiegegevens nog ontbreken.
```

Te breed:

```text
Leg 3D-printen uit.
```

Een foto helpt als er ook een overzicht, scherp detail en niet-zichtbare context bij zitten.
Gebruik daarvoor [de beeld-naar-testgids](guides/what-can-claude-see/guide.md).

## Chat is niet hetzelfde als duurzaam geheugen

Claude of ChatGPT kan de openbare context gebruiken als de assistent de gedeelde URL werkelijk
opent, of als je de tekst plakt of uploadt. Een chatantwoord werkt de repository niet automatisch
bij. Waardevolle kennis wordt pas duurzaam als je:

1. de voorgestelde proef zelf uitvoert;
2. het resultaat en de omstandigheden controleert;
3. laat bepalen in welk bestaand bestand het thuishoort;
4. de wijziging naleest;
5. de map back-upt of later via GitHub publiceert.

GitHub is hierbij de gedeelde bron, niet automatisch AI-geheugen. Lees
[waarom GitHub handig is voor samenwerken met AI](docs/git-for-makers.md).

## De belangrijkste routes

| Onderwerp | Startpunt |
|---|---|
| Bambu Studio en printfouten | [Bambu Studio — van foutbeeld naar test](guides/bambu-studio/guide.md) |
| Fusion automatiseren | [Een Python-script in Fusion laden](guides/fusion-python/guide.md) |
| Arduino responsief houden | [Arduino zonder blokkerende wachttijden](guides/arduino-zonder-blokkeren/guide.md) |
| Lasersnijden | [Fusion → DXF → kerfproef → onderdeel](guides/lasersnijden-van-fusion-naar-onderdeel/guide.md) |
| CNC | [Fusion CAM → simulatie → air cut → eerste snede](guides/cnc-van-fusion-naar-eerste-snee/guide.md) |
| Robotarm | [Bevestigde context en startupgedrag](arm/README.md) |
| Bouwprojecten | [Nederlandse projectroutes](site/projecten.html) |
| Korte antwoorden | [Kennisbank met bewijslabels](site/kennis.html) |
| Dezelfde context voor Claude en ChatGPT | [GitHub + AI](site/github-en-ai.html) |

## Hoe vertrouwen zichtbaar blijft

[docs/knowledge-policy.md](docs/knowledge-policy.md) definieert vijf niveaus:

- **Geverifieerd** — de geopende primaire bron draagt de exacte claim;
- **Onderbouwd** — betrouwbare secundaire of meerdere bronnen;
- **Praktijkadvies** — nuttige makerroute, geen gegarandeerde specificatie;
- **Nog bevestigen** — bron of werkplaatsmeting ontbreekt;
- **Experiment** — expliciet te testen met een meetbaar resultaat.

Ruwe deep-researchrapporten in `research/dossiers/` zijn bronmateriaal, geen automatisch
goedgekeurde werkplaatskennis.

## Kaart van de repository

| Map/bestand | Functie |
|---|---|
| [`docs/workshop-profile.md`](docs/workshop-profile.md) | Canonieke eigenaar-, hardware- en softwarecontext |
| [`CLAUDE.md`](CLAUDE.md) | Gedragsregels die Claude bij iedere sessie leest |
| [`guides/`](guides/) | Nederlandstalige uitvoeringsgidsen met zelfstandige HTML-uitleg |
| [`projects/`](projects/) | Bronbestanden, sketches en diepere projectdocumentatie |
| [`site/`](site/) | Leesbare publieke ingang en kennisbank |
| [`arm/`](arm/) | Robotarmkalibratie, bekende beperkingen en startupwaarschuwingen |
| [`research/dossiers/`](research/dossiers/) | Ongewijzigde onderzoeksuitvoer met provenance-overzicht |
| [`ideas/`](ideas/) | Bestaande ideeën; een menukaart, geen takenlijst |

## Werkplaatsveiligheid zonder schijnzekerheid

Claude kan ontwerpen, berekenen en testplannen maken. Jij controleert het werkelijke materiaal,
de machinehandleiding, opspanning, voeding, nulpunten en uitschakeling en blijft bij een powered
test. Een softwareclamp bewijst geen botsingsveiligheid. De huidige penplotter-sketch kan bij
startup al 90° naar de servo's sturen; lees [arm/README.md](arm/README.md) vóór gebruik.

Deze repository is openbaar. Bewaar projectcontext en meetwaarden, geen adressen, sleutels,
privéfoto's of andere persoonsgegevens.
