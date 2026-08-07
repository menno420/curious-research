# Gidsen — uitvoerbaar naast de machine

Elke actieve gids heeft:

- `index.html` — een zelfstandige Nederlandse procesuitleg in de browser;
- `guide.md` — benodigdheden, stappen, succescontrole, fouten, Claude-vragen en bewijsstatus.

Hardware- en eigenaarfeiten worden niet in gidsen beheerd. De canonieke bron is
[`docs/workshop-profile.md`](../docs/workshop-profile.md); het format staat in
[`docs/teaching-style.md`](../docs/teaching-style.md).

## Start en Claude

| Gids | Doel |
|---|---|
| [`begin-hier/`](./begin-hier/) | Eerste contextcontrole, goede vraag en duurzame kennisworkflow |
| [`what-can-claude-see/`](./what-can-claude-see/) | Van foto/fouttekst naar observaties, hypotheses en één meetbare test |
| [`windows-gereedschap/`](./windows-gereedschap/) | Windows-hulpmiddelen; controleer actuele downloads vóór installatie |

## Bambu Lab A1 en A1 mini

| Gids | Doel |
|---|---|
| [`bambu-studio/`](./bambu-studio/) | Van foutbeeld naar een kleine A/B-test in Bambu Studio |
| [`first-layer/`](./first-layer/) | Plaat/profiel/nozzle controleren zonder generieke handmatige Z-offset |
| [`retraction-vs-stringing/`](./retraction-vs-stringing/) | Vocht, temperatuur en retraction één voor één scheiden |
| [`temperature-tower/`](./temperature-tower/) | Controleren dat temperatuur werkelijk verandert en resultaat per functie scoren |
| [`part-cooling/`](./part-cooling/) | Overhangvorm én laaghechting vergelijken |
| [`vulling/`](./vulling/) | Wanddikte, infill en gewicht met dezelfde testgeometrie vergelijken |
| [`speling/`](./speling/) | Passing meten in plaats van een universele tolerantie overnemen |
| [`lithophane-night-light/`](./lithophane-night-light/) | Foto → proefstrook → backlighttest → gemeten Fusion-frame |

## Fusion en productie

| Gids | Doel |
|---|---|
| [`fusion-python/`](./fusion-python/) | Een Python-script in de huidige Fusion-interface maken, uitvoeren en controleren |
| [`lasersnijden-van-fusion-naar-onderdeel/`](./lasersnijden-van-fusion-naar-onderdeel/) | Fusion-schets → DXF → schaalcheck → kerf-/passingcoupon → snede |
| [`cnc-van-fusion-naar-eerste-snee/`](./cnc-van-fusion-naar-eerste-snee/) | Model → Setup/WCS → toolpaths → simulatie → air cut → eerste snede |

## Arduino en robotarm

| Gids | Doel |
|---|---|
| [`arduino-zonder-blokkeren/`](./arduino-zonder-blokkeren/) | Meerdere taken responsief houden met onafhankelijke `millis()`-timers |
| [`arm-werkgebied/`](./arm-werkgebied/) | Gemeten hoekbereik vastleggen en claims over een softwareclamp begrenzen |
| [`arm-herhaalbaarheid-meten/`](./arm-herhaalbaarheid-meten/) | A→B→A-spreiding meten en één wijziging tegelijk vergelijken |

## Compatibele oude paden

Deze mappen blijven bestaan zodat bestaande links niet breken, maar verwijzen naar één actuele
Nederlandse bron:

| Oud pad | Actuele bron |
|---|---|
| [`start-here/`](./start-here/) | `begin-hier/` |
| [`infill/`](./infill/) | `vulling/` |
| [`how-print-clearance-works/`](./how-print-clearance-works/) | `speling/` |
| [`arm-envelope-explained/`](./arm-envelope-explained/) | `arm-werkgebied/` |
| [`how-a-pr-flows/`](./how-a-pr-flows/) | optionele ontwikkelaarsnotitie; voor normaal gebruik `begin-hier/` |

Voeg een nieuwe gids alleen toe als bestaande kennis niet op één huidige plek kan worden
verbeterd. Indexeer hem hier in dezelfde wijziging.
