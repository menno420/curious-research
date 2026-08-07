# Claude gebruiken met deze werkplaatsmap

## Welk probleem lost dit op?

In een losse chat moet je steeds opnieuw vertellen welke printers, software en machines je
gebruikt. Als Claude Code in deze map start, leest het `CLAUDE.md` en kan het daarna het
werkplaatsprofiel, de gidsen, projecten en research openen wanneer die relevant zijn.

Belangrijk: iedere Claude-sessie begint met een nieuw contextvenster. `CLAUDE.md` geeft vaste
projectinstructies, maar gewone chattekst wordt niet vanzelf een bestand in deze repository.
Claude Code heeft daarnaast lokale automatische notities; die blijven op die ene computer en
worden niet automatisch met de GitHub-repository of een andere computer gedeeld.

## Wat heb je nodig?

- je Windows-pc;
- je Claude Pro-account;
- internet voor de eerste download en installatie;
- ongeveer tien minuten.

Je hebt voor deze eerste route **geen eigen GitHub-account** nodig. De repository is openbaar.

## Eerste gebruik — aanbevolen route met Claude Code

### 1. Download de werkplaatsmap

1. Open <https://github.com/menno420/curious-research>.
2. Klik op de groene knop **Code**.
3. Klik op **Download ZIP**.
4. Open in Verkenner je map **Downloads**.
5. Klik met rechts op het ZIP-bestand en kies **Alles uitpakken**.
6. Kies bijvoorbeeld `Documenten\curious-research` en klik **Uitpakken**.

GitHub beschrijft dezelfde ZIP-route hier:
<https://docs.github.com/en/repositories/working-with-files/using-files/downloading-source-code-archives>.

### 2. Installeer Claude Code

1. Klik op **Start**.
2. Typ `PowerShell` en open **Windows PowerShell**.
3. Plak deze officiële WinGet-opdracht en druk op **Enter**:

```powershell
winget install Anthropic.ClaudeCode
```

4. Wacht tot de installatie klaar is en sluit PowerShell.

De actuele officiële installatiepagina staat op
<https://code.claude.com/docs/en/setup>. WinGet werkt eenvoudig op Windows, maar werkt niet
automatisch bij. Werk later bij met:

```powershell
winget upgrade Anthropic.ClaudeCode
```

### 3. Start Claude in precies deze map

1. Open in Verkenner de uitgepakte map `curious-research`.
2. Klik in de adresbalk bovenin Verkenner.
3. Typ `powershell` en druk op **Enter**. PowerShell opent nu direct in deze map.
4. Typ:

```powershell
claude
```

5. Volg de browsermelding om met je Claude Pro-account in te loggen.
6. Accepteer alleen de werkmap die je zojuist zelf hebt geopend.

Controleer daarna met deze vraag:

```text
Lees CLAUDE.md en docs/workshop-profile.md. Vertel in het Nederlands in vijf punten welke werkplaatscontext je nu kent en welke gegevens nog ontbreken.
```

**Geslaagd als:** Claude de A1, A1 mini, AMS Lite, Fusion 360, Arduino en de 6-DOF-arm
noemt, én geen onbekend laser- of CNC-model verzint.

De officiële Claude Code-snelstart staat op <https://code.claude.com/docs/en/quickstart>.

## Alternatief — een Claude Project in de browser

Wil je geen programma installeren, maak dan op <https://claude.ai/projects> een project met
de naam **Mijn werkplaats**. Upload met de **+** in elk geval:

1. `docs/workshop-profile.md`;
2. `CLAUDE.md`;
3. de gids of het project dat je op dat moment gebruikt.

Zet bij **Set project instructions**:

```text
Antwoord standaard in het Nederlands. Lees eerst workshop-profile.md. Gebruik alleen bevestigde hardwarefeiten; benoem aannames. Geef genummerde stappen, volledige links en een controle waarmee ik zie of het gelukt is.
```

Projectkennis wordt in alle chats **binnen dat Claude Project** gebruikt. Een bestand dat later
in GitHub verandert, wordt niet vanzelf opnieuw geüpload. De officiële uitleg staat op
<https://support.claude.com/en/articles/9519177-how-can-i-create-and-manage-projects>.

## Zo stel je een goede vraag

Een goede vraag bevat het doel, wat je al ziet of meet, en wat niet mag veranderen.

**Goed:**

```text
Mijn PETG-beugel uit Bambu Studio scheurt bij het schroefgat. Lees het werkplaatsprofiel. Help me eerst bepalen of de oriëntatie, wanddikte of passing de oorzaak is. Geef één test tegelijk en vertel wat ik moet meten.
```

```text
Ik wil dit Fusion-onderdeel uit 3 mm plaat lasersnijden. Geef de workflow van schets naar DXF en testcoupon. Neem geen kerfwaarde aan: laat me die eerst meten.
```

```text
Deze Arduino-sketch mist soms een knopdruk zodra de servo beweegt. Zoek blokkerende delay()-aanroepen, herschrijf alleen de timing met millis() en leg uit hoe ik controleer dat het gedrag gelijk blijft.
```

**Te breed:**

```text
Leg Fusion uit.
```

Maak hem bruikbaar door een doel toe te voegen: *welk onderdeel*, *welke productiemethode* en
*wanneer is het resultaat goed*.

## Waardevolle kennis bewaren

Een chatantwoord is pas werkplaatskennis als het controleerbaar en terugvindbaar is.

1. **Test het advies** aan de machine of in simulatie.
2. **Leg het resultaat vast:** materiaal, machine, relevante instellingen, meting en datum.
3. **Vraag Claude waar het thuishoort:** profiel, bestaande gids, projectlog of nieuwe gids.
4. **Laat Claude alleen het passende bestand bijwerken.** Ruwe research blijft ongewijzigd.
5. **Lees de wijziging na.** Feit en aanname moeten zichtbaar gescheiden zijn.

Handige opdracht:

```text
Dit resultaat is bevestigd op mijn eigen machine. Werk de juiste bestaande pagina bij zonder feiten te dupliceren. Noem de testdatum, omstandigheden en wat nog niet bewezen is. Laat eerst zien welk bestand je wilt wijzigen en waarom.
```

Zonder GitHub-account blijven wijzigingen in de uitgepakte map op deze pc staan. Maak geregeld
een kopie van die map. Met een later GitHub-account kan de geschiedenis online worden bewaard,
maar dat is niet nodig om vandaag te beginnen.

## Veelgemaakte fouten

- Claude starten vanuit `Downloads` in plaats van uit de uitgepakte `curious-research`-map;
- aannemen dat een losse chat automatisch alle repositorybestanden heeft gelezen;
- een antwoord als feit opslaan vóór de test;
- een waarde op meerdere pagina's kopiëren in plaats van het canonieke profiel bij te werken;
- een machinebestand als master bewaren terwijl het Fusion-model de ontwerpbron hoort te zijn.

## Wanneer vraag je Claude om hulp?

- *"Controleer met `/context` of de CLAUDE.md uit deze map is geladen."*
- *"Welke bevestigde gegevens mis je nog om dit advies voor mijn machine te geven?"*
- *"Zet dit testresultaat op de juiste plek en label het volgens docs/knowledge-policy.md."*
- *"Vergelijk mijn nieuwe meting met het vorige projectlog en verander maar één hypothese."*

