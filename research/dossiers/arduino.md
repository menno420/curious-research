<!-- RAW RESEARCH — do not edit. Rewrite into Dutch cards in site/kennis.html instead. -->
> **Topic:** arduino · **Tool:** ChatGPT deep research · **Received:** 2026-08-07
> **Source:** the owner's Drive folder <https://drive.google.com/drive/folders/1Vg9HJxbKaBuv31Ovm4uSlIIMFyi7Yun3>
> **Known artifact:** every card carries an inline `cite…turn…` marker wrapped in invisible private-use characters (U+E201/U+E202). STRIP BOTH before any text reaches the site.
> Saved unedited, per `research/deep-research-prompts.md` § After the research comes back.

---

# Arduino voorbij copy-paste: referentiedossier voor de werkbank

## A — Boards die het kennen waard zijn

**Wanneer is een Arduino UNO R4 Minima de verstandige standaardkeuze?**

De UNO R4 Minima is geschikt voor bestaande 5V-shields en projecten die meer rekenruimte nodig hebben dan een klassieke UNO R3. De 32-bit RA4M1 draait op 48 MHz en biedt 256 kB flash, 32 kB RAM, 8 kB EEPROM, een 14-bits ADC, een 12-bits DAC en CAN. De vorm en pinindeling blijven grotendeels UNO-compatibel. De meerprijs is verspild wanneer een bestaande ATmega328P-schets al betrouwbaar draait en geen extra geheugen, snelheid, DAC, CAN of nauwkeurigere metingen nodig heeft. AVR-specifieke libraries kunnen aanpassing vereisen. citeturn0search4turn0search0turn11search2

SOURCE: https://docs.arduino.cc/hardware/uno-r4-minima  
CONFIDENCE: COMMON

**Wanneer rechtvaardigt de UNO R4 WiFi zijn extra hardware?**

De UNO R4 WiFi combineert dezelfde 48MHz-RA4M1 met een ESP32-S3 voor Wi‑Fi en Bluetooth. Hij voegt een 12×8-ledmatrix, Qwiic-connector, realtimeklok, CAN en een 12-bits DAC toe. De hoofdprocessor en GPIO werken op 5 V; de ESP32-S3 is normaal de communicatiecoprocessor. Kies hem wanneer draadloze bediening, logging of firmware-updates echt onderdeel van de machine zijn. De meerprijs is verspild wanneer een USB-kabel voldoende is of wanneer de ingebouwde matrix, RTC en draadloze verbinding ongebruikt blijven. Voedingsingang VIN accepteert volgens Arduino 6–24 V. citeturn0search1turn12view3turn11search1

SOURCE: https://docs.arduino.cc/hardware/uno-r4-wifi  
CONFIDENCE: COMMON

**Waarom zou je een Nano R4 nemen in plaats van een UNO R4?**

De Nano R4 brengt vrijwel dezelfde RA4M1-capaciteiten naar een kleiner breadboardformaat: 48 MHz, 256 kB flash, 32 kB RAM, 8 kB EEPROM, 14-bits ADC, 12-bits DAC, CAN, RTC en USB‑C. De normale GPIO werkt op 5 V; de Qwiic-aansluiting gebruikt 3,3 V. Hij past beter in een robotarmkast, sensormodule of geprinte behuizing dan een UNO. De meerprijs of migratie-inspanning is verspild wanneer je bestaande UNO-shields wilt stapelen of wanneer de grotere UNO-connectoren mechanisch juist handiger zijn. citeturn2search1turn6search9

SOURCE: https://docs.arduino.cc/hardware/nano-r4/  
CONFIDENCE: COMMON

**Wanneer is een Nano ESP32 beter dan een klassieke Arduino?**

Kies de Nano ESP32 voor Wi‑Fi, Bluetooth Low Energy, webinterfaces, MQTT, draadloze sensoren of veel rekenwerk. De ESP32-S3 heeft 16 MB flash, USB‑C en ondersteuning voor debugging en MicroPython. Het belangrijke verschil is elektrisch: de GPIO is uitsluitend 3,3 V en mag niet rechtstreeks met 5V-signalen worden belast. De meerprijs en complexiteit zijn verspild voor een eenvoudige eindschakelaar, relaisbesturing of één analoge sensor zonder netwerkfunctie. Let ook op de instelbare pinnummering: Arduino- en ESP32-pinnamen kunnen naast elkaar bestaan. citeturn11search12turn11search6turn11search3

