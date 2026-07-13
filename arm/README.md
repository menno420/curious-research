# arm/ — the robot arm lane

This folder holds the arm's calibration and (later) its motion routines. Keep everything about
the arm in this lane.

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
