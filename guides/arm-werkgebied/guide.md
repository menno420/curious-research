# Het veilige werkgebied van de arm — en de begrenzer die hem beschermt

Deze pagina geeft je een simpele, praktische manier om per servo het veilige bereik met de hand
op te meten, die getallen op te schrijven, en ze aan de software te geven zodat die elk commando
kan **weigeren** dat een gewricht het bureau, een draad of zijn eigen frame in zou duwen.

Geen wiskunde, geen theorie — gewoon rustig meten, één gewricht tegelijk.

> **Bekijk eerst de animatie.** Dubbelklik op `guides/arm-werkgebied/index.html` en druk op
> **Opnieuw**: je ziet de arm eerst ergens tegenaan lopen en daarna opgevangen worden door de
> begrenzer. Daarna leest de rest van deze pagina een stuk makkelijker.

---

## De woorden die we gebruiken

- **Servo** — een motortje dat je een exacte hoek geeft. Je zegt niet "draai", je zegt "ga naar
  90°", en daar gaat hij heen en daar blíjft hij. Jouw arm heeft er zes.
- **Werkgebied** (ook wel het **veilige bereik**) — elke hoek die een gewricht kan halen
  **zonder** zichzelf, het bureau, een draad of zijn eigen voet te raken. Elk gewricht heeft zijn
  eigen werkgebied.
- **Begrenzer** — een klein stukje software dat elk commando terugsnoeit tot binnen dat veilige
  bereik, vóórdat het bij de motor aankomt. Vraag je 170° op een gewricht dat op 120° ophoudt,
  dan geeft de begrenzer de servo gewoon 120°.
- **Kalibratie** — die veilige hoeken één keer rustig opmeten en opschrijven, zodat de software
  met échte getallen werkt in plaats van met aannames.

---

## Voordat je iets aanraakt — de veiligheidsregels

Deze zijn niet onderhandelbaar.

- **De servo's krijgen hun stroom uit een APARTE voeding van 5–6 V**, met een eigen schakelaar,
  gedeelde massa met de Arduino, gezekerd, en ruim genoeg voor de **blokkeerstroom** (de flinke
  slok stroom die een servo trekt als hij ergens tegenaan duwt en niet verder kan).
  **Nooit uit de 5V-pin van de Arduino.** Een blokkerende servo trekt veel meer dan die pin kan
  geven: de spanning zakt weg en de Arduino reset of gaat raar doen — of hij gaat stuk.

  > *Dit heb je al goed voor elkaar* — de aparte voeding en het verdeelblok staan er. De regel
  > staat hier voor de volledigheid, en omdat hij opnieuw gaat gelden zodra je iets aan de
  > bedrading verandert of er een servo bij zet.

- **Houd je hand bij de schakelaar tijdens elke beweging onder stroom.** Ziet, klinkt of ruikt
  iets vreemd: eerst de stroom eraf, dan pas nadenken.
- **Er kijkt altijd iemand mee.** De arm beweegt nooit onbeheerd — niet één keer, ook niet "even
  om te testen".
- **Doe de EERSTE meetronde met de stroom ERAF**, het gewricht rustig met de hand en op het oog.
  Pas als je ruwweg weet waar de grenzen liggen, laat je een gewricht onder stroom die kant op
  lopen.

---

## Stap voor stap: meet per servo de veilige min, max en midden

Je doet dit voor alle zes de gewrichten. Bij een arm met zes assen zijn dat meestal **voet**,
**schouder**, **elleboog**, **pols kantelen**, **pols draaien** en **grijper** — noem ze zoals
jij ze noemt. Doe **één gewricht tegelijk**, helemaal af, voordat je aan het volgende begint.

1. **Stroom eraf.** Beweeg gewricht 1 met de hand rustig door zijn hele bereik, op gevoel. Zoek
   de twee punten waar hij *net* zijn eigen frame, het bureau of een strakke draad raakt —
   **zonder ergens tegenaan te forceren**. Dat zijn je ruwe fysieke grenzen.

