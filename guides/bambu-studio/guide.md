# Je Bambu-printers doen het meeste al zelf

**Wat je hier leert:** wat je **A1 mini** en je **A1 met AMS Lite** automatisch afstellen vóór
elke print, en wat er daardoor nog wél voor jou overblijft.

> **Bekijk het eerst:** open [`index.html`](./index.html) — daar zie je in een halve minuut
> welke knoppen jouw printer zelf omdraait, en welke van jou blijven.

---

## Waarom deze pagina bestaat

De meeste uitleg over 3D-printen op internet — en ook een deel van de gidsen hier — is
geschreven voor printers die **niets** zelf afstellen. Bij zo'n printer moet je met de hand
het bed waterpas zetten, de hoogte van de nozzle instellen, en dan testprints doen om
trillingen en materiaalstroom goed te krijgen.

**Jouw printers doen dat allemaal zelf. Vóór elke print. Elke keer.**

Dat is geen detail. Het betekent dat je een hoop testprints en gepriegel kunt overslaan waar
anderen avonden aan kwijt zijn. Zonde om dat werk te doen als je machine het al voor je heeft
gedaan.

---

## Wat de A1 en A1 mini zelf doen

Vóór elke print draait de printer een rijtje metingen af:

| Wat | Wat het betekent in gewone taal |
|---|---|
| **Bed levelling** | Meet of het bed scheef staat en rekent dat weg. |
| **Z-offset** | Zoekt zelf de goede hoogte van de nozzle boven het bed. |
| **Trillingsmeting** | Meet hoe de printer resoneert en past het printen daarop aan. |
| **Flow dynamics** | Meet hoe het plastic uit de nozzle komt en corrigeert de druk. *(Bij andere printers heet dit "pressure advance", en moet je dat met testprints uitzoeken.)* |

Die laatste twee zijn het opvallendst. Op een gewone printer zijn dat elk een avondje
uitzoeken met testprintjes en een schuifmaat. Bij jou gebeurt het terwijl je koffie zet.

Wat je printer **niet** heeft: de lasermeting (LiDAR) die de duurdere Bambu's gebruiken om de
eerste laag te scannen. De A1 doet het met een krachtsensor. Dat werkt prima — het is alleen
handig om te weten dat "mijn Bambu scant de eerste laag" niet over jouw model gaat.

---

## Welke gidsen hier gaan dus wél en niet over jou

Eerlijk zijn scheelt je tijd:

| Gids | Voor jou? |
|---|---|
| [`first-layer`](../first-layer/) | **Grotendeels niet meer.** Hij legt uit hoe je met de hand de nozzlehoogte instelt. Dat doet jouw printer zelf. **Wél nuttig:** het stuk over hoe een goede eerste laag *eruitziet* — dat blijft waar. |
| [`temperature-tower`](../temperature-tower/) | **Soms.** Bambu levert per filament een afgestemd profiel. Print je goedkoop of onbekend filament zonder profiel, dan is een temperatuurtoren nog steeds de snelste manier om het uit te zoeken. |
| [`retraction-vs-stringing`](../retraction-vs-stringing/) | **Soms.** De profielen zijn meestal goed. Krijg je tóch draadjes met vreemd filament, dan is dit je uitleg. |
| [`part-cooling`](../part-cooling/) | **Ja, als achtergrond.** De ventilator staat per filament goed ingesteld, maar begrijpen *waarom* PLA en PETG het tegenovergestelde willen helpt je als iets doorzakt. |
| [`infill`](../infill/) | **Volledig ja.** Dit is geen afstelling maar een keuze van jou. Geen printer beslist dit voor je. |
| [`how-print-clearance-works`](../how-print-clearance-works/) | **Volledig ja.** Hoeveel ruimte twee onderdelen nodig hebben om te passen — dat blijft jouw ontwerpkeuze. |
| [`lithophane-night-light`](../lithophane-night-light/) | **Volledig ja.** Een project, geen afstelling. |

**Kort:** de gidsen over *afstellen* zijn deels ingehaald door je machine. De gidsen over
*ontwerpen en kiezen* gelden onverkort — die gaan over beslissingen, en die neemt je printer
niet voor je.

