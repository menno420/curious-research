<!-- RAW RESEARCH — do not edit. Rewrite into Dutch cards in site/kennis.html instead. -->
> **Topic:** frezen · **Tool:** ChatGPT deep research · **Received:** 2026-08-07
> **Source:** the owner's Drive folder <https://drive.google.com/drive/folders/1Vg9HJxbKaBuv31Ovm4uSlIIMFyi7Yun3>
> **Known artifact:** every card carries an inline `cite…turn…` marker wrapped in invisible private-use characters (U+E201/U+E202). STRIP BOTH before any text reaches the site.
> Saved unedited, per `research/deep-research-prompts.md` § After the research comes back.

---

# Praktisch dossier hobby-CNC-frezen en -routeren

## A — De vier getallen

### Wat bepaalt de voeding, en waarom is “langzamer” niet automatisch veiliger?

De voeding is de lineaire snelheid van de frees door het materiaal, in mm/min. De nuttigste afgeleide grootheid is de spaandikte per tand:

**spaandikte = voeding ÷ (toerental × aantal snijkanten)**.

Voorbeeld: 1 snijkant, 18.000 rpm en 1.440 mm/min geeft 0,08 mm/tand. Te langzaam geeft stof, hitte, glimmende of verbrande wanden en een hoog jankend geluid: de frees wrijft. Te snel geeft dikke, onregelmatige spanen, motorvertraging, stappenverlies of een abrupt ratelend geluid. Verander voeding tijdens een test bij voorkeur met 10–20%, niet meteen met een factor twee. citeturn0search2turn1search0  
SOURCE: https://www.harveyperformance.com/in-the-loupe/speeds-and-feeds-101/  
CONFIDENCE: SOLID

### Wat doet het toerental, en welk geluid verraadt een verkeerde instelling?

Toerental bepaalt de snijsnelheid aan de omtrek én, samen met voeding en aantal snijkanten, de spaandikte. Meer rpm zonder evenredig meer voeding maakt iedere spaan dunner en verhoogt wrijving. Een scherpe, constante “sirene” met fijn stof betekent meestal te veel rpm, te weinig voeding of een botte frees. Een laag, hamerend geluid betekent eerder overbelasting, slechte opspanning of te veel aangrijping. Houd bij een wijziging van 18.000 naar 21.600 rpm dezelfde spaandikte door ook de voeding 20% te verhogen. Overschrijd nooit het maximale toerental van de fabrikant. citeturn0search2turn2search18  
SOURCE: https://www.amanatool.com/maxrpm  
CONFIDENCE: SOLID

### Wat doet de snedediepte, en waarom breekt een frees vaak pas na enkele lagen?

De axiale snedediepte, in Fusion vaak *stepdown*, bepaalt hoeveel snijkant tegelijk belast wordt. Verdubbeling van 2 naar 4 mm verdubbelt bij gelijkblijvende stepover ongeveer het materiaalvolume per millimeter baan. Dieper snijden vergroot buiging, warmte, spaanpakking en de kans dat de schacht of houder het werk raakt. Een steeds harder wordende brom, slechtere wand onderin en spanen die in de sleuf blijven wijzen op te veel diepte. Fabrikantwaarden van 1×, 2× of 3× freesdiameter zijn meestal voor stijve industriële machines; Onsrud verlaagt bij 2×D de geadviseerde spaandikte al 25%. citeturn0search2turn6view0turn6view3  
SOURCE: https://onsrud.com/Forms/Cutting-Data-Recommendations.asp  
CONFIDENCE: SOLID

### Wat doet de stepover, en waarom is sleuffrezen zoveel zwaarder dan zijfrezen?

