<!-- RAW RESEARCH — do not edit. Rewrite into Dutch cards in site/kennis.html instead. -->
> **Topic:** bambu-printen · **Tool:** ChatGPT deep research · **Received:** 2026-08-07
> **Source:** the owner's Drive folder <https://drive.google.com/drive/folders/1Vg9HJxbKaBuv31Ovm4uSlIIMFyi7Yun3>
> **Known artifact:** every card carries an inline `cite…turn…` marker wrapped in invisible private-use characters (U+E201/U+E202). STRIP BOTH before any text reaches the site.
> Saved unedited, per `research/deep-research-prompts.md` § After the research comes back.

---

# Referentiedossier: maximaal rendement uit de Bambu Lab A1 mini en A1 met AMS Lite

## A. Wat de A1 zelf kalibreert — en wat werkelijk aan de gebruiker blijft

**Wat kalibreert de A1-serie vóór iedere normale printopdracht?**

De standaardstartprocedure bepaalt automatisch de Z-offset, maakt een hoogtekaart van het bed, controleert de resonanties van X en Y en kalibreert de flow dynamics — Bambu’s term voor druk-/vooruitregeling tijdens accelereren en vertragen. De A1 gebruikt daarvoor onder meer accelerometers en een kracht-/druksensor rond de hotend, technisch uitgevoerd met een eddy-current-meetsysteem. Er wordt geen optische LiDAR-scan van een kalibratielijn gemaakt. Laat in Bambu Studio daarom normaal zowel **Bed leveling** als **Flow dynamics calibration** ingeschakeld; handmatige papierproeven of K-factor-torens voegen niets toe aan deze standaardworkflow. citeturn4search12turn0search1turn0search2

SOURCE: https://bambulab.com/en-eu/a1  
CONFIDENCE: SOLID

**Welke instellingen beslist de printer juist níét automatisch?**

De A1 kiest niet zelfstandig het juiste plaat-, nozzle- of filamentprofiel, de materiaaltemperaturen, maximale volumestroom, flow ratio, wanddikte, infill, ondersteuning, naadpositie of oriëntatie. Hij weet evenmin of een rol nat is, een spoel klemt, een model mechanisch verkeerd is ontworpen of een PEI-plaat vettig is. Automatische flow dynamics corrigeert de tijdsafhankelijke drukrespons; het is geen universele compensatie voor een foutieve filamentdiameter, versleten nozzle of te hoge ingestelde volumestroom. Controleer daarom vóór het slicen vooral printerprofiel, plaat, nozzlediameter en filamentpreset. citeturn0search1turn0search5turn2search12

SOURCE: https://wiki.bambulab.com/en/software/bambu-studio/calibration_pa  
CONFIDENCE: SOLID

**Kalibreert flow dynamics ook de flow ratio en maximale volumestroom?**

Nee. Flow dynamics bepaalt de drukcompensatie die nodig is bij snelheidswisselingen. **Flow rate/flow ratio** bepaalt hoeveel kunststof een nominale extrusielijn werkelijk krijgt; **maximum volumetric speed** begrenst hoeveel mm³/s het filament-hotendsysteem kan smelten. Bij Bambu-filament zijn de fabrieksprofielen doorgaans voldoende. Bij onbekend derde-partijfilament kan een flow-ratio-test zinvol zijn wanneer wanden structureel te dik, te dun of slecht gesloten zijn. Verlaag maximale volumestroom wanneer onderextrusie alleen bij snelle segmenten optreedt. Dat is materiaalprofilering, geen handmatige pressure-advance-tuning. citeturn0search1turn0search5turn10search0

SOURCE: https://wiki.bambulab.com/en/software/bambu-studio/calibration_flow_rate  
CONFIDENCE: SOLID

**Wanneer is een volledige systeemkalibratie toch zinvol?**

Voer via het scherm een volledige kalibratie uit na verplaatsing van de printer, opnieuw opspannen van riemen, vervanging van motoren, hotend-heater of andere relevante toolhead-onderdelen, en wanneer de printer zelf een resonantie- of levelafwijking meldt. Na alleen een normale nozzlewissel volstaat meestal de automatische printstart, mits de nozzle correct vergrendeld is en de juiste diameter in printer én Studio staat. Bambu schrijft na diverse mechanische onderhoudshandelingen expliciet een volledige kalibratie voor; dit is een herstel- of onderhoudsstap, niet een avondritueel voor iedere rol filament. citeturn4search17turn4search20turn4search29

