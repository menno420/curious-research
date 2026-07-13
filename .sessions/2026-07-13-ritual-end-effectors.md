# Session — 2026-07-13 — Idea ritual: printed end-effectors (the swappable tool family)

> **Status:** `in-progress`
> **📊 Model:** Claude Opus 4 family. **Venue:** Claude Code on the web (remote container), Curious Research seat — ritual worker.

## What this session is doing

Running the idea ritual (`docs/idea-ritual.md`, 8 questions → one verdict) on
`ideas/printed-end-effectors.md`, which was still a captured — and title-truncated —
one-liner ("Parametric wrist-mount fingers, a suction cup, and a pen hol…"). Growing it in
place with real, cited research into an honest verdict.

The dossier already ranks printed end-effectors the **#1 printer↔arm crossover**
(`research/possibility-dossier.md` Part 3 #1, "DO THIS FIRST") and a pen holder has already
shipped inside `projects/arm-pen-plotter/`, so the open question the ritual answers is *the
rest of the family* — the 2-finger gripper, magnet pickup, scoop, phone clamp, suction cup —
and, more importantly, what actually makes a "family" worth building.

Research grounding (cited in the idea file): hobby-servo payload/torque realities (usable
~50–200 g at the gripper; the printed effector's own 30–120 g mass eats that budget), real
SG90 / MG90S / MG996R stall-torque + weight figures and the derate-to-~50 %-of-stall rule,
single-servo gripper mechanisms (rack-and-pinion vs pivot vs Fin Ray), zero-channel passive
tools, honest suction limits, PLA/PETG/TPU material + layer-orientation guidance, and the
industrial quick-change / tool-changer case for standardizing the mount.

## The verdict reached

**build** — but build the *mount standard first*, then a single-servo gripper as the family's
second member (the [pen holder](../projects/arm-pen-plotter/) is already the first). The
ritual's sharpening: the one-liner read as "collect effectors"; the research says the real
power is the **shared wrist interface** that lets them all swap. Full reasoning + 8 answers +
first-steps in `ideas/printed-end-effectors.md`.

## 💡 Session idea

A **printed bench tool-dock** — a passive rack on the desk with keyed cradles where the arm
sets down one effector and picks up another through a *taught* sequence, no hands. It's the
piece that turns a swappable-mount *family* into an actual auto-tool-changer, and it plays to
the arm's one real strength (repeatability — returning to a taught spot) instead of its
weakness (absolute accuracy). Distinct from the effector family itself (the tools) and from the
standard mount (the interface): this is the *infrastructure* that makes the swap hands-free. It
needs the mount standard to exist first, so it's a natural sequel, not a competitor — and it
rides on `projects/arm-pen-plotter/teach_and_replay.py` for the taught pick/place moves.

## ⟲ Previous-session review

Predecessor by mtime: `.sessions/2026-07-13-idea-teach-mode-hygiene.md` — it marked
`ideas/arm-teach-mode.md` as "largely built" now that
`projects/arm-pen-plotter/teach_and_replay.py` exists, so the backlog stops advertising built
work as unbuilt. Clean continuation: that card kept an idea file honest about what's *already
built*; this one keeps an idea file honest about what's *worth building next* — same in-lane
discipline (one idea file grown, no code, no motion, safety untouched), and it links forward to
that same teach-mode tool, since the tool-dock idea above rides on teach-mode replay.
