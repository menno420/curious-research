# Bewijsbeleid — wat een zekerheidslabel werkelijk betekent

> **Status:** bindend voor nieuwe gidsen, naslagkaarten en bewerkte research

Een label zegt iets over de **onderbouwing van één concrete bewering**. Het zegt niet dat een
hele bron goed is en ook niet dat advies gegarandeerd werkt op iedere machine.

## De vijf labels

| Label op de site | Code | Wanneer gebruiken |
|---|---|---|
| **Geverifieerd** | `verified` | Een primaire bron bestaat, de bron is geopend en de bewering komt ermee overeen. Voorbeelden: fabrikantdocumentatie, datablad, norm of oorspronkelijke meetpublicatie. |
| **Onderbouwd** | `supported` | Een betrouwbare secundaire bron of meerdere onafhankelijke bronnen ondersteunen de bewering, maar er is geen passende primaire bevestiging gecontroleerd. |
| **Praktijkadvies** | `practical` | Een bruikbare werkplaatsmethode of vuistregel. Resultaat hangt af van machine, materiaal, montage of meetmethode. Altijd als startpunt of test formuleren. |
| **Nog bevestigen** | `confirm` | Bron ontbreekt, bronnen spreken elkaar tegen, de bron is niet controleerbaar of de bewering gaat over deze specifieke werkplaats en is nog niet gemeten. |
| **Experiment** | `experimental` | Een bewust proefvoorstel. Beschrijf invoer, meting, succescriterium en wat maar één voor één mag veranderen. |

## Beslisregels

1. **Een URL alleen is niet genoeg.** Open de bron en controleer de precieze claim.
2. **Fabrikant van een andere machine is geen primaire bron voor deze machine.** Zo'n bron kan
   hoogstens een algemene werkwijze ondersteunen.
3. **Een webwinkel of samenvattende datasheet-site is secundair.** Ook als de cijfers er
   overtuigend uitzien.
4. **Een label erft niet.** Als een kaart drie beweringen bevat, moet de bron ze alle drie
   dragen; anders kaart splitsen of het zwakste passende label gebruiken.
5. **Werkplaatsspecifieke prestaties worden gemeten.** Passing, kerf, werkelijk servostroom,
   herhaalnauwkeurigheid, feeds en materiaalinstellingen beginnen als `practical`, `confirm`
   of `experimental` totdat een herhaalbare meting is vastgelegd.
6. **Tijdgevoelige softwarestappen krijgen een controledatum.** Menu's en licentiebeperkingen
   kunnen veranderen.
7. **Veiligheidskritische claims** over dampen, netspanning, laserklasse, brand, belasting of
   voeding krijgen geen `verified` zonder passende primaire bron.

## Minimale provenance per bewerkte kaart

Een kaart of gidsnote bevat waar relevant:

- titel of korte vraag;
- het label;
- directe bronlink;
- datum waarop de bron is gecontroleerd;
- scope: voor welke machine, versie, materiaal of test de claim geldt;
- bij `practical` of `experimental`: hoe de maker het zelf controleert.

De ruwe bestanden in `research/dossiers/` houden hun oorspronkelijke `SOLID`, `COMMON` en
`DISPUTED` labels omdat zij ongewijzigde onderzoeksuitvoer zijn. Die oude labels zijn **input,
geen goedkeuring**. Zodra tekst naar een gids of `site/kennis.html` gaat, wordt hij opnieuw
beoordeeld met de vijf labels hierboven.

## Voorbeeld

> **Bewering:** "Gebruik 0,15 mm kerfcompensatie voor 3 mm multiplex."

- Zonder eigen meting: **Praktijkadvies**; 0,15 mm is alleen een proefstart.
- Als herhaalde couponmetingen op de eigen machine 0,15 mm opleveren: **Geverifieerd voor deze
  combinatie**, mits machine, lens/focus, materiaalbatch, spreiding en meetwijze in het
  projectlog staan.
- Voor een nieuwe plaatbatch: terug naar **Experiment** totdat de coupon opnieuw is gesneden.