SOURCE: https://wiki.bambulab.com/en/general/printer-calibration  
CONFIDENCE: SOLID

**Kan automatische bednivellering een mechanisch fout bed wegregelen?**

Alleen binnen het normale compensatiebereik. De hoogtekaart compenseert kleine vlakheids- en uitlijnverschillen tijdens het printen, maar verwijdert geen vuil onder de flexplaat, loszittende bedscharnierschroeven, een verkeerd geplaatste plaat of ernstige mechanische scheefstand. Handmatig bed-trammen is pas relevant wanneer officiële diagnostiek of terugkerende HMS-fouten daarop wijzen. Controleer eerst of de plaat vlak op de magneten ligt, niets onder de plaat zit en de nozzle schoon is: opgedroogd filament aan de punt kan de krachtmeting tijdens homing en leveling vervalsen. citeturn4search4turn4search16turn7search7

SOURCE: https://wiki.bambulab.com/en/a1/troubleshooting/homing-leveling-failure  
CONFIDENCE: SOLID

## B. Filament — PLA, PETG, TPU en PLA-CF op de A1

**Wat verandert er praktisch bij PLA?**

PLA is het referentiemateriaal voor de open A1-serie: veel Bambu-varianten printen rond **190–230 °C** nozzle en **35–65 °C** bed, afhankelijk van PLA-type en plaat. Gebruik eerst het specifieke fabrikantprofiel; Generic PLA is het veilige vertrekpunt voor onbekende merken. Gewoon PLA werkt in AMS Lite en heeft geen geharde nozzle nodig. Droog pas systematisch bij breekbaarheid, plopjes, een ruwe schuimende extrusie of onverklaarbare stringing; Bambu noemt voor PLA Basic **50 °C gedurende 8 uur** in een geforceerde droger. Bewaar geopende rollen luchtdicht met droogmiddel. citeturn1search2turn19search0turn5search17

SOURCE: https://eu.store.bambulab.com/products/pla-basic-filament  
CONFIDENCE: SOLID

**Wat vraagt PETG anders dan PLA?**

PETG vraagt meer warmte, minder agressieve koeling en vooral aandacht voor vocht. Bambu PETG HF specificeert **230–260 °C** nozzle, **65–75 °C** bed en drogen op **65 °C gedurende 8 uur**. Een natte rol geeft belletjes, matte of ruwe oppervlakken, stringing en zwakkere lagen; extra retractie maskeert dat niet. Gebruik de PETG-preset in plaats van een PLA-profiel en controleer de ingestelde plaatsoort. PETG werkt normaal in AMS Lite en met de standaard roestvaststalen nozzle. Laat het bed afkoelen voordat het onderdeel wordt losgenomen; heet PETG kan zeer sterk aan PEI hechten. citeturn13search0turn5search1turn13search2

SOURCE: https://eu.store.bambulab.com/products/petg-hf  
CONFIDENCE: SOLID

**Hoe print je gewone TPU 95A op een A1?**

Voer gewone TPU 95A vanaf de externe spoel in, via een zo kort en soepel mogelijk PTFE-traject. De direct-drive-extruder van de A1 kan flexibel materiaal goed trekken, maar AMS Lite moet filament laden, terugtrekken en door meerdere buizen geleiden; zacht TPU kan daarbij knikken of uitrekken. Begin met het juiste TPU-profiel, lage volumestroom en minimale onnodige retracties. TPU is sterk hygroscopisch: droog vóór kritisch werk en print bij voorkeur vanuit een droge box. Bij oozing verlaagt Bambu de nozzletemperatuur als eerste stap met ongeveer **5 °C**, niet de Z-offset. citeturn1search1turn0search10turn12search3

SOURCE: https://wiki.bambulab.com/en/knowledge-sharing/tpu-printing-guide  
CONFIDENCE: SOLID

**Kan er dan helemaal geen TPU door AMS Lite?**

