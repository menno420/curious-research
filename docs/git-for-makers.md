# GitHub als gedeeld werkplaatsgeheugen

> **Status:** gebruikersuitleg · een GitHub-account is nu niet nodig

## Welk probleem lost GitHub hier op?

Een gesprek met Claude of ChatGPT is tijdelijk en iedere assistent heeft een eigen context.
GitHub bewaart daarentegen één openbare verzameling bestanden plus de wijzigingsgeschiedenis.
Daardoor kun je verschillende AI-assistenten steeds naar **dezelfde actuele bron** verwijzen.

Dat maakt GitHub in dit project geen programmeerhobby, maar een centrale gereedschapskast voor
kennis:

- het werkplaatsprofiel heeft één vaste plek;
- gidsen en projecten hebben stabiele links;
- oude en nieuwe versies zijn vergelijkbaar;
- wijzigingen kunnen eerst worden nagekeken en getest;
- de website wordt uit dezelfde repository gepubliceerd.

## Wat is GitHub in gewone werkplaatstaal?

| GitHub-woord | Werkplaatsbetekenis |
|---|---|
| **repository / repo** | De hele projectkast: bestanden, mappen en de geschiedenis van ieder bestand. |
| **main** | De huidige goedgekeurde inhoud waar de website uit wordt gepubliceerd. |
| **commit** | Eén benoemd opslagmoment van een concrete wijziging. |
| **branch** | Een tijdelijke werkversie naast `main`; het goedgekeurde werk blijft staan. |
| **pull request (PR)** | De wijziging met uitleg en verschilweergave, klaar om na te kijken. |
| **CI / controle** | Automatische tests voor onder meer links, sitebestanden en OpenSCAD-renders. |
| **merge** | De gecontroleerde wijziging wordt onderdeel van `main`. |
| **clone** | Later een volledige lokale kopie maken, inclusief versiegeschiedenis. |

De normale publicatieroute is:

**branch → wijziging → PR → groene controle → beoordeling → merge → website**

De maker hoeft deze commando's nu niet zelf uit te voeren. Het is vooral belangrijk te begrijpen
waarom een getest chatresultaat niet rechtstreeks in `main` hoort.

## Waarom helpt dit bij samenwerken met AI?

### 1. Eén bron voorkomt verschillende versies van “de waarheid”

`docs/workshop-profile.md` is de canonieke werkplaatscontext. Claude en ChatGPT kunnen hetzelfde
bestand krijgen, in plaats van elk een losse handgeschreven samenvatting. Een wijziging aan de
printer, controller of software wordt één keer daar vastgelegd.

### 2. Gewone bestanden zijn niet aan één AI-merk gebonden

De kennis bestaat hoofdzakelijk uit Markdown, HTML, Arduino-code en ontwerpbestanden. Daardoor
kan de eigenaar vandaag Claude gebruiken en morgen ChatGPT, zonder de kernkennis in een
propriëtair chatgeheugen op te sluiten.

### 3. Geschiedenis maakt AI-wijzigingen controleerbaar

Een AI kan overtuigend klinken en toch iets verkeerd veranderen. In een PR zie je precies welke
regels erbij kwamen of verdwenen. Een commit maakt bovendien duidelijk *wanneer* en *waarom* een
feit wijzigde.

### 4. Automatische controles vangen mechanische fouten in bestanden

De controles bewijzen geen fysieke veiligheid of printkwaliteit, maar ze kunnen wel voorkomen
dat een dode link, fout HTML-bestand of onrenderbaar OpenSCAD-model ongezien wordt gepubliceerd.

### 5. De website is de leesbare voorkant van dezelfde bron

GitHub Pages publiceert HTML, CSS en JavaScript rechtstreeks uit de repository. De website is
daardoor de gemakkelijke ingang; de repository blijft de diepere bron en geschiedenis.

## Wat gebeurt nadrukkelijk niet automatisch?

- Een willekeurige AI kent deze repository niet vanzelf.
- Een openbare URL wordt alleen gelezen als de gekozen chat webtoegang heeft en de pagina echt
  opent.
- Als een AI geen URL kan openen, moet je de relevante tekst plakken of het bestand uploaden.
- Een chatantwoord wijzigt GitHub niet.
- Een update in GitHub vervangt niet automatisch een eerder geüpload projectbestand in een AI.
- Dezelfde bron maakt de **invoer** gelijk; Claude en ChatGPT kunnen nog steeds verschillend
  redeneren. Vraag beide om feiten en aannames zichtbaar te scheiden.

GitHub zorgt dus niet voor magisch gedeeld AI-geheugen. Het zorgt voor één controleerbare bron
die je aan iedere AI kunt geven.

## Huidige route zonder eigen GitHub-account

1. Open de [publieke werkplaatswebsite](https://menno420.github.io/curious-research/).
2. Open daar **GitHub + AI** en kopieer het actuele werkplaatsprofiel of de directe contextlink.
3. Geef Claude of ChatGPT daarnaast de pagina van het concrete probleem.
4. Laat de AI eerst samenvatten wat zij werkelijk kon openen; ontbrekende toegang wordt dan
   zichtbaar.
5. Test het advies aan machine, ontwerp of simulatie.
6. Geef een bevestigd resultaat terug aan de repositorybeheerder, inclusief omstandigheden en
   datum.
7. Na controle en merge verschijnt de nieuwe kennis weer op de gedeelde bron en, waar relevant,
   op de website.

De webpagina met kopieerbare context staat in
[`site/github-en-ai.html`](../site/github-en-ai.html).

## Later, met een eigen account

Een eigen GitHub-account wordt pas nuttig wanneer de maker zelf wijzigingen wil voorstellen of
de volledige map lokaal wil bijhouden. Dan kan hij:

1. de repository clonen;
2. een eigen branch gebruiken;
3. Claude of ChatGPT een gecontroleerde bestandswijziging laten maken;
4. het verschil nalezen;
5. een PR openen;
6. pas na groene controles mergen.

Dat is een uitbreiding van de huidige route, geen voorwaarde om de website of chatcontext nu te
gebruiken.

## Hoe controleer je of de samenwerking goed werkt?

Geef twee verschillende assistenten dezelfde profieltekst en vraag:

```text
Noem alleen de bevestigde printers, software en robotarmcontext. Zet daarna apart welke
machinegegevens ontbreken. Verzin niets en citeer de sectie waarop ieder feit is gebaseerd.
```

Geslaagd als beide assistenten dezelfde bevestigde hardware noemen, dezelfde belangrijke lege
plekken herkennen en niet doen alsof een chat GitHub heeft bijgewerkt.

## Bronnen

- [About repositories — GitHub Docs](https://docs.github.com/en/repositories/creating-and-managing-repositories/about-repositories)
  — een repository bevat bestanden en hun revisiegeschiedenis; GitHub definieert hier ook
  branch, clone, merge en pull request, **Geverifieerd**, gecontroleerd 2026-08-07.
- [What is GitHub Pages? — GitHub Docs](https://docs.github.com/en/pages/getting-started-with-github-pages/what-is-github-pages)
  — GitHub Pages publiceert een statische site uit repositorybestanden, **Geverifieerd**,
  gecontroleerd 2026-08-07.
