# Filament drybox logger — an Arduino humidity watcher

> **State:** grown via the ritual (2026-07-13) → verdict: think more

A cheap Arduino + humidity sensor that watches the air around your filament and writes the numbers to a file in this repo — a real beginner Arduino win, *if* the readings actually lead to action instead of just piling up as data.

## The 8 questions

**1. What is this thing, really?**
It is a small Arduino board reading a humidity sensor once in a while and saving each reading (time, temperature, relative humidity — how much moisture the air is holding compared to the most it *could* hold at that temperature) as a row in a CSV file (a plain spreadsheet-style text file, one reading per line) you commit to this repo. Honestly: right now it is a *thermometer with a memory* — it measures, it does not protect.

**2. What could it grow into? (the fun ceiling)**
The fun ceiling is turning "a number on a screen" into "the box tells me when my filament is at risk." Growth path: reading → logging → a graph of humidity over weeks → an **alert** (an LED or a phone ping) when it crosses a danger line → and eventually closing the loop by switching on a small dry-box heater or reminding you to swap the desiccant (a drying agent like silica gel packets that soak up moisture). At the top end it becomes a genuine early-warning system for your most moisture-hungry filament.

**3. What's the coolest version of the simplest build?**
Not "log a CSV forever." The coolest *simple* version is a **traffic-light box**: sensor inside your filament storage bin, one green/yellow/red LED on the outside. Green = safe, yellow = getting damp, red = dry your filament now. It gives you the one thing logging alone never does — a decision, at a glance, with zero spreadsheet reading. The CSV can still record in the background for the graph-nerd payoff later.

**4. What breaks it? (sensor accuracy, the log-vs-dry question, data-plumbing)**
Three honest weak points:

- **Sensor accuracy.** The common cheap DHT22 sensor is rated for "2-5% accuracy" on humidity and ±0.5°C on temperature, and can only be read once every 2 seconds ([Adafruit DHT overview](https://learn.adafruit.com/dht/overview)). Independent long-term bench testing was harsher: one reviewer judged real accuracy "to be around 5%," found "a significant temperature dependence when away from" 25°C, and had "three of the original six devices... failed" over two years ([kandrsmith hygrometer comparison](http://www.kandrsmith.org/RJS/Misc/Hygrometers/calib_many.html)). Why this matters: the danger line for a fussy filament like nylon is around 15% RH (see below), and a sensor that can be 5% off — and drifts — might read "18%, fine" when you are really at 13%, or cry wolf at a safe level. A newer sensor (SHT31 or BME280) is more accurate and more stable for a few dollars more, and is worth it here.
- **The log-vs-dry question (the big one).** Recording humidity does **not** remove humidity. A logger that only records is low-value — the data does nothing unless it changes what you do. Filament stays dry only through *action*: a sealed box with desiccant, or an actual heated dryer. Airtight box + desiccant can hold "<20% RH for 2-3 months," and vacuum bags with desiccant keep filament dry "6+ months" ([UAVMODEL filament dryer guide](https://blog.uavmodel.com/3d-printer-filament-dryer-guide-moisture-effects-on-pla-petg-tpu-and-nylon-2026/)). The sensor's honest job is to *tell you the box is working (or isn't)* — it is the dashboard, not the engine.
- **Data-plumbing.** A bare Arduino has no clock and no internet, so getting timestamped rows into a CSV *in this repo* is fiddly (you need either a real-time-clock chip, or a Wi-Fi board like an ESP32 that knows the time, plus a way to push the file to GitHub). The simplest builds skip the repo entirely and log to an SD card or just light the LED — the "commit to the repo" part is the hardest plumbing for the least payoff at the start.

**5. What does it let me build next? (does it compound?)**
Strongly yes. This is the gateway Arduino project: read a sensor, make a decision, act on it (LED/beeper), optionally save data. Every one of those skills transfers — a temperature alarm for the printer enclosure, a soil-moisture plant waterer, a servo that only moves when a sensor says it's safe (which ties straight into your robot-arm envelope thinking). The "sensor → threshold → action" loop is the backbone of half of Arduino.

**6. What does it need? (parts, filament, libraries, skills)**
- **Parts:** an Arduino (an Uno or Nano you likely already have); a humidity sensor — DHT22 works, but an **SHT31 or BME280 is the better buy** for accuracy/stability; an LED or two (and resistors); jumper wires and a breadboard. Optional later: a real-time-clock module or an ESP32 (Wi-Fi board) for timestamps and repo logging; an SD-card module for offline logs.
- **Filament:** basically none — a small printed sensor mount or LED bezel for your storage box, in any PLA.
- **Libraries:** the sensor's Arduino library (e.g. `DHT` or `Adafruit_SHT31` / `Adafruit_BME280`) — Claude can point to the exact one and paste the install steps.
- **Skills (new to you, all beginner-level):** uploading a sketch (an Arduino program) to the board; reading the Serial Monitor (the text window that shows what the board is saying); wiring a sensor and an LED. Nothing here is advanced.

**7. Who does what — me, Claude, or both?**
- **You:** wire the sensor and LED, upload the sketch, put the sensor in the box, and — the part that actually protects filament — add desiccant or a dryer. Only you touch hardware and power.
- **Claude:** write and comment the sketch, pick the right sensor and library, set the RH danger thresholds per material, explain each wiring step as a numbered guide, and (if you go there later) build an animated HTML explainer showing "air moisture rises → sensor reads → LED turns red."
- **Both:** decide the thresholds and what "red" should trigger.

**8. What's the smallest piece I could finish this weekend?**
Wire the sensor to the Arduino and get a **live humidity number in the Serial Monitor** — nothing saved, no LED yet. That is a complete, satisfying first win: proof you can read the real air in your filament box. If that goes smoothly, add one LED that turns red above a threshold. Skip the CSV-to-repo plumbing entirely for now.

## Verdict

**think more.**

The build is a genuinely great beginner Arduino project and the parts are cheap — but the ritual surfaced a real tension the one-liner hid: **logging humidity is not the same as protecting filament.** A CSV that only records is low-value; the value only appears when the reading drives an *action* (an alert, or pairing the sensor with real desiccant/drying). So this isn't a clean `build` of the thing as originally written ("log to a CSV"), and it's too good to `park` or `drop`.

**The one open question to resolve before it earns `build`:** *Which job is this — a passive data logger, or a traffic-light alarm that tells you to act?* Pick the alarm (sensor → threshold → LED, sitting on top of a desiccant box), and it flips straight to `build`. Keep it a pure logger, and it's not worth the data-plumbing effort yet.

---

**Safety — check this yourself:** everything above is low-voltage 5 V hobby wiring and is fine for a beginner. But the *moment* this idea grows toward switching on an active dry-box heater or anything mains-powered, that is a different, higher-risk project — flag it in the PR and verify the wiring yourself (per repo `CLAUDE.md` §2). This idea file stays firmly on the safe, low-voltage side.