Alleen specifiek daarvoor samengesteld, relatief hard TPU. **Bambu TPU for AMS** is **68D**, veel stijver dan 95A, en wordt officieel ondersteund in AMS Lite. De fabrikant specificeert **220–240 °C** nozzle, **30–35 °C** bed en drogen op **70 °C gedurende 8 uur**. Behandel “TPU for AMS” daarom als een aparte materiaalcategorie: geschikt voor taaie, enigszins buigzame clips en beschermdelen, maar geen vervanger voor zacht 95A bij afdichtingen, flexibele voeten of sterk vervormbare delen. Leid uit het woord TPU op een willekeurige derde-partijrol nooit automatisch AMS-compatibiliteit af. citeturn11search0turn12search1turn5search2

SOURCE: https://eu.store.bambulab.com/products/tpu-for-ams  
CONFIDENCE: SOLID

**Wat vraagt PLA-CF van nozzle en AMS Lite?**

De A1 en A1 mini worden standaard met een **0,4 mm roestvaststalen nozzle** geleverd. Voor langdurig PLA-CF-gebruik is een **0,4 of 0,6 mm gehardstalen nozzle** de verstandige keuze; deeltjesgevulde filamenten slijten zacht staal en de **0,2 mm** nozzle verstopt gemakkelijker. Bambu PLA-CF gebruikt **210–240 °C**, een bed van **35–45 °C** en drogen op ongeveer **50–55 °C gedurende 8 uur**. Bambu’s eigen relatief gladde PLA-CF is officieel AMS-Lite-compatibel, maar ruwe derde-partij-CF kan feeders en PTFE sneller uitslijten. Inspecteer het traject regelmatig. citeturn14search6turn15view0turn8search2

SOURCE: https://store.bblcdn.eu/s8/default/aefa8303ad8d40248b0d86dfdad46518/Bambu_PLA-CF_Technical_Data_Sheet_V3.pdf  
CONFIDENCE: SOLID

**Wanneer moet een rol daadwerkelijk de droger in?**

Droog onmiddellijk bij hoorbare plopjes, dampbelletjes, schuimige extrusie, plotselinge stringing of broos filament. Voor voorspelbaar functioneel werk is preventief drogen verstandig bij PETG, TPU en PLA-CF: respectievelijk ongeveer **65 °C/8 uur**, **70 °C/8 uur** en **50–55 °C/8 uur** volgens Bambu’s huidige materiaaladviezen. PLA Basic kan op **50 °C/8 uur**, maar hoeft niet na iedere korte blootstelling gedroogd te worden. AMS Lite is geen droger of afgesloten opslagkamer. Meet liefst de lucht in de opslagbox en mik voor gevoelig materiaal op minder dan circa **20% RV**. citeturn1search0turn5search3turn19search2

SOURCE: https://wiki.bambulab.com/en/filament-acc/filament/dry-filament  
CONFIDENCE: SOLID

## C. AMS Lite in de praktijk

**Hoeveel filament kost één kleurwissel?**

Er bestaat geen vast gewicht: Bambu Studio berekent een matrixwaarde voor iedere overgang. Donker naar licht vraagt meer spoeling dan licht naar donker. Recente Studio-versies hanteren grofweg **63–900 mm³** als normale matrixorde; bij PLA met circa **1,24 g/cm³** is dat ongeveer **0,08–1,12 gram** kunststof per overgang. Daar kunnen prime-towermateriaal, laad-/snijresten en de startpurge nog bijkomen. Gebruik na slicen de Preview-verdeling voor **model**, **flushed filament** en **prime tower** als waarheid voor die specifieke plaat. Verlaag nooit blind alle overgangen even sterk: zwart-naar-wit is kritischer dan wit-naar-zwart. citeturn2search0turn10search2turn10search6

SOURCE: https://wiki.bambulab.com/en/software/bambu-studio/reduce-wasting-during-filament-change  
CONFIDENCE: COMMON

**Hoe ontwerp je een model zodat AMS Lite veel minder hoeft te wisselen?**

