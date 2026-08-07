<!-- RAW RESEARCH — do not edit. Rewrite into Dutch cards in site/kennis.html instead. -->
> **Topic:** servos · **Tool:** ChatGPT deep research · **Received:** 2026-08-07
> **Source:** the owner's Drive folder <https://drive.google.com/drive/folders/1Vg9HJxbKaBuv31Ovm4uSlIIMFyi7Yun3>
> **Known artifact:** every card carries an inline `cite…turn…` marker wrapped in invisible private-use characters (U+E201/U+E202). STRIP BOTH before any text reaches the site.
> Saved unedited, per `research/deep-research-prompts.md` § After the research comes back.

---

# Referentiedossier: zes MG996R-klasse servo’s in een 6-DOF-robotarm

## A. Wat een MG996R werkelijk is

### Is “MG996R” één betrouwbaar vastgelegde servospecificatie?

Niet helemaal. De officiële TowerPro MG996R is een standaardservo van **55 g**, circa **40,7 × 19,7 × 42,9 mm**, met metalen tandwielen, twee lagers en een voedingsbereik van **4,8–6,6 V**. Verkopers noemen hem vaak digitaal, terwijl veel goedkope “MG996R-class”-exemplaren andere elektronica, motoren en tandwielen bevatten. Voor de besturing maakt dat label weinig verschil: zowel analoge als digitale hobbyservo’s ontvangen doorgaans dezelfde pulsbreedte-interface. Behandel onbekende exemplaren daarom als afzonderlijke servo’s die je per stuk moet kalibreren en, voor kritieke gewrichten, belasten en meten. citeturn17search0turn19search1

SOURCE: https://towerpro.com.tw/product/mg996r/
CONFIDENCE: DISPUTED

### Hoeveel koppel levert een MG996R werkelijk?

TowerPro specificeert **9,4 kg·cm bij 4,8 V** en **11 kg·cm bij 6,0 V**; 11 kg·cm is **1,08 N·m**. Dat is stall-koppel: het punt waarop de as niet meer beweegt en stroom en verwarming maximaal zijn. Ideaal omgerekend blijft bij een arm van **10 cm** nog 1,1 kgf over en bij **30 cm** slechts 0,37 kgf, vóór het eigen gewicht van arm en pols. Een benchtest van drie clones vond maximaal **10 kg·cm bij 6,6 V**. Ontwerp voor langdurig vasthouden liever rond **3–5 kg·cm per zwaar belast gewricht**, niet rond de stallwaarde. citeturn17search0turn17search1

SOURCE: https://forums.modelflying.co.uk/index.php?%2Ftopic%2F37161-testing-clone-of-the-towerpro-mg996r-servo%2F=
CONFIDENCE: SOLID

### Wat betekent de opgegeven snelheid in een zesassige arm?

De officiële onbelaste snelheid is **0,19 s per 60° bij 4,8 V** en **0,15 s per 60° bij 6,0 V**. Dat laatste komt overeen met ongeveer **400°/s**; een theoretische beweging van 180° duurt dus 0,45 s. Dit geldt zonder relevante belasting. Een schouder die vijf servo’s, metalen beugels en een grijper draagt beweegt duidelijk langzamer dan een bijna onbelaste polsas. Bij een gecoördineerde beweging bepaalt het langzaamste, zwaarst belaste gewricht de minimale bewegingstijd. Te korte softwaretiming veroorzaakt geen hogere snelheid, maar langdurige positieafwijking, hoge stroom en mogelijk overshoot wanneer de belasting afneemt. citeturn17search3turn18search4

SOURCE: https://towerpro.com.tw/product/mg995-robot-servo-180-rotation/
CONFIDENCE: SOLID

### Hoeveel stroom gebruikt één MG996R?

De officiële TowerPro-pagina noemt **10 mA stationair**, **170 mA onbelast bewegend** en **1,4 A stall**. Een verkoper van als echt aangeduide TowerPro-exemplaren specificeert daarentegen **0,5–0,9 A tijdens bewegen** en **2,5 A stall bij 6 V**. Dat verschil is te groot om te negeren en weerspiegelt waarschijnlijk productrevisies, meetmethoden en clonevariatie. Gebruik voor het elektrische ontwerp daarom **2,5 A piek per servo** totdat jouw exemplaren anders zijn gemeten. Voor thermische beoordeling is niet alleen de piek relevant: langdurig 0,8–1,5 A trekken terwijl een gewricht nauwelijks beweegt is een ernstiger signaal dan een korte startpiek. citeturn17search0turn18search0

