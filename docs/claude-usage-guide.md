# Claude of ChatGPT gebruiken met deze werkplaatskennis

## Welk probleem lost dit op?

Een losse AI-chat kent niet automatisch de printers, software, robotarm en voorkeursstijl van
de maker. Deze repository bewaart die context op één plek. De huidige aanbevolen route is:

**website openen → actuele context delen → concrete vraag stellen → advies testen → bevestigd
resultaat laten bewaren**

Daarvoor is nu geen GitHub-account, clone of lokale installatie nodig.

## Direct beginnen via website en chat

### 1. Open de werkplaatswebsite

Ga naar <https://menno420.github.io/curious-research/> en open **GitHub + AI**. Die pagina legt
uit waarom GitHub de centrale bron is en laadt het actuele canonieke werkplaatsprofiel rechtstreeks
uit de repository.

Directe pagina:
<https://menno420.github.io/curious-research/github-en-ai.html>

### 2. Geef de AI het werkplaatsprofiel

Klik op **Kopieer startopdracht** en plak die als eerste bericht in Claude of ChatGPT. De
opdracht verwijst naar:

<https://raw.githubusercontent.com/menno420/curious-research/main/docs/workshop-profile.md>

Vraag de assistent daarna eerst te vertellen wat zij werkelijk kon openen. Dat voorkomt dat
webtoegang wordt verondersteld.

Kan de AI de URL niet lezen? Klik op **Kopieer profieltekst** en plak de tekst in de chat. Als
de gebruikte chat een bestandsupload aanbiedt, mag je `docs/workshop-profile.md` ook uploaden.

### 3. Deel één relevante gids of projectpagina

Open op de website het onderwerp dat bij de vraag hoort en kopieer die URL. Deel niet meteen
de hele repository als één lange tekst; één profiel plus één relevante uitvoeringspagina geeft
meestal een duidelijker antwoord.

Voorbeeld:

```text
Gebruik het werkplaatsprofiel dat ik zojuist gaf. Open ook deze gids:
https://menno420.github.io/curious-research/guides/speling/index.html

Mijn geprinte passing klemt. Help me bepalen of krimp, olifantenvoet of te weinig speling de
oorzaak is. Laat me één variabele tegelijk wijzigen en benoem wat je niet uit de pagina kunt
afleiden.
```

### 4. Controleer of de context werkelijk is gebruikt

De eerste ronde is geslaagd als de AI:

1. Bambu Lab A1, A1 mini en AMS Lite noemt;
2. Bambu Studio, Fusion 360 Personal Use, Arduino IDE en Windows herkent;
3. de zelfgebouwde 6-DOF-arm met MG996R-klasse servo's noemt;
4. geen exact laser-, CNC-, Arduino-board- of servomodel verzint;
5. feiten, aannames en ontbrekende gegevens zichtbaar uit elkaar houdt.

## Zo stel je een goede vraag

Een goede vraag bevat het onderdeel, het doel, wat je ziet of meet en wat niet zomaar mag
veranderen.

**Goed:**

```text
Mijn PETG-beugel scheurt bij het schroefgat. Gebruik mijn werkplaatsprofiel. Help me eerst
bepalen of oriëntatie, wanddikte of passing de oorzaak is. Kies één kleine proef en vertel wat
ik in Bambu Studio Preview en aan het proefstuk moet controleren.
```

```text
Ik wil dit Fusion-onderdeel uit 3 mm plaat maken. Vergelijk laser en CNC voor deze geometrie.
Noem eerst welke gegevens van mijn machines en materiaal nog ontbreken en geef geen universele
feeds, speeds of kerfwaarde.
```

```text
Deze Arduino-sketch mist soms een knopdruk zodra de servo beweegt. Zoek blokkerende
delay()-aanroepen. Herschrijf alleen de timing met millis() en geef een test waarmee het oude en
nieuwe gedrag vergelijkbaar zijn.
```

**Te breed:**

```text
Leg Fusion uit.
```

Maak de vraag bruikbaar met: *welk onderdeel*, *welke productiemethode*, *wat gaat mis* en
*wanneer is het resultaat goed*.

## Wat GitHub hier precies toevoegt

GitHub is de centrale plek voor bestanden plus hun wijzigingsgeschiedenis. Daardoor kun je
Claude en ChatGPT dezelfde actuele bron geven en later terugzien waarom iets veranderde. De
website is de leesbare voorkant van die bron.

GitHub geeft AI echter geen automatisch geheugen:

