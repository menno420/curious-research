<!-- RAW RESEARCH — do not edit. Rewrite into Dutch cards in site/kennis.html instead. -->
> **Topic:** lasersnijden · **Tool:** ChatGPT deep research · **Received:** 2026-08-07
> **Source:** the owner's Drive folder <https://drive.google.com/drive/folders/1Vg9HJxbKaBuv31Ovm4uSlIIMFyi7Yun3>
> **Known artifact:** every card carries an inline `cite…turn…` marker wrapped in invisible private-use characters (U+E201/U+E202). STRIP BOTH before any text reaches the site.
> Saved unedited, per `research/deep-research-prompts.md` § After the research comes back.

---

# Referentiedossier laser­snijden voor eigen onderdelen

## Materialen

**Welke materialen snijden voorspelbaar met CO₂-, diode- en fiberlasers?**

Een **CO₂-laser van 30–100 W, 10,6 µm** is de werkpaardkeuze voor hout, MDF, laser­multiplex, papier, karton, kurk, textiel, geschikt leer en PMMA-acrylaat. Voor acrylaat geldt als productiegerichte vuistregel ongeveer **10 W per mm dikte**. Een blauwe **diodelaser van 5–40 W, circa 450 nm** snijdt vooral hout, papier en donker, opaak acrylaat; 20 W snijdt volgens xTool bijvoorbeeld **3 mm berken-/lindemultiplex rond 6 mm/s**. Een **fiberlaser rond 1064 nm** is primair voor metalen en bepaalde kunststoffen; hobby-galvo’s van 20–60 W markeren of graveren vooral en zijn geen algemene plaatsnijmachines. citeturn1search7turn8search7turn8search14  
SOURCE: https://www.troteclaser.com/en/resources/blog/diode-laser-vs-co2-laser-vs-fiber-laser-the-comparison-guide  
CONFIDENCE: SOLID

**Waarom mag PVC of vinyl nooit in een laser?**

**Nooit laseren, ook niet met “goede afzuiging”.** Bij thermische ontleding van PVC ontstaat vooral **waterstofchloride, HCl**: een giftig, sterk irriterend en corrosief gas dat met vocht zoutzuur vormt. Het tast longen, geleidingen, lagers, elektronica en optiek aan. Daarnaast kunnen bij onvolledige verbranding gechloreerde organische verbindingen, waaronder **dioxinen en furanen**, ontstaan. “Chloorgas” is een onnauwkeurige versimpeling; het gedocumenteerde hoofdproduct is HCl. Vinylfolie, kunstleer, flexibele kabelmantel, PVC-schuim en zelfklevend vinyl tellen allemaal als PVC-risico. Stop direct als onbekend materiaal een scherpe zure geur, roest of groene koper­corrosie veroorzaakt. citeturn0search0turn0search1turn0search2  
SOURCE: https://www.troteclaser.com/static/ebook/trotec-ebook-handbook-for-engravers.pdf  
CONFIDENCE: SOLID

**Welke andere kunststoffen en composieten horen niet in de machine?**

Vermijd **PTFE/Teflon en andere fluorpolymeren**: verhitting produceert fluorverbindingen, potentieel waaronder waterstoffluoride. Vermijd halogeenhoudende polymeren, vlamvertragende onbekende platen, **FR-4**, epoxy- en fenolcomposieten en onbekende schuimen. Urethaan, nylon en acrylonitrilhoudende polymeren kunnen cyanideverbindingen vormen; polystyreen geeft styreen af. **ABS is niet universeel verboden**, maar smelt, rookt sterk en kan acrylonitril- en styreenproducten geven: alleen verwerken wanneer machine- én materiaalfabrikant het expliciet toestaan. Glas- en koolstofvezelcomposieten snijden doorgaans slecht: de hars verbrandt terwijl vezels achterblijven. Eis voor ieder technisch kunststof een exacte handelsnaam en veiligheidsinformatieblad; “plastic plaat” is onvoldoende identificatie. citeturn7search2turn8search28  
SOURCE: https://www.osha.gov/otm/section-2-health-hazards/chapter-1  
CONFIDENCE: SOLID

**Welke houtsoorten en houtplaten werken goed, en waar gaat het mis?**

