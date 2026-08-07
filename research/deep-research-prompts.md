# Deep-research prompts — how to grow the dossiers

Agent- and owner-facing (English on purpose, `CLAUDE.md` §0).

## What these are for

The maker asks Claude things. Claude answers better when it can read a **grounded, cited
dossier in this repo** than when it works from memory alone. These prompts are for running in
a deep-research tool (ChatGPT deep research, Gemini deep research, or Claude with search) and
dropping the result into `research/dossiers/`.

**Each prompt below is complete.** Copy one whole fenced block, paste it, run it. Nothing to
fill in, nothing to look up first. They repeat his setup on purpose — each one is used in a
separate chat that knows nothing about the others.

**The output format is the point.** He must be able to *browse* the result — press a topic,
scan short cards, stop when he has what he needs. A 4,000-word essay is a wall he will bounce
off, no matter how correct it is. Every prompt therefore demands short, self-contained cards
with a source and a confidence mark.

## Where the answers go

One file per topic in `research/dossiers/`: `arduino.md`, `bambu-printen.md`, `fusion360.md`,
`servos.md`, `lasersnijden.md`, `frezen.md`.

Keep the raw research **in English** — it is agent-facing, like the rest of `research/`. The
Dutch he reads is built from it in `site/kennis.html`, in browsable cards. Do not paste raw
research into the site: it has to be re-written in his language and **cut** to card size
first. A 120-word English card is usually a 60-word Dutch card once the filler is gone.

---

## 1 · Arduino

```
You are compiling a reference dossier for an experienced hobby maker. Research thoroughly,
use primary sources where they exist, and cite everything.

WHO THIS IS FOR
A Dutch hobby maker with a busy Arduino bench. Strong mechanical and practical skills — he
assembles kits, wires things, and reasons well about how machines work. Low coding skills:
he can copy-paste a sketch, change a number, and flash a board, but he cannot read a stack
trace and should never have to. He works on Windows. He also runs two Bambu Lab 3D printers,
a 6-DOF robot arm on MG996R servos, and does laser cutting and CNC milling. Treat him as
intelligent and technically minded, never as a beginner in general — only as someone who has
not been taught this specific thing yet.

TOPIC
Arduino, aimed at someone who already flashes sketches and wires sensors, but has never been
shown the capabilities that sit one step beyond copy-paste.

PRODUCE 5 SECTIONS, 4-6 CARDS EACH
  A. Boards worth knowing — what each is actually good at, and when the extra money is wasted
  B. Getting signals in — sensors, debouncing, analog vs digital, what "pull-up" really means
  C. Getting things to move — servos, steppers, motor drivers, and the power rules behind them
  D. Beyond the basic loop — interrupts, millis() vs delay(), state machines, watchdogs,
     saving settings to EEPROM
  E. Talking to other things — serial, I2C, SPI, and when each is the right choice

FORMAT, STRICTLY
- Each card: a question as its title, then at most 120 words of answer.
- Include a concrete number wherever one exists (voltage, current, pin count, timing, price).
- Every card ends with two lines:
      SOURCE: <url>
      CONFIDENCE: SOLID | COMMON | DISPUTED
  SOLID = documented by the manufacturer or a datasheet. COMMON = widely reported by users but
  not officially documented. DISPUTED = people genuinely disagree. Never dress a COMMON claim
  up as SOLID.
- No filler. Never write "it depends" without saying what it depends on.

THEN A FINAL SECTION: MYTHS AND OUTDATED ADVICE
At least 6 things commonly repeated about Arduino that are wrong, obsolete, or true only for
old boards. For each, say plainly what is true instead. This section matters more than the
rest — most bad hobby advice is advice that was correct five years ago.
```

---

## 2 · 3D printing on a Bambu A1 / A1 mini

