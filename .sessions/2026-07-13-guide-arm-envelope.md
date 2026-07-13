# Session card — 2026-07-13 · guide-arm-envelope

> **Status:** `complete`

**Seat:** Curious Research (dispatched work session)
**Branch:** `claude/guide-arm-envelope`
**Scope:** `guides/arm-envelope-explained/` + `arm/` lane groundwork

## Goal
Ship the ARM-ENVELOPE-EXPLAINED guide — an animated HTML explainer plus a
numbered "measure your servos by hand" guide.md — and seed the `arm/` lane with
a calibration template (calibration.example.json + README) so future motion code
has a clamp target to point at. Done-when: the owner could measure his 6 servos'
safe min/max tonight, by hand, with zero jargon and zero guessing.

## Plan
- [x] guides/arm-envelope-explained/index.html — animated 2–3 joint arm: what a servo's safe angle range is, why an uncalibrated command slams a joint into itself or the desk, and how a software clamp (min/max per joint) catches a bad command before the servo moves.
- [x] guides/arm-envelope-explained/guide.md — numbered: measure each servo's safe min/max by hand (power-off / by-eye first, then slow supervised sweeps), record them, what the clamp does.
- [x] arm/calibration.example.json — 6-servo template (min/max/center per joint, measured-by + date), commented-by-convention.
- [x] arm/README.md — the template must be filled from HIS own measurements before any motion code runs.
- [x] guides/README.md — one index line.

## Safety (binding — CLAUDE.md §2)
Arm moves only inside the calibrated envelope, only via routines that clamp to
it, only with the human watching. Servo power is EXTERNAL always — a separate
5–6 V supply, shared ground, sized for stall headroom, fused, with a reachable
power switch, NEVER the Arduino 5 V pin. No motion code merges without the clamp
in the path. This guide ships NO motion code and does NOT create
arm/calibration.json (that file is born from his real measurements).

## What shipped
- `guides/arm-envelope-explained/index.html` — the animated explainer: a staged,
  replayable arm showing the safe angle range per joint, an uncalibrated command
  slamming a joint into itself/the desk, and the software clamp catching a bad
  command before the servo moves.
- `guides/arm-envelope-explained/guide.md` — the numbered "measure your servos by
  hand" companion: power-off by-eye first, then slow supervised sweeps, record the
  min/max/center, and what the clamp does with those numbers.
- `arm/calibration.example.json` — the 6-servo template (min/max/center per joint,
  measured-by + date), the clamp target future motion code points at.
- `arm/README.md` — seeds the `arm/` lane and states plainly the template must be
  filled from HIS own measurements before any motion code runs.
- `guides/README.md` — one index line for the new guide.

Ships **NO motion code**, and did **NOT** create `arm/calibration.json` — that
file is born only from his real measurements. `arm/` lane established as
groundwork; the clamp now has a documented target to point at.

## 💡 Idea
**Servo sweep wizard** — a single-file, self-contained offline HTML page that uses
the browser's Web Serial API to talk to his Arduino and walk him through the slow
supervised limit sweeps **one joint at a time**. Big, always-visible **STOP**
button; on-screen live angle readout as the joint moves; and a final "save these
min / max / center" step that emits a ready-to-paste `arm/calibration.json`. It
turns the scary, error-prone manual calibration into a guided, one-button wizard —
the natural companion to the guide.md this session shipped (the guide teaches the
by-hand method; the wizard drives it). Not a duplicate: the existing arm ideas
cover recording/replaying poses (`arm-teach-mode`), timelapse, pen-plotting, print
removal, and end-effectors — none is a Web-Serial calibration/limit-sweep tool.

## 📊 Model
📊 Model: Claude Opus 4 family (dispatched Curious Research work session).

## Previous-session review
The prior card (`.sessions/2026-07-13-session-2.md`) flagged `arm-envelope-explained`
as a next-2 baton item seeding `arm/calibration.json` groundwork — now shipped this
session. It also flagged stop-hook telemetry churn dirtying the tree (PROPOSAL 001);
that held true here — only `HANDOFF.md` and `.substrate/` churn appeared, handled by
staging narrowly (just the card + the dropped claim), leaving the churn out of the
commit.