Droog, harsarm massief hout, MDF en expliciet **laser-grade multiplex** snijden goed met CO₂ en blauwe diode. Goedkoop bouwmultiplex bevat vaak luchtgaten, harde lijmlagen en overlappen; daardoor blijft een snede lokaal vastzitten terwijl de rest al verkoolt. MDF snijdt homogener, maar produceert veel fijnstof en donkere randen. Als referentie noemt xTool voor **3 mm multiplex** circa **3 mm/s bij 10 W diode**, **6 mm/s bij 20 W** en **12–13 mm/s bij 40 W**, steeds met 100% vermogen en één doorgang. Gebruik die waarden uitsluitend als startpunt. Laser geen geïmpregneerd, drukbehandeld, brandvertragend, geverfd of onbekend verlijmd hout. citeturn1search3turn8search7  
SOURCE: https://uk.xtool.com/pages/material-settings  
CONFIDENCE: SOLID

**Hoe gedragen acrylaat, polycarbonaat en metaal zich?**

**PMMA-acrylaat** is uitstekend voor CO₂: helder acrylaat absorbeert 10,6 µm en krijgt een gladde, vaak glanzende snijrand. Een blauwe diode kan helder, wit en blauw acrylaat meestal niet snijden omdat 450 nm erdoorheen gaat; donker opaak acrylaat kan wel. **Polycarbonaat** absorbeert warmte maar vergeelt, verkoolt en geeft een slechte rand: frees of zaag het liever. Fiberlasers absorberen goed in blank metaal. Een 20–60 W fiber-galvo markeert en graveert; echt plaat­snijden vraagt doorgaans een speciale snijkop, hulpgas en vermogens vanaf honderden watts tot **1 kW of meer**. Een CO₂-hobbylaser snijdt blank metaal normaal niet, afgezien van gespecialiseerde hoogvermogeninstallaties. citeturn1search0turn1search1turn1search23  
SOURCE: https://www.troteclaser.com/en/resources/laser-wiki/diode-lasers-the-guide-to-precision-marking-engraving-and-cutting  
CONFIDENCE: SOLID

## Kerf en passing

**Wat is kerf, en welke waarden zijn realistisch?**

Kerf is de totale breedte materiaal die de snede verwijdert, niet alleen de theoretische lichtvlek. Voor desktop-CO₂ op **3–6 mm hout of PMMA** is **0,10–0,25 mm** een bruikbare startband; Trotec gebruikte in een 3 mm/10 mm acrylaatproject **0,21 mm**. Bij blauwe diodes ligt een typische werkelijke kerf vaak rond **0,08–0,25 mm**, hoewel de geadverteerde spot 0,06–0,10 mm kan zijn. Industriële fiber­snede in metaal varieert veel sterker met plaatdikte: SendCutSend rapporteert ongeveer **0,15–1,0 mm**. Gebruik deze waarden nooit als kalibratie; ze zijn uitsluitend orde van grootte. citeturn2search0turn2search3  
SOURCE: https://www.troteclaser.com/nl/bronnen/laserprojecten/acrylaat-koffie-capsulehouder  
CONFIDENCE: COMMON

**Hoe compenseer je kerf geometrisch correct?**

Als de laser het midden van de getekende lijn volgt, verwijdert hij aan beide zijden ongeveer **kerf ÷ 2**. Voor een buitendiameter offset je de snijlijn **naar buiten met k/2**; voor een gat of binnenuitsparing **naar binnen met k/2**. Bij k = **0,18 mm** is de offset dus **0,09 mm**. Voeg gewenste speling pas daarna toe. Een gat dat werkelijk 20,00 mm moet worden, krijgt een gecorrigeerde baan op 19,82 mm diameter wanneer de software geen automatische kerfcompensatie toepast. Controleer eerst of de laser-CAM zelf “cut outside/inside” gebruikt; dubbele compensatie maakt buitenstukken te groot en gaten te klein. citeturn2search0turn2search7  
SOURCE: https://www.troteclaser.com/nl/bronnen/laserprojecten/acrylaat-koffie-capsulehouder  
CONFIDENCE: SOLID

**Hoe meet je de kerf van je eigen machine nauwkeurig?**