Stepover is de radiale aangrijping: hoeveel van de freesdiameter zijwaarts in materiaal zit. Een volle sleuf is 100% stepover en belast beide zijden van de frees; spanen kunnen moeilijk weg en de kracht verandert voortdurend. Adaptief voorfrezen gebruikt vaak 10–30% stepover en kan daardoor dieper snijden met gelijkmatiger belasting. Een praktische hobby-start voor een frees van 6 mm is circa 0,6–1,5 mm radiale aangrijping; een volle sleuf vereist meestal minder diepte en soms lagere voeding. Hard ratelen in binnenhoeken ontstaat vaak doordat de effectieve stepover daar plotseling richting 100% gaat. citeturn0search2turn0search0  
SOURCE: https://help.autodesk.com/view/fusion360/ENU/?contextId=MFG-REF-3D-ADAPTIVE-CMD  
CONFIDENCE: COMMON

### Hoe stel je alle vier getallen af zonder willekeurig te gokken?

Begin met toerental en voeding die samen een redelijke spaandikte geven; kies daarna een voorzichtige diepte en stepover voor de stijfheid van jouw machine. Test in een rechte baan en verander steeds één variabele. Goede spanen zijn herkenbare stukjes, niet alleen stof; houtspanen mogen warm zijn maar niet verkoold, kunststofspanen mogen niet samensmelten en aluminiumspanen mogen niet aan de frees lassen. Wordt het geluid hoog en de frees heet, verhoog voeding of verlaag rpm met circa 10%. Gaat de machine bonken of vertragen, verminder eerst snedediepte of stepover; zo blijft de spaandikte behouden. citeturn0search2turn1search0  
SOURCE: https://www.acrylite.co/resources/knowledge-base/article/what-is-the-proper-method-to-use-when-routing-acrylic-sheet  
CONFIDENCE: SOLID

## B — Frezen en graveerbits

### Wanneer kies je een up-cut frees?

Een up-cut spiraal trekt spanen omhoog en uit de sleuf. Dat is de veilige standaard voor pockets, diepe contouren, aluminium en kunststof, omdat achtergebleven spanen anders opnieuw worden gesneden. De keerzijde is opwaartse kracht: dun plaatmateriaal kan optillen en de bovenzijde van multiplex kan splinteren. Gebruik daarom sterke opspanning en een zo kort mogelijke frees. Voor acryl adviseert ACRYLITE expliciet een hardmetalen up-spiral O-flute; gangbare diameters zijn 3,2–12,7 mm. Een up-cut is minder geschikt wanneer uitsluitend een perfecte zichtzijde bovenop telt en de spaanafvoer niet kritisch is. citeturn10search11  
SOURCE: https://www.acrylite.co/resources/fabrication-manuals/routing-premium-acrylite-acrylic-sheet  
CONFIDENCE: SOLID

### Wanneer kies je een down-cut frees?

Een down-cut duwt vezels en spanen omlaag. Daardoor blijft de bovenkant van multiplex, fineer of gelamineerd plaatmateriaal vaak veel schoner en wordt dun materiaal minder snel opgetild. De prijs is slechte spaanafvoer: in een diepe sleuf worden spanen samengeperst, stijgen temperatuur en snijkracht en kan de frees verbranden of breken. Gebruik down-cut vooral voor ondiepe pockets, groeven en een laatste afwerkpassage. Een 6 mm down-cut wordt op industriële productpagina’s vaak rond 16.000–18.000 rpm genoemd, maar dat toerental is geen universele voedingstabel en zegt niets over de draagkracht van een hobbyrouter. citeturn2search20turn2search23  
SOURCE: https://www.whitesiderouterbits.com/collections/down-cut-spirals  
CONFIDENCE: SOLID

### Wanneer werkt een compressiefrees werkelijk zoals bedoeld?

Een compressiefrees heeft onderaan up-cut en bovenaan down-cut; beide oppervlakken worden naar het midden van de plaat gedrukt. Hij is ideaal voor volledige contouren door multiplex, melamine en gefineerde panelen. De eerste snede moet echter dieper zijn dan de lengte van het onderste up-cut gedeelte. Is dat bijvoorbeeld 5 mm, dan moet de eerste laag meer dan 5 mm diep zijn; een lichte hobby-CNC kan dat mogelijk niet dragen. Bij een ondiepe pocket blijft alleen het up-cut deel actief en splintert juist de bovenkant. Compressie is dus geen algemene vervanger voor up- of down-cut. citeturn2search2turn2search11  
SOURCE: https://toolstoday.com/learn/downcut-upcut-and-compression-bits  
CONFIDENCE: SOLID

