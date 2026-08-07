# Begin hier — je werkplaats die terugpraat

Welkom. Deze map is voor jou gemaakt: een plek waar je **gewoon in het Nederlands kunt vragen
wat je wilt weten** over je 3D-printers, je robotarm en je Arduino-projecten — en waar het
antwoord daarna **bewaard blijft**.

Je hoeft niet te kunnen programmeren. Echt niet. Je hoeft alleen te kunnen typen wat je je
afvraagt.

**Liever kijken dan lezen?** Open [`index.html`](./index.html) — een filmpje van twee minuten
dat precies dit uitlegt. (Vraag Claude gerust: *"laat me de begin-hier uitleg zien"* — dan zet
hij hem voor je op het scherm.)

---

## In het kort: wat is dit?

Stel je een schriftje voor dat naast je printer ligt. Je schrijft er een vraag in — *"waarom
heeft mijn print overal draadjes?"* — en de volgende ochtend staat er een compleet antwoord in,
met een tekening erbij, toegespitst op **jouw** printer.

Dat is dit. Alleen gaat het antwoorden binnen een minuut, en het schriftje raakt nooit vol.

---

## Wat kun je er vanavond al mee? (kies er één)

Je hoeft niets te installeren voor deze drie. Alleen typen.

### 1. Laat een mislukte print nakijken

Maak een foto van een print die niet goed ging. Sleep hem in het chatvenster en plak dit erbij:

```
Hier is een foto van een 3D-print die niet goed ging. Vertel me in gewone taal:
wat zie ik hier, wat is waarschijnlijk de oorzaak, en welke één instelling zou jij
als eerste veranderen? Het is PLA op mijn kleine printer.
```

Je krijgt terug wat er te zien is, waar het door komt, en **één ding om te proberen**. Niet tien
dingen — één.

### 2. Vraag om uitleg over iets wat je nooit durfde aan te raken

```
Leg me uit wat "retraction" doet in mijn slicer, alsof ik het nog nooit gehoord heb.
Maak er een filmpje-uitleg van die ik kan bekijken.
```

Vul in plaats van *retraction* gerust in wat je maar wilt: infill, koeling, laaghoogte, wat een
servo eigenlijk doet, waarom je Arduino warm wordt. Er staan er al elf klaar in
[`guides/`](../) — die zijn nog in het Engels, maar vraag gewoon *"vat deze samen in het
Nederlands"* en dat gebeurt.

### 3. Gooi een idee naar binnen

```
Ik heb een idee: [jouw idee in één zin]. Zet het in ideas/ en denk er eens goed over na.
```

Je krijgt een eerlijk antwoord terug — inclusief *"dit is een slecht idee, en dit is waarom"*.
Dat is de bedoeling. Er staan al **veertien** ideeën klaar, allemaal afgestemd op jouw
machines: sleutelhangers in twee kleuren, een weegschaal voor je filamentrol, een pen in de
robotarm die tekent.

---

## Hoe begin je? (3 stappen — je hoeft nergens een account voor te maken)

1. **Open Claude**, zoals je dat al doet.

2. **Plak dit erin**, letterlijk:

   ```
   Kijk eens in deze map: https://github.com/menno420/curious-research

   Ik heb twee 3D-printers, een robotarm met 6 servo's en ik knutsel veel met Arduino.
   Leid me er in het Nederlands doorheen: wat staat er allemaal in, en wat is het
   leukste om vanavond mee te beginnen?
   ```

3. **Lees mee en vraag door.** Alles wat je verder wilt weten, vraag je gewoon in gewone taal.
   *"Laat die uitleg over draadjes eens zien"*, *"wat betekent dit?"*, *"kan ik dit met mijn
   printer?"*

**Controle of het werkt:** je krijgt een antwoord in het Nederlands waarin je printers, je
robotarm en je Arduino-bench genoemd worden. Staat dat er — dan heeft Claude de map echt
gelezen en zit je goed.

Dat is het. **Geen account, geen installatie, geen commando's.**

