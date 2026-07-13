# Tolerance test coin — your printer's real clearance numbers

> A once-per-printer calibration you print, feel by hand, and reuse forever.

**Clearance** = the deliberate air gap you leave between two parts so they actually
fit together. Too little and they weld into one blob; too much and they wobble.
Every printer, filament, and setting has its own true clearance — this coin
measures *yours* so future designs start from fact instead of a guess.

Grown from [`ideas/tolerance-test-coin.md`](../../ideas/tolerance-test-coin.md)
(ritual verdict: **build**).

## What's in here

| File | What it is |
|---|---|
| [`tolerance-test-coin.scad`](./tolerance-test-coin.scad) | The parametric model source (OpenSCAD). Change one line to change the gap range, size, or number of pins. |
| [`print-and-test-guide.md`](./print-and-test-guide.md) | Step-by-step: make the STL → slice → print → feel each hole → turn your readings into a reusable clearance number. |
| [`clearance-results.md`](./clearance-results.md) | A fill-in record. One table per printer + material — your numbers live here. |

> **No STL yet, on purpose.** OpenSCAD isn't installed in the environment that
> generates these files, so the `.stl` couldn't be rendered here. Step 1 of the
> guide shows you exactly how to make it yourself in about a minute (it's one
> menu click). See the guide.

## The 60-second version

1. Make the STL from the `.scad` (guide step 1) and slice it — turn ON
   **elephant foot compensation** (~0.2 mm) first.
2. Print the coin + the 3 loose pins.
3. Push one pin through each hole. Feel: which grips (press), which slides,
   which drops out loose.
4. Write the winning gap in `clearance-results.md`.
5. Tell Claude that number — it becomes the `clearance` constant in every future
   design that has to fit together.

## Safety

Claude designed this model. **You** slice it, load filament, start the print, and
watch it. Nothing here is "safe to print unattended."

## The honest limit

One coin gives you a **strong starting number for that printer + that filament** —
not a universal law. Fit also shifts with temperature, speed, and part shape. Swap
to a very different filament or print much hotter and it's worth re-checking. You
still start far closer than a blind guess. Full reasoning:
[`ideas/tolerance-test-coin.md`](../../ideas/tolerance-test-coin.md), question 4.
