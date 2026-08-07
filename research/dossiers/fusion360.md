<!-- RAW RESEARCH — do not edit. Rewrite into Dutch cards in site/kennis.html instead. -->
> **Topic:** fusion360 · **Tool:** ChatGPT deep research · **Received:** 2026-08-07
> **Source:** the owner's Drive folder <https://drive.google.com/drive/folders/1Vg9HJxbKaBuv31Ovm4uSlIIMFyi7Yun3>
> **Known artifact:** every card carries an inline `cite…turn…` marker wrapped in invisible private-use characters (U+E201/U+E202). STRIP BOTH before any text reaches the site.
> Saved unedited, per `research/deep-research-prompts.md` § After the research comes back.

---

# Autodesk Fusion voorbij dagelijks tekenen: parametriek en Python-API

Peildatum: **7 augustus 2026**. Gericht op Autodesk Fusion voor Windows met een gratis **Personal Use**-licentie.

## A. Parametrisch modelleren zoals het bedoeld is

### Wat is het praktische verschil tussen User Parameters en Model Parameters?

**User Parameters** maak je bewust aan via **Design > Modify > Change Parameters**. Geef kernmaten namen zoals `plaatdikte`, `speling`, `breedte` en `vingerAantal`. **Model Parameters** ontstaan automatisch bij schetsmaten en timeline-features, bijvoorbeeld de afstand van een Extrude. Beide mogen formules bevatten, maar User Parameters vormen de stabiele publieke “bedieningslaag” van het model. Gebruik dus `kastBreedte = 420 mm` en laat modelmaten verwijzen naar `kastBreedte`, in plaats van later tussen `d17`, `d38` en `d91` te zoeken. Autodesk ondersteunt ook comments, favorieten en eenheidhoudende expressies. citeturn1search1

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?guid=SLD-MODIFY-PARAMETERS  
CONFIDENCE: SOLID

### Wanneer gebruik je een Driven Dimension?

Een **Driving Dimension** bepaalt geometrie; een **Driven Dimension** meet het resultaat van andere constraints, parameters of geometrie. Fusion toont driven maten tussen haakjes en als alleen-lezen in **Change Parameters**. Ze zijn nuttig voor controlematen: een berekende diagonaal, resterende wandbreedte of afstand tussen twee door andere regels gepositioneerde gaten. Een driven maat kan bovendien elders in dezelfde schets, andere schetsen en features worden gerefereerd. Maak een maat driven wanneer een extra driving maat de schets zou overconstrainen; gebruik hem niet als vervanging voor ontbrekende ontwerpintentie. citeturn1search0

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?guid=SKT-SKETCH-CREATE-DIMENSIONS  
CONFIDENCE: SOLID

### Waarom overleeft een volledig gedefinieerde schets een maatwijziging?

Een volledig constrained schets heeft geen onbedoelde vrijheidsgraden: geometrie kan niet willekeurig verschuiven wanneer een parameter verandert. Afstanden, raaklijnen, symmetrie, horizontaliteit en relaties met oorsprong of constructiegeometrie bepalen samen **hoe** de nieuwe vorm moet worden berekend. In een gedeeltelijk constrained schets bestaan meerdere geldige oplossingen; de solver kan dan een profiel omklappen, een boog naar de andere zijde verplaatsen of een downstream profiel verliezen. Autodesk waarschuwt expliciet dat verwijzingen naar unconstrained geometrie in complexe parametrische modellen onvoorspelbare resultaten kunnen geven. citeturn1search2

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?contextId=SKT-3D-SKETCH  
CONFIDENCE: SOLID

### Welke verwijzingen maken een parametrisch model robuuster?

Verwijs waar mogelijk naar **origin planes, axes, sketch geometry en construction geometry**, niet naar toevallig ontstane randen of vlakken van late features. Een schets “op de bovenkant” van een body kan zijn referentie verliezen wanneer een eerdere Chamfer, Fillet of Extrude de face-identiteit verandert. Een offset construction plane met parameter `hoogte` is voorspelbaarder. Geprojecteerde geometrie is associatief en wordt bijgewerkt, maar blijft afhankelijk van het bestaan van de bronrand. De robuuste volgorde is daarom: hoofdparameters, vaste referentiegeometrie, master sketches, hoofdvolumes, daarna details zoals gaten en afrondingen. citeturn1search2

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?contextId=SKT-3D-SKETCH  
CONFIDENCE: SOLID

