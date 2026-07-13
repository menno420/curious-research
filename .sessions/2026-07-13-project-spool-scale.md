# Session — 2026-07-13 — project-spool-scale (build)

> **Status:** `complete`
> **📊 Model:** Claude Opus 4 family. **Venue:** Claude Code (remote), building
> `projects/spool-weight-scale/` from the `ideas/spool-weight-scale.md` ritual verdict
> (build — the honest spot-check-gauge version).

## What this session is doing

Turning the spool-weight-scale `build` verdict into a real starter kit under
`projects/spool-weight-scale/` — the honest, on-demand "how much filament is left?" gauge,
not an always-on precision shelf display.

- **`projects/spool-weight-scale/spool_scale.ino`** — one staged Arduino sketch with clear
  `#define` switches for three stages: (a) calibrate against a known weight (HX711_ADC flow),
  (b) the honest tare — an in-sketch spool library (name → empty-spool grams; seeded with
  cited examples, "trust your own measured number" front and centre) reporting
  grams-remaining = total − tare, (c) SSD1306 OLED press-to-read standalone mode.
- **`projects/spool-weight-scale/README.md`** — teaching-bar walkthrough: parts + rough
  prices, numbered wiring (load cell → HX711 → Arduino, OLED I2C), the one mechanical
  "check this yourself" caution (don't twist/over-torque the load cell bar), a known-mass
  calibration walkthrough, the weigh-it-empty tare habit, honest framing (spot-check, not a
  live feed).
- **`projects/spool-weight-scale/index.html`** — self-contained animated explainer: load
  cell flexes → HX711 turns strain into a number → calibration maps it to grams → tare
  subtraction gives grams-remaining. Replay + per-stage captions, dark-mode + reduced-motion
  aware, honest-simplification note.
- **`ideas/spool-weight-scale.md`** — State line updated → building as
  `projects/spool-weight-scale/`.

## 💡 Session idea

**Grams → "can I actually print this?"** Turn grams-remaining into the answer the maker really wants. Using filament density + diameter (PLA ≈ 1.24 g/cm³, 1.75 mm ≈ 2.98 g per metre), the sketch converts `~440 g left` into approximate **metres of filament**, and — with one saved grams-per-model number — into "enough for about N more of these." The scale already knows the grams; one small formula makes it answer "is there enough to start this print?" in the unit that matters, on the same OLED. It reuses the exact hardware for a genuinely different question than "how much is left," and it's the natural companion to the ritual card's print-failure-by-grams idea — both turn one weight reading into a decision.

## ⟲ Previous-session review

Predecessor: `.sessions/2026-07-13-ritual-spool-scale.md` (complete) — the idea ritual that grew this one-liner to a `build` verdict. This session executes that verdict into a real project lane, and it deliberately honours the ritual's hard-won honest reframe: an on-demand spot-check + a personal weigh-it-empty tare table, **not** the always-on live-grams display a drifting load cell can't support. It also carries the ritual's crossover thinking forward — this card's grams→metres idea is the weight-world sibling of that card's print-failure-by-grams idea.
