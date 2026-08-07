# Filament spool scale — an honest "how much is left?" gauge, not an always-on precision readout

> **State:** grown via the ritual (2026-07-13) → verdict: **build** (an on-demand spot-check + your own tare table — not a live shelf display) → building as [`projects/spool-weight-scale/`](../projects/spool-weight-scale/) (2026-07-13)

> **Historical idea note:** this file preserves the exploration that led to the project. It is
> not a wiring guide or a current performance specification. Use the Dutch
> [`project README`](../projects/spool-weight-scale/README.md) and its empty
> [`measurement log`](../projects/spool-weight-scale/meetlog.md). In particular, wire colours,
> resolution, drift and empty-spool weights must be verified on the actual hardware.

A cheap load cell + HX711 amplifier + Arduino that tells you how many grams of filament are left on a spool — a superb beginner electronics build, as long as it's honest about what it is: an *on-demand* gauge you set a spool on to spot-check, backed by a one-time "weigh it empty" tare habit — not a precise always-on display drifting on a shelf next to a hot printer.

*(Bench terms, one clause each: **load cell** = a small metal bar with a strain gauge inside that bends a tiny, measurable amount under weight; **strain gauge** = a foil pattern whose electrical resistance changes as it stretches, which is how the bar "feels" weight; **HX711** = the little amplifier + analog-to-digital chip that turns the load cell's microscopic voltage change into a number the Arduino can read; **ADC (analog-to-digital converter)** = the part that turns a voltage into a digital number; **tare** = zeroing the scale so it ignores a known weight (the empty spool) and reports only what you added; **calibration factor** = the counts-per-gram number you find once by weighing a known mass, so raw readings become real grams; **creep / drift** = a load cell's reading slowly wandering under a constant weight or as temperature changes; **RFID / NFC** = a chip in the spool a reader can scan to know the spool's identity and weight automatically.)*

## The 8 questions

**1. What is this thing, really?**
It's a scale concept for filament: a load cell read through an HX711 by an Arduino. But "grams *remaining*" is a bigger claim than total mass on the platform; it requires calibration, characterized measurement performance and this spool's measured empty weight.

**2. What could it grow into?**
A "spool library": save each spool's measured empty weight, and use it for future readings; add a low-filament warning only after repeatability is known. Automatic spool identity could be a later, separate project, but is not needed for the maintained build.

**3. What's the coolest version of the simplest build?**
Not a live always-on shelf number. The coolest *honest* version is an **on-demand spool checker**: set a spool on the platform, and read "≈ 640 g total → ≈ 440 g filament left" using that spool's saved tare — in the Serial Monitor first, on a tiny OLED once it's standalone. It answers the one real question — "do I have enough to start this print?" — in five seconds, without pretending to milligram precision.

**4. What breaks it? (drift, temperature, the tare problem, precision)**
Three honest weak points, and the first two are why "always-on live grams" oversells it:
- **Drift + temperature.** A cheap load cell wanders. Reported figures: ~0.03 g per °C ([Electronics-Lab](https://www.electronics-lab.com/forums/threads/load-cell-hx711-drifting-value.279103/)), creep of ~2 g every 12–15 min under constant load ([RobTillaart/HX711 #21](https://github.com/RobTillaart/HX711/issues/21)), ~0.5 g over 24 h with a 1–2 °C room swing ([bogde/HX711 #51](https://github.com/bogde/HX711/issues/51)). A builder of exactly this device says his scale "should not be expected to have great precision... measurement drift especially as chamber temperature changes... a general measuring system rather than a precision scale" ([Printables — Prusa MK3 spool scale](https://www.printables.com/model/62424-prusa-mk3-spool-holder-with-weight-scale-side-moun)). So a spot-check you re-zero is reliable; a number left drifting on a shelf all day near a hot printer is not.
- **The tare / empty-spool problem — the real hard part.** The cell reads *total*; filament-left = total − empty spool. Catalogs show that spool construction varies, but those crowd-sourced values are not measurements of the spool on this bench ([empty-spool catalog](https://www.printables.com/model/464663-empty-spool-weight-catalog), [stlDenise3D](https://stldenise3d.com/how-much-do-empty-spools-weigh/)). Without a measured empty weight, the scale cannot honestly report filament remaining.
- **Precision.** The original exploration copied a generic `±5 g` rule from a secondary article. That is not a specification for an unknown load cell, HX711 board, mounting system and calibration. Resolution, bias, repeatability and drift are now explicit experiments in the project measurement log.

**5. What does it let me build next?**
It compounds well as an *electronics* foundation: read-a-sensor-over-two-wires (HX711) + calibrate-with-a-known-mass + show-it-on-an-OLED is the backbone of dozens of projects (any scale, a force gauge, bed-force testing, even reading the arm's payload). And it pairs with the [drybox humidity logger](filament-drybox-logger.md): moisture (is it dry?) + quantity (how much?) are the two "filament health" instruments, sharing a display and enclosure and a mental model though they sense different things.

**6. What does it need?**
- **Parts:** a load cell whose rated capacity safely exceeds platform plus full spool, an **HX711 amplifier board**, a confirmed Arduino-compatible board, and optionally a compatible display. Exact capacity, voltage, pins and display address follow from the selected hardware rather than this idea note.
- **Power:** confirm the permitted supply and logic levels of the selected Arduino, HX711 board and optional display. The current concept is low-voltage USB electronics, but `5 V` is not universal across boards and modules.
- **Libraries:** [bogde/HX711](https://github.com/bogde/HX711) (classic, minimal) or [olkal/HX711_ADC](https://github.com/olkal/HX711_ADC) (adds smoothing + a ready [calibration example](https://github.com/olkal/HX711_ADC/blob/master/examples/Calibration/Calibration.ino)); [Adafruit_SSD1306 + Adafruit_GFX](https://github.com/adafruit/Adafruit_SSD1306) for the OLED.
- **Skills:** identify the exact hardware, map load-cell functions from its datasheet, mount it correctly, upload a sketch, read Serial Monitor and run calibration plus repeatability tests.

**7. Who does what — me, Claude, or both?**
- **You:** follow the selected load cell's mounting diagram, wire by documented function rather than colour, upload the sketch, and calibrate with an independently known mass.
- **Claude:** write and comment the sketch (HX711 read + averaging + tare + OLED), pick the library, write the numbered wiring + calibration walkthrough, and build the little "tare table" helper so each spool's empty weight is saved once and reused.
- **Both:** decide the honest scope up front — an on-demand spot-check vs the always-on display the drift argues against.

**8. What's the smallest piece I could finish this weekend?**
Wire the load cell + HX711 to the Arduino, run the calibration example with a known weight, and read **live grams of anything in the Serial Monitor** — a working, calibrated scale. That's a complete, satisfying win. Next: tare an empty spool, save its weight, and show "grams remaining" for that one spool. The OLED and a saved tare table for your whole filament shelf are the following weekend.

## Verdict

**build** — but build the *honest* version.

The ritual sharpened the one-liner. "Reporting real grams-remaining per spool" hides two things: (1) time, temperature, electronics and mounting can change the reading, so an on-demand check must still be characterized on the real build; and (2) the scale reads total weight, so "grams remaining" needs this spool's measured empty weight rather than a catalog guess.

None of that sinks it — it reframes it. As an **on-demand "how much is left?" gauge plus a weigh-it-empty habit**, it is a useful electronics and measurement project, and the natural sibling to the [drybox humidity logger](filament-drybox-logger.md). Its result is only as good as the hardware identification, mounting, calibration and logged repeatability.

**First steps Claude will set up:**
1. **A calibrated scale first.** Select a load cell with suitable rated capacity, map its documented functions to the HX711, upload the [HX711_ADC calibration example](https://github.com/olkal/HX711_ADC/blob/master/examples/Calibration/Calibration.ino), and characterize the reading against known masses.
2. **Solve tare honestly.** A tiny "spool library" — weigh a spool empty, save that measurement, and let the sketch report **grams-remaining = total − saved tare**. Do not seed it with catalog guesses.
3. **Go standalone.** Add the SSD1306 OLED so the gauge reads grams without a PC — press-to-read, and honest that it's a spot-check, not a live feed.
4. **(Optional, later) Pair the instruments.** Share an enclosure and display with the [drybox humidity logger](filament-drybox-logger.md) into one "filament health" station — moisture + quantity, side by side.

---

**Safety — current implementation wins:** disconnect power while wiring, verify every module's voltage, stay below the selected cell's rated load and follow its mounting diagram. Avoid torsion, side contact and over-tightening. The Dutch project README contains the maintained procedure; this historical note must not be used as a hardware guarantee.
