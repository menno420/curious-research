# Begin hier — laat Claude eerst jouw werkplaats begrijpen

## Welk probleem lost dit op?

Je wilt niet bij iedere vraag opnieuw uitleggen welke printer, slicer, CAD-software en arm je
gebruikt. Deze map geeft Claude die vaste context en bewaart geteste kennis buiten één chat.

Bekijk je liever eerst wat er ligt? Open [`index.html`](./index.html) en druk op **Opnieuw**.

## Waarom dit voor jouw werkplaats telt

De bron van waarheid staat in
[`docs/workshop-profile.md`](../../docs/workshop-profile.md). Daarin staat wat bevestigd is en
wat nog niet bekend is. Daardoor hoort Claude bij een printfout over de A1-serie te praten,
bij een ontwerpvraag Fusion 360 mee te nemen en bij laser- of freesinstellingen eerst naar het
exacte machine- en materiaaltype te vragen.

## Benodigdheden

- de openbare site: <https://menno420.github.io/curious-research/>;
- voor vragen met de hele map als context: je Claude Pro-account en een Windows-pc;
- tien minuten voor de eerste installatie via
  [`docs/claude-usage-guide.md`](../../docs/claude-usage-guide.md).

Een eigen GitHub-account is voor het eerste gebruik niet nodig.

## Stappenplan

### 1. Bekijk één onderwerp dat je nu echt gebruikt

Open <https://menno420.github.io/curious-research/> en kies geen rondleiding maar een echt
werkplaatsprobleem, bijvoorbeeld:

- **Bambu Studio** als een print tegenvalt;
- **Python in Fusion 360** als je herhaalwerk wilt automatiseren;
- **Lasersnijden** of **CNC-frezen** voor de route van ontwerp naar onderdeel;
- een bouwproject als je iets wilt maken.

### 2. Geef Claude Code toegang tot de map

Volg één keer de Windows-stappen in
[`docs/claude-usage-guide.md`](../../docs/claude-usage-guide.md). Start `claude` vanuit de
uitgepakte map `curious-research`, niet vanuit de algemene map Downloads.

### 3. Controleer de context

Plak dit als eerste vraag:

```text
Lees CLAUDE.md en docs/workshop-profile.md. Noem in het Nederlands mijn bevestigde werkplaatscontext en daarna alleen de gegevens die nog ontbreken. Verzin niets.
```

### 4. Stel een echte vraag met een meetbaar doel

Bijvoorbeeld:

```text
Mijn geprinte passing klemt. Help me een korte test maken waarmee ik bepaal of de oorzaak krimp, olifantenvoet of te weinig speling is. Laat me maar één variabele tegelijk veranderen.
```

Of:

```text
Ik wil deze Fusion-schets uit plaat maken. Vergelijk laser en CNC voor dit onderdeel en vertel welke ontbrekende machinegegevens jouw keuze nog kunnen veranderen.
```

### 5. Bewaar alleen wat is getest

Als een oplossing aan de machine werkt, vraag dan:

```text
Dit resultaat is op mijn werkplaats bevestigd. Zet het op de juiste bestaande plek, met datum, omstandigheden, bewijsniveau en wat nog niet bewezen is. Dupliceer geen hardwarefeiten.
```

Een chat wordt niet vanzelf repositorykennis. Controleer altijd welk bestand Claude wil
wijzigen en lees de wijziging na.

## Zo controleer je het resultaat

Je eerste gebruik is geslaagd als Claude:

1. de Bambu Lab A1, A1 mini en AMS Lite kent;
2. Bambu Studio, Fusion 360 Personal Use, Arduino IDE en Windows noemt;
3. de 6-DOF-arm met MG996R-klasse servo's herkent;
4. geen laser-, CNC-, Arduino-board- of materiaalmodel verzint dat nog niet bevestigd is;
5. een antwoord afsluit met een zichtbare of meetbare controle.

## Veelgemaakte fouten

- Een brede vraag stellen zoals *"leg 3D-printen uit"* zonder onderdeel of foutbeeld.
- Claude in een andere map starten en aannemen dat `CLAUDE.md` toch is geladen.
- Een internetwaarde voor kerf, stroom of voeding opslaan alsof hij op de eigen machine is gemeten.
- Een goed chatantwoord niet testen, maar wel meteen als definitief documenteren.
- Denken dat Claude Project-bestanden of een gedownloade ZIP automatisch met GitHub bijwerken.

## Wanneer vraag je Claude om hulp?

- *"Welke drie foto's of metingen geven je het snelst genoeg informatie?"*
- *"Welke aanname in jouw antwoord kan mij materiaal kosten?"*
- *"Maak van dit advies een proef met één veranderde parameter en een succescriterium."*
- *"Zoek eerst in de bestaande gidsen en research voordat je van internet antwoordt."*
- *"Waar hoort dit bevestigde resultaat thuis zonder dezelfde waarheid dubbel op te slaan?"*

## Bronnen en bewijsniveau

- Claude Code-installatie en projectbestanden lezen:
  <https://code.claude.com/docs/en/quickstart> — **Geverifieerd**, gecontroleerd 2026-08-07.
- Werking van `CLAUDE.md` en lokale automatische notities:
  <https://code.claude.com/docs/en/memory> — **Geverifieerd**, gecontroleerd 2026-08-07.
- Claude Projects en geüploade projectkennis:
  <https://support.claude.com/en/articles/9519177-how-can-i-create-and-manage-projects> —
  **Geverifieerd**, gecontroleerd 2026-08-07.
