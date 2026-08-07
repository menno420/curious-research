# Arm-penplotter — waypoints aanleren en terugspelen

## Wat is dit?

De 6-DOF-arm draagt een zwevende penhouder. Met de Python-tool jog je één gewricht tegelijk,
bewaar je de zes gewrichtshoeken als waypoint en speel je de reeks langzaam terug. Het doel is
een korte, karaktervol wiebelige lijn — geen printerprecisie.

De centrale context en nog onbekende armgegevens staan in
[`docs/workshop-profile.md`](../../docs/workshop-profile.md). De veiligheids- en
kalibratieafspraken staan in [`arm/README.md`](../../arm/README.md).

## Bekende startupbeperking — lees dit vóór bekrachtigen

> **De besturingsworkflow vereist kalibratie vóór gecontroleerde bediening. Dat betekent niet
> dat de fysieke arm zonder kalibratie niet kan bewegen.**

De laptoptool weigert gecontroleerde opdrachten als `arm/calibration.json` ontbreekt of nog
placeholders bevat. De huidige Arduino-sketch doet tijdens `setup()` echter al het volgende:

1. alle zes servo's koppelen met `attach()`;
2. de interne limieten voorlopig op 90°–90° zetten;
3. eenmaal `write(90)` naar iedere servo sturen;
4. pas daarna op gemeten limieten van de laptop wachten.

Een boardreset of het openen van een seriële verbinding kan dus vóór de kalibratiehandshake een
90°-opdracht veroorzaken. Negentig graden is **niet** als gezamenlijke veilige startupstand voor
deze arm geverifieerd. Gebruik de sketch niet voor powered startup voordat pinvolgorde,
werkelijke rusthouding en een aangepaste startupstrategie onder toezicht op de echte arm zijn
getest. Dit document claimt geen hardwareveiligheid.

## Waarom bouwen?

Dit is een compacte integratietest voor mechanica, gewrichtslimieten, Python, seriële
communicatie en herhaalbaarheid. Je ziet onmiddellijk of een wijziging het gedrag verbetert.

## Benodigde onderdelen en gereedschappen

- de bestaande 6-DOF-arm met MG996R-klasse servo's;
- Arduino, USB-kabel en Windows-pc met Arduino IDE en Python;
- pen, papier en een geprinte zwevende penhouder;
- een externe servovoeding die past bij de **werkelijke servovariant en belasting**, met
  gedeelde massa, passende zekering en bereikbare uitschakeling;
- gemeten min-, max- en middenwaarden per gewricht.

De exacte MG996R-variant, voedingsspanning, gemeten piekstroom en mechanische limieten zijn nog
niet vastgelegd. Neem daarom geen universele stroomwaarde of voorbeeldhoek over als bewezen
eigenschap van deze arm.

## Bestanden

| Bestand | Functie |
|---|---|
| [`teach_and_replay.py`](./teach_and_replay.py) | Laptoptool voor joggen, waypoints bewaren en begrensd terugspelen. |
| [`pen_plotter_arm.ino`](./pen_plotter_arm.ino) | Arduino-ontvanger; begrenst gecontroleerde `S`-opdrachten na de limietenhandshake. Bevat de hierboven beschreven startupbeperking. |
| [`pen_holder.scad`](./pen_holder.scad) | Parametrische bron; standaard- en alternatieve tak renderen manifold, fysieke passing nog meten. |
| [`index.html`](./index.html) | Vereenvoudigde animatie van teach-and-replay; geen veiligheidsbewijs. |

## Bouwstappen

### 1. Meet de arm met servovoeding uit

Volg [`guides/arm-werkgebied/guide.md`](../../guides/arm-werkgebied/guide.md). Noteer per
gewricht de mechanisch bruikbare min en max met marge, plus een middenstand die op deze montage
is gecontroleerd. Let ook op kabelroute, bureaurand, gereedschap en last.

Maak daarna op Windows je eigen bestand:

```powershell
Copy-Item arm\calibration.example.json arm\calibration.json
```

Vervang alle placeholders. Zet bij `measured_by` alleen initialen of een werkplaatsalias en noteer bij
`measured_on` de meetdatum.

### 2. Test de laptoptool zonder hardware

```powershell
python projects\arm-pen-plotter\teach_and_replay.py
```

Zonder `--port` voert de tool een dry-run uit. Controleer dat:

- het eigen kalibratiebestand wordt geladen;
- ongeldige of te grote hoeken naar de gemeten grens worden teruggebracht;
- `rec`, `save` en `replay` met twee oefenwaypoints werken;
- een ontbrekend of onvolledig kalibratiebestand de gecontroleerde workflow blokkeert.

