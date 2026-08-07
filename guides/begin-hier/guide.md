# Begin hier — geef een AI eerst jouw werkplaatscontext

## Welk probleem lost dit op?

Je wilt niet bij iedere vraag opnieuw uitleggen welke printer, slicer, CAD-software en arm je
gebruikt. Deze repository bewaart die vaste context buiten één chat. Via de openbare website kun
je haar nu aan Claude of ChatGPT geven zonder GitHub-account of lokale clone.

Bekijk je liever eerst wat er ligt? Open [`index.html`](./index.html) en druk op **Opnieuw**.

## Waarom dit voor jouw werkplaats telt

De bron van waarheid staat in
[`docs/workshop-profile.md`](../../docs/workshop-profile.md). Daardoor hoort een assistent bij
een printfout over de A1-serie te praten, bij een ontwerpvraag Fusion 360 mee te nemen en bij
laser- of freesinstellingen eerst naar het exacte machine- en materiaaltype te vragen.

GitHub bewaart de ene actuele bron; de website maakt haar leesbaar. Geen van beide geeft een AI
automatisch geheugen: je deelt de link of tekst in het gesprek dat je gebruikt.

## Benodigdheden

- de openbare site: <https://menno420.github.io/curious-research/>;
- een gesprek met Claude of ChatGPT;
- een concreet werkplaatsprobleem, liefst met foto of meting.

Een eigen GitHub-account, clone of Claude Code-installatie is voor het eerste gebruik niet
nodig.

## Hoe heet de kennisbank?

De exacte GitHub-repository is:

**[`menno420/curious-research`](https://github.com/menno420/curious-research)**

Noem die naam in je eerste bericht. Zo weet de assistent welke openbare verzameling je bedoelt:

```text
Gebruik de openbare GitHub-repository menno420/curious-research als kennisbank voor mijn
werkplaats. Lees eerst het werkplaatsprofiel en help me daarna stap voor stap met mijn vraag.
Noem bevestigde feiten en aannames apart. Als je de repository of het profiel niet werkelijk
kunt openen, zeg dat dan meteen.
```

## Stappenplan

### 1. Geef de AI de actuele context

Open:
<https://menno420.github.io/curious-research/github-en-ai.html>

Klik **Kopieer startopdracht** en plak die als eerste bericht. Vraag de assistent daarna te
bevestigen of zij het profiel werkelijk kon openen. Lukt dat niet, klik **Kopieer profieltekst**
en plak de tekst zelf.

### 2. Kies één relevant onderwerp

Ga terug naar <https://menno420.github.io/curious-research/> en open het onderwerp dat je nu
echt gebruikt, bijvoorbeeld:

- **Bambu Studio** als een print tegenvalt;
- **Python in Fusion 360** als je herhaalwerk wilt automatiseren;
- **Lasersnijden** of **CNC-frezen** voor de route van ontwerp naar onderdeel;
- een bouwproject als je iets wilt maken.

Kopieer de URL van die pagina naar hetzelfde gesprek.

### 3. Controleer de context

Plak:

```text
Noem eerst alleen de bevestigde werkplaatscontext die je werkelijk uit het gedeelde profiel
hebt gelezen. Noem daarna apart welke gegevens voor deze vraag nog ontbreken. Verzin niets.
```

### 4. Stel een echte vraag met een meetbaar doel

Bijvoorbeeld:

```text
Mijn geprinte passing klemt. Help me een korte test maken waarmee ik bepaal of de oorzaak krimp,
olifantenvoet of te weinig speling is. Laat me maar één variabele tegelijk veranderen.
```

Of:

```text
Ik wil deze Fusion-schets uit plaat maken. Vergelijk laser en CNC voor dit onderdeel en vertel
welke ontbrekende machinegegevens jouw keuze nog kunnen veranderen.
```

### 5. Bewaar alleen wat is getest

Als een oplossing aan de machine werkt, gebruik:

```text
Dit resultaat is op de echte werkplaats bevestigd. Vat machine, materiaal, instelling, meting,
datum en resterende onzekerheid samen. Stel daarna voor welk bestaand repositorybestand de
beheerder moet bijwerken; dupliceer geen hardwarefeiten.
```

Een chat wordt niet vanzelf repositorykennis. De wijziging hoort via een zichtbare pull request,
controle en merge in de gedeelde bron. De maker hoeft dat nu niet zelf uit te voeren.

## Zo controleer je het resultaat

Je eerste gebruik is geslaagd als Claude of ChatGPT:

1. de Bambu Lab A1, A1 mini en AMS Lite kent;
2. Bambu Studio, Fusion 360 Personal Use, Arduino IDE en Windows noemt;
3. de 6-DOF-arm met MG996R-klasse servo's herkent;
4. weet dat de arm al met een controller is gebruikt, maar geen onbekend controllermodel
   verzint;
5. geen laser-, CNC-, Arduino-board- of materiaalmodel verzint dat nog niet bevestigd is;
6. een antwoord afsluit met een zichtbare of meetbare controle.

## Veelgemaakte fouten

- Een brede vraag stellen zoals *“leg 3D-printen uit”* zonder onderdeel of foutbeeld.
- Aannemen dat een assistent een link heeft gelezen zonder dat te laten bevestigen.
- Alleen een foto sturen zonder overzicht, detail, materiaal en relevante instelling.
- Een internetwaarde voor kerf, stroom of voeding opslaan alsof hij op de eigen machine is
  gemeten.
- Een goed chatantwoord niet testen, maar wel meteen als definitief documenteren.
- Denken dat de website, Claude of ChatGPT de GitHub-repository automatisch bijwerkt.

## Wanneer vraag je Claude of ChatGPT om hulp?

- *“Welke drie foto's of metingen geven je het snelst genoeg informatie?”*
- *“Welke aanname in jouw antwoord kan mij materiaal kosten?”*
- *“Maak van dit advies een proef met één veranderde parameter en een succescriterium.”*
- *“Welke gedeelde bron heb je werkelijk geopend?”*
- *“Waar hoort dit bevestigde resultaat thuis zonder dezelfde waarheid dubbel op te slaan?”*

## Bronnen en bewijsniveau

- GitHub-repository's bewaren bestanden en revisiegeschiedenis:
  <https://docs.github.com/en/repositories/creating-and-managing-repositories/about-repositories>
  — **Geverifieerd**, gecontroleerd 2026-08-07.
- GitHub Pages publiceert de statische website uit repositorybestanden:
  <https://docs.github.com/en/pages/getting-started-with-github-pages/what-is-github-pages>
  — **Geverifieerd**, gecontroleerd 2026-08-07.
- Of een gekozen AI-chat een openbare URL in die sessie kan openen — **Nog bevestigen**; laat de
  assistent dat expliciet bewijzen of plak de tekst.
