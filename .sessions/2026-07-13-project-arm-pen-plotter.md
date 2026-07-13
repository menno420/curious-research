# Session — 2026-07-13 — Arm pen-plotter project (starter kit)

> **Status:** `in-progress`
> **📊 Model:** Claude Opus 4 family. **Venue:** Claude Code on the web (remote container), Curious Research seat — build worker.

## What this session is doing

Turning the `ideas/arm-pen-plotter.md` ritual verdict (**build**) into the first
inhabitant of a new lane, `projects/arm-pen-plotter/` — the starter kit for the 6-servo
arm holding a printed spring-loaded pen and drawing charming, wobbly line art. The build
sequences **calibration first, clamp always, human watching every move** — the binding arm
safety rules (CLAUDE.md §2 + the envelope guide) live in the code and the docs, not just as
a note.

Planned deliverables (calibration-first order):

- `teach_and_replay.py` — teach-mode waypoint recorder/replayer. Refuses to start with no
  `arm/calibration.json`; every servo value sent to serial routed through one `clamp()`
  send function — no code path reaches the port unclamped.
- `pen_plotter_arm.ino` — Arduino sketch, clamps on-board too (defense in depth), with the
  external-fused-supply wiring block.
- `pen_holder.scad` — printable compliant (spring/gravity float) pen holder, parametric pen
  diameter, `.scad` source only (OpenSCAD is a verified wall here — owner renders locally).
- `README.md` — teaching-bar walkthrough, calibration-first, honest wobble expectations.
- `index.html` — animated explainer: jog → record waypoint → replay through the clamp.

## 💡 Session idea

*(filled at close-out)*

## ⟲ Previous-session review

*(filled at close-out)*
