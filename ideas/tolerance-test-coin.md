# Tolerance test coin — calibration that compounds

> **State:** grown via the ritual (2026-07-13) → verdict: build → **built** (2026-07-13)

Print one small coin covered in test gaps (a "clearance" set — the deliberate air gap left between two parts so they fit), write down which gaps actually fit, and Claude keeps your printers' real tolerance numbers on file so every future design starts from *your* machine's truth instead of a guess.

## Built (2026-07-13)

Now a real project: **[`projects/tolerance-test-coin/`](../projects/tolerance-test-coin/)** — a parametric OpenSCAD coin, a step-by-step print-and-test guide, and a fill-in results record. Watch the idea move: [`guides/how-print-clearance-works/`](../guides/how-print-clearance-works/).

## The 8 questions

**1. What is this thing, really?**
A once-per-printer calibration coin: a small disc with a row of pegs-and-holes (or rings) at known gaps like 0.10, 0.15, 0.20 … 0.50 mm, printed so you can feel which gap gives a press fit, which slides, and which is loose — then those numbers become constants you reuse forever. It is the widely-used "tolerance test" idea in coin form; models like [A_Str8's Printer Tolerance Test](https://www.printables.com/model/10116-printer-tolerance-test) and [3DMakerNoob's Clearance Tolerance Test](https://www.printables.com/model/116911-clearance-tolerance-test) on Printables do exactly this — the markings tell you the clearance in millimetres for each hole, and you push the pegs in to feel the fit.

**2. What could it grow into? (the fun ceiling)**
A per-printer, per-material "fit profile" that Claude reads before generating any part with a moving joint, snap, lid, or press-fit pin — so the arm's servo horns, a printed hinge, a battery lid, or a box that actually closes all come out right on the first print. The ceiling: a tiny library where you say "make this a sliding fit in PLA on the small printer" and the correct gap is filled in automatically. Tolerance is the hidden reason most first prints of mating parts fail; owning your numbers removes that failure class.

**3. What's the coolest version of the simplest build?**
One coin per printer (small printer + multi-material printer = two coins), printed in your default PLA (polylactic acid — the common cornstarch-based filament) at your normal layer height. On the coin: pegs at 0.10–0.50 mm gap in 0.05 mm steps, each gap engraved next to it. You test by hand, tell Claude three numbers — the tightest gap that presses in and holds, the gap that slides with no wobble, the gap that drops in loose — and you are done.

**4. What breaks it? (printability, tolerance, torque, time, physics)**
The honest caveat: **one coin does not generalize perfectly.** Real fit depends on material, temperature, print speed, part geometry, and orientation — the tolerance guides say so directly ("your results will depend on printer quality, calibration, filament brand, temperature, and print orientation," [3dprintcalcs.uk](https://3dprintcalcs.uk/reference/common-tolerances/)). Two more traps:
- **Elephant's foot** (the first layer squishing wider than the rest because the nozzle presses it into the hot bed) fattens the bottom of every peg and hole, skewing tight fits. Both PrusaSlicer and Bambu Studio have an "elephant foot compensation" that shrinks the first layer to fix this; Prusa says "values around 0.2 mm usually work well for the default 0.4 mm nozzle" ([Prusa Knowledge Base](https://help.prusa3d.com/article/elephant-foot-compensation_114487)).
- **Clearances are per side.** A 0.20 mm clearance means 0.20 mm of gap on *each* side, so the total gap between two parts is 0.40 mm ([3dprintcalcs.uk](https://3dprintcalcs.uk/reference/common-tolerances/)). Getting this wrong is the classic "why is it twice as loose as I expected" mistake.

Because of all this, the coin gives you a *strong starting number per material*, not a universal constant. Change filament brand or print much hotter and it is worth re-checking. That is a real limit, not a dealbreaker — you still start far closer than a blind guess.

**5. What does it let me build next? (does it compound?)**
Strongly yes — this is the whole point. Once you know your numbers, they drop straight into CAD as a single reusable variable. In OpenSCAD (a text-based 3D modelling tool where you describe shapes in code) you set `clearance = 0.20;` once and every hole in every future design uses it; change printers and you change one line. Typical anchor values the guides converge on, per side: **press fit ≈ 0.0–0.1 mm, snug/push fit ≈ 0.1–0.2 mm, sliding fit ≈ 0.15–0.3 mm, loose fit ≈ 0.4–0.5 mm** ([3dprintcalcs.uk](https://3dprintcalcs.uk/reference/common-tolerances/), [X3D Studios](https://x3dstudios.com/blog/3d-printing-tolerances-guide)). Every later project with a joint — hinges, the robot arm's mounts, enclosures, snap lids — inherits these for free.

**6. What does it need? (parts, filament, libraries, skills)**
- A tolerance-test STL (free — download one, or Claude generates a coin in OpenSCAD).
- A little filament and ~15–30 min print time; the simple tests are famously fast (joncruz's [Basic Tolerance Test](https://www.printables.com/model/903911-basic-tolerance-test) is ~18 minutes on an Ender 3).
- No new hardware. A caliper is a nice-to-have for measuring but not required — the coin is designed so you judge fit by hand.
- Skill: none beyond "print a thing and press pegs." Recording the result is the whole exercise.

**7. Who does what — me, Claude, or both?**
- **You:** print the coin on each printer, feel the fits, report the winning gaps to Claude.
- **Claude:** picks or generates the coin, explains elephant's foot and per-side clearance up front so the readings are trustworthy, and — the compounding part — records your numbers as maintained constants and injects them into every future design's `clearance` variable, per printer and per material.
- **Both:** re-run a quick check when you switch to a new filament and Claude updates the stored constant.

**8. What's the smallest piece I could finish this weekend?**
Print one coin on the small printer in default PLA, test it by hand, and give Claude the sliding-fit gap. That single number already makes the next joint-based print more likely to fit. Everything else (second printer, second material, the OpenSCAD variable) can follow later.

## Verdict

**build.**

Cheap, fast, needs no new gear, and it directly removes the most common first-print failure for anything that has to fit together — with an honest, stated limit (one coin is a strong per-material starting point, not a universal law). It compounds better than almost any other idea in the folder: one afternoon of testing pays off in every joint you ever print.

First steps Claude will set up:
1. Generate (or pick) a tolerance-test coin STL and hand you a print-ready file for the small printer, with slicer notes including turning on elephant-foot compensation (~0.2 mm).
2. A one-page "how to read the coin" guide — press vs. snug vs. sliding vs. loose, and the per-side clearance gotcha.
3. A tiny record file (per printer, per material) where your measured gaps live, plus a reusable `clearance` variable pattern so future OpenSCAD designs pull your real numbers automatically.

## Sources

- [3dprintcalcs.uk — Common tolerances / fit guide](https://3dprintcalcs.uk/reference/common-tolerances/) (per-material press/snug/sliding values; per-side clearance; "verify on your own printer" caveat)
- [X3D Studios — 3D Printing Tolerances: A Practical Guide](https://x3dstudios.com/blog/3d-printing-tolerances-guide)
- [Prusa Knowledge Base — Elephant foot compensation](https://help.prusa3d.com/article/elephant-foot-compensation_114487)
- [Bambu Lab Wiki — Elephant foot compensation](https://wiki.bambulab.com/en/software/bambu-studio/parameter/elephant-foot)
- [Printables — Printer Tolerance Test by A_Str8](https://www.printables.com/model/10116-printer-tolerance-test)
- [Printables — Clearance Tolerance Test by 3DMakerNoob](https://www.printables.com/model/116911-clearance-tolerance-test)
- [Printables — Basic Tolerance Test by joncruz](https://www.printables.com/model/903911-basic-tolerance-test)
