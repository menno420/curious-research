# Session — 2026-07-13 — Retraction vs stringing guide

> **Status:** `complete`
> **📊 Model:** Opus 4.8 (Claude Opus 4 family). **Venue:** Claude Code on the web (remote container), Curious Research seat.

## What this session did
- Built `guides/retraction-vs-stringing/` — an animated cause-and-effect explainer for the slicer's retraction setting: what retraction physically does in the hot end, why too little strings and too much jams, and a "print this tower and read it" experiment to dial it in.
- Companion `guide.md` with numbered bench-terms steps, a starting-values table (PLA/PETG × direct/Bowden), and the test-print procedure ending in a Verify line.
- Indexed it in `guides/README.md`. Physics web-verified against Simplify3D, Prusa, Bambu Lab, Ellis' Print Tuning Guide, MatterHackers.

## 💡 Session idea
- Next off `ideas/explain-my-slicer.md`: a "temperature tower" companion guide — same test-print teaching shape, for finding the best nozzle temp (the other half of the stringing fight).

## ⟲ Previous-session review
- The seeding session delivered exactly what it promised — a working gate, the binding teaching doctrine, and the `how-a-pr-flows` exemplar — and it set this one up cleanly by leaving both a reference implementation to mirror and the `explain-my-slicer` idea this guide grows from.

## Context delta
- Repo names no specific slicer/printer/filament (only "two 3D printers — one small, one 3-color"), so this guide is deliberately slicer-agnostic; the PR asks the owner which slicer he uses so a follow-up can add exact menu paths. Source physics dossier lived in this session's research, cited inline in guide.md.