SOURCE: https://docs.arduino.cc/nano-esp32  
CONFIDENCE: COMMON

**Wanneer is de Mega 2560 nog steeds de juiste keuze?**

De Mega 2560 blijft nuttig wanneer vooral veel fysieke aansluitingen nodig zijn: 54 digitale pinnen, 15 PWM-uitgangen, 16 analoge ingangen en 4 hardware-UART’s. Hij heeft 256 kB flash, 8 kB RAM en 4 kB EEPROM, maar blijft een 8-bit AVR op 16 MHz. Hij is daarom ideaal voor veel schakelaars, drivers en seriële apparaten zonder complexe berekeningen. Extra geld is verspild wanneer je slechts 10–15 pinnen gebruikt of snelheid, netwerkfuncties en veel RAM belangrijker zijn. Een Mega is groter dan een UNO, maar niet sneller per klokcyclus. citeturn2search0

SOURCE: https://store.arduino.cc/products/arduino-mega-2560-rev3  
CONFIDENCE: COMMON

**Wanneer is een GIGA R1 WiFi geen overkill?**

De GIGA R1 WiFi is bedoeld voor projecten die een gewone microcontroller ontgroeien. De STM32H747 bevat een Cortex-M7 op 480 MHz en een Cortex-M4 op 240 MHz. Het bord heeft 76 GPIO-aansluitingen, Wi‑Fi, Bluetooth, USB‑C device, USB‑A host en interfaces voor camera, display en audio. Hij is zinvol voor machinevision, grote displays, audioverwerking of meerdere gelijktijdige regelkringen. Voor een stappenmotor, temperatuursensor of robotarm met simpele positiecommando’s is hij meestal overkill: meer softwarelagen en 3,3V-elektronica zonder praktisch voordeel voor die taak. citeturn1search0

SOURCE: https://docs.arduino.cc/hardware/giga-r1-wifi  
CONFIDENCE: COMMON

## B — Signalen binnenhalen

**Wanneer is een signaal analoog en wanneer digitaal?**

Een digitale ingang vraagt alleen of de spanning als LOW of HIGH geldt; een analoge ingang meet een bereik. Op een klassieke 5V-UNO verdeelt een 10-bits ADC dat bereik in 1.024 waarden: 0–1023, ongeveer 4,9 mV per stap. Gebruik digitaal voor eindschakelaars, pulsen en modules met een comparatoruitgang. Gebruik analoog voor potentiometers, druksensoren en ruwe spanningssignalen. Een sensor met drie pinnen is niet automatisch analoog: controleer of zijn uitgang spanning, pulsen, I²C, SPI of een open-collectorcontact levert. citeturn3search8turn3search2

SOURCE: https://docs.arduino.cc/language-reference/en/functions/analog-io/analogRead/  
CONFIDENCE: SOLID

**Wat doet `INPUT_PULLUP` werkelijk?**

`INPUT_PULLUP` verbindt de ingang intern via een relatief grote weerstand met de voedingsspanning. Bij klassieke AVR-borden ligt die weerstand typisch tussen 20 kΩ en 50 kΩ. De ingang wordt daardoor stabiel HIGH wanneer de schakelaar open is. Verbind de knop vervolgens tussen ingang en GND: ingedrukt leest hij LOW. De logica is dus omgekeerd, maar je hebt geen externe weerstand nodig. De pull-up levert slechts ongeveer 0,1–0,25 mA bij 5 V en is niet bedoeld om een led, relais of andere belasting te voeden. citeturn3search1turn2search0

SOURCE: https://docs.arduino.cc/built-in-examples/digital/InputPullupSerial/  
CONFIDENCE: SOLID

**Waarom telt één druk op een knop soms meerdere keren?**

Mechanische contacten sluiten niet in één perfecte overgang. Ze stuiteren gedurende enkele milliseconden tussen open en dicht, waardoor de Arduino meerdere flanken ziet. Arduino’s officiële voorbeelden gebruiken onder meer 50 ms debounce-tijd. Een praktische softwareoplossing accepteert een verandering pas wanneer de ingang bijvoorbeeld 20–50 ms stabiel is gebleven. Gebruik voor snelle encoders of veiligheidssignalen liever geschikte hardware, interruptlogica of een RC/Schmitt-trigger-oplossing; een vaste `delay(50)` blokkeert ondertussen de rest van de machine. Debouncing is nodig voor zowel pull-up- als pull-downbedrading. citeturn13search0turn6search8

