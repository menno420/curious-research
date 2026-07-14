# First layer — the foundation everything else is built on

**What this is:** the one layer that decides whether a print sticks or fails — how to read it,
and the two dials (the nozzle-to-bed gap and the first-layer speed) that get it right, tonight.

**Watch it instead:** open [`index.html`](./index.html) in your browser — it animates this whole
page in about 20 seconds, in side-view cross-section. (How to open it is the last line of this
page.)

## In bench terms

The first layer is the layer of glue every other layer stands on. Every wall, every bit of
detail, every hour of print above it is only as solid as the layer touching the bed. Nail this
one layer and roughly **90% of beginner print failures — the ones that won't stick, or curl up
and pop off halfway — simply disappear.** It is the single highest-value thing to get right, and
you can dial it in tonight with nothing but your printer and a clean bed.

First time you'll meet these words — one line each:

- **nozzle-to-bed gap / Z-offset** — the tiny distance between the nozzle tip and the bed on the
  first layer. "Z-offset" is the setting that fine-tunes it (Z is the up-down axis).
- **squish** — the gentle flattening as the nozzle presses each line down onto the bed.
- **elephant's foot** — a squashed-out bulge at the very bottom edge when the first layer is
  pressed down too hard.
- **adhesion** — how well the print grips (sticks to) the bed.
- **brim** — a thin flat collar of plastic printed around the part's base for extra grip, peeled
  off after.
- **bed leveling** — setting the nozzle-to-bed gap the same at every corner so the whole first
  layer squishes evenly.
- **first-layer speed** — how fast the nozzle moves while laying that first layer (usually set
  separately from the rest of the print).

## The honest #1 fix first: a clean bed

Before any setting: **most "it won't stick" problems are a dirty bed, not a bad printer.** Skin
oil from your fingers is invisible and it kills adhesion. So, first:

```
Warm water + a drop of dish soap → rinse → dry.  (or: 90%+ IPA on a paper towel)
```

Then **stop touching the print surface with bare fingers** — handle the plate by its edges. Do
this one thing and a surprising number of first-layer problems never happen.

> IPA = isopropyl alcohol, the "rubbing alcohol" cleaner; 90%+ evaporates clean without leaving
> a film.

## Steps

Do one step, check what it says you should see, then move to the next.

### 1. Clean the bed

Do the clean-bed step above first — warm water + a drop of dish soap, rinse, dry; then handle the
plate by its edges only. A clean bed is the foundation of the foundation.

### 2. Level the bed / set the Z-offset (the paper-drag method)

Getting the gap the same at every corner is called **leveling**. The classic feeler is a plain
sheet of paper slid under the nozzle at each corner:

```
Slide a sheet of paper under the nozzle at each corner.
Adjust until you feel SLIGHT friction — the paper drags a little,
but still slides.  Not free (too far).  Not pinned (too close).
```

That slight drag is the "just right" gap you saw in the animation. Set it the same at every
corner (and the middle, if your printer asks).

> Many printers do this automatically ("auto bed leveling" / a bed probe). If yours does, run its
> routine — the paper-drag method is the manual version and a good sanity check either way.
> A **bed probe** = a sensor that measures the gap for you automatically.

### 3. THE ONE-VALUE EXPERIMENT: slow the first layer down

This is the single change that fixes the most first layers. Drop the first-layer speed to about
half your normal speed:

```
First layer speed: 20 mm/s   (down from a typical ~50 mm/s)
```

A slow first layer gives each line time to press onto the bed and bond, instead of being dragged
loose. This setting lives under **Speed → First layer** (or "Initial layer speed", or similar) in
every slicer — it exists in all of them, the name just varies.

> ⚑ Tell me which slicer you use and I'll paste the exact click-by-click path here — the menu
> names differ between slicers, and I'd rather paste your exact clicks than make you hunt.

### 4. Print a one-layer test

