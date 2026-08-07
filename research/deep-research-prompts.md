# Deep-research prompts — how to grow the dossiers

Agent- and owner-facing (English on purpose, `CLAUDE.md` §0).

## What these are for

The maker asks Claude things. Claude answers better when it can read a **grounded, cited
dossier in this repo** than when it works from memory alone. These prompts are for running in
a deep-research tool (ChatGPT deep research, Gemini deep research, or Claude with search) and
dropping the result into `research/dossiers/`.

**The output format is the point.** He must be able to *browse* it — press a topic, scan short
cards, stop when he has what he needs. A 4,000-word essay is a wall he will bounce off, no
matter how correct it is. Every prompt below therefore demands short, self-contained cards.

## The rules that make the output usable

Every prompt carries the same five constraints. Do not drop them:

1. **Cards, not prose.** Each card ≤ 120 words, answers exactly one question, and stands alone.
2. **A real number in every card where one exists.** "Fairly fast" is useless; "about 2.5 A at
   stall" is a fact he can plan around.
3. **A source URL per card**, preferring primary sources — manufacturer wikis, datasheets,
   official docs — over blog posts and YouTube.
4. **A confidence mark per card**: `SOLID` (documented by the manufacturer or a datasheet) ·
   `COMMON` (widely reported by users, not officially documented) · `DISPUTED` (people
   disagree). Never let a `COMMON` claim be presented as `SOLID`.
5. **A "myths and outdated advice" section per topic.** This matters more than the rest. Most
   bad hobby advice is advice that was true five years ago or true for a different machine.

## His actual setup — paste this into every prompt

Written once here so it never has to be re-derived:

> 3D printers: a **Bambu Lab A1 mini** and a **Bambu Lab A1 with AMS Lite**, sliced in **Bambu
> Studio**. CAD: **Fusion 360** (free/personal licence) for everything — 2D for **laser cutting
> and CNC milling**, 3D for the printers. Electronics: a busy **Arduino** bench. Robotics: a
> 6-DOF arm on **6 × MG996R** analog servos, already assembled, wired to an enclosed switching
> supply, and moving under program control from a laptop. Operating system: **Windows**.
> Experience: strong mechanical and practical skills, low coding skills, learns by doing.

## Where the answers go

One file per topic in `research/dossiers/`, named for the topic (`arduino.md`,
`bambu-printen.md`, `fusion360.md`, `servos.md`, `lasersnijden.md`, `frezen.md`).

Keep the raw research **in English** — it is agent-facing, like the rest of `research/`. The
Dutch version he reads is built from it on the website, in browsable cards. Do not paste raw
research into the site: it has to be re-written in his language and cut to card size first.

---

## The prompts

Each one is self-contained. Paste the setup block above into it where marked.

### 1 · Arduino

```
You are building a reference dossier for an experienced hobby maker. Research thoroughly and
cite everything.

WHO IT IS FOR:
[paste the setup block]

TOPIC: Arduino, aimed at someone who already flashes sketches and wires sensors, but has never
been shown the capabilities that sit one step beyond copy-paste.

Produce 5 sections, 4-6 cards each:
  A. Boards worth knowing — what each is actually good at, and when the extra money is wasted
  B. Getting signals in — sensors, debouncing, analog vs digital, what "pull-up" really means
  C. Getting things to move — servos, steppers, motor drivers, and the power rules behind them
  D. Beyond the basic loop — interrupts, millis() vs delay(), state machines, watchdogs,
     saving settings to EEPROM
  E. Talking to other things — serial, I2C, SPI, and when each is the right choice

FORMAT, strictly:
- Each card: a question as its title, then <=120 words of answer.
- Include a concrete number wherever one exists (voltage, current, pin count, timing, cost).
- Every card ends with: SOURCE: <url> and CONFIDENCE: SOLID | COMMON | DISPUTED
- No filler, no "it depends" without saying what it depends on.

Then a final section: MYTHS AND OUTDATED ADVICE — at least 6 things commonly repeated about
Arduino that are wrong, obsolete, or true only for old boards. Say what is true instead.
```

### 2 · 3D printing on his Bambu A1 / A1 mini

