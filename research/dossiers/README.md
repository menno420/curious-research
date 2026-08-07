# Researchdossiers — provenance en gebruik

Deze map bevat **ruwe onderzoeksuitvoer**. De bestanden blijven ongewijzigd, inclusief hun
oorspronkelijke taal, confidence-woorden en bekende extractieartefacten. Zij zijn bewijsinput
voor Claude, geen kant-en-klare uitleg voor de maker.

## Onderwerpen en corroboratie

| Onderwerp | ChatGPT-run | Tweede onafhankelijke run | Status |
|---|---|---|---|
| Arduino | [`arduino.md`](arduino.md) | [`arduino-gemini.md`](arduino-gemini.md) | Twee ruwe bronnen aanwezig |
| Bambu A1-serie | [`bambu-printen.md`](bambu-printen.md) | [`bambu-printen-gemini.md`](bambu-printen-gemini.md) | Twee ruwe bronnen aanwezig |
| Fusion 360 | [`fusion360.md`](fusion360.md) | [`fusion360-gemini.md`](fusion360-gemini.md) | Twee ruwe bronnen aanwezig |
| MG996R-klasse servo's | [`servos.md`](servos.md) | [`servos-gemini.md`](servos-gemini.md) | Twee ruwe bronnen aanwezig |
| Lasersnijden | [`lasersnijden.md`](lasersnijden.md) | — | Slechts één run; extra broncontrole nodig |
| CNC-frezen/routeren | [`frezen.md`](frezen.md) | [`frezen-gemini.md`](frezen-gemini.md) | Twee ruwe bronnen aanwezig |

Het provenanceblok bovenaan ieder bestand noemt onderwerp, tool, ontvangstdatum en herkomst.
Dat blok is de bron van waarheid voor een afzonderlijk dossier; kopieer geen aantallen naar
andere documenten.

## Van dossier naar gids of naslagkaart

1. Zoek de relevante bewering in beide beschikbare runs.
2. Open de oorspronkelijke bron zelf. Een oud `SOLID`-label is geen verificatie.
3. Controleer dat de bron precies dezelfde machine, versie, materiaalsoort of meetcontext dekt.
4. Verwijder bij het herschrijven de onzichtbare `cite…turn…`-tekens en zichtbare
   `start_span`/`end_span`-artefacten.
5. Schrijf kort Nederlands voor de maker; kopieer geen onderzoeksparagraaf.
6. Ken opnieuw een label toe volgens [`../../docs/knowledge-policy.md`](../../docs/knowledge-policy.md).
7. Voeg een directe bronlink, controledatum en praktische verificatie toe.

Bij verschil tussen bronnen: leg het verschil uit en gebruik **Nog bevestigen**. Bij een
werkplaatsspecifieke waarde: maak er een **Experiment** van met één variabele, een meetmethode
en een succescriterium.

