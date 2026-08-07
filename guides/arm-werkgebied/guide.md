# Het gemeten werkbereik van de arm — en wat een begrenzer echt doet

## Welk probleem lost dit op?

Deze pagina geeft een praktische manier om per servo een bruikbaar hoekbereik te meten en dat
aan de besturingssoftware te geven. De software kan daarna een **hoekgetal** terugsnoeien tot
dat bereik. Zij kan niet zien of een nieuw gereedschap, draad, last of obstakel toch in de baan
staat.

Geen wiskunde, geen theorie — gewoon rustig meten, één gewricht tegelijk.

> **Bekijk eerst de animatie.** Dubbelklik op `guides/arm-werkgebied/index.html` en druk op
> **Opnieuw**: je ziet de arm eerst ergens tegenaan lopen en daarna opgevangen worden door de
> begrenzer. Daarna leest de rest van deze pagina een stuk makkelijker.

## Waarom dit voor jouw werkplaats telt

De bevestigde armcontext staat in
[`docs/workshop-profile.md`](../../docs/workshop-profile.md). De arm beweegt al; dit is dus geen
eerste-startgids. Het doel is herhaalbare, gecontroleerde bediening met getallen die op deze arm
zijn gemeten, in plaats van limieten van een verkoper of andere kit.

## Benodigdheden

- de bestaande arm en controller;
- vóór iedere powered test: een servovoeding binnen de specificatie van de exacte servo's,
  gedeelde massa, passende bedrading en zekering, plus een bereikbare uitschakeling;
- Windows Verkenner en een teksteditor;
- `arm/calibration.example.json`;
- een manier om één gewricht langzaam te bedienen;
- papier of een tijdelijk meetlog voor ruwe grenzen.

**Eerst bevestigen:** pinvolgorde, draairichting en mechanische naam van ieder gewricht. De
voorbeeldvolgorde in de code is geen bewijs dat de eigen bedrading dezelfde volgorde gebruikt.

---

## De woorden die we gebruiken

- **Servo** — een motortje dat je een exacte hoek geeft. Je zegt niet "draai", je zegt "ga naar
  90°", en daar gaat hij heen en daar blíjft hij. Jouw arm heeft er zes.
- **Gemeten werkbereik** — de min- en maxhoek die voor één bekende montage, kabelroute, last en
  testconditie bruikbaar bleken. Het is geen universele veiligheidsverklaring.
- **Begrenzer** — een klein stukje software dat elk commando terugsnoeit tot binnen dat gemeten
  bereik, vóórdat het bij de motor aankomt. Vraag je 170° op een gewricht dat op 120° ophoudt,
  dan geeft de begrenzer de servo 120°. Dat beschermt alleen tegen het verkeerde **getal**;
  120° kan door een nieuwe last of kabelroute alsnog ongeschikt zijn.
- **Kalibratie** — die bruikbare hoeken rustig opmeten en opschrijven, zodat de software
  met échte getallen werkt in plaats van met aannames.

---

## Voordat je iets aanraakt — de veiligheidsregels

Deze zijn niet onderhandelbaar.

- **De servo's krijgen hun stroom uit een aparte voeding**, binnen de spanningsspecificatie van
  de exacte servovariant, met gedeelde massa met de Arduino, geschikte bedrading, zekering en
  bereikbare uitschakeling. **Nooit uit de 5V-pin van de Arduino.** Voedingsspanning,
  stroomcapaciteit en zekering zijn voor deze arm nog niet geverifieerd; stel model en belasting
  vast en meet voordat je een waarde kiest.

- **Houd je hand bij de schakelaar tijdens elke beweging onder stroom.** Ziet, klinkt of ruikt
  iets vreemd: eerst de stroom eraf, dan pas nadenken.
- **Er kijkt altijd iemand mee.** De arm beweegt nooit onbeheerd — niet één keer, ook niet "even
  om te testen".
- **Doe de eerste inspectie met alle servovoeding geïsoleerd.** Beweeg alleen met de hand als de
  constructie aantoonbaar kan worden teruggedreven; forceer geen tandwielkast. Anders maak je de
  verbinding mechanisch los of gebruik je later een gecontroleerde één-gewrichtstest.