- een assistent moet de URL werkelijk openen of de tekst van jou krijgen;
- een chatantwoord verandert geen repositorybestand;
- eerder geüploade bestanden verversen niet vanzelf wanneer `main` wijzigt;
- dezelfde context kan nog steeds tot verschillende adviezen leiden.

Lees voor de volledige uitleg
[`git-for-makers.md`](git-for-makers.md) of de publieke pagina
<https://menno420.github.io/curious-research/github-en-ai.html>.

## Waardevolle kennis bewaren

Een antwoord wordt pas duurzame werkplaatskennis na deze lus:

1. **Test het advies** aan machine, werkstuk of simulatie.
2. **Noteer de omstandigheden:** machine, materiaal, relevante instelling, meting en datum.
3. **Vraag waar het thuishoort:** profiel, bestaande gids of projectlog.
4. **Laat een gecontroleerde repositorywijziging maken.** Dat kan voorlopig via de beheerder;
   de maker hoeft daarvoor geen eigen account te hebben.
5. **Lees het verschil na** en merge alleen na groene controles.

Handige vervolgopdracht:

```text
Dit resultaat is op de echte werkplaats bevestigd. Vat exact samen wat is gemeten, onder welke
omstandigheden en wat nog niet bewezen is. Stel daarna voor welk bestaand repositorybestand
moet worden bijgewerkt; dupliceer geen hardwarefeiten.
```

Bewaar geen namen, adressen, toegangssleutels, privéfoto's of andere gevoelige gegevens in deze
openbare repository.

## Optioneel: vaste projectcontext in de browser

Als de gebruikte Claude- of ChatGPT-versie projectmappen en bestandsuploads aanbiedt, kun je een
project **Mijn werkplaats** maken en minimaal toevoegen:

1. `docs/workshop-profile.md`;
2. de relevante gids of projectdocumentatie;
3. deze instructie:

```text
Antwoord standaard in het Nederlands. Gebruik alleen bevestigde hardwarefeiten uit
workshop-profile.md, benoem aannames en sluit af met een zichtbare of meetbare controle.
```

Behandel geüploade bestanden als snapshots. Wanneer GitHub verandert, controleer je zelf of het
projectbestand opnieuw moet worden geüpload. De officiële Claude-uitleg over Projects staat op
<https://support.claude.com/en/articles/9519177-how-can-i-create-and-manage-projects>.

## Later pas: de hele repository lokaal gebruiken

Een lokale clone en Claude Code worden pas nuttig wanneer de maker zelf bestanden wil wijzigen
of de volledige repository als lokale context wil gebruiken. Een eigen GitHub-account is zelfs
dan niet nodig om de openbare repository als ZIP te downloaden, maar wordt wel handig voor eigen
branches en pull requests.

### Download als ZIP

1. Open <https://github.com/menno420/curious-research>.
2. Klik **Code → Download ZIP**.
3. Kies in Verkenner **Alles uitpakken**.
4. Bewaar de map bijvoorbeeld onder `Documenten\curious-research`.

GitHub beschrijft ZIP en clone hier:
<https://docs.github.com/en/repositories/working-with-files/using-files/downloading-source-code-archives>.

### Claude Code op Windows, alleen wanneer die route gewenst is

1. Open PowerShell.
2. Installeer volgens de actuele officiële instructie, bijvoorbeeld met:

```powershell
winget install Anthropic.ClaudeCode
```

3. Open de uitgepakte repositorymap in Verkenner.
4. Typ `powershell` in de adresbalk.
5. Start `claude` vanuit precies die map.
6. Laat `CLAUDE.md` en `docs/workshop-profile.md` samenvatten vóór de eerste taak.

Actuele officiële installatie: <https://code.claude.com/docs/en/setup>.

## Veelgemaakte fouten

- aannemen dat een AI een gedeelde URL heeft gelezen zonder dat te controleren;
- alleen de website noemen en niet het concrete profiel of de relevante pagina delen;
- een goed klinkend antwoord als werkplaatsfeit bewaren vóór een fysieke test;
- een waarde op meerdere pagina's kopiëren in plaats van de canonieke bron te wijzigen;
- denken dat GitHub, Claude Projects of ChatGPT-projectbestanden automatisch synchroniseren;
- de optionele clone- en installatieroute als voorwaarde voor de eerste vraag behandelen.

## Wanneer vraag je de AI om hulp?

- *“Welke bevestigde context heb je werkelijk uit de gedeelde bron gelezen?”*
- *“Welke ontbrekende hardware-informatie kan jouw advies nog veranderen?”*
- *“Maak van dit advies een proef met één variabele en een succescriterium.”*
- *“Vat mijn meetresultaat samen zodat de repositorybeheerder het controleerbaar kan bewaren.”*