SOURCE: https://docs.arduino.cc/tutorials/opta/user-manual/  
CONFIDENCE: SOLID

**Levert een 14-bits ADC automatisch een nauwkeuriger meting?**

Niet noodzakelijk. Veertien bits geven theoretisch 16.384 codes; bij 5 V is dat circa 0,305 mV per code. Werkelijke nauwkeurigheid wordt ook begrensd door referentiespanning, elektrische ruis, sensorfout, bedrading en ADC-specificaties. Op R4-borden kan `analogReadResolution(14)` de hogere resolutie inschakelen; standaardinstellingen kunnen om compatibiliteitsredenen lager zijn. Gebruik korte bedrading, goede massa, ontkoppeling en eventueel meerdere metingen. Een stabiele externe referentie kan helpen, maar AREF werkt niet op ieder bord hetzelfde en verkeerd aansluiten kan het bord beschadigen. citeturn3search2turn11search11turn6search9

SOURCE: https://docs.arduino.cc/language-reference/en/functions/analog-io/analogReadResolution/  
CONFIDENCE: COMMON

**Hoe sluit je een 5V-sensor veilig aan op een 3,3V-board?**

Controleer eerst de maximale ingangsspanning. De Nano ESP32 accepteert op zijn GPIO niet meer dan 3,3 V. Een 5V-digitale uitgang heeft daarom een level shifter of spanningsdeler nodig. Met 10 kΩ vanaf het signaal naar de ingang en 20 kΩ van ingang naar GND wordt 5 V nominaal ongeveer 3,33 V. Voor snelle I²C- of SPI-signalen is een geschikte bidirectionele level shifter beter dan een willekeurige deler. Een 3,3V-uitgang wordt door een 5V-board niet altijd gegarandeerd als HIGH herkend; controleer de drempels in de datasheet. citeturn11search12turn11search6

SOURCE: https://docs.arduino.cc/tutorials/nano-esp32/cheat-sheet/  
CONFIDENCE: SOLID

## C — Dingen laten bewegen

**Waarom heeft een servo een aparte voeding nodig?**

Het besturingssignaal van een servo vraagt weinig stroom, maar de motor niet. Een originele MG996R werkt op 4,8–6,6 V, gebruikt circa 170 mA onbelast en kan ongeveer 1,4 A trekken wanneer hij geblokkeerd staat. Voed hem daarom niet via een Arduino-regelaar of GPIO-pin. Gebruik een aparte 5–6V-voeding en verbind de min daarvan met Arduino-GND, zodat het stuursignaal dezelfde referentie heeft. De Servo-library gebruikt standaard pulsen van ongeveer 544–2.400 µs met een herhalingsperiode van 20 ms, oftewel 50 Hz. citeturn5search0turn14search6

SOURCE: https://towerpro.com.tw/product/mg996r/  
CONFIDENCE: SOLID

**Hoe zwaar moet de voeding voor zes MG996R-servos zijn?**

Zes MG996R-servos kunnen theoretisch tegelijk 6 × 1,4 A = 8,4 A trekken bij blokkeren of hard versnellen. Een gereguleerde 5–6V-voeding van ongeveer 10 A geeft daarvoor redelijke marge. Verdeel de voeding met dikke bedrading; laat niet alle stroom door een breadboardbaan of dun Dupont-draad lopen. Plaats bijvoorbeeld 470–1.000 µF buffercondensator bij de servoverdeling en 100 nF dicht bij elektronica. Gemeenschappelijke GND blijft verplicht. Een voeding op gemiddelde bewegingsstroom dimensioneren kan spontane resets veroorzaken zodra meerdere assen tegelijk starten. citeturn5search0

SOURCE: https://towerpro.com.tw/product/mg996r/  
CONFIDENCE: COMMON

**Betekent `Servo.write(90)` werkelijk precies 90 graden?**

Nee. De library zet het getal om in een pulsbreedte; de servo meet geen absolute mechanische hoek terug naar de Arduino. Speling, montage, eindstops en kalibratie bepalen de werkelijke stand. TowerPro specificeert voor de normale MG996R ongeveer 0–159°, terwijl een 180°-versie een afzonderlijke uitvoering is. Begin daarom rond het midden, vergroot het bereik voorzichtig en noteer veilige minimum- en maximumwaarden per gewricht. Dwing een arm nooit tegen zijn mechanische eindstop: bij 6 V kan de MG996R ongeveer 11 kg·cm stilstandskoppel leveren en 1,4 A trekken. citeturn5search0turn5search1turn14search6

