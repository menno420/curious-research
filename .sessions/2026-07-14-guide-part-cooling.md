# Session — 2026-07-14 — guide-part-cooling (part-cooling fan % explainer)

> **Status:** `in-progress`
> **📊 Model:** opus-4.8 (Claude Opus family). **Venue:** a dispatched work session for the Curious Research seat, building on the coordinator's baton.

## What this session did

Shipping the part-cooling (fan %) visual guide — the invisible slicer setting behind droopy overhangs, saggy bridges, melted small points, and (for PETG) brittle layers. Creates `guides/part-cooling/index.html` (self-contained animated explainer: overhang drooping with no fan vs holding with fan, a tower point going molten-blob vs crisp with minimum-layer-time, and the PLA-loves-max / PETG-wants-less material fork) and `guides/part-cooling/guide.md` (the one-value fan 0/50/100 % experiment, minimum layer time, reading droop/blobs/stringing, a per-material fan table with whys, cited sources), plus one index row in `guides/README.md`. Slicer-agnostic with ⚑ flags per the first-layer bar. Honors CLAUDE.md §1 (teaching doctrine) and docs/teaching-style.md.

## 💡 Session idea

**A "cooling budget" mental model** — instead of memorizing per-material fan numbers, the owner could think of cooling as a budget he spends against two competing goals: *shape* (freeze fast, more fan) and *strength* (fuse slowly, less fan). PLA has strength to spare so it spends the whole budget on shape; PETG must hold some back. A future guide could turn that one sentence into the through-line for every material setting, not just fan.

## ⟲ Previous-session review

Predecessor: `.sessions/2026-07-14-current-state-refresh.md` (refreshed docs/current-state.md snapshot through #37, shipped as #38). This session picks up the possibility-dossier Part 2 ladder — part-cooling is entry #4, the next one-value slicer experiment after the first-layer (#36) and temperature-tower guides. Workflow note: the recon-worker-first pattern (gather every sibling template verbatim before writing a line) kept this guide structurally identical to first-layer/temperature-tower with no drift.

## Context delta

New surface: `guides/part-cooling/` (this session creates it) — holding `index.html` (the animated explainer) and `guide.md` (the walkthrough). One new row added to `guides/README.md`. No kit-owned or `adopt` files touched; this session stays in the `guides/` lane plus this session card and the work claim in `control/claims/`.
