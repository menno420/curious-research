# Windows-gereedschap — wat je nodig hebt, en wat je (nog) niet nodig hebt

Alles hieronder is **gratis** en draait op Windows 10 en 11.

**Het belangrijkste eerst:** je hebt hier **niets** van nodig om te beginnen. Vragen stellen aan
Claude over deze map werkt gewoon in je browser. Installeer pas iets als je het echt gaat
gebruiken — dat scheelt een middag klooien voor niets.

Volgorde hieronder = volgorde waarin het nuttig wordt.

---

## Snel overzicht

| Programma | Waarvoor | Nodig? |
|---|---|---|
| **Je slicer** | Een 3D-model omzetten naar wat je printer echt doet | **Ja** — heb je waarschijnlijk al |
| **Arduino IDE** | Een sketch (programmaatje) naar je Arduino sturen | **Ja**, zodra je met de arm of een sensor werkt |
| **OpenSCAD** | De ontwerpen uit `projects/` omzetten naar een printbaar bestand | **Ja**, zodra je iets uit deze map wilt printen |
| **7-Zip** | Een gedownloade map uitpakken | Handig |
| **Notepad++** | Even in een bestand kijken zonder gedoe | Alleen als je wilt |
| **Git** | — | **Nee.** Echt niet. Claude doet dat. |

---

## 1 · Je slicer — heb je waarschijnlijk al

De **slicer** *(= het programma dat een 3D-model omzet in laagjes en in de instructies die je
printer echt uitvoert)* kwam waarschijnlijk mee met je printer. Gebruik gewoon die.

Weet je niet welke je hebt, of wil je een nieuwe:

- **Bambu Studio** — <https://bambulab.com/en/download/studio> *(voor Bambu-printers)*
- **PrusaSlicer** — <https://www.prusa3d.com/page/prusaslicer_424/> *(werkt met bijna elke printer)*
- **Ultimaker Cura** — <https://ultimaker.com/software/ultimaker-cura/> *(werkt met bijna elke printer)*

> **Vraag dit gerust aan Claude:** *"welke slicer gebruik ik het beste voor mijn printers?"* —
> zeg erbij welke printers je hebt, dan krijg je een echt antwoord in plaats van een lijstje.

**Klaar als:** je kunt een `.stl`- of `.3mf`-bestand openen en op **Slice** klikken.

---

## 2 · Arduino IDE — voor je robotarm en je sensoren

Dit heb je nodig zodra je iets uit `projects/` naar een Arduino wilt sturen. In deze map liggen
al drie kant-en-klare sketches klaar *(**sketch** = zo heet een Arduino-programmaatje)*.

**Download:** <https://www.arduino.cc/en/software>
→ kies **Windows Win 10 and newer, 64 bits** (de gewone installer, niet de "ZIP file")

Zo werkt het, één keer instellen:

1. Installeer en start het programma.
2. Steek je Arduino in de USB-poort.
3. Bovenin staat een uitklapmenu waar **"Select Board"** staat — klik erop. Windows heeft je
   bordje meestal al herkend; kies hem uit de lijst.
4. Open een sketch uit deze map, bijvoorbeeld
   [`projects/spool-weight-scale/spool_scale.ino`](../../projects/spool-weight-scale/spool_scale.ino).
5. Klik op het **pijltje naar rechts** (→) linksboven om hem naar het bordje te sturen.

**Klaar als:** onderin staat **"Done uploading"** in plaats van een rode foutmelding.

> Krijg je een rode foutmelding? Maak er een schermfoto van, plak hem in Claude en vraag *"wat
> betekent dit?"*. Dat is precies waar dit hele repo voor bedoeld is — je hoeft de foutmelding
> niet zelf te kunnen lezen.

⚠️ **Voordat je een servo aansluit, lees eerst de veiligheidsregel:** servo's krijgen hun eigen
voeding van 5–6 volt, met gedeelde massa en een schakelaar die je kunt bereiken. **Nooit** via
de 5V-pin van de Arduino — die levert te weinig stroom en je Arduino kan eraan kapotgaan. Staat
ook in [`CLAUDE.md`](../../CLAUDE.md) §2.

---

## 3 · OpenSCAD — om de ontwerpen hier printbaar te maken

De ontwerpen in `projects/` zijn `.scad`-bestanden. Dat is **CAD waarbij het model een stukje
tekst is** in plaats van iets wat je met de muis boetseert — precies daarom kan Claude ze voor
je schrijven en aanpassen. Jij hoeft er alleen een printbaar bestand van te maken.

**Download:** <https://openscad.org/downloads.html>
→ kies onder **Windows** de **Installer (x86-64)**

Zo maak je er een printbaar bestand van:

1. Open een `.scad`-bestand, bijvoorbeeld
   [`projects/tolerance-test-coin/tolerance-test-coin.scad`](../../projects/tolerance-test-coin/tolerance-test-coin.scad).
2. Bovenin het bestand staan de instellingen (bijvoorbeeld een naam of een maat). Verander
   gerust een getal.
3. Druk op **F6** *(Render — hij rekent het echte model uit; dit duurt even)*.
4. Klik op **File → Export → Export as STL...** en sla het op.
5. Dat `.stl`-bestand open je in je slicer, en printen maar.

**Klaar als:** je een `.stl`-bestand hebt dat je slicer zonder klagen opent.

> **Waarom dit leuk is:** verander één getal bovenin, druk op F6, en je hebt een ander object.
> Dat is de makkelijkste manier om te zien wat "parametrisch ontwerpen" betekent.

---

## 4 · 7-Zip — om een download uit te pakken

Als je deze map ooit als ZIP downloadt, of iemand stuurt je een `.7z`-bestand.

**Download:** <https://www.7-zip.org/download.html>
→ kies **Windows x64** bij de bovenste `.exe`

Windows kan zelf ook ZIP-bestanden uitpakken, dus dit is puur gemak.

---

## 5 · Notepad++ — om even in een bestand te kijken

Handig als je een `.ino` of `.scad` wilt bekijken zonder een heel programma te openen. Kleurt
de tekst netjes zodat het leesbaar is.

**Download:** <https://notepad-plus-plus.org/downloads/>
→ kies de nieuwste versie, dan **Installer 64-bit x64**

Echt optioneel. Kladblok werkt ook.

---

## Wat je expliciet **niet** hoeft te installeren

- **Git** — dit is het programma waar veel mensen op vastlopen. Jij hebt het niet nodig. Claude
  regelt het bewaren; jij klikt op **Merge** in je browser. Klaar.
- **Python** — de scripts in deze map draaien in Claude's eigen werkomgeving, niet op jouw
  laptop.
- **Een code-editor zoals VS Code** — leuk als je nieuwsgierig bent, niet nodig.

Krijg je ergens het advies "installeer eerst X" en snap je niet waarom? Vraag het gewoon:
*"heb ik dit echt nodig, of kan het zonder?"* Meestal kan het zonder.

---

## Als iets niet lukt

Dat is normaal, en het is geen teken dat je iets fout doet. Doe dit:

1. Maak een **schermfoto** van wat er misgaat (Windows: toets **Windows + Shift + S**).
2. Sleep hem in het chatvenster bij Claude.
3. Typ erbij: *"dit gaat mis, wat moet ik doen?"*

Je hoeft de foutmelding niet te begrijpen. Dat is het hele punt.

---

**Controleer dat je klaar bent:** je kunt een `.scad`-bestand openen in OpenSCAD en met **F6**
en **Export as STL** een bestand maken dat je slicer opent. Lukt dat, dan kun je alles in
`projects/` printen.
