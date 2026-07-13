# Feed your drawer's measurements, get bins that fit — with Gridfinity as the honest default and a custom generator only where it earns its keep

> **State:** grown — full ritual, 2026-07-13. **Verdict: build** (the deliberately tiny version — one bin, one drawer corner). See the end.

Original one-liner: *"Feed a CSV of drawer measurements, get a fitted bin set per drawer."*

Bench terms up front — **OpenSCAD**: a free CAD program where the shape is written as a little script, so a size is just a variable like `drawer_width = 210;`. Change the number, hit render, the model updates. That is what makes "measurements in → printable bin out" possible ([openscad.org](https://openscad.org/)).

## 1 · What is this thing, really?

A small OpenSCAD script — one Claude writes from the numbers you measure — that turns *"here is the empty space inside my drawer and the compartments I want"* into bins sized to drop into **that exact drawer**.

## 2 · What could it grow into?

Measure any drawer, get a set that uses every millimetre; labelled slots; a saved little library of your drawers' shapes. The same "measure → generate" loop then aims at tool trays, screw-sorting drawers, and parts trays for the robot-arm bench. The fun ceiling is that once the pattern works for a drawer, it works for almost any "I need a fitted holder for X."

## 3 · What's the coolest version of the simplest build?

**One** bin, fitted to **one** corner of **one** drawer. You measure three numbers (the leftover width, the leftover depth, how tall you want it), tell Claude, and get a ~30-line `.scad`. You render it to an STL, slice it, print one bin overnight — and the next morning it drops in and fits. The whole idea proven in a single print, no commitment to a full set.

## 4 · What breaks it? (the honest realities)

**Gridfinity is the elephant in the room.** Gridfinity is a mature, open modular-storage *standard* — a fixed **42 mm × 42 mm** grid with **7 mm** height steps, created by Zack Freedman in 2022 ([intro video](https://www.youtube.com/watch?v=ra_9zU-mnl8), [overview](https://en.wikipedia.org/wiki/Gridfinity)). It has an enormous free ecosystem — "over 10,000 designs on Printables" ([gridfinity.xyz](https://gridfinity.xyz/)) — including ready parametric generators like [gridfinity-rebuilt-openscad](https://github.com/kennetek/gridfinity-rebuilt-openscad). Honest comparison: because Gridfinity snaps to a 42 mm grid it **wastes the edge strips** of an odd drawer (a 400 mm drawer = 9 units = 378 mm, ~22 mm stranded per axis), but its bins are **standard and reusable** — they move between any drawer or baseplate you own. A custom-fit generator is the mirror image: it uses **every millimetre** of one specific drawer, but those bins are **locked to that drawer**. So — custom-fit earns its keep on an **oddly sized or tight drawer where nothing moves again**; **Gridfinity wins** when you have several drawers, want to re-sort later, or just want to print something proven tonight. A fair first version should say "try a Gridfinity generator first; reach for the custom one when the grid genuinely wastes space you need."

**Big flat bins warp.** A wide flat PLA bottom lifts at the corners once the internal layer tension beats the bed's grip ([Prusa: Warping](https://help.prusa3d.com/article/warping_2011)). The fix is a **brim** (a thin skirt fused to the base, ~5 mm+), better first-layer adhesion, and no cold drafts — but a brim costs extra filament and a cleanup/peel step after the print.

**A full set is a weekend of printing, not an afternoon.** Real figures: individual bins run ~**8–50 g** each ([GridPilot filament cost](https://gridpilot.us/blog/gridfinity-filament-cost)); a worked example of a single 400×300 mm drawer set (baseplates + 8 bins + tray) used **480 g of PLA over 12–16 hours**. A large published collection reports **~34 hours across 17 plates** for the full thing ([MakerWorld listing](https://makerworld.com/en/models/2175256-ultimate-standardized-gridfinity-bin-collection) — *listing-reported figure, not one I sliced*). One ~100×100×50 mm bin is roughly **1–2 h and ~30–50 g** — *an interpolated estimate; only slicing the real model gives a firm number.* The lesson: print **one** and judge before committing filament and machine-days to a set.

**Fit is a tolerance problem, and you already have the answer.** FDM prints come out biased — outer sizes ~**0.05–0.15 mm oversize**, holes ~**0.1–0.3 mm undersize** — so a "sliding fit" needs roughly **0.3 mm of designed clearance per side** ([3DPut tolerances](https://3dput.com/complete-guide-to-3d-printing-tolerances-and-fit-getting-perfect-clearance-for-moving-parts/), [AON3D fits](https://www.aon3d.com/applications/engineering-fits-how-to-design-for-3d-printed-assemblies/)). The generator should expose a `clearance` variable subtracted per side so bins drop in instead of jamming. This is exactly what [[tolerance-test-coin]] measures — your printer's real **Snug** clearance feeds straight into this generator as the `clearance` default, instead of guessing.

**Drawers aren't perfect rectangles.** Sides bow, corners round. Measure the **narrowest** point of the opening, not the widest, and let clearance absorb the rest.

## 5 · What does it let me build next?

The whole *pattern* compounds: **measure → plain list → Claude writes a `.scad` → you render/slice/print** is reusable for tool trays, cable holders, arm-parts organizers — anything that has to fit a real object. And the measured numbers become a shared asset (see this session's idea: a `printer-profile.json` every generator reads).

## 6 · What does it need?

- **OpenSCAD**, free ([openscad.org](https://openscad.org/)) — its built-in Customizer even turns the script's variables into slider fields.
- A tape measure or calipers.
- Claude to write and explain the `.scad`.
- Your printer's measured **Snug** clearance from [[tolerance-test-coin]] (or the ~0.3 mm/side default until you have it).
- No new hardware — this is a pure design + print idea.

## 7 · Who does what — me, Claude, or both?

- **You** measure the drawer (only you can — it's your drawer) and you **slice, start, and watch every print**.
- **Claude** writes the `.scad`, names every variable in plain language, and explains what to change. Claude never sends G-code to the printer and never marks a print "safe to run unattended."

## 8 · What's the smallest piece I could finish this weekend?

**One bin, one drawer corner.** Measure the leftover width/depth and pick a height → tell Claude three numbers → get a `one-bin.scad` → render to STL → slice **with a brim and elephant-foot compensation on** → print one → next morning, check it drops in and holds. If it fits, *then* talk about a set.

---

## Verdict: **build** — the tiny version only

Build the **one-bin** version; treat a **full fitted set as parked** behind "prove the fit on one bin first," and honestly consider a Gridfinity generator for anything that doesn't need custom edges.

**First steps (Claude sets these up when you say go):**
1. A `projects/drawer-bin-generator/` with a parametric `one-bin.scad` — variables `drawer_gap_w`, `drawer_gap_d`, `bin_h`, `wall`, `clearance` — and a plain-language note on each.
2. A short **measure-your-drawer** mini-guide: numbered steps, what to measure, and "measure the narrowest point."
3. Wire the `clearance` default to your [[tolerance-test-coin]] **Snug** number once you've recorded it.
4. An animated HTML explainer (`guides/`) showing measurements → variables → a bin dropping into the drawer — motion, so it earns a guide under the teaching doctrine.
5. Only after one bin fits: a `bins.csv → set` stretch, with the ~hours-and-hundreds-of-grams reality stated up front so a whole-drawer run is a choice, not a surprise.

---

*Safety: ordinary desktop FDM printing. Claude designs; you slice, start, and watch every print. Nothing is auto-sent to the printer.*
