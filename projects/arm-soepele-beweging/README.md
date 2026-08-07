# Soepele beweging — je arm laten optrekken en afremmen

**Wat dit is:** een Arduino-sketch die je arm rustig en beheerst laat bewegen in plaats van
schokkerig, plus de uitleg waaróm dat werkt.

> **Bekijk het eerst:** open [`index.html`](./index.html) in je browser. Daar zie je drie
> keer exact dezelfde beweging naast elkaar — knallen, gelijke stapjes, en optrekken/afremmen
> — met onderin een grafiek van de snelheid. Dat plaatje maakt de rest van deze pagina in
> tien seconden duidelijk.

---

## Het probleem, in één zin

Een hobbyservo heeft **geen snelheidsingang**. Je kunt hem niet vertellen "ga langzaam".

Als je dit schrijft:

```cpp
servo.write(140);
```

zeg je letterlijk: *"sta NU op 140 graden."* De servo geeft vol gas tot hij er is en staat
dan stil. Twee snelheden — alles of niets. Dat is precies het schokkerige, plotselinge
gedrag dat je ziet.

**De vloeiendheid moet dus uit jouw code komen, niet uit de servo.**

---

## De oplossing in drie lagen

Elke laag is een verbetering op de vorige. De sketch doet alle drie.

### Laag 1 — stuur veel doelen die dichtbij liggen

In plaats van één keer `write(140)`, stuur je elke 20 milliseconden een doel dat een klein
stukje verder ligt: 90, 91, 92, 93… De servo jaagt telkens iets na dat vlakbij is, en dan
beweegt hij rustig.

**Waarom 20 milliseconden?** Een gewone analoge servo luistert **50 keer per seconde**. Vaker
sturen is weggegooid werk — hij kijkt er niet naar. Veel langzamer dan dat en je gaat de
losse stapjes zien.

### Laag 2 — laat alle gewrichten tegelijk aankomen

Als de basis 90 graden moet draaien en de pols maar 10, en beide doen 1 graad per stapje,
dan is de pols na 10 stapjes klaar terwijl de basis nog 80 te gaan heeft. Dat ziet er
hakkelig uit, ook al beweegt elke servo op zichzelf netjes.

De sketch kijkt daarom eerst welk gewricht het **verst** moet. Dat bepaalt de looptijd. Alle
andere gewrichten krijgen diezelfde tijd en doen dus rustiger aan. Ze vertrekken samen en
komen samen aan.

### Laag 3 — optrekken en afremmen (dit is de grote)

Verdeel je de beweging in **gelijke** stapjes, dan gaat de snelheid aan het begin in één klap
van stil naar vol, en aan het eind in één klap terug naar stil. Twee schokjes, alleen
kleiner dan bij `write()`. Je voelt ze als een tikje bij vertrek en aankomst.

De sketch verdeelt daarom níet gelijk: **kleine stapjes aan het begin, grote in het midden,
weer kleine aan het eind.** Eén regel rekenwerk doet dat:

```cpp
float sBocht(float t) {
  return t * t * (3.0 - 2.0 * t);      // 3t² - 2t³
}
```

Je stopt er de voortgang in als getal van 0 tot 1 (0 = net begonnen, 1 = klaar), en er komt
een voortgang uit die traag start, versnelt, en weer afremt.

| voortgang in de tijd | 0 | 0,25 | 0,5 | 0,75 | 1 |
|---|---|---|---|---|---|
| gelijke stapjes | 0 | 0,25 | 0,5 | 0,75 | 1 |
| met de s-bocht | 0 | 0,16 | 0,5 | 0,84 | 1 |

Het verschil in **positie** lijkt klein. Het verschil in **snelheid** is het hele punt — en
dat zie je in de animatie.

---

## Aan de slag

### Stap 1 · Meet eerst je grenzen op

Bovenin de sketch staat een tabel `JOINT_MIN` / `JOINT_MAX`. Daar staan nu startwaarden van
85 tot 95 graden in — een spleet van 10 graden rond het midden.

**Dat is expres.** Zo kun je de sketch veilig uitproberen: je ziet hem netjes optrekken en
afremmen binnen een paar graden, zonder dat een verkeerd getal de arm ergens in kan rammen.

Vervang ze door je eigen opgemeten waarden. Hoe je die meet staat in
[`guides/arm-envelope-explained/guide.md`](../../guides/arm-envelope-explained/guide.md).
Meet met marge: blijf een paar graden weg van waar een gewricht mechanisch klem loopt.

### Stap 2 · Controleer je bedrading