### Hoe test je of een model werkelijk parametrisch is?

Open **Design > Modify > Change Parameters** en test niet alleen de nominale maat, maar ook geloofwaardige uitersten. Maak bijvoorbeeld `plaatdikte` tijdelijk 9, 18 en 30 mm; verander `breedte` met ±30%; test een oneven en even `vingerAantal`. Controleer daarna de timeline op gele waarschuwingen, rode fouten, verdwenen profielen en omgekeerde extrusierichtingen. Formules zoals `binnenBreedte = buitenBreedte - 2 * plaatdikte` leggen de bedoeling expliciet vast. Een model dat slechts bij één maatcombinatie werkt, is geometrisch getekend maar nog niet als parametrisch systeem ontworpen. citeturn1search1turn1search2

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?guid=SLD-MODIFY-PARAMETERS  
CONFIDENCE: SOLID

## B. De Python-API

### Hoe laad je op Windows een Python-programma in Fusion?

Open **Utilities > Scripts and Add-Ins**. Kies bovenaan **+ > Script or add-in from device** en selecteer de volledige map van het programma, niet alleen het `.py`-bestand. Fusion onthoudt die map; selecteer daarna het script en klik op het pictogram in de kolom **Run**. Permanent installeren kan door de programmamap te plaatsen in `%appdata%\Autodesk\Autodesk Fusion\API\Scripts`. De map hoort minimaal een gelijknamig Python-bestand en manifest te bevatten. Een veiligere methode voor losse code is **+ > Create script or add-in**, kies **Script**, **Python**, plak de code in het aangemaakte bestand en sla op. citeturn0search1turn0search5turn16search3

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?guid=GUID-9701BBA7-EC0E-4016-A9C8-964AA4838954  
CONFIDENCE: SOLID

### Waarin verschilt een script van een add-in?

Een **script** wordt gestart, voert doorgaans één taak uit via `run(context)` en eindigt. Een **add-in** blijft tijdens de Fusion-sessie actief, kan automatisch starten, knoppen toevoegen en op events reageren; daarvoor gebruikt hij meestal zowel `run(context)` als `stop(context)`. Beide gebruiken exact dezelfde Fusion-API: er bestaan geen API-calls die uitsluitend voor scripts of uitsluitend voor add-ins beschikbaar zijn. Kies een script voor “maak nu deze gatenreeks” of “exporteer deze variant”. Kies een add-in voor een blijvende knop, dialoog, selectie-interactie of automatisch reagerende workflow. citeturn7search3

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?guid=GUID-9701BBA7-EC0E-4016-A9C8-964AA4838954  
CONFIDENCE: SOLID

### Hoe moet je het objectmodel begrijpen zonder programmeerjargon?

Het objectmodel is de Browser en timeline in navigeerbare Python-objecten. `adsk.core.Application.get()` geeft Fusion; `app.activeProduct` geeft het actieve product; als dat een model is, cast je het naar `adsk.fusion.Design`. Daaronder zit `design.rootComponent`, met collecties zoals `sketches`, `features`, `bRepBodies` en `occurrences`. Een bestaande extrusie wordt bijvoorbeeld voorgesteld door een `ExtrudeFeature`. Collecties bevatten objecten; input-objecten beschrijven wat je wilt maken; een `.add(...)`-methode maakt de feature. Denk: **Fusion > document > design > component > collectie > object**. citeturn7search26turn11search11

SOURCE: https://help.autodesk.com/cloudhelp/ENU/Fusion-360-API/files/BasicConcepts_UM.htm  
CONFIDENCE: SOLID

### Waar zit de beruchte centimeterfout?