```
You are compiling a reference dossier for an experienced hobby maker. Research thoroughly,
use primary sources where they exist, and cite everything.

WHO THIS IS FOR
A Dutch hobby maker who owns a Bambu Lab A1 mini and a Bambu Lab A1 with AMS Lite, and slices
in Bambu Studio. He designs his own parts in Fusion 360. Strong mechanical and practical
skills, low coding skills, works on Windows. Treat him as intelligent and technically minded,
never as a beginner in general.

TOPIC
Getting the most out of an A1 mini and an A1 with AMS Lite.

CRITICAL FRAMING — DO NOT GET THIS WRONG
These printers automatically calibrate bed level, Z-offset, resonance and flow dynamics
(pressure advance) before EVERY print. Do NOT give advice that assumes manual bed levelling,
manual Z-offset setting, or manual pressure-advance tuning — that advice is for a class of
printer he does not own, and following it would waste his evening. Focus on what is genuinely
still his decision, and on what is specific to this machine. Note also that the A1 series uses
a force sensor, NOT the LiDAR found on the P1/X1 — do not attribute LiDAR features to it.

PRODUCE 5 SECTIONS, 4-6 CARDS EACH
  A. What the A1 calibrates itself, and the few things it genuinely does not
  B. Filament — PLA, PETG, TPU, PLA-CF on an A1: what changes per material, what the AMS Lite
     can and cannot feed, drying, and which materials need a hardened nozzle
  C. The AMS Lite in practice — how much filament a colour change purges, how to design a part
     to reduce that, common failure modes, and when multi-colour is simply not worth it
  D. Settings that still matter — walls vs infill, supports, seam placement, part orientation
  E. Diagnosing failures on a self-calibrating printer — the real causes, in the order a
     sensible person should check them

FORMAT, STRICTLY
- Each card: a question as its title, then at most 120 words of answer.
- Include a concrete number wherever one exists (temperature, percentage, mm, grams).
- Every card ends with two lines:
      SOURCE: <url>
      CONFIDENCE: SOLID | COMMON | DISPUTED
  SOLID = documented by Bambu Lab or another manufacturer. COMMON = widely reported by users
  but not officially documented. DISPUTED = people genuinely disagree. Prefer the official
  Bambu Lab wiki over YouTube and Reddit, and mark it COMMON when user reports are the only
  source.
- No filler. Never write "it depends" without saying what it depends on.

THEN A FINAL SECTION: MYTHS AND OUTDATED ADVICE
At least 6 pieces of 3D-printing advice that are wrong, pointless or actively misleading
specifically on a self-calibrating Bambu A1. For each, say plainly what is true instead.
```

---

## 3 · Fusion 360, including the Python API

```
You are compiling a reference dossier for an experienced hobby maker. Research thoroughly,
use primary sources where they exist, and cite everything.

WHO THIS IS FOR
A Dutch hobby maker who already draws in Fusion 360 every day, on the free personal licence:
2D for laser cutting and CNC milling, 3D for his Bambu printers. So he knows sketching,
constraints and the general interface — do not explain those. What he has never done is script
it, and he has asked specifically how to load a Python program into Fusion. Low coding skills:
he can paste code and change a number, but cannot debug. He works on Windows. Treat him as
intelligent and technically minded, never as a beginner in general.

TOPIC
Fusion 360 beyond everyday drawing — parametric technique and the Python API.

PRODUCE 5 SECTIONS, 4-6 CARDS EACH
  A. Parametric modelling properly — user parameters, driven dimensions, and why a
     well-built sketch survives a size change while a badly-built one collapses
  B. The Python API — how scripts differ from add-ins, the object model in plain terms, the
     unit trap (the API works in CENTIMETRES, not millimetres), and how to debug when the
     script appears to do nothing at all
  C. Things worth scripting — the cases where a script beats the mouse decisively, with real
     examples: repeated features, families of sizes, hole patterns, finger-jointed boxes
  D. From Fusion to a machine — exporting for a 3D printer, for a laser, and for CNC; what
     each format keeps and what it throws away
  E. Limits of the free personal licence — exactly what is restricted, what is not, and what
     has changed recently

FORMAT, STRICTLY
- Each card: a question as its title, then at most 120 words of answer.
- Include a real API name, exact menu path, or number wherever one exists.
- Every card ends with two lines:
      SOURCE: <url>
      CONFIDENCE: SOLID | COMMON | DISPUTED
  SOLID = documented by Autodesk. COMMON = widely reported by users but not officially
  documented. DISPUTED = people genuinely disagree. Prefer Autodesk's own help and API
  reference over third-party tutorials.
- No filler. Never write "it depends" without saying what it depends on.

THEN A FINAL SECTION: MYTHS AND OUTDATED ADVICE
At least 6 things commonly said about Fusion 360 — especially about the free personal licence
and about scripting — that are wrong or out of date. For each, say plainly what is true now.
```

