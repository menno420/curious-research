# Speling tussen onderdelen — waarom ze klemmen, en het gaatje lucht dat het oplost

**Bekijk het liever:** open [`index.html`](./index.html) in je browser — die animeert deze
hele pagina in ongeveer 20 seconden. *(Hoe je hem opent staat onderaan.)*

Twee onderdelen die je op **precies dezelfde maat** print, passen niet. Ze lassen aan elkaar
vast tot één klomp. De oplossing is een bewust gelaten laagje lucht — maar daar zitten twee
dingen in waar bijna iedereen de eerste keer over struikelt: die ruimte telt **per kant**, en
de **onderkant** van een gat liegt over de pasvorm.

Hier is het hele idee in vier stappen.

> **Woorden die je hieronder tegenkomt**
> - **Speling** — de ruimte die je expres tussen twee onderdelen laat zodat ze passen.
>   In slicers en CAD heet dit *clearance* of *tolerance*.
> - **FDM** — het printen met gesmolten plastic dat jouw machine doet. Het plastic is nog
>   zacht als het neerkomt, en dát is precies waaróm die speling nodig is.
> - **Slicer** — het programma dat je 3D-model omzet in instructies voor de printer. Bij jou
>   is dat Bambu Studio.

---

## De vier stappen, in gewone taal

### 1. Nul speling mislukt — de onderdelen lassen vast

Een pen en een gat die je even groot tekent, schuiven niet in elkaar. FDM-plastic is zacht op
het moment dat het neergelegd wordt, dus het puilt uit in elke ruimte die je overlaat — en die
was er niet. De twee onderdelen smelten samen tot één geheel.

**Een gat moet dus altijd iets groter geprint worden dan de pen die erin gaat.**

### 2. Speling erbij — en die telt PER KANT

Laat je ruimte, dan schuift de pen erin. De valkuil: die ruimte zit aan **beide** wanden van
het gat, dus hij **telt dubbel over de breedte**.

```
0,20 mm aan de bovenkant
0,20 mm aan de onderkant
------------------------- +
0,40 mm speling over de diameter
```

Je ontwerpt dus **per kant**, en de totale speling is het **dubbele** daarvan. Wil je 0,40 mm
totaal? Teken dan 0,20 mm per kant.

**Dit vergeten is de klassieke eerste-print-fout:** mensen tekenen 0,40 mm per kant en houden
een onderdeel over dat rammelt.

Een goed startgetal voor iets dat moet schuiven is **0,20 mm per kant**. Laat daarna het
muntje (hieronder) je vertellen wat het échte getal van jouw printer is.

### 3. De pasvormladder — vier soorten passing, van strak naar rammelig

Meer ruimte = lossere passing:

| Passing | Hoe het voelt | Pak hem wanneer |
|---|---|---|
| **Klempassing** *(press fit)* | Strak. De onderdelen houden zichzelf vast en moeten er met een stevige duw of een klem in. | Je wilt dat iets blíjft zitten, zonder lijm. |
| **Nauwe passing** *(snug / push fit)* | Gaat er met de hand in, met lichte druk. Geen speling als hij zit. | Je zet het in elkaar maar het hoeft niet te bewegen. |
| **Glijpassing** *(sliding fit)* | Beweegt vrij, met een heel klein beetje speling. | Een asje dat moet draaien, of een dekseltje dat schuift. |
| **Losse passing** *(loose fit)* | Valt erin en rammelt. | Makkelijk in elkaar zetten is belangrijker dan precisie. |

### 4. De olifantenvoet maakt de onderkant scheef

De nozzle drukt die allereerste laag in het hete bed, dus die spreidt **breder** uit dan alle
lagen erboven. Bij een gat puilt die platgedrukte eerste laag naar **binnen**, waardoor de
**onderkant van het gat nauwer is dan de bovenkant**.

Een pen kan dus bovenin prima zakken en onderin vastlopen. Het onderdeel liegt over zijn eigen
pasvorm.

**De oplossing in één regel:** zet **elephant foot compensation** aan (ongeveer `0,2 mm`) in
je slicer. Die schaaft de platgedrukte eerste laag terug, zodat het gat van boven tot onder
even groot is.

> De instelling heet in Bambu Studio ook letterlijk **"Elephant foot compensation"**. Waar hij
> precies in het menu staat heb ik hier niet nagekeken — gebruik het zoekveld in de
> instellingen en typ *elephant*. Ik zeg liever dat ik het niet zeker weet dan dat ik je een
> menupad geef dat ik verzonnen heb.

---

## De echte getallen voor *jouw* printer

De getallen hierboven zijn het *idee*. Wat jouw machine echt nodig heeft hangt af van je
filament, de temperatuur, de printsnelheid en de vorm van het onderdeel — elke printer is net
even anders.

Wil je het meten, print dan het bijbehorende projectje:

- **[Het tolerantiemuntje →](../../projects/tolerance-test-coin/)** — één klein printje met
  pennetjes op een reeks spelingen, zodat je de klem-, nauwe, glij- en losse maat van jouw
  printer zó van het muntje afleest.

---

## Hoe je de animatie opent

Dubbelklik op `guides/speling/index.html` — hij opent in je browser. Er wordt niets
geïnstalleerd en er gaat niets online.

Of pak hem op je telefoon, zonder account, via
[de website](https://menno420.github.io/curious-research/).

> *Eerlijk erbij: de animatie laat het idee zien, niet exacte getallen. Je filament,
> temperatuur, snelheid en vorm schuiven de echte waarden allemaal op — het muntje meet jouw
> printer, deze pagina laat zien waaróm die meting ertoe doet.*

---

*Dit is de Nederlandse versie. Het Engelse origineel staat in
[`guides/how-print-clearance-works/`](../how-print-clearance-works/) en blijft daar staan.*