### Waarom is een single-flute vaak de beste eerste frees voor acryl en aluminium?

Eén snijkant laat een grote spaangroef over. Dat geeft dikke, goed afvoerbare spanen bij hoge routertoerentallen, zonder dat de machine extreme voeding nodig heeft. Bij 18.000 rpm en 0,05 mm/tand is met één snijkant 900 mm/min nodig; met drie snijkanten al 2.700 mm/min. Dat verklaart waarom een drie- of vierfluiter op een hobbyrouter vaak wrijft en aluminium aan de snijkant last. Gebruik een gepolijste O-flute voor acryl en een scherpe, ongecoate of ZrN-gecoate aluminiumfrees voor aluminium. DATRON waarschuwt dat zijn high-speed single-flutes niet praktisch zijn onder circa 15.000 rpm. citeturn1search4turn1search7  
SOURCE: https://www.datron.com/cnc-machine-options/cnc-cutting-tools/  
CONFIDENCE: SOLID

### Waarvoor gebruik je een ball-nose, en waarom is hij slecht voor vlak voorfrezen?

Een ball-nose maakt vloeiende 3D-oppervlakken, reliëfs en organische vormen. De afgeronde punt voorkomt scherpe overgangslijnen, maar precies in het midden is de effectieve snijsnelheid vrijwel nul. Daar wrijft de frees meer dan hij snijdt. Gebruik hem daarom na voorfrezen met een vlakke frees en kies voor de afwerking een kleine stepover, vaak 5–15% van de diameter. Een ball-nose van 6 mm met 0,5 mm stepover laat veel minder zichtbare ribbels achter dan 2 mm stepover, maar vraagt ongeveer viermaal zoveel banen. MDF is bijzonder abrasief en maakt een scherpe ball-nose snel bot. citeturn11search3turn11search7  
SOURCE: https://shop.datron.com/product-category/end-mills/ballnose-end-mills/  
CONFIDENCE: SOLID

### Waarvoor gebruik je een V-bit, en waarom maakt Z-nulpuntfout zoveel verschil?

Een V-bit is bedoeld voor V-carving, belettering, decoratieve groeven, afschuiningen en soms vouwgroeven. Gebruikelijke hoeken zijn 60°, 90° en 120°. De snijbreedte groeit met de diepte: bij een perfecte 90°-punt maakt 1 mm extra diepte de groef ongeveer 2 mm breder. Een Z-fout van slechts 0,2 mm wordt dus zichtbaar als circa 0,4 mm breedteverschil. Brede V-bits kunnen op diepte een veel grotere effectieve diameter krijgen en vragen dan meer koppel; fabrikantbereiken van 16.000–20.000 rpm gelden voor specifieke Whiteside-bits, niet automatisch voor iedere hobbyopstelling. Gebruik voor aluminium een daarvoor ontworpen graveerbit, niet een botte hout-V-bit. citeturn11search1turn11search5  
SOURCE: https://www.whitesiderouterbits.com/products/1550  
CONFIDENCE: SOLID

## C — Materialen

### Wat verandert er bij multiplex?

Multiplex snijdt relatief gemakkelijk, maar de dwarsliggende fineerlagen, lijm en eventuele holtes geven wisselende belasting. Up-cut voert spanen goed af maar kan de bovenzijde splinteren; down-cut houdt de bovenkant schoon; compressie is het best voor volledige doorsneden als de eerste pass diep genoeg kan. Onsrud noemt voor een 6,35 mm industriële frees spaandiktes rond 0,13–0,25 mm/tand, afhankelijk van geometrie. Bij 18.000 rpm en twee snijkanten betekent 0,20 mm/tand 7.200 mm/min: **dit is industriële routerdata, niet een veilige hobby-startwaarde**. Begin op een hobbyrouter veel lager in materiaalafname en verhoog op basis van spanen, geluid en maatvastheid. citeturn6view0turn6view1  
SOURCE: https://onsrud.com/images/Hard%20Plywood%20Cutting%20Data%20Recommendations.jpg  
CONFIDENCE: SOLID

