# Vulling — wat er ín je print zit, en hoeveel je er echt van nodig hebt

> **Bekijk het eerst:** open [`index.html`](./index.html) in je browser. Je ziet een print
> in doorsnede vollopen met verschillende patronen. Kom daarna hier terug voor het
> proefje. *(Hoe je het opent staat onderaan.)*

Bijna elke print is **hol vanbinnen**. Niet leeg — gevuld met een licht raster dat
**vulling** heet, in de slicer **infill**. De slicer legt precies genoeg plastic binnenin
om de bovenkant en de wanden overeind te houden, en laat de rest lucht.

De vraag die beginners het vaakst stellen is *"hoeveel procent infill moet ik nemen?"* En
het eerlijke antwoord verrast de meeste mensen:

**Meestal veel minder dan je denkt. De wanden doen het werk, niet het percentage.**

Deze pagina laat zien waaróm, en geeft je één klein proefje waarmee je het vanavond zelf
kunt bewijzen.

---

## Woorden die je hier tegenkomt

Elk woord één keer uitgelegd, in gewone taal:

- **Vulling / infill** — het raster van plastic binnenin een print. Vooral lucht, met een
  beetje plastic.
- **Vullingsdichtheid (%)** — hoeveel van de binnenkant plastic is in plaats van lucht.
  0 % = hol, 100 % = massief. 15–20 % is de dagelijkse standaard.
- **Vullingspatroon** — de *vorm* van dat raster (raster, gyroid, lijnen…).
- **Wand** — de dichte omtrek die de nozzle elke laag natrekt. "3 wanden" betekent dat hij
  die omtrek 3 keer trekt, dus een dikkere huid.
- **Boven- en onderlagen** — de dichte deksels op de platte vlakken. De vulling houdt die
  omhoog.

---

## Het ene ding om te onthouden

Een print is sterk door zijn **wanden en zijn boven- en onderlagen**, niet doordat hij
vanbinnen volgepropt zit.

CNC Kitchen — een bekend testkanaal over 3D-printen — mat dat **één wand erbij een
onderdeel sterker maakt dan 20 % meer vulling.** En het kost minder plastic én minder
tijd. Vulling zorgt er vooral voor dat het platte dak niet doorzakt, en geeft de wanden
iets om tegenaan te leunen.

De winnende zet voor een steviger onderdeel is dus bijna altijd: **houd de vulling laag,
doe er een wand bij.**

In **Bambu Studio** staat dat hier:

```
Wanden:   Strength → Wall loops
Vulling:  Strength → Sparse infill density
Patroon:  Strength → Sparse infill pattern
```

Neem dit over als startpunt voor een onderdeel dat stevig moet zijn:

```
Sparse infill density:  15%
Wall loops:             3      (standaard staat hij meestal op 2)
Boven-/onderlagen:      4 à 5
```

---

## Het proefje — 10 % tegen 30 %, en laat de onderdelen het zeggen

Je print **hetzelfde kleine modelletje twee keer** en verandert alleen het
vullingsgetal. Daarna weeg je ze, knijp je erin, en vergelijk je de tijd. Eén waarde
veranderen — dat is de hele methode.

**Stap 1 — Kies iets kleins.** Een kubusje van 2 à 3 cm, of een klein beugeltje. Klein,
zodat elke print snel en goedkoop is.

**Stap 2 — Slice hem op 10 %.** Laad het model in Bambu Studio, ga naar
`Strength → Sparse infill density` en zet hem op:

```
10
```

Schrijf op wat de slicer je nu voorspelt aan **printtijd** en **filament**:

```
10% vulling  →  tijd: ______   filament: ______ g
```

**Stap 3 — Slice hetzelfde model op 30 %.** Verander alléén dat ene getal:

```
30
```

En schrijf de nieuwe schatting op:

```
30% vulling  →  tijd: ______   filament: ______ g
```

Nog vóór je print zie je het al: de versie van 30 % kost meer tijd en meer plastic.

**Stap 4 — Print ze allebei.** Jij zet het filament erin en jij start elke print zelf.
*(Zie de veiligheidsregels onderaan.)*

**Stap 5 — Lees het resultaat met je handen.**

