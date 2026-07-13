# Lithophane night-light — the color printer's show-off print

> **State:** grown via the ritual (2026-07-13) → verdict: **build** (start single-color; treat full-color as the stretch) → built as `guides/lithophane-night-light/` (2026-07-13)

A backlit photo-in-plastic night-light: a free web tool turns a photo into a printable model, plus a repeatable workflow doc so it comes out great every time.

*(A **lithophane** = a thin 3D print whose thickness varies across a picture. Thick spots block the light and look dark; thin spots let light through and look bright. Hold it up to a lamp and the photo appears — like a photo made of shadow.)*

## The 8 questions

**1. What is this thing, really?**
It's a thin plastic panel that hides a photo until you shine light behind it — you print it, stand it in front of a small LED, and a picture glows into view. Single-color lithophanes are one of the most reliable, well-documented crowd-pleasers in 3D printing ([ItsLitho slicer guide](https://itslitho.com/itslitho-blog/slicer-settings-for-lithophanes-tweaking-to-perfection/)).

**2. What could it grow into?**
The fun ceiling is a *full-color* glowing photo. Two ways up there: (a) a curved or cube-shaped lithophane lamp where a photo wraps around an LED tealight; and (b) a **HueForge**-style color print — software that stacks a few colored filaments and uses how light passes through each thin layer to blend them into a full-color image, viewable either front-lit like a painting or backlit like stained glass ([HuePick: what is HueForge](https://huepick.app/what-is-hueforge)). Your 3-color multi-material printer is exactly the machine people reach for here.

**3. What's the coolest version of the simplest build?**
A single-color night-light of one great photo: drop the photo into a free generator, export the model, print it standing up in one color, and set it in front of a $3 LED tealight or a USB LED panel. No color changes, no new hardware — just a photo that glows. Free browser generators that do the photo-to-model step: [3dp.rocks/lithophane](https://3dp.rocks/lithophane/), [ItsLitho](https://itslitho.com/), and [LithophaneMaker](https://www.lithophanemaker.com/) (which has a dedicated night-light shape).

**4. What breaks it?**
- **Layer height** (how thick each printed layer is): go fine. ~0.2 mm is the *coarsest* that still looks acceptable; **0.12 mm** is the sweet spot where the stripey layer lines and banding disappear into smooth tone ([ItsLitho](https://itslitho.com/itslitho-blog/slicer-settings-for-lithophanes-tweaking-to-perfection/)). Finer = better picture but longer print.
- **Thickness range** (bright-to-dark): the picture lives entirely in a small thickness window — roughly **~0.8 mm at the brightest spots up to ~3.2 mm at the darkest** ([ItsLitho](https://itslitho.com/itslitho-blog/slicer-settings-for-lithophanes-tweaking-to-perfection/), [Obico lithophane guide](https://www.obico.io/blog/3d-printing-lithophanes/)). Too thin overall and even the "dark" parts glow; too thick and no light gets through.
- **Print orientation:** stand it up **vertically**, not flat on the bed. A printer's side-to-side (X/Y) detail is much finer than its up-the-layers (Z) detail, so printing flat turns your grayscale into visible contour steps; printing upright makes each layer a thin vertical stripe the eye reads as smooth texture ([ItsLitho](https://itslitho.com/itslitho-blog/slicer-settings-for-lithophanes-tweaking-to-perfection/)).
- **First layer / quality:** print **solid** (100% infill, or many walls with no infill — internal gaps show up as blotches when backlit), add a **brim** (a thin skirt of plastic around the base) so a tall thin part doesn't tip mid-print, and print **slow, ~30 mm/s**, to hold detail ([ItsLitho](https://itslitho.com/itslitho-blog/slicer-settings-for-lithophanes-tweaking-to-perfection/)).
- **Color lithophane realities (the honest part):** a true single-color lithophane is *grayscale by nature* — thickness only makes light/dark, not hue. "Full color" almost always means the HueForge stacking trick, and that is a real step up in effort: it needs a **paid** HueForge license (not free like the generators above), patience, and a curated palette of filaments whose light-transmission values are known so the color preview is accurate ([HuePick](https://huepick.app/what-is-hueforge)). On your multi-material unit, automatic color swaps also **waste filament** — each swap purges the nozzle, and a multi-color print can throw away a surprising amount (one small Bambu demo cube produced ~83 g of purge "poop" for ~11 g of part) ([P3D: reducing AMS waste](https://p3d.mx/blogs/how-to-3d-print/reducing-bambu-lab-poops)), tunable but never zero ([Bambu Studio: reduce waste](https://wiki.bambulab.com/en/software/bambu-studio/reduce-wasting-during-filament-change)). Community makers do get *very nice* color results, but many do it with manual filament swaps and g-code tweaks, not one-click ([Bambu forum: HueForge + lithophane](https://forum.bambulab.com/t/hueforge-lithophane-printing-multiple-colors-a1-mini-without-ams/84900)). **Bottom line:** single-color is a near-guaranteed win; full-color is genuinely achievable on your printer but is finicky, wastes filament, and costs software money — a great *stretch*, not the first print.

**5. What does it let me build next?**
It compounds nicely. The workflow doc (generator settings → slicer settings → LED mount) is reusable for every future photo. From there: a wrap-around lithophane lamp, a set of them as gifts, and — once you're comfortable — the HueForge color version. It also teaches fine-layer, slow, high-detail printing, which carries over to any print where surface quality matters.

**6. What does it need?**
- **Parts:** a light source — a battery LED tealight or a small USB LED panel; optional printed stand (the generators can add one).
- **Filament:** for v1, any one color you already have (white or a light color reads best). For the color stretch: 3+ colors with known transmission values.
- **Tools:** a free generator ([3dp.rocks](https://3dp.rocks/lithophane/) / [ItsLitho](https://itslitho.com/) / [LithophaneMaker](https://www.lithophanemaker.com/)) + your normal slicer. Color stretch adds paid [HueForge](https://huepick.app/what-is-hueforge).
- **Skills:** exporting a model, dialing in fine layer height, and printing slow/vertical. All beginner-friendly.

**7. Who does what — me, Claude, or both?**
- **You:** pick the photo, run it through the generator, load filament, print, and mount the LED.
- **Claude:** write the repeatable workflow doc — exact generator values and slicer settings (0.12 mm layers, ~0.8–3.2 mm thickness, vertical, solid, brim, ~30 mm/s), an LED-mount option, and a plain-language "why each setting" note. Per the repo's teaching style, Claude can also build a short animated HTML explainer of *why thickness makes the picture* and *why vertical printing looks cleaner than flat*.
- **Both:** compare the first test print to the settings and tune together.

**8. What's the smallest piece I could finish this weekend?**
One single-color night-light of one photo, standing in front of an LED tealight. That's a few hours of printing and zero new purchases — a finished, glowing object by Sunday.

## Verdict

**build.** The research is clear on which version to build first: single-color lithophanes are a well-trodden, low-risk, high-delight win with free tools and settings that are thoroughly documented — a real weekend finish. Full-color is the honest catch: it's a HueForge project, not a plain lithophane, and it brings paid software, a filament palette, fiddly tuning, and unavoidable purge waste on your multi-material unit. So the truthful call is *build the simple version now, keep the color version as the labeled stretch goal* — not "build a 3-color show-off print" as if that were the easy path.

**First steps Claude will set up (single-color v1):**
1. A `guides/lithophane-night-light/` workflow doc: exact generator settings + slicer settings (0.12 mm layers, ~0.8–3.2 mm thickness, print vertical, solid infill, brim, ~30 mm/s), with a one-line "why" on each.
2. An LED-mount option (tealight stand vs. USB panel) and the recommended filament color.
3. A short animated HTML explainer: thickness → brightness, and flat-vs-vertical print quality.
4. A clearly separated "stretch: full-color with HueForge" section that states the real costs (paid software, filament palette, purge waste) up front, so v2 is an eyes-open choice.