Ontwerp kleuren zoveel mogelijk per Z-zone: een kleurwissel op laag **40** en terug op laag **60** kost twee wissels; twee kleuren die in iedere laag voorkomen kunnen honderden wissels veroorzaken. Een logo dat over **300 lagen** naast de basiskleur loopt, kan rekenkundig tot ongeveer **600 overgangen** veroorzaken. Maak letters daarom als verhoogde of verzonken topdetails, gebruik losse klik- of persinserts, of splits een Fusion-assemblage in onderdelen die afzonderlijk worden geprint. Kleur per object of per hoogte is vrijwel altijd efficiënter dan kleine, doorlopende kleurvlakken in elke laag. citeturn2search15turn10search12

SOURCE: https://wiki.bambulab.com/en/software/bambu-studio/multi-color-printing  
CONFIDENCE: SOLID

**Wanneer zijn ‘Flush into infill’ en ‘Flush into supports’ verstandig?**

Gebruik ze wanneer de purgekleur intern onzichtbaar mag blijven. **Flush into infill** vervangt een deel van normaal infillmateriaal; **Flush into supports** stopt het in wegwerpsteun. Dit vermindert afval, maar niet iedere wissel kan volledig intern worden verwerkt. Vermijd infill-flushing bij witte, dunwandige of doorschijnende delen: donker materiaal kan door **2–3 wanden** zichtbaar worden. Meng evenmin achteloos verschillende materiaaltypen in een belast onderdeel; rest-PETG in PLA of andersom kan lokale hechting beïnvloeden. Controleer de kleur- en featureweergave in Preview en behoud voldoende externe wanden. citeturn2search0turn2search2turn10search1

SOURCE: https://wiki.bambulab.com/en/bambu-studio/color-mixing  
CONFIDENCE: SOLID

**Waarvoor dient de prime tower werkelijk?**

De prime tower stabiliseert de nozzleflow na laden, terugtrekken en spoelen; hij is niet hetzelfde als de kleurpurge. De purge verwijdert het oude materiaal uit de smeltzone, terwijl de tower een consistente druk en lijnstart helpt herstellen voordat het zichtbare model verdergaat. Een kleinere tower bespaart dus niet automatisch evenveel als het verkleinen van de flushing matrix. Bij modellen met kleine gekleurde eilandjes of veel korte segmenten is de tower juist waardevol tegen ontbrekende lijnstarts. Controleer na slicen afzonderlijk hoeveel materiaal aan **flushing** en hoeveel aan **prime tower** wordt toegerekend. citeturn2search3turn10search9

SOURCE: https://wiki.bambulab.com/en/software/bambu-studio/parameter/prime-tower  
CONFIDENCE: SOLID

**Wat zijn de meest voorkomende mechanische AMS-Lite-storingen?**

Controleer in deze volgorde: een gekruiste winding op de rol; een spoel die niet vrij draait; verkeerde spoelmaat; te scherpe PTFE-bochten; een buis die niet volledig in de koppeling zit; daarna pas feeder, cutter en extruder. AMS Lite ondersteunt rollen van **40–68 mm breed** met een kerngat van **53–58 mm**. Een te ver weg geplaatste unit of een geforceerd korte bocht verhoogt de weerstand. Bij laadproblemen haalt u het filament uit het volledige traject en test u elk deel afzonderlijk; blijf niet twintigmaal automatisch herladen, want een ingesleten of afgeplatte filamentplek wordt alleen slechter. citeturn8search0turn1search17turn7search1

SOURCE: https://wiki.bambulab.com/en/ams-lite/troubleshooting/amslite-loading-unloading-failure  
CONFIDENCE: SOLID

**Wanneer is meerkleurendruk de verspilling eenvoudig niet waard?**

Gebruik als praktische grens de geslicede statistiek. Wanneer **flushed filament plus prime tower** ongeveer even zwaar wordt als het model, of de printtijd meer dan circa **drie keer** die van de enkelkleurige versie wordt, is een losse insert, verf, vinyl of tweedelige constructie meestal rationeler. Muurplaatjes en vlakke tekst kunnen efficiënt zijn wanneer kleuren slechts enkele Z-overgangen vragen; miniaturen met vier kleuren in vrijwel iedere laag zijn het ongunstige uiterste. Ook een kleine mislukking laat dan uren aan kleurwissels en purge verloren gaan. De drempel is economisch, niet technisch. citeturn10search9turn10search12