SOURCE: https://thepihut.com/products/servo-motor-mg996r-high-torque-metal-gear
CONFIDENCE: DISPUTED

### Zijn deadband en resolutie hetzelfde als positioneringsnauwkeurigheid?

Nee. TowerPro noemt een elektrische deadband van **1 µs**: zeer kleine veranderingen in de commando­puls veroorzaken geen nieuwe correctie. Een benchtest van clones zag pas na ongeveer twee stappen van **1 µs** een zichtbare reactie. Dat zegt nog niets over de werkelijke ashoek. Tandwielspeling, potentiometer­ruis, regelhysterese en elastische vervorming kunnen samen tientallen malen groter zijn. “Resolutie” kan bovendien slaan op de puls­generator, interne regelaar of mechanische uitgang. Een controller met **0,25 µs** commandostappen maakt een servo met **0,7° tandwielspeling** dus niet viermaal nauwkeuriger. citeturn17search0turn17search1turn18search2

SOURCE: https://forums.modelflying.co.uk/index.php?%2Ftopic%2F37161-testing-clone-of-the-towerpro-mg996r-servo%2F=
CONFIDENCE: SOLID

## B. Vermogen en voedingsgedrag

### Wat trekt een arm met zes MG996R’s in de praktijk?

Zes onbelast draaiende officiële exemplaren zouden volgens de **170 mA**-waarde samen ongeveer **1,0 A** trekken. Met realistische mechanische belasting is **3–5,4 A** aannemelijk wanneer alle zes bewegen: zesmaal de gepubliceerde **0,5–0,9 A**. De theoretische gezamenlijke stallstroom ligt, afhankelijk van welke specificatie bij jouw exemplaren hoort, tussen **8,4 A** en **15 A**. Ook servo’s die ogenschijnlijk stilstaan trekken stroom om zwaartekracht tegen te werken. Vooral schouder en elleboog kunnen daardoor continu een groot deel van het budget gebruiken terwijl alleen de pols zichtbaar beweegt. Dimensioneer dus niet op het gemiddelde van een rustige demonstratiecyclus. citeturn17search0turn18search0

SOURCE: https://thepihut.com/products/servo-motor-mg996r-high-torque-metal-gear
CONFIDENCE: SOLID

### Welke voeding is passend voor zes servo’s?

Een conservatieve keuze is een gereguleerde **6,0 V-, 15 A-voeding**, dus ongeveer **90 W**, die korte overbelastingen aankan zonder onmiddellijke foldback. Een goede **6 V/10 A-voeding** kan bruikbaar zijn wanneer gelijktijdige versnellingen softwarematig worden beperkt, de arm mechanisch niet kan vastlopen en metingen aantonen dat de rail tijdens de zwaarste horizontale beweging boven ongeveer **5,5–5,8 V** blijft. Ga niet boven de gespecificeerde **6,6 V** om koppel te winnen: motor-, regelaar- en potentiometerslijtage nemen toe. Controleer de spanning zowel op de distributiekaart als aan het uiteinde van de langste servokabel. citeturn17search0turn18search0

SOURCE: https://towerpro.com.tw/product/mg996r/
CONFIDENCE: COMMON

### Hoe moet de servo-installatie worden afgezekerd?

De zekering moet primair bedrading, connectoren en distributieprint tegen oververhitting en kortsluiting beschermen. Voor een installatie die op **15 A** is bedraad, is een hoofdzekering rond **12,5–15 A** logisch, mits de kabels en connectoren die stroom werkelijk verdragen. Per servo is een **3,15 A trage zekering** een bruikbaar startpunt bij een mogelijke **2,5 A** stallpiek; per paar is **5–6,3 A traag** praktischer. Controleer altijd de tijd-stroomcurve: een zekering die “3,15 A” heet, schakelt bij 3,2 A niet onmiddellijk uit. Zekeringen voorkomen bovendien geen tandwielschade of thermische servoschade tijdens langdurig, nét onder de zekeringwaarde, vastlopen. citeturn11search12turn18search0