Numerieke lengtes in veel lage API-objecten gebruiken intern **centimeters**, ongeacht of het document millimeters toont. `adsk.core.Point3D.create(10, 0, 0)` betekent daarom doorgaans 10 cm, niet 10 mm. Voor een maker die in millimeters denkt is `ValueInput.createByString('10 mm')` veiliger dan `ValueInput.createByReal(10)`. Voor berekeningen kun je millimeters expliciet delen door 10, of `design.unitsManager` gebruiken om waarden te converteren en expressies te evalueren. Parameter-eigenschappen zoals `.value` leveren eveneens interne waarden; `.expression` kan leesbare tekst als `18 mm` bevatten. citeturn2search0turn13search0turn13search6

SOURCE: https://forums.autodesk.com/t5/fusion-api-and-scripts-forum/how-to-make-points-in-inches-instead-of-cm/td-p/10939865  
CONFIDENCE: COMMON

### Wat controleer je wanneer een script zichtbaar niets doet?

Controleer eerst dat het script vanuit Fusion is gestart; een Fusion-script werkt niet als gewone Python via dubbelklikken of **Run Python File** in VS Code. Zet als eerste regel in `run()` een `ui.messageBox('start')`. Gebruik vervolgens:

```python
except:
    app.log(traceback.format_exc())
```

Open op Windows **Text Commands** met `Ctrl+Alt+C`. Controleer daarna `app.activeDocument` en `app.activeProduct`: sinds de API-wijzigingen van 2026 mogen die `None` zijn wanneer geen document openstaat. Test in kleine stappen en sla het Python-bestand vóór iedere Run op. Voor add-ins: eerst **Stop**, daarna opnieuw **Run**. citeturn16search0turn7search7turn2search17

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?guid=GUID-9701BBA7-EC0E-4016-A9C8-964AA4838954  
CONFIDENCE: SOLID

## C. Dingen die het scripten waard zijn

### Wanneer wint een script overtuigend van Rectangular Pattern?

De ingebouwde pattern-feature blijft de beste keuze voor één regulier, associatief patroon. Een script wint wanneer aantallen, afstanden, uitsluitingen of richtingen uit regels of gegevens komen: bijvoorbeeld 137 ventilatiegaten waarbij posities binnen een randzone of rond bevestigingspunten worden overgeslagen. Relevante API-objecten zijn `RectangularPatternFeatures`, `CircularPatternFeatures`, `ObjectCollection` en `ValueInput`. Een script kan eerst alle posities berekenen, uitzonderingen filteren en daarna features genereren. Voor één rooster is de muis sneller; voor tientallen afwijkende roosters of herhaalde opdrachten wordt code beslissend. citeturn11search19turn7search11

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?contextId=MODEL-RECTANGULAR-PATTERN-CMD  
CONFIDENCE: SOLID

### Hoe automatiseer je een familie van maten zonder Configurations?

Laat één goed parametrisch model sturen door User Parameters en schrijf een script dat bijvoorbeeld `breedte`, `hoogte` en `gatDiameter` via `UserParameter.expression` wijzigt. Na iedere wijziging laat je Fusion recomputeren en exporteer je de actieve variant via `ExportManager`. Zo kun je 40 beugelbreedtes of alle combinaties voor M3, M4 en M5 genereren zonder 40 modellen handmatig te onderhouden. Dit is extra relevant voor Personal Use, omdat Autodesk **Configurations** bij de betaalde Fusion-functionaliteit plaatst. Het script moet vóór export controleren op compute-fouten en unieke bestandsnamen gebruiken. citeturn1search1turn4view2turn11search21

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?guid=SLD-MODIFY-PARAMETERS  
CONFIDENCE: SOLID

### Hoe ziet een scriptbare gatenworkflow eruit?

Laat code eerst een lijst posities maken, bijvoorbeeld op een raster, steekcirkel of CSV-coördinaten. Maak daar `SketchPoint`-objecten van en gebruik ze als plaatsingsinput voor `HoleFeatures`. Eén `HoleFeature` kan meerdere punten gebruiken wanneer diameter, diepte en gatvorm gelijk zijn. Voor varianten kan code de diameter, countersink, counterbore of extent aanpassen. Dit is betrouwbaarder dan losse cirkels extrude-cutten wanneer de gaten later als gaten herkend moeten worden in CAM. Voeg vóór uitvoering controles toe voor minimale randafstand, overlap en componentselectie; anders maakt automatisering alleen sneller een fout patroon. citeturn11search24turn11search8

