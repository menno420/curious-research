# Lithophane night-light — from a photo to a glowing print

A **lithophane** is a thin plastic panel whose thickness changes across a picture: thick
spots block the light and look dark, thin spots let light through and look bright. Stand one
in front of a small LED and a photo glows into view — a picture made of shadow. This guide
takes you the whole way: **photo → free web tool → 3D model → slice → print → light it up.**

> **Watch it first (2 minutes):** open `index.html` in this folder (double-click it — it
> opens in your web browser, no internet needed) and press **Play**. It animates *why*
> thickness becomes brightness, and *why* you print the panel standing up. Then come back here
> for the exact steps.

> **Safety — this one's simple, but it's a rule:** *you* slice, start, and watch every print.
> Claude never sends a print to your machine and never calls a print safe to leave running
> alone. The only powered part here is a small light — keep it low-voltage (USB or battery),
> covered under Part D.

---

## Bench terms (each explained once, here)

- **STL** — the 3D model file. The web tool spits one out; your slicer reads it.
- **Slicer** — the program that turns a 3D model into the move-by-move instructions your
  printer follows (PrusaSlicer, Bambu Studio, Cura, OrcaSlicer are all slicers).
- **Layer height** — how thick each printed layer is. Smaller = finer detail, longer print.
- **Infill** — the fill inside a part. 100% = completely solid.
- **Brim** — a thin flat skirt of plastic printed around the base to stop a tall thin part
  from tipping over mid-print. It peels off after.
- **Orientation** — which way up the part sits on the printer bed.

---

## What you'll need

- **A light source** — a battery **LED tealight** (~$2–3) or a small **USB LED panel**. Both
  are low-voltage and safe to sit right behind the plastic. (Details in Part D.)
- **Filament** — for your first one, any single color you already have. White or a light color
  reads best.
- **A photo** — high contrast, one clear subject, not too busy. Faces, pets, and landscapes
  with a bright sky all work well.
- **Free tools** — a lithophane web generator (Part A) and your normal slicer (Part B).

---

## Part A — Turn your photo into a 3D model (free, in your browser)

The generator does the hard part: it reads your photo's light and dark and builds a panel
that's thin where the photo is bright and thick where it's dark.