---

## 4 · Servos and the robot arm

```
You are compiling a reference dossier for an experienced hobby maker. Research thoroughly,
use primary sources where they exist, and cite everything.

WHO THIS IS FOR
A Dutch hobby maker with a 6-DOF robot arm he assembled himself from a kit, running on six
MG996R-class analog servos. The arm is already built, wired to a proper enclosed switching
power supply through a distribution board, and moving under program control from a laptop —
so he is well past first power-up and does not need beginner wiring advice. Strong mechanical
and practical skills, low coding skills, works on Windows. Treat him as intelligent and
technically minded, never as a beginner in general.

TOPIC
Hobby servos and small robot arms, specifically MG996R-class analog servos stacked six deep.

PRODUCE 5 SECTIONS, 4-6 CARDS EACH
  A. What an MG996R actually is — torque, current, speed, deadband, resolution, and what each
     of those numbers means once six of them are stacked in an arm
  B. Power — realistic draw versus stall draw, sizing a supply, fusing, and the brownout
     symptoms that look exactly like a software bug
  C. Control — PWM timing, driver boards (PCA9685 and alternatives), why smooth motion must be
     generated in software, and what having no position feedback rules out entirely
  D. Accuracy and repeatability — backlash, deadband, gravity sag, how error stacks across six
     joints, and the honest millimetre figure to expect at the tool tip
  E. Upgrades that actually change something — digital servos, servos with feedback, adding
     external encoders, counterweights or springs; each with a rough cost and what it buys

FORMAT, STRICTLY
- Each card: a question as its title, then at most 120 words of answer.
- Include a concrete number wherever one exists (kg-cm, amps, degrees, milliseconds, euros).
- Every card ends with two lines:
      SOURCE: <url>
      CONFIDENCE: SOLID | COMMON | DISPUTED
  SOLID = on a datasheet or from a measured bench test. COMMON = widely reported by users but
  not officially documented. DISPUTED = people genuinely disagree. Manufacturer torque claims
  for MG996R clones are frequently optimistic — say so where the evidence supports it, and
  prefer measured tests to marketing copy.
- No filler. Never write "it depends" without saying what it depends on.

THEN A FINAL SECTION: MYTHS AND OUTDATED ADVICE
At least 6 commonly repeated claims about hobby servos and cheap robot arms that are wrong or
misleading. For each, say plainly what is true instead.
```

---

## 5 · Laser cutting