SOURCE: https://wiki.bambulab.com/en/software/bambu-studio/view-slicing-information  
CONFIDENCE: COMMON

## D. Instellingen die nog steeds het verschil maken

**Moet sterkte vooral uit meer wanden of meer infill komen?**

Vergroot voor trek en buiging eerst het aantal wandlussen. Een bruikbaar functioneel vertrekpunt met een **0,4 mm** nozzle is **3–5 wall loops** en **15–25%** gyroid of cubic infill. Bambu noemt voor zwaarder belaste constructiedelen expliciet ongeveer **5 wanden en 25% infill**. Infill ondersteunt topvlakken en helpt bij drukbelasting, maar **100% infill** is zelden de efficiëntste route naar sterkte en kan krimp en printtijd vergroten. Voeg rond boutgaten, lagerzittingen en heat-set inserts lokale modifiers met extra wanden of massief materiaal toe in plaats van het volledige onderdeel te vullen. citeturn17search6turn17search12turn17search16

SOURCE: https://wiki.bambulab.com/en/knowledge-sharing/printed-model-warping  
CONFIDENCE: SOLID

**Hoe stel je supports doelgericht in?**

Gebruik supports alleen waar geometrie of oppervlak dit vereist. Bambu Studio’s standaard threshold angle is **30°**, gemeten volgens Studio’s eigen definitie; verhoog of verlaag die pas na controle in Preview. Kies tree support voor organische of verspreide contactpunten en normal support voor brede vlakke overhangen. Gebruik support painting om montagevlakken te ondersteunen en cosmetische vlakken vrij te houden. De belangrijkste kwaliteitsvariabelen zijn top-Z-afstand, interface-lagen en interface-spacing: een kleinere afstand en dichtere interface verbeteren de onderzijde, maar maken verwijderen moeilijker. Ontwerp waar mogelijk **45°-afschuiningen**, druppelvormige gaten of een los te breken offerlaag. citeturn6search3turn6search7

SOURCE: https://wiki.bambulab.com/en/software/bambu-studio/support  
CONFIDENCE: SOLID

**Waar moet de Z-naad staan op een functioneel onderdeel?**

Kies bewust tussen **Nearest, Aligned, Back** en **Random**. Plaats een aligned of back seam op een niet-zichtbare, laagbelaste rand; dan ontstaat één voorspelbare lijn die zo nodig kan worden nabewerkt. Random verdeelt kleine start-stopmarkeringen, maar kan het hele oppervlak onrustig maken. Vermijd een naad in een afdichtingsvlak, glijlagerpassing, snap-fit-scharnier of dunne trekzone: de overgang tussen einde en begin van een wand is geometrisch nooit volledig onzichtbaar. Draai het model of schilder de seam in Studio; probeer hem niet op te lossen met een handmatig ingestelde Z-offset. citeturn6search0turn6search4

SOURCE: https://wiki.bambulab.com/en/software/bambu-studio/Seam  
CONFIDENCE: SOLID

**Hoe belangrijk is onderdeeloriëntatie nog op een automatisch gekalibreerde printer?**

Oriëntatie blijft vaak belangrijker dan een klein slicerverschil. Leg de hoofdtrek- en buigspanning zoveel mogelijk in het XY-vlak, zodat de kracht door doorlopende extrusies loopt in plaats van door laaggrenzen. Bambu’s PLA-CF-data tonen bijvoorbeeld circa **38 MPa treksterkte in XY** tegenover **26 MPa in Z**, en **89 MPa buigsterkte in XY** tegenover **49 MPa in Z**. Geef pennen, haken en klemarmen daarom een laagverloop dat niet loodrecht op de belasting staat. Splits een onderdeel wanneer één oriëntatie anders een sterke arm én nauwkeurige passing onmogelijk maakt. citeturn16view0

SOURCE: https://store.bblcdn.eu/s8/default/aefa8303ad8d40248b0d86dfdad46518/Bambu_PLA-CF_Technical_Data_Sheet_V3.pdf  
CONFIDENCE: SOLID

**Wanneer gebruik je variabele laaghoogte of een andere nozzle?**

