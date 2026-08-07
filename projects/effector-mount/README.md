# Verwisselbaar gereedschap voor de robotpols

> Begin bij de Nederlandse [projectpagina](../../site/projecten.html#gereedschap) voor het
> doel en de korte bouwroute. Dit bestand beschrijft de bronbestanden en de testvolgorde.

## Wat is dit?

Een parametrische montageplaat die als gedeelde interface dient voor gereedschap aan het
uiteinde van de robotarm. De map bevat twee voorbeelden:

- een passieve houder voor een ronde magneet;
- een experimentele tandheugelgrijper met één extra servo.

De interface is nog niet op de echte pols gemeten of proefgeprint. De meegeleverde maten zijn
placeholders. Een modelbestand zonder bewegingscode zegt bovendien niets over het
startupgedrag van de Arduino-sketch die later de arm bestuurt.

## Waarom bouwen?

Met één gemeten gaten-, centreer- en oriëntatiepatroon hoeft elk nieuw gereedschap niet vanaf
nul aan de pols te worden aangepast. De winst zit in herhaalbaarheid: één interface meten,
een dun teststuk valideren en daarna alleen boven die interface ontwerpen.

## Bestanden

| Bestand | Functie | Status |
|---|---|---|
| [`mount_standard.scad`](mount_standard.scad) | gedeelde plaat en montageparameters | nog meten en renderen |
| [`magnet_tool.scad`](magnet_tool.scad) | passieve magneethouder op de plaat | experiment; pasvorm en houdkracht testen |
| [`gripper.scad`](gripper.scad) | actieve tandheugelgrijper | experiment; geometrie is niet gevalideerd |
| [`gripper_test.ino`](gripper_test.ino) | automatische banktest met één losse servo | beweegt direct na startup; eerst waarden controleren |
| [`index.html`](index.html) | Nederlandse visuele uitleg | lokaal in een browser te openen |

OpenSCAD was tijdens deze repositorybewerking niet beschikbaar. De SCAD-bestanden zijn dus
niet gerenderd, op manifold-geometrie gecontroleerd, gesliced of proefgepast.

## Benodigde onderdelen en gereedschappen

- de werkelijke servohoorn en bevestigingsmiddelen van de pols;
- schuifmaat;
- OpenSCAD, Bambu Studio en A1 of A1 mini;
- voor de passieve tool: een gemeten ronde magneet;
- voor de actieve tool: een **afzonderlijke** servo waarvan maat, spanning en stroomgedrag
  bekend zijn; het bezit daarvan staat niet vast in het werkplaatsprofiel;
- bij powered testen: een externe servovoeding binnen de specificatie van het exacte model,
  gedeelde signaalmassa, passende bedrading/beveiliging en een bereikbare uitschakeling.

## Stappenplan — eerst de interface

1. **Schakel de arm volledig uit.** Verwijder de servohoorn indien dat zonder verlies van de
   referentiestand kan; markeer anders de oriëntatie vóór demontage.
2. **Meet de echte interface.** Noteer hart-op-hartafstand, gatdiameters, naafdiameter en
   -hoogte, beschikbare schroeflengte en vrije ruimte rond de pols.
3. **Vul alleen de plaatparameters in.** Werk in `mount_standard.scad` minimaal
   `horn_span`, `horn_screw_d`, `horn_hub_d`, `horn_hub_th`, `mount_th`, `plate_w`,
   `plate_front` en `plate_back` bij.
4. **Render een kaal teststuk.** Open het bestand, gebruik F5 voor Preview en F6 voor Render,
   exporteer STL en controleer de mesh vóór het slicen.
5. **Print de plaat zonder tool.** Gebruik weinig materiaal; het doel is alleen gaten,
   naaf, oriëntatienok, schroeflengte en botsingsvrije montage controleren.
6. **Monteer met de arm uit.** Schroeven moeten vrij door de plaat gaan en de hoorn grijpen;
   de plaat mag niet op kabels, behuizing of de centrale schroef drukken.
7. **Demonteer en herhaal drie keer.** Controleer of de plaat telkens dezelfde richting en
   positie terugvindt. Pas eerst daarna een toolbestand aan.

## Passieve magneethouder

1. Meet diameter en dikte van de magneet en vul `magnet_d` en `magnet_h` in.
2. `magnet_fit` wordt van de magneetdiameter afgetrokken. Een **grotere positieve** waarde
   maakt de pocket dus kleiner en strakker; een kleinere of negatieve waarde maakt hem
   ruimer. Maak eerst een losse ringcoupon als de passing kritisch is.
3. Render en controleer dat de bevestigingsschroeven bereikbaar blijven.
4. Test perspassing en houdkracht volledig op de werkbank. Houd magneten weg van personen en
   voorwerpen waarvoor de magneetfabrikant een waarschuwing geeft.
5. Til een proefmassa eerst met de hand slechts enkele millimeters boven een zachte opvang.
   Noteer massa, contactvlak en oriëntatie. Een geslaagde banktest is nog geen bewijs voor
   dynamisch gebruik aan de arm.

## Actieve grijper — afzonderlijk experiment

`gripper.scad` bevat twee voorbeeldsets voor servo-afmetingen en eenvoudige, niet-involute
tandvormen. Beide moeten aan het echte onderdeel worden gemeten. Een modelnaam of
“MG996R-klasse” bewijst niet dat behuizing, spline, hoorn of elektrisch gedrag gelijk is.

1. Controleer en wijzig alle servo-, tandwiel-, geleiding- en spelingsparameters.
2. Render de onderdelen en draai tandheugels en pignon met de hand. Geen enkel deel mag
   klemmen of uit de geleiding lopen.
3. Bevestig het pignon mechanisch aan een passende servohoorn; vertrouw niet op een kale
   perspassing op de spline.
4. Test één servo op de werkbank, los van de arm. `gripper_test.ino` schrijft bij startup
   direct een onbevestigde middenpuls en gaat daarna automatisch tussen twee placeholders
   bewegen. Vervang die waarden vóór bekrachtiging en houd de uitschakeling binnen bereik.
5. Beperk de sluitstand zodat de grijper het object raakt zonder langdurig tegen een
   mechanische stop te duwen. Stop bij brommen, opwarming, vastlopen of een voedingsreset.
6. Meet houdkracht en herhaalbaarheid met een zachte opvang. Monteer de grijper pas op de
   arm nadat de banktest reproduceerbaar is én startup en beweging van de arm afzonderlijk
   zijn beoordeeld.

## Zo controleer je succes

De interface is geslaagd wanneer:

- hetzelfde kale teststuk drie keer zonder forceren in dezelfde oriëntatie monteert;
- de schroeven voldoende grijpen zonder bodem te raken;
- de plaat niet zichtbaar kantelt of kabels/huis raakt;
- maatbron, printer, materiaal, profiel en revisie zijn genoteerd;
- een tool na wisselen terugkeert naar dezelfde mechanische referentie binnen de voor het
  project vereiste nauwkeurigheid.

Een tool die iets optilt of klemt krijgt daarnaast een eigen testlog. “Het hield één keer” is
geen belastingsspecificatie.

## Veelgemaakte fouten

- voorbeeldmaten als gemeten maten behandelen;
- tegelijk plaat en tool printen voordat de interface apart past;
- perspassing verkeerd om bijstellen;
- een MG996R-klasse label als garantie voor maat, spanning of stroom gebruiken;
- een actieve grijper direct op de zesassige arm testen;
- aannemen dat softwarebegrenzing een botsingssensor of hardware-interlock is.

## Wanneer vraag je Claude om hulp?

- *“Controleer deze gemeten hoornmaten tegen de parameters in `mount_standard.scad`. Noem
  ontbrekende maten, maar vul niets zelf in.”*
- *“Maak een kleine ringcoupon voor mijn magneet met vijf pocketdiameters rond deze gemeten
  waarde.”*
- *“Review `gripper_test.ino` op beweging bij startup en maak een testplan zonder te beweren
  dat softwarebegrenzing hardwareveiligheid levert.”*

## Veiligheidsstatus

- **Geverifieerd in broncode:** `gripper_test.ino` koppelt de servo aan en schrijft de
  ingestelde middenpuls tijdens `setup()`; daarna volgt automatische beweging.
- **Nog bevestigen:** alle mechanische maten, geschikte servovoeding, houdkracht en
  botsingsvrije armroute.
- **Experiment:** beide toolontwerpen totdat ze zijn gerenderd, proefgeprint en gemeten.

Voor de startupbeperking van de bestaande zesassige penplottersketch, zie
[`projects/arm-pen-plotter/README.md`](../arm-pen-plotter/README.md).
