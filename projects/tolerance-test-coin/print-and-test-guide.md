# Speling meten met de parametrische testmunt

## Welk probleem lost dit op?

Deze route bepaalt welke radiale speling op een gekozen printer-, materiaal- en profielcombinatie
een klem-, nauw schuivende of losse passing oplevert. Het resultaat is een vastgelegde
ontwerpwaarde die later terug te voeren is op één fysieke proef.

## Waarom is dit relevant voor jouw setup?

Je ontwerpt eigen onderdelen en gebruikt twee printers. Eenzelfde nominale maat kan op de ene
printer of met een ander materiaal anders passen. Door printer, nozzle, filament en profiel in de
resultatenlog te bewaren kan Claude later de relevante meetwaarde kiezen zonder te doen alsof één
getal overal geldt.

Lees voor de algemene werkplaatscontext
[`docs/workshop-profile.md`](../../docs/workshop-profile.md). De visuele uitleg over radiale en
diametrale speling staat in [`guides/speling/`](../../guides/speling/).

## Benodigde gereedschappen

- [OpenSCAD](https://openscad.org/downloads.html);
- Bambu Studio met het werkelijk gebruikte printer-, nozzle- en materiaalprofiel;
- de gekozen printer en filamentrol;
- bij voorkeur een schuifmaat voor diagnose, naast de noodzakelijke voeltest;
- [`clearance-results.md`](./clearance-results.md) voor het duurzame resultaat.

## Stapsgewijze workflow

### 1. Leg de proefcondities vast

Kies vooraf één combinatie en verander die tijdens de proef niet:

- printer en nozzle;
- filamentmerk, materiaal en kleur;
- laaghoogte en relevante procesprofielrevisie;
- nozzle- en bedtemperatuur;
- waarde voor olifantsvoetcompensatie.

Gebruik geen oude meetwaarde als de combinatie wezenlijk is gewijzigd. Maak in
`clearance-results.md` alvast één rij aan, maar vul de passingen pas na de fysieke test in.

### 2. Kies de meetreeks

Open `tolerance-test-coin.scad`. De standaardreeks loopt van `0.10` tot `0.50` mm radiale speling
in stappen van `0.05` mm. Pas alleen deze waarden aan als de gewenste passing buiten de reeks valt:

```scad
clear_min  = 0.10;
clear_max  = 0.50;
clear_step = 0.05;
```

Laat `pin_d` gelijk binnen één proef. Anders verander je zowel de nominale maat als de speling en
wordt het resultaat moeilijker te vergelijken.

### 3. Render en exporteer

Gebruik in OpenSCAD **F6** of **Design → Render**. Controleer in de console dat geen waarschuwing
of fout verschijnt. Exporteer daarna via **File → Export → Export as STL**.

De repositorybron is automatisch als manifold mesh gecontroleerd. Een eigen parameterwijziging is
nieuwe afgeleide uitvoer en moet daarom opnieuw worden gerenderd en gecontroleerd.

### 4. Controleer in Bambu Studio

1. Kies het echte printer- en nozzleprofiel vóór het slicen.
2. Importeer de STL en controleer dat munt en losse pennen als afzonderlijke volumes aanwezig zijn.
3. Open **Quality → Precision → Elephant foot compensation** en noteer de actieve waarde. Neem niet
   blind een algemeen getal over: deze instelling beïnvloedt precies de onderzijde die je meet.
4. Slice en bekijk Preview laag voor laag. Controleer dat gaten open blijven, labels leesbaar zijn
   en de pennen niet met de munt versmelten.
5. Gebruik geen support in de meetgaten; supportresten zouden de passing veranderen.

### 5. Print één gecontroleerde proef

Start de print en beoordeel de eerste laag. Stop bij loslatende lijnen, sterke verbreding,
materiaalophoping of een profiel dat niet bij printer/nozzle/materiaal hoort. Laat de onderdelen na
de print volledig afkoelen voordat je meet; warme kunststof kan een andere indruk geven.

### 6. Classificeer de passing

Gebruik steeds dezelfde losse pen en werk van klein naar groot. Forceer een te klein gat niet;
beschadiging maakt een tweede beoordeling onbetrouwbaar.

| Waarneming | Classificatie | Ontwerpgebruik |
|---|---|---|
| Gaat niet of alleen met buitensporige kracht | interferentie | onbruikbaar zonder bewuste pers-/nabewerking |
| Stevige druk, blijft zonder merkbare speling zitten | klempassing | delen die bewust vast moeten blijven |
| Schuift gecontroleerd zonder duidelijke zijdelingse speling | nauw schuivend | geleid maar demonteerbaar deel |
| Schuift vrij met beperkte voelbare ruimte | schuivend | bewegend of makkelijk monteerbaar deel |
| Valt erin en rammelt | los | snelle montage waar positionering niet kritisch is |

Herhaal een twijfelgeval minimaal drie keer en controleer of braamvorming of olifantsvoet alleen aan
één zijde het oordeel bepaalt.

### 7. Schrijf het resultaat duurzaam weg

Vul de gekozen rij in [`clearance-results.md`](./clearance-results.md) volledig in. De gegraveerde
waarde is **per zijde**. Bij `0.20` is een gatdiameter dus `pen_d + 0.40` mm.

Een bericht in chat bewaart de meting niet automatisch. Vraag Claude desgewenst om de gemeten rij
in het bestand te zetten, controleer de wijziging en zorg daarna voor back-up of publicatie volgens
[`docs/claude-usage-guide.md`](../../docs/claude-usage-guide.md).

### 8. Gebruik de juiste waarde in een ontwerp

Kies eerst het gewenste passingstype en daarna de rij die exact bij de productiecombinatie past.
In OpenSCAD kan de gemeten radiale speling bijvoorbeeld één parameter worden:

```scad
clearance = 0.20;  // gemeten waarde per zijde voor deze combinatie

module shaft_hole(shaft_r, depth) {
    cylinder(h = depth, r = shaft_r + clearance);
}
```

Bij Fusion 360 hoort dezelfde waarde in een benoemde gebruikersparameter, met printer, materiaal en
meetdatum in de parameterbeschrijving of projectnotitie.

## Hoe verifieer je succes?

De workflow is pas afgerond wanneer:

- de STL zonder OpenSCAD-waarschuwingen rendert;
- Bambu Studio de juiste printer-, nozzle- en materiaalcombinatie toont;
- de geprinte munt en pennen onbeschadigd en volledig afgekoeld zijn;
- minimaal klempassing, nauw schuivend en los zijn geclassificeerd, of expliciet is genoteerd dat
  de reeks niet breed genoeg was;
- `clearance-results.md` omstandigheden, waarden en datum bevat;
- een afgeleide ontwerpmaat aantoonbaar het juiste passingstype en de juiste rij gebruikt.

## Veelgemaakte fouten

- radiale speling verwarren met het totale diameterverschil;
- twee printers of materialen onder één resultaat samenvoegen;
- een compensatiewaarde overnemen zonder het actieve Bambu-profiel te controleren;
- een braam of vervormde eerste laag als normale maat behandelen;
- een te krap gat forceren en daarna opnieuw als meetgat gebruiken;
- de waarde alleen in chat noemen en aannemen dat de repository daarmee is bijgewerkt;
- een geldige manifold STL verwarren met een bewezen fysieke passing.

## Wanneer vraag je Claude om hulp?

- *“Controleer mijn ingevulde rij in `clearance-results.md`. Is duidelijk welke printer, nozzle,
  materiaal- en profielcombinatie is getest?”*
- *“Mijn reeks van 0,10–0,50 mm bevat geen nauw schuivende passing. Stel één nieuwe, smallere
  parameterreeks voor zonder andere SCAD-maten te veranderen.”*
- *“Gebruik voor dit deksel de gemeten klempassing van deze exacte printer- en materiaalrij. Laat de
  berekening van radiale naar diametrale maat zien.”*
- *“Vergelijk twee meetrijen en noem alleen verschillen die door de vastgelegde omstandigheden
  worden ondersteund.”*