### Wat verandert er bij MDF?

MDF is homogeen en voorspelbaar, maar zeer abrasief en produceert fijn stof in plaats van mooie houtspanen. Het slijt HSS en extra scherpe kunststofgeometrieën snel; hardmetaal is de praktische minimumkeuze, PCD is economisch bij grote productievolumes. Een 6 mm hardmetalen frees kan op een stijve hobbyrouter bijvoorbeeld beginnen rond 18.000 rpm, 1.500–2.500 mm/min en 2–4 mm diepte, waarna je gecontroleerd verhoogt. Dit is een hobby-startvenster, geen fabrikantgarantie. Gebruik afzuiging aan de bron: officiële arbeidsveiligheidsrichtlijnen verlangen dat blootstelling aan houtstof en formaldehyde zo laag mogelijk blijft. citeturn6view2turn2search24turn10search0  
SOURCE: https://www.hse.gov.uk/woodworking/faqs.htm  
CONFIDENCE: COMMON

### Wat verandert er bij acryl?

Acryl faalt meestal door warmte of trilling, niet doordat het materiaal “te hard” is. Gebruik bij voorkeur gegoten plaat, een scherpe gepolijste O-flute, sterke ondersteuning en lucht om spanen te verwijderen. ACRYLITE noemt 10.000–20.000 rpm en 0,004–0,015 inch per tand, oftewel ongeveer 0,10–0,38 mm/tand; de bijbehorende 2.540–7.620 mm/min is doorgaans productiemachinedata. Voor een hobbyrouter is circa 0,04–0,10 mm/tand een voorzichtiger testgebied. Witte of heldere krullen zijn goed; kleverige draden en een dichtgesmeerde frees betekenen meer voeding, minder rpm, betere spaanafvoer of een nieuwe frees. Gegoten acryl heeft minder smelt- en afbrokkelneiging dan geëxtrudeerd. citeturn1search0turn10search1  
SOURCE: https://www.acrylite.co/resources/knowledge-base/article/what-is-the-proper-method-to-use-when-routing-acrylic-sheet  
CONFIDENCE: SOLID

### Is aluminium realistisch op een hobby-CNC?

Ja, vooral goed verspaanbare plaat zoals 6061-T6 of Europees vergelijkbaar materiaal, maar een hobbyrouter moet als lichte hogesnelheidsmachine worden behandeld: scherpe single-flute, ondiepe sneden, beperkte stepover, stijve opspanning en continue spaanafvoer. Een conservatieve 3,175 mm-start kan circa 18.000 rpm, 500–900 mm/min, 0,2–0,5 mm diep en 10–30% stepover zijn. Dit is hobbydata, geen industriële norm. Onsrud-tabellen noemen aanzienlijk grotere spaandiktes en snededieptes voor stijve productiemachines. Stop direct bij aluminium dat aan de snijkant last: dezelfde vastgelaste klomp vergroot de effectieve diameter, waarna de frees vaak binnen seconden breekt. citeturn6view3turn10search2turn10search10  
SOURCE: https://onsrud.com/images/Aluminum%20Cutting%20Data%20Recommendations.jpg  
CONFIDENCE: COMMON

## D — Werkstukopspanning

### Hoe gebruik je klemmen zonder er later met de frees tegenaan te rijden?

Klemmen leveren hoge, controleerbare kracht en zijn geschikt voor dik hout, platen, blokken en aluminium. Plaats ze laag, dicht bij het actieve snijgebied en zodanig dat de snijkracht het werkstuk tegen een aanslag drukt. Klem niet alleen de vier uiterste hoeken van een grote plaat: het midden kan nog 1–2 mm opveren. Modelleer klemmen in Fusion als *fixtures* en houd minimaal enkele millimeters gereedschap- en houdervrijloop aan. Controleer ook de schroefkoppen en de colletmoer, niet alleen de snijkant. Fusion kan botsingen met gemodelleerde fixtures in de simulatie markeren. citeturn3search5turn4search0  
SOURCE: https://help.autodesk.com/view/fusion360/ENU/?contextId=MFG-SETUP-2ND-SIDE  
CONFIDENCE: SOLID

