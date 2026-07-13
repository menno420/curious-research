# Session card — 2026-07-13 · guide-arm-envelope

> **Status:** `in-progress`

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
- [ ] guides/arm-envelope-explained/index.html — animated 2–3 joint arm: what a servo's safe angle range is, why an uncalibrated command slams a joint into itself or the desk, and how a software clamp (min/max per joint) catches a bad command before the servo moves.
- [ ] guides/arm-envelope-explained/guide.md — numbered: measure each servo's safe min/max by hand (power-off / by-eye first, then slow supervised sweeps), record them, what the clamp does.
- [ ] arm/calibration.example.json — 6-servo template (min/max/center per joint, measured-by + date), commented-by-convention.
- [ ] arm/README.md — the template must be filled from HIS own measurements before any motion code runs.
- [ ] guides/README.md — one index line.

## Safety (binding — CLAUDE.md §2)
Arm moves only inside the calibrated envelope, only via routines that clamp to
it, only with the human watching. Servo power is EXTERNAL always — a separate
5–6 V supply, shared ground, sized for stall headroom, fused, with a reachable
power switch, NEVER the Arduino 5 V pin. No motion code merges without the clamp
in the path. This guide ships NO motion code and does NOT create
arm/calibration.json (that file is born from his real measurements).

## 💡 Idea
_(filled at close)_

## 📊 Model
_(filled at close)_

## Previous-session review
_(filled at close)_
