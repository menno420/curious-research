# Temperatuurreeks in Bambu Studio — bewijs eerst dat de temperatuur echt wijzigt

## Welk probleem lost dit op?

Je wilt voor één filamentvariant een nozzletemperatuur kiezen op basis van stringing,
brugkwaliteit, oppervlak en laaghechting. Een “temperatuurtoren” is alleen een geldige proef als
de geslicede uitvoer werkelijk per band van temperatuur verandert.

Open [`index.html`](./index.html) voor de meetroute.

## Waarom dit voor jouw werkplaats telt

De A1-serie kan snel printen, waardoor temperatuur, volumestroom en koeling samen het resultaat
bepalen. Een mooi gelabelde STL verandert zelf geen temperatuur. Deze gids kiest daarom de
controleerbare route: meerdere identieke korte prints, of een toren waarvan je de
temperatuurwissels in Preview/G-code aantoonbaar controleert.

## Benodigdheden

- Bambu Studio met het juiste printer-, nozzle- en plaatprofiel;
- één filamentvariant met fabrikanttemperatuurbereik;
- een compact testmodel met korte brug, overhang en twee losse pennen;
- schuifmaat en eenvoudige breek-/buigvergelijking;
- log met gekozen temperaturen en resultaten.

## Stappenplan

1. **Noteer de grenzen.** Neem de fabrikantband en de maximale waarden van nozzle/hotend als
   harde rand. Gebruik geen getallen uit deze gids als instelling.
2. **Kies drie tot vijf waarden.** Verdeel ze binnen de fabrikantband. Begin bij het bestaande
   Bambu-filamentprofiel en neem kleine gelijke stappen.
3. **Maak de controleerbare proef.** Dupliceer hetzelfde model naar afzonderlijke platen en geef
   iedere plaat een kopie van het filamentprofiel met precies één andere nozzletemperatuur.
   Dat kost iets meer tijd maar voorkomt onzichtbare hoogte-G-codefouten.
4. **Wil je toch één toren gebruiken?** Stel de temperatuurwissel per hoogte in met een functie
   die jouw Bambu Studio-versie werkelijk ondersteunt. Controleer daarna in de geslicede uitvoer
   of op iedere bedoelde hoogte een temperatuurcommando staat. Geen bewijs = geen geldige toren.
5. **Houd de rest gelijk.** Zelfde printer, nozzle, plaat, laaghoogte, snelheid, flow,
   ventilator, modeloriëntatie en droogstatus.
6. **Print onder toezicht.** Een deel van de reeks is bewust suboptimaal. Stop bij slechte
   hechting, verstopping of loskomend materiaal.
7. **Beoordeel blind als het kan.** Vergelijk stringing, brugonderzijde, glans, detail en
   laaghechting zonder eerst naar het temperatuurlabel te kijken.
8. **Kies op functie.** Een sierdeel kan oppervlakte prioriteren; een belast deel vraagt ook
   een reproduceerbare hechtingstest. Bewaar het resultaat per filamentvariant.

## Zo controleer je het resultaat

Geslaagd als iedere proef aantoonbaar op zijn bedoelde temperatuur draaide, alle andere
variabelen gelijk waren en één temperatuurbereik aantoonbaar de beste combinatie voor het
beoogde onderdeel geeft. Herhaal de winnende waarde eenmaal.

## Veelgemaakte fouten

- Alleen een gelabelde toren slicen zonder temperatuurwissels te controleren.
- Waarden buiten fabrikant- of hotendlimiet kiezen.
- Een betere brug meteen gelijkstellen aan betere laagsterkte.
- Een andere temperatuur combineren met andere fan of snelheid.
- Eén temperatuur als universeel voor alle kleuren en merken opslaan.

## Wanneer vraag je Claude?

- *"Maak een temperatuurmatrix binnen deze fabrikantband, met gelijke stappen."*
- *"Controleer op deze Preview/G-code of de temperatuur echt per band verandert."*
- *"Maak een scoringsblad voor brug, stringing, oppervlak en laaghechting."*
- *"Welke volumestroom- of koelingsaanname kan deze temperatuurproef vertekenen?"*

## Bronnen en bewijsniveau

- Fabrikantband van het eigen filament en Bambu-profiel — **Nog bevestigen** totdat merk/type is
  vastgelegd.
- Meerdere identieke prints met één gewijzigde temperatuur — **Experiment**.
- Controle van gegenereerde temperatuurcommando's — **Geverifieerd in eigen bestand** zodra
  vastgelegd; niet automatisch een bewijs van materiaalkwaliteit.