### Hoe groot moeten tabs zijn, en waar plaats je ze?

Tabs houden een uitgefreesd onderdeel verbonden met het omringende materiaal. Voor 12–18 mm multiplex zijn 3–6 mm breed en 1–2 mm hoog bruikbare startwaarden; kleine of zware onderdelen vragen meer of grotere tabs. Plaats ze op rechte, goed bereikbare randen, nabij hoeken en op lange stukken die anders kunnen gaan trillen. Ramped of driehoekige tabs belasten de frees geleidelijker dan abrupte rechthoeken. Tabs zijn geen vervanging voor vlakke opspanning: als de plaat al beweegt, buigen de tabs mee. Snijd bij voorkeur eerst alle interne details en pas als laatste de buitencontour, zodat het grootste opspanoppervlak zo lang mogelijk behouden blijft. citeturn3search2  
SOURCE: https://shopbottools.com/products/holddown/  
CONFIDENCE: COMMON

### Wanneer is tape met secondelijm beter dan dubbelzijdige tape?

Bij de tape-en-CA-methode komt schilderstape op werkstuk en spoilboard; secondelijm verbindt uitsluitend de twee taperuggen. Daardoor komt geen CA op het onderdeel en ontstaat een stijvere verbinding dan met zacht schuimtape. Bedek een groot deel van het oppervlak, druk overal stevig aan en laat de lijm volledig uitharden. Dunne dubbelzijdige CNC-tape kan ongeveer 0,127 mm dik zijn; die laag verandert het werkelijke Z-niveau en kan bij kleine onderdelen elastisch veren. Gebruik tape-en-lijm niet op stoffige MDF-oppervlakken, poreuze onderzijden of onderdelen met grote hefboomkrachten zonder een proefsnede. citeturn3search0turn9search6  
SOURCE: https://community.carbide3d.com/t/masking-tape-super-glue-to-hold-the-workpiece/1671  
CONFIDENCE: COMMON

### Wanneer werkt vacuümopspanning goed, en wanneer plotseling niet meer?

Vacuümkracht is drukverschil maal afgesloten oppervlak. Een effectief drukverschil van 50 kPa op 100 × 100 mm levert theoretisch 500 N neerwaartse kracht; bij een onderdeel van 20 × 20 mm resteert slechts 20 N. Vacuüm werkt daarom uitstekend voor grote, vlakke platen maar slecht voor kleine delen, poreus MDF, krom materiaal en werkstukken die tijdens het uitsnijden veel afdichtingsoppervlak verliezen. Maskeer ongebruikte zones en plan interne gaten vóór de buitencontour. ShopBot adviseert vacuüm waar nodig aan te vullen met schroeven, tabs of kunststof nagels, vooral voor kleine delen die kunnen losbreken. citeturn3search2turn3search6  
SOURCE: https://shopbottools.com/wp-content/uploads/2024/01/holdingdown.pdf  
CONFIDENCE: SOLID

### Waarom veroorzaakt werkholding zoveel plotselinge mislukkingen?

CAM veronderstelt dat het materiaal onbeweeglijk blijft. Schuift een werkstuk 0,5 mm, dan verandert niet alleen de maat: de frees kan ineens 0,5 mm extra materiaal aangrijpen, een wand opnieuw raken of een los onderdeel tussen frees en stock klemmen. Een omhoogkomende plaat verandert bovendien de werkelijke snedediepte. Waarschuwingssignalen zijn veranderend geluid tijdens identieke banen, trillende afvaldelen, spanen onder het werkstuk en een snijlijn die niet op eerdere lagen ligt. Test vóór de start met handkracht in X, Y en Z; niets mag voelbaar bewegen. Controleer de opspanning opnieuw voordat de buitencontour begint. citeturn1search0turn3search5  
SOURCE: https://www.acrylite.co/resources/knowledge-base/article/what-is-the-proper-method-to-use-when-routing-acrylic-sheet  
CONFIDENCE: SOLID

