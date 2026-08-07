# Vulling kiezen met een eerlijke vergelijkingsproef

> Open eerst [`index.html`](./index.html) als je de patronen in doorsnede wilt zien. Gebruik
> deze gids daarna naast Bambu Studio voor de echte vergelijking.

## Welk probleem lost dit op?

Een hoger vullingspercentage kost bijna altijd extra tijd en materiaal, maar levert niet
automatisch de beste mechanische winst. De belasting kan vooral door de wanden, de
printrichting of een lokaal verstevigingsdetail lopen. Deze proef maakt zichtbaar welke
instelling voor één werkelijk onderdeel iets toevoegt.

## Waarom dit voor jouw werkplaats telt

Op de A1 en A1 mini toont Bambu Studio vóór het printen de verwachte tijd en hoeveelheid
filament. Door één waarde tegelijk te veranderen verbind je die slicerdata met een fysieke
test. Het resultaat wordt een ontwerpbeslissing in plaats van een universeel internetgetal.

## Benodigdheden

- Bambu Lab A1 of A1 mini;
- Bambu Studio met het juiste printer-, plaat-, nozzle- en materiaalprofiel;
- één klein proefmodel dat op dezelfde manier wordt belast als het echte onderdeel;
- hetzelfde filament voor alle varianten;
- bij voorkeur een weegschaal en een eenvoudige, herhaalbare belastingstest.

## Begrippen en startpunt

- **Wall loops** maken de buitenhuid dikker.
- **Sparse infill density** bepaalt hoeveel raster binnen de huid komt.
- **Sparse infill pattern** bepaalt hoe dat raster de belasting en bovenlagen ondersteunt.
- **Top/bottom shell layers** sluiten horizontale vlakken.

In Bambu Studio staan deze waarden onder `Strength`. Gebruik bijvoorbeeld 15% vulling,
3 wall loops en 4–5 boven-/onderlagen als **praktisch startpunt**, niet als specificatie.
Vorm, belasting, materiaal en laagoriëntatie kunnen een andere keuze vereisen.

## Stappenplan

1. **Kies een relevant proefstuk.** Gebruik bij voorkeur een verkleinde beugel of rib met
   dezelfde doorsnede en belastingrichting als het uiteindelijke onderdeel. Een kubus zegt
   weinig over een lange hefboom.
2. **Maak variant A.** Slice met 10% vulling en 2 wall loops. Noteer patroon, printtijd en
   filamentmassa uit de slicer.
3. **Maak variant B.** Dupliceer A en verander alleen de vulling naar 30%. Noteer opnieuw
   tijd en massa.
4. **Maak variant C.** Dupliceer A, laat de vulling op 10% en verander alleen wall loops van
   2 naar 3.
5. **Controleer Preview.** Loop laag voor laag langs dunne zones, bovenlagen en de overgang
   tussen vulling en wand. Bevestig dat de bedoelde waarde werkelijk veranderde.
6. **Print alle varianten gelijk.** Gebruik dezelfde printer, oriëntatie, plaat, nozzle,
   materiaalrol en profiel. Label de onderdelen direct na het printen.
7. **Weeg en test.** Belast elk onderdeel op dezelfde plaats en in dezelfde richting.
   Noteer doorbuiging, eerste schade en breukplaats; “voelt steviger” is alleen een eerste
   indruk.
8. **Kies op eis.** Neem de lichtste en snelste variant die de vereiste belasting met een
   passende marge haalt. Bij onzekerheid verbeter je eerst geometrie of printrichting en
   herhaal je de proef.

## Patroon kiezen

| Patroon | Bruikbare eerste toepassing | Wat je nog moet testen |
|---|---|---|
| Grid | snelle algemene vergelijking | kruisingen, geluid en lokale materiaalopbouw |
| Gyroid | belasting uit meerdere richtingen | extra printtijd op jouw model |
| Rectilinear/lijnen | snelle, lichte ondersteuning | richtingafhankelijke stijfheid |
| Concentrisch | flexibele of contourvolgende delen | beweging loodrecht op de contour |

Behandel de tabel als praktijkadvies. Het beste patroon volgt uit de werkelijke belasting en
de Preview, niet uit de naam van het patroon.

## Zo controleer je het resultaat

De proef is geslaagd als je per variant minimaal dit kunt terugvinden:

```text
printer / materiaal / profiel:
oriëntatie:
vulling / patroon / wall loops:
slicertijd / filament:
werkelijk gewicht:
belasting en testopstelling:
doorbuiging / schade / breukplaats:
besluit en reden:
```

Een bruikbaar besluit klinkt bijvoorbeeld als: “Variant C haalde dezelfde belasting als B,
maar gebruikte minder materiaal; voor deze beugel kies ik 3 wanden en 10% vulling.” Dat is
geen regel voor alle toekomstige onderdelen.

## Veelgemaakte fouten

- vulling, patroon, wandtal en oriëntatie tegelijk veranderen;
- verschillende materiaalprofielen vergelijken;
- handkracht als precieze meting presenteren zonder onzekerheid;
- een resultaat van één vorm op elk ontwerp toepassen;
- 100% vulling gebruiken als vervanging voor betere geometrie of printrichting;
- alleen de slicerwaarde noteren en niet het materiaal, profiel en de belasting.

## Wanneer vraag je Claude om hulp?

- *“Vergelijk deze drie Bambu Studio-samenvattingen. Is telkens maar één variabele
  veranderd?”*
- *“Mijn beugel breekt op deze plek en wordt zo belast. Welke geometrische wijziging moet ik
  vóór extra vulling testen, en waarom?”*
- *“Zet mijn meetnotities om in een korte conclusie. Scheid metingen, aannames en advies.”*

## Bronnen en bewijsniveau

- **Praktijkadvies:** de genoemde startwaarden en patroontoepassingen zijn proefkeuzes, geen
  Bambu-specificaties.
- **Onderbouwd:** [Prusa Knowledge Base — Infill](https://help.prusa3d.com/article/infill_42)
  beschrijft functies en afwegingen van vullingspatronen. De bron ondersteunt het concept,
  maar bewijst niet welke variant jouw onderdeel nodig heeft.
- **Experiment:** de slicerschatting plus jouw gelabelde proefstukken bepalen de keuze voor
  één vastgelegde combinatie.

## Animatie openen

Dubbelklik op `guides/vulling/index.html`. Er wordt niets geïnstalleerd. Het oude pad
[`guides/infill/`](../infill/) verwijst naar deze ene actuele Nederlandse bron.
