# Session — 2026-07-13 — Tolerance test coin project

> **Status:** `in-progress`
> **📊 Model:** Opus 4.8 (Claude Opus 4 family). **Venue:** Claude Code on the web (remote container), Curious Research seat.

## What this session did
- Built the first inhabitant of `projects/` — `projects/tolerance-test-coin/`, the ritual "build" idea turned into a ready-to-slice thing:
  - `tolerance-test-coin.scad` — a clean, fully parametric OpenSCAD clearance coin: a labelled disc of holes from 0.10–0.50 mm radial clearance (per side) plus 3 matching loose pins. Gap range/step/size/pin-count are all one-line edits.
  - `print-and-test-guide.md` — numbered bench-terms walkthrough: make the STL → slice (with elephant-foot compensation) → print → feel each hole → turn the reading into a reusable `clearance` constant. Teaches the per-side gotcha and the per-material caveat; carries the "you slice/start/watch" safety note.
  - `clearance-results.md` — fill-in record, one table per printer + material.
  - `README.md` — project overview + why there's no STL yet.
- Built `guides/how-print-clearance-works/` — an animated explainer of what clearance is, why per-side doubles it, the press→snug→sliding→loose ladder, and elephant's foot. Indexed in `guides/README.md`.
- Updated `ideas/tolerance-test-coin.md` → verdict build **→ built**, linked to the project.
- Recorded a verified capability wall in `docs/CAPABILITIES.md`: no `openscad`/`prusa-slicer`/`slic3r` in this environment, so the STL ships as source + owner instructions, not a rendered binary.

## Context delta
- **STL not rendered here** (openscad absent — new CAPABILITIES finding). Owner makes the STL in one OpenSCAD menu click; the guide's Part A walks it. Never shipped G-code (safety rule).
- `projects/` did not exist — this coin establishes the lane. Kept the flat convention: one folder per build, its docs beside it.
- Design choice: one standard pin + many graded holes (feel press→snug→loose by moving one pin across the row), rather than captive print-in-place pins — gives the graded feel the idea file asked for and prints without supports.

## 💡 Session idea
- The `clearance` constant this coin produces wants a home Claude reads automatically. Next: `clearance-results.md` → a repo-level `clearance.scad` include file, so future OpenSCAD designs `include <clearance.scad>` and inherit the owner's real numbers with zero copy-paste.

## ⟲ Previous-session review
- The retraction-guide session set a clean bar to mirror: same "print this and read it" teaching shape, honest slicer-agnostic caveats. This session reused that shape for a physical calibration artifact instead of a pure guide — the natural next rung. Workflow nit: the openscad wall should have been in CAPABILITIES already from an earlier gear session; it is now, so no future session re-discovers it.
