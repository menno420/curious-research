# The robot arm's safe envelope — and the clamp that protects it

This guide gives you a simple, hands-on way to measure each servo's safe range of motion by
hand, write those numbers down, and hand them to software so it can *refuse* any command that
would drive a joint into the desk, a wire, or its own frame. No math, no theory — just careful
measuring, one joint at a time.

**Open the animation first.** Double-click `guides/arm-envelope-explained/index.html` to open
it in your web browser, then hit **Replay** to watch the arm crash and then get caught by the
clamp. The picture makes the rest of this page click into place.

## Words we'll use

- **Servo** — a motor you command to an exact angle. You don't tell it "spin"; you tell it
  "go to 90°" and it goes there and holds. Your arm has six of them.
- **Envelope** (also called the **safe range**) — every angle a joint can reach *without*
  hitting itself, the desk, a wire, or its own base. Each joint has its own envelope.
- **Clamp** — a tiny bit of software that trims any command back into the safe range before it
  ever reaches the motor. Ask for 170° on a joint that maxes out at 120°, and the clamp quietly
  hands the servo 120° instead.
- **Calibration** — measuring those safe angles once, carefully, and writing them down so the
  software has real numbers to work with.

## Before you touch anything — the safety rules (non-negotiable)

- **Servo power is a SEPARATE 5–6 V supply** with its own switch — shared ground with the
  Arduino, fused, and sized for stall current (the big gulp of current a servo pulls when it's
  pushing against something and can't move). **Never power servos from the Arduino's 5 V pin.**
  A stalling servo pulls far more current than that pin can give; it will brown out the board
  (voltage sags, the Arduino resets or acts drunk) or fry it outright.
- **Keep a hand on the power switch during every powered move.** If anything looks, sounds, or
  smells wrong, cut power first and ask questions after.
- **A human watches every single move.** The arm never moves unattended — not once, not "just
  to test."
- **Do the FIRST measurement pass with power OFF**, moving the joint gently by hand and by eye.
  Only sweep a joint under power once you already know roughly where its limits are.

## Step-by-step: measure each servo's safe min, max, and center

You'll do this for all six joints. On a typical 6-joint (6-DOF) arm those are **base**,
**shoulder**, **elbow**, **wrist tilt**, **wrist rotate**, and **gripper** — rename them to
match whatever you call yours. Do **one joint at a time**, start to finish, before moving to
the next.

1. **Power OFF.** Gently move joint 1 by hand through its whole travel, by feel. Find the two
   points where it *just barely* reaches its own frame, the desk, or a taut wire — WITHOUT
   forcing anything. Those two points are your rough physical limits.

2. **Back off a few degrees from each rough limit.** That little safety margin is your working
   **min** and **max**. Write them down.

3. **Find the center** — roughly halfway between min and max, the neutral "rest" pose the arm
   sits in when it's doing nothing. Write it down.

4. **Now power on** with the external supply, finger on the switch. Command the joint **slowly**
   toward one recorded limit at low speed. If it reaches the limit cleanly with a little margin
   to spare, good. If it strains or **buzzes**, cut power and reduce that limit. (A buzzing or
   straining servo is fighting a mechanical stop — it's pushing on something it can't move.
   Back the number off until the move is clean.)

5. **Repeat the slow sweep toward the other limit** and adjust that number the same way.

6. **Record min / max / center for that joint** in your calibration file (next section). Then
   repeat every step above for the other five servos — ONE joint at a time.

Here's what one finished measurement looks like, so you know the shape of what you're after:

```
shoulder:  min 25°   max 120°   center 75°
```

## Write it down: your calibration file

There's a ready-made template in the `arm/` folder. Copy it to a file of your own:

```
cp arm/calibration.example.json arm/calibration.json
```

Then open `arm/calibration.json` and fill in each joint's measured **min**, **max**, and
**center**, and set the `measured_by` and `measured_on` fields so future-you knows who took
these numbers and when.

Honest note: `arm/calibration.json` does **not** exist yet and is **not** in this repo on
purpose. It's YOUR file, born from YOUR measurements — nobody else's numbers are safe for your
arm. Keep it; the motion code will read it.

## What the clamp does (and the rule that makes it work)

The clamp is one small function — `clamp(angle, min, max)` — that every motion routine must
call *before* it sends an angle to a servo. It takes the angle you asked for and the safe min
and max you measured, and it returns an angle that's guaranteed to sit inside the safe range.
Ask for 170° on a joint whose max is 120°, and the clamp returns 120° — the servo stops at the
safe edge instead of slamming into whatever's past it.

```
clamp(170, 25, 120)  ->  120     // trimmed down to the safe max
clamp(10,  25, 120)  ->  25      // trimmed up to the safe min
clamp(75,  25, 120)  ->  75      // already safe, unchanged
```

The hard rule, stated plainly: **no motion code runs without every command routed through the
clamp, and the clamp is only as safe as the numbers you measured.** The clamp is software — it
can't save you from a wrong measurement, or from a wire it doesn't know about, or from a part
you added since you last measured. That's exactly why a human always watches every move.

## Verify

You're done when you have a filled-in `arm/calibration.json` with a real min, max, and center
for all six joints, and you've watched each joint reach both limits under power without strain.