Een **0,4 mm** nozzle is de universele keuze; Bambu Studio laat daarbij typisch ongeveer **0,08–0,28 mm** variabele laaghoogte toe. Gebruik dunne lagen alleen op hellingen, schroefdraad en zichtdetails, en grovere lagen op rechte wanden. Een **0,6 mm** nozzle is aantrekkelijk voor grote functionele delen en vezelgevulde materialen: bredere lijnen leveren sneller dikke wanden en verminderen verstoppingsrisico. Een **0,2 mm** nozzle is voor kleine tekst en details, maar niet voor abrasieve CF-, glow- of grof gevulde filamenten. De printer kalibreert zijn beweging, maar kan de fysieke resolutie en doorlaat van de gekozen nozzle niet veranderen. citeturn6search10turn14search13turn14search35

SOURCE: https://wiki.bambulab.com/en/software/bambu-studio/adaptive-layer-height  
CONFIDENCE: SOLID

## E. Fouten diagnosticeren op een zelfkalibrerende printer

**Wat controleer je eerst wanneer de eerste laag niet hecht?**

Begin niet met Z-offset. Controleer eerst de vier waarschijnlijkste oorzaken: juiste plaat geselecteerd in Studio, flexplaat correct geplaatst, oppervlak vetvrij en nozzle schoon vóór probing. Was textured PEI met warm water, afwasmiddel en een vetvrije spons; alcohol alleen verwijdert niet altijd huidvet en additiefresidu. Raak het printgebied daarna niet aan. Controleer vervolgens bedtemperatuur, brim en tocht. Laat pas daarna opnieuw bed leveling lopen. Een verkeerde plaatselectie kan tientallen graden verschil in de bedoelde bedtemperatuur veroorzaken en is daarmee veel waarschijnlijker dan een structureel fout berekende Z-offset. citeturn18search0turn18search15turn7search0

SOURCE: https://wiki.bambulab.com/en/filament-acc/acc/pei-plate-clean-guide  
CONFIDENCE: SOLID

**Wat is de juiste volgorde bij onderextrusie?**

Bepaal eerst of de fout snelheidsafhankelijk is. Print langzaam goed maar snel slecht, verlaag dan de maximale volumestroom of gebruik een warmer, correct filamentprofiel. Is de extrusie altijd zwak, controleer vocht, filamentdiameter, spoelweerstand en PTFE-traject. Extrudeer daarna handmatig bij de normale materiaaltemperatuur. Komt er weinig of schuin materiaal uit, onderzoek de hotend op een gedeeltelijke verstopping; slipt of tikt de extruder, inspecteer tandwielen en een afgeplatte filamentplek. Demonteer de extruder pas nadat rol, traject en nozzle afzonderlijk zijn uitgesloten. citeturn7search3turn7search2turn7search5

SOURCE: https://wiki.bambulab.com/en/a1-mini/troubleshooting/how-to-check-which-part-is-clogged  
CONFIDENCE: SOLID

**Wat doe je bij een AMS-melding ‘tangled or stuck’?**

Stop en trek niet onmiddellijk hard aan de rol. Controleer eerst op een gekruiste winding en of de spoel zonder zijdelingse klem draait. Maak daarna het PTFE-traject recht en test laden met de buis losgekoppeld aan het volgende knooppunt. Zo lokaliseer je of de weerstand in spoelhouder, AMS-feeder, PTFE, filamenthub, extruder of hotend zit. Knip een ingesleten filamentstuk minstens enkele centimeters terug voordat je opnieuw laadt. Controleer bij terugkerende problemen ook de officiële spoelmaten **40–68 mm breed** en **53–58 mm kerndiameter**; adapters die excentrisch lopen kunnen valse tangle-detectie veroorzaken. citeturn7search6turn7search1turn8search0

SOURCE: https://wiki.bambulab.com/en/a1-mini/troubleshooting/hmscode/1200_8000_0002_0001  
CONFIDENCE: SOLID

**Wat controleer je bij warping of een model dat halverwege loskomt?**

Behandel het eerst als hechtings- en spanningsprobleem, niet als levelingprobleem. Reinig de plaat, verifieer de plaatsoort en verhoog zo nodig contactoppervlak met een brim of in CAD ontworpen tabs. Controleer bedtemperatuur en voorkom koude luchtstromen over grote PETG- of PLA-CF-delen. Verlaag sterke interne spanningen door minder massieve infill, meer gelijkmatige wanddiktes en afgeronde hoeken; Bambu adviseert voor constructiedelen rond **5 wanden en 25% infill** in plaats van kritiekloos 100%. Bij hoge, smalle onderdelen verlaagt een bredere voet vaak meer risico dan extra bedtemperatuur. citeturn18search15turn6search6turn18search5

