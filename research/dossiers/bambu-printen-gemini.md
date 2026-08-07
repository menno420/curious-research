<!-- RAW RESEARCH — do not edit. Rewrite into Dutch cards in site/kennis.html instead. -->
> **Topic:** bambu-printen · **Tool:** Gemini deep research · **Received:** 2026-08-07
> **Source:** the owner's Drive folder <https://drive.google.com/drive/folders/1Vg9HJxbKaBuv31Ovm4uSlIIMFyi7Yun3>
> Text extracted from the delivered PDF (`Bambu A1 Optimization Dossier Plan.pdf`, Drive id `14Q1Rf4Eemt10iY_ZUuNsBQr1HOUjW6VS`); PDF layout means headings and tables may run together.
> Saved unedited, per `research/deep-research-prompts.md` § After the research comes back.

---

Optimization  and  Technical  Operational  
Dossier
 
for
 
Bambu
 
Lab
 
A1
 
and
 
A1
 
Mini
 
Systems
 Section  A:  What  the  A1  Calibrates  Itself,  and  What  It  
Genuinely
 
Does
 
Not
 
How  does  automatic  bed  leveling  and  Z-offset  calibration  function  on  
the
 
A1
 
series?
 
The  A1  series  utilizes  force  sensors  embedded  beneath  the  heatbed  to  perform  automatic  
Z-offset
 
and
 
bed
 
leveling
 
without
 
manual
 
adjustment.
 
Before
 
printing,
 
the
 
nozzle
 
physically
 
touches
 
the
 
build
 
plate
 
across
 
a
 
grid,
 
measuring
 
contact
 
forces
 
to
 
determine
 
the
 
surface
 
bed
 
mesh.
 
This
 
compensates
 
for
 
surface
 
tilt
 
up
 
to
 
several
 
millimeters
 
across
 
the
 
256x256
 
mm
 
(A1)
 
or
 
180x180
 
mm
 
(A1
 
mini)
 
build
 
plate.
 
Manual
 
Z-offset
 
setting
 
and
 
bed
 
tramming
 
screws
 
are
 
absent.
 
The
 
nozzle
 
tip
 
must
 
remain
 
clean
 
of
 
debris
 
to
 
prevent
 
force
 
sensor
 
offset
 
errors
 
exceeding
 
0.02
 
mm.
 
SOURCE:
 
https://wiki.bambulab.com/en/knowledge-sharing/identify-and-fix-first-layer-issues-with-a-test-pri
nt
 
CONFIDENCE:
 
SOLID
 
How  does  the  A1  perform  automatic  flow  dynamics  calibration?  
Firmware  version  01.04.00.00+  enables  automated  dynamic  flow  calibration  (pressure  advance  
K-value)
 
using
 
an
 
eddy
 
current
 
sensor
 
in
 
the
 
toolhead.
 
Before
 
printing,
 
the
 
toolhead
 
extrudes
 
filament
 
at
 
the
 
purge
 
wiper
 
while
 
the
 
sensor
 
detects
 
real-time
 
extrusion
 
pressure
 
changes.
 
The
 
system
 
measures
 
hysteresis
 
during
 
acceleration
 
and
 
deceleration
 
to
 
calculate
 
a
 
precise
 
K-value,
 
typically
 
0.015
 
to
 
0.060.
 
Unlike
 
the
 
X1
 
series
 
which
 
uses
 
optical
 
LiDAR
 
to
 
scan
 
printed
 
lines
 
on
 
the
 
bed,
 
the
 
A1
 
calibrates
 
nozzle
 
pressure
 
directly
 
without
 
occupying
 
build
 
plate
 
space.
 
SOURCE:
 
https://wiki.bambulab.com/en/software/bambu-studio/calibration_pa
 
CONFIDENCE:
 
SOLID
 
How  does  the  A1  calibrate  vibration  resonance  compensation?  
The  A1  series  executes  automated  input  shaping  calibration  by  sweeping  excitation  frequencies  
through
 
X
 
and
 
Y
 
stepper
 
motors
 
during
 
initial
 
setup
 
or
 
calibration
 
routines.
 
Integrated
 
accelerometers
 
measure
 
structural
 
resonance
 
frequencies
 
from
 
10
 
Hz
 
to
 
100
 
Hz.
 
The
 
motion
 
controller
 
applies
 
anti-vibration
 
filtering
 
algorithms
 
to
 
eliminate
 
ringing
 
and
 
ghosting
 
at
 
speeds
 
up
 
to
 
500
 
mm/s
 
and
 
accelerations
 
up
 
to
 
10,000
 
mm/s².
 
Re-running
 
the
 
12-minute
 
machine
 
calibration
 
updates
 
input
 
shaping
 
parameters
 
whenever
 
the
 
printer
 
is
 
moved
 
or
 
belt
 
tension
 
is
 
adjusted.
 
SOURCE:
 
https://wiki.bambulab.com/en/a1/maintenance/basic-maintenance
 
CONFIDENCE:
 
SOLID
 
What  physical  maintenance  calibrations  must  be  performed  
manually?
 
Automatic  systems  cannot  physically  tension  belts,  lubricate  rails,  or  clear  extruder  debris.  
When
 
