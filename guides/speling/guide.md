# Speling tussen geprinte onderdelen meten en hergebruiken

> Open [`index.html`](./index.html) voor de korte animatie. De animatie legt het principe
> uit; de coupon en je meetlog leveren de ontwerpwaarde.

## Welk probleem lost dit op?

Een pen en gat die in CAD exact dezelfde nominale maat hebben, klemmen na FDM-printen vaak
of hechten lokaal aan elkaar. Lijnbreedte, materiaalstroom, krimp, laagoriëntatie en de
eerste laag veranderen de werkelijke geometrie. Deze workflow bepaalt doelbewust de speling
voor een gewenste pers-, schuif- of losse passing.

## Waarom dit voor jouw werkplaats telt

Dezelfde Fusion-parameter kan op de A1 en A1 mini een andere passing geven, zeker na een
wisseling van materiaal, nozzle, oriëntatie of profiel. Een kleine coupon maakt van een gok
een herbruikbare ontwerpwaarde en verbindt CAD rechtstreeks met fabricage en test.

## Benodigdheden

- Bambu Lab A1 of A1 mini en Bambu Studio met het juiste profiel;
- het [pasmuntproject](../../projects/tolerance-test-coin/) of een eigen parametrische
  coupon;
- hetzelfde materiaal en dezelfde oriëntatie als het uiteindelijke onderdeel;
- schuifmaat en een meetlog.

## Belangrijk onderscheid: per kant of over de diameter

Bij een ronde pen-gatcombinatie is de diametrale speling tweemaal de radiale speling:

```text
0,20 mm vrije ruimte per kant
× 2 kanten
= 0,40 mm verschil tussen gatdiameter en pendiameter
```

Leg in Fusion vast welke grootheid je parameter bedoelt. Een parameter `speling_per_kant`
voorkomt dat 0,40 mm per ongeluk nogmaals aan beide kanten wordt toegevoegd.

## Stappenplan

1. **Kies de functie van de passing.** Noteer of het onderdeel geperst, met handdruk
   gemonteerd, vrij geschoven of bewust los moet worden.
2. **Leg de productiecombinatie vast.** Noteer printer, nozzle, materiaal, plaat, profiel,
   oriëntatie en relevante slicercorrecties.
3. **Maak een reeks.** Kies meerdere oplopende spelingen per kant rond een redelijke
   startwaarde. `0,20 mm per kant` is hier slechts een **experimenteel middenpunt**, geen
   printerspecificatie.
4. **Controleer het model.** Meet in CAD zowel pen- als gatmaat en controleer dat labels na
   het slicen leesbaar blijven.
5. **Controleer Preview.** Kijk vooral naar de eerste lagen, dunne wanden en de werkelijk
   gegenereerde opening.
6. **Print de coupon.** Blijf bij de eerste laag en laat de coupon afkoelen voordat je de
   passing beoordeelt.
7. **Test zonder forceren.** Plaats elke pen meerdere keren. Classificeer de passing en
   noteer eventuele richtingafhankelijkheid.
8. **Meet boven en onder.** Als alleen de onderzijde te krap is, onderzoek je de eerste laag
   afzonderlijk voordat je de hele CAD-speling vergroot.
9. **Bewaar het resultaat.** Noteer de gekozen waarde met alle omstandigheden. Herhaal de
   coupon bij een relevante wijziging; combineer de printers niet tot één ongedocumenteerd
   getal.

## Olifantsvoet afzonderlijk testen

Een sterk aangedrukte eerste laag kan buitencontouren verbreden en gaten onderaan vernauwen.
Controleer eerst of de afwijking werkelijk tot de eerste lagen beperkt blijft. Test daarna
olifantsvoetcompensatie in kleine stappen, bijvoorbeeld 0,10 en 0,20 mm, terwijl alle andere
waarden gelijk blijven. Kies de kleinste correctie die het ondervlak herstelt zonder de
buitenmaat onnodig te verkleinen.

De exacte instelling en standaardwaarde kunnen per Bambu Studio-versie of profiel wijzigen.
Zoek op `elephant` in de instellingen in plaats van een oud menupad te vertrouwen.

## Zo controleer je het resultaat

De proef is geslaagd als de gekozen pen meerdere keren met de gewenste kracht kan worden
geplaatst en verwijderd, zonder vijlen of forceren, en deze velden zijn ingevuld:

```text
printer / nozzle / materiaal:
profiel / oriëntatie:
speling per kant:
olifantsvoetcompensatie:
passing bij boven- en onderzijde:
datum / besluit:
```

## Veelgemaakte fouten

- diametrale speling verwarren met speling per kant;
- een PLA-resultaat zonder proef voor PETG of een andere oriëntatie gebruiken;
- een gat op slechts één hoogte meten;
- slicercorrectie en CAD-speling tegelijk veranderen;
- een perspassing beoordelen door met gereedschap te forceren;
- één waarde voor beide printers opschrijven zonder vergelijkingsproef.

## Wanneer vraag je Claude om hulp?

- *“Maak een parametrische Fusion-coupon met deze vijf spelingen per kant en reliëflabels.”*
- *“Hier zijn mijn A1- en A1-mini-resultaten. Welke waarden kan ik hergebruiken en welke
  moet ik apart bewaren?”*
- *“Mijn maat klopt bovenaan maar niet in de eerste twee lagen. Geef één test voor
  olifantsvoetcompensatie en leg uit wat ik moet meten.”*

## Bronnen en bewijsniveau

- **Praktijkadvies:** 0,20 mm per kant en de genoemde compensatiestappen zijn startwaarden,
  geen garanties.
- **Experiment:** het [pasmuntproject](../../projects/tolerance-test-coin/) en jouw meetlog
  bepalen de waarde voor één vastgelegde combinatie.
- **Nog bevestigen:** de exacte locatie en standaardwaarde van de Bambu Studio-instelling
  moeten in de gebruikte softwareversie worden gecontroleerd.

## Animatie openen

Dubbelklik op `guides/speling/index.html`. Er wordt niets geïnstalleerd. Het oude pad
[`guides/how-print-clearance-works/`](../how-print-clearance-works/) verwijst naar deze ene
actuele Nederlandse bron.
