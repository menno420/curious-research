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
| `gripper.scad` | The second, *active* tool — a single-servo rack-and-pinion 2-finger gripper on the same plate. Pulls in the standard; **this** is a file you render + print. |
| `gripper_test.ino` | A tiny Arduino sketch to test the gripper's **one servo on the bench** (not on the arm). |
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

## The single-servo gripper (step 3) — a hand that actually grips
The magnet tool is passive; the **gripper** is the family's first *active* member.
It is a **rack-and-pinion** design: one servo turns a round gear (the **pinion**),
and that pinion drives **two straight toothed bars** (the **racks**) that sit on
*opposite* sides of it. Turn the servo one way and one rack slides left while the
other slides right — so both jaws close (or open) together, at the same speed,
from one motor. Each rack carries a printed **finger**; the fingers meet in front
to grab a part. The whole thing is built on the same standard plate, so it clicks
onto the arm's wrist exactly like the pen and the magnet.

Two files make it up:
- `gripper.scad` — the printed parts (plate + servo cradle + pinion + two racks +
  two fingers), all parametric.
- `gripper_test.ino` — a bench sketch that sweeps the **one servo by itself** so
  you can find its open/closed positions safely, off the arm.

> **Bench words for this section:** **rack** = a straight bar with teeth (a
> flattened gear); **pinion** = the round gear the servo turns; **mesh** = two
> sets of teeth engaging cleanly, rolling instead of jamming or slipping;
> **stall** = a servo pushing against something it can't move — it draws a lot of
> current and heats up, so you never hold a gripper hard-closed.

### Build it in this order (don't skip ahead)

**Step 1 — Print the parts, in the right orientation.** A printed part is weakest
*between* its layers, and gear teeth push on each other sideways. So print the
**pinion and both racks lying flat** on the bed, so each tooth's load runs *along*
the layers, not across them — teeth printed standing up shear off at the layer
lines on the first firm grip. Use **PETG** (tougher, better layer bond) over PLA
for these load-bearing gear parts. Open `gripper.scad`, pick your servo, then
render (**F6**), export, and slice. Set the servo before anything else:
```scad
servo_type = "MG90S";   // "MG90S" (default) or "MG996R". Never "SG90".
```
Then correct the servo body/shaft/tab numbers to the servo in your hand
(calipers), for example:
```scad
body_l = 22.8;   // servo body length in mm — measure yours
```
```scad
shaft_d = 4.8;   // output-shaft diameter in mm — measure yours
```
*You should see* the assembled gripper in preview: a servo cradle, a central gear,
two racks reaching out to two fingers.

**Step 2 — Check the gear MESH by hand, with NO power.** This is the make-or-break
check, and it costs nothing but a minute:
1. Slot the pinion onto the racks (or assemble as printed) and turn the pinion
   **by hand**.
2. Watch both racks: they must slide in **opposite** directions, smoothly, and
   the two jaws must move **together** — closing as one, opening as one.
3. There must be **no binding** and no skipping teeth. If the teeth jam, the gap
   is too tight; if they slip, it's too loose. Nudge the fit and re-print:
```scad
mesh_tweak = 0.0;   // +raises tightness of the mesh; clearance widens the fit
```
*You should see* a clean roll: turn pinion → jaws glide together → reverse → jaws
glide apart. Do NOT go near power until this feels right by hand. (The teeth here
are a **simplified straight-flank profile**, not proper involute gears — the
`.scad` says so honestly — so this hand-check matters. If you have a gear library
you can swap in real teeth.)

**Step 3 — Bench-test the ONE servo, off the arm.** Now, and only now, add power —
to the servo *alone*, on the bench, using `gripper_test.ino`. Wire it on its
**external, fused 5–6 V supply with the ground shared to the Arduino, and a
reachable switch — never the Arduino's 5 V pin** (a gripping servo stalls and can
brown out or fry the board). Then find your two pulse widths by hand, power off
between tries, in tiny steps:
```cpp
const int GRIP_OPEN_US  = 1300;   // pulse where the jaws are open enough
```
```cpp
const int GRIP_CLOSE_US = 1600;   // pulse where the jaws JUST MEET — no harder
```
Set `GRIP_CLOSE_US` so the jaws *just touch* your object and **no further** — never
drive them into a hard closed stall (that overheats the servo and strips gears; an
SG90's plastic gears strip fast, which is why the `.scad` refuses SG90). Upload,
open the Serial Monitor at 115200 baud, **read the banner**, keep a hand on the
switch, and watch it sweep open↔closed.

**Step 4 — Only then, mount it on the arm.** Once the mesh is clean and the servo
sweeps sweetly on the bench, bolt the gripper onto the arm's standard plate (two
horn screws, power off — same hand-fit as the magnet tool above). Arm-mounted
motion does **not** use `gripper_test.ino`; it goes through the arm's **clamped**
path — `projects/arm-pen-plotter/teach_and_replay.py` driving the gripper as joint
index 5, against `arm/calibration.json`, where every angle is trimmed to your
measured safe range before it can reach a motor. **That calibration file does not
exist yet, so no arm motion runs until you make it** (see the arm-envelope guide).

### Honest payload — what one small servo can actually hold
Keep expectations low and you won't be disappointed:
- **Usable grip is small — think ~50–200 g at an optimistic ceiling**, and that
  figure is *before* you subtract the gripper's own weight. A printed servo tool
  like this weighs roughly **30–120 g**, and that mass hangs at the very end of
  the arm's longest lever, so it comes straight off the arm's already-modest lift
  budget (a small hobby arm is working in the low hundreds of grams total). Net:
  grip *light* parts — small hardware, a bottle cap, a lego brick — not a full can.
  (Numbers from [`ideas/printed-end-effectors.md`](../../ideas/printed-end-effectors.md).)
- An **MG90S** is the gentle default; an **MG996R** grips harder but adds ~55 g of
  end-of-arm weight and a bigger current draw. **Never an SG90** — it strips its
  plastic gears on the stall a gripper makes by design.

> ### ⚠ Load-bearing — check this yourself
> A gripper that lets go mid-lift **drops the part**, and preventing that is on the
> human, not the design. Before you ever ask the arm to lift with it: at the bench,
> power off after positioning, confirm the jaws actually **hold YOUR object** — at
> the angle, height, and firmness you'll use. If it barely holds in your hand it
> will not hold on a moving arm. Pick a lighter part or a firmer grip first. This
> is a "flag it, you verify it" step, per repo `CLAUDE.md` §2.

### The gripper's safety rules, restated
- **Servo power stays external and fused** — a separate 5–6 V supply, shared
  ground, reachable switch — **never the Arduino's 5 V pin**.
- **You slice, print, power, and watch.** Claude designs the parts; the print and
  every powered move are yours, hand on the switch.
- **No raw servo writes on the arm.** On the wrist, the gripper moves only through
  the clamped `teach_and_replay.py` path against `arm/calibration.json` — and that
  file must exist first.

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
