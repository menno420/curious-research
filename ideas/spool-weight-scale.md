# Filament spool scale — an honest "how much is left?" gauge, not an always-on precision readout

> **State:** grown via the ritual (2026-07-13) → verdict: **build** (as an on-demand spot-check + your own tare table — not a live shelf display)

A cheap load cell + HX711 amplifier + Arduino that tells you how many grams of filament are left on a spool — a superb beginner electronics build, as long as it's honest about what it is: an *on-demand* gauge you set a spool on to spot-check, backed by a one-time "weigh it empty" tare habit — not a precise always-on display drifting on a shelf next to a hot printer.

*(Bench terms, one clause each: **load cell** = a small metal bar with a strain gauge inside that bends a tiny, measurable amount under weight; **strain gauge** = a foil pattern whose electrical resistance changes as it stretches, which is how the bar "feels" weight; **HX711** = the little amplifier + analog-to-digital chip that turns the load cell's microscopic voltage change into a number the Arduino can read; **ADC (analog-to-digital converter)** = the part that turns a voltage into a digital number; **tare** = zeroing the scale so it ignores a known weight (the empty spool) and reports only what you added; **calibration factor** = the counts-per-gram number you find once by weighing a known mass, so raw readings become real grams; **creep / drift** = a load cell's reading slowly wandering under a constant weight or as temperature changes; **RFID / NFC** = a chip in the spool a reader can scan to know the spool's identity and weight automatically.)*

## The 8 questions

**1. What is this thing, really?**
It's a kitchen scale for filament: a load cell (a metal bar that bends a hair under weight) read through an [HX711 amplifier](https://github.com/bogde/HX711) by an Arduino, reporting grams. The weighing part is a well-trodden, cheap (~$5–15) build with abundant tutorials ([Random Nerd Tutorials](https://randomnerdtutorials.com/arduino-load-cell-hx711/), [Maker Portal](https://makersportal.com/blog/2019/5/12/arduino-weighing-scale-with-load-cell-and-hx711)). But "real grams *remaining*" is a bigger claim than "grams on the scale" — the honest core is a total-weight gauge, and turning that into filament-remaining needs one more thing: knowing the empty spool's weight.

**2. What could it grow into?**
A "spool library": save each spool's empty (tare) weight once, and every future reading becomes honest grams-remaining; add a low-filament warning; eventually a small filament-inventory dashboard shared with the [drybox humidity logger](filament-drybox-logger.md) as a two-instrument "filament health" bench. The ceiling is a scale that also *identifies* the spool automatically — exactly what Bambu (RFID) and Prusa's Oct-2025 [OpenPrintTag](https://blog.prusa3d.com/the-openprinttag-is-here-a-brand-new-nfc-tag-standard-for-smart-filament-is-now-shipped-with-a-new-redesigned-prusament-spool_123878/) NFC already do commercially ([Bambu Filament Manager](https://wiki.bambulab.com/en/software/bambu-studio/filament-manager)).

**3. What's the coolest version of the simplest build?**
Not a live always-on shelf number. The coolest *honest* version is an **on-demand spool checker**: set a spool on the platform, and read "≈ 640 g total → ≈ 440 g filament left" using that spool's saved tare — in the Serial Monitor first, on a tiny OLED once it's standalone. It answers the one real question — "do I have enough to start this print?" — in five seconds, without pretending to milligram precision.

**4. What breaks it? (drift, temperature, the tare problem, precision)**
Three honest weak points, and the first two are why "always-on live grams" oversells it:
- **Drift + temperature.** A cheap load cell wanders. Reported figures: ~0.03 g per °C ([Electronics-Lab](https://www.electronics-lab.com/forums/threads/load-cell-hx711-drifting-value.279103/)), creep of ~2 g every 12–15 min under constant load ([RobTillaart/HX711 #21](https://github.com/RobTillaart/HX711/issues/21)), ~0.5 g over 24 h with a 1–2 °C room swing ([bogde/HX711 #51](https://github.com/bogde/HX711/issues/51)). A builder of exactly this device says his scale "should not be expected to have great precision... measurement drift especially as chamber temperature changes... a general measuring system rather than a precision scale" ([Printables — Prusa MK3 spool scale](https://www.printables.com/model/62424-prusa-mk3-spool-holder-with-weight-scale-side-moun)). So a spot-check you re-zero is reliable; a number left drifting on a shelf all day near a hot printer is not.
- **The tare / empty-spool problem — the real hard part.** The cell reads *total*; filament-left = total − empty spool. Empty spools vary hugely: cardboard 80–297 g, plastic 113–306 g; Prusament ~201 g, Bambu ~256 g, Hatchbox ~225 g, eSun ~224 g ([empty-spool catalog](https://www.printables.com/model/464663-empty-spool-weight-catalog), [stlDenise3D](https://stldenise3d.com/how-much-do-empty-spools-weigh/)). Without knowing *which* spool is on it, the scale can't honestly say grams-remaining — you must save each spool's empty weight (a personal tare table) or weigh it empty at end-of-life. This is why the commercial answer is spool *identity*: Bambu RFID tags carry current weight ([Bambu wiki](https://wiki.bambulab.com/en/software/bambu-studio/filament-manager)); Prusa's [OpenPrintTag](https://blog.prusa3d.com/the-openprinttag-is-here-a-brand-new-nfc-tag-standard-for-smart-filament-is-now-shipped-with-a-new-redesigned-prusament-spool_123878/) NFC (shipping since Oct 2025) stores remaining length.
- **Precision.** Practical resolution is ~0.1% of cell capacity — about ±5 g on a 5 kg cell ([PCBSync](https://pcbsync.com/load-cell-hx711-arduino/)). ±5 g ≈ ±5 g of filament: great for "roughly half left," weak for "exactly enough to finish."

**5. What does it let me build next?**
It compounds well as an *electronics* foundation: read-a-sensor-over-two-wires (HX711) + calibrate-with-a-known-mass + show-it-on-an-OLED is the backbone of dozens of projects (any scale, a force gauge, bed-force testing, even reading the arm's payload). And it pairs with the [drybox humidity logger](filament-drybox-logger.md): moisture (is it dry?) + quantity (how much?) are the two "filament health" instruments, sharing a display and enclosure and a mental model though they sense different things.

**6. What does it need?**
- **Parts:** a **5 kg straight-bar load cell** (right size for a ≤1.25 kg full spool + headroom — 10 kg would waste resolution), an **HX711 amplifier board**, an Arduino (an Uno/Nano you likely have), and for a standalone readout a **0.96" SSD1306 I2C OLED** (or a cheap TM1637 4-digit LED for big numbers). Plus a rigid base and a flat platform to mount the cell.
- **Power:** just USB 5 V — this is all low-voltage, no external supply needed (unlike the arm).
- **Libraries:** [bogde/HX711](https://github.com/bogde/HX711) (classic, minimal) or [olkal/HX711_ADC](https://github.com/olkal/HX711_ADC) (adds smoothing + a ready [calibration example](https://github.com/olkal/HX711_ADC/blob/master/examples/Calibration/Calibration.ino)); [Adafruit_SSD1306 + Adafruit_GFX](https://github.com/adafruit/Adafruit_SSD1306) for the OLED.
- **Skills (all beginner):** wiring the load cell's 4 wires into the HX711 and 2 data pins to the Arduino, uploading a sketch, reading the Serial Monitor, and a one-time calibration with a known weight.

**7. Who does what — me, Claude, or both?**
- **You:** bolt the load cell to a rigid base with a flat platform (one end fixed, load on the free end — never twist or over-torque the bar), wire it, upload the sketch, and do the physical calibration by placing a known mass (a labeled kitchen weight, or a water bottle you weigh on a kitchen scale).
- **Claude:** write and comment the sketch (HX711 read + averaging + tare + OLED), pick the library, write the numbered wiring + calibration walkthrough, and build the little "tare table" helper so each spool's empty weight is saved once and reused.
- **Both:** decide the honest scope up front — an on-demand spot-check vs the always-on display the drift argues against.

**8. What's the smallest piece I could finish this weekend?**
Wire the load cell + HX711 to the Arduino, run the calibration example with a known weight, and read **live grams of anything in the Serial Monitor** — a working, calibrated scale. That's a complete, satisfying win. Next: tare an empty spool, save its weight, and show "grams remaining" for that one spool. The OLED and a saved tare table for your whole filament shelf are the following weekend.

## Verdict

**build** — but build the *honest* version.

The ritual sharpened the one-liner. "Reporting real grams-remaining per spool" hides two things the research made plain: (1) a cheap load cell **drifts** a few grams with temperature and time, so an always-on "live grams" display sitting near a hot printer overpromises — the reliable form is an **on-demand spot-check** you re-zero; and (2) the genuinely hard part isn't weighing, it's the **tare** — the scale reads total weight, and empty spools range ~80–306 g, so "grams remaining" needs each spool's empty weight saved (a personal tare table) rather than guessed. The commercial world solved this with spool *identity* (Bambu RFID, Prusa's OpenPrintTag NFC), which a plain load cell doesn't have.

None of that sinks it — it reframes it. As a **cheap, on-demand "how much is left?" gauge plus a one-time weigh-it-empty habit, it's an excellent beginner electronics build** (load cell → HX711 → calibrate → OLED is a genuinely foundational skill stack), and it's the natural sibling to the [drybox humidity logger](filament-drybox-logger.md). It's a `build` because the honest scope is buildable this weekend and every skill compounds — just not as the always-on precision instrument the one-liner implied.

**First steps Claude will set up:**
1. **A calibrated scale first.** Wire the 5 kg load cell → HX711 → Arduino, upload the [HX711_ADC calibration example](https://github.com/olkal/HX711_ADC/blob/master/examples/Calibration/Calibration.ino), and confirm a **live, accurate grams reading in the Serial Monitor** against a known weight. Numbered wiring + calibration walkthrough included.
2. **Solve tare honestly.** A tiny "spool library" — weigh a spool empty once, save its tare, and the sketch reports **grams-remaining = total − saved tare** for that spool. Seed it with known empties (Prusament ~201 g, Bambu ~256 g) but trust your own measured number over any table.
3. **Go standalone.** Add the SSD1306 OLED so the gauge reads grams without a PC — press-to-read, and honest that it's a spot-check, not a live feed.
4. **(Optional, later) Pair the instruments.** Share an enclosure and display with the [drybox humidity logger](filament-drybox-logger.md) into one "filament health" station — moisture + quantity, side by side.

---

**Safety — check this yourself:** this whole build is low-voltage USB 5 V hobby electronics and is fine for a beginner — no external power supply, no mains, nothing hot or load-bearing (unlike the robot arm, which needs its own fused external servo supply). The one physical caution is mechanical, not electrical: **mount the load cell properly** — one end rigidly fixed, load on the free end, and don't over-torque or twist the bar, which permanently damages the strain gauge. If you ever grow this toward a mains-powered heated element or anything structural, treat that as a separate, higher-risk project and verify it yourself (per repo `CLAUDE.md` §2).