SOURCE: https://towerpro.com.tw/product/mg996r/  
CONFIDENCE: SOLID

**Waarom mag een stappenmotorvoeding hoger zijn dan de spoelspanning?**

Een moderne chopperdriver regelt de spoelstroom actief. Daardoor kan een motor met een lage nominale spoelspanning uit bijvoorbeeld 12 V of 24 V worden aangestuurd, zolang de stroomlimiet correct staat. De hogere spanning laat de stroom bij hogere toerentallen sneller opbouwen en behoudt daardoor meer koppel. Een DRV8825-carrier accepteert ongeveer 8,2–45 V en ondersteunt tot 1/32 microstepping. Sluit een stappenmotor nooit tijdens bedrijf los: de inductieve spanningspiek kan de driver beschadigen. De motorstroom, niet alleen de voedingsspanning, bepaalt de veilige instelling. citeturn4search0turn4search16

SOURCE: https://www.pololu.com/product/2133  
CONFIDENCE: SOLID

**Hoe stel je de stroomlimiet van een DRV8825 praktisch in?**

Bij de Pololu-DRV8825 geldt: stroomlimiet in ampère is ongeveer tweemaal VREF in volt. Voor 1,0 A per spoel stel je dus circa 0,50 V in tussen VREF en GND. Meet met een multimeter en draai de potentiometer voorzichtig met een geïsoleerde schroevendraaier. Zonder extra koeling is ongeveer 1,5 A per spoel een praktische bovengrens voor deze carrier; hogere stromen tot circa 2,2 A vereisen serieuze koeling. Clone-modules kunnen andere meetweerstanden gebruiken, waardoor dezelfde VREF-formule niet automatisch geldt. Controleer daarom altijd het schema van de specifieke module. citeturn4search0turn4search10

SOURCE: https://www.pololu.com/product/2133  
CONFIDENCE: SOLID

## D — Voorbij de basis-loop

**Waarom is `millis()` meestal beter dan `delay()`?**

`delay(1000)` houdt de normale programma-afhandeling één seconde tegen. Interrupts, PWM en seriële ontvangst kunnen deels doorgaan, maar je eigen knop-, sensor- en bewegingslogica wordt niet uitgevoerd. Met `millis()` onthoud je wanneer een actie voor het laatst gebeurde en laat je `loop()` ondertussen duizenden keren doorlopen. Daardoor kunnen een display, noodstop, servo en temperatuurregeling naast elkaar werken. Het kernpatroon is: lees `now = millis()`, vergelijk `now - previous` met een interval en update `previous` wanneer de actie werkelijk uitgevoerd is. citeturn15search0turn6search8

SOURCE: https://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay/  
CONFIDENCE: SOLID

**Wat gebeurt er wanneer `millis()` na ongeveer 50 dagen overloopt?**

`millis()` gebruikt doorgaans een 32-bits unsigned teller. Na 4.294.967.296 ms, ongeveer 49,7 dagen, springt hij terug naar nul. Dat hoeft geen storing te veroorzaken. Vergelijk geen toekomstige absolute tijd met `if (now > target)`, maar gebruik unsigned verschilrekening: `if (now - previous >= interval)`. Die berekening blijft ook rond de overgang correct, zolang intervallen kleiner zijn dan ongeveer 2³¹ ms. Resetten vóór dag 50 is dus geen betrouwbare oplossing; rolloverbestendige vergelijking is dat wel. Test dit patroon afzonderlijk voordat het een machinebeveiliging bestuurt. citeturn6search0

SOURCE: https://docs.arduino.cc/language-reference/en/functions/time/millis/  
CONFIDENCE: COMMON

**Wanneer hoort een ingang aan een interrupt en wanneer niet?**

Gebruik een interrupt wanneer een korte puls gemist kan worden of onmiddellijk geregistreerd moet worden, bijvoorbeeld een encoder, toerenteller of nauwkeurige timingflank. Gebruik hem niet als vervanging voor normale knopafhandeling. Een interrupt service routine moet kort blijven: zet een `volatile` vlag, kopieer eventueel een teller en keer terug. `delay()` werkt er niet betrouwbaar en `millis()` loopt tijdens de ISR niet verder. Print niet via Serial vanuit de ISR. Welke pinnen interrupts ondersteunen verschilt per board; de oude regel “alleen pin 2 en 3” geldt niet algemeen. citeturn6search1turn11search18