Snijd uit een rechthoek met bekende breedte **W** meerdere parallelle lijnen. Leg alle ontstane stroken zonder tussenruimte tegen elkaar en meet hun gezamenlijke breedte **S**. Bij **n** volledige sneden geldt: **k = (W − S) ÷ n**. Voorbeeld: W = 100,00 mm, tien sneden en S = 98,40 mm geeft k = **0,16 mm**. Tien sneden vergroten een meetfout van 0,02 mm niet, maar middelen hem juist uit. Meet ook een test in X- en Y-richting, boven en onder aan het materiaal, en noteer materiaal, dikte, lens, focus, vermogen, snelheid, air-assist en aantal doorgangen. Gebruik een schuifmaat met **0,01 mm resolutie**. citeturn9search2  
SOURCE: https://boxes.hackerspace-bamberg.de/BurnTest  
CONFIDENCE: COMMON

**Waardoor verandert kerf terwijl dezelfde tekening wordt gebruikt?**

Kerf wordt groter of taps door onjuiste focus, dikke platen, te lage snelheid, te veel vermogen, meerdere doorgangen, slechte air-assist, vervuilde optiek en variërende materiaaldichtheid. Een korte lens geeft een kleine spot maar geringe scherptediepte; dik materiaal kan daardoor boven smaller snijden dan onder, of omgekeerd. Houtlijm en hars vergroten lokaal de warmte-inbreng. Bij fiber­metaalsnijden veranderen ook nozzleafstand, focuspositie, zuurstof of stikstof, gasdruk en pierce-strategie de snede. Meet daarom kerf met exact dezelfde productie-instellingen en dezelfde plaatbatch. Controleer passing opnieuw na lensreiniging of parameterwijziging; een verschuiving van slechts **0,05 mm** is al voelbaar in een stijve perspassing. citeturn2search12turn8search2  
SOURCE: https://sendcutsend.com/blog/best-practices-for-designing-and-laser-cutting-small-parts/  
CONFIDENCE: COMMON

**Hoe organiseer je kerf en passing in Fusion 360 zonder tekeningen te vervuilen?**

Maak centrale gebruikersparameters, bijvoorbeeld `plaat = 3.05 mm`, `kerf = 0.16 mm` en `speling = 0.10 mm`. Modelleer functionele nominale maten en maak een aparte exportschets waarin je offsets toepast. Zo blijft de brongeometrie bruikbaar voor CNC, 3D-printen en een andere laser. Voor een vrije sleuf is de doelbreedte bijvoorbeeld `plaat + speling`; voor een lichte perspassing `plaat − interferentie`. Vermijd losse handcorrecties op tientallen vingers: één gewijzigde parameter moet alle verbindingen deterministisch aanpassen. Exporteer vervolgens alleen de zichtbare productiegeometrie van de exportschets als DXF. Fusion laat bij de huidige DXF-export expliciet eenheid en zichtbare geometrie kiezen. citeturn4search0  
SOURCE: https://help.autodesk.com/view/fusion360/ENU/?caas=caas%2Fsfdcarticles%2Fsfdcarticles%2FHow-to-Save-Sketch-as-DXF-in-Fusion-360.html  
CONFIDENCE: SOLID

## Verbindingen die werken

**Welke tolerantie heeft een goede vingerlasverbinding nodig?**

Meet de werkelijke plaatdikte; “3 mm” multiplex kan bijvoorbeeld **2,8–3,3 mm** zijn. Definieer passing als sleuf minus werkelijke tabdikte, ná kerfcompensatie. Voor hout of MDF is een praktische startwaarde **−0,05 tot −0,15 mm** voor stevige perspassing, **0 tot +0,10 mm** voor handmontage en **+0,10 tot +0,20 mm** voor lijmmontage. Voor bros PMMA begint een veilige perspassing rond **0 tot −0,05 mm**; meer interferentie veroorzaakt gemakkelijk spanningsscheuren. Maak bij iedere nieuwe plaatbatch een kleine kamtest. Houd vingers doorgaans minimaal **1–2× de plaatdikte** breed; zeer smalle vingers verbranden relatief veel en breken sneller. citeturn9search2turn9search15  
SOURCE: https://1cutfab.com/blogs/news/designing-notches-tabs-and-slots-for-laser-assembly  
CONFIDENCE: COMMON

**Hoe dimensioneer je een T-slot met bout en moer?**