---

## En als je later meer wilt

Zoals het nu staat, kan Claude alles hier **lezen** en aan je uitleggen. Dat is bewust zo, en
het is genoeg voor heel lang: er staan dertien uitleggen, vier bouwprojecten en veertien
ideeën klaar. Daar kun je maanden mee vooruit zonder ook maar iets in te stellen.

Wil je op een dag dat ook **jouw eigen vragen** hier blijvend bij komen te staan — dus dat de
plank uit het filmpje echt van jou wordt en aangroeit — dan is daar een eigen (gratis)
GitHub-account voor nodig. Dat is geen haast en geen huiswerk. Vraag het gewoon als je zover
bent:

```
Ik denk erover om zelf een GitHub-account te maken. Wat zou me dat precies opleveren
in deze map, en wat moet ik dan doen?
```

> **Kun je iets kapotmaken?** Nee. Je kijkt nu alleen maar rond — er verandert niets. En ook
> later niet: van elk bestand blijft elke versie bewaard, voor altijd. Er is altijd een weg
> terug. Experimenteer rustig.

---

## Wat ligt er nu al klaar

| Map | Wat erin zit |
|---|---|
| [`guides/`](../) | **Elf uitleg-filmpjes** met tekst ernaast: eerste laag, draadjes, temperatuur, koeling, infill, lithophanes, de veilige bewegingsruimte van je arm, en meer. |
| [`ideas/`](../../ideas/) | **Veertien ideeën** voor jouw spullen — geen huiswerk, gewoon een menukaart. |
| [`projects/`](../../projects/) | **Vier echte bouwsels**: een pasvorm-testmuntje, een pen-houder voor de arm, een weegschaal voor filamentrollen, en verwisselbaar gereedschap voor de arm. |
| [`guides/windows-gereedschap/`](../windows-gereedschap/) | Welke gratis programma's handig zijn op je Windows-laptop, met directe downloadlinks. |

---

## Vier zinnen die altijd werken

Plak deze gerust letterlijk. Ze zijn gemaakt om geplakt te worden.

```
Leg dit uit alsof ik er niets van weet, in het Nederlands.
```

```
Maak hier een filmpje-uitleg van die ik kan bekijken.
```

```
Wat kan ik hiermee vanavond doen op mijn eigen printer?
```

```
Bewaar dit, zodat ik het volgende week terug kan vinden.
```

---

## Veiligheid — dit staat vast

Drie regels waar niet vanaf geweken wordt. Ze staan uitgebreider in
[`CLAUDE.md`](../../CLAUDE.md) §2.

1. **Claude ontwerpt, jij print.** Claude stuurt nooit zelf iets naar je printer. Jij slicet en
   jij drukt op start. Altijd.
2. **De robotarm beweegt alleen als jij kijkt** — en alleen binnen de grenzen die jij zelf
   opgemeten hebt. Zolang die meting er niet is, weigert de software simpelweg te bewegen.
   *(Hoe je meet staat in [`guides/arm-envelope-explained/`](../arm-envelope-explained/).)*
3. **Servo's krijgen hun eigen stroom** — een aparte voeding van 5–6 volt met een schakelaar
   die je kunt bereiken. **Nooit** via de 5V-pin van de Arduino: die houdt het niet en je
   Arduino kan eraan kapotgaan.

---

## Nog twee eerlijke dingen

- **Een lege week is prima.** Deze map is geen takenlijst. "Niks gebouwd, één ding geleerd" is
  een prima week.
- **Als iets onduidelijk is, ligt dat aan de uitleg, niet aan jou.** Zeg gewoon *"ik snap dit
  niet, leg het anders uit"* — dan komt er een nieuwe versie. Dat is precies waar dit voor is.

---

**Controleer dat alles werkt:** open [`index.html`](./index.html) en druk op **Speel af**. Je
ziet in vijf stappen hoe je vraag een uitleg wordt die op de plank blijft staan — en aan het
eind waarom dat anders is dan gewoon chatten.