SOURCE: https://www.autodesk.com/learn/ondemand/curated/part-modeling-fusion-360/7GAVRigY6I9FDKzphz9ZnU  
CONFIDENCE: SOLID

### Waarom zijn finger-jointed boxes een schoolvoorbeeld voor scripting?

Een finger joint combineert discrete regels: plaatdikte, totale randlengte, gewenst aantal vingers, kerf of speling, afwisseling tussen pen en uitsparing en eventueel dogbones voor een frees. Voor zes panelen leidt dat snel tot honderden handelingen en veel kansen op inconsistentie. Een add-in kan overlappende bodies analyseren, contactvlakken vinden, vingerverdeling berekenen en uitsparingen op beide delen maken. Het open-source **BoxJoint**-project toont bovendien een editable custom feature die opnieuw berekent wanneer eerdere bodies wijzigen. Niet ieder finger-joint-script is parametrisch; controleer dit expliciet vóór gebruik. citeturn9search0turn9search1

SOURCE: https://github.com/EvilHacker/BoxJoint  
CONFIDENCE: COMMON

### Welke exporttaken zijn de moeite van automatisering waard?

Automatiseer exports wanneer dezelfde ontwerpbron herhaaldelijk naar meerdere outputs moet: 3MF voor printen, STEP voor uitwisseling, DXF voor plaatdelen en eventueel verschillende mesh-resoluties. `ExportManager` kan exports uitvoeren; add-ins zoals **ExportIt** voegen naamregels, resoluties, herhaalbare instellingen en export per body of component toe. Een nuttige naam kan automatisch `onderdeel_breedte-120_dikte-18_v07.3mf` worden. Laat code nooit stilzwijgend bestaande bestanden overschrijven en exporteer pas nadat `design.computeAll()` zonder fouten is voltooid. Batch-export is vooral waardevol bij productfamilies, printprofielen en periodieke archivering. citeturn11search18turn3search8

SOURCE: https://github.com/WilkoV/Fusion360_ExportIt  
CONFIDENCE: COMMON

## D. Van Fusion naar een machine

### Wat stuur je naar Bambu Studio: STL of 3MF?

Gebruik bij voorkeur **3MF**. Open **Design > Utilities > Make > 3D Print**, of rechtsklik op een body/component en kies **Save As Mesh**. STL bewaart uitsluitend een getrianguleerd oppervlak en heeft geen gestandaardiseerde eenheidsmetadata; namen, parameters, timeline en exacte B-Rep-geometrie verdwijnen. 3MF is eveneens meshgebaseerd, maar kan expliciete units, objectstructuur, kleuren en andere metadata bevatten. Fusion ondersteunt zowel `.3mf` als `.stl` onder alle licentietypen. De slicer bepaalt daarna laaghoogte, support, infill en G-code; die informatie hoort niet in het oorspronkelijke Fusion-model. citeturn3search0turn3search8turn3search17

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?caas=caas%2Fsfdcarticles%2Fsfdcarticles%2FHow-to-export-an-STL-file-from-Fusion-360.html  
CONFIDENCE: SOLID

### Wat exporteer je voor een lasersnijder?

Maak of selecteer de uiteindelijke vlakke schets en kies in de Browser **rechtsklik op Sketch > Export DXF**. De huidige dialoog laat units en zichtbare geometrie kiezen. DXF bewaart 2D-lijnen, bogen, cirkels, splines en eventueel tekstobjecten voor uitwisseling, maar niet de Fusion-constraints, User Parameters, feature timeline of 3D-relaties. Controleer in de laser-/nestsoftware altijd één bekende maat, gesloten contouren, dubbele lijnen en splineconversie. Kerfcompensatie hoort óf centraal in het parametrische model óf in de machineworkflow; pas haar niet ongemerkt in beide toe. citeturn3search1turn3search5

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?caas=caas%2Fsfdcarticles%2Fsfdcarticles%2FHow-to-Save-Sketch-as-DXF-in-Fusion-360.html  
CONFIDENCE: SOLID

