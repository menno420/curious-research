# Retraction vs stringing — why prints grow hairs, and how to stop it

**Watch it instead:** open [`index.html`](./index.html) in your browser — it animates this
whole page in ~15 seconds, showing the hot end cross a gap six times. (On GitHub: tap
`index.html` → the **⋯** menu → *Download*, then open the downloaded file in any browser. Or
view the repo in any Codespace/preview and open it there.)

## In bench terms

1. **Pressure builds up.** While the **nozzle** (the metal tip the plastic flows out of) lays
   down a wall, the motor keeps pushing filament in like a piston. That squeezes the melted
   plastic in the little **hot pocket** just above the hole — it is under pressure, primed to
   flow. That pressure is the whole story: it does not switch off the instant the motor stops.
2. **No retraction → a string.** When the nozzle finishes a part and has to cross an open gap
   to the next one, it makes a **travel move** (moving without printing). The motor stops
   pushing, but the pocket is still pressurized, so plastic keeps oozing out of the tip. The
   nozzle drags that ooze across the gap and it cools into a thin hair. That is **stringing**.
3. **What retraction does.** **Retraction** is the printer briefly pulling the filament
   *backward* just before a travel move. That relieves the pressure in the pocket and draws
   the plastic back from the tip, so the oozing stops. The point is *relieving pressure* — not
   sucking plastic far up the tube.
4. **Just-right → a clean gap.** With the pressure released, the nozzle crosses the gap
   trailing nothing. On arrival it pushes the filament back in — a **prime** — to
   re-pressurize before printing again. How far it must pull depends on the printer:
   a **direct-drive** machine (motor sitting right on the nozzle) needs only a tiny tug, about
   0.5–2 mm; a **Bowden** machine (motor pushing the filament through a long springy PTFE tube)
   needs a bigger pull, about 4–7 mm, just to take up the tube's slack first.