---

## Stappenplan: meet per servo de bruikbare min, max en midden

Je doet dit voor alle zes de actuatoren. Nummer ze eerst fysiek van 1 tot 6 en leg per nummer
vast welke pin en bewegingsas erbij horen. De bestaande software gebruikt de labels **base**,
**shoulder**, **elbow**, **wrist_tilt**, **wrist_rotate** en **gripper**, maar die indeling is
nog niet tegen de echte 6-DOF-opbouw bevestigd. Sluit labels dus niet op goed geluk aan. Doe
**één actuator tegelijk**, helemaal af, voordat je aan de volgende begint.

1. **Servovoeding geïsoleerd.** Inspecteer gewricht 1, mechanische aanslagen, kabelroute en
   omliggende delen. Beweeg het alleen voorzichtig als terugdrijven voor deze constructie is
   bevestigd; forceer nooit een servo. Noteer ruwe grenzen als **Experiment**.

2. **Ga van elke ruwe grens een paar graden terug.** Die kleine marge is je werkelijke **min** en
   **max**. Schrijf ze op.

3. **Zoek het midden** — ongeveer halverwege min en max, de neutrale ruststand waar de arm in
   staat als hij niets doet. Schrijf hem op.

4. **Los eerst startup op.** Gebruik geen arm-sketch die bij `attach()` of reset naar een
   onbevestigde 90°-stand springt. Maak een gecontroleerde één-gewrichtstest die start vanuit een
   bekende werkelijke houding en de eerste opdracht onder toezicht in kleine stappen uitvoert.

   > Een brommende of persende servo vecht tegen een mechanische aanslag — hij duwt tegen iets
   > wat niet meegeeft. Draai het getal terug tot de beweging schoon is.

5. **Valideer daarna onder toezicht**, met uitschakeling bereikbaar, eerst ruim binnen de ruwe
   grenzen. Benader iedere kant in kleine stappen. Stop bij brommen, persen, kabelspanning,
   onverwachte richting of reset en verklein het bereik.

6. **Noteer min / max / midden voor dat gewricht** in je kalibratiebestand (hieronder). Daarna
   alle stappen opnieuw voor de andere vijf servo's — telkens één tegelijk.

Zo ziet één afgeronde meting eruit, zodat je weet welke vorm je zoekt:

```
schouder:  min 25°   max 120°   midden 75°
```

---

## Schrijf het op: je kalibratiebestand op Windows

1. Open de map `arm` in Windows Verkenner.
2. Selecteer `calibration.example.json` en druk **Ctrl+C**, daarna **Ctrl+V**.
3. Hernoem de kopie naar `calibration.json`.
4. Open het bestand in Kladblok of Notepad++.
5. Vul per gewricht de gemeten **min**, **max** en **midden** in.
6. Vul `measured_on` in met de datum. Gebruik bij `measured_by` hoogstens een voornaam of
   werkplaatsnaam; de repository is openbaar.
7. Verwijder bij elk werkelijk gemeten gewricht de `_status: PLACEHOLDER`-regel.

> **Eerlijk erbij:** `arm/calibration.json` bestaat nog niet en staat **expres** niet in deze
> repo. Het is **jouw** bestand, uit **jouw** metingen — de getallen van iemand anders zijn niet
> bevestigd voor jouw arm. Bewaar het; de bedieningssoftware leest het uit.
>
> Let op wat dit wél en niet zegt: het gaat over **de laptopworkflow**, niet over een fysieke
> blokkade in de arm. De laptoptool weigert zonder dit bestand gecontroleerde bediening. De
> huidige Arduino-sketch kan tijdens zijn eigen startup al een 90°-opdracht versturen.

---

## Wat de begrenzer doet (en de regel die hem laat werken)

De begrenzer is één klein functietje — `clamp(hoek, min, max)` — dat élke bewegingsroutine moet
aanroepen *voordat* er een hoek naar een servo gaat. Hij neemt de hoek die je vroeg plus de
gemeten min en max, en geeft een hoek terug die numeriek binnen dat bereik ligt.

