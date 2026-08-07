# Camera rond een print — geparkeerd idee

**Status:** parkeren. Een statieve camera levert de gewenste timelapse met veel minder
complexiteit. De armvariant wordt pas relevant als een werkelijk voordeel en de ontbrekende
randvoorwaarden zijn aangetoond.

## Idee

Een lichte camera maakt losse opnamen vanuit meerdere hoeken. Dat is een ander doel dan een
gewone laag-voor-laagtimelapse: voor zo’n timelapse hoeft de camera niet door de robotarm te
worden gedragen.

## Waarom niet nu?

- massa van camera, houder en kabel is niet gemeten tegen de draagkracht van de echte arm;
- temperatuur en drift tijdens langdurig vasthouden zijn niet gemeten;
- het is onbekend of de huidige printerworkflow een bruikbaar laag-event beschikbaar stelt;
- de werkzone naast bed, hotend en bewegende assen is niet gemeten;
- de bestaande robotbesturing heeft een apart te beoordelen startupbeweging.

Daarom staan hier geen universele payload-, stroom- of temperatuurlimieten. Een modelnaam of
secundaire datasheet is onvoldoende om deze opstelling veilig te dimensioneren.

## Wat kan het idee heropenen?

1. maak eerst één timelapse met een vaste camera;
2. definieer welk zichtbaar resultaat alleen een bewegende camera kan leveren;
3. weeg een concrete lichte camera met houder en kabel;
4. meet herhaalbaarheid en drift van een korte, begeleide route zonder draaiende printer;
5. ontwerp pas daarna een botsingsvrije proef, met bereikbare uitschakeling en zachte opvang.

Tot die tijd is dit een onderzoeksvraag, geen bouwinstructie.