```
You are building a reference dossier for an experienced hobby maker. Research thoroughly and
cite everything.

WHO IT IS FOR:
[paste the setup block]

TOPIC: getting the most out of a Bambu Lab A1 mini and an A1 with AMS Lite, in Bambu Studio.

IMPORTANT FRAMING: these printers auto-calibrate bed level, Z-offset, resonance and flow
dynamics before every print. Do NOT give advice that assumes manual bed levelling or manual
pressure-advance tuning. Focus on what is genuinely still the user's decision, and on things
specific to this machine.

Produce 5 sections, 4-6 cards each:
  A. What the A1 calibrates itself, and the few things it does not
  B. Filament — PLA, PETG, TPU, PLA-CF on an A1: what changes, what the AMS Lite can and
     cannot feed, drying, and which need a hardened nozzle
  C. The AMS Lite in practice — purge waste per colour change, how to design to reduce it,
     failure modes, and whether multi-colour is worth it for a given part
  D. Settings that still matter — walls vs infill, supports, seam placement, orientation
  E. Diagnosing failures on a self-calibrating printer — the real causes, in the order to
     check them

FORMAT, strictly:
- Each card: a question as its title, then <=120 words of answer.
- Include a concrete number wherever one exists (temperature, percentage, mm, grams).
- Every card ends with: SOURCE: <url> and CONFIDENCE: SOLID | COMMON | DISPUTED
- Prefer the official Bambu Lab wiki over YouTube and Reddit; mark it COMMON when the only
  source is user reports.

Then a final section: MYTHS AND OUTDATED ADVICE — at least 6 pieces of 3D-printing advice
that are wrong or pointless specifically on a self-calibrating Bambu A1. Say what is true
instead.
```

### 3 · Fusion 360, including the Python API

```
You are building a reference dossier for an experienced hobby maker. Research thoroughly and
cite everything.

WHO IT IS FOR:
[paste the setup block]

TOPIC: Fusion 360 for someone who already draws in it daily — 2D for laser and CNC, 3D for
printing — but has never scripted it and never used its more advanced parametric features.

Produce 5 sections, 4-6 cards each:
  A. Parametric modelling properly — user parameters, driven dimensions, why a well-built
     sketch survives a change and a badly-built one collapses
  B. The Python API — how scripts and add-ins differ, the object model in plain terms, the
     unit trap (the API works in centimetres), and how to debug when nothing happens
  C. Things worth scripting — the cases where a script beats the mouse decisively, with real
     examples (repeated features, size families, hole patterns, finger-jointed boxes)
  D. From Fusion to a machine — exporting for a 3D printer, for a laser, and for CNC; what
     each format keeps and loses
  E. Limits of the free personal licence — exactly what is restricted, what is not, and what
     changed recently

FORMAT, strictly:
- Each card: a question as its title, then <=120 words of answer.
- Include a real API name, menu path, or number wherever one exists.
- Every card ends with: SOURCE: <url> and CONFIDENCE: SOLID | COMMON | DISPUTED
- Prefer Autodesk's own help and API reference over third-party tutorials.

Then a final section: MYTHS AND OUTDATED ADVICE — at least 6 things commonly said about
Fusion 360 (especially about the free licence and about scripting) that are wrong or out of
date. Say what is true instead.
```

### 4 · Servos and the robot arm

```
You are building a reference dossier for an experienced hobby maker. Research thoroughly and
cite everything.

WHO IT IS FOR:
[paste the setup block]

TOPIC: hobby servos and small robot arms, specifically MG996R-class analog servos in a 6-DOF
arm that is already built and moving.

Produce 5 sections, 4-6 cards each:
  A. What an MG996R actually is — torque, current, speed, deadband, resolution, and what
     those numbers mean when six of them are stacked in an arm
  B. Power — realistic current draw versus stall, supply sizing, fusing, brownout symptoms
     that look like software bugs
  C. Control — PWM timing, driver boards (PCA9685 and alternatives), why smooth motion has to
     be generated in software, and what "no position feedback" rules out
  D. Accuracy and repeatability — backlash, deadband, gravity sag, error stacking across six
     joints, and the honest millimetre figure to expect at the tool tip
  E. Upgrades that actually change something — digital servos, servos with feedback, adding
     encoders, counterweights or springs; each with a rough cost and what it buys

FORMAT, strictly:
- Each card: a question as its title, then <=120 words of answer.
- Include a concrete number wherever one exists (kg-cm, amps, degrees, milliseconds, euros).
- Every card ends with: SOURCE: <url> and CONFIDENCE: SOLID | COMMON | DISPUTED
- Prefer datasheets and measured bench tests over marketing copy. Manufacturer torque claims
  for MG996R clones are frequently optimistic — say so where the evidence supports it.

Then a final section: MYTHS AND OUTDATED ADVICE — at least 6 commonly repeated claims about
hobby servos and cheap robot arms that are wrong or misleading. Say what is true instead.
```

