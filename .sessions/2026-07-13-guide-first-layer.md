# Session — 2026-07-13 — guide-first-layer (the foundation everything is built on)

> **Status:** `in-progress`
> **📊 Model:** opus-4.8 (Claude Opus family). **Venue:** a dispatched work session for the Curious Research seat, EAP final-night ladder slice 6.

## What this session did

Shipped the **first-layer guide** under `guides/first-layer/` — an animated HTML explainer
(`index.html`) that *shows*, in side-view cross-section, what makes a first layer stick or fail:
the nozzle-to-bed gap (too far → round un-pressed noodle that pops off; too close → torn,
under-extruded ridges with an elephant's-foot bulge; just right → a slight squish welded into one
solid sheet) and first-layer speed (fast drags a weak thin line, slow presses a strong bond). It
shipped with a numbered, jargon-glossed `guide.md` walkthrough that starts from the honest #1 fix
(a clean bed), walks the paper-drag level / Z-offset, the one-value experiment (halve first-layer
speed), a one-layer test print, reading the squish three ways, live baby-step Z nudges, bed
temperature per material, and a brim — plus one new row on `guides/README.md` so the explainer is
discoverable from the guides lane.

The first layer is the #1 beginner failure point: it's the layer of glue every other layer stands
on, and nailing it makes ~90% of print failures vanish — a change-one-value-and-look experiment in
the house teaching style (CLAUDE.md §1, `docs/teaching-style.md`).

## 💡 Session idea

**A Claude-assisted first-layer check.** Photograph your finished first-layer test square, describe
what you see, and Claude reads it against the three squish patterns in this guide and tells you
which way to nudge the Z-offset — up or down, and roughly how much. It turns "read the squish"
from a skill you have to build into a two-minute loop, and it's exactly the repo's mission: a new,
easier way to let Claude help him improve his prints. (Distinct from the existing
`ideas/what-can-claude-see.md`, which maps general failing-print diagnosis — this one is the
narrow, repeatable first-layer Z-offset advisor.)

## ⟲ Previous-session review

Predecessor: `.sessions/2026-07-13-guide-temperature-tower.md` — it nailed the house move of making
one physical test print reveal its own fix (the tower sweeps nozzle temperature so the defect names
the cure), and left a clean "see this defect → print this tower" decision-tree seed. This session
carries that shape forward one rung down the stack — from nozzle heat to the bed the whole print
stands on — keeping the same change-one-value-and-look teaching style.