### Wat gaat vanuit Fusion daadwerkelijk naar een CNC-frees?

Een CNC-machine krijgt geen Fusion-model maar controller-specifieke **NC-code**. Maak in de **Manufacture**-workspace een Setup, genereer operations en kies **Actions > Post Process**. De postprocessor vertaalt generieke toolpaths naar commando’s voor de betreffende besturing, bijvoorbeeld `G0`, `G1`, `G2`, `G3`, spindle-, koelmiddel- en toolcommando’s. De NC-file bewaart bewegingen, voedingen en machinecommando’s, maar niet de parametrische CAD-opbouw. Kies daarom een postprocessor die bij de exacte controller hoort en simuleer vóór productie. Splines en oppervlakken kunnen in de uiteindelijke toolpath worden benaderd door lineaire segmenten volgens de ingestelde tolerantie. citeturn3search3turn3search26

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?contextId=MFG-POST-PROCESS-OPERATIONS  
CONFIDENCE: SOLID

### Wanneer gebruik je F3D, F3Z of STEP?

Gebruik **F3D** als de ontvanger in Fusion verder moet ontwerpen: dit is het native archiefformaat dat de timeline en bewerkbare Fusion-informatie bewaart. Een ontwerp met externe referenties wordt als **F3Z** verpakt. Gebruik **STEP** voor uitwisseling van exacte solid- en surface-geometrie met andere CAD/CAM-pakketten. STEP is veel geschikter dan STL voor verdere verspaning of maatvaste CAD-bewerking, maar bewaart de Fusion-timeline, constraints, scripts en User Parameters niet als dezelfde bewerkbare ontwerpstructuur. Een geëxporteerd bestand blijft bovendien niet associatief gekoppeld aan het oorspronkelijke Fusion-document. citeturn3search8turn3search11

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?caas=caas%2Fsfdcarticles%2Fsfdcarticles%2FExport-format-options-for-Fusion-360.html  
CONFIDENCE: SOLID

### Welke informatie verdwijnt bij de belangrijkste machineformaten?

**F3D/F3Z** bewaren de meeste Fusion-intelligentie. **STEP** bewaart exacte 3D-vorm en meestal assemblystructuur, maar geen Fusion-featuregeschiedenis. **3MF/STL** zetten oppervlakken om in driehoeken; STL verliest daarnaast betrouwbare units en rijke metadata. **DXF uit een sketch** bewaart 2D-uitwisselingsgeometrie, niet de schetslogica. **NC/G-code** bewaart alleen de geposte machinebewegingen en instructies. Geen van deze afgeleide outputs moet als masterbestand dienen. Houd het parametrische Fusion-document als bron en genereer machinebestanden opnieuw wanneer een parameter, gereedschap, materiaal of machine-instelling verandert. citeturn3search8turn3search11turn3search3

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?contextId=ASM-EXPORT-DESIGN  
CONFIDENCE: SOLID

## E. Grenzen van de gratis Personal Use-licentie

### Wie mag Personal Use gebruiken en hoe lang geldt de licentie?

De licentie is voor individuele, thuisgebaseerde, niet-commerciële projecten. Ze mag niet worden gebruikt voor primaire arbeid, binnen een bedrijfsomgeving of voor commerciële training. Autodesk noemt als financiële grens minder dan **USD 1.000 jaarlijkse omzet**; zodra het gebruik commercieel wordt of die omzet wordt overschreden, moet de gebruiker stoppen met Personal Use en naar een betaalde licentie overstappen. De actuele product- en supportpagina’s noemen een termijn van **drie jaar**, waarna opnieuw kan worden aangevraagd zolang de gebruiker nog kwalificeert. Verlengen kan volgens Autodesk vanaf 30 dagen voor afloop. citeturn4view2turn8search0turn8search3

SOURCE: https://www.autodesk.com/products/fusion-360/personal  
CONFIDENCE: SOLID

### Betekent de limiet van tien documenten dat je maar tien ontwerpen mag hebben?

