# Een Python-programma in Fusion 360 laden

**Wat je hier leert:** hoe je een stukje Python in Fusion 360 krijgt en laat draaien, zodat
het voor jou tekent. Je hoeft geen Python te kunnen schrijven — dat doet Claude. Jij plakt en
drukt op Run.

> **Bekijk het eerst:** open [`index.html`](./index.html) in je browser. Daar zie je in een
> halve minuut wat er gebeurt: van "ik wil zes gaten met oplopende maat" naar geometrie in je
> scherm, en waarom één getal veranderen dan meteen een nieuw model oplevert.

---

## Waarom dit de moeite waard is

Je kunt alles wat hieronder staat ook met de muis. Zes gaten tekenen met steeds 0,05 mm
verschil kost een kwartier. En als je daarna denkt *"eigenlijk wil ik ze 0,1 mm uit elkaar"*,
mag je grotendeels opnieuw beginnen.

Met een script verander je één getal en druk je op Run.

**Dat is het hele idee.** Niet moeilijker doen — het saaie werk wegnemen. Fusion blijft
gewoon Fusion; je krijgt er alleen een assistent bij die het herhaalwerk doet.

En het mooie: **Claude schrijft de Python voor je.** Jij hoeft alleen te weten waar je hem
plakt. Dat is precies wat deze pagina uitlegt.

---

## Wat je nodig hebt

- **Fusion 360** — heb je al.
- Meer niet. Er komt een code-editor in beeld, maar die installeert Fusion zelf.

---

## Stap voor stap

### 1 · Open een Design

Start Fusion 360 en zorg dat je een gewoon Design open hebt staan (**File → New Design** als
je twijfelt). Een script tekent *in* een bestand, dus er moet er een zijn.

### 2 · Open het scriptenvenster

Klik bovenin op de tab **UTILITIES**. Klik daar in het paneel **ADD-INS** op
**Scripts and Add-Ins**.

> Sneltoets: **Shift + S**. Die onthoud je zo.

Er opent een venster met twee tabbladen: **Scripts** en **Add-Ins**. Je zit op **Scripts**,
en dat is waar je moet zijn.

*(Verschil, voor als je het je afvraagt: een **script** draait één keer en is daarna klaar.
Een **add-in** blijft draaien zolang Fusion open staat. Wij willen een script.)*

### 3 · Maak een nieuw script

1. Klik op de **+** bovenin het venster.
2. Kies **Create script or add-in** uit het lijstje.
3. In het venster dat opent:
   - **Type:** `Script`
   - **Language:** `Python`
   - **Name:** `teststrip` *(of wat je wilt — geen spaties)*
4. Klik **Create**.

Fusion maakt nu een mapje aan met een leeg script erin. Je ziet het in de lijst verschijnen.

### 4 · Open het in de editor

Je nieuwe script staat geselecteerd in de lijst. Klik op **Edit in code editor** (het knopje
bovenaan het lijstje, of rechtermuisknop → dezelfde optie).

**Visual Studio Code** gaat open — de code-editor die Fusion daarvoor gebruikt. Die installeert
Fusion zelf als je hem nog niet had.

> Schrik niet van hoe het eruitziet. Je hoeft er niets in te doen behalve plakken en opslaan.

### 5 · Plak de code

In VS Code staat je scriptbestand open met wat startcode erin.

1. Klik in het codevenster.
2. Selecteer **alles** — **Ctrl + A**.
3. Verwijder het — **Delete**.
4. Plak de code uit [`teststrip.py`](./teststrip.py) — **Ctrl + V**.
5. Sla op — **Ctrl + S**.

### 6 · Draai het

Terug naar Fusion 360.

Staat het venster **Scripts and Add-Ins** nog open? Selecteer je script en klik **Run**.
Anders: **Shift + S** → je script aanklikken → **Run**.

**Klaar als:** er verschijnt een strookje met zes gaten in je scherm, en een venstertje dat
vertelt welk gat welke speling heeft.

---

## Nu het leuke deel

Open het script weer (**Shift + S** → je script → **Edit in code editor**) en kijk bovenaan.
Daar staat dit:

```python
BREEDTE_MM = 78.0
HOOGTE_MM  = 20.0
DIKTE_MM   = 3.0

PEN_MM = 5.0

SPELINGEN_MM = [0.10, 0.15, 0.20, 0.25, 0.30, 0.40]
```

Verander iets. Bijvoorbeeld:

```python
SPELINGEN_MM = [0.05, 0.10, 0.15, 0.20, 0.25, 0.30, 0.35, 0.40]
```

Opslaan, terug naar Fusion, **Run**. Nu krijg je acht gaten, en het strookje deelt zichzelf
opnieuw in. Je hoefde niets opnieuw te tekenen.

*(Het oude strookje blijft staan — verwijder het even, of begin in een nieuw bestand.)*

---

## De valkuil waar iedereen in trapt

**Fusion rekent van binnen in centimeters.** Niet in millimeters, ook al staat je scherm op
mm en typ je overal mm.

Zeg je in een script `10`, dan denkt Fusion **10 cm**.

Daarom staat er in het script overal `* MM` achter een maat:

```python
MM = 0.1     # 1 mm = 0,1 cm
```

Vergeet je dat een keer, dan komt er een object uit dat **tien keer te groot** is. Dat is niet
stuk en jij doet niets fout — dat is deze regel. Kom je hem tegen, dan weet je het meteen.

---

## Als er iets misgaat

Het script vangt fouten op en laat ze in een venstertje zien in plaats van stilletjes niets te
doen. Krijg je zo'n rode brij te zien:

1. **Schermfoto** — Windows: **Windows + Shift + S**.
2. Sleep hem in Claude.
3. Typ erbij: *"dit komt eruit bij mijn Fusion-script, wat betekent het?"*

Je hoeft die tekst niet te kunnen lezen. Daar is hij niet voor jou geschreven.

Twee dingen die vaak simpelweg de oorzaak zijn:

| Wat je ziet | Wat het meestal is |
|---|---|
| *"Dit script wil een Design om in te tekenen"* | Je had geen bestand open. **File → New Design**. |
| Er gebeurt niets zichtbaars | Kijk of je hebt opgeslagen in VS Code (**Ctrl + S**) voor je op Run drukte. |

---

## Iets om over na te denken

Dit script zet vaste getallen in de geometrie. Verander je er een, dan moet je opnieuw **Run**
drukken en begin je met een nieuw lichaam.

Fusion kan het ook **anders** doen. Het kent zogeheten **user parameters**: benoemde maten die
je in Fusion zelf aanpast via **Modify → Change Parameters**, waarna het model zichzelf
bijwerkt — zonder script, zonder opnieuw draaien.

> **De vraag:** zou je het script die parameters willen laten *aanmaken*, zodat je daarna in
> Fusion aan de knoppen draait in plaats van in de code?

Dat is een echte afweging, geen strikvraag:

- **Getallen in het script** — simpel, alles staat op één plek, maar elke wijziging is een
  nieuwe Run.
- **User parameters** — je draait erna in Fusion aan de maten en het model volgt meteen. Maar
  het script wordt ingewikkelder, en de maten staan dan op twee plekken.

Er is geen goed antwoord. Het hangt ervan af of je vaker één ding wilt bijstellen of vaker een
heel nieuw ding wilt maken. Wil je het proberen:

```
Laat teststrip.py user parameters aanmaken in Fusion in plaats van vaste getallen
```

---

## Wat je hier eigenlijk net hebt geleerd

Niet "hoe maak ik een teststrip". Dat was het excuus.

Wat je nu kunt: **een idee beschrijven en er geometrie uit krijgen.** Vanaf hier werkt alles
hetzelfde — een houder voor je robotarm, een rij bakjes die precies in een la passen, een
patroon dat je met de muis nooit zou uittekenen. Je beschrijft het, je krijgt code, je plakt
en drukt op Run.

Goede volgende vraag om te stellen, letterlijk te plakken:

```
Schrijf een Fusion 360-script dat <wat je wilt> maakt, met de maten bovenaan zodat ik ze kan aanpassen
```

Zeg erbij wat het moet passen, en in welke maten. Dat scheelt een ronde.
