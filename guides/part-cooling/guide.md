# Part-cooling (the fan %) — freeze fresh plastic before it droops

**What this is:** the slicer setting that aims a fan at the plastic the instant it's printed — the invisible knob behind droopy overhangs, saggy bridges, blobby little points, and (on PETG) layers that split apart.

**Watch it instead:** open [index.html](./index.html) in this same folder — it animates the whole idea in about 20 seconds (an overhang drooping with no fan vs. holding with fan, a tiny point melting into a blob vs. staying crisp, and why PLA and PETG want opposite settings).

## What part-cooling actually is

Plastic leaves the nozzle hot and soft. For a fraction of a second after it's laid down it can still move — and gravity pulls it down. The **part-cooling fan** blows a breeze on that fresh plastic so it hardens before it can sag. More fan = the plastic freezes faster = sharper shapes. Less fan = the plastic stays warm longer = stronger bonding between layers. That trade — shape vs. strength — is the whole story.

First time you'll meet these words — one line each:

- **Part-cooling fan** — a small fan on the print head aimed at the freshly-printed plastic. Not the hot-end fan (which cools the printer's heater) and not a room fan.
- **Overhang** — a part of the print that leans out over empty space, with nothing under it to hold it up.
- **Bridge** — a flat span printed straight across a gap, like the top of a doorway.
- **Minimum layer time** — a slicer rule that says "spend at least N seconds on every layer." On tiny layers the printer slows down (and turns the fan up) so each one has time to set before the next lands on it.
- **Slicer** — the program that turns a 3D model into the instructions your printer follows. It's where the fan % lives.

## The one-value experiment

The honest way to find your fan number is to change *only the fan* and print the same little test three times, then look at the undersides side by side.

### 1. Get an overhang/bridge test model

Any of these prints the shapes that cooling actually affects:

```
#3DBenchy — the classic boat; its bow and cabin roof are an overhang + bridge torture test
All-in-one calibration (majda107) — Thingiverse thing 2656594 — has a dedicated overhang + bridging section
```

> ⚑ Tell me which slicer you use and I'll paste the exact click-by-click path for the next steps — the
> menu names differ between slicers, and I'd rather paste your exact clicks than make you hunt.

### 2. Slice it once at fan 0 %

Load the model, set your normal settings for your filament, and set the part-cooling fan to:

```
Fan speed: 0 %
```

Save this file with a name you'll recognise:

```
overhang-fan-000.gcode
```

### 3. Slice the same model at fan 50 %

Change **only** the fan, nothing else:

```
Fan speed: 50 %
```

Save as:

```
overhang-fan-050.gcode
```

### 4. Slice it once more at fan 100 %

Again, change only the fan:

```
Fan speed: 100 %
```

Save as:

```
overhang-fan-100.gcode
```

### 5. Print all three (you slice, you start, you watch)

Print each file. Keep the first layer's fan low no matter what — a cold breeze on the very first layer hurts how well the print sticks to the bed:

```
First-layer fan: 0 % (raise to ~25 % only if you see first-layer problems)
```

> **Check this yourself.** Claude never sends G-code to your printer and never marks a print "safe to run unattended." You slice it, you start it, and you stay with the printer while it runs — especially for a back-to-back test batch like this.

### 6. Read the three undersides

Line the three prints up and turn them over. Reading from fan 0 % up to 100 %, you're looking for the point where more fan stops helping:

```
Too little fan  → overhang underside is rough, droopy, "melted" looking; small points blob over
Just right      → underside is clean and flat; points are crisp; layers still feel solidly bonded
Too much fan    → (mostly PETG/ABS) layers look great but split apart easily; corners lift/warp
```

Your number is the lowest fan % that gives a clean underside without weakening the layers.

## Minimum layer time — the fix for blobby little points

Fan % is a *how hard* setting. **Minimum layer time** is a *how long* setting, and it fixes a different problem: tiny tips and thin towers. When a layer is small, the printer races around it in a split second and immediately lands the next layer on plastic that's still molten — so the tip melts into a blob. Minimum layer time tells the slicer to slow down (and lean on the fan) so every layer gets a few seconds to set.

A common starting point:

```
Minimum layer time: 5–10 seconds
```

> ⚑ This setting lives in every slicer, usually under "Cooling" or "Speed." Tell me your slicer and I'll
> paste the exact name and where to click.

## Fan % by material — starting points, not gospel

Cooling helps shape but can cost layer strength, so each filament wants a different amount. Start here, then run the experiment above to fine-tune for your printer:

```
PLA   — first layer 0 %, then ~100 %   (fuses easily; loves max cooling for sharp shapes)
PETG  — ~30–50 %, higher only for overhangs   (too much fan makes layers brittle and split)
ABS   — 0–20 %, often none   (cooling causes cracking and warping; usually printed in an enclosure)
TPU   — ~20–50 %   (flexible; moderate cooling helps detail without over-stiffening)
```

> **Check this yourself.** These are typical starting numbers from community guides, not settings for your
> exact filament. Your spool's maker often prints a recommended range on the label or spec page — that
> beats any general table, including this one.

Why the split, in one line each:

- **PLA** has strength to spare, so it can spend its whole "cooling budget" on freezing shapes fast.
- **PETG** must hold some cooling back — its strength comes from layers staying warm long enough to weld together.
- **ABS** is so prone to cracking from a sudden chill that it's usually printed warm, in an enclosure, with little or no fan.
- **TPU** is flexible and forgiving; a moderate breeze sharpens detail without making it too stiff.

## Sources

- 3DPut — *PLA 3D printing settings: temperature, speed and cooling* — https://3dput.com/pla-3d-printing-settings-guide-temperature-speed-and-cooling-for-perfect-prints/
- 3DPut — *3D printing overhangs and bridges: settings and techniques* — https://3dput.com/3d-printing-overhangs-and-bridges-settings-and-techniques-for-perfect-results/

**Verify:** you can hold up three prints of the same model — fan 0 %, 50 %, 100 % — and point to the one with the cleanest overhang underside. That fan % (kept low on the first layer) is your number for that filament.

## How to open the animation

The animation is a single file — nothing to install, nothing goes online.

1. In this folder, double-click `index.html`. It opens in your web browser.
2. Press **▶ Play all** to watch it run start to finish, or step through with **Next step ▶** and **◀ Back**. **↻ Replay** starts it over.
3. If you're reading this on GitHub, click `index.html` in the file list, then the **Download** (raw) button, and open the downloaded file — GitHub won't run the animation in its preview, but your browser will.