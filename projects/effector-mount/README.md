# projects/effector-mount — one wrist mount, many tools

> **What this is, honestly:** a *standard* — one printed adapter plate that bolts
> to your arm's last servo horn, that every tool is built on top of. It is not a
> finished gadget on its own; it is the shared "socket" that makes swapping tools
> painless. The first tool riding on it is a **passive magnet pickup** — no servos,
> no wires, and it holds a part even with the arm powered off. Whether the magnet
> is strong enough to lift *your* part is something **you test**, not something the
> design can promise.

Grown from [`ideas/printed-end-effectors.md`](../../ideas/printed-end-effectors.md)
(ritual verdict: **build — standardize the mount first**). This lane is steps
**1–2** of that verdict; steps 3–4 are the roadmap at the bottom.

▶ **Want the picture first?** Open `index.html` in any browser to *watch* two
different tools click onto the same plate, and see the key stop one from spinning.

## Bench words (one line each)
- **end effector** — the "hand" at the end of a robot arm: whatever tool it holds.
- **servo horn** — the star/arm-shaped disc bolted to a servo's output shaft that
  actually moves. Your tool bolts to the horn.
- **interface / standard** — an agreed shape + hole pattern so parts made
  separately still fit. USB is an interface; so is this plate.
- **bolt pattern** — the spacing and size of the screw holes. Match it, tools fit.
- **keying** — a shape that fits only one way, so a tool can't sit crooked or spin.
- **press-fit** — a hole a hair *smaller* than the thing you push in, so it wedges
  and stays with no glue.
- **payload** — how much weight the arm can actually carry at arm's length.
- **`.scad` file** — an OpenSCAD design: text that *describes* a 3D shape. You open
  it, render, then slice and print. Nothing here is an STL yet, on purpose.

## What's in here
| File | What it is |
|------|-----------|
| `mount_standard.scad` | The shared interface. A **library** — you don't print it alone; tools pull it in. Holds every number of the mounting plate: bolt pattern, thickness, keying. |
| `magnet_tool.scad` | The first tool. Pulls in the standard, adds a cup for a magnet. **This** is the file you render + print. |
| `index.html` | A small self-contained animated explainer — open in any browser. |
| `README.md` | This walkthrough. |

## Why a mount standard is worth the trouble
Right now your pen holder carries its own bolt-to-the-horn code baked inside it
(the `arm_mount()` module in
[`projects/arm-pen-plotter/pen_holder.scad`](../arm-pen-plotter/pen_holder.scad)).
If you drew a second tool from scratch you'd re-measure the horn, re-draw the
holes, and hope they matched. Do that five times and you have five slightly
different mounts and no guarantee any tool fits on any given day.

The standard flips that: **measure your horn once, write it in one file, and every
tool built on that file mounts the same way, in the same place, facing the same
direction.** Swapping a pen for a magnet becomes: undo two screws, lift, drop the
next tool on, two screws back in. That ten-second swap is the whole reason to
standardize *before* collecting tools.

## The keying feature — two small shapes doing real work
Two screws already stop a tool spinning once they're tight. The keying adds the
part that makes the swap *repeatable*:

1. **Hub recess** — a shallow round pocket on the *underside* of the plate that
   drops over the raised hub in the middle of most 9 g horns. It self-centres the
   plate on the shaft, so the plate lands in the same spot every time and can't
   creep sideways.
2. **Back-edge notch** — a small notch that always marks the plate's "back". Build
   every tool with its working end (pen tip, magnet, fingers) pointing the same
   way and the notch at the back, and every tool goes onto the arm the same way
   round — no "which way does this one face again?". It is also the hook a future
   auto-tool-changer (the bench tool-dock idea) will use to find a tool.

## Setting the mount to YOUR horn — one number at a time
Open `mount_standard.scad`. Change these, save, press **F5** to preview.

**1. The distance between the two horn screws.** Put calipers on your horn, measure
centre-of-hole to centre-of-hole. Set:
```scad
horn_span = 16.0;   // <- your measured centre-to-centre, in mm
```

**2. The screw clearance hole.** For the little M2 self-tappers that come with 9 g
servos, leave this. For a bigger screw, use its shaft diameter + ~0.2 mm:
```scad
horn_screw_d = 2.2;   // <- screw diameter + a hair, in mm
```

**3. The hub the plate centres on.** Measure the diameter of the raised round hub
in the middle of your horn. No hub? Set it to `0` and the recess disappears:
```scad
horn_hub_d = 8.0;   // <- your horn hub diameter, or 0 for none
```

**4. Plate thickness.** 3 mm is fine for light tools; go 4 mm if anything feels
bendy:
```scad
mount_th = 3.0;   // <- plate thickness in mm
```