You only need to judge the *foundation*, so don't print a whole model. Slice a **20 mm square to a
single layer height**, or start the first layer of a **20 mm cube** and cancel the print after
layer 1.

```
20 mm square, one layer tall  (or: first layer of a 20 mm cube, then cancel)
```

Why: you're only reading the first layer, so print only the first layer — it's a 60-second test,
not a lost hour.

### 5. Read the squish (what you see)

Take a close look at the test square. Match it to one of these three:

- **TOO FAR** — separate round lines you can see between, gaps, maybe a corner already curling up.
  Not enough squish; it won't stick.
- **TOO CLOSE** — translucent or torn lines, ridges, very little plastic, and an **elephant's-foot**
  bulge at the edges. Too much squish; starved of plastic — the little plastic that does escape
  squeezes out sideways at the base, and that side-squeeze is the elephant's foot.
- **JUST RIGHT** — the lines have merged into one smooth sheet with a uniform sheen, and it sticks
  hard. This is the target.

### 6. Adjust live with baby-steps (Z-offset)

Most printers let you nudge the Z-offset **while the first layer is printing** ("baby-stepping"),
so you can dial it in on the next test without re-leveling. Change it a hair at a time:

```
Too far (not sticking):  nudge nozzle DOWN 0.05 mm, retest
Too close (scraping):    nudge nozzle UP 0.05 mm, retest
```

0.05 mm is tiny on purpose — the whole "just right" window is a fraction of a millimetre, so small
nudges land it; big jumps overshoot.

### 7. Bed temperature

If a clean bed, a level gap, and a slow first layer still aren't quite enough, a warm bed helps
the first layer grip. A rough starting point per material:

```
PLA bed:  ~60 °C      PETG bed:  ~70–80 °C     (check your filament's label)
```

> **Check this yourself.** These are hot surfaces and rough starting numbers only — the real value
> is on your filament's label and box. Confirm it against your own spool before you print; don't
> take a number from a guide (including this one) as gospel.

### 8. A brim

For small-footprint parts, a brim — a flat collar welded to the part's edge — gives more grip and
peels off cleanly after:

```
Brim: 5 mm   (a flat collar welded to the part's edge — more grip, peels off after)
```

> ⚑ Both of these — bed temperature (step 7) and a brim (step 8) — live in every slicer, under
> "Material"/"Filament" and "Build Plate Adhesion" (or similar). Tell me your slicer and I'll paste
> the exact clicks.

## Safety — check this yourself

- **You** level the bed, **you** slice, **you** start the print, and **you** watch it. Claude
  never sends print instructions (G-code) to your printer.
- **Never leave a print running unattended** — nothing here is "safe to print unattended".
- The **bed and the nozzle are hot enough to burn.** The bed temperatures above are hot surfaces;
  confirm every temperature against your own filament and hot-end (the heated nozzle assembly the
  filament melts in) before you print.

## Sources

- Simplify3D — *Print not sticking to the bed* — <https://www.simplify3d.com/resources/print-quality-troubleshooting/not-sticking-to-the-bed/>
- Sovol — *Fix first-layer problems (easy steps guide)* — <https://www.sovol3d.com/blogs/news/fix-first-layer-problems-3d-printing-easy-steps-guide>
- Raise3D — *3D printing speed* — <https://www.raise3d.com/blog/3d-printing-speed/>
- Teaching Tech — *Calibration* — <https://teachingtechyt.github.io/calibration.html>

**Verify:** you're done when your test square shows lines that have merged into one smooth,
well-stuck sheet — no gaps, no torn ridges, no curling corner — and it takes a real tug to lift
off the bed.

## How to open the animation

Double-click `guides/first-layer/index.html` — it opens in your web browser. Nothing is installed,
and nothing goes online. Press **Play all** to watch it, or **Next step ▶** to walk through one
idea at a time. (On GitHub, tap `index.html` → the **⋯** menu → *Download*, then open the
downloaded file in any browser.)
