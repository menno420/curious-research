# Infill — what's inside your print, and how much you actually need

> **Watch it first:** open `guides/infill/index.html` in your browser to see a
> cutaway of a print filling in with different patterns. Then come back here for
> the hands-on experiment. (How to open it is at the bottom.)

Almost every print is **hollow inside**. Not empty — filled with a light lattice
called **infill**. The slicer draws just enough plastic inside to hold the top and
walls up, and leaves the rest as air. The single most-asked beginner question is
*"what infill percentage should I use?"* — and the honest answer surprises people:

**Usually way less than you think. The walls matter more than the percentage.**

This guide shows you why, and gives you one small experiment to prove it to
yourself tonight.

## Bench terms (each explained once)

- **Infill** — the lattice of plastic inside a print. Air + a little plastic.
- **Infill density (%)** — how much of the inside is plastic vs air. 0 % = hollow,
  100 % = solid. 15–20 % is the everyday default.
- **Infill pattern** — the *shape* of that lattice (grid, gyroid, lines…).
- **Wall / perimeter** — the solid outline the nozzle traces around each layer.
  "3 walls" means it traces the outline 3 times, making a thicker skin.
- **Top/bottom layers** — the solid caps on the flat faces. Infill holds these up.

## The one thing to remember

A print is strong because of its **walls and top/bottom layers**, not because it's
packed solid inside. Testing by CNC Kitchen (a well-known 3D-printing test channel)
found that **adding one more wall makes a part stronger than adding 20 % more
infill** — and it uses less plastic and less time doing it. Infill mostly stops the
flat top from sagging and gives the walls something to lean on.

So the winning move for a stronger part is usually: **keep infill low, add a wall.**

⚑ Where to set wall count:
- **Cura:** Walls → *Wall Line Count*
- **PrusaSlicer / OrcaSlicer:** Layers and perimeters → *Perimeters*
- **Bambu Studio:** Strength → *Wall loops*

Copy this as your starting point for a "needs to be sturdy" part:

```
Infill density: 15%
Wall count / perimeters: 3   (default is usually 2)
Top/bottom layers: 4–5
```

## The experiment — 10 % vs 30 %, and let the parts tell you

You'll print the **same small model twice**, changing only the infill number, then
weigh, squeeze, and time each. One value changed — that's the whole method.

**Step 1 — Pick a small model.** A 2–3 cm cube or a small bracket. Small so each
print is quick and cheap.

**Step 2 — Slice it at 10 % infill.** Open your slicer, load the model, find the
infill density setting, set it to:

```
10
```

⚑ Where the infill setting lives:
- **Cura:** Infill → *Infill Density*
- **PrusaSlicer / OrcaSlicer:** Infill → *Fill density*
- **Bambu Studio:** Strength → *Sparse infill density*

Note the **estimated print time** and **filament used** the slicer shows you. Write
them down:

```
10% infill  →  time: ______   filament: ______ g
```

**Step 3 — Slice the SAME model at 30 % infill.** Change only that one number to:

```
30
```

Write down the new estimate:

```
30% infill  →  time: ______   filament: ______ g
```

Already, before printing, you'll see the 30 % version costs more time and plastic.

**Step 4 — Print both.** Load your filament, start each print yourself, and watch
the first layer go down. *(You start every print — see safety below.)*

**Step 5 — Read the results with your hands.**
- **Weigh them** on a kitchen scale. The 30 % one is heavier — that's the extra
  plastic you paid for.
- **Squeeze them** between finger and thumb. For most small parts you'll struggle
  to feel a difference. That's the point: the walls are doing the work.
- **Compare the times** you wrote down. The 30 % print took noticeably longer.

**Step 6 — Now try the real fix.** Slice the model once more at **10 % infill but
one extra wall** (2 → 3). Print it, squeeze it. *That* one feels stiffer — for less
plastic than the 30 % version used.

## Pattern cheat-table (pick by what the part is for)

Infill *pattern* changes the shape of the lattice. You rarely need to change it, but
here's when each earns its keep:

| Pattern | What it's good at | Reach for it when |
| --- | --- | --- |
| **Grid** | Fast, strong enough, the sensible default | You're not sure — leave it here |
| **Gyroid** | Equal strength in every direction, no weak seams, a bit flexible | Parts that flex or get squeezed from odd angles; light-but-tough |
| **Lines / Rectilinear** | Fastest, least plastic, weakest | Display pieces that never get handled hard |
| **Concentric** | Follows the outline, stays bendy | Flexible (TPU) parts you *want* to keep soft |

⚑ Pattern setting: **Cura** *Infill Pattern* · **PrusaSlicer/OrcaSlicer** *Fill
pattern* · **Bambu Studio** *Sparse infill pattern*.

## Rough cost of turning the dial up

Infill percentage adds plastic and time in a roughly straight line, so doubling the
percentage roughly doubles the infill's share of both. As a ballpark for a typical
small part (your own slicer's estimate is the real answer — read it every time):

```
 0%  — hollow, needs support under the top; fragile
10%  — light, fine for most display + light-duty parts
15–20% — the everyday default; good balance
30–50% — noticeably heavier & slower; for parts under real load
100% — solid; slow and heavy; almost never worth it — add walls instead
```

The jump from 20 % to 100 % can multiply the infill's plastic and time several times
over for very little extra real-world strength. Diminishing returns kick in fast.

## Check this yourself (safety)

- **You slice, power, and start every print. Claude never sends a print to the
  machine and never marks anything "safe to run unattended."** Stay with the first
  layer.
- Higher infill = longer print = the machine runs hotter for longer. Don't leave
  long prints unattended.
- These numbers are safe starting points, not a guarantee for *your* printer,
  filament, and model. Change one value, watch, and trust what the parts tell you.

## Sources

- CNC Kitchen — *Infill vs. Wall thickness: which makes a stronger print?* and
  related strength tests (walls beat infill % for strength).
- Prusa Knowledge Base — *Infill patterns* (pattern strength/speed trade-offs).
- Your own slicer's time & filament estimate — the most honest source for *your*
  part.

## Verify

You've got this if: you can point at your two printed cubes, say which is heavier
and why, and explain in one sentence why adding a wall beats cranking infill. If you
can, the guide worked.

## How to open the animation

1. In GitHub, open the folder `guides/infill/`.
2. Click `index.html`, then click the **Raw** button (top-right of the file view).
3. It opens and plays in your browser — press **Replay** to watch it again. Nothing
   to install.
