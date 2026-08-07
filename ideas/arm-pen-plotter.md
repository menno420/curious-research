# Arm als penplotter — uitgevoerd idee

**Status:** uitgevoerd. Gebruik voor bouwen en testen de actuele Nederlandse bronnen:

- [`projects/arm-pen-plotter/README.md`](../projects/arm-pen-plotter/README.md);
- [`guides/arm-werkgebied/guide.md`](../guides/arm-werkgebied/guide.md);
- [`guides/arm-herhaalbaarheid-meten/guide.md`](../guides/arm-herhaalbaarheid-meten/guide.md).

## Waarom dit idee is gekozen

Een korte getekende lijn verbindt kalibratie, begrensde seriële opdrachten, mechanische
speling en een geprint gereedschap in één zichtbaar testresultaat. Het doel is niet de
nauwkeurigheid van een plotter, maar gecontroleerd leren hoeveel herhaalbaarheid deze arm
werkelijk heeft.

## Kleinste zinvolle resultaat

1. bevestig pinvolgorde en mechanische middenstanden;
2. leg gemeten limieten vast in `arm/calibration.json`;
3. oefen de laptoptool zonder seriële poort;
4. beoordeel startup afzonderlijk;
5. teken onder toezicht één korte lijn en meet de afwijking.

## Bekende beperking

De gecontroleerde laptopworkflow vereist kalibratie voordat hij seriële beweging toestaat.
De huidige Arduino-sketch koppelt de servo’s echter aan en schrijft 90° tijdens `setup()`,
voordat die limieten zijn ontvangen. Dat is geen bewijs van stilstand of hardwareveiligheid.
Gebruik de projectdocumentatie voor de actuele waarschuwing en testvolgorde.
