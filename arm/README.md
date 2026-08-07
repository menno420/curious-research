# arm/ — the robot arm lane

This folder holds the arm's calibration and (later) its motion routines. Keep everything about
the arm in this lane.

## What this arm actually is (known as of 2026-08-07)

A **6-DOF robot-arm kit, assembled from parts** — the widely-cloned "6DOF Robot Mechanical
Arm Kit" pattern sold under many names, on **MG996R-class standard servos**.

| | |
|---|---|
| **Servos** | **6 × MG996R** analog, ~55 g each, 180° nominal |
| **Torque** | ~9.4 kg·cm at 4.8 V, ~11 kg·cm at 6 V |
| **Current** | ~1.4 A quoted official, **up to ~2.5 A stalled at 6 V, each** |
| **Structure** | metal brackets, cup bearings at the joints |
| **Joint 6** | the gripper/claw is one of the six — not a spare channel |

### It is already built, wired and moving — start from there

**This is the single most important thing for any session to know.** The arm is not a box of
parts waiting for a first power-up. It has been assembled, wired and driven under program
control from a laptop over USB. Observed on the bench:

- an **enclosed switching power supply** — the metal-cased kind with a cooling fan, mains in
  one end and a **screw-terminal block** out the other. Real bench power, correctly separate
  from the controller, exactly as §2 requires.
- a small **power-distribution board** with screw terminals between the supply and the servos;
- a **driver/controller board** with the servo leads converging on it;
- a laptop on USB, driving the arm.

So **do not** write him a "how to power your arm" or "how to make it move the first time"
guide. He is past both. He solved the hard electrical problem before this repo said a word
about it. Pitch everything at what comes *after* first motion: repeatability, envelope limits,
useful work. Ask before assuming anything about board models or supply ratings — the exact
parts have not been confirmed in writing, only seen.

### Three things that are easy to get wrong

1. **Power sizing, if it ever gets rebuilt.** Six MG996R stalled together is on the order of
   **15 A**. They never all stall at once, but the supply must survive two or three doing it.
   A **6 V supply in the 10 A class** is the usual answer; a 5 V 2 A USB brick is not, and its
   sag looks exactly like a software bug. Full arithmetic in
   [`projects/arm-pen-plotter/pen_plotter_arm.ino`](../projects/arm-pen-plotter/pen_plotter_arm.ino).
2. **Analog servos cannot report their position.** You cannot backdrive a joint by hand and
   read the angle out. This is *why* teach mode in
   [`projects/arm-pen-plotter/`](../projects/arm-pen-plotter/) works by **jogging** — you nudge
   a joint in small commanded steps and snapshot the numbers you sent. Any future design that
   assumes position feedback is not buildable on this hardware without adding encoders.
3. **The gripper channel is already spoken for.** The end-effector work in
   [`projects/effector-mount/`](../projects/effector-mount/) assumes a servo for its tool.
   On this arm that means either *replacing* the stock claw on joint 6, or adding a **7th**
   servo and channel. Decide which before printing.

Sources for the electrical numbers, and the accuracy you can honestly expect from this servo
class, are in [`research/possibility-dossier.md`](../research/possibility-dossier.md).

`arm/calibration.example.json` is a **TEMPLATE**. Before ANY motion code runs, copy it to
`arm/calibration.json` and fill every joint's `min` / `max` / `center` from YOUR OWN
measurements — the how-to is in
[`guides/arm-envelope-explained/guide.md`](../guides/arm-envelope-explained/guide.md).

## Your real `arm/calibration.json` belongs in the repo — commit it

Once you have measured your own arm and filled in real numbers, **commit `arm/calibration.json`.**
It is not a secret and it is not personal — it's six servos' worth of `min` / `max` / `center`
angles, just numbers. Keeping it in the repo is what makes this whole workflow work:

- **Claude reads it to design motion for *your* arm.** The clamp that keeps the arm safe is only
  right if it knows your true limits — and it can only know them if the file is here.
- **A reviewer reads it to confirm a motion change stays inside your envelope.** Nobody can check
  a file they can't see.

So the file follows the normal template pattern — like `.env.example` → `.env` — except here the
filled-in file is *meant* to be shared:

1. Copy the template: `cp arm/calibration.example.json arm/calibration.json`
2. Fill every joint's `min` / `max` / `center` from **your own** hand measurements — the
   step-by-step (and an animation) is in
   [`guides/arm-envelope-explained/`](../guides/arm-envelope-explained/): open its `index.html`
   and press **Replay** first.
3. **Commit it.** From then on it is the arm's source of truth for
   [`projects/arm-pen-plotter/`](../projects/arm-pen-plotter/) and any future motion routine.

**Never commit fake or placeholder numbers.** The tools refuse to run on the template's
`PLACEHOLDER` values on purpose — wrong limits are dangerous. Commit the file only once the
numbers are really yours.

> **What never goes in this public repo:** genuinely personal data — full names, photos,
> addresses, account handles. Servo angles are not personal data; *you* are. Keep the numbers,
> leave yourself out — `measured_by` is fine as a first name or nickname, nothing that identifies
> you.

## The safety rules (repeat — binding)

- The arm moves **only inside the calibrated envelope**, only via routines that **clamp** every
  command to that envelope (`clamp(angle, min, max)`), and only with a **human watching**.
- Servo power is a **separate fused 5–6 V supply** with shared ground and a reachable switch —
  **never** the Arduino's 5 V pin.
- **No motion code merges here without the clamp in the path.**