Maak de plaatinsteek voor demontabele houten of acrylaatdelen ongeveer **werkelijke plaatdikte +0,15 tot +0,25 mm**. Geef een zeskantige moerval dezelfde speling over de sleutelwijdte; maak hem bij zacht hout liever iets krapper en vijl na. Normale ISO-doorvoergaten zijn onder meer **3,4 mm voor M3, 4,5 mm voor M4 en 5,5 mm voor M5**. Compenseer deze gaten voor kerf wanneer de laserbesturing dat niet doet. Laat tussen moerval en plaatrand bij hout minimaal ongeveer **1,5× plaatdikte** materiaal staan. Oriënteer de T zo dat de bout de verbinding tegen een schouder trekt, niet uitsluitend tegen een dun, verkoold lipje. citeturn3search4turn11search4  
SOURCE: https://sendcutsend.com/faq/how-to-design-a-slip-fit-for-mating-parts/  
CONFIDENCE: COMMON

**Welke geometrie werkt voor een living hinge?**

Voor hout en acrylaat van **3–5 mm** zijn herhaalde sleuven of golven bruikbaar. Trotec adviseert voor acrylaat ongeveer **1–1,5 mm afstand** tussen snijlijnen; bij sommige houtpatronen kan de afstand tot circa **0,5 mm** dalen. Leg rechte sleuven in massief hout bij voorkeur evenwijdig aan de nerf; dwars op de nerf breken de bruggen sneller. Maak de scharnierzone langer dan strikt geometrisch nodig zodat de rek over meer bruggen wordt verdeeld. Acrylaat-living-hinges zijn geschikt voor incidenteel vormen, niet als scharnier dat duizenden cycli maakt: de smalle webben vermoeien en scheuren. Snijd altijd een radiuscoupon met dezelfde dikte voordat je een kastwand ontwerpt. citeturn3search0  
SOURCE: https://www.troteclaser.com/en/helpcenter/materials/application-techniques/bending-technique  
CONFIDENCE: SOLID

**Hoeveel interferentie heeft een perspassing nodig?**

Voor een starre tab-sleufpassing is **0,10–0,20 mm totale interferentie** een veelgebruikte houtwaarde, maar alleen na kerfcompensatie en proefsnijden. Begin bij MDF of multiplex op **0,10 mm**, bij hard massief hout op **0,05–0,10 mm**, en bij PMMA op hoogstens **0,05 mm**. Voor een schuifpassing geef je meestal **0,10–0,30 mm totale speling**. Een stijve perspassing is gevoelig voor vocht, plaatdikte en kerf; voor herhaald demonteren werkt een geïntegreerde veertab beter. Onderzoek naar laser­gesneden spring-fitverbindingen laat juist zien dat een veerweg procesvariatie beter opvangt dan een volledig starre passing. citeturn9search12turn9search15  
SOURCE: https://thijsroumen.eu/data/publications/2019-UIST-springFit.pdf  
CONFIDENCE: COMMON

**Hoe maak je een passingstest die werkelijk bruikbaar is?**

Snijd één coupon met een vaste tab en minstens zeven sleuven, bijvoorbeeld `plaat −0,15`, `−0,10`, `−0,05`, `0`, `+0,05`, `+0,10` en `+0,15 mm`. Graveer de waarde naast iedere sleuf. Neem zowel een sleuf evenwijdig aan X als aan Y op; riemspanning, spotvorm en houtnerf kunnen richtingseffect geven. Test met dezelfde plaatzijde boven, dezelfde focus, air-assist, snelheid en laagvolgorde als het einddeel. Beoordeel afzonderlijk: handmontage, perspassing, lijmruimte en demonteerbaarheid. Bewaar de coupon met datum en materiaalbatch. Eén test van ongeveer **60 × 100 mm** voorkomt meer mislukkingen dan een theoretische universele kerftabel. citeturn9search2  
SOURCE: https://boxes.hackerspace-bamberg.de/BurnTest  
CONFIDENCE: COMMON

## Een bestand voorbereiden

**Welke lijnkleur en lijndikte betekenen snijden of graveren?**

Er bestaat **geen universele kleurcode**. Bij Trotec JobControl is een snijlijn traditioneel een rode RGB-vector op “hairline” en rastergravure een zwarte vulling. Epilog adviseert voor vectorherkenning **0,001 inch, oftewel 0,0254 mm of 0,072 pt**, in RGB; de kleuren kunnen in de driver aan processen worden gekoppeld. LightBurn en veel diodesoftware gebruiken kleur-lagen waarvan de gebruiker zelf de bewerking instelt. Fiber-galvosoftware koppelt kleuren eveneens vaak aan afzonderlijke markeerparameters. Gebruik kleur dus als procesmetadata in de laatste softwarestap, niet als veronderstelling in je Fusion-model. Controleer vóór Start expliciet welke laag Cut, Score, Fill of Ignore is. citeturn4search2turn4search23  
SOURCE: https://support.epiloglaser.com/laser-machine/fusion-pro/system-requirements-setup/default-software-settings-printing-to-the-epilog-software-suite/  
CONFIDENCE: SOLID