the
 
Health
 
Management
 
System
 
(HMS)
 
prompts
 
belt
 
tension
 
issues,
 
manually
 
loosen
 
the
 
H2.0
 
hex
 
screws
 
behind
 
the
 
toolhead
 
(X-axis),
 
under
 
the
 
bed
 
cover
 
(Y-axis),
 
or
 
beside
 
the
 
Z-column,
 
move
 
the
 
axis
 
2
 
to
 
3
 
times,
 
and
 
retighten.
 
Stainless
 
steel
 
guide
 
rails
 
require
 
manual
 
cleaning
 
and
 
oil
 
lubrication
 
monthly,
 
while
 
dual
 
Z-axis
 
lead
 
screws
 
require
 
grease
 
every
 
3
 
months.
 
Extruder
 
gear
 
housings
 
require
 
periodic
 
manual
 
cleaning
 
to
 
remove
 
filament
 
dust.
 
SOURCE:
 
https://wiki.bambulab.com/en/a1/maintenance/basic-maintenance
 
CONFIDENCE:
 
SOLID
 
What  slicing  and  material  parameters  remain  uncalibrated  by  the  
printer
 
hardware?
 
Auto-calibration  does  not  calculate  absolute  flow  ratio,  volumetric  speed  limits,  or  material  
shrinkage.
 
While
 
dynamic
 
flow
 
regulates
 
pressure
 
lag,
 
overall
 
dimensional
 
scaling
 
requires
 
entering
 
thermal
 
shrinkage
 
percentages
 
in
 
Bambu
 
Studio
 
1.10.0+
 
(e.g.,
 
99.2%
 
XY
 
compensation).
 
Maximum
 
volumetric
 
speed
 
(e.g.,
 
15
 
mm³/s
 
for
 
PLA,
 
12
 
mm³/s
 
for
 
PETG,
 
3.6
 
mm³/s
 
for
 
TPU)
 
must
 
be
 
manually
 
defined
 
in
 
filament
 
profiles
 
to
 
prevent
 
high-speed
 
under-extrusion.
 
Thermal
 
targets
 
like
 
hotend
 
temperature
 
(210°C–260°C)
 
and
 
bed
 
temperature
 
(60°C–80°C)
 
also
 
require
 
explicit
 
assignment.
 
SOURCE:
 
https://wiki.bambulab.com/en/software/bambu-studio/release/release-note-1-10-0
 
CONFIDENCE:
 
SOLID
 
Section  B:  Filament  Characteristics,  Feed  Mechanics,  
and
 
Hardware
 
Requirements
 
How  do  core  printing  parameters  differ  among  PLA,  PETG,  TPU,  and  
PLA-CF
 
on
 
the
 
A1?
 
PLA  prints  at  210°C–220°C  hotend  and  60°C  bed  temperature,  reaching  volumetric  speeds  
around
 
15
 
mm³/s.
 
PETG
 
requires
 
250°C–260°C
 
hotend
 
and
 
70°C–80°C
 
bed
 
temperature,
 
with
 
volumetric
 
speed
 
capped
 
at
 
12
 
mm³/s
 
for
 
layer
 
strength.
 
Flexible
 
TPU
 
95A
 
requires
 
220°C–240°C
 
hotend,
 
bed
 
temperatures
 
below
 
70°C,
 
and
 
a
 
strict
 
3.6
 
mm³/s
 
volumetric
 
speed
 
cap.
 
PLA-CF
 
prints
 
at
 
220°C–240°C
 
but
 
requires
 
a
 
hardened
 
steel
 
nozzle
 
to
 
resist
 
micro-abrasion
 
from
 
carbon
 
fibers.
 
SOURCE:
 
https://wiki.bambulab.com/en/h2/manual/soft-and-hard-filament-multi-material-printing-guide
 
CONFIDENCE:
 
SOLID
 
Which  filaments  are  compatible  with  the  AMS  Lite,  and  which  are  
strictly
 
prohibited?
 
The  AMS  Lite  reliably  feeds  standard  PLA,  PETG,  PLA-CF,  and  rigid  TPU  for  AMS.  Flexible  
TPU
 
variants
 
(85A,
 
90A,
 
95A)
 
are
 
strictly
 
prohibited
 
because
 
flexible
 
strands
 
buckle,
 
twist,
 
and
 
jam  inside  unassisted  feeder  gears  and  long  PTFE  tubes.  Highly  brittle  materials  like  wood  PLA  
or
 
damp
 
PVA
 
risk
 
snapping
 
inside
 
feed
 
channels.
 
Abrasive
 
filaments
 
like
 
PETG-CF
 
or
 
glow-in-the-dark
 
PLA
 
can
 
feed
 
temporarily
 
but
 
accelerate
 
internal
 
PTFE
 
tube
 
wear.
 
Incompatible
 
materials
 
must
 
feed
 
from
 
an
 
external
 
spool
 
directly
 
into
 
the
 
toolhead.
 
SOURCE:
 
https://wiki.bambulab.com/en/general/filament-guide-material-table
 
CONFIDENCE:
 
SOLID
 
What  are  the  exact  drying  parameters  required  for  hygroscopic  
filaments
 
on
 
the
 