### 5 · Laser cutting

```
You are building a reference dossier for an experienced hobby maker. Research thoroughly and
cite everything.

WHO IT IS FOR:
[paste the setup block]

TOPIC: laser cutting for someone who already draws 2D in Fusion 360 for it, but has no
written reference to work from.

Produce 5 sections, 4-6 cards each:
  A. Materials — what cuts well, what cuts badly, and what must NEVER be lasered (be specific
     and blunt about the toxic ones, PVC especially, and say why)
  B. Kerf and fit — what kerf is, typical values by material and machine type, how to
     compensate in the drawing, and how to measure your own
  C. Joints that work — finger joints, T-slots, living hinges, press fits; the tolerances
     each needs
  D. Preparing a file — line colours and widths for cut vs engrave, units, closed paths,
     what exports cleanly from Fusion
  E. Safety and extraction — fumes, fire risk, what never to leave unattended, and eye safety
     by laser class

FORMAT, strictly:
- Each card: a question as its title, then <=120 words of answer.
- Include a concrete number wherever one exists (mm of kerf, wattage, mm/s, material
  thickness).
- Every card ends with: SOURCE: <url> and CONFIDENCE: SOLID | COMMON | DISPUTED
- Distinguish clearly between CO2, diode, and fibre lasers wherever the answer differs.

Then a final section: MYTHS AND OUTDATED ADVICE — at least 6 things commonly said about laser
cutting that are wrong or dangerous. Say what is true instead.
```

### 6 · CNC milling

```
You are building a reference dossier for an experienced hobby maker. Research thoroughly and
cite everything.

WHO IT IS FOR:
[paste the setup block]

TOPIC: hobby CNC milling and routing for someone with strong mechanical intuition, who draws
in Fusion 360 but has not been taught the machining side properly.

Produce 5 sections, 4-6 cards each:
  A. The four numbers — feed, speed, depth of cut, stepover; what each does, how they trade
     off, and how to recognise each one being wrong from the sound and the chips
  B. Cutters — up-cut, down-cut, compression, single-flute, ball-nose, V-bit: what each is
     for, and which materials wreck which
  C. Materials — plywood, MDF, acrylic, aluminium: what changes for each, and which are
     realistic on a hobby machine
  D. Workholding — clamps, tabs, tape-and-glue, vacuum; why workholding causes more ruined
     parts than the cutting settings do
  E. Fusion CAM — toolpath types worth knowing, stock setup, simulation, post-processors,
     and the mistakes that turn into a broken cutter

FORMAT, strictly:
- Each card: a question as its title, then <=120 words of answer.
- Include a concrete number wherever one exists (RPM, mm/min, mm depth, chipload).
- Every card ends with: SOURCE: <url> and CONFIDENCE: SOLID | COMMON | DISPUTED
- Be explicit when a number applies to an industrial machine and NOT to a hobby router.

Then a final section: MYTHS AND OUTDATED ADVICE — at least 6 commonly repeated claims about
hobby CNC that are wrong or that get cutters broken. Say what is true instead.
```

---

## After the research comes back

1. Save the raw output to `research/dossiers/<topic>.md`, unedited, with the date and which
   tool produced it at the top.
2. **Check the `SOLID` claims that matter.** A deep-research tool will confidently mislabel
   things. Anything that touches safety — power, fumes, materials that must not be cut — gets
   verified against a primary source before it reaches him.
3. Rewrite as Dutch cards for the website. Cut, do not translate: a 120-word English card
   usually becomes a 60-word Dutch card once the filler is gone.
4. Where two sources disagree, say so in the card rather than picking one silently. He would
   rather know it is contested.