**Not sure your numbers are right?** Print the bare plate ALONE first (open
`mount_standard.scad`, F6, slice, print — it's a couple of grams) and bolt it to
your real horn. If it drops on and the screws line up, your numbers are good and
you can print the whole tool with confidence. (That "print just the plate to
check" is the *horn fit-check coin* idea in this session's card.)

## Setting the magnet tool — one number at a time
Open `magnet_tool.scad`. It already pulls in the standard, so the horn numbers
above carry over. Set the magnet:

**1. Magnet diameter and height** (read the bag label "D x H", or measure):
```scad
magnet_d = 12.0;   // <- magnet diameter in mm
```
```scad
magnet_h = 3.0;    // <- magnet thickness in mm
```

**2. How tight the magnet grips.** The pocket prints this much *smaller* than the
magnet so it wedges in. If your printer runs tight and the magnet won't seat, raise
it; if the magnet drops out, lower it (or add a drop of glue):
```scad
magnet_fit = 0.15;   // <- 0.10–0.20 firm press-fit; raise if too tight
```

**Press-fit vs glue:** aim for a firm press-fit so the magnet never rattles loose
mid-move. If a press-fit is fiddly, print it slightly loose and put ONE drop of
super-glue or epoxy in the cup floor before pressing the magnet home. Don't glue
the magnet proud of the rim — keep the flat face flush so it makes full contact.

## Printing it
- **Material:** PETG is the pick — a bit tougher and less brittle than PLA, and it
  shrugs off the warmth of a workshop. PLA works for gentle testing.
- **Orientation & strength (read this):** a printed part is weakest *between* its
  layers. The magnet's pull runs straight up its axis. If you print the tool
  sitting flat on the bed (cup pointing up), that pull is *across* the layers — the
  weak direction — so a hard yank could pop the cup off its stem. For a stronger
  tool, stand it on its side so the pull runs *along* the layers; you'll need a few
  supports under the cup. For light parts and gentle moves, flat-and-simple is
  usually fine. **This is a "check this yourself" — test the pull before you trust
  it.**
- **Infill:** 30–40% infill, 3 walls. No need for solid.

## Hand-fit test — do this with the servo power OFF
You are checking the *mechanical* fit only. No motion, no power to the arm.

1. **Cut power to the arm's servos.** Flip the switch on the external servo supply
   (the arm never runs off the Arduino's 5 V pin). Confirm nothing on the arm can
   move.
2. **Drop the plate onto the horn.** The hub recess should seat over the horn's hub
   and the plate should sit flat. If it rocks, your `mount_th`/`horn_hub_th` or the
   hub diameter is off — re-measure.
3. **Start the two screws by hand.** They should thread into the horn's holes
   without forcing. If they cross-thread or miss, your `horn_span` is off.
4. **Snug the screws** (gentle — you're biting into plastic/the horn, not steel).
   Wiggle the tool: it should not rotate or rock. That's the key + screws doing
   their job.
5. **Test the magnet by hand.** With power still OFF, touch the magnet to the actual
   part you want to pick up and lift it by hand at the tool. Does it hold at the
   angle and height you'll use? If it barely holds in your hand, it will not hold on
   a moving arm. Pick a stronger magnet or a lighter part before you ever power up.

Only after all five pass do you move on to (separately, another day, with the arm
calibrated and a human watching) trying a taught pick-and-place move.

## Honest limits
- **Payload is small.** Little hobby arms carry roughly **50–200 g at arm's length**,
  and the tool's own weight eats into that. Keep picked parts light — think small
  steel hardware, not a full can.
- **Magnets only grab magnetic metal.** Steel and iron yes; aluminium, brass,
  copper, plastic, wood — no.
- **The pull is through the cup floor**, so it's a little weaker than magnet-on-bare-
  metal. That's on purpose (no clack, magnet can't fall through). Size up the magnet
  if you need more grab.
- **Unverified by render.** These `.scad` files were written where OpenSCAD isn't
  installed, so they have *not* been rendered or sliced here. Open them, render, and
  eyeball the shapes before printing.

## Migrating the pen holder onto the standard (a later, backward-compatible step)
The pen holder still has its own `arm_mount()` and is left **unchanged** by this
lane — nothing to fix, it works. When you feel like it, the clean migration is: add
`use <../effector-mount/mount_standard.scad>` to `pen_holder.scad`, replace its
`arm_mount()` body with a call to `mount_plate()`, and drop its private
`mount_mode`/`horn_span`/`mount_th` globals in favour of the standard's. Because the
bolt pattern is identical, a pen holder rebuilt on the standard bolts to the same
horn in the same place — old prints keep working, new ones share the interface.
That's its own one-change PR when you want it.

## Roadmap — what rides on this next
- **Step 3 — single-servo gripper.** A 2-finger rack-and-pinion gripper (PapaBravo
  style) driven by one MG90S/MG996R servo, built on this same plate, with the servo
  motion clamped through the arm's `clamp()` path. Its own PR, its own guide, once
  the arm's calibration envelope exists.
- **Step 4 — soft grip / suction.** A TPU Fin-Ray finger pair for delicate parts,
  or a light suction cup for flat non-porous things — nice-to-haves, not the point.
- **The bench tool-dock** (already logged as a session idea) — a passive desk rack
  with keyed cradles so the arm sets one tool down and picks another up through a
  taught sequence. It *needs this standard to exist first*, and it leans on the
  back-edge notch to locate each tool. This lane is the groundwork for that.

## Safety (the hard rails, restated)
- **No motion code is in this PR**, and none belongs in these files. The arm moves
  only inside its calibrated envelope, through routines that clamp to it, with a
  human watching.
- **You slice, load, start, and watch every print.** The model designs; the print
  and the power are yours.
- **Servo power stays external and fused** (a separate 5–6 V supply, shared ground,
  reachable switch) — never the Arduino's 5 V pin. (No servos in this tool, but the
  rule holds for the gripper to come.)
- **Any lift is "check this yourself."** Confirm the magnet holds your part, by
  hand, power off, before you trust the arm with it.