A1?
 
PETG  requires  drying  at  60°C–65°C  for  8  hours  in  a  blast  oven.  TPU  95A  requires  drying  at  
70°C
 
for
 
8
 
to
 
12
 
hours.
 
Water-soluble
 
PVA
 
requires
 
strict
 
drying
 
at
 
75°C–85°C
 
for
 
8
 
to
 
12
 
hours
 
and
 
absorbs
 
moisture
 
within
 
1
 
to
 
3
 
hours
 
in
 
55%
 
RH
 
ambient
 
air.
 
Drying
 
on
 
the
 
A1
 
heatbed
 
requires
 
placing
 
an
 
enclosure
 
box
 
over
 
the
 
spool
 
at
 
80°C–90°C
 
for
 
12
 
hours,
 
flipping
 
the
 
spool
 
every
 
6
 
hours.
 
SOURCE:
 
https://wiki.bambulab.com/en/filament-acc/filament/dry-filament
 
CONFIDENCE:
 
SOLID
 
Why  is  a  hardened  steel  nozzle  required  for  composite  filaments  on  
the
 
A1?
 
The  stock  A1  printer  includes  a  0.4  mm  stainless  steel  nozzle.  Stainless  steel  has  low  Vickers  
hardness
 
and
 
erodes
 
rapidly
 
when
 
extruding
 
abrasive
 
composite
 
fibers
 
or
 
hard
 
particles
 
like
 
PLA-CF,
 
PETG-CF,
 
or
 
glow-in-the-dark
 
filaments.
 
Micro-abrasion
 
enlarges
 
the
 
nozzle
 
orifice
 
beyond
 
0.4
 
mm
 
after
 
printing
 
under
 
200
 
g
 
of
 
abrasive
 
material,
 
corrupting
 
flow
 
dynamics
 
and
 
dimensional
 
accuracy.
 
Upgrading
 
to
 
an
 
optional
 
0.4
 
mm,
 
0.6
 
mm,
 
or
 
0.8
 
mm
 
hardened
 
steel
 
nozzle
 
(HRA
 
90)
 
prevents
 
abrasive
 
wear.
 
Extruder
 
gears
 
on
 
the
 
A1
 
are
 
hardened
 
steel
 
standard.
 
SOURCE:
 
https://wiki.bambulab.com/en/a1/manual/faq
 
CONFIDENCE:
 
SOLID
 
Why  are  engineering  plastics  like  ABS,  ASA,  and  PC  unsuitable  for  
the
 
open-frame
 
A1?
 
ABS,  ASA,  and  PC  require  ambient  chamber  temperatures  between  45°C  and  60°C  to  manage  
high
 
thermal
 
contraction
 
stress.
 
Because
 
the
 
A1
 
and
 
A1
 
mini
 
feature
 
open-frame
 
motion
 
systems
 
without
 
enclosures,
 
draft
 
cooling
 
creates
 
temperature
 
differentials
 
exceeding
 
40°C
 
between
 
lower
 
and
 
upper
 
print
 
layers.
 
This
 
gradient
 
triggers
 
severe
 
warping,
 
corner
 
lifting
 
off
 
PEI
 
plates,
 
and
 
Z-axis
 
interlayer
 
separation.
 
Furthermore,
 
extruding
 
ABS
 
releases
 
styrene
 
gas
 
requiring
 
filtered
 
enclosed
 
ventilation.
 
Open-frame
 
usage
 
is
 
restricted
 
to
 
small
 
parts
 
under
 
50
 
mm
 
with
 
low
 
infill.
 
SOURCE:
 
https://wiki.bambulab.com/en/a1/manual/faq
 
CONFIDENCE:
 
SOLID
 
Section  C:  The  AMS  Lite  in  Practice  
How  much  filament  is  purged  during  color  changes,  and  how  is  it  
controlled?
 
Purge  mass  per  color  change  ranges  from  50  mm³  (~0.15  g)  for  light-to-dark  swaps  up  to  300  
mm³
 
(~0.90
 
g)
 
for
 
dark-to-light
 
transitions.
 
Bambu
 
Studio
 
utilizes
 
a
 
Flushing
 
Volumes
 
matrix
 
that
 
multiplies  base  values  by  coefficients  between  0.50  and  1.50  based  on  color  pigmentation.  A  
multi-color
 
job
 
with
 
400
 
layer
 
swaps
 
can
 
waste
 
100
 
g
 
to
 
300
 
g
 
of
 
filament
 
on
 
purge
 
material
 
alone
 
if
 
unoptimized.
 
During
 
swaps,
 
the
 
toolhead
 
cuts
 
filament,
 
retracts
 
through
 
the
 
AMS
 
Lite,
 
loads
 
the
 
new
 
strand,
 
and
 
purges
 
over
 
the
 
wiper
 
before
 
resuming
 
printing.
 
SOURCE:
 
https://wiki.bambulab.com/en/software/bambu-studio/release/release-note-1-10-0
 
CONFIDENCE:
 
SOLID
 
How  can  parts  and  slicer  profiles  be  designed  to  minimize  purge  
waste?
 
Designing  models  in  Fusion  360  with  color  transitions  aligned  strictly  along  the  Z-axis  eliminates  
mid-layer
 