SOURCE: https://docs.arduino.cc/language-reference/en/functions/external-interrupts/attachInterrupt/  
CONFIDENCE: SOLID

**Wat is een toestandsmachine zonder programmeertheorie?**

Een toestandsmachine is een vaste lijst van machinefasen, bijvoorbeeld `IDLE`, `HOMING`, `MOVING`, `PAUSED` en `FAULT`. In iedere doorgang door `loop()` voert een `switch` alleen de logica van de huidige toestand uit. Overgangen gebeuren door een knop, sensor, fout of verstreken tijd. Daardoor staat de homingprocedure niet door de bewegingscode heen gevlochten en kan `FAULT` vanuit iedere fase veilig worden bereikt. Voor een hobbyproject zijn 3–8 duidelijke toestanden vaak overzichtelijker dan tientallen verspreide `if`-vlaggen. Iedere toestand moet snel terugkeren en mag niet minutenlang in een `while`-lus blijven hangen. citeturn6search2turn13search1

SOURCE: https://docs.arduino.cc/built-in-examples  
CONFIDENCE: COMMON

**Wat voegen een watchdog en EEPROM werkelijk toe?**

Een watchdog reset de controller wanneer software hem niet binnen een gekozen tijd voedt. Klassieke AVR’s bieden intervallen van ongeveer 15 ms tot 8 s. Gebruik hem pas nadat initialisatie en foutlogging betrouwbaar zijn; verkeerd gebruik kan een permanente resetlus veroorzaken. EEPROM bewaart instellingen zonder voeding, maar klassieke AVR-EEPROM is typisch voor circa 100.000 schrijfacties per cel gespecificeerd. Eén schrijfactie per minuut bereikt dat in ongeveer 69 dagen. Sla daarom alleen gewijzigde instellingen op, gebruik `EEPROM.update()` en bewaar continu meetlogwerk op SD, FRAM of een computer. citeturn7search1turn11search8turn6search3

SOURCE: https://docs.arduino.cc/learn/programming/eeprom-guide  
CONFIDENCE: SOLID

## E — Praten met andere dingen

**Wanneer is gewone Serial de beste verbinding?**

UART/Serial is de eenvoudigste punt-tot-puntverbinding voor logging, configuratie, GPS-modules en communicatie tussen twee controllers. Beide zijden moeten dezelfde baudrate gebruiken, bijvoorbeeld 9.600 of 115.200 bit/s, en hun GND delen. Een UNO R4 Minima heeft een USB-seriële verbinding naar de pc én een afzonderlijke hardware-UART op RX/TX. Een Mega 2560 heeft 4 hardware-UART’s, handig voor gelijktijdig een pc, display, GPS en motordriver. Gebruik geen `Serial.print()`-storm in tijdkritische code: een volle buffer kan uitvoering merkbaar vertragen. citeturn8search3turn11search4turn2search0

SOURCE: https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-monitor  
CONFIDENCE: SOLID

**Wanneer is I²C de logische keuze?**

I²C gebruikt slechts twee signaallijnen, SDA en SCL, voor meerdere geadresseerde apparaten. Typische kloksnelheden zijn 100 kHz en 400 kHz. Het is ideaal voor sensoren, RTC’s, kleine displays en I/O-expanders op dezelfde print of in dezelfde compacte behuizing. SDA en SCL zijn open-drain en hebben pull-upweerstanden nodig; veel modules bevatten die al. Te veel parallelle pull-ups maken de totale weerstand te laag. Twee apparaten met hetzelfde vaste adres kunnen niet zonder multiplexer, tweede bus of configureerbare adrespin samen op dezelfde bus. citeturn8search1turn11search24

SOURCE: https://docs.arduino.cc/learn/communication/wire  
CONFIDENCE: SOLID

**Wanneer verdient SPI de voorkeur boven I²C?**

SPI is geschikt wanneer snelheid belangrijker is dan een minimaal aantal draden: SD-kaarten, snelle displays, ADC’s en geheugen. De basisbus gebruikt SCK, MOSI en MISO, plus doorgaans één afzonderlijke chip-select per apparaat. SPI is full-duplex en kan op korte printverbindingen tientallen megahertz halen; I²C zit gewoonlijk op 100 of 400 kHz. Apparaten kunnen verschillende klokmodi en maximumsnelheden eisen. Gebruik daarom `SPI.beginTransaction(SPISettings(...))`, zodat klok, bitvolgorde en mode per apparaat correct worden ingesteld en libraries elkaar minder snel verstoren. citeturn9search2turn9search0turn9search3