Any of these free browser tools work — [**ItsLitho**](https://itslitho.com/) is a good default,
with [3dp.rocks/lithophane](https://3dp.rocks/lithophane/) and
[LithophaneMaker](https://www.lithophanemaker.com/) (which has a dedicated night-light shape)
as alternatives. Steps below use ItsLitho; the others have the same knobs under similar names.

> **Heads-up on your photo:** it uploads to a third-party website (not to this repo, and not
> to Claude). Use a photo you're comfortable putting online. Nothing personal ever goes into
> this project's files.

1. Open **[itslitho.com](https://itslitho.com/)** and click **Start creating** (or **Create**).
2. Click **Upload** and choose your photo.
3. Choose the shape **Plate** (a flat standing panel) for your first one.
4. Set the **size**. A good first size is about 100 mm on the long edge — big enough to see,
   quick enough to print:

   ```
   Width: 100 mm
   ```

   *Why:* small enough to print in a few hours, big enough that the picture reads clearly.

5. Set the **thickness window** — this is the single most important setting. The whole picture
   lives between a thin "brightest" value and a thick "darkest" value:

   ```
   Thinnest point (brightest): 0.8 mm
   ```

   *Why:* the highlights. Thinner than this and even the light areas get fragile and can glow
   too evenly.

   ```
   Thickest point (darkest): 3.2 mm
   ```

   *Why:* the deep shadows. Thicker than this and no light gets through at all — the darks just
   go black and flat.

6. Keep the image **positive** (not inverted) for a backlit night-light. If the preview looks
   like a photo negative, toggle **Invert / Negative** once.
7. Click **Download** and choose **STL**. Save it somewhere you'll find it. That `.stl` file is
   your model.

*(3dp.rocks and LithophaneMaker: same idea — upload, set "Model" to a flat/plate type, set
"Thickness/Maximum" to ~3.2 mm and "Thickness/Minimum" (or "Base") to ~0.8 mm, then export STL.)*

---

## Part B — Slice it (settings that make or break the picture)

Open your slicer and load the `.stl` from Part A. These settings matter more than which slicer
you use — set each one, and it'll come out great. Each value has a one-line reason.

> Tell me which slicer you use and I'll add an exact, click-by-click version with your menu
> names — until then this is written to work in any of them.

1. **Stand it upright.** Rotate the panel so it stands vertically on its edge, tall side up —
   not lying flat on the bed.

   ```
   Orientation: vertical (standing on its long edge)
   ```

   *Why:* your printer's side-to-side detail is far finer than its layer-to-layer detail.
   Upright, each layer is a thin vertical stripe and the tones look smooth; flat, the tones
   climb in coarse steps you can see. (The `index.html` animation shows exactly this.)

2. **Set a fine layer height.**

   ```
   Layer height: 0.12 mm
   ```

   *Why:* fine enough that the stripey layer lines blur into smooth tone. 0.2 mm is the
   coarsest that still looks acceptable; 0.12 mm is the sweet spot.

3. **Fill it solid.**

   ```
   Infill: 100%
   ```

   *Why:* any hollow pocket inside shows up as a blotch when the light shines through. Solid =
   even glow. (Lots of walls with 0% infill also works, but 100% infill is the simple version.)

4. **Add a brim.**

   ```
   Brim: on, 5–8 mm wide
   ```

   *Why:* a tall thin panel is tippy. A brim glues the base down so it can't fall over partway
   through. It peels off after printing.

5. **Slow it down.**

   ```
   Print speed: ~30 mm/s
   ```

   *Why:* slow printing holds the fine detail that makes the picture look like a photo instead
   of a smudge.

6. Click **Slice**, then open the **Preview**. Scrub to the first layer and check it's one
   clean solid sheet with the brim around it. If it looks right, you're ready.

---

## Part C — Print it (you drive)

1. Load your filament (white or a light color for the first one).
2. Send the sliced file to the printer **yourself** and **start it yourself**.
3. Watch the **first layer** go down — that's where prints succeed or fail. It should be a
   smooth, fully-filled base with the brim attached, no gaps.
4. Let it finish, let it cool, then gently peel off the brim.

*Claude never starts your printer and never marks a print safe to leave alone — starting and
watching are yours.*

---

## Part D — Light it up (the backlight)

The panel is just plastic until light comes through it. Two easy, safe options:

- **Battery LED tealight (easiest).** A flickery or steady LED tealight, ~$2–3. Set it a
  couple of centimetres behind the standing panel. No wiring, low-voltage, safe against
  plastic.
- **USB LED panel or strip.** A small 5 V USB LED gives a more even, brighter wash. Diffuse
  (frosted) light looks better than a single bright dot — a little distance behind the panel
  spreads it out.

**Filament color:** white or a light color transmits the most light and reads most like a real
photo. A warm-white LED behind white filament looks cozy; a cool-white LED looks crisp. Skip
dark filament for your first one — it barely lets light through.

> **Check this yourself (safety):** keep the light **low-voltage** — USB or battery only. Never
> put a mains-powered bulb or anything that gets warm right against the plastic; PLA softens
> and warps with heat. If you ever want to wire something to mains power, that's the one part
> to hand to someone qualified and verify yourself. Claude flags it; you check it.

**You're done when:** with the room lights low, you stand the printed panel in front of the lit
LED and the photo appears — bright where the plastic is thin, dark where it's thick. That's the
whole trick, working.

---

## Stretch goal — full color with HueForge (eyes open)

A plain lithophane is grayscale by nature: thickness only makes light and dark, never hue. The
famous *full-color* glowing photos are a different, harder trick called **HueForge** — software
that stacks a few colored filaments and uses how much light passes through each thin layer to
blend them into a color image. Your 3-color printer is exactly the machine people reach for
here, but go in knowing the real costs:

- **It's paid software.** HueForge is **not free** like the generators in Part A
  ([what HueForge is](https://huepick.app/what-is-hueforge)).
- **It wastes filament.** Every color swap purges the nozzle. On a multi-material printer that
  adds up fast — one small Bambu demo cube threw away about **83 g of purge for an 11 g part**
  ([reducing AMS waste](https://p3d.mx/blogs/how-to-3d-print/reducing-bambu-lab-poops)). You
  can tune it down ([Bambu Studio: reduce waste](https://wiki.bambulab.com/en/software/bambu-studio/reduce-wasting-during-filament-change)),
  but never to zero.
- **It needs a curated palette** — filaments whose light-transmission values are known, so the
  color preview matches reality.
- Community makers get **beautiful** results, often with manual filament swaps and g-code
  tweaks rather than one click
  ([Bambu forum example](https://forum.bambulab.com/t/hueforge-lithophane-printing-multiple-colors-a1-mini-without-ams/84900)).

**Bottom line:** single-color first — it's a near-guaranteed win with free tools. Full color is
a genuine step up that's worth doing once you're comfortable, as an eyes-open v2. When you want
it, tell me and I'll write a HueForge-specific guide the same careful way.

---

## Sources

- ItsLitho — slicer settings for lithophanes: <https://itslitho.com/itslitho-blog/slicer-settings-for-lithophanes-tweaking-to-perfection/>
- Obico — 3D printing lithophanes guide: <https://www.obico.io/blog/3d-printing-lithophanes/>
- Free generators: <https://3dp.rocks/lithophane/> · <https://itslitho.com/> · <https://www.lithophanemaker.com/>
- HuePick — what HueForge is: <https://huepick.app/what-is-hueforge>
- P3D — reducing Bambu AMS purge waste: <https://p3d.mx/blogs/how-to-3d-print/reducing-bambu-lab-poops>
- Bambu Studio — reduce waste during filament change: <https://wiki.bambulab.com/en/software/bambu-studio/reduce-wasting-during-filament-change>
- Bambu forum — HueForge lithophane, manual multi-color: <https://forum.bambulab.com/t/hueforge-lithophane-printing-multiple-colors-a1-mini-without-ams/84900>