filament
 
swaps
 
completely.
 
When
 
multi-color
 
features
 
exist
 
on
 
identical
 
XY
 
planes,
 
enable
 
"Flush
 
into
 
infill"
 
and
 
"Flush
 
into
 
support
 
objects"
 
in
 
Bambu
 
Studio
 
to
 
divert
 
up
 
to
 
60%
 
of
 
purge
 
volume
 
into
 
hidden
 
internal
 
structures.
 
Furthermore,
 
printing
 
multiple
 
identical
 
models
 
simultaneously
 
on
 
the
 
A1's
 
256x256
 
mm
 
bed
 
divides
 
fixed
 
per-layer
 
purge
 
volume
 
across
 
all
 
parts,
 
reducing
 
purge
 
waste
 
per
 
part
 
by
 
up
 
to
 
75%
 
in
 
a
 
4-part
 
batch.
 
SOURCE:
 
https://wiki.bambulab.com/en/software/bambu-studio/release/release-note-1-10-0
 
CONFIDENCE:
 
SOLID
 
What  are  the  primary  failure  modes  of  the  AMS  Lite  during  loading  
and
 
unloading?
 
AMS  Lite  failures  stem  from  filament  tangles,  gear  slippage,  or  broken  strands  inside  the  4-in-1  
toolhead
 
hub.
 
When
 
feeding
 
resistance
 
exceeds
 
motor
 
torque,
 
the
 
feeder
 
odometer
 
wheel
 
stops
 
turning,
 
triggering
 
error
 
HMS
 
1200_2000.
 
Snapped
 
filament
 
fragments
 
trapped
 
inside
 
the
 
4-way
 
splitter
 
block
 
physical
 
insertion
 
of
 
new
 
strands,
 
requiring
 
toolhead
 
hub
 
disassembly.
 
Placing
 
the
 
AMS
 
Lite
 
farther
 
than
 
50
 
mm
 
from
 
the
 
printer
 
creates
 
sharp
 
PTFE
 
tube
 
bending
 
radii,
 
increasing
 
friction
 
resistance
 
beyond
 
motor
 
feed
 
limits.
 
SOURCE:
 
https://wiki.bambulab.com/nl/ams-lite/troubleshooting/amslite-loading-unloading-failure
 
CONFIDENCE:
 
SOLID
 
When  is  multi-color  printing  economically  or  practically  inefficient  on  
the
 
A1?
 
Multi-color  printing  becomes  inefficient  when  cosmetic  color  swaps  occur  across  hundreds  of  
layers,
 
increasing
 
print
 
time
 
by
 
300%–500%
 
and
 
purge
 
waste
 
weight
 
beyond
 
model
 
weight.
 
A
 
20
 
g
 
model
 
requiring
 
350
 
color
 
swaps
 
can
 
consume
 
120
 
g
 
of
 
purged
 
filament
 
and
 
take
 
14
 
hours
 
instead
 
of
 
1.5
 
hours.
 
Multi-material
 
prints
 
combining
 
materials
 
with
 
incompatible
 
thermal
 
properties—such
 
as
 
PLA
 
and
 
PETG
 
for
 
primary
 
structural
 
bodies—fail
 
due
 
to
 
zero
 
interlayer
 
bonding
 
strength.
 
Multi-material
 
feeding
 
should
 
be
 
limited
 
to
 
thin
 
support
 
interface
 
layers.
 
SOURCE:
 
https://wiki.bambulab.com/en/h2/manual/soft-and-hard-filament-multi-material-printing-guide
 
CONFIDENCE:
 
COMMON
 
How  does  the  AMS  Lite  odometer  and  tangle  detection  mechanism  
prevent
 
air-printing?
 
Each  AMS  Lite  feeder  slot  contains  an  optical  rotary  odometer.  During  printing,  firmware  
cross-checks
 
odometer
 
pulse
 
counts
 
against
 
extruder
 
stepper
 
motor
 
step
 
commands
 
in
 
real
 
time.
 
If
 
a
 
spool
 
tangle,
 
knot,
 
or
 
nozzle
 
clog
 
halts
 
filament
 
movement
 
while
 
the
 
extruder
 
spins,
 
the
 
odometer
 
stops
 
pulsing.
 
On
 
firmware
 
01.02.00.00+,
 
detecting
 
an
 
velocity
 
discrepancy
 
triggers
 
active
 
air-printing
 
protection:
 
the
 
printer
 
automatically
 
cuts
 
filament,
 
retracts
 
from
 
the
 
toolhead,
 
pauses
 
execution,
 
and
 
alerts
 
the
 
user.
 
SOURCE:
 
https://wiki.bambulab.com/en/a1-mini/troubleshooting/hmscode/1200_2000_0002_0006
 
CONFIDENCE:
 
SOLID
 
Section  D:  Settings  That  Still  Matter  
How  should  walls,  shell  counts,  and  infill  patterns  be  configured  for  
mechanical
 
strength?
 
Part  strength  depends  primarily  on  perimeter  wall  counts  rather  than  high  infill  percentages.  
Increasing
 
wall
 
loops
 
from
 
2
 
to
 
4
 
increases
 