SOURCE: https://docs.arduino.cc/language-reference/en/functions/communication/SPI/beginTransaction  
CONFIDENCE: SOLID

**Hoe kies je tussen Serial, I²C en SPI zonder te gokken?**

Gebruik UART wanneer twee apparaten elkaar rechtstreeks spreken en eenvoudige debugging belangrijk is. Gebruik I²C wanneer meerdere relatief trage modules via twee draden dicht bij elkaar zitten. Gebruik SPI wanneer een display, ADC of geheugen veel data nodig heeft en extra chip-selectdraden acceptabel zijn. Controleer altijd vier zaken: spanning, maximale klokfrequentie, kabelafstand en protocolondersteuning van de module. Een “vierpins sensor” verraadt het protocol niet betrouwbaar. Qwiic en STEMMA QT gebruiken doorgaans I²C op 3,3 V, maar de connector garandeert niet dat iedere aangesloten controller 5V-tolerant is. citeturn11search24turn9search0turn2search1

SOURCE: https://docs.arduino.cc/learn/communication/wire  
CONFIDENCE: SOLID

**Wat gebruik je voor meters kabel naast motoren en frequentieregelaars?**

Gebruik voor langere of elektrisch rumoerige trajecten liever een differentiële bus zoals RS‑485 of CAN dan kale TTL-Serial of I²C. RS‑485 gebruikt een getwist aderpaar en kan, afhankelijk van kabel en snelheid, ongeveer 1,2 km halen rond 90 kbit/s of circa 10 Mbit/s over enkele meters. Termineer de hoofdkabel aan beide uiteinden en houd aftakkingen kort. De UART-data kan via een RS‑485-transceiver worden verstuurd, maar richtingbesturing en protocolafspraken blijven nodig. Voor meerdere intelligente machineknooppunten biedt CAN bovendien arbitrage en foutdetectie. citeturn10search9turn10search1turn10search3

SOURCE: https://www.analog.com/en/resources/app-notes/an-960.html  
CONFIDENCE: SOLID

## Mythes en verouderd advies

**“Alle Arduino’s werken met 5V-signalen.” Klopt dat nog?**

Nee. UNO R3, Mega 2560 en de normale GPIO van UNO R4 en Nano R4 gebruiken 5V-logica, maar veel moderne boards niet. De Nano ESP32 werkt op 3,3 V en zijn GPIO mag niet boven 3,3 V worden gebracht. Hetzelfde probleem komt voor bij veel ARM-, ESP32- en RP2040-borden. Een bord kan via 5 V USB worden gevoed en tóch 3,3V-GPIO hebben. Kijk daarom naar de I/O-spanning, niet naar de USB- of VIN-spanning. Een verkeerd 5V-signaal kan een ingang onmiddellijk of geleidelijk beschadigen. citeturn11search12turn11search6turn2search1

SOURCE: https://docs.arduino.cc/tutorials/nano-esp32/cheat-sheet/  
CONFIDENCE: SOLID

**“`analogRead()` levert altijd 0–1023.” Wat is waar?**

Dat gold als praktische standaard voor 10-bits AVR-borden zoals de UNO R3 en Mega 2560. Moderne Arduino’s kunnen hogere ADC-resoluties hebben. UNO R4 en Nano R4 ondersteunen tot 14 bits, dus maximaal 16.383, wanneer de resolutie correct wordt ingesteld. Sommige cores starten op 10 bits voor compatibiliteit met oude sketches. Code die hard `1023` gebruikt voor schaalberekening kan daardoor verkeerde resultaten geven. Gebruik een benoemde ADC-maximumwaarde en zet de gewenste resolutie expliciet met `analogReadResolution()` op boards die dat ondersteunen. citeturn3search2turn6search9

SOURCE: https://docs.arduino.cc/language-reference/en/functions/analog-io/analogReadResolution/  
CONFIDENCE: SOLID

**“`analogWrite()` maakt een echte analoge spanning.” Is dat juist?**

