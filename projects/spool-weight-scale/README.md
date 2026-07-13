# Filament spool scale — an honest "how much is left?" gauge

> Set a spool on it, press read, and it tells you *roughly* how much filament
> is left. This is an **on-demand spot-check you re-zero** — not an always-on
> precision number left drifting on a shelf. The honest scope is the whole
> point; a cheap load cell can't do more, and pretending otherwise just
> disappoints you the first hot afternoon.

Grown from [`../../ideas/spool-weight-scale.md`](../../ideas/spool-weight-scale.md)
(ritual verdict: **build** — the honest version).

---

## Bench words (one line each)

- **load cell** = a small metal bar with a strain gauge inside that bends a
  tiny, measurable amount under weight.
- **strain gauge** = a foil pattern whose electrical resistance changes as it
  stretches — that's how the bar "feels" weight.
- **HX711** = the little amplifier + analog-to-digital chip that turns the load
  cell's microscopic voltage change into a number the Arduino can read.
- **ADC (analog-to-digital converter)** = the part that turns a voltage into a
  digital number (it's the "711" chip's day job).
- **tare** = zeroing the scale so it ignores a known weight (the empty spool)
  and reports only what you added.
- **calibration factor** = the counts-per-gram number you find once by weighing
  a known mass, so raw readings become real grams.
- **drift / creep** = a load cell's reading slowly wandering under a constant
  weight or as the temperature changes — the reason this is a spot-check, not a
  live display.

---

## What it honestly is / isn't

**It is** reliable as an *on-demand spot-check you re-zero*: set a spool on the
platform, take a fresh reading, get an answer to the one real question — "do I
have enough to start this print?" — in five seconds.

**It isn't** reliable as a number left drifting on a shelf all day. Cheap load
cells wander a few grams with temperature and time, and practical resolution is
only about **±5 g on a 5 kg cell**. That's great for "roughly half a spool
left," and weak for "exactly enough to finish this one." A reading that sits
powered next to a hot printer drifts as the chamber warms.

The drift reasoning — the cited creep and temperature figures, and a builder of
exactly this device calling it "a general measuring system rather than a
precision scale" — is written up in
[`../../ideas/spool-weight-scale.md`](../../ideas/spool-weight-scale.md).

---

## Parts list

| Part | Rough price (USD) | Notes |
|---|---|---|
| 5 kg straight-bar load cell | ~$3–8 | The right size for a ≤1.25 kg full spool **plus headroom**. A 10 kg cell wastes resolution on weight you'll never load. |
| HX711 amplifier board | ~$1–3 | Often bundled *with* the load cell as a kit — check before buying separately. |
| Arduino Uno or Nano | ~$5–25 | You very likely already own one. |
| 0.96" SSD1306 I2C OLED | ~$4–8 | **Stage 3 only** — the standalone "press to read" screen. Skip it until you want to unplug from the PC. |
| Rigid base + flat platform | scrap / printed | One end of the cell bolts down solid; the platform sits on the free end. Print one or use scrap. |
| A known calibration weight | you have this | A labelled kitchen weight, or a water bottle you weigh on a kitchen scale (a full 500 mL bottle is ~500 g). |

---

## The one safety note

> **Check this yourself — the one real caution is mechanical, not electrical.**
> This whole build is low-voltage USB 5 V hobby electronics: no external power
> supply, nothing mains-powered, nothing hot, nothing load-bearing (unlike the
> robot arm). The single thing that can permanently break a part is how you
> **mount the load cell**: bolt it with **one end rigidly fixed** and the load
> on the **free end**, and never twist or over-torque the bar. Bending it the
> wrong way or cranking the screws too hard damages the strain gauge inside for
> good. Mount it right once and it lasts.

---

## Install the library

In the Arduino IDE:

1. Open the Library Manager: click `Sketch` > `Include Library` > `Manage Libraries…`.

2. In the search box, type:

   ```
   HX711_ADC
   ```

3. Find **"HX711_ADC" by Olav Kallhovd** in the list and click `Install`.

That one library covers all three stages. **For Stage 3 (the OLED screen) also
install these two:**

4. Search for and install **"Adafruit SSD1306" by Adafruit**. If it offers to
   install dependencies, click `Install All`.

5. Search for and install **"Adafruit GFX Library" by Adafruit**.

---

## Numbered wiring steps

Do these with the Arduino **unplugged**. One connection per step.

**Load cell (4 thin wires) → HX711 board.** The colours are standard on most
cells:

1. Connect the load cell's **red** wire to the HX711 **E+** pad.
2. Connect **black** to **E-**.
3. Connect **white** to **A-**.
4. Connect **green** to **A+**.

   ```
   red   -> E+      white -> A-
   black -> E-      green -> A+
   ```

   > If your grams read **negative** (weight goes down when you add load), the
   > cell is just wired mirror-image — swap **white ↔ green** and re-upload.

**HX711 board → Arduino.**

5. Connect HX711 **VCC** to Arduino **5V**.
6. Connect HX711 **GND** to Arduino **GND**.
7. Connect HX711 **DT** (data) to Arduino **pin 4**.
8. Connect HX711 **SCK** (clock) to Arduino **pin 5**.

   ```
   VCC -> 5V        DT  -> pin 4
   GND -> GND       SCK -> pin 5
   ```