Nee. Je mag een onbeperkt aantal documenten en projecten bewaren, maar maximaal **tien documenten tegelijk editable/active** hebben. Andere documenten blijven opgeslagen en kunnen naar read-only/inactive worden gezet. Je kunt vervolgens een ander document activeren. Bij externe assemblies telt ieder geopend, afzonderlijk editable referenced design mee; een assembly mag wel naar inactive referenties verwijzen, maar die referenties zijn dan read-only. PDF’s, afbeeldingen, spreadsheets en vergelijkbare niet-Fusion-documenten tellen niet mee. De limiet is dus een edit-slotlimiet, geen opslaglimiet. citeturn14search3turn5search2turn5search8

SOURCE: https://www.autodesk.com/products/fusion-360/blog/the-10-document-limit-for-personal-use-explained-in-7-steps/  
CONFIDENCE: SOLID

### Welke CAM-functies zijn daadwerkelijk beperkt?

Personal Use ondersteunt basisfrezen met **2-, 2.5- en 3-assige** strategieën, toolpathsimulatie en postprocessing naar NC-code. Niet beschikbaar zijn de geavanceerde 3+2-, 4- en 5-assige mogelijkheden. Autodesk vermeldt voor Personal Use bovendien geen automatische toolchange-uitvoer en beperkt rapid-bewegingen: rapids worden op cutting-feedniveau uitgevoerd in plaats van als volledige machine-rapid. Dat kan cyclustijden sterk verhogen op grotere machines. Basis-CAM is dus bruikbaar voor hobbyrouters en eenvoudige freesdelen, maar niet gelijk aan de commerciële Manufacturing-functionaliteit met geavanceerde automatisering, toolpathmodificatie, inspectie en multi-axis workflows. citeturn14search3turn7search12

SOURCE: https://www.autodesk.com/support/technical/article/caas/sfdcarticles/sfdcarticles/Fusion-360-Free-License-Changes.html  
CONFIDENCE: SOLID

### Welke beperkingen gelden voor drawings, electronics en collaboration?

De Personal Use-versie heeft **single-user data management**, forumondersteuning en beperkte 2D-documentatie. Autodesk specificeert voor de beperkte drawingworkflow één sheet en printgerichte uitvoer in plaats van de volledige commerciële documentatieset. Electronics is beperkt tot maximaal **twee schematic sheets**, **twee signal layers** en ongeveer **80 cm² PCB-oppervlak**. Geavanceerde multi-user collaboration, commerciële supportkanalen, BOM-functionaliteit en Configurations behoren volgens de actuele vergelijking tot betaalde Fusion. Deze beperkingen raken een maker vooral bij grote assemblies, professionele werktekeningen, omvangrijke PCB’s en formele samenwerking; gewoon 3D-modelleren, scripts en printmodellen blijven beschikbaar. citeturn4view2turn14search0turn8search23

SOURCE: https://www.autodesk.com/products/fusion-360/personal  
CONFIDENCE: SOLID

### Welke import- en exportformaten zijn nu wel en niet beschikbaar?

De actuele 2026-tabel noemt voor alle licenties onder meer **F3D, 3MF, DXF via rechtsklik op een sketch, OBJ, STEP en STL**. Dat betekent dat Personal Use momenteel STEP kan exporteren, ondanks oudere artikelen die het tegendeel zeggen. Commerciële/native translators zoals CATIA V5, NX, Parasolid, Creo, Rhino en SolidWorks vallen onder de aanvullende formaten die Personal Use uitsluiten. Ook algemene DXF-export via **File > Export** is niet hetzelfde als sketch-DXF; voor laserwerk blijft **rechtsklik Sketch > Export DXF** de gedocumenteerde route. citeturn4view1turn15search0turn15search1

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?guid=TPD-SUPPORTED-FILE-FORMATS  
CONFIDENCE: SOLID

### Wat is er recent veranderd dat oudere handleidingen onbetrouwbaar maakt?

