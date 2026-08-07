# Werkplaatsprofiel — bron van waarheid voor advies

> **Status:** canoniek · **laatst gecontroleerd:** 2026-08-07
>
> Dit bestand beschrijft de werkplaats waarvoor deze repository is gemaakt. Claude en andere
> assistenten lezen dit vóór zij advies geven. Een gids verwijst hiernaar en kopieert deze
> gegevens niet opnieuw. Zo hoeft één verandering maar op één plek te worden bijgewerkt.

## Eigenaar en manier van leren

- **Taal:** Nederlands. Antwoord standaard in helder Nederlands.
- **Niveau:** ervaren hobby-maker; sterk in mechanica, bouwen, bedraden en praktisch testen.
  Hij is geen beginner in 3D-printen, Arduino, Fusion 360 of het maken van onderdelen.
- **Programmeren:** weinig ervaring. Hij kan code plakken, een duidelijk aangegeven getal
  wijzigen en een Arduino-sketch uploaden. Laat hem geen stacktrace ontcijferen.
- **Uitleg:** geef uitvoerbare, genummerde stappen. Noem echte knoppen en menu's. Leg kort uit
  *waarom* een stap nodig is en beschrijf wat hij daarna hoort te zien, meten of horen.
- **Doel:** betere keuzes, betrouwbaardere werkstukken, systematisch storingen vinden en de
  verbinding leggen tussen ontwerp → productie → meten → verbeteren.
- **AI-gebruik:** hij gebruikt Claude voor projecten en krijgt Claude Pro; dezelfde openbare
  context moet ook bruikbaar zijn in ChatGPT of een andere assistent. Een los gesprek is niet
  de bewaarplek voor bevestigde werkplaatskennis.

## Hardware

### 3D-printen

| Apparaat | Bevestigd | Relevante context |
|---|---:|---|
| Bambu Lab A1 | Ja | Gebruikt met AMS Lite. |
| Bambu Lab A1 mini | Ja | Tweede, compactere printer. |
| AMS Lite | Ja | Eén nozzle; kleurwissels veroorzaken spoel-/purge-afval. |

Gebruik voor deze printers geen handleiding die handmatig bednivelleren, een handmatige
Z-offset of LiDAR-metingen veronderstelt. De A1-serie gebruikt automatische kalibratie en
heeft geen LiDAR zoals sommige duurdere Bambu-modellen. De keuzes die wél bij de maker blijven
zijn onder meer materiaalprofiel, oriëntatie, wanden, vulling, support, passing en ontwerp.

### Robotarm

- **Bouw en gebruik:** zelfgebouwde 6-DOF-robotarm. De maker heeft bevestigd dat de arm al met
  een controller is gebruikt (2026-08-07). Exact controllermodel, gebruikte firmware/sketch,
  pinvolgorde en huidig startupgedrag zijn nog niet schriftelijk vastgelegd.
- **Aandrijving:** zes `MG996R`-klasse hobbyservo's. Het precieze fabrikaat en de interne
  elektronica zijn niet bevestigd; klonen onder dezelfde naam kunnen afwijken.
- **Voeding:** type, spanning, stroomcapaciteit, bedrading, verdeelwijze en zekeringwaarden zijn
  nog niet met de maker bevestigd. Adviseer alleen de algemene eis van een aparte, passende
  servovoeding; schrijf niet dat een specifiek voedingssysteem aanwezig is.
- **Bekende beperking:** voor deze arm is geen onafhankelijke positieterugmelding bevestigd.
  Behandel een gevraagde servohoek daarom niet als bewijs dat die hoek mechanisch is bereikt.
- **Kalibratie:** de besturingsworkflow in `projects/arm-pen-plotter/` vereist een gemeten
  `arm/calibration.json` voordat hij gecontroleerde beweging uitvoert. Dat is een eigenschap
  van deze software, niet het bewijs dat de fysieke arm zonder dat bestand niet kan bewegen.
- **Bediening:** test nieuwe bewegingen per gewricht, langzaam en onder direct toezicht. Houd
  de voedingsschakelaar bereikbaar. Softwarelimieten beschermen alleen tegen de situaties die
  in de metingen en code zijn meegenomen; zij bewijzen geen algemene hardwareveiligheid.

Lees vóór armadvies ook [`../arm/README.md`](../arm/README.md).

### Elektronica

