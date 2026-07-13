# Print & test the tolerance coin — step by step

> Goal: end up with **one number per printer + filament** — the clearance that
> gives you the fit you want — written down and reusable forever.
>
> New words are explained the first time they appear. Every command or menu path
> is in its own block so you can copy it, never retype it.

Want to watch the idea move first? Open the explainer:
[`guides/how-print-clearance-works/`](../../guides/how-print-clearance-works/).

---

## Part A — turn the model into a printable STL

The design lives in a text file, `tolerance-test-coin.scad`. **OpenSCAD** (a free
program that turns that text into a 3D shape) makes the printable **STL** (the
standard 3D-model file your slicer reads).

**Step 1 — install OpenSCAD (once).**
Download it from the official site and install like any other program:

```
https://openscad.org/downloads.html
```

You should see an "OpenSCAD" application after installing.

**Step 2 — open the model.**
Launch **OpenSCAD**. Click **File ▸ Open**, and choose:

```
projects/tolerance-test-coin/tolerance-test-coin.scad
```

You should see the model code on the left and a preview area on the right.

**Step 3 — render it.**
Press **F6** (or menu **Design ▸ Render**). A round coin full of holes, plus 3
little pins beside it, appears. Numbers (0.10, 0.15 …) are engraved under each
hole — those are the **clearances** in millimetres.

> **Clearance** = the air gap left between two parts so they fit. The number under
> each hole is the gap **per side** (more on that in Part D).

**Step 4 — export the STL.**
Click **File ▸ Export ▸ Export as STL…**. Save it as:

```
tolerance-test-coin.stl
```

Verify: you now have a `tolerance-test-coin.stl` file next to the `.scad`.

> Want a different size or gap range? Change the values at the top of the `.scad`
> (they're labelled `EDIT THESE`), press **F6** again, and export again. Or just
> tell Claude what you want and it'll adjust the file for you.

---

## Part B — slice and print

**Slicer** = the program that turns an STL into printer instructions (**G-code**).
PrusaSlicer, Bambu Studio, Cura — whichever you use.

**Step 5 — load the STL.**
Open your slicer and drag `tolerance-test-coin.stl` onto the plate.

**Step 6 — turn ON elephant-foot compensation.** *(This matters — read it.)*
The first layer of a print gets squished wider than the rest because the nozzle
presses it into the hot bed. That bulge is called **elephant's foot**, and it makes
the *bottom* of every hole and pin tighter than the top — which would lie to you
about the fit. Your slicer can shrink the first layer to cancel it:

- **PrusaSlicer:** *Print Settings ▸ Advanced ▸ Elephant foot compensation* → set
  `0.2` mm.
- **Bambu Studio:** *Quality ▸ Precision ▸ Elephant foot compensation* → set
  `0.2` mm.
- **Cura:** search settings for **Initial Layer Horizontal Expansion** → set
  `-0.2` mm (negative shrinks it).

**Step 7 — normal settings, then slice.**
Use your everyday PLA profile and layer height (e.g. 0.2 mm). Click **Slice**. The
whole thing prints in roughly 15–30 minutes.

**Step 8 — print it.** *(Check this yourself.)*
Send it to the printer, load your filament, **start the print, and stay with it** —
watch the first layer go down cleanly. Claude never starts a print; that click is
yours.

Verify: you have a printed coin and 3 loose pins in your hand.

---

## Part C — feel the fit and read your number

Do this with the coin at room temperature (warm plastic reads looser).

**Step 9 — try one pin in every hole.**
Take one loose pin. Push it into each hole in turn, smallest number first. Feel
which of these it is, and note it against the number engraved by that hole:

| Feel | What it means | Name |
|---|---|---|
| Won't go / needs a hard push | too tight to use | **interference** |
| Firm push, holds, no wobble | stays put on its own | **press fit** |
| Slides in snug, no side-to-side play | guided but movable | **snug / push fit** |
| Slides freely, tiny bit of play | moves easily | **sliding fit** |
| Drops in, rattles | falls out | **loose fit** |

**Step 10 — write your numbers down.**
Open [`clearance-results.md`](./clearance-results.md) and fill in the row for this
printer + filament:
- the tightest gap that still **presses in and holds**,
- the gap that **slides with no wobble**,
- the gap that drops in **loose**.

That's the whole test.

---

## Part D — make it compound (this is the point)

**Step 11 — the per-side gotcha.**
The number under each hole is the gap on **one side**. In a real two-part fit,
*both* parts contribute, so the total slack between them is roughly **double** the
engraved number. If your snug reading is `0.20`, a hole you design for a shaft
should be `shaft_radius + 0.20` — not `+0.10`, and not `+0.40`. Getting this
backwards is the classic "why is it twice as loose as I expected."

**Step 12 — turn your reading into a reusable constant.**
In OpenSCAD you set the gap once and every hole in every future design uses it:

```
clearance = 0.20;   // <-- YOUR snug number from step 10, per side

module shaft_hole(shaft_r, depth) {
    cylinder(h = depth, r = shaft_r + clearance);
}
```

Change printer or filament later? Change that one line.

**Step 13 — hand your numbers to Claude.**
Tell Claude your press / snug / loose gaps for this printer + filament. Claude keeps
them on file and drops the right one into every future design that has to fit
together — servo horns for the arm, a battery lid, a box that actually closes.

Verify (the whole exercise worked): `clearance-results.md` has at least one filled
row, and you can say out loud "on *this* printer in *this* filament, a snug fit is
___ mm per side."

---

## The honest limit

This gives you a **strong starting number for that printer + that filament** — not
a universal constant. Fit also shifts with temperature, print speed, and part
shape. Swap to a very different filament or print much hotter and re-run the coin.
You still start far closer than a guess. (Full reasoning:
[`ideas/tolerance-test-coin.md`](../../ideas/tolerance-test-coin.md), question 4.)