flexural
 
and
 
tensile
 
strength
 
by
 
up
 
to
 
80%.
 
For
 
functional
 
CAD
 
parts,
 
specify
 
4
 
perimeter
 
walls,
 
4
 
top
 
shells,
 
and
 
4
 
bottom
 
shells
 
in
 
Bambu
 
Studio.
 
Set
 
infill
 
density
 
between
 
15%
 
and
 
25%
 
using
 
non-crossing
 
3D
 
patterns
 
like
 
Gyroid
 
or
 
3D
 
Honeycomb.
 
Avoid
 
rectilinear
 
Grid
 
infill
 
on
 
moving
 
bed-slingers
 
like
 
the
 
A1,
 
as
 
intersecting
 
travel
 
paths
 
cause
 
nozzle
 
scraping
 
against
 
grid
 
intersections
 
at
 
high
 
speeds
 
above
 
200
 
mm/s.
 
SOURCE:
 
https://wiki.bambulab.com/en/software/bambu-studio/release/release-note-1-10-0
 
CONFIDENCE:
 
SOLID
 
What  support  parameters  produce  optimal  surface  finishes  and  easy  
removal?
 
Tree  supports  (Tree  Slim  or  Tree  Hybrid)  reduce  interface  contact  area  and  material  
consumption
 
by
 
30%–50%
 
compared
 
to
 
Normal
 
grid
 
supports.
 
For
 
single-material
 
supports
 
(PLA
 
supporting
 
PLA),
 
set
 
top
 
Z-distance
 
to
 
0.20
 
mm
 
with
 
3
 
top
 
interface
 
layers
 
at
 
0.5
 
mm
 
line
 
spacing.
 
When
 
using
 
dedicated
 
support
 
materials
 
(Support
 
for
 
PLA/PETG)
 
via
 
AMS
 
Lite,
 
set
 
top
 
Z-distance
 
to
 
0.00
 
mm
 
and
 
top
 
interface
 
density
 
to
 
100%
 
concentric,
 
creating
 
an
 
ultra-smooth
 
overhang
 
finish
 
that
 
releases
 
cleanly
 
after
 
cooling.
 
SOURCE:
 
https://wiki.bambulab.com/en/filament/support
 
CONFIDENCE:
 
SOLID
 
How  should  seam  placement  and  scarf  seams  be  configured  in  
Bambu
 
Studio?
 
Z-seam  visibility  can  be  minimized  using  scarf  seam  algorithms  in  Bambu  Studio  1.10.0+.  
Standard
 
seam
 
placement
 
should
 
be
 
set
 
to
 
"Aligned"
 
or
 
"Back"
 
along
 
sharp
 
geometric
 
edges.
 
On
 
cylindrical
 
models,
 
enabling
 
Scarf
 
Seam
 
creates
 
a
 
gradual
 
ramped
 
extrusion
 
flow
 
over
 
a
 
10
 
mm
 
to
 
20
 
mm
 
transition
 
zone
 
at
 
seam
 
starts
 
and
 
ends.
 
This
 
prevents
 
pressure
 
spikes
 
and
 
blob
 
formation.
 
Scarf
 
seams
 
are
 
enabled
 
by
 
default
 
for
 
PLA
 
Basic,
 
Matte,
 
Silk,
 
and
 
PLA-CF,
 
reducing
 
seam
 
protrusion
 
height
 
by
 
up
 
to
 
70%.
 
SOURCE:
 
https://wiki.bambulab.com/nl/software/bambu-studio/release/release-note-1-10-0
 
CONFIDENCE:
 
SOLID
 
How  does  part  orientation  affect  print  strength  and  bed  adhesion  on  
bed-slingers?
 
Tensile  loads  must  align  parallel  to  the  XY  build  plane;  vertical  prints  fail  under  40%  less  force  
due
 
to
 
interlayer
 
cleavage.
 
On
 
Y-axis
 
bed-slingers
 
like
 
the
 
A1,
 
high
 
Y-accelerations
 
(up
 
to
 
10,000
 
mm/s²)
 
induce
 
inertial
 
rocking
 
on
 
tall
 
models.
 
Align
 
long
 
model
 
axes
 
parallel
 
to
 
the
 
Y-axis
 
guide
 
rail
 
to
 
minimize
 
rocking
 
torque,
 
and
 
apply
 
a
 
5
 
mm
 
to
 
10
 
mm
 
outer
 
brim
 
for
 
tall
 
spires
 
with
 
bed
 
contact
 
area
 
under
 
400
 
mm².
 
SOURCE:
 
https://wiki.bambulab.com/en/a1-mini/manual/intro-a1-mini
 
CONFIDENCE:
 
SOLID
 
How  should  filament  thermal  scaling  compensation  be  applied  in  
Bambu
 
Studio?
 
Polymers  shrink  during  cooling  from  extrusion  temperatures  to  20°C  ambient.  Bambu  Studio  
1.10.0+
 
includes
 
Filament
 
Thermal
 
Scaling
 
Compensation.
 
If
 
a
 
100.00
 
mm
 
calibration
 
block
 
measures
 
99.20
 
mm
 
on
 
XY
 
axes
 
after
 
cooling,
 
shrinkage
 