## E — Fusion CAM

### Welke Fusion-toolpaths zijn voor praktisch routerwerk werkelijk belangrijk?

Gebruik **Face** om de bovenzijde vlak te maken; **2D Pocket** voor eenvoudige vlakke uitsparingen; **2D Adaptive** voor gelijkmatig voorfrezen met beperkte radiale aangrijping; **2D Contour** voor binnen- en buitenprofielen; **Drill/Bore** voor gaten; en **Trace of Engrave** voor lijnen en V-carving. Voor 3D-werk volstaan aanvankelijk **Adaptive** voor ruwen en **Parallel, Scallop of Contour** voor afwerken. Een gewone gesloten pocket is soms korter en eenvoudiger dan Adaptive; Adaptive is vooral waardevol wanneer volle sleuven en abrupte binnenhoekbelasting vermeden moeten worden. Programmeer aparte ruwe en afwerkbewerkingen, bijvoorbeeld 0,2–0,5 mm radiale restvoorraad vóór de finishpassage. citeturn0search0turn0search4turn0search11  
SOURCE: https://help.autodesk.com/view/fusion360/ENU/?contextId=MFG-REF-3D-ADAPTIVE-CMD  
CONFIDENCE: SOLID

### Hoe stel je stock en nulpunt zo in dat het op de machine reproduceerbaar is?

Het Fusion-WCS moet exact overeenkomen met het fysieke werkstuknulpunt. Voor plaatwerk is een bovenhoek van de stock vaak praktisch: X en Y zijn tegen aanslagen te vinden en Z wordt op het bovenvlak gemeten. Bodem-Z is nuttig wanneer plaatdikte varieert maar vereist een betrouwbaar spoilboardniveau. Voer de werkelijk gemeten stockdikte in, niet alleen de nominale 18 mm. Modelleer ook extra materiaal, klemranden en een eventuele ondersnijding van bijvoorbeeld 0,2 mm in het spoilboard. Controleer visueel dat de blauwe Z-as van het werkstuk af wijst; een omgekeerde Z-as kan de eerste beweging rechtstreeks de tafel in sturen. citeturn4search0turn4search4  
SOURCE: https://help.autodesk.com/view/fusion360/ENU/?contextId=MFG-SETUP-2ND-SIDE  
CONFIDENCE: SOLID

### Welke hoogte- en insteekfouten breken de meeste frezen?

Controleer *Top Height*, *Bottom Height*, *Retract Height* en *Clearance Height* afzonderlijk. Een verkeerde selectie kan een contour 5 mm dieper maken dan bedoeld of rapids door een klem sturen. Vermijd rechtstandig plungeren met een standaard frees, vooral in aluminium en diepe houtpockets; gebruik een helicale of schuine ramp. Voor non-ferrometaal noemt Harvey voor bepaalde gereedschappen ramping rond 3–10°, terwijl een directe plunge een sterke voedingsreductie vereist. Controleer dat de snijlengte langer is dan de maximale diepte, maar laat de frees niet onnodig ver uit de collet steken: tweemaal zoveel uitsteek geeft veel meer doorbuiging en trillingsgevoeligheid. citeturn0search10turn10search3  
SOURCE: https://www.harveyperformance.com/in-the-loupe/category/machining-101/  
CONFIDENCE: SOLID

### Wat moet je in de simulatie bekijken behalve het eindresultaat?

