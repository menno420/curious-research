# Robotarm — bevestigde context, kalibratie en startupgedrag

De canonieke werkplaatsgegevens staan in
[`docs/workshop-profile.md`](../docs/workshop-profile.md). Deze map bewaart alleen de
arm-specifieke meetgegevens die de bewegingsprojecten nodig hebben.

## Wat is bevestigd?

- Een zelfgebouwde 6-DOF-robotarm met zes `MG996R`-klasse hobbyservo's.
- De arm is door de maker zelf gebouwd; huidige controller, pinvolgorde en operationele toestand
  zijn nog niet opnieuw bevestigd.
- De exacte servovariant, voeding, verdeling, zekeringwaarden en externe positieterugmelding zijn
  nog niet schriftelijk bevestigd.
- De bestaande softwarelabels `base`, `shoulder`, `elbow`, `wrist_tilt`, `wrist_rotate` en
  `gripper` zijn een oude schema-aanname. Of deze zes labels en hun volgorde overeenkomen met de
  werkelijke 6-DOF-opbouw is nog niet bevestigd.

Gebruik daarom geen verkoopcijfers alsof zij aan deze zes servo's zijn gemeten. Het ruwe
onderzoek staat in [`research/dossiers/servos.md`](../research/dossiers/servos.md) en
[`research/dossiers/servos-gemini.md`](../research/dossiers/servos-gemini.md); claims die
hieruit worden overgenomen krijgen opnieuw een label volgens
[`docs/knowledge-policy.md`](../docs/knowledge-policy.md).

## Wat lost kalibratie op?

`calibration.json` legt per gewricht een gemeten minimale hoek, maximale hoek en middenstand
vast. De penplotterworkflow gebruikt die waarden om ieder aangevraagd hoekgetal naar het
gemeten bereik terug te snoeien.

Dat helpt tegen **numerieke opdrachten buiten het gemeten bereik**. Het detecteert niet:

- of een servo de gevraagde hoek werkelijk heeft bereikt;
- een nieuw werkstuk, gereedschap, kabel of obstakel in de baan;
- doorbuiging, speling, belasting of een losse koppeling;
- een verkeerde meting;
- beweging die firmware al tijdens het opstarten veroorzaakt.

Daarom heet dit gecontroleerde bediening, geen bewijs van hardwareveiligheid.

## Belangrijke startupwaarschuwing voor de penplotter

De huidige [`pen_plotter_arm.ino`](../projects/arm-pen-plotter/pen_plotter_arm.ino) doet in
`setup()` voor alle zes gewrichten het volgende:

1. de servo koppelen met `attach()`;
2. het interne bereik voorlopig op 90°–90° zetten;
3. `servo.write(90)` versturen;
4. pas daarna wachten op gemeten limieten vanaf de laptop.

Een reset of het openen van de seriële verbinding kan dus **eerst een 90°-opdracht geven**.
Negentig graden is niet op deze arm als veilige gezamenlijke startupstand geverifieerd. De
latere weigering van een `S`-commando zonder limieten maakt die eerste opdracht niet ongedaan.

Gebruik dit project daarom niet alsof het een hardware-interlock heeft. De besturingsworkflow
vereist kalibratie vóór gecontroleerde beweging, maar de fysieke arm kan bij startup toch
bewegen. Een toekomstige codewijziging moet dit startupgedrag op de echte arm oplossen en
testen voordat de documentatie een sterkere garantie mag geven.

## Kalibratiebestand maken op Windows

1. Zet de servovoeding uit.
2. Open `arm` in Windows Verkenner.
3. Selecteer `calibration.example.json` en druk **Ctrl+C**, daarna **Ctrl+V**.
4. Hernoem de kopie naar `calibration.json`.
5. Meet één gewricht tegelijk volgens
   [`guides/arm-werkgebied/guide.md`](../guides/arm-werkgebied/guide.md).
6. Bevestig eerst welk fysiek gewricht bij ieder bestaand softwarelabel en pinindex hoort.
7. Vul alleen werkelijk gemeten `min`, `max` en `center` in.
8. Laat geen `_status: PLACEHOLDER` staan.
9. Bewaar machinegegevens zonder naam, adres of andere persoonlijke informatie.

**Documentatie gereed als:** ieder gewricht drie herleidbare waarden heeft en
`min < center < max` geldt. Markeer ze als experiment totdat een gecontroleerde startup bestaat
en de waarden onder toezicht rustig zijn getest zonder brommen, persen, kabelspanning of botsen.

## Regels voor bewegingsprojecten

- Nieuwe bewegingen gaan via één centrale begrenzer en beginnen langzaam, één gewricht tegelijk.
- De maker kijkt mee en houdt de voedingsschakelaar bereikbaar.
- Servo's gebruiken een aparte voeding binnen de specificatie van de werkelijke servovariant,
  met gedeelde massa, passende beveiliging en bereikbare uitschakeling; nooit de 5V-pin van het
  Arduino-bord. De huidige voedingsgegevens zijn nog niet vastgelegd.
- Een gewijzigde arm, grijper, kabelroute of montage maakt een oude kalibratie verdacht: opnieuw
  controleren en zo nodig opnieuw meten.
- Placeholder- of internetwaarden worden nooit als werkplaatsmeting vastgelegd.
- Documentatie noemt expliciet het startupgedrag van de gebruikte sketch.