SOURCE: https://wiki.bambulab.com/en/knowledge-sharing/printed-model-warping  
CONFIDENCE: SOLID

**Wat veroorzaakt layer shifts op een A1 meestal werkelijk?**

Zoek eerst naar een fysieke botsing: omgekrulde overhang, opgehoopte purge, losgekomen support, vervormd onderdeel of kabel/PTFE die beweging hindert. Controleer daarna of bed en toolhead met uitgeschakelde motoren soepel bewegen en of er vuil op rails of rond poelies zit. Pas daarna zijn riemspanning en motorproblemen aan de beurt. Na riemonderhoud schrijft Bambu een nieuwe vibration-compensation-kalibratie voor. Verminder eventueel gyroid-kruisingen, overhangkrul of agressieve travel over het model; een layer shift is zelden te genezen door flow dynamics of Z-offset opnieuw te tunen. citeturn4search17turn4search10turn18search13

SOURCE: https://wiki.bambulab.com/en/a1-mini/maintenance/belt_tension  
CONFIDENCE: SOLID

**Wanneer moet je stoppen met slicerinstellingen wijzigen en hardware onderzoeken?**

Wanneer een fout ook optreedt met een bekend goed Bambu-profiel, droge PLA, een schoon bed en een eenvoudig testmodel. Terugkerende HMS-meldingen over de extrusion-force/eddy-current-sensor, homing, heater, thermistor of motor vereisen inspectie van nozzleplaatsing, stekkers, kabels en het betreffende onderdeel. Een niet volledig geplaatste hotend kan de krachtmeting verstoren. Noteer de volledige HMS-code, maak een korte video en exporteer printerlogs vóór verdere demontage. Als dezelfde sensorfout na opnieuw plaatsen en volledige kalibratie terugkomt, is vervanging of een supportticket rationeler dan nog tien slicerprofielen proberen. citeturn7search8turn7search11turn4search31

SOURCE: https://wiki.bambulab.com/en/a1-mini/troubleshooting/hmscode/0300_1800_0001_0004  
CONFIDENCE: SOLID

## Mythes en verouderd advies

**Mythe: “Level het bed met een papiertje tot iedere hoek dezelfde weerstand heeft.”**

Waarheid: de A1 meet het bed automatisch met de nozzle en krachtmeting en compenseert de hoogtekaart tijdens het printen. Een papierproef introduceert een subjectieve tweede referentie die de printer niet nodig heeft. Handmatig trammen is uitsluitend een onderhoudsprocedure bij aantoonbare mechanische scheefstand of officiële foutdiagnose. Bij een slechte eerste laag controleer je eerst plaatselectie, vervuiling, plaatsing van de flexplaat en een schone nozzle. citeturn4search12turn4search16

SOURCE: https://wiki.bambulab.com/en/a1/maintenance/manual-bed-tramming  
CONFIDENCE: SOLID

**Mythe: “Corrigeer de eerste laag door handmatig de Z-offset op en neer te draaien.”**

Waarheid: de A1 bepaalt de Z-offset automatisch uit nozzlecontact en bedsensing. Een slechte eerste laag komt veel vaker door vet, een verkeerde plaatpreset, vuil op de nozzle, materiaaltemperatuur of loskomende hoeken. Corrigeer de echte oorzaak. Alleen wanneer officiële diagnose een mechanisch of sensortechnisch probleem vaststelt, is onderhoud nodig; een willekeurige vaste offset kan na een plaat- of nozzlewissel juist nieuwe fouten veroorzaken. citeturn7search0turn18search4

SOURCE: https://wiki.bambulab.com/en/a1-mini/troubleshooting/print-issues-troubleshooting  
CONFIDENCE: SOLID

**Mythe: “Print voor iedere nieuwe rol een pressure-advance- of K-factor-toren.”**