```
clamp(170, 25, 120)  ->  120     // teruggesnoeid naar gemeten max
clamp(10,  25, 120)  ->  25      // opgetrokken naar gemeten min
clamp(75,  25, 120)  ->  75      // al binnen bereik
```

De harde regel voor gecontroleerde bediening: **iedere doelhoek gaat door één begrensde route,
en die route bewijst alleen dat het getal binnen de vastgelegde limieten ligt.**

De begrenzer is software. Hij kan je niet redden van een verkeerde meting, van een draad waar hij
niets van weet, of van een onderdeel dat je erbij gezet hebt sinds je voor het laatst mat. Precies
daarom kijkt er altijd iemand mee.

## Startupgedrag dat je vóór gebruik moet kennen

De penplotter-sketch koppelt in `setup()` alle zes servo's aan en schrijft daarna 90°. Dat gebeurt
vóórdat de gemeten limieten vanaf de laptop aankomen. Een reset of het openen van een seriële
poort kan daarom beweging geven, ook al weigert de laptoptool zonder kalibratie te starten.

Negentig graden is niet als gezamenlijke veilige startupstand op deze arm bevestigd. Behandel de
huidige penplotter daarom als **Nog bevestigen** voor powered startup. Houd de servovoeding uit
tijdens reset en gebruik de sketch pas nadat een toekomstige startupstrategie op de echte arm is
getest en gedocumenteerd. Zie [`arm/README.md`](../../arm/README.md).

---

## Zo controleer je het resultaat

De documentatiefase is geslaagd als `arm/calibration.json` per gewricht een herleidbare ruwe min,
max en midden bevat. Markeer ze **Experiment** totdat de startup is opgelost en ieder gewricht
onder toezicht is gevalideerd zonder persen, brommen of kabelspanning.

Controleer bovendien:

1. `min < center < max` voor ieder gewricht;
2. geen placeholdertekst meer in het echte bestand;
3. pinvolgorde en gewrichtsnaam komen overeen;
4. een testcommando net onder `min` en net boven `max` wordt in een **droge softwaretest** naar
   de grens teruggesnoeid;
5. powered startup is nog niet als veilig afgevinkt zolang de 90°-opdracht in `setup()` bestaat.

## Veelgemaakte fouten

- Limieten van internet of een identieke kit kopiëren.
- Alle gewrichten tegelijk testen.
- Alleen naar de servohoorn kijken en kabels, grijper en belasting vergeten.
- Een softwareclamp een botsingssensor noemen.
- Na een mechanische wijziging de oude kalibratie blijven vertrouwen.
- Denken dat de laptopweigering ook Arduino-resetbeweging voorkomt.

## Wanneer vraag je Claude om hulp?

- *"Controleer mijn calibration.json op ontbrekende gewrichten, placeholders en onlogische volgorde; beweeg niets."*
- *"Maak een droge test die alle grensgevallen van clamp() laat zien zonder een seriële poort te openen."*
- *"Wijs in deze sketch precies aan welke opdrachten tijdens setup beweging kunnen veroorzaken."*
- *"Ontwerp eerst een testplan voor een startup zonder sprong; wijzig de code pas nadat ik de huidige rusthouding heb gemeten."*

## Bronnen en bewijsniveau

- Feitelijk startupgedrag: [`pen_plotter_arm.ino`](../../projects/arm-pen-plotter/pen_plotter_arm.ino)
  — **Geverifieerd in broncode**, gecontroleerd 2026-08-07; fysieke uitwerking nog **Nog
  bevestigen** op de werkbank.
- Hoeklimieten en marges — **Experiment**; alleen de eigen meting kan ze bevestigen.
- Algemene servocontext: [`research/dossiers/servos.md`](../../research/dossiers/servos.md) —
  ruwe research, opnieuw beoordelen vóór gebruik.

---

De oude map [`guides/arm-envelope-explained/`](../arm-envelope-explained/) verwijst alleen nog
naar deze gids, zodat veiligheidsinformatie één actuele bron houdt.