SOURCE: https://info.littelfuse.com/fuse-fundamentals-technical-paper
CONFIDENCE: COMMON

### Welke brownoutverschijnselen lijken op softwarefouten?

Typische symptomen zijn een USB-controller die opnieuw verschijnt, een COM-poort die kort verdwijnt, terugkeer naar de opstartpose, willekeurige servosprongen, afgebroken I²C-commando’s of een programma dat uitsluitend bij snelle richtingswisselingen vastloopt. Adafruit documenteert dat overmatige servostroom microcontrollers grillig kan laten werken of resetten; SparkFun noemt expliciet reboot en brownout wanneer de voeding de servostroom niet aankan. Het beslissende patroon is belastingafhankelijkheid: de fout verschijnt bij versnellen, remmen of een horizontaal gestrekte arm, maar niet bij dezelfde commando’s zonder mechanische belasting. Meet tijdens zo’n test de **6 V-rail**, niet alleen de logica­voeding in rust. citeturn20search1turn18search3

SOURCE: https://learn.sparkfun.com/tutorials/pi-servo-phat-v2-hookup-guide/troubleshooting-tips
CONFIDENCE: SOLID

### Hoeveel helpt een buffercondensator werkelijk?

Adafruit adviseert als eerste orde **100 µF per servo**; voor zes servo’s is **600–680 µF** dus het minimumstartpunt. In een stevige arm is **1.000–2.200 µF**, laag-ESR en geschikt voor minimaal **10 V**, dicht bij de distributiekaart gebruikelijker. Dit vermindert zeer korte spanningsdalen door kabelinductie en schakelpieken. Het vervangt geen krachtige voeding: een condensator kan geen secondenlange vraag van **5–15 A** opvangen. Een zinvolle validatie is een oscilloscoopmeting tijdens gelijktijdig omkeren van meerdere assen. Meet ook ver aan de kabel; een stabiele voedingsterminal bewijst niet dat de servo zelf geen spanningsval ziet. citeturn20search1

SOURCE: https://learn.adafruit.com/16-channel-pwm-servo-driver/hooking-it-up
CONFIDENCE: COMMON

## C. Aansturing

### Wat betekent het PWM-signaal bij een hobbyservo precies?

De gewenste positie wordt gecodeerd door de **duur van de hoge puls**, niet door een motorvermogenpercentage. Een conventioneel uitgangspunt is een puls van circa **1,0–2,0 ms**, herhaald iedere **20 ms**, dus **50 Hz**, met ongeveer **1,5 ms** als midden. Er bestaat geen universele koppeling met graden: dezelfde 1–2 ms kan bij de ene servo 80° en bij een andere 100° produceren. Sommige uitvoeringen accepteren ongeveer **0,5–2,5 ms**, maar de werkelijke veilige eindpunten moeten per servo worden vastgesteld. Pulswaarden buiten het bruikbare mechanische bereik verhogen stroom en kunnen tandwielen, horn of eindstop beschadigen. citeturn19search1turn19search7

SOURCE: https://www.pololu.com/blog/17/servo-control-interface-in-detail
CONFIDENCE: SOLID

### Wat levert een PCA9685 op, en wat niet?

De PCA9685 levert **16 onafhankelijke kanalen**, een gedeelde programmeerbare frequentie en **12-bit**, dus 4.096 tijdstappen per cyclus. Bij **50 Hz** duurt één stap **20.000/4.096 = 4,88 µs**. Wanneer een servo 180° aflegt over slechts 1.000 µs pulsverschil, vertegenwoordigt één stap theoretisch **0,88°**; over een span van 2.000 µs wordt dat **0,44°**. De chip ontlast de pc of microcontroller van precieze pulstiming en kan kanaalstarts spreiden om stroompieken te beperken. Hij kent echter geen gewrichtshoeken, snelheden, acceleraties, botsingen of trajecten: het is oorspronkelijk een LED-PWM-generator, geen motion controller. citeturn19search0turn20search11