Meestal niet. Op de meeste Arduino-pinnen produceert `analogWrite()` PWM: een snel digitaal signaal dat afwisselend 0 V en de logicaspanning levert. De waarde 0–255 verandert de duty-cycle, niet de piekspanning. Een multimeter of traag apparaat ziet soms een gemiddelde, waardoor het analoog lijkt. Sommige moderne boards hebben daarnaast één of meer echte DAC-uitgangen; bij de UNO R4 zit de 12-bits DAC op A0. Controleer dus zowel het boardschema als het pinnummer. Een PWM-pin wordt niet automatisch een DAC omdat de functie `analogWrite` heet. citeturn11search5turn0search20

SOURCE: https://support.arduino.cc/hc/en-us/articles/9350537961500-Use-PWM-output-with-Arduino  
CONFIDENCE: SOLID

**“Externe interrupts zitten altijd op pin 2 en 3.” Voor welke boards gold dat?**

Dat is vooral oude UNO R3-kennis. Op de ATmega328P-UNO zijn pin 2 en 3 de klassieke externe-interruptpinnen, maar moderne boards ondersteunen interrupts vaak op veel meer of vrijwel alle digitale pinnen. De Nano ESP32 kan bijvoorbeeld interrupts op zijn GPIO gebruiken volgens de ESP32-coremogelijkheden. Gebruik `digitalPinToInterrupt(pin)` in plaats van een hard interruptnummer en controleer de officiële boardtabel. Pinondersteuning, beschikbare modi en elektrische eigenschappen verschillen per processor; een sketch die op een Mega of ESP32 werkt, hoeft niet ongewijzigd op een oude UNO te werken. citeturn6search1turn11search18

SOURCE: https://docs.arduino.cc/language-reference/en/functions/external-interrupts/attachInterrupt/  
CONFIDENCE: SOLID

**“Een Arduino-pin mag veilig 40 mA leveren.” Wat is de correcte grens?**

Veertig milliampère is bij klassieke AVR-processors een absolute maximumwaarde, geen aanbevolen bedrijfsstroom. Arduino specificeert voor de Mega 2560 bijvoorbeeld 20 mA aanbevolen per I/O-pin. Daarnaast bestaan maxima per poortgroep en voor de totale chipstroom. Ontwerp leds meestal rond enkele milliampères en gebruik een transistor, MOSFET of driver voor relais, motoren, krachtige leds en solenoïdes. Een pin die bij 40 mA nog lijkt te werken kan buiten zijn gegarandeerde uitgangsspanning zitten, warm worden of op termijn beschadigen. “Hij ging niet direct kapot” betekent niet dat het ontwerp elektrisch correct is. citeturn2search0

SOURCE: https://store.arduino.cc/products/arduino-mega-2560-rev3  
CONFIDENCE: SOLID

**“`delay()` zet de hele Arduino stil.” Wat blijft wel doorgaan?**

`delay()` blokkeert de normale voortgang door jouw `loop()`, maar schakelt interrupts niet volledig uit. Daardoor kunnen hardware-PWM, tijdregistratie en ontvangst van seriële bytes blijven functioneren. Jouw eigen code verwerkt die ontvangen data echter pas na de vertraging, en buffers kunnen ondertussen vollopen. De juiste uitspraak is dus: `delay()` stopt niet alle hardware, maar voorkomt wel dat de meeste applicatielogica tijdig reageert. Voor één ledtest is dat prima; voor een robot, temperatuurregeling of noodstop is niet-blokkerende timing met `millis()` meestal veiliger. citeturn15search0turn6search8

SOURCE: https://docs.arduino.cc/language-reference/en/functions/time/delay/  
CONFIDENCE: SOLID

**“Een Arduino moet iedere 50 dagen worden herstart vanwege `millis()`.” Klopt dat?**

Nee. De teller loopt na ongeveer 49,7 dagen over, maar goed geschreven code blijft doorwerken. De fout ontstaat wanneer code absolute tijdstippen met `>` vergelijkt. Gebruik een unsigned verschil: `now - previous >= interval`. Door modulo-rekenkunde blijft dat ook rond de overgang correct. Een geplande reset verbergt alleen de programmeerfout en kan nieuwe problemen veroorzaken, zoals verloren positie, onverwachte uitgangen of extra EEPROM-slijtage. Watchdogs zijn bedoeld voor vastgelopen software, niet om normale teller-overflow te omzeilen. citeturn6search0turn7search1

SOURCE: https://docs.arduino.cc/language-reference/en/functions/time/millis/  
CONFIDENCE: COMMON

**“De ESP32 op een UNO R4 WiFi voert automatisch mijn Arduino-sketch uit.” Is dat zo?**

