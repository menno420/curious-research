# Eerste laag op de Bambu Lab A1-serie — diagnose zonder handmatige Z-offset

## Welk probleem lost dit op?

Een print laat aan de plaat los, de lijnen sluiten niet aan of de onderrand wordt te breed. Deze
workflow bepaalt met één kleine test of de oorzaak in plaat, profiel, nozzle of eerste-laagproces
zit. Hij gebruikt de automatische metingen van de A1/A1 mini en schrijft geen handmatige
Z-offset voor.

Open [`index.html`](./index.html) voor de beslisroute in beeld.

## Waarom dit voor jouw werkplaats telt

Je gebruikt een Bambu Lab A1 en A1 mini met Bambu Studio; zie
[`docs/workshop-profile.md`](../../docs/workshop-profile.md). Veel generieke eerste-laaggidsen
zijn geschreven voor handmatig genivelleerde printers. Op de A1-serie begin je bij correcte
profielen, een schoon contactvlak en de automatische controle vóór de print.

## Benodigdheden

- de printer en plaat waarop het probleem werkelijk optreedt;
- Bambu Studio met het juiste A1- of A1-mini-profiel, echte nozzlemaat en plaattype;
- het gebruikte filament en bijbehorend profiel;
- warm water, een klein beetje gewoon afwasmiddel en een schone, pluisvrije doek;
- een vlak testvlak van ongeveer 30 × 30 mm en één laag hoog.

## Stappenplan

1. **Leg de uitgangssituatie vast.** Noteer printer, nozzle, plaat, filamentprofiel en waar op
   het bed de fout zit. Maak een foto vóór je iets schoonmaakt of wijzigt.
2. **Controleer de plaatkeuze.** Vergelijk de fysieke plaat met de geselecteerde plaat in Bambu
   Studio. Controleer ook printer en nozzlemaat.
3. **Reinig zonder nieuwe variabele.** Laat de plaat afkoelen, was het printvlak met warm water
   en weinig gewoon afwasmiddel, spoel volledig en droog met een schone doek. Raak het vlak
   daarna alleen aan de randen aan. Volg bij een gecoate plaat altijd de plaatinstructie als die
   hiervan afwijkt.
4. **Controleer de nozzle koud.** Verwijder zichtbaar materiaal aan de buitenkant zonder de
   nozzle of plaat te beschadigen. Controleer hotendmontage en plaatligging volgens de
   machinehandleiding.
5. **Slice alleen het testvlak.** Gebruik dezelfde laaghoogte en hetzelfde filamentprofiel als
   het mislukte onderdeel. Bekijk in Preview de eerste laag, brim en volgorde.
6. **Laat de A1 zijn normale startcontroles uitvoeren.** Sla bed/nozzlekalibratie niet over voor
   deze diagnoserun. Verander nog geen temperatuur, snelheid of flow.
7. **Lees het resultaat.** Losse ronde banen en openingen wijzen op onvoldoende contact; diepe
   groeven, een erg doorschijnend vlak of opgestuwde randen op te veel vervorming. Een egaal,
   gesloten vlak is de referentie.
8. **Verander daarna één ding.** Is reinigen al genoeg, bewaar dat als resultaat. Zo niet, test
   bijvoorbeeld alleen een passend Bambu-filamentprofiel of alleen een lagere eerste-laagsnelheid
   in een kopie van het procesprofiel. Pas geen internet-Z-offset toe.

## Zo controleer je het resultaat

De test is geslaagd als het vlak over de hele 30 × 30 mm gesloten en gelijkmatig is, tijdens de
print niet wordt meegesleept en na afkoelen zonder beschadiging loskomt. Herhaal op dezelfde
bedpositie om toeval uit te sluiten.

## Veelgemaakte fouten

- Een A1 behandelen als een printer met vier handmatige bedknoppen.
- Meerdere zaken tegelijk wijzigen: plaat reinigen, temperatuur verhogen én snelheid verlagen.
- Het verkeerde plaattype of nozzleprofiel selecteren.
- Een volledig onderdeel herprinten in plaats van één laag.
- Een mislukte automatische meting proberen te “repareren” met een algemene Z-offset.
- Een plaat heet aanraken of een schoonmaakmiddel gebruiken dat de coating niet verdraagt.

## Wanneer vraag je Claude?

- *"Vergelijk deze foto van mijn A1-eerste laag met de Preview en geef één volgende test."*
- *"Controleer op deze screenshots printer-, nozzle-, plaat- en filamentprofiel."*
- *"Maak een A/B-test waarbij alleen de eerste-laagsnelheid verandert."*
- *"Welke waarneming onderscheidt vervuiling van een verkeerd plaatprofiel?"*

## Bronnen en bewijsniveau

- Bambu Lab A1 introductie en automatische kalibratie:
  <https://wiki.bambulab.com/en/a1/manual/intro-a1> — **Onderbouwd**, officiële bron.
- Bambu Lab A1 mini introductie:
  <https://wiki.bambulab.com/en/a1-mini/manual/intro-a1-mini> — **Onderbouwd**, officiële bron.
- Testvolgorde, foto en één variabele per proef — **Praktijkadvies**.
- De beste profielwijziging voor een specifieke plaat/filamentcombinatie — **Experiment**.