**Welke eenheden en schaal moet het bestand hebben?**

Werk voor een Nederlandse werkplaats bij voorkeur volledig in **millimeters en schaal 1:1**. Geef bij Fusion’s DXF-export expliciet millimeters op en controleer na import een bekende maat, bijvoorbeeld een vierkant van **100,00 × 100,00 mm**. Een onderdeel dat 25,4 maal te groot of te klein verschijnt heeft een inch/mm-interpretatiefout. Laat de laserapplicatie niet automatisch “fit to page” of schalen naar het werkbed. PDF is bruikbaar voor rasterwerk of gecontroleerde printflows, maar kan door printerinstellingen worden geschaald. Voor maatvaste contouren is DXF doorgaans veiliger; SVG is praktisch voor veel desktopsoftware, maar Fusion ondersteunt geen algemene directe SVG-export uit iedere schetsworkflow. citeturn4search0turn4search14  
SOURCE: https://help.autodesk.com/view/fusion360/ENU/?caas=caas%2Fsfdcarticles%2Fsfdcarticles%2FHow-to-Save-Sketch-as-DXF-in-Fusion-360.html  
CONFIDENCE: SOLID

**Waarom moeten contouren gesloten en dubbele lijnen verwijderd zijn?**

Een buitendeel of gat moet één gesloten, niet-zelfkruisende vectorlus zijn. In Fusion wordt een gesloten profiel gearceerd; ontbreekt die profielvulling, dan zit er meestal een opening of overlap. Open vectoren zijn alleen wenselijk voor score- of vouwlijnen. Dubbele lijnen zijn gevaarlijker dan ze lijken: de machine snijdt dezelfde plek tweemaal, vergroot de kerf, verkoolt hout en verhoogt brandrisico. Ook onzichtbare vectoren kunnen door een printerdriver worden uitgevoerd. Zoom sterk in op aansluitingen, verwijder dubbele projecties en houd één eigenaar per rand. Gebruik bij voorkeur een geometrische tolerantie rond **0,01 mm** voor het samenvoegen van bedoelde eindpunten, zonder afzonderlijke vormen onbedoeld te verbinden. citeturn4search12turn4search13  
SOURCE: https://help.autodesk.com/view/fusion360/ENU/?contextId=SKT-3D-SKETCH  
CONFIDENCE: SOLID

**Wat exporteert het schoonst uit Fusion 360?**

Maak één vlakke, volledig bepaalde exportschets. Projecteer uitsluitend de randen die werkelijk moeten worden gesneden, verwijder maatvoering en hulplijnen en zet ongewenste geometrie op construction. Klik vervolgens rechts op de schets en kies **Export DXF**; selecteer millimeters en alleen zichtbare geometrie. Dit is schoner dan een complete 3D-assembly als DXF exporteren of een tekeningblad met kader en annotaties gebruiken. Houd graveergebieden desgewenst in een afzonderlijke schets of laag, omdat een kale DXF geen betrouwbare, machine-onafhankelijke betekenis voor “cut” en “engrave” garandeert. Open het resultaat één keer in de uiteindelijke lasersoftware en controleer aantal objecten, schaal, gesloten profielen en duplicaten. citeturn4search0turn4search3  
SOURCE: https://help.autodesk.com/view/fusion360/ENU/?caas=caas%2Fsfdcarticles%2Fsfdcarticles%2FHow-to-Save-Sketch-as-DXF-in-Fusion-360.html  
CONFIDENCE: SOLID

**In welke volgorde moeten gravures, gaten en buitencontouren worden uitgevoerd?**

Voer eerst rastergravure uit, daarna vector-scorelijnen, vervolgens kleine binnengaten en pas als laatste buitencontouren. Zodra de buitenvorm losligt, kan hij door afzuiging, spanning of een opvlammende rand verschuiven; latere gaten staan dan verkeerd. Veel software kan “inner geometries first” automatisch toepassen, maar controleer de simulatie. Zet tekst vóór overdracht om in contouren wanneer het lettertype niet gegarandeerd op de laser-pc aanwezig is. Verwijder maatlijnen, middellijnen en verborgen objecten: elke zichtbare dunne vector kan een echte snede worden. Houd kleine onderdelen met microtabs of een schoon, vlak steunrooster op hun plek; gebruik geen willekeurige dubbele lijn als geïmproviseerde tab. citeturn2search0turn9search7  
SOURCE: https://www.laserboost.com/laser-cutting-design-guideline/  
CONFIDENCE: COMMON

