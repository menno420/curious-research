# Spelingmunt — gemeten passing voor eigen prints

> Meet per printer, materiaal en profiel welke radiale speling een klem-, schuif- of losse
> passing geeft. Gebruik die meting daarna als ontwerpwaarde in plaats van een algemene vuistregel.

Begin voor een korte projectintroductie bij de Nederlandse
[projectpagina](../../site/projecten.html#spelingmunt). Dit bestand beschrijft de bronbestanden en
de actuele validatiestatus.

## Welk probleem lost dit op?

De maat in een CAD-model is niet automatisch de maat van een geprint gat of pennetje. Eerste-laag-
verbreding, materiaal, temperatuur, oriëntatie en het gekozen profiel beïnvloeden de passing. Deze
munt houdt de penmaat gelijk en varieert alleen de **radiale speling per zijde**.

Een opschrift van `0.20` betekent daarom:

- 0,20 mm extra ruimte aan iedere zijde;
- 0,40 mm verschil over de volledige diameter.

## Bestanden

| Bestand | Functie |
|---|---|
| [`tolerance-test-coin.scad`](./tolerance-test-coin.scad) | Parametrische OpenSCAD-bron voor munt en losse testpennen. |
| [`print-and-test-guide.md`](./print-and-test-guide.md) | Nederlandse werkroute van gecontroleerde export tot herbruikbare ontwerpwaarde. |
| [`clearance-results.md`](./clearance-results.md) | Enige resultatenlog voor gemeten printer-, materiaal- en profielcombinaties. |

## Validatiestatus

- **Geverifieerd op 2026-08-07:** OpenSCAD 2021.01 rendert de standaardreeks en een afwijkende
  korte parameterreeks zonder waarschuwingen naar eenvoudige manifold STL-meshes.
- **Nog bevestigen:** de maatnauwkeurigheid, leesbaarheid, passing en gekozen
  olifantsvoetcompensatie op de fysieke printer.
- **Niet opgeslagen als vaste STL:** het `.scad`-bestand blijft de master. Een STL is afgeleide
  uitvoer van de op dat moment gekozen meetreeks en wordt opnieuw gegenereerd na een wijziging.

De repositorycontrole voert dezelfde renderproeven opnieuw uit met
`.github/scripts/check_openscad.sh` wanneer OpenSCAD beschikbaar is. Dat bewijst geldige geometrie,
niet dat de fysieke passing klopt.

## Korte werkroute

1. Kies precies één printer, nozzle, materiaal en Bambu Studio-profiel.
2. Render de gewenste reeks vanuit `tolerance-test-coin.scad` en exporteer STL.
3. Controleer profiel, eerste-laagcompensatie en geometrie in Bambu Studio Preview.
4. Print munt en pennen samen en laat ze volledig afkoelen.
5. Classificeer iedere passing zonder forceren.
6. Schrijf de omstandigheden en waarden in `clearance-results.md`.
7. Laat Claude bij een volgend ontwerp de juiste **gemeten rij** gebruiken en de gekozen passing
   expliciet noemen.

## Eerlijke grens

Een meting is een sterke startwaarde voor de vastgelegde combinatie, geen universele
printerspecificatie. Herhaal de proef na een relevante wijziging in printer, nozzle, materiaal,
profiel, temperatuur, oriëntatie of eerste-laaginstelling.
