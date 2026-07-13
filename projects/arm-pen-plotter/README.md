# Arm pen-plotter — the arm draws wobbly line art (and that's the charm)

> The 6-servo arm holds a printed, floating pen and draws simple line art on paper.
> The honest promise is **charming, wobbly lines** — not printer-perfect ones. The
> canonical version of exactly this ([BrachioGraph](https://www.brachiograph.art/))
> proudly ships *"adorably wiggly"* drawings, and that wiggle is the whole aesthetic.

Grown from [`ideas/arm-pen-plotter.md`](../../ideas/arm-pen-plotter.md) (ritual verdict: **build**).

**Bench words** (one line each): **servo** = a motor you command to an exact angle;
**jog** = nudge one joint a small step at a time by eye; **waypoint** = a saved snapshot
of all six joint angles you can replay; **clamp** = software that trims any angle back
inside the safe range you measured, *before* it reaches a motor; **envelope** = that safe
range per joint; **compliance / float** = the pen holder gives a few mm so pen pressure
stays even on an uneven surface.

---

## The one rule that comes before everything

> **No calibration file, no motion.** The tool here literally refuses to run until *you*
> have measured your arm and created `arm/calibration.json`. The clamp that keeps the arm
> safe is only as good as *your* measured numbers — and nobody else's numbers are safe for
> your arm. **Claude cannot do this step for you.** It is measured by hand, on your bench.

And the powered-move rules, every single time:

- **Servo power is a separate, fused 5–6 V supply** with a shared ground and a **reachable
  switch** — **never** the Arduino's 5 V pin. (Why: a stalling servo pulls far more current
  than that pin can give; it browns out or fries the board.)
- **Keep a hand on that switch during every powered move.** If anything looks, sounds, or
  smells wrong, cut power first and ask questions after.
- **A human watches every move.** Nothing here is ever "safe unattended."

---

## What's in this folder

| File | What it is |
|---|---|
| [`teach_and_replay.py`](./teach_and_replay.py) | The teach-mode tool: jog the arm, record waypoints, replay them slowly. Refuses to run without `arm/calibration.json`; clamps every value it sends. |
| [`pen_plotter_arm.ino`](./pen_plotter_arm.ino) | The Arduino sketch. Receives your safe limits at startup and **clamps again on-board** (belt and braces). |
| [`pen_holder.scad`](./pen_holder.scad) | The printable floating pen holder (source only — you render the STL locally). |
| [`index.html`](./index.html) | An animated explainer of how teach-mode works — open it in a browser, press **Replay**. |

---

## Step-by-step: your first wobbly line

Do these **in order**. Calibration is Step 1 on purpose — the drawing steps physically
cannot run before it.

### Step 1 — Measure your arm and create `arm/calibration.json` (YOUR file)

This is the hand-measuring step, and it's yours. Full walkthrough with the safety rules
and the animation:
[`guides/arm-envelope-explained/guide.md`](../../guides/arm-envelope-explained/guide.md).

1. Open the envelope guide's animation first so the idea clicks:

   ```
   guides/arm-envelope-explained/index.html
   ```

   (Double-click it to open in your browser, press **Replay**.)

2. With the **servo power switched OFF**, gently move each joint by hand to find its safe
   min and max — back off a few degrees from where it just reaches its own frame, the desk,
   or a wire. Write down min / max / center for all six joints. The guide walks every step.

3. Copy the template to your own calibration file:

   ```
   cp arm/calibration.example.json arm/calibration.json
   ```

4. Open `arm/calibration.json` and replace every `PLACEHOLDER` value with your measured
   numbers, and fill in `measured_by` and `measured_on`. (The tool refuses to run while any
   placeholder remains — that's on purpose.)

5. **Commit `arm/calibration.json`** once your real numbers are in. It's just servo angles —
   not personal data — and committing it is how Claude and reviewers learn your arm's true
   limits. See [`arm/README.md`](../../arm/README.md) for why. (Keep your identity out of it —
   `measured_by` can be a first name or nickname.)

**Verify:** run the tool with no arm connected. It should print your limits in the banner
and *not* complain about calibration:

```
python3 projects/arm-pen-plotter/teach_and_replay.py
```

If it prints "NO CALIBRATION FILE" or "TEMPLATE placeholder values", go back to Step 1.4.
Type `quit` to leave for now.

### Step 2 — Flash the Arduino sketch

1. Open `projects/arm-pen-plotter/pen_plotter_arm.ino` in the Arduino IDE.

2. **Read the wiring comment block at the top of that file before wiring anything.** The
   short version, and the part to **check yourself**:

   > External fused 5–6 V servo supply · shared ground to the Arduino GND · a fuse on the
   > supply's + lead · a reachable switch · servo signal wires to pins 3, 5, 6, 9, 10, 11 ·
   > **never the Arduino 5 V pin.**

3. Confirm the servo pin order in the sketch matches how you plugged them in:

   ```
   // 0 base   1 shoulder   2 elbow   3 wrist_tilt   4 wrist_rotate   5 gripper
   const int SERVO_PINS[NUM_JOINTS] = { 3, 5, 6, 9, 10, 11 };
   ```

4. Upload the sketch (the **Upload** arrow button). With the Serial Monitor at **115200**
   baud you should see:

   ```
   READY pen_plotter_arm -- send L limits, then S moves.
   ```

**Check this yourself (powered wiring):** before you switch on the servo supply, verify by
eye that the fuse is in the + lead, the grounds are shared, and the switch is within reach.
This is powered hardware — Claude flags it, you verify it.

### Step 3 — Print and fit the floating pen holder

1. Render the STL from the source. OpenSCAD isn't available in the environment that
   generated these files, so you make the STL yourself (about a minute):

   - Open `projects/arm-pen-plotter/pen_holder.scad` in **OpenSCAD**.
   - Set `pen_d` to *your* pen's measured barrel diameter, then press **F6** (full render).
   - **File → Export → Export as STL…**

2. Slice and print it (you slice, you start it, you watch it — nothing here prints
   unattended). It prints as **two loose parts**: the rail-with-mount and the pen sleeve.

3. Drop the sleeve into the rail — it should slide up and down freely by the `travel`
   amount. Clip the mount to your arm's end, fit the pen, and pinch the side screw so the
   tip pokes ~2–3 mm below the rail at rest. Start in **gravity** float mode (the pen's own
   weight is the down-force); only switch `float_mode` to `"spring"` if a light pen skips.

**Verify:** press the pen tip up with a finger — it should float up a few mm and settle
back down under its own weight. That float is what rides the uneven paper.

### Step 4 — Teach one straight line, then replay it

Now the payoff. Do this powered, hand on the switch, watching.

1. Start the tool, pointing it at your Arduino's serial port (`/dev/ttyUSB0` on Linux,
   something like `COM3` on Windows):

   ```
   python3 projects/arm-pen-plotter/teach_and_replay.py --port /dev/ttyUSB0
   ```

   It prints the safety banner, sends your safe limits to the board, and drops you into a
   `teach>` prompt.

2. Jog the arm to the **start of your line**, pen just touching the paper. Nudge one joint
   at a time (every nudge is clamped to your safe range):

   ```
   j shoulder 3
   ```

   ```
   j elbow -2
   ```

   (Use `set <joint> <angle>` for an absolute angle, `pose` to see all six, `help` for the
   full list.)

3. When the pen tip is where the line should **start**, record that waypoint:

   ```
   rec
   ```

4. Jog to the **end** of the line, keeping the pen down, then record again:

   ```
   rec
   ```

5. Save your two waypoints:

   ```
   save
   ```

6. Replay them slowly — hand on the switch, watch the whole move:

   ```
   replay
   ```

   The arm eases from the first waypoint to the second, drawing your line. It will **wobble**.
   That's not a bug — that's the machine. **Celebrate the wobble.**

**Verify:** you have a drawn line on the paper and a saved `waypoints.json`. That's the
whole pipeline proven end to end: calibration → clamp → serial → pen-down → move.

> Want to practise with no hardware first? Run without `--port` for a **dry-run**: it prints
> every move (and every clamp) instead of sending it. Great for learning the commands.
>
> ```
> python3 projects/arm-pen-plotter/teach_and_replay.py
> ```

---

## Honest expectations (read before you're disappointed)

This is an SG90/MG996R-class hobby arm. Servo slop **stacks** along the arm — a fraction of
a degree at the shoulder becomes millimetres of wiggle at the pen tip. Lines come out
visibly shaky and wavy. That is the identity of this machine, the same as BrachioGraph's
*"adorably wiggly"* output — not a defect to code away. First win: **one straight line**.
Then a square, then a circle. Portraits are out of scope for this servo class (the fine
detail is below the machine's resolution — it'd come out as mush).

## The road ahead (not built yet — this is the roadmap)

- **Step 4½ — tune the calibration curve.** As you draw squares and circles, the same
  commanded angle won't land in quite the same spot each way a joint reverses (that's
  *backlash* and *deadband*). A per-servo calibration curve
  ([numpy.polyfit](https://github.com/evildmp/BrachioGraph/blob/master/docs/explanation/hardware-limitations.rst))
  bakes in each joint's real quirks. A future script will fit it from measured points.
- **Step 5 — SVG → path → motion.** Draw a shape in Inkscape → `Path > Object to Path` →
  a Python script parses the points → scales them to your paper rectangle → runs each point
  through your calibration → streams **clamped** serial commands, pen-up between strokes.
  [ikpy](https://github.com/Phylliade/ikpy) (validated in simulation first) comes in only
  once a straight line already works — never hand-derive 6-DOF inverse kinematics on day one.

Both of those are *described here as the plan*, on purpose — they ship as their own small,
reviewable changes later, each with the clamp in the path.

## Safety recap (binding)

- No motion without `arm/calibration.json` **and** the clamp in the path. Both are enforced
  in code — the tool refuses without the file, and the one send function clamps every value.
- External fused 5–6 V supply · shared ground · reachable switch · **never** the Arduino 5 V pin.
- A human watches every powered move, hand on the switch. Nothing here is safe unattended.