⚠️ **Servovoeding is een aparte voeding.** Nooit de 5V-pin van de Arduino. Gedeelde massa,
een zekering, en een schakelaar die je kunt bereiken. Zes MG996R samen vastgelopen is in de
orde van **15 ampère**. De hele rekensom staat in
[`../arm-pen-plotter/pen_plotter_arm.ino`](../arm-pen-plotter/pen_plotter_arm.ino).

### Stap 3 · Zet de pinnen goed

```cpp
const int SERVO_PIN[JOINT_COUNT] = { 3, 5, 6, 9, 10, 11 };
```

Pas aan naar de pinnen waar jouw signaaldraden op zitten.

### Stap 4 · Upload en kijk

Open [`soepele_beweging.ino`](./soepele_beweging.ino) in de Arduino IDE, kies je bordje, en
klik op het pijltje naar rechts (→). Open daarna **Tools → Serial Monitor** op **115200** —
daar vertelt de sketch wat hij doet.

De arm gaat heen en weer tussen twee standen. **Hand bij de schakelaar, ogen erbij.**

---

## Nu het leuke deel — draai aan de knoppen

Dit is geen sketch om te draaien en dan te vergeten. Er zitten drie knoppen in waarmee je
kunt voelen wat er gebeurt.

### `maxSnelheid` — graden per seconde

```cpp
float maxSnelheid = 60.0;
```

| waarde | hoe het voelt |
|---|---|
| `30` | plechtig langzaam, mooi om naar te kijken |
| `60` | rustig en beheerst — goede startwaarde |
| `120` | vlot |
| `300` | ongeveer wat de servo zelf doet bij `write()` — weer schokkerig |

**Het experiment:** zet hem op 300 en kijk. Merk je dat netjes rekenen bij hoge snelheid
bijna niets meer oplevert? Er is simpelweg geen tijd meer om op te trekken. **Vloeiendheid
kost tijd.** Dat is geen instelling die je kunt winnen — dat is de ruil.

### `gebruikSbocht` — aan of uit

```cpp
bool gebruikSbocht = true;
```

Zet hem op `false`, upload, en kijk of je het tikje bij vertrek en aankomst terugvoelt. Zet
hem weer op `true`. Heen en weer schakelen tussen die twee is de beste manier om te snappen
wat laag 3 doet.

### `UPDATE_MS` — hoe vaak je een nieuw doel stuurt

```cpp
const unsigned long UPDATE_MS = 20;   // 20 ms = 50 keer per seconde
```

Zet hem eens op `60`. Nu stuur je nog maar ~17 keer per seconde en zie je de arm stappen in
plaats van glijden. Zet hem op `5` en… er verandert niets, want de servo luistert toch maar
50 keer per seconde. Dat laatste is een nuttige teleurstelling: sneller sturen is niet
altijd beter.

---

## Iets om over na te denken

Een echte open vraag, waar we het antwoord niet van weten voor jouw arm:

> De **schouder** tilt het hele gewicht van de arm op. De **basis** draait alleen maar rond,
> vlak, zonder iets omhoog te hoeven duwen. Zouden die twee wel dezelfde snelheidslimiet
> moeten hebben?

En daar bovenop: omhoog bewegen is zwaar, omlaag helpt de zwaartekracht juist mee. Dezelfde
opdracht levert dus niet dezelfde beweging op, afhankelijk van welke kant je op gaat.

Eén snelheidslimiet **per gewricht** in plaats van één voor de hele arm is een paar regels
code. Je hebt de arm om het uit te proberen — en dat is precies het soort ding waar dit
schriftje voor is. Vraag het gerust:

```
Ik wil een aparte snelheidslimiet per gewricht in soepele_beweging.ino
```

---

## Wat dit níet oplost

Eerlijk zijn helpt meer dan mooi doen:

- **Slop blijft slop.** Speling in de tandwielen en de beugels wordt hier niet minder van.
  De beweging wordt netter, niet nauwkeuriger.
- **Herhaalbaarheid is een ander probleem.** Waar een gewricht precies uitkomt hangt af van
  welke kant hij kwam aanrijden. Dat heet *backlash* en *deadband*, en daar helpt een
  s-bocht niet tegen.
- **Zakken onder gewicht blijft.** Een uitgestrekte arm zakt iets in. Soepel bewegen
  verandert daar niets aan.

De arm wordt hier **rustiger**, niet **preciezer**. Dat is nog steeds veel waard: rustiger
bewegen betekent minder trillen, minder overshoot, en minder stroompieken.