SOURCE: https://www.nxp.com/products/power-drivers/lighting-driver-and-controller-ics/led-drivers/16-channel-12-bit-pwm-fm-plus-ic-bus-led-driver%3APCA9685
CONFIDENCE: SOLID

### Waarom moet vloeiende beweging boven de PCA9685 worden gemaakt?

De PCA9685 springt direct van de oude naar de nieuwe pulsbreedte. Voor vloeiende beweging moet software of controllerfirmware tussenpunten genereren, bijvoorbeeld iedere **10–20 ms**, met een begrensd snelheids- en acceleratieprofiel. Een trapeziumprofiel beperkt snelheid en versnelling; een S-curve beperkt bovendien de “jerk”, waardoor de arm minder schokt en de stroompieken kleiner worden. Alle gewrichten moeten bij voorkeur dezelfde eindtijd krijgen, ondanks verschillende hoekafstanden. Alleen lineair interpoleren in gewrichtshoeken garandeert overigens geen rechte baan van de grijper; daarvoor moeten tussenliggende cartesische punten via inverse kinematica naar gewrichtsstanden worden omgezet. citeturn18search4turn18search18

SOURCE: https://www.pololu.com/docs/0J40/5.e
CONFIDENCE: SOLID

### Welke controllers bieden meer dan een PCA9685?

Een **Pololu Maestro** heeft USB, **0,25 µs** pulsresolutie en ingebouwde snelheids- en acceleratiebegrenzing; daardoor kan de pc enkele doelen sturen terwijl het bord zelf de overgang afwerkt. Een **Lynxmotion SSC-32U** biedt **32 kanalen**, ongeveer **1 µs** resolutie, 0,5–2,5 ms pulsbereik en groepsbewegingen waarbij assen tegelijk beginnen en eindigen. Directe microcontroller­timers zijn goedkoper en potentieel zeer deterministisch, maar vragen meer foutgevoelige code. Voor een Windows-gebruiker met beperkte programmeerervaring is een USB-controller met configuratieprogramma en ingebouwde trajectfuncties vaak onderhoudbaarder dan zelf zes realtime puls- en acceleratie­generatoren bouwen. citeturn18search2turn19search2

SOURCE: https://www.pololu.com/category/102/maestro-usb-servo-controllers
CONFIDENCE: SOLID

### Wat sluit het ontbreken van uitleesbare positiefeedback uit?

Een standaard drieaderige servo heeft intern wel een potentiometer, maar rapporteert die positie niet aan de computer. Zonder extra sensor kun je daarom niet vaststellen of een gewricht zijn doel werkelijk bereikte, hoeveel het onder zwaartekracht inzakte of dat het door een obstakel werd tegengehouden. Daarmee vallen betrouwbare positie-foutbewaking, automatische backlashcorrectie, gekalibreerde cartesische closed-loopregeling en veilig “teach by hand” af. Stroommeting kan een blokkade vermoeden, maar geeft geen unieke hoek. Servo’s met een vierde feedbackdraad maken doelbereik, blokkering en een hogere externe regellus wel waarneembaar. citeturn17search2

SOURCE: https://www.pololu.com/category/267/feetech-servos-with-feedback
CONFIDENCE: SOLID

## D. Nauwkeurigheid en herhaalbaarheid

### Hoe groot is de mechanische speling werkelijk?

In een gemeten serie van drie MG996R-clones bedroeg de rotatiespeling ongeveer **0,7°** en de verticale bewegingsvrijheid van de uitgang circa **1,4°**. Bij een resterende armlengte van **300 mm** veroorzaakt alleen 0,7° al ongeveer **3,7 mm** richtingsafhankelijke tipverplaatsing; bij 400 mm wordt dat **4,9 mm**. Dit is geen controllerresolutieprobleem en verdwijnt niet met meer PWM-bits. Slijtage, losse horn-schroeven, zachte aluminiumbeugels en onvoldoende ondersteunde servouitgangen kunnen de waarde verder vergroten. Vooral belastingomkering is zichtbaar: de motor beweegt eerst door de tandspeling voordat de volgende armsectie volgt. citeturn17search1