Deze test zegt nog niets over startup van de fysieke arm.

### 3. Pas en print de penhouder

1. Meet de pendiameter en de werkelijke aansluiting aan de pols.
2. Pas `pen_d`, montage-afmetingen en zo nodig `travel` aan in `pen_holder.scad`.
3. Render naar STL, slice in Bambu Studio en controleer de doorsnede in Preview.
4. Print eerst de kleinste montageproef als de polsinterface nog niet gemeten is.
5. Controleer dat de pen een paar millimeter vrij kan veren zonder zijdelingse blokkade.

### 4. Beoordeel startup voordat de servovoeding aan gaat

Controleer pinvolgorde, gedeelde massa, zekering, uitschakeling en servovariant. Vergelijk de
werkelijke huidige gewrichtsstanden met de 90°-opdracht in `setup()`. Ontwerp en test eerst een
startupstrategie die niet naar een onbevestigde stand springt; dit is een noodzakelijke
vervolgwijziging voordat de huidige sketch powered wordt gebruikt.

### 5. Leer pas daarna één korte lijn aan

Als startup op de echte arm aantoonbaar is opgelost en gecontroleerd:

```powershell
python projects\arm-pen-plotter\teach_and_replay.py --port COM3
```

Vervang `COM3` door de poort uit Apparaatbeheer of de Arduino IDE.

1. Begin zonder gereedschapslast, met lage bewegingen en iemand bij de uitschakeling.
2. Jog naar het beginpunt en gebruik `rec`.
3. Jog een korte afstand naar het eindpunt en gebruik opnieuw `rec`.
4. Gebruik `save` en daarna `replay`.
5. Stop bij brommen, vastlopen, onverwachte richting, reset of kabelspanning.

## Hoe controleer je succes?

- Software: zonder geldige kalibratie worden geen gecontroleerde laptopopdrachten uitgevoerd.
- Protocol: vóór de limietenhandshake worden gecontroleerde `S`-opdrachten geweigerd.
- Hoekroute: iedere gecontroleerde opdracht wordt op laptop én Arduino begrensd.
- Mechanica: de pen beweegt tussen twee waypoints zonder botsing of klemmen.
- Resultaat: er staat één lijn op papier en de waypoints zijn opgeslagen.
- Startup: dit punt is pas geslaagd nadat de 90°-sprong uit de huidige workflow is verwijderd of
  op de echte arm als onderdeel van een gecontroleerde strategie is gevalideerd.

## Veelgemaakte fouten

- “De laptoptool weigert” verwarren met “de hardware blijft stil”.
- Voorbeeldhoeken of limieten van een andere arm kopiëren.
- Een MG996R-stroomwaarde als universele specificatie gebruiken zonder exacte variant en bron.
- De Arduino vanuit de 5V-pin van het board voeden.
- Kabelroute, penkracht en bureaurand buiten de limietmeting laten.
- Meerdere verbeteringen tegelijk testen, zodat het effect niet meer toewijsbaar is.

## Mogelijke verbeteringen

1. Eerst een begeleid geteste startup zonder sprong implementeren.
2. Met [`guides/arm-herhaalbaarheid-meten`](../../guides/arm-herhaalbaarheid-meten/guide.md)
   de spreiding van één lijn meten.
3. Pas daarna snelheid, penkracht of compensatie één voor één aanpassen.
4. SVG-import of inverse kinematica pas toevoegen nadat rechte lijn en vierkant reproduceerbaar
   zijn.

## Wanneer vraag je Claude?

- *"Lees de setup van `pen_plotter_arm.ino` en maak een testplan voor startup zonder sprong.
  Wijzig nog geen code totdat ik mijn werkelijke ruststanden heb gegeven."*
- *"Controleer mijn kalibratiebestand op tegenstrijdigheden, maar verzin geen veilige hoeken."*
- *"Maak van mijn A→B→A-metingen een vergelijking met één veranderde variabele."*
- *"Welke observatie bewijst dat dit voeding, speling of softwaretiming is?"*

## Bewijsstatus

- De beschreven volgorde `attach()` → `write(90)` → limietenhandshake is
  **Geverifieerd** in [`pen_plotter_arm.ino`](./pen_plotter_arm.ino).
- Dat 90° veilig is, is **Nog bevestigen** en mag niet worden aangenomen.
- Dat softwareclamps hardwarebotsingen voorkomen, is onjuist: ze begrenzen alleen de hoeken in
  de routes die de clamp daadwerkelijk gebruiken.
- De verwachte wiebelige lijnkwaliteit is **Praktijkadvies** voor een hobbyservoarm en moet met
  de herhaalbaarheidstest op deze arm worden gekwantificeerd.
