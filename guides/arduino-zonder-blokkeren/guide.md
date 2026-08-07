# Arduino zonder vastlopende wachttijden

## Welk probleem lost dit op?

Een sketch met `delay()` kan tijdens het wachten geen knop lezen, sensor verwerken of tweede
actie plannen. Deze gids vervangt één blokkerende wachttijd door tijdstempels met `millis()`,
zonder meteen een ingewikkeld softwareproject te maken.

Open [`index.html`](./index.html) en druk op **Afspelen** om het verschil te zien.

## Waarom dit voor jouw werkplaats telt

Je kunt al bedraden, sketches uploaden en waarden aanpassen; zie
[`docs/workshop-profile.md`](../../docs/workshop-profile.md). De volgende stap is niet “meer
code”, maar zorgen dat een sketch blijft luisteren terwijl een lamp, sensor of beweging zijn
eigen tempo volgt. Dit patroon is herbruikbaar voor knoppen, displays, logging en robotica.

## Benodigdheden

- Arduino IDE op Windows;
- een Arduino-bord waarvan je het exacte model kent;
- de ingebouwde led (`LED_BUILTIN`);
- optioneel een drukknop tussen pin 2 en GND;
- [`zonder_delay.ino`](./zonder_delay.ino).

Controleer bij andere sensoren eerst de bordspanning en pinmogelijkheden. Die zijn nog niet
canoniek voor deze werkplaats vastgelegd.

## Stappenplan

### 1. Bewaar het huidige gedrag

Schrijf vóór de wijziging op:

- wat hoort te knipperen of bewegen;
- na hoeveel milliseconden;
- welke input tijdens het wachten wordt gemist;
- welk bericht in de Serial Monitor bewijst dat een input is gelezen.

Zo weet je later of alleen de timing veranderde.

### 2. Open het voorbeeld

1. Start **Arduino IDE**.
2. Klik **File → Open**.
3. Open [`zonder_delay.ino`](./zonder_delay.ino).
4. Kies onder **Tools → Board** het echte bordmodel.
5. Kies onder **Tools → Port** de poort die verschijnt als je het bord aansluit.

### 3. Lees de vier onderdelen bovenin

```cpp
const unsigned long KNIPPER_INTERVAL_MS = 1000;
unsigned long laatsteWisselMs = 0;
bool ledAan = false;
const int KNOP_PIN = 2;
```

- `KNIPPER_INTERVAL_MS` is de wachttijd zonder te blokkeren.
- `laatsteWisselMs` onthoudt wanneer de led voor het laatst wisselde.
- `ledAan` is de huidige toestand.
- `KNOP_PIN` is de input die ondertussen gelezen blijft worden.

### 4. Upload en open de Serial Monitor

1. Klik **Verify** (het vinkje).
2. Klik **Upload** (de pijl).
3. Klik **Tools → Serial Monitor**.
4. Zet de snelheid op **115200 baud**.

De led moet iedere seconde wisselen. Druk je de optionele knop in, dan verschijnt direct
`knop ingedrukt`, ook midden in een knipperinterval.

### 5. Bouw hetzelfde patroon in je eigen sketch

Vervang niet alle `delay()`-regels tegelijk. Kies één functie.

1. Maak één `unsigned long` voor de laatste uitvoertijd.
2. Lees bovenaan `loop()` één keer `unsigned long nu = millis();`.
3. Controleer met:

```cpp
if (nu - laatsteUitvoerMs >= intervalMs) {
  laatsteUitvoerMs = nu;
  // voer één korte stap uit
}
```

4. Laat de rest van `loop()` doorlopen.
5. Voeg een kort Serial-bericht toe waarmee je ziet wanneer de stap liep.

Gebruik expres `nu - laatsteUitvoerMs`, niet `nu >= laatsteUitvoerMs + intervalMs`. De eerste
vorm blijft correct wanneer de `millis()`-teller na lange tijd overloopt.

### 6. Maak meerdere taken zichtbaar

Geef iedere taak zijn eigen interval en laatste tijdstip. Bijvoorbeeld:

- knop lezen: iedere `loop()`;
- display bijwerken: elke 200 ms;
- sensor loggen: elke 1000 ms;
- servo een kleine stap geven: bijvoorbeeld elke 20 ms, als de servo-workflow dat vereist.

Elke taak doet per beurt weinig werk en geeft daarna de controle terug aan `loop()`.

## Zo controleer je het resultaat

1. Meet met de Serial Monitor of de led ongeveer iedere seconde wisselt.
2. Druk twintig keer op willekeurige momenten op de knop.
3. Controleer dat iedere bewuste druk direct een bericht geeft.
4. Laat de sketch minstens twee minuten lopen en controleer dat timing en input tegelijk blijven
   werken.

Geslaagd als de oorspronkelijke uitvoer hetzelfde tempo houdt én de input niet meer door een
wachttijd wordt gemist.

## Veelgemaakte fouten

- `laatsteWisselMs` als gewone `int` bewaren in plaats van `unsigned long`.
- Binnen het nieuwe `if`-blok alsnog een lange `delay()` of blokkerende lus laten staan.
- Eén tijdstempel voor meerdere onafhankelijke taken hergebruiken.
- Iedere ronde duizenden Serial-regels schrijven; ook de seriële buffer kan dan vertragen.
- Een library blokkert intern en aannemen dat alleen zichtbare `delay()`-regels tellen.
- Mechanische knopdender (meerdere snelle overgangetjes) verwarren met gemiste timing.

## Wanneer vraag je Claude om hulp?

- *"Markeer alle blokkerende stukken in deze sketch; verander nog niets."*
- *"Vervang alleen deze delay()-taak door millis() en behoud alle pinnen en uitgangen."*
- *"Maak voor iedere taak een aparte tijdstempel en leg de toestanden in een tabel uit."*
- *"Schrijf een test waarmee ik zie of een knopdruk gemist wordt."*
- *"Welke library-aanroep kan nog blokkeren nadat delay() weg is?"*

## Bronnen en bewijsniveau

- Arduino, **Blink Without Delay**:
  <https://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay> — **Onderbouwd**;
  officiële voorbeeldpagina.
- Arduino `millis()`-referentie: <https://docs.arduino.cc/language-reference/en/functions/time/millis/>
  — **Onderbouwd**.
- De intervals in dit voorbeeld — **Experiment/Praktijkadvies**; pas ze aan het echte proces
  aan en verifieer met tijdstempels.

