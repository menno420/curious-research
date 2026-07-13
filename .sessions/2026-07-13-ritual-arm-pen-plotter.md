# Session — 2026-07-13 — ritual-arm-pen-plotter (idea ritual)

> **Status:** `complete`
> **📊 Model:** Claude Opus 4 family. **Venue:** Claude Code (remote), running the idea
> ritual on `ideas/arm-pen-plotter.md` and landing the result against `main`.

## What this session did

Ran the idea ritual on the arm pen-plotter one-liner — grown in place with cited
research, ending in one verdict.

- **`ideas/arm-pen-plotter.md` → ritual COMPLETE, verdict `build`** — grew the "arm +
  printed pen holder draws pictures, Claude converts drawings to clamped safe motion
  scripts" one-liner through all 8 questions with real sources (BrachioGraph, SG90/MG996R
  servo deadband + backlash numbers, ikpy, compliant pen-holder STLs, svg2gcode/vpype).
  The honest framing: hobby-servo slop stacks along the arm into visibly wobbly lines, so
  the goal is *charming line art*, not a precise printer — and the first demo is a single
  straight line, then a square, then a circle, NOT portraits.
- **Safety sequencing is visible in the dossier and the verdict:** calibration comes
  BEFORE any drawing code — step 1 is create `arm/calibration.json` from the owner's own
  measured servo min/max/center (via `guides/arm-envelope-explained/`), then a clamped
  teach-mode recorder, and no motion runs until the clamp exists. External fused servo
  supply, human watching every move.
- **Printer↔arm crossover named explicitly:** the printed compliant (spring/gravity) pen
  holder is the physical bridge between the two hobbies.
- `ideas/README.md` left untouched (mirrors the grown-lithophane convention — the row
  stays a one-liner).

## 💡 Session idea

A printed **"servo-slop gauge"** — have the arm draw the same square ~10 times in a row and
overlay the passes, so the deadband and backlash of each joint show up as visible line-spread
(fat, fuzzy edges where a precise machine would draw one crisp line). It turns arm calibration
into a *see-it* test print — the arm's answer to the printer's tolerance-test-coin — and gives
an honest before/after when you tighten joints or refit the pen holder. Bonus: the spread at
each corner points at *which* joint is the worst offender, since corners are where joints
reverse and backlash bites hardest.

## ⟲ Previous-session review

Predecessor: `.sessions/2026-07-13-guide-temperature-tower.md`, which landed the
temperature-tower guide (animated explainer + numbered walkthrough + index row) as the
first-touch print-quality dial — a clean, in-lane trace this session builds on by turning
another seeded one-liner into a durable ritual verdict.

## Context delta

Everything needed comes from the seeded repo itself: `docs/idea-ritual.md` (the 8-question
ritual), the `ideas/arm-pen-plotter.md` one-liner, and cited web research folded into the
idea file. No new machinery introduced — this session edits `ideas/arm-pen-plotter.md`,
adds this session card, and files a work claim.