is
 
0.80%.
 
Entering
 
a
 
99.20%
 
scaling
 
factor
 
in
 
filament
 
settings
 
scales
 
model
 
geometry
 
in
 
the
 
XY
 
plane
 
during
 
slicing
 
while
 
leaving
 
Z
 
unscaled.
 
This
 
ensures
 
engineered
 
tolerances
 
(e.g.,
 
0.20
 
mm
 
press
 
fits)
 
fit
 
precisely
 
without
 
altering
 
CAD
 
models.
 
SOURCE:
 
https://wiki.bambulab.com/en/software/bambu-studio/release/release-note-1-10-0
 
CONFIDENCE:
 
SOLID
 
Section  E:  Diagnosing  Failures  on  a  Self-Calibrating  
Printer
 
What  is  the  systematic  protocol  when  first-layer  bed  adhesion  fails  on  
an
 
A1?
 
When  first-layer  adhesion  fails,  finger  oil  contamination  on  the  PEI  plate  is  the  primary  cause.  
Wash
 
the
 
Textured
 
PEI
 
plate
 
thoroughly
 
with
 
warm
 
water
 
and
 
concentrated
 
dish
 
soap
 
using
 
a
 
clean
 
sponge,
 
then
 
dry
 
with
 
clean
 
paper
 
towels.
 
Avoid
 
using
 
Isopropyl
 
Alcohol
 
(IPA)
 
on
 
textured
 
PEI,
 
as
 
IPA
 
dissolves
 
and
 
spreads
 
lipids
 
into
 
textured
 
valleys.
 
Second,
 
check
 
that
 
the
 
hotend
 
quick-release
 
buckle
 
is
 
fully
 
locked
 
and
 
secured.
 
Third,
 
ensure
 
the
 
nozzle
 
tip
 
is
 
clean
 
of
 
hardened
 
filament
 
to
 
prevent
 
force
 
sensor
 
offset
 
errors.
 
SOURCE:
 
https://wiki.bambulab.com/en/knowledge-sharing/identify-and-fix-first-layer-issues-with-a-test-pri
nt
 
CONFIDENCE:
 
SOLID
 
How  should  motion  system  mechanics  and  belt  tension  be  diagnosed  
upon
 
HMS
 
warnings?
 
When  the  Health  Management  System  reports  resonance  frequency  shifts,  manual  belt  
tensioning
 
is
 
required.
 
For
 
the
 
X-axis,
 
loosen
 
the
 
tension
 
screw
 
behind
 
the
 
toolhead,
 
slide
 
the
 
toolhead
 
back
 
and
 
forth
 
2
 
to
 
3
 
times,
 
and
 
retighten.
 
For
 
the
 
Y-axis,
 
remove
 
the
 
rear
 
cover,
 
loosen
 
2
 
tension
 
screws,
 
move
 
the
 
bed
 
fully
 
back
 
and
 
forth
 
2
 
to
 
3
 
times,
 
and
 
retighten.
 
For
 
the
 
Z-axis,
 
loosen
 
2
 
tension
 
screws
 
near
 
the
 
right
 
pillar,
 
home
 
axes,
 
and
 
retighten.
 
Re-run
 
full
 
machine  calibration  afterward.  SOURCE:  
https://wiki.bambulab.com/en/a1/maintenance/basic-maintenance
 
CONFIDENCE:
 
SOLID
 
How  should  hotend  clogs  and  extruder  gear  grinding  be  cleared  on  
the
 
A1?
 
Grinding  noises  indicate  heat  creep  or  nozzle  blockages.  Perform  a  cold  pull  to  clear  partial  
clogs:
 
heat
 
nozzle
 
to
 
220°C,
 
feed
 
PLA,
 
cool
 
to
 
90°C,
 
and
 
pull
 
filament
 
upward
 
firmly
 
to
 
extract
 
debris.
 
If
 
the
 
filament
 
cutter
 
lever
 
is
 
stuck
 
forward,
 
push
 
it
 
manually
 
to
 
reset
 
the
 
hall
 
sensor.
 
For
 
persistent
 
clogs,
 
unlatch
 
the
 
toolhead
 
quick-release
 
lever,
 
remove
 
the
 
integrated
 
hotend
 
assembly,
 
and
 
clear
 
the
 
heat
 
break.
 
Clean
 
residual
 
dust
 
from
 
extruder
 
gears
 
using
 
a
 
brass
 
brush.
 
SOURCE:
 
https://wiki.bambulab.com/en/knowledge-sharing/how_to_avoid_nozzle_clogs
 
CONFIDENCE:
 
SOLID
 
What  causes  under-extrusion  or  air-printing  when  automatic  
calibrations
 
report
 
success?
 
If  bed  leveling  and  dynamic  flow  pass  but  under-extrusion  occurs,  check  filament  moisture  first.  
Wet
 
filament
 
creates
 
steam
 
pockets
 
that
 
disrupt
 
extrusion
 
pressure
 
despite
 
correct
 
K-values.
 
Second,
 
inspect
 
for
 
heat
 
creep:
 
high
 
ambient
 
room
 
temperatures
 
(>30°C)
 
or
 
fan
 
airflow
 
obstruction
 
