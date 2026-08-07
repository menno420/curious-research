# Stringing op A1/A1 mini — oorzaak scheiden vóór retraction tunen

## Welk probleem lost dit op?

Er staan fijne haren tussen losse delen. Deze workflow onderscheidt vocht, temperatuur,
reisbeweging en retraction met kleine A/B-proeven. Je start vanuit het Bambu-profiel en neemt
geen Bowden-waarden over voor de direct-drive A1-serie.

Open [`index.html`](./index.html) voor de diagnosevolgorde.

## Waarom dit voor jouw werkplaats telt

De A1 en A1 mini hebben een korte filamentroute bij de printkop. Grote retraction-afstanden uit
oude Bowden-gidsen kunnen hier nieuwe fouten veroorzaken. Bovendien kan vochtig filament blijven
spetteren en haren trekken, ongeacht een keurige retraction-instelling.

## Benodigdheden

- Bambu Studio met het juiste machine-, nozzle- en filamentprofiel;
- het probleemfilament en, indien beschikbaar, droging volgens de fabrikant;
- een klein model met twee torentjes en open reisbewegingen;
- drie kopieën van hetzelfde proces-/filamentprofiel of drie identieke platen;
- foto en log van materiaal, droogstatus, temperatuur en gewijzigde waarde.

## Stappenplan

1. **Bevestig het foutbeeld.** Haren alleen tussen losse delen zijn stringing; naden, blobs en
   ruwe extrusie vragen een bredere diagnose.
2. **Controleer profiel en materiaal.** Gebruik het echte filamenttype en de juiste nozzle. Neem
   de fabrikantbandbreedte als limiet, niet een algemene PLA/PETG-tabel.
3. **Beoordeel vocht eerst.** Sputteren, belletjes, onregelmatige glans en fijn spinrag over de
   hele print maken vocht aannemelijk. Droog volgens de filamentfabrikant en herprint exact
   hetzelfde testmodel voordat je retraction verandert.
4. **Maak een temperatuur-A/B-test.** Print dezelfde torentjes met het huidige profiel en met
   één kleine lagere nozzletemperatuur binnen de fabrikantband. Verander niets anders.
5. **Open pas daarna retraction.** Maak een kopie van het filamentprofiel. Zoek in de
   filamentinstellingen naar de retraction-override en wijzig alleen de afstand in een kleine
   stap ten opzichte van het Bambu-profiel. Leg de oude en nieuwe waarde vast.
6. **Vergelijk drie symptomen.** Minder haren is winst; ontbrekende lijnstart, putjes, tikken of
   materiaal dat wordt afgeslepen betekenen terug naar de vorige waarde.
7. **Test snelheid afzonderlijk.** Alleen als afstand een bruikbaar gebied heeft, vergelijk je
   twee retractionsnelheden met dezelfde afstand en temperatuur.
8. **Bewaar per filament.** Een resultaat geldt voor deze printer/nozzle, filamentvariant,
   droogstatus en temperatuur. Zet het niet als universele A1-waarde in het profiel.

## Zo controleer je het resultaat

Maak foto's vanuit dezelfde hoek. Tel haren tussen de torens en controleer de start van iedere
nieuwe wand. Geslaagd is de laagste wijziging die haren duidelijk reduceert zonder putjes,
klikgeluid of slechte laagstart. Herhaal eenmaal vanaf een koude start.

## Veelgemaakte fouten

- Bowden-afstanden rechtstreeks op de A1 overnemen.
- Retraction tunen terwijl filament hoorbaar of zichtbaar vochtig is.
- Temperatuur, afstand en snelheid in één print tegelijk wijzigen.
- Alleen naar haren kijken en nieuwe onderextrusie negeren.
- Een purgetoren bij kleurwissels verwarren met stringing tijdens travel.

## Wanneer vraag je Claude?

- *"Classificeer deze foto: stringing, naadblob, vocht of iets anders; noem je onzekerheid."*
- *"Maak drie Bambu Studio-proeven waarbij slechts één retractionwaarde verandert."*
- *"Vergelijk deze foto's en tel haren én ontbrekende lijnstarts."*
- *"Waar staat de retraction-override in mijn versie van Bambu Studio? Gebruik mijn screenshot."*

## Bronnen en bewijsniveau

- Bambu Lab, stringing/oozing:
  <https://wiki.bambulab.com/en/filament-acc/filament/print-quality/stringing-oozing> —
  **Onderbouwd**, officiële productbron.
- Testen vanuit het machine-/filamentprofiel — **Praktijkadvies**.
- Eigen retractionafstand en temperatuur — **Experiment** totdat herhaald.
