# Lithofaanpaneel — van foto naar getest lichtbeeld

## Welk probleem lost dit op?

Een foto moet worden omgezet in plaatselijke dikte: dun laat meer licht door, dik minder. Deze
workflow controleert uitsnede, generator, slicer, proefpaneel en backlight vóór je een volledige
lampbehuizing ontwerpt.

Open [`index.html`](./index.html) voor de keten in beeld.

## Waarom dit voor jouw werkplaats telt

Je gebruikt A1/A1 mini, Bambu Studio en Fusion 360. Daarmee kun je het beeldpaneel genereren en
printen, daarna pas een parametrisch frame rond de gemeten print ontwerpen. De AMS Lite is alleen
nodig voor een meerkleurige variant; een monochroom paneel werkt met één geschikt licht filament.

## Benodigdheden

- eigen foto waarvan je het gebruiksrecht hebt;
- [MakerWorld MakerLab — Make My Lithophane](https://makerworld.com/en/makerlab/makeMyLithophane?from=makerlab)
  of een andere generator waarvan je de afmetingen controleert;
- Bambu Studio, A1 of A1 mini en geïdentificeerd filament;
- schuifmaat;
- gelijkmatige, geschikte laagspannings-LED-backlight of een kant-en-klare lichtmodule;
- Fusion 360 voor het frame, pas nadat het paneel is getest.

## Stappenplan

1. **Kies een leesbare foto.** Gebruik een scherp onderwerp met duidelijk contrast. Snijd grote,
   lege achtergronden weg. Bewaar het origineel en een aparte werkversie.
2. **Bescherm privégegevens.** Een gezicht, adres, nummerbord of interieur kan in de foto en in
   de openbare repository terechtkomen. Upload en commit alleen wat bewust gedeeld mag worden.
3. **Genereer één eenvoudig paneel.** Begin monochroom en zonder ingewikkelde lijst. Noteer de
   ingestelde breedte, hoogte, minimum- en maximumdikte; behandel generatorstandaarden als
   uitgangspunt, niet als werkplaatsmeting.
4. **Importeer in Bambu Studio.** Kies de echte printer, nozzle, plaat en filament. Controleer de
   uiteindelijke X/Y/Z-maat na import; schaal niet opnieuw zonder dat te loggen.
5. **Volg de generator-/Bambu-oriëntatie.** Controleer ondersteuning, brim en laagopbouw in
   Preview. Dunne beelddetails die na slicen verdwijnen moeten in bron of generator worden
   aangepast, niet pas na een mislukte volledige print.
6. **Print een representatieve uitsnede.** Gebruik een strook met lichte, middentoon- en donkere
   delen. Zo test je contrast, banding en maat met weinig materiaal.
7. **Beoordeel met de echte backlight.** Houd afstand, diffuser en helderheid gelijk. Een mooi
   paneel bij daglicht kan met de bedoelde lamp toch uitgebeten of te donker zijn.
8. **Print het volledige paneel.** Blijf bij de start, controleer hechting en stop bij warping of
   instabiliteit van een hoge, smalle print.
9. **Meet pas daarna het frame.** Gebruik de echte paneelmaat en een kleine pasproef in Fusion.
   Voorzie ruimte voor montage, kabel, warmteafvoer en onderhoud. Pas geen netspanningselektronica
   toe zonder een daarvoor geschikte kant-en-klare module en bijbehorende handleiding.

## Zo controleer je het resultaat

Geslaagd als lichte en donkere zones bij de bedoelde backlight herkenbaar blijven, er geen
storende ontbrekende banen zijn en de echte paneelmaat in het Fusion-frame past zonder buigen of
forceren. Beoordeel ook na minstens tien minuten brandtijd of de gekozen module ongewenste warmte
opbouwt volgens zijn specificatie.

## Veelgemaakte fouten

- Meteen een volledig paneel printen zonder uitsnede.
- Fotoformaat en uiteindelijke paneelverhouding door elkaar halen.
- Alleen het onverlichte oppervlak beoordelen.
- Generatorwaarden als universele ideale dikte behandelen.
- Een frame tekenen op nominale STL-maat in plaats van de gemeten print.
- Privéfoto of persoonsinformatie onbedoeld committen.
- Losse netspanningsbedrading in een geprinte behuizing improviseren.

## Wanneer vraag je Claude?

- *"Welke uitsnede van deze foto bevat licht, middentoon en donker voor een kleine proef?"*
- *"Controleer deze Bambu Preview op verdwenen dunne banen en instabiele oriëntatie."*
- *"Maak een parametrische Fusion-frameroute op basis van mijn gemeten paneelmaat."*
- *"Vergelijk deze twee backlightfoto's met vaste criteria, niet alleen op smaak."*

## Bronnen en bewijsniveau

- MakerWorld MakerLab, **Make My Lithophane**:
  <https://makerworld.com/en/makerlab/makeMyLithophane?from=makerlab> — **Geverifieerd** als
  beschikbare officiële generator, gecontroleerd 2026-08-07.
- Bambu Lab, CMYK-lithofaanworkflow:
  <https://wiki.bambulab.com/en/knowledge-sharing/cmyk-color-lithophane-printing-instructions> —
  **Onderbouwd**, officiële productbron; instellingen gelden niet automatisch voor monochroom.
- Beeld-, dikte- en framekeuze — **Experiment** op eigen foto, filament, printer en backlight.