Simuleer vanaf de gedefinieerde stock, met houder en fixtures zichtbaar. Bekijk de eerste insteek, alle rapids, de diepste laag, binnenhoeken, toolchanges en de uiteindelijke contour. Zet botsings- en gougedetectie aan en controleer of achtergebleven materiaal overeenkomt met de bedoeling. Simulatie toont programmeerfouten, maar niet automatisch een losse klem, werkelijke spindelrun-out, doorbuiging of een verkeerd ingesteld machinenulpunt. Fusion ondersteunt afzonderlijke collision-clearances voor schacht en houder; dat is belangrijk bij diepe pockets waar de snijkant vrijloopt maar de dikkere schacht of colletmoer niet. citeturn4search1turn4search5  
SOURCE: https://help.autodesk.com/view/fusion360/ENU/?contextId=MFG-REF-SIMULATION  
CONFIDENCE: SOLID

### Waarom is de juiste postprocessor net zo belangrijk als de toolpath?

De postprocessor vertaalt Fusion-bewegingen naar de exacte G-code, eenheden, boogcommando’s, spindlecodes, offsets en toolchange-logica van jouw besturing. Kies een post voor de werkelijke controller, bijvoorbeeld GRBL, Mach3/4, LinuxCNC of een machinespecifieke variant; “generic” betekent niet universeel. Controleer vóór productie minimaal millimeters versus inches, G54/WCS, spindel aan/uit, veilige startpositie, booguitvoer en gedrag bij toolwissels. Een verkeerd postbestand kan een geometrisch perfecte simulatie alsnog omzetten in onveilige machinebewegingen. Bewaar een geteste post in een persoonlijke of cloudbibliotheek en wijzig niet vlak vóór een belangrijk onderdeel meerdere postinstellingen tegelijk. citeturn4search2turn4search6turn4search11  
SOURCE: https://help.autodesk.com/view/fusion360/ENU/?contextId=MFG-REF-NC-OLD-V-NEW  
CONFIDENCE: SOLID

### Welke Fusion-fouten eindigen specifiek in een gebroken frees?

De gevaarlijkste combinaties zijn: verkeerde freesdiameter of aantal snijkanten in de tool library; feed per tand verwarren met totale voeding; stock dunner modelleren dan werkelijk; vergeten tabs; volledige sleuf met parameters voor adaptief zijfrezen; verkeerde bottom height; en een rechte plunge in materiaal. Controleer ook *stock to leave*: 0,5 mm axiaal laten staan kan gewenst zijn, maar −0,5 mm betekent extra diep snijden. Fusion waarschuwt bovendien dat *Shortest path* bij controllers met niet-lineaire “dogleg” G0-bewegingen botsingen kan veroorzaken die de softwaresimulatie niet juist weergeeft. Proefloop nieuwe code eerst boven het materiaal of met sterk verlaagde rapid override. citeturn0search8turn4search2  
SOURCE: https://help.autodesk.com/view/fusion360/ENU/?contextId=MFG-REF-3D-POCKET-CMD  
CONFIDENCE: SOLID

## Mythen en verouderd advies

### Is “verlaag de voeding als het spannend klinkt” goed advies?

Niet zonder diagnose. Bij een hoog jankend geluid, stof of smeltende kunststof kan een lagere voeding de spaandikte verder verkleinen en de warmte juist verhogen. Verlaag bij echte mechanische overbelasting eerst snedediepte of stepover; zo behoud je een snijdende spaandikte. Verlaag voeding alleen wanneer de spanen aantoonbaar te dik zijn, de spindle vertraagt of de machine stappen verliest. citeturn0search2turn1search0  
SOURCE: https://www.harveyperformance.com/in-the-loupe/speeds-and-feeds-101/  
CONFIDENCE: SOLID

### Is maximaal toerental altijd het veiligst voor een kleine frees?

Nee. Meer rpm is alleen nuttig wanneer de voeding evenredig kan stijgen. Anders wrijft iedere snijkant met een te dunne spaan, waardoor acryl smelt, hout verbrandt en aluminium aan de frees last. Verhoog je rpm met 25%, verhoog dan voor dezelfde spaandikte ook de voeding met 25%. citeturn0search2turn1search3  
SOURCE: https://www.acrylite.co/files/content/acrylite.co/documents/fabrication-briefs/Extruded-Fabrication-Routing-Technical-Information.pdf  
CONFIDENCE: SOLID

