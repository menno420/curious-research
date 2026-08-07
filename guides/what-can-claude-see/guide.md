# Een foto of foutmelding aan Claude geven — van beeld naar meetbare test

## Welk probleem lost dit op?

“Mijn print is mislukt” bevat te weinig informatie. Met een overzichtsfoto, detail, relevante
instellingen en een concrete vraag kan Claude hypotheses rangschikken en een kleine proef
voorstellen. Een beeld levert aanwijzingen, geen automatische zekerheid.

Open [`index.html`](./index.html) voor de invoerketen.

## Waarom dit voor jouw werkplaats telt

Claude kent via [`docs/workshop-profile.md`](../../docs/workshop-profile.md) de A1/A1 mini,
Bambu Studio, Fusion 360 en de robotarm. Daardoor hoef je die context niet telkens uit te
schrijven. Het beeld moet nog wel laten zien welk onderdeel, welke plaats en welke afwijking je
bedoelt; materiaal, instellingen en geluid zijn vaak niet zichtbaar.

## Benodigdheden

- Claude met deze repository als context;
- één overzichtsfoto en één scherpe detailfoto;
- bij software: volledige fouttekst als kopieerbare tekst plus een screenshot voor context;
- bij printen: printer, materiaalprofiel, plaat/nozzle en de relevante Bambu Studio-instellingen;
- bij een bewegend systeem: video of opeenvolgende beelden, plus wat je hoorde en wanneer.

## Stappenplan

1. **Maak eerst een overzicht.** Laat onderdeel, oriëntatie en omgeving zien. Gebruik voldoende
   licht en een rustige achtergrond.
2. **Maak daarna één detail.** Zet een liniaal of bekende maat in beeld als schaal nuttig is.
   Markeer de fout desnoods met een eenvoudige cirkel in een kopie van de foto.
3. **Verwijder privé-informatie.** Controleer naam, adreslabel, serienummer, gezichten, schermtabs,
   notificaties en reflecties. Deel geen toegangscodes of sleutels.
4. **Geef niet-zichtbare context.** Noem materiaal, processtap, instelling, voorafgaand gedrag en
   wat al is geprobeerd. Voeg de exacte fouttekst als tekst toe; laat Claude niet OCR raden als
   kopiëren kan.
5. **Vraag om observatie vóór diagnose.** Laat Claude eerst beschrijven wat werkelijk zichtbaar
   is en dat scheiden van aannames.
6. **Laat hypotheses rangschikken.** Vraag maximaal drie oorzaken, met per oorzaak welk detail
   ervoor en ertegen spreekt.
7. **Kies één onderscheidende test.** Een goede volgende stap verandert één variabele of vraagt
   één extra foto/meting die hypotheses uit elkaar trekt.
8. **Bewaar het resultaat pas na uitvoering.** Noteer foto, omstandigheden, wijziging en uitkomst
   op de juiste project- of gidspagina. Een chatdiagnose is nog geen werkplaatsfeit.

## Voorbeeldprompt

```text
Lees eerst docs/workshop-profile.md. Beschrijf alleen wat je op deze twee foto's ziet.
Scheid observaties, aannames en ontbrekende gegevens. Rangschik daarna maximaal drie oorzaken
en geef één kleine test die ze het best uit elkaar trekt. Verander maar één variabele.
```

## Zo controleer je het resultaat

Geslaagd als Claude geen onbekend printer-, materiaal- of machinegegeven verzint, observaties van
aannames scheidt en de voorgestelde proef een zichtbaar succescriterium heeft. Na de test moet je
één hypothese sterker of zwakker kunnen maken.

## Veelgemaakte fouten

- Alleen een extreem close-upbeeld sturen zonder onderdeeloriëntatie.
- Een screenshot sturen terwijl de fouttekst kopieerbaar is.
- Vragen “wat is er mis?” zonder materiaal, processtap of doel.
- Een foto als bewijs van onzichtbare temperatuur, stroom of maat behandelen.
- Meerdere instellingen tegelijk veranderen en daarna de diagnose “bevestigd” noemen.
- Privégegevens in achtergrond, reflectie of venstertitel vergeten.

## Wanneer vraag je Claude?

- *"Welke extra foto geeft de meeste informatiewinst?"*
- *"Welke van jouw beweringen is een observatie en welke is een aanname?"*
- *"Vergelijk dit Bambu Preview-beeld met de foto van het werkelijke defect."*
- *"Zet mijn uitgevoerde test en resultaat op de juiste plek, met bewijsniveau Experiment."*

## Bronnen en bewijsniveau

- De bekende machinecontext komt uit
  [`docs/workshop-profile.md`](../../docs/workshop-profile.md) — **Geverifieerd in repository**.
- Beeldinterpretatie en hypotheserangschikking — **Nog bevestigen** totdat een werkplaatstest de
  oorzaak onderscheidt.
- De uitgevoerde A/B-test — **Experiment**; promoveer alleen met vastgelegde herhaling en bron.