5. **Too much → new problems.** Overshoot and you swap one defect for another. Pull too far and
   molten plastic gets dragged up into the cooler part of the hot end, hardens, and jams —
   this is **heat creep**. On the next printed line you then get a gap (**under-extrusion**) or
   a blob where the prime didn't quite re-pressurize in time, and yanking too hard or too fast
   can grind a flat spot into the filament so the gear slips (you'll hear a *click*). More is
   not better — you are hunting for the balance point.
6. **Find your number: the stringing tower.** To dial it in, print a **stringing tower**: two
   thin pillars with a gap between them, so the nozzle must cross open air on every layer and
   any ooze shows up as a visible hair. Sweep the retraction value up the height in small steps
   (about 0.5 mm per band for Bowden, 0.2 mm for direct drive). Then read it top-to-bottom:
   lots of strings means too little; clean but with blobs or a clicking sound means too much;
   pick the value where the strings just vanish.

## Which numbers do I start from?

These are **starting points to tune from, not final truth** — every printer, filament brand,
and even filament colour is a little different. Start here, then let the tower (below) tell you
the real number for *your* setup.

| Setting | PLA · direct drive | PLA · Bowden | PETG · direct drive | PETG · Bowden |
|---|---|---|---|---|
| Retraction distance | 0.5–1.5 mm (start ~0.8) | 4–6 mm (start ~5) | 1.5–2 mm (start ~2) | 4–7 mm (start ~6) |
| Retraction speed | 30–45 mm/s | 40–60 mm/s | 25–40 mm/s | 25–40 mm/s |
| Nozzle temp | 195–215 °C | 195–215 °C | 230–245 °C | 230–245 °C |
| Travel speed | 150–250 mm/s | 150–250 mm/s | 150–200 mm/s | 150–200 mm/s |

PETG strings much more than PLA because it stays gooey over a wider temperature range — expect
to fight it harder, and read the "if strings persist" note below before blaming your settings.

## Try it now (2 minutes, just your browser)

1. Open [`index.html`](./index.html) (download it, or preview it — see the top of this page).
2. Press **Next step ▶** and walk through it one stage at a time instead of watching it play.
3. On **step 2**, watch the red string appear across the gap while the melt pocket is still
   glowing — pressure with nowhere to go.
4. On **step 3**, watch the glow *fade* as the filament pulls back — that is retraction
   releasing the pressure.
5. On **step 4**, watch the nozzle cross the *same* gap trailing nothing. That is the whole
   lesson in one frame: same travel, pressure released, no string.
6. Press **↻ Replay** any time to run it again from the top. No printer required — you now know
   what the slider does before you touch it.

## The real experiment: print a stringing tower

This is the part that actually fixes your prints. It is slicer-agnostic — the same idea works
in every slicer; only the menu names differ.

1. **Find the settings.** In your slicer (Cura, PrusaSlicer, OrcaSlicer or Bambu Studio), type
   `retraction` into the settings **search box** to find **Retraction distance** and
   **Retraction speed**. (Every one of those slicers has a search box precisely so you don't
   have to know which menu a setting lives in.)
2. **Get a test tower.** Use your slicer's built-in calibration/tower tool if it has one —
   OrcaSlicer and Bambu Studio ship **retraction/stringing calibration** generators, and
   PrusaSlicer/Cura support **height-range modifiers** that change one setting as the print
   gets taller. That lets you sweep a single value up one print. **Low-tech fallback:**
   download any small "stringing test" model (two thin pillars with a gap) and print it several
   times, changing only the retraction distance each time.
3. **Sweep one value, in small steps.** Change **only retraction distance**, nothing else, so
   you're testing one thing. Use small steps: about **0.5 mm per band for Bowden**, **0.2 mm
   for direct drive**. Leave temperature and speed at your starting-table values for now.
4. **What to look for** as it prints and when you take it off the plate:
   - **strings** — fine hairs spanning the gap between the pillars (the headline symptom);
   - **blobs / zits** — little bumps where each pillar *starts* (a sign of too much retraction
     over-priming);
   - **a clicking sound** during retraction — the extruder gear skipping because you're pulling
     too hard or fast, grinding the filament.
5. **How to read it (top-to-bottom):**
   - Lots of strings → retraction is **too little** → increase it.
   - Clean but with blobs, or you heard clicking → **too much** → back off one step.
   - Pick the value where the **strings just vanish** but the blobs/clicking haven't started.
     That's your number. Set it as your default for that filament.
6. **If strings persist at *every* value**, retraction isn't the culprit — two real causes:
   - **Temperature too high.** Hotter plastic is runnier and oozes more. Drop the nozzle
     5–10 °C, or run a **temperature tower** (a print that steps temp down in 5 °C bands) to
     find the coolest temp that still bonds well.
   - **Damp filament — the big one.** Plastic absorbs water from the air; when that water hits
     the hot nozzle it flashes to steam and sprays fine strings and sputter no matter how
     perfect your retraction. **PETG especially is hygroscopic** (water-loving). Dry the
     filament (a filament dryer, or a few hours in an oven at ~45–55 °C for PLA / ~60–65 °C for
     PETG) and re-test. Dry filament first, *then* trust the tower.

One note for your 3-colour printer: a **colour change** forces a full **purge/prime tower**
(the printer flushes the old colour before printing the new one). That's a different ooze
problem from travel stringing — it's about clearing the melt zone, not crossing a gap — but
it's the same underlying physics of pressure and how runny the melt is.

**Verify:** On your next real print, the gaps between separate features come out bare — no fine
hairs to pick off.

## A safety check you do yourself

The hot end runs **200–250 °C** and will burn you on contact; the motors and heaters carry real
power. Claude can explain the physics and walk you through the slicer, but **you** power the
printer, **you** slice, and **you** start and watch every print yourself. A first layer going
wrong is the most common way a print fails or a nozzle clogs — never leave one running
unattended on the strength of a guide, including this one.

## Sources

Physics and starting values cross-checked against:

- Simplify3D — Print Quality Troubleshooting: Stringing or Oozing —
  <https://www.simplify3d.com/resources/print-quality-troubleshooting/stringing-or-oozing/>
- Ellis' Print Tuning Guide — Retraction —
  <https://ellis3dp.com/Print-Tuning-Guide/articles/retraction.html>
- Bambu Lab Wiki — Stringing / Oozing —
  <https://wiki.bambulab.com/en/filament-acc/filament/print-quality/stringing-oozing>
- Prusa Knowledge Base — Stringing and oozing —
  <https://help.prusa3d.com/article/stringing-and-oozing_1805>
- MatterHackers — Filament and Water (why damp filament strings) —
  <https://www.matterhackers.com/news/filament-and-water>
- All3DP — 3D Print Stringing: Easy Ways to Prevent It —
  <https://all3dp.com/2/3d-print-stringing-easy-ways-to-prevent-it/>

*Tell us which slicer you use (Cura / PrusaSlicer / OrcaSlicer / Bambu Studio) and a follow-up
guide can name the exact menu clicks for your machine.*
