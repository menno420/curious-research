# Temperature tower — one print that finds your best nozzle heat

**What this is:** a single tall test print that sweeps the nozzle temperature from hot to cool,
so you can read it band by band and pick the temperature that prints your filament cleanest.

**Watch it instead:** open [`index.html`](./index.html) in your browser — it animates this whole
page in about 20 seconds, band by band. (How to open it is the last line of this page.)

## What a temperature tower is

A temperature tower is one tall part sliced into stacked bands, and each band is printed a few
degrees cooler than the band below it. You print it once, then look at the finished tower and
find the band that came out cleanest — that band's temperature is the one to use. It turns
"what temperature should I use?" into "which band looks best?", which your eyes can answer.

First time you'll meet these words — one line each:

- **nozzle** — the brass tip the melted plastic comes out of.
- **stringing** — thin plastic hairs left behind as the nozzle travels from one spot to another.
- **bridging** — plastic printed straight across open space with nothing underneath to hold it up.
- **layer adhesion** — how well each printed layer fuses to the one below it.
- **under-extrusion** — not enough plastic coming out, so you get gaps and a thin, rough surface.

## Why print one

It finds your best nozzle temperature with **one** print instead of guessing, or instead of
printing the same model five times at five temperatures. Too hot and the plastic oozes (strings
and blobs); too cold and it won't fuse (weak layers, sagging bridges). The tower shows you both
extremes and the sweet spot in between, all on one part.

## What you need

- Your printer.
- A spool of filament (the plastic you want to dial in).
- Your **slicer** — the program that turns a 3D model into instructions your printer can follow.
- A temperature-tower model to print (step 1 shows how to get one).

## Steps

Do one step, check what it says you should see, then move to the next.

### 1. Get a temperature-tower model

Many slicers include a built-in temperature (or "calibration") tower generator. If yours does,
use that. If it doesn't, download a temperature-tower model file (an `.stl` — a plain 3D shape
file) from any model-sharing site and open it in your slicer.

You should see a tall, narrow tower on your build plate, usually with little test features
(overhangs, small bridges, text) on each level.

> ⚑ Tell me which slicer you use and I'll add the exact click-by-click path here — the menu
> names differ between slicers, and I'd rather paste your exact clicks than make you hunt.

### 2. Find your filament's safe temperature range

Read the number printed on the **spool** or its box. It's usually a range, for example a PLA
spool might say:

```
190–220 °C
```

Write that range down — you'll sweep across it in the next step.

> **Check this yourself.** Never set the nozzle hotter than the filament's printed rating **or**
> your hot-end's rating, whichever is lower. Hot-end temperatures are a real burn-and-hardware
> risk, so confirm the numbers against your own spool and your own printer before you print —
> don't take a number from a guide (including this one) as gospel.

### 3. Set the tower to sweep that range

Tell the tower to change temperature as it gets taller — hottest at the bottom, stepping cooler
toward the top. A common setup is a new temperature every set height, for example:

```
Start 220 °C at the bottom → drop 5 °C each band → 195 °C at the top
```

In your slicer, look for a **temperature** setting that changes per band, or a **height-range**
setting (a rule that changes one setting once the print passes a certain height). Set it to walk
across the range you wrote down in step 2.

You should see each level of the tower labelled with (or assigned to) a different temperature.

> ⚑ Same offer as step 1 — tell me your slicer and I'll paste the exact setting names and clicks
> for making the tower step temperature by height.

### 4. Slice it

Turn the model into printer instructions (this is called slicing), then print it.

> **Safety — read this before you print.** Claude never sends print instructions (G-code) to
> your printer. **You** slice it, **you** start the print, and **you** watch it. Never leave a
> print running unattended, and nothing here is "safe to print unattended" — a temperature tower
> deliberately prints some bands badly on purpose, so keep an eye on it.

### 5. Read the result

Take the finished tower off the plate and look at it band by band, from hot (bottom) to cool
(top). What to look for:

- **A bad hot band:** fine hairs (strings) between features, little blobs, a shiny over-melted look.
- **A bad cold band:** a rough, gappy surface, layers you can pick apart with a fingernail, and
  bridges that **sag** in the middle.
- **A good band:** flat bridges that span the gap without drooping, no strings to pick off, and
  solid layers that feel like one piece.

The single clearest tell is the little **bridge** on each band: it sags when the plastic is too
cold and stays flat when the temperature is right.

### 6. Pick your temperature

Choose the band that looks cleanest — good flat bridges, no strings, strong layers. Find the
temperature assigned to that band. **That temperature is the one to set for this filament from
now on.**

Keep a note per spool: a different filament — even the same type in a different brand or colour —
can want a different number, so don't assume one temperature covers everything.

## Verify

You're done when you can point at one band on the tower and say **"that's my temperature for this
spool."**

## How to open the animation

Double-click `guides/temperature-tower/index.html` — it opens in your web browser. Nothing is
installed, and nothing goes online. Press **Play all** to watch it, or **Next step ▶** to walk
through one band at a time. (On GitHub, tap `index.html` → the **⋯** menu → *Download*, then open
the downloaded file in any browser.)