---

## Wat er dan nog wél van jou is

### 1 · De eerste laag bijstellen tijdens het printen

Vindt je printer de hoogte net niet mooi — te plat, of net te los — dan kun je hem tijdens het
printen bijsturen. Op het schermpje van de printer zit een afstelling voor de Z-hoogte terwijl
de print loopt; in Bambu Studio heet dat de eerste-laag-bijstelling.

Kleine stapjes. Een paar honderdste millimeter is al veel.

### 2 · Temperatuur bij vreemd filament

Heeft je filament een profiel in Bambu Studio — gebruik dat. Heeft het er geen, of ziet het
resultaat er niet uit, dan is de [temperatuurtoren](../temperature-tower/) nog steeds het
beste gereedschap dat er is.

### 3 · Alles wat met ontwerpen te maken heeft

Wanddikte, vulling, speling tussen onderdelen, waar je steun neerzet, hoe je een onderdeel op
het bed legt. Hier beslist je printer niets. Dit is waar je eigen inzicht het verschil maakt —
en waar deze map het meest te bieden heeft.

---

## Als er iets misgaat, kijk éérst hier

Bij een zelfafstellende printer is de oorzaak van een mislukte eerste laag zelden een
instelling. Meestal is het iets mechanisch of iets viezigs:

1. **Is het bed schoon?** Vetvlekken van vingers verpesten zowel de hechting *als* de meting.
   Even met wat isopropylalcohol erover.
2. **Is de nozzle schoon?** Zit er een klodder oud plastic aan, dan drukt die tegen het bed
   tijdens het meten en klopt de hele meting niet meer.
3. **Zitten de schroefjes van de hotend vast?** Bij de A1-serie is dit een bekende. Zitten ze
   los, dan meet de krachtsensor onzin, en dan gaat je eerste laag zwerven zonder dat je iets
   fout doet.

Pas als die drie in orde zijn is het zinvol om aan instellingen te denken.

**En anders:** schermfoto of gewone foto van de mislukte print, in Claude, met de vraag
*"wat gaat hier mis?"*. Dat werkt bij dit soort dingen opvallend goed, omdat het meestal
zichtbaar is.

---

## De AMS Lite — over dat afvalhoopje

Je A1 met AMS Lite kan meerdere kleuren. Wat niemand van tevoren vertelt: bij **elke**
kleurwissel moet de printer eerst het oude plastic uit de nozzle duwen voordat de nieuwe kleur
zuiver is. Dat wordt een klein torentje of hoopje naast je print.

Dat is **geen storing**. Dat is natuurkunde: er zit maar één nozzle in, en die moet leeg
voordat de volgende kleur eruit komt.

Waar het op neerkomt:

- **Veel kleurwissels = veel afval.** Een model dat per laag vier keer wisselt kost meer
  weggegooid filament dan het model zelf weegt. Dat is niet overdreven.
- **Minder wissels = minder afval.** Een ontwerp waarbij elke kleur zijn eigen stuk hoogte
  heeft, wisselt maar een paar keer. Hetzelfde model, een fractie van het afval.

Dat is iets om al bij het *ontwerpen* in je achterhoofd te houden, niet pas bij het slicen.

---

## Iets om over na te denken

Je printers stellen zichzelf af. Je arm doet dat niet — daar moet je elk gewricht met de hand
opmeten (zie [`arm-envelope-explained`](../arm-envelope-explained/)).

> **Waarom eigenlijk dat verschil?**

Het is de moeite van het doordenken waard. Een printer weet waar zijn bed is doordat hij
ertegenaan kan duwen en de tegendruk kan meten — hij heeft een **zintuig**. De servo's in je
arm hebben dat niet: die kunnen wél een hoek aannemen, maar niet terugvertellen waar ze staan
of waar ze ergens tegenaan lopen.

Dat is het hele verschil tussen "stelt zichzelf af" en "moet met de hand opgemeten worden":
niet slimmere software, maar **een sensor die er wel of niet is.**

Wat zou je aan de arm moeten toevoegen om hem zichzelf te laten opmeten? Dat is een echte
vraag, met echte antwoorden — en geen ervan is gratis.
