# The arm orbits a camera around a print — a real idea, but a static phone gets 90 % of it and the arm can't safely hold a phone for a whole print

> **State:** grown via the ritual (2026-07-13) → verdict: **park** — the timelapse you actually want is a *static phone + interval/Octolapse* job you can do tonight; the arm's unique *moving-orbit* version is a real but separate future build, gated on a **light** camera (not a 170–230 g phone) and on your printer exposing layer events. Parked, not dropped — see "what unparks it" below.

A one-liner captured earlier: *"the arm orbits a phone or small camera around an in-progress print for smooth moving timelapses, stepping once per layer change."* Grown honestly, it splits in two: the **timelapse** (easy, and mostly doesn't need the arm) and the **moving orbit shot** (the arm's real gift, but it collides with hard physics — a phone is heavier than the arm can safely hold at the end of its reach, and servos overheat holding a load for hours).

*(Bench terms, one clause each: **timelapse** = many still photos played back fast so a slow print looks like it grows in seconds; **intervalometer** = a timer that fires the camera shutter every N seconds, with no idea what the printer is doing; **Octolapse** = an OctoPrint plugin that snaps one frame at each layer change by controlling the printer's G-code stream; **OctoPrint** = a small server (usually a Raspberry Pi) that drives your printer and can watch a camera; **layer event** = the printer signalling "a new layer just started" — what layer-synced capture listens for; **G-code** = the text commands (move here, extrude this much) that actually run a print; **stall torque** = the most twisting force a servo can make for a moment before it stalls, in kg·cm; **kg·cm** = "this many kg, but only at 1 cm from the shaft" — the lever eats it fast; **payload** = the weight the arm can actually hold at its far end; **back-drivable** = a joint you can push by hand — hobby servos go limp and slump the instant power is off.)*

## The 8 questions

**1. What is this thing, really?**
Two ideas wearing one sentence. (a) A **print timelapse** — the well-solved, satisfying "watch it grow" video; and (b) an **arm-driven moving/orbit shot** — the camera physically swinging around the print between frames. The timelapse barely needs the arm; the orbit is the only part that does, and it's the part physics fights.

**2. What could it grow into? (the fun ceiling)**
The dream: buttery orbit timelapses where the camera arcs around the bed, each frame snapped at the same point in every layer — the shot that makes a print look like a game asset materialising. It piggybacks on the printed phone-clamp effector ([`projects/effector-mount/`](../projects/effector-mount/)) and a stepped shoot-move-shoot routine, and the dossier already flags it as a 🧪 "try it" ([`research/possibility-dossier.md`](../research/possibility-dossier.md), Part 3 #3).

**3. What's the coolest version of the simplest build?**
Honestly, the coolest *simple* version has no arm in it: a **phone on a cheap tripod aimed at the bed**, running an interval app (or Octolapse if you have OctoPrint), left alone for the print. That gets ~90 % of the wow with zero risk and zero calibration. The arm earns its keep only when you specifically want the camera to *move*.

**4. What breaks it? (payload, torque, heat, layer-sync, physics)**
This is where the honest version diverges hard from the one-liner:
- **A phone is too heavy for the far end of the arm.** Modern phones run ~187–232 g ([iPhone 15 Pro 187 g](https://www.gsmarena.com/apple_iphone_15_pro-12557.php), [Pro Max 221 g](https://www.macrumors.com/2023/09/09/iphone-15-weights-and-dimensions/), [Galaxy S24 Ultra 232 g](https://www.gsmarena.com/samsung_galaxy_s24_ultra-12771.php)). The arm's realistic *usable* payload at the tool is only ~50–200 g optimistic, and a printed clamp already eats 30–120 g of that ([`ideas/printed-end-effectors.md`](printed-end-effectors.md)). And "kg·cm" is measured at 1 cm from the shaft: a 187 g phone hanging ~18 cm out demands ~3.4 kg·cm at that joint *just to hold still* (0.187 kg × 18 cm), before the arm's own weight and the clamp — a big bite out of an [MG996R's ~11 kg·cm stall](https://components101.com/motors/mg996r-servo-motor-datasheet) and far past an [SG90 wrist servo's 1.8 kg·cm](http://www.ee.ic.ac.uk/pcheung/teaching/DE1_EE/stores/sg90_datasheet.pdf). A phone likely **exceeds** safe payload. A light camera doesn't — hold that thought.
- **Servos overheat holding for hours.** A print runs hours; a servo straining to hold a load against gravity draws high current the whole time (the MG996R pulls up to ~2.5 A stalled at 6 V, [datasheet](https://components101.com/motors/mg996r-servo-motor-datasheet)) and makers routinely report arm servos overheating and jittering under sustained hold ([RobotShop](https://www.robotshop.com/community/forum/t/servo-damage-by-overheating/17744), [Arduino Forum](https://forum.arduino.cc/t/robotic-arm-servos-overheating/524454) — forum-strength evidence, but consistent). Heat also makes the hold *drift*, which shows up as wobble in the video.
- **Cut the power and it falls.** Hobby servos are back-drivable — no holding torque when unpowered; kill power to save heat and the arm (and phone) slumps ([Arduino Forum](https://forum.arduino.cc/t/servo-motor-to-hold-still-when-off/1086009)). So "brace it in a pose and switch off" isn't available.
- **Layer-sync may not be reachable.** True per-layer frames need the print host to expose layer events — [Octolapse](https://plugins.octoprint.org/plugins/octolapse/) does it by owning the G-code through OctoPrint. A printer running from an **SD card or plain USB with no OctoPrint doesn't hand those events to anything**, so you'd fall back to plain interval shooting. Whether *your* printers expose this is an honest unknown until we check the firmware/host.

**5. What does it let me build next? (does it compound?)**
The arm-motion half compounds nicely: a working **stepped shoot-move-shoot** routine (move a small increment, settle, cue a photo, repeat, all inside the calibrated envelope) is the same skill as record-and-replay teach-mode moves — reusable for any "arm does a repeatable little dance" project. The static-tripod half doesn't compound much, but it's a 20-minute win.

**6. What does it need?**
For the *now* path: a phone, a tripod/clamp, and a free interval app — or OctoPrint + a Pi camera for layer-synced frames ([Octolapse](https://plugins.octoprint.org/plugins/octolapse/)). For the *arm* path later: a **light** camera (an ESP32-CAM board is ~20–40 g, a small action cam ~60–130 g — both far under a phone), the printed clamp effector, a settle-delay stepped routine, and confirmation your printer can signal layers.

**7. Who does what — me, Claude, or both?**
Claude can write the stepped orbit routine (clamped to the envelope, settle-before-photo), help pick a light camera under the payload budget, and check whether your printer/host exposes layer events. **You** mount the phone/tripod for the easy version, physically watch any arm motion, and power the servos from the external fused supply — never the Arduino 5 V pin. The hot end and the printer's moving parts stay a "check this yourself" zone.

**8. What's the smallest piece I could finish this weekend?**
Not an arm build — a **static-phone interval timelapse of your next print**: tripod, phone, interval app, hit record, let it run. It tells you immediately whether you even *like* print timelapses before investing in arm motion. If you love it and want movement, the next weekend's small piece is a **short, empty-bed stepped orbit** with a light camera (no print running, nothing hot, arm watched) to judge the moving-shot quality for yourself.

## Verdict

**park** — good, not now, and *not dropped*.

The honest split: the **timelapse** you actually want is a static-phone job you can do tonight with a tripod and a free app (or Octolapse if you run OctoPrint) — the arm adds almost nothing to it and adds real risk. The **arm-orbit** version is a genuinely cool, genuinely different build, but the one-liner's specific "arm holds a **phone**, stepping every layer, for the whole print" runs into three walls: a 170–230 g phone likely **exceeds** the arm's safe far-end payload, servos **overheat and drift** holding a load for a multi-hour print, and they **slump when unpowered** so you can't switch off to cool down. Parking is the honest call — the idea is good, the *phone-for-hours* form isn't buildable safely right now.

**What unparks it (any time you're curious):**
1. **Do the easy win first** — Claude writes you a one-page "static-phone print timelapse" guide (tripod placement clear of the hot end, interval-vs-Octolapse, framing) so you can try timelapses this weekend with zero arm risk.
2. **Swap the phone for a light camera** — pick an ESP32-CAM (~20–40 g) or a small action cam, comfortably under the ~50–200 g payload ceiling ([`ideas/printed-end-effectors.md`](printed-end-effectors.md)).
3. **Keep it stepped and short** — the arm does shoot-move-shoot in small increments and *doesn't* hold through a whole print; for a full-print orbit, the timelapse frames come from a static camera and the arm only adds occasional moving "hero" passes.
4. **Check the layer-event question** — confirm whether your printer runs through OctoPrint/Klipper (layer-synced frames possible) or straight from SD/USB (interval only).

---

**Safety — check this yourself:** Any arm motion happens only inside the calibrated envelope, via routines that clamp to it, and **only with you watching** (repo `CLAUDE.md` §2). Servo power is a separate, fused 5–6 V supply with shared ground and a reachable switch — never the Arduino's 5 V pin. Keep the camera, clamp, and every arm move well clear of the **hot end and the printer's moving parts** — those are a "you verify the clearance yourself" zone. And the public-repo rule: timelapse videos of prints are great to share, but keep faces, room details, and anything identifying out of frame.

---