- Arduino-projecten, sensoren en hobbyrobotica zijn normaal werk in deze werkplaats.
- De maker kan bedraden, sketches uploaden en parameters aanpassen.
- Exacte Arduino-borden, sensorvoorraad, meetapparatuur en gebruikte voedingsmodules zijn nog
  niet geïnventariseerd. Vraag er alleen naar wanneer de keuze het antwoord verandert.

### Fabricage

- **Lasersnijden:** hij ontwerpt zelf 2D-onderdelen in Fusion 360. Exact lasertype, vermogen,
  besturingssoftware en beschikbare materialen zijn nog niet bevestigd.
- **CNC-frezen/routeren:** hij ontwerpt zelf 2D-onderdelen in Fusion 360. Exacte machine,
  spindel, besturing, opspanning en gereedschapsvoorraad zijn nog niet bevestigd.

Geef zonder die machinegegevens geen schijnpreciese laserinstellingen, voedingen, toerentallen
of snededieptes. Geef een startmethode en laat de maker de machine- of gereedschapstabel invullen.

## Software en omgeving

| Onderdeel | Bevestigd gebruik |
|---|---|
| Besturingssysteem | Windows-pc |
| CAD | Autodesk Fusion 360, Personal Use |
| Slicer | Bambu Studio |
| Microcontrollers | Arduino IDE |
| AI | Claude Pro; daarnaast kan hij andere assistenten gebruiken |

Voor ontwerpen die in Fusion 360 beginnen is het parametrische Fusion-model de hoofdbron: 3D
voor printen en 2D voor laser en CNC. STL, 3MF, DXF en G-code zijn dan afgeleide uitvoer. De
bestaande tekstgebaseerde OpenSCAD-projecten houden hun `.scad`-bestand als eigen master; zet ze
niet stilzwijgend om of kopieer feiten tussen beide ontwerpbronnen.

## Instructies voor Claude, ChatGPT en andere assistenten

1. **Lees eerst dit profiel**, daarna de relevante gids en het bijbehorende dossier onder
   `research/dossiers/`.
2. **Antwoord in het Nederlands**, tenzij de maker uitdrukkelijk een andere taal vraagt.
3. **Sla de beginnersintro over.** Begin bij de beslissing, workflow of fout die nu relevant
   is. Leg nieuwe vaktermen wel één keer in gewone taal uit.
4. **Geef stappen die uitvoerbaar zijn.** Noem menu's, velden, eenheden, te verwachten
   tussenresultaten en een afsluitende controle.
5. **Geef volledige links** naar officiële handleidingen of downloadpagina's wanneer een stap
   buiten deze repository nodig is.
6. **Verzin geen ontbrekende werkplaatsgegevens.** Zet een aanname zichtbaar boven het advies,
   of vraag één gerichte vraag wanneer een verkeerde aanname materiaal, gereedschap of tijd kan
   kosten.
7. **Scheid bewijs van advies.** Gebruik het bewijsniveau uit
   [`knowledge-policy.md`](knowledge-policy.md). Een bruikbare vuistregel is geen
   fabrikantenspecificatie.
8. **Leg uit waarom het ertoe doet.** Verbind een instelling met het zichtbare of meetbare
   gevolg aan de machine.
9. **Sluit de lus.** Eindig met: wat meten of bekijken, wanneer het geslaagd is en welke ene
   parameter daarna eventueel verandert.
10. **Bewaar waardevolle ontdekkingen duurzaam.** Stel voor het profiel, een projectlog of een
    gids bij te werken. Zeg nooit dat een gewone chat automatisch de repository bijwerkt.

## Nog te bevestigen

Deze lege plekken zijn bewust zichtbaar. Zij mogen niet stilzwijgend worden ingevuld:

- normale filamentsoorten, merken en nozzle-diameters;
- exact model, vermogen en software van de lasersnijder;
- exact model, spindelbereik, controller en werkbereik van de CNC-machine;
- beschikbare frezen en gebruikelijke plaatmaterialen;
- precieze Arduino-borden en sensoren op voorraad;
- fabrikant/variant van de zes servo's en gemeten voeding- en stroomwaarden;
- exact controllermodel, werkende firmware/sketch, pinvolgorde, startupgedrag en aanwezige
  voedingsopbouw van de arm;
- werkelijk gemeten min/midden/max per armgewricht.

Wanneer de maker een van deze feiten bevestigt, werk dan **dit bestand** bij met datum en bron.
Verwijder de betreffende regel uit deze lijst; kopieer de waarde niet naar meerdere gidsen.