cause
 
filament
 
to
 
soften
 
inside
 
the
 
titanium
 
thermal
 
break,
 
leading
 
to
 
extruder
 
slippage.
 
Third,
 
verify
 
that
 
filament
 
profile
 
settings
 
in
 
Bambu
 
Studio
 
do
 
not
 
contain
 
an
 
artificially
 
low
 
Max
 
Volumetric
 
Speed
 
cap
 
(e.g.,
 
2
 
mm³/s
 
instead
 
of
 
15
 
mm³/s).
 
SOURCE:
 
https://wiki.bambulab.com/en/software/bambu-studio/calibration_pa
 
CONFIDENCE:
 
SOLID
 
What  factors  cause  dimensional  inaccuracy  or  out-of-round  circles  on  
a
 
self-calibrated
 
printer?
 
Dimensional  skew  occurs  when  physical  mechanical  play  overrides  calibration  algorithms.  First,  
check
 
for
 
loose
 
X/Y
 
timing
 
belts;
 
backlash
 
from
 
loose
 
pulley
 
engagement
 
creates
 
ovalized
 
holes
 
along
 
direction
 
transitions.
 
Second,
 
check
 
the
 
four
 
hotend
 
mounting
 
screws
 
behind
 
the
 
toolhead
 
heater
 
block;
 
a
 
loose
 
heating
 
assembly
 
shifts
 
nozzle
 
position
 
under
 
extrusion
 
resistance.
 
Third,
 
check
 
Y-axis
 
linear
 
rail
 
carriage
 
play;
 
loose
 
carriage
 
screws
 
cause
 
bed
 
wobble
 
during
 
rapid
 
movement.
 
Finally,
 
verify
 
XY
 
thermal
 
scaling
 
compensation
 
in
 
Bambu
 
Studio.
 
SOURCE:
 
https://wiki.bambulab.com/en/a2l/manual/a2l-intro
 
CONFIDENCE:
 
SOLID
 
Myths  and  Outdated  Advice  
1.  Myth:  You  must  manually  level  the  heatbed  using  paper  or  feeler  gauges  before  
printing.
 ○  Truth :  The  A1  series  has  no  manual  leveling  thumbscrews  or  bed  tramming  
springs.
 
Force
 
sensors
 
under
 
the
 
heatbed
 
measure
 
physical
 
nozzle
 
contact
 
across
 
a
 
multi-point
 
grid
 
automatically,
 
generating
 
a
 
digital
 
bed
 
mesh
 
before
 
printing.
 
Manual
 
bed
 
leveling
 
procedures
 
do
 
not
 
apply
 
to
 
this
 
architecture.
 2.  Myth:  Z-offset  must  be  manually  set  or  adjusted  when  changing  build  plates.  ○  Truth :  Z-offset  is  calculated  automatically  during  pre-print  probing.  The  clean  nozzle  
tip
 
presses
 
against
 
the
 
build
 
plate
 
surface
 
using
 
load
 
cells
 
to
 
detect
 
contact
 
zero,
 
adjusting  for  plate  thickness  variations  automatically.  3.  Myth:  Pressure  advance  (K-value)  requires  manually  printing  and  inspecting  line  
calibration
 
patterns.
 ○  Truth :  Firmware  version  01.04.00.00+  enables  automatic  dynamic  flow  calibration  
using
 
an
 
eddy
 
current
 
pressure
 
sensor
 
inside
 
the
 
toolhead.
 
The
 
printer
 
extrudes
 
filament
 
over
 
the
 
purge
 
wiper,
 
detects
 
real-time
 
pressure
 
lag,
 
and
 
sets
 
the
 
K-value
 
automatically.
 4.  Myth:  Isopropyl  alcohol  (IPA)  is  the  superior  cleaning  solution  for  textured  PEI  
plates.
 ○  Truth :  IPA  dissolves  skin  lipids  but  spreads  them  evenly  into  the  textured  
micro-valleys
 
of
 
PEI
 
plates.
 
Washing
 
the
 
plate
 
with
 
warm
 
water
 
and
 
dish
 
soap
 
physically
 
removes
 
grease
 
and
 
restores
 
optimal
 
adhesion.
 5.  Myth:  High  infill  density  (80%–100%)  is  required  to  produce  strong  functional  parts.  ○  Truth :  Mechanical  strength  is  primarily  determined  by  perimeter  wall  loop  count.  
Increasing
 
wall
 
loops
 
from
 
2
 
to
 
4
 
yields
 
up
 
to
 
an
 
80%
 
strength
 
improvement
 
with
 
lower
 
print
 
time
 
and
 
weight
 
than
 
solid
 
infill.
 6.  Myth:  The  Bambu  A1  uses  LiDAR  to  scan  calibration  lines  on  the  bed.  ○  Truth :  LiDAR  sensors  are  used  exclusively  on  Bambu  X1  series  machines.  The  A1  
series
 
uses
 
bed
 
force
 
sensors
 
for
 
Z-probing
 
and
 
an
 
eddy
 
current
 
sensor
 
in
 
the
 
toolhead
 
for
 
dynamic
 
flow
 