## Veiligheid en afzuiging

**Hoeveel afzuiging heeft een laser werkelijk nodig?**

Volg het werkpunt uit de machinehandleiding, niet alleen de vrije-luchtwaarde van een ventilator. Epilog specificeert voor diverse desktopmachines **350–400 CFM, ongeveer 595–680 m³/h**, via een aansluiting van circa **100 mm**. Een Trotec Speedy 100 noemt minimaal **200 m³/h bij 1000 Pa**. Het drukverschil is essentieel: lange slangen, bochten, filters en kleine doorvoeren verlagen het werkelijke debiet sterk. Gebruik metalen of aantoonbaar brandwerend kanaal, korte leidingen en onderdruk in de machine. Uitblazen naar buiten is robuust; recirculatie vereist een passend fijnstoffilter plus voldoende actieve kool en filterbewaking. Geurafwezigheid bewijst niet dat giftige gassen worden verwijderd. citeturn6search1turn6search6turn6search19  
SOURCE: https://support.epiloglaser.com/laser-machine/mini-helix/getting-started/setting-up-the-exhaust_mini-helix/  
CONFIDENCE: SOLID

**Welke rook en deeltjes ontstaan bij laserbewerking?**

Laserbewerking produceert een materiaalafhankelijke mix van ultrafijne deeltjes, dampen en vluchtige stoffen. NIOSH mat bij CO₂-bewerking onder meer aldehyden, benzeen, acrylonitril, styreen, zuren en deeltjes van **0,3 µm en groter** op niveaus ruim boven achtergrond. Fiberbewerking van metaal maakt metaal- en oxideaerosolen; lak, anodisatie of plating voegt eigen ontledingsproducten toe. Gebruik bronafzuiging tijdens de hele taak en laat die na afloop nog enkele seconden doorlopen voordat het deksel open gaat. Draag bij normaal gesloten bedrijf niet automatisch een masker als vervanging voor slechte afzuiging: herstel eerst de technische beheersing. Stop bij zichtbare rooklekkage, condens op de ruit of geur buiten de behuizing. citeturn7search1turn12search5  
SOURCE: https://stacks.cdc.gov/view/cdc/189415/cdc_189415_DS1.pdf  
CONFIDENCE: SOLID

**Wat mag tijdens het snijden nooit onbeheerd blijven?**

**Geen enkele actieve snijtaak.** Papier, karton, schuim, hout, MDF, textiel en acrylaat kunnen binnen seconden ontbranden; ook afzettingen onder het honingraatrooster kunnen vlam vatten. Blijf op armlengte of in directe zichtlijn van de stopknop. Een camera vanuit een andere ruimte is geen volwaardige bewaking. Gebruik air-assist waar de fabrikant dat voorschrijft, stel focus correct in en stop bij een blijvende vlam; een kort vlammetje direct achter de snijkop kan materiaalafhankelijk voorkomen, maar een stationaire of groeiende vlam niet. Trotec schrijft een **CO₂-brandblusser** binnen direct bereik voor. Schakel bij brand eerst laser en afzuiging veilig uit wanneer dat zonder vertraging kan. citeturn5search2turn5search17turn5search29  
SOURCE: https://www.troteclaser.com/static/pdf/sp500/8091_OM_SP500S_en-us_1.0.pdf  
CONFIDENCE: SOLID

**Welke oogbescherming hoort bij welke laserklasse?**

Een gecertificeerde **klasse-1-behuizing** is bij normaal gesloten gebruik optisch veilig, ook als binnenin een klasse-4-bron zit. Een open diodeframe, geopende servicestand, verwijderde afscherming of open pass-through kan **klasse 4** zijn: direct licht, spiegelreflecties en bij klasse 4 zelfs diffuse reflecties kunnen oog- en huidletsel veroorzaken. CO₂ werkt rond **10,6 µm**, blauwe diode rond **450 nm** en fiber meestal rond **1064 nm**; vooral 1064 nm is onzichtbaar. Brillen moeten aantoonbaar geschikt zijn voor de exacte golflengte én vereiste optische dichtheid. Een willekeurige oranje bril, zonnebril of transparante kap is geen bewijs van bescherming. Bij gesloten klasse 1 hoort de behuizing de primaire beveiliging te zijn, niet een bril. citeturn10search1turn10search2turn10search7  
SOURCE: https://www.gov.uk/government/publications/laser-radiation-safety-advice/laser-radiation-safety-advice  
CONFIDENCE: SOLID

