# Session — 2026-07-13 — Lithophane night-light guide

> **Status:** `complete`
> **📊 Model:** Opus 4.8 (Claude Opus 4 family). **Venue:** Claude Code on the web (remote container), Curious Research seat.

## What this session did
- Shipped the BUILD verdict from `ideas/lithophane-night-light.md` as `guides/lithophane-night-light/`:
  - `index.html` — self-contained animated explainer (inline CSS/JS, no CDNs, Replay + per-stage captions, dark-mode + reduced-motion aware): thickness → brightness (thick = dark, thin = bright) with a backlight, and why printing vertical beats flat. Carries an honest simplification note (9 columns stand in for thousands of thickness values; brightness is illustrative, not a physics-exact curve).
  - `guide.md` — numbered, slicer-agnostic step-by-step: photo → free web tool (ItsLitho + alternatives) → STL → slice → print, each exact setting in its own copy block with a one-line why (0.12 mm layers, ~0.8–3.2 mm thickness window, vertical, 100% infill, brim, ~30 mm/s). LED/backlight options with a low-voltage "check this yourself" safety note; a clearly separated, honest "full-color HueForge stretch" section (paid software, filament palette, purge-waste numbers). Sources cited as the idea file does.
- Indexed the guide in `guides/README.md`; added a `→ built` state-line to the idea file (ritual record kept intact).

## Context delta
- **main advanced mid-session** to `edf4f90` (PR #14, arm-envelope guide, merged after this branch was cut). Merged `origin/main` into the branch (never rebased a published branch) and resolved the one real conflict — `guides/README.md` — by keeping ALL index lines (temperature-tower, arm-envelope-explained, lithophane-night-light).
- **Slicer-agnostic by necessity:** the owner's slicer is unknown, so Part B names settings, not menu paths. Raised as an open ⚑ question on PR #15 — once he says PrusaSlicer / Bambu Studio / Cura / OrcaSlicer, a click-by-click version follows.
- **Full-color kept as a labeled stretch, not the headline** — faithful to the idea file's verdict: single-color is the near-guaranteed weekend win; HueForge is a genuine but paid, purge-wasteful, palette-dependent v2.
- Safety held: the human slices/starts/watches every print; backlight guidance is low-voltage USB/battery only; nothing marked safe to run unattended.

## 💡 Session idea
- **A lithophane thickness step-wedge — a calibration strip for HIS filament + LED.** Light transmission changes with filament brand, color, and the LED behind it, so the generic ~0.8–3.2 mm window is a starting point, not a guarantee. Print one small part: a row of flat pads stepping 0.8 → 3.2 mm in ~0.3 mm increments, each pad labelled with its thickness, printed vertical. Backlit once, it reveals the exact thinnest-that-still-reads and thickest-that-still-glows for his actual materials — a reusable number he feeds back into every future lithophane. Same "print it once, read it, keep the number" philosophy as `projects/tolerance-test-coin/`, aimed at the lithophane workflow. (Deduped against `ideas/` — not present.)

## ⟲ Previous-session review
- The newest complete card, `2026-07-13-tolerance-test-coin.md`, set a clean bar this session mirrored: honest slicer-agnostic caveats and a "one setting, one reason" teaching shape. This session reused that shape for a pure guide (photo→print), and the 💡 idea above is the natural next rung — turning the coin's "calibration artifact → reusable constant" pattern loose on lithophane thickness. One carry-forward: the coin session had to discover the openscad wall live; nothing comparable bit here because the lithophane workflow is all free web tools + the owner's own slicer, no local render needed.
