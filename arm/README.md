# arm/ — the robot arm lane

This folder holds the arm's calibration and (later) its motion routines. Keep everything about
the arm in this lane.

`arm/calibration.example.json` is a **TEMPLATE**. Before ANY motion code runs, copy it to
`arm/calibration.json` and fill every joint's `min` / `max` / `center` from YOUR OWN
measurements — the how-to is in
[`guides/arm-envelope-explained/guide.md`](../guides/arm-envelope-explained/guide.md).

`arm/calibration.json` is intentionally **NOT** in this repo: it's born from real measurements,
it's yours, and fake numbers in it would be dangerous.

## The safety rules (repeat — binding)

- The arm moves **only inside the calibrated envelope**, only via routines that **clamp** every
  command to that envelope (`clamp(angle, min, max)`), and only with a **human watching**.
- Servo power is a **separate fused 5–6 V supply** with shared ground and a reachable switch —
  **never** the Arduino's 5 V pin.
- **No motion code merges here without the clamp in the path.**