De huidige Personal Use-termijn is **drie jaar**, terwijl veel oudere handleidingen jaarlijks verlengen noemen. De 2026-formaattabel geeft STEP-export weer voor alle licentietypen, terwijl de beperkingen uit 2020 STEP-export uitsloten. Daarnaast is “Fusion 360” als productnaam grotendeels vervangen door **Autodesk Fusion**, en de Scripts and Add-Ins-dialoog heeft een vernieuwde `+`-workflow voor maken en linken. Voor API-code is eveneens relevant dat Fusion in 2026 zijn embedded Python-versie van **3.12 naar 3.14** heeft bijgewerkt en sommige Application-properties nu `None` kunnen retourneren wanneer geen document openstaat. citeturn8search0turn15search1turn16search3turn7search7turn7search32

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?guid=FIC-REL-NOTES-INC  
CONFIDENCE: SOLID

## Mythes en verouderd advies

### Is “Fusion for Personal Use verdwijnt binnenkort” waar?

Nee. Autodesk biedt Personal Use op 7 augustus 2026 nog steeds expliciet aan als gratis, beperkte licentie voor kwalificerende niet-commerciële gebruikers. De voorwaarden en functionaliteit kunnen veranderen, maar er is geen officiële aankondiging dat het product momenteel wordt beëindigd. De geldigheidsduur is nu drie jaar per toekenning, waarna opnieuw kan worden aangevraagd. “Gratis” betekent niet onbeperkt: commercieel gebruik, meer dan USD 1.000 omzet, geavanceerde CAM, Configurations en bepaalde translators vallen erbuiten. citeturn4view2turn8search0

SOURCE: https://www.autodesk.com/products/fusion-360/personal  
CONFIDENCE: SOLID

### Is “je mag maar tien Fusion-bestanden bezitten” waar?

Nee. De grens is tien **editable/active documents**, niet tien opgeslagen bestanden, ontwerpen of projecten. Inactive documenten blijven bestaan, kunnen worden bekeken en kunnen door het wisselen van status weer editable worden gemaakt. Externe componenten hoeven niet allemaal tegelijk editable te zijn om een assembly te openen; ze zijn dan read-only totdat je een edit-slot vrijmaakt. citeturn14search3turn5search2

SOURCE: https://www.autodesk.com/products/fusion-360/blog/the-10-document-limit-for-personal-use-explained-in-7-steps/  
CONFIDENCE: SOLID

### Is “Personal Use kan geen STEP exporteren” nog juist?

Nee. Dat was onderdeel van de beperkingen die Autodesk in 2020 aankondigde en staat daarom nog in veel video’s en forumantwoorden. De huidige Autodesk-formatentabel van 2026 plaatst **STEP `.stp/.step/.ste` met export** onder de standaardformaten voor alle licentietypen. Commerciële translators zoals SolidWorks, CATIA, NX en Parasolid blijven wel beperkt. Controleer bij toekomstige wijzigingen altijd de actuele formatentabel in plaats van een oude licentievergelijking. citeturn14search3turn15search1

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?guid=TPD-SUPPORTED-FILE-FORMATS  
CONFIDENCE: SOLID

### Is “scripts en add-ins zijn Extensions en dus geblokkeerd” waar?

Nee. **Extensions** zijn betaalde Autodesk-capabilitypakketten; scripts en add-ins zijn uitbreidingen via de Fusion-API. Autodesk bevestigt uitdrukkelijk dat Personal Use toegang houdt tot scripts, add-ins en de API. Een third-party add-in kan zelf natuurlijk een betaalde licentie vragen of functies aanroepen die jouw Fusion-licentie niet bevat, maar het mechanisme **Utilities > Scripts and Add-Ins** is niet geblokkeerd. citeturn7search19turn7search3

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?caas=caas%2Fsfdcarticles%2Fsfdcarticles%2FFusion-360-Free-License-Changes.html  
CONFIDENCE: SOLID

### Is “de Python-API gebruikt de millimeters van het document” waar?

Nee. De zichtbare documenteenheid verandert niet automatisch de interne numerieke lengtes van veel API-objecten. Interne lengtes zijn centimeters. Daardoor kan `Point3D.create(10, 0, 0)` honderd millimeter opleveren terwijl de programmeur tien millimeter bedoelde. Gebruik waar mogelijk `ValueInput.createByString('10 mm')`, parameterexpressies met eenheid of expliciete conversie via `UnitsManager`. citeturn2search0turn13search0