calibration.
 7.  Myth:  Disabling  pre-print  auto-calibration  saves  time  without  affecting  quality.  ○  Truth :  Skipping  pre-print  resonance  sweeps,  bed  leveling,  and  dynamic  flow  
calibration
 
exposes
 
prints
 
to
 
thermal
 
expansion
 
shifts,
 
bed
 
tilt,
 
and
 
corner
 
bloat.
 
Running
 
pre-print
 
auto-calibration
 
ensures
 
first-layer
 
adhesion
 
and
 
dimensional
 
accuracy.
 
Geciteerd  werk  
1.  Flow  Dynamics  Calibration  |  Bambu  Lab  Wiki,  
https://wiki.bambulab.com/en/software/bambu-studio/calibration_pa
 
2.
 
Identify
 
and
 
Fix
 
First
 
Layer
 
Issues
 
With
 
a
 
Simple
 
Test
 
Print
 
|
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/knowledge-sharing/identify-and-fix-first-layer-issues-with-a-test-pri
nt
 
3.
 
A1
 
FAQ
 
|
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/a1/manual/faq?fbclid=IwAR2vHBgbZ1p4u_h4rN17gJ137_H_daRz
ocdLJtEFsvCLY4IWb0Ctdt2E278
 
4.
 
A1
 
mini
 
FAQ
 
|
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/a1-mini/manual/faq
 
5.
 
A1
 
Maintenance
 
Guidelines
 
-
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/a1/maintenance/basic-maintenance
 
6.
 
All
 
Public
 
Links
 
-
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/knowledge-sharing/all-public-links
 
7.
 
P2S
 
FAQ
 
-
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/p2s/manual/p2s-faq
 
8.
 
Z-axis
 
Motor
 
Replacement
 
Guide
 
for
 
A1
 
-
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/a1/maintenance/z-motor-replacement-guide
 
9.
 
Bambu
 
Studio
 
1.10.0
 
Public
 
Release
 
Note,
 
https://wiki.bambulab.com/en/software/bambu-studio/release/release-note-1-10-0
 
10.
 
Printing
 
method
 
when
 
PETG
 
HF
 
is
 
not
 
completely
 
dried
 
-
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/filament-acc/filament/petg-hf-unfinished-drying
 
11.
 
H2D
 
Soft
 
and
 
Hard
 
Filament
 
Multi-Material
 
Printing
 
Guide
 
-
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/h2/manual/soft-and-hard-filament-multi-material-printing-guide
 
12.
 
A1
 
mini
 
Introduction
 
|
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/a1-mini/manual/intro-a1-mini  13.  Filament  Drying  
Recommendations
 
-
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/filament-acc/filament/dry-filament
 
14.
 
Introduction
 
to
 
Bambu
 
Nozzles,
 
https://wiki.bambulab.com/en/filament-acc/acc/nozzles
 
15.
 
Filament
 
guide
 
-
 
Printer,
 
Nozzle,
 
AMS,
 
Build
 
Plate,
 
Glue
 
Compatibility
 
and
 
Required
 
Parameters
 
|
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/general/filament-guide-material-table
 
16.
 
TPU
 
Printing
 
Guide
 
-
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/knowledge-sharing/tpu-printing-guide
 
17.
 
Support
 
Filament
 
Usage
 
Guide
 
-
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/filament/support
 
18.
 
PVA
 
Printing
 
Guide
 
-
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/filament-acc/filament/pva-printing-guide
 
19.
 
ABS
 
/
 
ASA
 
/
 
PC
 
Usage
 
Guide
 
-
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/filament/abs_asa_pc
 
20.
 
A2L
 
Introduction
 
|
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/a2l/manual/a2l-intro
 
21.
 
PA6-GF
 
-
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/filament-acc/absgf-pa6gf/bambu_pa6-gf_technical_data_sheet.pdf
 
22.
 
AMS
 
lite:
 
Probleemoplossing
 
bij
 
storingen
 
bij
 
het
 
laden
 
en
 
lossen
 
van
 
filament,
 
https://wiki.bambulab.com/nl/ams-lite/troubleshooting/amslite-loading-unloading-failure
 
23.
 
HMS_1200-2000-0002-0006:
 
Failed
 
to
 
extrude
 
AMS1
 
Slot1
 
filament,
 
the
 
extruder
 
may
 
be
 
clogged,
 
or
 
the
 
filament
 
may
 
be
 
too
 
thin,
 
causing
 
the
 
extruder
 
slipping
 
|
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/a1-mini/troubleshooting/hmscode/1200_2000_0002_0006
 
24.
 
Seam
 
settings
 
-
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/software/bambu-studio/Seam
 
25.
 
Openbare
 
releaseopmerkingen
 
Bambu
 
Studio
 
1.10.0,
 
https://wiki.bambulab.com/nl/software/bambu-studio/release/release-note-1-10-0
 
26.
 
Y
 
Motor
 
Replacement
 
for
 
A1
 
|
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/a1/maintenance/y-motor-replacement-guide
 
27.
 
How
 
to
 
Avoid
 
Nozzle
 
Clogs
 
-
 
Bambu
 
Lab
 
Wiki,
 
https://wiki.bambulab.com/en/knowledge-sharing/how_to_avoid_nozzle_clogs
 