**Stage-3 extras (skip these until you build the standalone screen).**

9. Connect one leg of the read button to **pin 6**, the other leg to **GND**.
   (No resistor needed — the sketch uses the chip's built-in pull-up.)

   ```
   button leg 1 -> pin 6
   button leg 2 -> GND
   ```

10. Connect the SSD1306 OLED over I2C. On an Uno or Nano, **SDA is A4** and
    **SCL is A5**.

    ```
    OLED VCC -> 5V       OLED SDA -> A4
    OLED GND -> GND      OLED SCL -> A5
    ```

---

## Stage 1 — calibrate (the weekend win)

This is the satisfying first finish: a working, calibrated scale reading real
grams.

1. Near the top of `spool_scale.ino`, set the stage to 1:

   ```
   #define STAGE 1
   ```

2. Click the **Upload** arrow button to flash the sketch.

3. Open the Serial Monitor (`Tools` > `Serial Monitor`) and set its baud rate
   (bottom-right dropdown) to:

   ```
   57600
   ```

4. Keep the platform **empty**. You'll see live raw readings scrolling.

5. Type `t` and press Enter to zero (tare) the empty platform:

   ```
   t
   ```

   You should see `>> tare done. Now place your known weight and type 'r'.`

6. Set `knownMassGrams` near the top of the sketch to match the weight you're
   about to use, and re-upload if you changed it. For a 500 g weight:

   ```
   float knownMassGrams = 500.0;
   ```

7. Place your known weight gently on the platform.

8. Type `r` and press Enter to read the calibration factor:

   ```
   r
   ```

9. The Monitor prints `>> YOUR CALIBRATION FACTOR = ...`. Copy that number into
   `calibrationFactor` near the top of the sketch:

   ```
   float calibrationFactor = 1234.56;   // <-- your number here
   ```

**Verify:** set `#define STAGE 2`, upload, and with your known weight still on
the platform the Serial Monitor should show grams within a few grams of the
weight's real value. If it does, you have a calibrated scale.

---

## Stage 2 — the honest tare (grams remaining)

Weighing is easy; the honest hard part is **tare** — the scale reads *total*
weight, and filament-left = total − the empty spool. So build the one habit
that makes this trustworthy: **weigh a spool empty, once.**

1. When a spool runs out, weigh the bare empty spool on your calibrated scale
   (or any kitchen scale). Write the number down.

2. Put that number into **slot 0** of the spool library near the top of the
   sketch — the slot labelled `MY SPOOL (measure me!)`:

   ```
   { "MY SPOOL (measure me!)", 245.0 },   // <-- your measured empty grams
   ```

3. Point the sketch at that slot:

   ```
   #define ACTIVE_SPOOL 0
   ```

4. Set the stage and upload:

   ```
   #define STAGE 2
   ```

The Monitor now prints a line like `total 640 g  - empty 245 g  = ~395 g
filament left`.

**Your own measured empty weight beats the seeded table, every time.** Empty
spools range roughly **80–306 g** depending on brand and material, so guessing
is useless. The seeds in the library — Prusament ~201 g, Bambu ~256 g, Hatchbox
~225 g, eSun ~224 g — are only *starting points* pulled from the empty-spool
catalogs cited in
[`../../ideas/spool-weight-scale.md`](../../ideas/spool-weight-scale.md).
Confirm any of them on your own bench before you trust them.

---

## Stage 3 — standalone OLED (press to read)

Cut the PC cord: read grams on a little screen with a button press.

1. Wire the read button and the OLED per steps 9–10 above.

2. Set the stage and upload:

   ```
   #define STAGE 3
   ```

3. The screen shows `spool scale / press button to read`. Set a spool on the
   platform and press the button — it takes a fresh, averaged reading and shows
   **grams remaining** big, with the **total** below as a spot-check.

It's **press-to-read on purpose.** That's the honest design: a spot-check you
ask for, not a live feed that drifts while you're not looking.

---

## Honest expectations

- **±5 g resolution on a 5 kg cell.** "Roughly half a spool left" is
  trustworthy. "Exactly enough to finish this print" is not — leave yourself
  margin.
- **Re-zero (re-tare) each session.** Drift means yesterday's zero isn't
  today's zero. A fresh tare before a reading is a few seconds well spent.
- **Drift grows if it sits powered near a hot printer.** As the chamber warms,
  the reading wanders. This is a set-it-down-and-check-it tool, not a shelf
  display.
- **Its natural companion** is the sibling
  [`../../ideas/filament-drybox-logger.md`](../../ideas/filament-drybox-logger.md):
  moisture (is it dry?) + quantity (how much?) are the two "filament health"
  instruments — same mental model, different sensors.

---

## A note on the sketch

The `spool_scale.ino` here was written and reviewed in this repo but has **not**
been compiled — there's no Arduino toolchain in the authoring environment, so
your Arduino IDE will be its first real compile. If it flags anything, it'll
almost certainly be a missing library (re-check the install steps) or a pin
typo (re-check the wiring) — both quick fixes.