Nee. De normale sketch draait op de Renesas RA4M1, een Cortex-M4 op 48 MHz. De ESP32-S3 verzorgt standaard de draadloze communicatie en werkt als aparte coprocessor. Daarom gedraagt de UNO R4 WiFi zich niet als een gewone ESP32-developmentboard waarop alle ESP32-libraries rechtstreeks toepasbaar zijn. De ESP32-S3 kan afzonderlijk worden geprogrammeerd, maar dat is een geavanceerdere architectuur met twee processors en aparte firmware. Kies een Nano ESP32 of ander direct ESP32-board wanneer jouw hoofdcode expliciet afhankelijk is van ESP32-specifieke functies. citeturn0search1turn11search1

SOURCE: https://docs.arduino.cc/hardware/uno-r4-wifi  
CONFIDENCE: SOLID

**“Een Mega is een snellere UNO.” Wat koop je werkelijk?**

Een Mega 2560 en klassieke UNO R3 draaien beide op 16 MHz met een 8-bit AVR-architectuur. De Mega koopt vooral meer aansluitingen en geheugen: 54 digitale pinnen, 16 analoge ingangen, 4 UART’s, 256 kB flash en 8 kB RAM. Hij voert een vergelijkbare eenvoudige instructie niet plotseling veel sneller uit. Voor veel I/O is hij uitstekend; voor floating-pointberekeningen, grafische interfaces, netwerkstacks of hoge samplefrequenties biedt een 32-bit R4, ESP32 of STM32-board veel meer rekenruimte. “Groter bord” betekent dus meer resources, niet automatisch hogere uitvoersnelheid. citeturn2search0turn0search4

SOURCE: https://store.arduino.cc/products/arduino-mega-2560-rev3  
CONFIDENCE: SOLID

**“EEPROM kun je als continu logbestand gebruiken.” Waarom is dat slecht advies?**

Klassieke AVR-EEPROM is typisch voor ongeveer 100.000 schrijfacties per geheugenlocatie gespecificeerd. Bij één update per seconde kan dezelfde cel theoretisch in ongeveer 28 uur die waarde bereiken. Lezen veroorzaakt die slijtage niet. Gebruik EEPROM daarom voor kalibratie, laatste gebruikersinstellingen en incidentele statusopslag. Schrijf alleen wanneer een waarde werkelijk verandert, gebruik `EEPROM.update()` en spreid frequente writes eventueel over meerdere locaties. Gebruik voor continue meetgegevens liever SD, FRAM, flash met wear levelling of streaming naar een pc. citeturn6search3turn6search6

SOURCE: https://docs.arduino.cc/learn/programming/eeprom-guide  
CONFIDENCE: SOLID

**“I²C werkt probleemloos door een kabel van enkele meters.” Wat is waar?**

I²C heeft geen eenvoudige universele maximumlengte; de beperking komt vooral door buscapaciteit, pull-ups, snelheid, storingsniveau en bedrading. Het protocol is primair geschikt voor korte verbindingen tussen componenten. Een kabel van enkele meters kan bij lage snelheid en zorgvuldig ontwerp werken, maar is geen robuuste standaardoplossing naast servokabels, spindels of frequentieregelaars. Voor een machineverbinding over meters zijn RS‑485 of CAN doorgaans beter: differentiële signalering onderdrukt gemeenschappelijke storing en de bekabeling kan correct worden getermineerd. Een test op de werkbank bewijst niet dat de bus betrouwbaar blijft tijdens motorbedrijf. citeturn11search24turn10search9turn10search1

SOURCE: https://www.analog.com/en/resources/app-notes/an-960.html  
CONFIDENCE: COMMON

**“`Servo.write(90)` is altijd de mechanische middenstand.” Wat is waar?**

`Servo.write(90)` vraagt ongeveer het midden van het door de library aangenomen pulsbereik. Het is geen gekalibreerde hoekmeting. De servohoorn kan één tand verkeerd staan, het mechanisme kan asymmetrisch zijn en het bruikbare bereik kan kleiner zijn dan geadverteerd. De standaard MG996R wordt door TowerPro rond 0–159° gespecificeerd; een 180°-uitvoering is afzonderlijk verkrijgbaar. Kalibreer ieder gewricht met lage snelheid en beperkte pulsen, sla veilige grenswaarden per as op en laat mechanische eindstops nooit als normale positiebepaling functioneren. citeturn5search0turn5search1turn14search6

SOURCE: https://towerpro.com.tw/product/mg996r/  
CONFIDENCE: SOLID