```
You are compiling a reference dossier for an experienced hobby maker. Research thoroughly,
use primary sources where they exist, and cite everything.

WHO THIS IS FOR
A Dutch hobby maker who already draws 2D in Fusion 360 for laser cutting, but has no written
reference to work from. Strong mechanical and practical skills, low coding skills, works on
Windows. He also 3D prints and does CNC milling. Treat him as intelligent and technically
minded, never as a beginner in general — he understands machines, he just has not been given
the laser-specific numbers and rules.

TOPIC
Laser cutting, practically, for someone designing his own parts.

PRODUCE 5 SECTIONS, 4-6 CARDS EACH
  A. Materials — what cuts well, what cuts badly, and what must NEVER be lasered. Be specific
     and blunt about the toxic ones, PVC above all, and say exactly why and what it releases
  B. Kerf and fit — what kerf is, typical values by material and machine type, how to
     compensate for it in the drawing, and how to measure your own machine's kerf
  C. Joints that work — finger joints, T-slots, living hinges, press fits, and the tolerance
     each one needs to actually go together
  D. Preparing a file — line colours and widths for cut versus engrave, units, closed paths,
     and what exports cleanly out of Fusion 360
  E. Safety and extraction — fumes, fire risk, what must never be left unattended, and eye
     safety by laser class

FORMAT, STRICTLY
- Each card: a question as its title, then at most 120 words of answer.
- Include a concrete number wherever one exists (mm of kerf, wattage, mm/s, thickness).
- Every card ends with two lines:
      SOURCE: <url>
      CONFIDENCE: SOLID | COMMON | DISPUTED
  SOLID = manufacturer documentation, a safety standard, or a materials datasheet. COMMON =
  widely reported by users but not officially documented. DISPUTED = people genuinely disagree.
- Distinguish clearly between CO2, diode and fibre lasers wherever the answer differs between
  them — do not give one number as though it covers all three.
- No filler. Never write "it depends" without saying what it depends on.

THEN A FINAL SECTION: MYTHS AND OUTDATED ADVICE
At least 6 things commonly said about laser cutting that are wrong or outright dangerous. For
each, say plainly what is true instead.
```

---

## 6 · CNC milling

```
You are compiling a reference dossier for an experienced hobby maker. Research thoroughly,
use primary sources where they exist, and cite everything.

WHO THIS IS FOR
A Dutch hobby maker who draws 2D in Fusion 360 for CNC milling and routing, but has never been
taught the machining side properly. Strong mechanical intuition — he will understand forces,
chip loads and rigidity if you explain them in plain terms — but low coding skills and no
formal machining background. Works on Windows. He also 3D prints and laser cuts. Treat him as
intelligent and technically minded, never as a beginner in general.

TOPIC
Hobby CNC milling and routing, practically.

PRODUCE 5 SECTIONS, 4-6 CARDS EACH
  A. The four numbers — feed, speed, depth of cut, stepover: what each one does, how they
     trade off against each other, and how to recognise each being wrong from the sound the
     machine makes and the chips it throws
  B. Cutters — up-cut, down-cut, compression, single-flute, ball-nose, V-bit: what each is for,
     and which materials destroy which
  C. Materials — plywood, MDF, acrylic, aluminium: what changes for each, and which are
     realistic on a hobby-class machine at all
  D. Workholding — clamps, tabs, tape-and-glue, vacuum; and why workholding ruins more parts
     than cutting settings ever do
  E. Fusion 360 CAM — the toolpath types worth knowing, stock setup, simulation,
     post-processors, and the specific mistakes that end in a snapped cutter

FORMAT, STRICTLY
- Each card: a question as its title, then at most 120 words of answer.
- Include a concrete number wherever one exists (RPM, mm/min, depth in mm, chipload).
- Every card ends with two lines:
      SOURCE: <url>
      CONFIDENCE: SOLID | COMMON | DISPUTED
  SOLID = manufacturer documentation, a tooling catalogue, or a machining reference. COMMON =
  widely reported by users but not officially documented. DISPUTED = people genuinely disagree.
- Be explicit whenever a number applies to a rigid industrial machine and NOT to a hobby
  router — that confusion is how cutters get broken.
- No filler. Never write "it depends" without saying what it depends on.

THEN A FINAL SECTION: MYTHS AND OUTDATED ADVICE
At least 6 commonly repeated claims about hobby CNC that are wrong, or that get cutters
broken and parts ruined. For each, say plainly what is true instead.
```

---

## After the research comes back

1. Save the raw output to `research/dossiers/<topic>.md`, unedited, with the date and which
   tool produced it at the top.
2. **Check the `SOLID` claims that matter.** A deep-research tool will confidently mislabel
   things. Anything touching safety — power, fumes, materials that must not be cut, laser
   class — gets verified against a primary source before it reaches him.
3. Rewrite as Dutch cards in `site/kennis.html`. **Cut, do not translate.**
4. Where two sources genuinely disagree, mark the card `BETWIST` and say so rather than
   silently picking a side. He would rather know something is contested than be handed a
   confident guess.