SOURCE: https://forums.modelflying.co.uk/index.php?%2Ftopic%2F37161-testing-clone-of-the-towerpro-mg996r-servo%2F=
CONFIDENCE: SOLID

### Hoeveel fout veroorzaakt zwaartekracht zonder dat de software iets verkeerd doet?

Een massa van **300 g** op **30 cm** veroorzaakt al **9 kg·cm** statisch koppel. Dat is **82%** van de geclaimde 11 kg·cm stallwaarde, nog vóór het gewicht van grijper, polsservo’s, links en kabels. De interne potentiometer kan daarbij een acceptabele motorstand aangeven terwijl tandwielen, horn, beugels en armen elastisch vervormen. De tip zakt dan zonder dat het commandosignaal verandert. De fout neemt sterk toe in horizontale poses en neemt af wanneer de arm verticaal staat. Daardoor is een kalibratie die in één pose perfect lijkt niet automatisch geldig in de rest van de werkruimte. citeturn17search3

SOURCE: https://towerpro.com.tw/product/mg995-robot-servo-180-rotation/
CONFIDENCE: SOLID

### Hoe stapelen hoekfouten zich over zes gewrichten op?

Voor kleine hoeken is de tipfout per gewricht ongeveer **resterende armlengte × hoekfout in radialen**. Neem resterende lengtes van 350, 300, 220, 120, 70 en 30 mm. Wanneer alle zes assen door belastingomkering dezelfde kant van **0,7°** speling bereiken, is de theoretische som ongeveer **13,3 mm**. Bij **1°** per as wordt dat circa **19 mm**. Fouten heffen soms gedeeltelijk op, maar daarop kun je niet ontwerpen: zwaartekracht en bewegingrichting correleren meerdere fouten juist dezelfde kant op. De proximale gewrichten domineren; één graad schouderfout bij 400 mm bereik betekent alleen al ongeveer **7 mm** tipfout. citeturn17search1

SOURCE: https://forums.modelflying.co.uk/index.php?%2Ftopic%2F37161-testing-clone-of-the-towerpro-mg996r-servo%2F=
CONFIDENCE: COMMON

### Wat is het verschil tussen nauwkeurigheid en herhaalbaarheid?

Nauwkeurigheid is hoe dicht de tip bij een absolute gewenste coördinaat komt; herhaalbaarheid is hoe dicht opeenvolgende pogingen bij elkaar liggen. Een arm kan bijvoorbeeld telkens op dezelfde plek eindigen, maar systematisch **15 mm** naast het doel. Individuele kalibratie van pulsminimum, midden, maximum en draairichting verwijdert veel systematische hoekfout. Altijd vanuit dezelfde richting naar een eindpositie bewegen vermindert backlashhysterese. Geen van beide corrigeert echter belastingafhankelijke doorbuiging. Kalibreer daarom minstens in meerdere poses en met de werkelijke grijperlast. Adafruit waarschuwt bovendien dat zelfs servo’s van hetzelfde type verschillende pulsgrenzen kunnen hebben. citeturn19search1turn20search3

SOURCE: https://learn.adafruit.com/16-channel-pwm-servo-driver?view=all
CONFIDENCE: COMMON

### Welke tool-tipnauwkeurigheid is eerlijk om te verwachten?

Voor een goed gemonteerde arm met lichte grijper, gekalibreerde servo’s en benadering uit dezelfde richting is **circa ±5–10 mm herhaalbaarheid** in het gunstige midden van de werkruimte haalbaar. Voor gewone bewegingen met wisselende richtingen en **100–300 g** nuttige last op **250–400 mm** bereik is **±10–30 mm** een realistischer planningsgetal. Absolute fouten boven **30 mm** zijn mogelijk in horizontale uiterste poses, bij warme servo’s of slechte clones. Deze bandbreedte volgt al uit gemeten 0,7° speling, geometrische foutstapeling en zwaartekracht; ze is geen fabrieksgarantie. Voor betrouwbaar millimeterwerk zijn uitgaande encoders, stijvere mechanica en externe closed-loopmeting nodig. citeturn17search1turn17search3

SOURCE: https://forums.modelflying.co.uk/index.php?%2Ftopic%2F37161-testing-clone-of-the-towerpro-mg996r-servo%2F=
CONFIDENCE: COMMON