### Moet de snedediepte altijd maximaal de helft van de freesdiameter zijn?

Nee. Er bestaat geen universele verhouding. Toelaatbare diepte hangt af van radiale aangrijping, materiaal, gereedschapsgeometrie, uitsteek, machinekracht en stijfheid. Een adaptieve baan met 10% stepover kan dieper zijn dan een volle sleuf; een 100% sleuf moet vaak juist ondiep. Industriële adviezen van 1–3×D mogen niet rechtstreeks naar een hobbyrouter worden gekopieerd. citeturn0search2turn6view3  
SOURCE: https://onsrud.com/Forms/Cutting-Data-Recommendations.asp  
CONFIDENCE: SOLID

### Geven meer snijkanten altijd een mooiere én snellere snede?

Alleen als machine en spaanafvoer de vereiste voeding aankunnen. Bij 18.000 rpm en 0,05 mm/tand vraagt één snijkant 900 mm/min, maar vier snijkanten 3.600 mm/min. Kan de hobbyrouter dat niet, dan wrijven de vier kanten. Voor acryl en aluminium zijn één of twee snijkanten daarom vaak betrouwbaarder dan drie of vier. citeturn1search2turn1search7  
SOURCE: https://shop.datron.com/cnc-cutting-tool-selection-guide/  
CONFIDENCE: SOLID

### Is een compressiefrees altijd de beste frees voor multiplex?

Nee. Compressie werkt alleen als de snedediepte voorbij het onderste up-cut gedeelte komt. Bij een ondiepe eerste passage gedraagt de frees zich als een up-cut en kan de zichtzijde juist splinteren. Een lichte machine die geen diepe eerste pass kan maken, krijgt vaak een beter resultaat met down-cut voor bovenafwerking en up-cut voor diepere spaanafvoer. citeturn2search2  
SOURCE: https://toolstoday.com/learn/downcut-upcut-and-compression-bits  
CONFIDENCE: SOLID

### Bewijst een foutloze Fusion-simulatie dat de echte snede veilig is?

Nee. De simulatie kent alleen het ingevoerde model. Zij weet niet dat de stock 0,8 mm dikker is, een klem verkeerd staat, de Z-probe fout is, de frees uit de collet glijdt of het werkstuk beweegt. Simulatie is noodzakelijk voor toolpathvalidatie, maar moet worden gevolgd door fysieke nulcontrole, opspancontrole en bij nieuwe code een veilige proefloop. citeturn4search0turn4search1  
SOURCE: https://help.autodesk.com/view/fusion360/ENU/?contextId=MFG-REF-SIMULATION  
CONFIDENCE: SOLID

### Kan aluminium alleen op een zware industriële freesbank worden bewerkt?

Nee. Goed verspaanbaar aluminium is realistisch op een stijve hobbyrouter wanneer je hoge rpm combineert met een single-flute, beperkte aangrijping en effectieve spaanafvoer. Wat niet overdraagbaar is, zijn industriële dieptes en voedingen voor machines met veel hogere massa, spindlepower en houderstijfheid. Een hobbyrouter moet ondieper snijden, maar niet zo langzaam voeren dat hij gaat wrijven. citeturn6view3turn10search4turn10search10  
SOURCE: https://community.carbide3d.com/t/can-we-use-shapeoko-pro-for-aluminum-milling/58868  
CONFIDENCE: COMMON

### Zijn tabs overbodig wanneer het werkstuk met vacuüm of tape vastzit?

Niet automatisch. Tijdens de buitencontour wordt het effectieve vacuümoppervlak steeds kleiner en kan tape door snijkracht of warmte loslaten. Een losgekomen onderdeel kan draaien, tegen de frees klemmen en zowel werkstuk als frees vernietigen. Gebruik tabs of een *onion skin* van bijvoorbeeld 0,2–0,5 mm wanneer de resterende houdkracht niet aantoonbaar ruim voldoende is. citeturn3search2turn3search6  
SOURCE: https://shopbottools.com/products/holddown/  
CONFIDENCE: COMMON