SOURCE: https://forums.autodesk.com/t5/fusion-api-and-scripts-forum/how-to-make-points-in-inches-instead-of-cm/td-p/10939865  
CONFIDENCE: COMMON

### Is “je start een Fusion-script gewoon vanuit VS Code” waar?

Nee. VS Code is de editor en debugger, maar Fusion moet het programma laden in zijn eigen Python-runtime en `run(context)` aanroepen. Start het via **Utilities > Scripts and Add-Ins**. Rechtstreeks uitvoeren als normale Python mist onder meer de geladen `adsk`-omgeving, het actieve document en de Fusion objecten. Voor add-ins moet je na codewijzigingen doorgaans eerst **Stop** en daarna **Run** gebruiken. citeturn16search3turn2search17

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?guid=GUID-9701BBA7-EC0E-4016-A9C8-964AA4838954  
CONFIDENCE: SOLID

### Is “gratis Fusion kan geen bruikbare CNC-code maken” waar?

Nee. Personal Use kan 2-, 2.5- en 3-assige freesbewerkingen genereren, simuleren en via een postprocessor omzetten naar NC-code. De werkelijke beperkingen zijn onder andere geen geavanceerde multi-axis CAM, geen automatische toolchange-capability en beperkte rapid-feeduitvoer. Voor een eenvoudige 3-assige hobbyrouter kan dit functioneel voldoende zijn; voor productie met toolchanger of veel verplaatsingen kan de beperking operationeel zwaar wegen. citeturn14search3turn3search3

SOURCE: https://www.autodesk.com/support/technical/article/caas/sfdcarticles/sfdcarticles/Fusion-360-Free-License-Changes.html  
CONFIDENCE: SOLID

### Is “STL is altijd het beste bestand voor een Bambu-printer” waar?

Nee. STL is breed ondersteund, maar bevat alleen een driehoeksmesh en heeft geen gestandaardiseerde eenheidsinformatie. **3MF** kan units, meerdere objecten, kleuren en aanvullende structuur bewaren en wordt door Fusion en Bambu Studio ondersteund. Voor een enkel eenvoudig object werkt STL nog steeds; voor assemblies, meerdere onderdelen of het vermijden van een schaalfactorfout is 3MF doorgaans de betere overdracht. Geen van beide bewaart de parametrische Fusion-timeline. citeturn3search0turn3search8

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?contextId=ASM-EXPORT-DESIGN  
CONFIDENCE: SOLID

### Is “de hobbylicentie moet ieder jaar opnieuw worden aangevraagd” nog waar?

Niet volgens de actuele Personal Use- en supportpagina’s. Autodesk noemt nu een geldigheidsduur van **drie jaar**, waarna de gebruiker opnieuw kan aanvragen wanneer hij nog aan de voorwaarden voldoet. Veel oudere tutorials noemen één jaar en sommige minder bijgewerkte Autodesk-overzichtspagina’s doen dat eveneens nog; voor de operationele termijn zijn de actuele registratie- en renewal-artikelen de meest specifieke bronnen. citeturn8search0turn8search2turn8search3

SOURCE: https://www.autodesk.com/support/technical/article/caas/sfdcarticles/sfdcarticles/How-to-renew-your-hobbyist-enthusiast-license-for-Fusion-360.html  
CONFIDENCE: SOLID

### Is “oude Fusion-Python-code blijft vanzelf werken” een veilige aanname?

Nee. Fusion heeft zijn embedded Python-runtime in 2026 van 3.12 naar **3.14** bijgewerkt en het API-objectmodel blijft evolueren. Een concreet voorbeeld is dat `Application.activeDocument`, `activeProduct` en `activeViewport` nu `None` kunnen zijn wanneer geen document openstaat. Scripts moeten daarom null-checks, foutlogging en expliciete typecontroles bevatten. Oude code kan nog werken, maar een script zonder defensieve controles kan na een update stil stoppen of een exception produceren. citeturn7search7turn7search32

SOURCE: https://help.autodesk.com/view/fusion360/ENU/?contextId=APIWhatsNew  
CONFIDENCE: SOLID