## E. Upgrades die werkelijk verschil maken

### Wat koopt een goedkope digitale drop-inservo?

Een DS3218 Pro-klasse digitale servo kost momenteel grofweg **€22–30 per stuk**, dus **€130–180 voor zes**. Verkopers claimen tot **20 kg·cm** en sommige uitvoeringen ondersteunen 7,4 V. Een hogere interne regel­frequentie kan stevigere positiehouding en kleinere elektrische deadband geven. De winst is echter niet automatisch tweemaal die van een MG996R: de “20 kg”-waarde is meestal stallmarketing en clonekwaliteit varieert. Ook een digitale drieaderige servo geeft geen positie terug en houdt mechanische backlash. Vervang daarom eerst schouder en elleboog en vergelijk stroom, temperatuur, belastingshoek en terugkeerspeling vóór aanschaf van zes stuks. citeturn21search17

SOURCE: https://www.drones-spare-parts.com/en/products/servomotore-ds3218-pro-6v-20kg-digitale-impermeabile-rc
CONFIDENCE: DISPUTED

### Wat levert een servo met een aparte feedbackdraad op?

Een FEETECH FS5115M-FB levert volgens specificatie **15,5 kg·cm bij 6 V** en exposeert de interne potentiometer via een vierde draad. Een Nederlandse winkel vermeldt ongeveer **€39,95 per servo**, dus circa **€240 voor zes**. Daarmee kun je meten of het doel bereikt is, een geblokkeerde as herkennen en een langzame hogere regellus bouwen die belasting­sag compenseert. De meting zit nog steeds op de servo-uitgangspotentiometer en ziet niet noodzakelijk alle vervorming ná de horn of in de arm. Ook zijn zes analoge ingangen, gemeenschappelijke referentie, filtering en kalibratie nodig. citeturn21search0turn21search13

SOURCE: https://www.vanallesenmeer.nl/FEETECH-High-Torque-Servo-FS5115M-FB-with-Position-Feedback-Pololu-3443
CONFIDENCE: SOLID

### Wat kopen externe magnetische encoders?

Een AS5600-module kost in Nederland ongeveer **€3–6** en levert **12 bit**, oftewel **4.096 standen per omwenteling**. Reken inclusief diametrische magneet, print, bracket, kabel en montage eerder op **€10–25 per gewricht**, dus **€60–150 voor zes**. Gemonteerd op de werkelijke gewrichtsas meet hij de uitgaande armstand, inclusief servo-backlash en een deel van de bracketvervorming. Daarmee worden logging, foutdetectie, belastingscompensatie en een externe positieregeling mogelijk. De ruwe stapgrootte is **0,088°**, maar absolute nauwkeurigheid wordt begrensd door magnetische centrering en montage. De sensor moet typisch binnen ongeveer **0,5–3 mm** van een goed uitgelijnde magneet staan. citeturn21search3

SOURCE: https://www.kiwi-electronics.com/en/grove-12-bit-magnetic-rotary-position-sensor-encoder-as5600-11463
CONFIDENCE: SOLID

### Hoeveel winnen veren of contragewichten?

Voor ongeveer **€10–40** aan trekveren, bevestigingspunten en kleinmateriaal kan de schouder- of elleboogbelasting sterker dalen dan met een duurdere servo. Een correct aangebrachte veer of contragewicht kan bijvoorbeeld een groot deel van **9 kg·cm** compenseren dat ontstaat door 300 g op 30 cm. Daardoor dalen houdstroom, warmte, sag en tandwielbelasting terwijl het bruikbare payloadkoppel stijgt. Een contragewicht verhoogt wel totale massa en traagheid; een veer levert hoekafhankelijk koppel en vereist passende geometrie. De beste praktische aanpak is de benodigde servostroom over het hele hoekbereik meten en de veerarm zo kiezen dat vooral de zwaarste horizontale poses worden ontlast. citeturn15search1turn15search2

SOURCE: https://www.mdpi.com/2075-1702/13/10/956
CONFIDENCE: COMMON

### Wanneer is migratie naar slimme busservo’s zinvol?