2. **Ga van elke ruwe grens een paar graden terug.** Die kleine marge is je werkelijke **min** en
   **max**. Schrijf ze op.

3. **Zoek het midden** — ongeveer halverwege min en max, de neutrale ruststand waar de arm in
   staat als hij niets doet. Schrijf hem op.

4. **Nu de stroom erop**, met de externe voeding en je vinger bij de schakelaar. Stuur het
   gewricht **langzaam** naar één van je opgeschreven grenzen, op lage snelheid. Haalt hij hem
   netjes met nog wat marge over: goed. Gaat hij **brommen** of persen: stroom eraf en die grens
   terugbrengen.

   > Een brommende of persende servo vecht tegen een mechanische aanslag — hij duwt tegen iets
   > wat niet meegeeft. Draai het getal terug tot de beweging schoon is.

5. **Herhaal dezelfde langzame gang naar de andere grens** en stel dat getal op dezelfde manier
   bij.

6. **Noteer min / max / midden voor dat gewricht** in je kalibratiebestand (hieronder). Daarna
   alle stappen opnieuw voor de andere vijf servo's — telkens één tegelijk.

Zo ziet één afgeronde meting eruit, zodat je weet welke vorm je zoekt:

```
schouder:  min 25°   max 120°   midden 75°
```

---

## Schrijf het op: je kalibratiebestand

In de map `arm/` staat een kant-en-klaar sjabloon. Kopieer het naar een eigen bestand:

```
cp arm/calibration.example.json arm/calibration.json
```

Open daarna `arm/calibration.json` en vul per gewricht je gemeten **min**, **max** en **midden**
in. Zet ook `measured_by` en `measured_on` in, zodat je later weet wie deze getallen genomen
heeft en wanneer.

> **Eerlijk erbij:** `arm/calibration.json` bestaat nog niet en staat **expres** niet in deze
> repo. Het is **jouw** bestand, uit **jouw** metingen — de getallen van iemand anders zijn niet
> veilig voor jouw arm. Bewaar het; de bewegingscode leest het uit.
>
> Let op wat dit wél en niet zegt: het gaat over **dit gereedschap**, niet over je arm. Jouw arm
> beweegt allang. Zonder dit bestand weigert alleen de code hiér te starten, en dat is met opzet.

---

## Wat de begrenzer doet (en de regel die hem laat werken)

De begrenzer is één klein functietje — `clamp(hoek, min, max)` — dat élke bewegingsroutine moet
aanroepen *voordat* er een hoek naar een servo gaat. Hij neemt de hoek die je vroeg plus de
veilige min en max die je gemeten hebt, en geeft een hoek terug die gegarandeerd binnen het
veilige bereik ligt.

```
clamp(170, 25, 120)  ->  120     // teruggesnoeid naar de veilige max
clamp(10,  25, 120)  ->  25      // opgetrokken naar de veilige min
clamp(75,  25, 120)  ->  75      // was al veilig, blijft staan
```

De harde regel, in gewone taal: **geen bewegingscode draait zonder dat elk commando door de
begrenzer gaat, en de begrenzer is niet veiliger dan de getallen die je gemeten hebt.**

De begrenzer is software. Hij kan je niet redden van een verkeerde meting, van een draad waar hij
niets van weet, of van een onderdeel dat je erbij gezet hebt sinds je voor het laatst mat. Precies
daarom kijkt er altijd iemand mee.

---

## Je bent klaar als…

…je een ingevulde `arm/calibration.json` hebt met een echte min, max en midden voor alle zes de
gewrichten, én je elk gewricht onder stroom allebei zijn grenzen hebt zien halen zonder persen of
brommen.

---

*Dit is de Nederlandse versie. Het Engelse origineel staat in
[`guides/arm-envelope-explained/`](../arm-envelope-explained/) en blijft daar staan.*