Waarheid: met ingeschakelde flow-dynamics-kalibratie meet de A1 zelf de extrusiedrukrespons vóór de print. Handmatige PA-tests horen vooral bij printers zonder deze A1-functionaliteit of bij bewust aangepaste workflows. Een nieuwe derde-partijrol kan nog wel een andere flow ratio of maximale volumestroom nodig hebben, maar dat zijn andere parameters. Diagnoseer daarom eerst of het probleem lijnvolume, smeltcapaciteit, vocht of echte drukdynamiek betreft. citeturn0search1turn4search1

SOURCE: https://wiki.bambulab.com/en/software/bambu-studio/calibration_pa  
CONFIDENCE: SOLID

**Mythe: “De A1 scant de kalibratielijn met LiDAR, net als een X1.”**

Waarheid: de A1 heeft geen LiDAR. Hij gebruikt accelerometers en een kracht-/druksysteem met eddy-current-sensing bij de hotend om onder meer nozzlebelasting en flow dynamics te bepalen. Advies over een vuile LiDAR-lens, optische kalibratiemarkeringen of LiDAR-onleesbare zwarte build plates is daarom niet van toepassing op een A1 of A1 mini. citeturn0search1turn0search13turn4search12

SOURCE: https://wiki.bambulab.com/en/a1-mini/manual/faq  
CONFIDENCE: SOLID

**Mythe: “Auto bed leveling compenseert een vettige of slecht geplaatste plaat.”**

Waarheid: leveling meet hoogte, geen oppervlakte-energie. Een perfect gemeten bed kan nog steeds nul hechting hebben door huidvet. Evenmin kan software vuil onder de flexplaat of een plaat die op de achterste geleiders ligt wegcompenseren. Was PEI met warm water en afwasmiddel, droog zonder het printvlak aan te raken en plaats de plaat volledig vlak. citeturn18search0turn18search17

SOURCE: https://wiki.bambulab.com/en/knowledge-sharing/first-layer-not-sticking  
CONFIDENCE: SOLID

**Mythe: “Voor maximale sterkte zet je infill gewoon op 100%.”**

Waarheid: bij veel trek- en buigbelastingen leveren extra perimeters meer rendement dan volledig massief infill. Start voor een functioneel deel rond **3–5 wanden en 15–25% infill** en versterk alleen kritieke zones lokaal. Oriëntatie kan bovendien een groter verschil maken: in Bambu’s PLA-CF-data daalt de treksterkte van circa **38 MPa in XY** naar **26 MPa in Z**. Een verkeerd georiënteerd massief onderdeel kan dus zwakker zijn dan een goed georiënteerd hol onderdeel. citeturn17search16turn16view0

SOURCE: https://help.prusa3d.com/article/infill_42  
CONFIDENCE: SOLID

**Mythe: “Omdat de A1 direct drive heeft, kan ieder TPU gewoon door AMS Lite.”**

Waarheid: direct drive helpt pas bij de extruder; AMS Lite moet het filament eerst gecontroleerd laden, geleiden, meten en terugtrekken. Gewoon TPU 95A kan daarbij knikken en hoort op de externe spoel. Alleen expliciet AMS-geschikt, relatief hard materiaal zoals Bambu TPU for AMS van **68D** is officieel bedoeld voor AMS Lite. citeturn0search10turn11search0

SOURCE: https://wiki.bambulab.com/en/general/bambu-mods-to-avoid  
CONFIDENCE: SOLID

**Mythe: “Langzamer printen lost iedere materiaal- of kwaliteitsfout op.”**

Waarheid: langzamer helpt alleen wanneer de hotend de gevraagde volumestroom niet haalt of trillingen domineren. Het helpt niet tegen nat filament, een verstopte nozzle, slechte plaathechting of een klemmende spoel. Bij kleine PETG- of technische details kan extreem langzaam printen zelfs extra warmteinbreng en vervorming geven doordat de nozzle langer boven dezelfde zone blijft. Gebruik minimum-laagtijd, gerichte koeling of print meerdere delen tegelijk wanneer koeltijd — niet bewegingssnelheid — het probleem is. citeturn6search11turn7search3turn1search15

SOURCE: https://wiki.bambulab.com/en/software/bambu-studio/auto-cooling  
CONFIDENCE: SOLID