Een Lynxmotion LSS HT1-klasse slimme servo kost grofweg **€115–130 per as**; zes assen komen dus rond **€700–780**, exclusief nieuwe voeding, brackets en controller. Daarvoor krijg je een seriële bus en uitleesbare positie plus bedrijfsgegevens zoals stroom, spanning en temperatuur. Dat maakt echte foutdetectie, configureerbare snelheden, diagnostiek en teach-functies mogelijk. Het model levert circa **29 kg·cm** en werkt rond **12 V**, maar is geen elektrische drop-in voor een 6 V-MG996R-installatie. Deze stap verandert de architectuur wezenlijk: één bidirectionele actuatorbus vervangt losse PWM-kanalen en externe feedbackbedrading. Voor een blijvend uitbreidbaar platform is dat vaak rationeler dan steeds meer correctielagen rond goedkope servo’s bouwen. citeturn8search3turn8search1

SOURCE: https://uk.robotshop.com/products/lynxmotion-smart-servo-lss-high-torque-ht1
CONFIDENCE: SOLID

## Mythes en verouderd advies

### “Een servo van 11 kg·cm kan 11 kilogram tillen”, klopt dat?

Nee. **11 kg·cm** betekent theoretisch 11 kgf op een arm van 1 cm, 1,1 kgf op 10 cm of 0,37 kgf op 30 cm, en alleen bij stall. Bij stall staat de as stil en zijn stroom en verwarming maximaal. In een robotarm verbruiken het eigen gewicht van links, vijf verderop gemonteerde servo’s, grijper en kabels een groot deel van het beschikbare schouderkoppel. Een payloadberekening moet voor ieder gewricht alle massa’s vermenigvuldigen met hun afstand tot dat gewricht. citeturn17search3

SOURCE: https://towerpro.com.tw/product/mg995-robot-servo-180-rotation/
CONFIDENCE: SOLID

### “Een 6 V/3 A-voeding is genoeg zolang niet alle servo’s tegelijk bewegen”, klopt dat?

Nee. Servo’s die niet bewegen trekken nog steeds stroom om zwaartekracht tegen te houden. Zes belaste exemplaren kunnen tijdens normale beweging samen **3–5,4 A** vragen, en gepubliceerde gezamenlijke stallwaarden lopen tot **15 A**. Bovendien kunnen meerdere interne regelaars gelijktijdig corrigeren, ook wanneer de software maar één nieuw doel heeft verzonden. Een 3 A-voeding kan bij een verticale rustpose goed lijken en bij dezelfde arm horizontaal voortdurend in stroombegrenzing raken. citeturn18search0

SOURCE: https://thepihut.com/products/servo-motor-mg996r-high-torque-metal-gear
CONFIDENCE: SOLID

### “De PCA9685 maakt beweging automatisch vloeiend”, klopt dat?

Nee. De PCA9685 genereert stabiele pulsbreedtes en houdt de laatst geschreven waarde vast. Wanneer de software van 1.200 naar 1.800 µs schrijft, verandert het uitgangsdoel onmiddellijk. Vloeiende snelheid, acceleratie, gezamenlijke eindtijd en S-curves moeten door hostsoftware of een hogere motion controller worden gemaakt. Een Maestro of SSC-32U heeft zulke functies gedeeltelijk ingebouwd; een kale PCA9685 niet. citeturn19search0turn18search4

SOURCE: https://www.nxp.com/products/power-drivers/lighting-driver-and-controller-ics/led-drivers/16-channel-12-bit-pwm-fm-plus-ic-bus-led-driver%3APCA9685
CONFIDENCE: SOLID

### “Twaalf-bit PWM betekent 4.096 bruikbare servohoeken”, klopt dat?

Nee. De 4.096 stappen bestrijken de volledige periode. Bij **50 Hz** is één stap **4,88 µs**. Over een bruikbaar pulsgebied van 1.000 µs blijven slechts ongeveer **205 commandostappen** over. Dat is theoretisch circa **0,88° per stap** wanneer die 1.000 µs met 180° overeenkomt. Vervolgens zijn mechanische speling, deadband en potentiometer­ruis nog groter. De gemeten clone­speling van ongeveer **0,7°** laat zien waarom een 12-bit chip geen 12-bit mechanische arm oplevert. citeturn19search0turn17search1