**Waarom mogen interlocks en beschermkappen nooit worden overbrugd?**

De deurinterlock voorkomt dat de ingebouwde klasse-4-bundel toegankelijk wordt. Overbruggen verandert een beheerst klasse-1-product functioneel in een open hoogvermogenlaser, vaak zonder afgeschermde bundelbaan, waarschuwingslicht of gecontroleerde laserruimte. Dat geldt voor CO₂, diode en fiber; bij fiber is een reflectie van blank metaal bovendien onzichtbaar. Gebruik pass-throughopeningen uitsluitend volgens de classificatie en instructies van de fabrikant. Tijdens onderhoud waarbij een kap werkelijk af moet, horen hoofdschakelaar, netstekker en hoogspanning veilig geïsoleerd te zijn; CO₂-voedingen kunnen tienduizenden volts voeren. Een venster is alleen veilig voor de golflengte waarvoor het systeem is gecertificeerd. Vervang beschadigde ruiten, schakelaars en afdichtingen vóór verder gebruik. citeturn5search14turn12search14  
SOURCE: https://www.troteclaser.com/static/pdf/speedmarker-700/8041-operating-manual-speedmarker-700_fiber-v3-en-us.pdf  
CONFIDENCE: SOLID

## Mythes en verouderd advies

**“Met sterke afzuiging kun je PVC veilig snijden” — klopt dat?**

Nee. Afzuiging vermindert blootstelling, maar voorkomt niet dat PVC **waterstofchloride** en mogelijk gechloreerde verbrandingsproducten vormt. HCl condenseert met vocht tot zuur en beschadigt machine, kanaal en omgeving. Een filter kan bovendien doorslaan of verzadigen. De juiste beheersmaatregel is eliminatie: geen PVC, vinyl, PVC-kunstleer of onbekende zelfklevende folie in de laser. Gebruik materiaal dat aantoonbaar PVC-vrij en door de fabrikant voor laserbewerking vrijgegeven is. citeturn0search0turn0search1  
SOURCE: https://support.epiloglaser.com/staging/de/lasermaschine/fusion-ascent/manual/fire-warning/  
CONFIDENCE: SOLID

**“De meegeleverde gekleurde bril maakt een open diode veilig” — klopt dat?**

Nee. Een bril is alleen bruikbaar wanneer golflengtebereik, optische dichtheid, normering en fysieke staat bekend zijn. Goedkope generieke brillen hebben geregeld geen verifieerbare demping. Bovendien beschermt een bril de huid, omstanders, camera’s en brandbare voorwerpen niet. De voorkeursmaatregel is een volledig gesloten, geïnterlockte behuizing met een voor **450 nm** gecertificeerd venster en afzuiging. Brilgebruik is aanvullend voor restrisico’s, niet de vervanging van engineering controls. citeturn5search1turn10search4  
SOURCE: https://www.osha.gov/etools/hospitals/surgical-suite/laser-hazards  
CONFIDENCE: SOLID

**“Rood hairline betekent op iedere laser automatisch snijden” — klopt dat?**

Nee. Rood hairline is een veelgebruikte **Trotec-conventie** en bij Epilog is een zeer dunne vector herkenbaar, maar kleurtoewijzing blijft driver- of softwareconfiguratie. LightBurn, xTool Creative Space en fiber­software kunnen rood aan snijden, graveren, positioneren of negeren koppelen. Controleer altijd de laaginstellingen, vermogen, snelheid, doorgangen en outputvolgorde. Een correct gekleurde lijn met een verkeerde procesmapping kan een diepe snede worden waar alleen een markering bedoeld was. citeturn4search2turn4search23  
SOURCE: https://www.troteclaser.com/static/images/Contact_Support/Manuals/engravers-handbook/Handbook-for-engravers.pdf  
CONFIDENCE: SOLID

**“De kerf is gelijk aan de geadverteerde laserspot” — klopt dat?**

