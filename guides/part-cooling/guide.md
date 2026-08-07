# Onderdeelkoeling op A1/A1 mini — overhang verbeteren zonder sterkte blind in te leveren

## Welk probleem lost dit op?

Overhangen zakken, bruggen hangen door of kleine punten blijven zacht. Meer ventilator kan vorm
verbeteren, maar verandert ook laaghechting en krimp. Deze workflow meet het effect met hetzelfde
testdeel en één gewijzigde koelinstelling per print.

Open [`index.html`](./index.html) voor de vergelijking.

## Waarom dit voor jouw werkplaats telt

Bambu Studio-profielen regelen onderdeelkoeling, laagduur en vertragen samen. Alleen “fan 100%”
opschrijven vertelt dus niet wat de slicer tijdens ieder deel van de print werkelijk doet. Werk
vanuit het juiste filamentprofiel en gebruik Preview om de geslicede snelheid en laagduur mee te
beoordelen.

## Benodigdheden

- A1 of A1 mini en Bambu Studio;
- het werkelijke filamentprofiel en een droog, geïdentificeerd filament;
- klein testmodel met overhang, brug en smalle toren;
- drie kopieën van hetzelfde filament-/procesprofiel;
- vergrootglas of vaste foto-opstelling; voor belast werk ook een eenvoudige breektest.

## Stappenplan

1. **Leg de nulmeting vast.** Print het testmodel met het bestaande Bambu-profiel. Noteer
   printer, nozzle, materiaal, temperatuur, faninstellingen en laaghoogte.
2. **Bekijk Preview.** Controleer laagduur en snelheid bij de brug, overhang en kleine top. Een
   fanwijziging is geen zuivere proef als de slicer tegelijk anders vertraagt.
3. **Maak twee profielkopieën.** Verander in de Cooling-instellingen slechts één gekozen
   fanparameter onder en boven de huidige waarde. Gebruik kleine stappen binnen het advies van
   de filamentfabrikant; exacte veldnamen verschillen per Bambu Studio-versie.
4. **Houd de eerste laag gelijk.** Neem de bestaande eerste-laagkoeling over; diagnoseer
   hechting apart en voeg niet tegelijk brim of andere bedtemperatuur toe.
5. **Slice en controleer opnieuw.** Vergelijk Preview en noteer de werkelijk verwachte fan,
   laagduur en snelheid. Als meerdere variabelen veranderen, label dat als beperking.
6. **Print de varianten onder dezelfde omstandigheden.** Zelfde plaatpositie indien mogelijk,
   dezelfde oriëntatie en dezelfde filamentbatch.
7. **Vergelijk vorm én hechting.** Fotografeer brugonderzijde, overhang en top. Buig of breek
   een identiek dun testlipje als laagsterkte belangrijk is.
8. **Kies de laagste koeling die het functiecriterium haalt.** Bewaar het resultaat alleen voor
   deze materiaal-/profielcombinatie.

## Zo controleer je het resultaat

Geslaagd als één variant aantoonbaar betere brug/overhang geeft zonder ongewenste scheiding,
warping of slechtere laaghechting. Herhaal de winnaar en controleer in een echt onderdeel.

## Veelgemaakte fouten

- PLA-, PETG- en ABS-percentages als universele waarheid behandelen.
- Max fan wijzigen terwijl laagduur en snelheid ongemerkt ook veranderen.
- Een fraaie onderzijde kiezen zonder laagsterkte te testen.
- Bedhechting en onderdeelkoeling in dezelfde proef oplossen.
- Resultaten van A1 en A1 mini zonder herhaaltest samenvoegen.

## Wanneer vraag je Claude?

- *"Wijs op deze Bambu Studio-screenshots aan welke fan- en laagduurvelden samen werken."*
- *"Maak drie koelvarianten rond mijn huidige profiel; verander verder niets."*
- *"Vergelijk deze foto's op brug, overhang en laaghechting met een vast scoreblad."*
- *"Welke Preview-weergave kan aantonen dat snelheid de uitkomst vertekent?"*

## Bronnen en bewijsniveau

- Het eigen Bambu-filamentprofiel en fabrikantadvies — **Nog bevestigen** totdat filament is
  vastgelegd.
- Eén-variabele koelvergelijking — **Experiment**.
- Keuze van laagste fan die vorm en functie haalt — **Praktijkadvies**, opnieuw testen bij
  andere printer, nozzle, materiaal of geometrie.
