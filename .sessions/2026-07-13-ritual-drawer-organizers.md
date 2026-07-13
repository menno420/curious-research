# Session — Idea ritual: drawer-organizer-generator

> **Status:** `complete`
> **📊 Model:** Claude Opus 4 family (curious-research work seat)

## Goal

Grow `ideas/drawer-organizer-generator.md` from a captured one-liner ("CSV of drawer
measurements → fitted bin set") into a full 8-question ritual with cited research, ending in
exactly one honest verdict. Cover the Gridfinity elephant honestly, the "Claude as generator"
pipeline that fits this repo, big-flat-bin print realities, and the tolerance carry-over from
`projects/tolerance-test-coin`.

## Previous-session review

Reviewed `.sessions/2026-07-13-project-gripper.md` (complete): the single-servo rack-and-pinion
2-finger gripper landed (step 3), with a "swappable fingertips" idea flagged for the `ideas/`
drawer. Nothing left in flight — clean handoff into this ritual session.

## 💡 Session idea

**A shared `printer-profile.json` that every parametric generator reads.** Right now each
generator (drawer bins, keychains, future ones) would re-ask the same measured facts — this
printer's real clearance for a sliding fit, its elephant-foot compensation, its max bed size.
The measured numbers from `projects/tolerance-test-coin` are exactly those facts. Capture them
once in a small `printer-profile.json` per printer, and the drawer generator (and every
generator after it) reads its fit clearances straight from there instead of guessing. It turns
one afternoon of tolerance testing into a permanent input for all future "measure → generate"
loops. Candidate for an `ideas/` one-liner + its own ritual.

## 📊 Model

Claude Opus 4 family (curious-research work seat).

## Notes

- Born red on purpose: card lands `in-progress` at first commit, flips `complete` as the last
  commit after `python3 bootstrap.py check --strict` passes on a bare exit code.
- Deliverable is the grown `ideas/drawer-organizer-generator.md` + this card + the claim. No
  other files.
