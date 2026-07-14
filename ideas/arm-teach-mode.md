# Record arm poses by hand and replay them inside the safe envelope — the routine library that powers the other arm ideas (printer/arm crossover).

> **State:** largely built (2026-07-13) — see `projects/arm-pen-plotter/teach_and_replay.py`; grow the remainder with the ritual (`docs/idea-ritual.md`) if curious.

## What already exists

`projects/arm-pen-plotter/teach_and_replay.py` is a working teach-and-replay tool. You jog the six
joints a few degrees at a time (`j <joint> <deg>` or an absolute `set`), `rec` each pose you like as
a waypoint, `save` the list to a JSON file, and `replay` the whole sequence. Every angle it ever
sends is clamped to your measured `arm/calibration.json` through one send path — and the tool
**refuses to run** without that file, or if it still holds `PLACEHOLDER` values. That's the
"routine library" this idea was reaching for: named, reusable, envelope-safe pose sequences.

## One honest nuance

The spark said record poses **"by hand"** — physically pushing the arm to a pose and having it
remember. Hobby servos can't do that: they have no way to report where they are (no encoders, no
position feedback), so there's nothing to read back off a joint you've pushed. The tool does the
practical equivalent instead — you nudge each joint with keyboard `jog` commands and eyeball the
result, then snapshot it. A true push-to-teach arm would need feedback servos or added encoders;
if you ever want that, it's the residual idea worth growing with the ritual.

---

Record arm poses by hand and replay them inside the safe envelope — the routine library that powers the other arm ideas (printer/arm crossover).