SOURCE: https://www.nxp.com/products/power-drivers/lighting-driver-and-controller-ics/led-drivers/16-channel-12-bit-pwm-fm-plus-ic-bus-led-driver%3APCA9685
CONFIDENCE: SOLID

### “Digitaal servo” betekent digitale communicatie en positiefeedback, klopt dat?

Nee. “Digitaal” beschrijft meestal de interne regel­elektronica en hogere motor­aanstuurfrequentie. De externe aansluiting blijft bij veel digitale hobbyservo’s drieaderig: voeding, massa en een pulsbreedtecommando. Er komt geen gemeten hoek terug. Voor bidirectionele data is een feedbackdraad, externe encoder of echte busservo nodig. Zelfs een dure digitale PWM-servo kan dus volledig onzichtbaar vastlopen terwijl de computer denkt dat de doelhoek is bereikt. citeturn19search1turn17search2

SOURCE: https://www.pololu.com/blog/17/servo-control-interface-in-detail
CONFIDENCE: SOLID

### “Metalen tandwielen hebben geen backlash”, klopt dat?

Nee. Metaal verhoogt vooral sterkte en slijtvastheid; het elimineert noodzakelijke tandspeling, lager­speling of toleranties niet. Bij drie geteste MG996R-clones werd ongeveer **0,7° rotatiespeling** en **1,4° verticale uitgangsspeling** gemeten. Bij 300 mm resterende armlengte wordt 0,7° al ongeveer 3,7 mm tipverplaatsing. Metalen tandwielen kunnen bovendien na herhaalde schokbelasting juist merkbare speling ontwikkelen zonder onmiddellijk tanden te verliezen. citeturn17search1

SOURCE: https://forums.modelflying.co.uk/index.php?%2Ftopic%2F37161-testing-clone-of-the-towerpro-mg996r-servo%2F=
CONFIDENCE: SOLID

### “Een grote condensator lost een te kleine voeding op”, klopt dat?

Nee. Een condensator helpt tegen korte stroomranden en lokale kabelspanningsval. Adafruit noemt **100 µF per servo** als beginwaarde, dus circa **600–680 µF** voor zes. Hij kan echter geen langdurige vraag van meerdere ampères leveren. Wanneer een arm gedurende 0,5 seconde 10 A vraagt en de voeding slechts 3 A kan leveren, wordt de condensator vrijwel onmiddellijk ontladen en volgt alsnog een brownout. De structurele oplossing is voldoende voedingsvermogen, lage kabelweerstand en begrensde gelijktijdige acceleratie. citeturn20search1

SOURCE: https://learn.adafruit.com/16-channel-pwm-servo-driver/hooking-it-up
CONFIDENCE: SOLID

### “De gevraagde hoek is de werkelijke gewrichtshoek”, klopt dat?

Nee. De besturing weet alleen welke pulsbreedte zij heeft verzonden. Zonder feedback kan zij niet zien of de servo achterloopt, tegen een obstakel staat, door tandspeling nog niet reageert of onder belasting enkele graden inzakt. De interne potentiometer sluit alleen de lokale servolus en is niet uitleesbaar via de normale drie draden. Een vierde feedbackdraad of een externe encoder is nodig om doel- en werkelijke hoek te vergelijken. citeturn17search2

SOURCE: https://www.pololu.com/category/267/feetech-servos-with-feedback
CONFIDENCE: SOLID

### “Alle MG996R’s reageren hetzelfde op 1.000–2.000 µs”, klopt dat?

Nee. Er is geen universele puls-naar-hoekstandaard. Pololu merkt op dat 1,0–2,0 ms bij de ene servo 80° en bij een andere 100° kan betekenen. Bovendien worden MG996R-achtige servo’s verkocht als 90°, 120°, 180° en soms anders begrensde varianten. Gebruik daarom per servo een kalibratietabel met veilig minimum, midden en maximum. Laat geen gewricht mechanisch tegen zijn stop lopen om een softwarematig gewenste “180°” af te dwingen. citeturn19search1turn18search0

SOURCE: https://www.pololu.com/blog/17/servo-control-interface-in-detail
CONFIDENCE: SOLID