- **Weeg ze** op een keukenweegschaal. Die van 30 % is zwaarder — dat is precies het
  extra plastic waar je voor betaald hebt.
- **Knijp erin**, tussen duim en wijsvinger. Bij de meeste kleine onderdelen voel je
  nauwelijks verschil. Dát is het punt: de wanden doen het werk.
- **Vergelijk de tijden** die je opschreef. De print van 30 % duurde merkbaar langer.

**Stap 6 — Probeer nu de echte oplossing.** Slice het model nog één keer op **10 %
vulling, maar met één wand extra** (van 2 naar 3). Print hem, knijp erin. *Die* voelt
stijver — en hij kostte minder plastic dan de versie van 30 %.

---

## Welk patroon, waarvoor

Het *patroon* verandert de vorm van het raster. Je hoeft het zelden aan te passen, maar
dit is wanneer elk patroon zijn plek verdient:

| Patroon | Waar het goed in is | Pak het wanneer |
|---|---|---|
| **Grid** | Snel, sterk genoeg, de verstandige standaard | Je twijfelt — laat hem gewoon hier staan |
| **Gyroid** | Even sterk in alle richtingen, geen zwakke naden, beetje veerkrachtig | Onderdelen die buigen of van rare hoeken belast worden; licht maar taai |
| **Lijnen / Rectilinear** | Het snelst, het minste plastic, het zwakst | Showstukken die nooit hard aangepakt worden |
| **Concentrisch** | Volgt de omtrek, blijft soepel | Flexibele onderdelen (TPU) die je juist zácht wilt houden |

---

## Wat het kost om aan de knop te draaien

Het percentage voegt plastic en tijd toe in ongeveer een rechte lijn: het percentage
verdubbelen verdubbelt ruwweg het aandeel van de vulling in allebei. Als grove indicatie
voor een klein onderdeel — **de schatting van je eigen slicer is het echte antwoord, lees
die elke keer**:

```
  0%   — hol; het dak heeft steun nodig; breekbaar
 10%   — licht, prima voor showstukken en licht werk
15–20% — de dagelijkse standaard; goede balans
30–50% — merkbaar zwaarder en langzamer; voor onderdelen die echt belast worden
100%   — massief; traag en zwaar; bijna nooit de moeite — doe er liever een wand bij
```

De sprong van 20 % naar 100 % kan het plastic en de tijd van de vulling een paar keer
over de kop jagen, voor bijzonder weinig extra sterkte in de praktijk. Je loopt snel tegen
afnemende opbrengst aan.

---

## Zelf even nakijken (veiligheid)

- **Jij slicet, jij zet hem aan, en jij start elke print.** Claude stuurt nooit een print
  naar je machine en zet nergens "veilig om onbeheerd te draaien". Blijf bij de eerste
  laag.
- Meer vulling = langere print = de machine staat langer heet. **Laat lange prints niet
  onbeheerd draaien.**
- Deze getallen zijn veilige startpunten, geen garantie voor *jouw* printer, filament en
  model. Verander één waarde, kijk wat er gebeurt, en vertrouw op wat de onderdelen je
  vertellen.

---

## Waar dit vandaan komt

- CNC Kitchen — *Infill vs. Wall thickness: which makes a stronger print?* en verwante
  sterktetests (wanden verslaan vullingspercentage als het om sterkte gaat).
- Prusa Knowledge Base — *Infill patterns* (de afweging tussen sterkte en snelheid per
  patroon).
- De tijd- en filamentschatting van je eigen slicer — de eerlijkste bron voor *jouw*
  onderdeel.

---

## Je hebt het door als…

…je naar je twee geprinte kubusjes kunt wijzen, kunt zeggen welke zwaarder is en waarom,
en in één zin kunt uitleggen waarom een wand erbij beter werkt dan de vulling opschroeven.
Lukt dat, dan heeft deze pagina zijn werk gedaan.

---

## Hoe je de animatie opent

Dubbelklik op `guides/vulling/index.html` — hij opent in je browser. Er wordt niets
geïnstalleerd en er gaat niets online.

Of pak hem op je telefoon, zonder account, via
[de website](https://menno420.github.io/curious-research/).

---

*Dit is de Nederlandse versie. Het Engelse origineel staat in [`guides/infill/`](../infill/)
en blijft daar staan.*