Nee. De optische spot beschrijft de bundel bij een bepaalde focus; kerf omvat verdamping, smelt, verkoling, gasstroming, meerdere doorgangen en de bundelvorm door de volledige plaatdikte. Een diode met een spot van **0,08 mm** kan in hout gemakkelijk een kerf van **0,15–0,25 mm** maken. Bij dikke fiber­gesneden metaalplaat kan de kerf richting **1 mm** gaan. Meet dus het verdwenen materiaal met een multi-cutcoupon en gebruik spotmaat alleen als indicatie voor minimale detailgrootte. citeturn2search3turn2search6  
SOURCE: https://sendcutsend.com/blog/what-is-kerf-in-laser-cutting/  
CONFIDENCE: COMMON

**“Dezelfde materiaalnaam betekent dezelfde snijinstelling” — klopt dat?**

Nee. Twee platen “3 mm berkenmultiplex” kunnen verschillen in werkelijke dikte, lijm, aantal fineerlagen, vocht, luchtgaten en nerfrichting. Ook PMMA verschilt tussen gegoten en geëxtrudeerd materiaal en tussen kleurpigmenten. Hergebruik een instelling alleen wanneer machine, lens, focus, plaatbatch en afzuiging vergelijkbaar zijn. Snijd bij iedere onbekende batch eerst een kleine vermogen-snelheidsmatrix en meet daarna kerf en passing. Fabriekswaarden zijn startwaarden, geen natuurconstanten. citeturn8search2turn8search19  
SOURCE: https://support.xtool.com/article/872  
CONFIDENCE: SOLID

**“Langzamer en met meer vermogen geeft altijd een betere snede” — klopt dat?**

Nee. Te veel energie vergroot kerf, verkoling, smeltrand, warmtebeïnvloede zone en brandrisico. Bij acrylaat kan een passende combinatie van hoog genoeg vermogen en redelijke snelheid een gladdere rand geven dan langzaam bakken met een zwakke bron. Bij hout kan een snelle doorgang met voldoende vermogen schoner zijn dan meerdere trage passages. Gebruik het laagste energie­niveau dat betrouwbaar doorsnijdt, met correcte focus en air-assist. Voor dikke platen kan twee gecontroleerde doorgangen beter zijn dan één extreem langzame, maar alleen na een brandveilige test. citeturn0search0turn8search10  
SOURCE: https://www.troteclaser.com/en-gb/helpcenter/materials/laser-parameter/laser-parameters-definition  
CONFIDENCE: SOLID

**“Een klasse-1-laser is volledig ongevaarlijk” — klopt dat?**

Nee. Klasse 1 zegt dat gevaarlijke laserstraling bij normaal gebruik niet toegankelijk is. Het zegt niets over rook, giftige ontledingsproducten, hete onderdelen, elektriciteit of brand. Een gesloten klasse-1-CO₂-machine kan nog steeds papier ontsteken, PVC-zuur produceren of rook lekken bij defecte afzuiging. Bovendien kan service met geopende kap de klasse-4-bron toegankelijk maken. Behandel klasse 1 dus als optische bescherming onder gespecificeerde omstandigheden, niet als algemene veiligheidsverklaring. citeturn10search2turn12search11  
SOURCE: https://www.gov.uk/government/publications/laser-radiation-safety-advice/laser-radiation-safety-advice  
CONFIDENCE: SOLID

**“Met genoeg doorgangen kan iedere laser ieder materiaal snijden” — klopt dat?**

Nee. Golflengteabsorptie, warmtegeleiding en ontledingschemie stellen harde grenzen. Een blauwe diode gaat door helder acrylaat; extra passages lossen ontbrekende absorptie niet op. Een 20 W fiber-galvo markeert metaal maar vervangt geen 1 kW fiberplaatsnijder met nozzle en hulpgas. Een desktop-CO₂ reflecteert grotendeels op blank metaal. En een technisch “snijbaar” polymeer kan chemisch verboden blijven, zoals PVC of PTFE. Meer passages kunnen vooral hitte, rook, tapsheid en brand verhogen. Kies laserbron en materiaal als passend procespaar. citeturn1search1turn1search9turn1search23  
SOURCE: https://support.xtool.com/hc/en-us/articles/8887535468055-FAQ-on-xTool-1064nm-Infrared-Laser-Module-  
CONFIDENCE: SOLID