<!-- RAW RESEARCH — do not edit. Rewrite into Dutch cards in site/kennis.html instead. -->
> **Topic:** servos · **Tool:** Gemini deep research · **Received:** 2026-08-07
> **Source:** the owner's Drive folder <https://drive.google.com/drive/folders/1Vg9HJxbKaBuv31Ovm4uSlIIMFyi7Yun3>
> Text extracted from the delivered PDF (`6-DOF MG996R Arm Research.pdf`, Drive id `1X1kOltoKuHHu12s4DXVbqe49d4hHZg8Y`); PDF layout means headings and tables may run together.
> Saved unedited, per `research/deep-research-prompts.md` § After the research comes back.

---

Technical  Dossier:  Performance,  Power,  
and
 
Precision
 
in
 
6-DOF
 
MG996R
 
Robotic
 
Arms
 Section  A:  Characterization  and  Electromechanical  
Parameters
 
of
 
the
 
MG996R
 
What  are  the  official  datasheet  specifications  for  MG996R  torque,  
speed,
 
and
 
current?
 
The  original  TowerPro  MG996R  specification  sheet  lists  a  stall  torque  of  9.4  kgf·cm  at  4.8  V  and  
11.0
 
kgf·cm
 
at
 
6.0
 
V.
 
Operating
 
speed
 
is
 
0.17
 
s/60°
 
at
 
4.8
 
V
 
and
 
0.14
 
s/60°
 
at
 
6.0
 
V.
 
Operating
 
voltage
 
spans
 
4.8
 
V
 
to
 
7.2
 
V.
 
Quiescent
 
idle
 
current
 
draw
 
is
 
10
 
mA,
 
while
 
normal
 
operating
 
running
 
current
 
ranges
 
from
 
500
 
mA
 
to
 
900
 
mA
 
at
 
6.0
 
V.
 
Peak
 
stall
 
current
 
draw
 
is
 
specified
 
at
 
1.4
 
A
 
for
 
genuine
 
units
 
and
 
up
 
to
 
2.5
 
A
 
at
 
6.0
 
V
 
for
 
common
 
market
 
variants.
 
SOURCE:
 
https://towerpro.com.tw/product/mg996r/
 
CONFIDENCE:
 
SOLID
 
How  do  real-world  clone  performance  numbers  differ  from  original  
TowerPro
 
specifications?
 
While  genuine  TowerPro  units  achieve  close  to  rated  figures,  market  clones  widely  sold  on  
third-party
 
platforms
 
exhibit
 
substantially
 
lower
 
performance.
 
Measured
 
bench
 
tests
 
on
 
cheap
 
MG996R
 
clones
 
demonstrate
 
true
 
stall
 
torques
 
of
 
only
 
6.0
 
kg·cm
 
to
 
8.0
 
kg·cm
 
at
 
6.0
 
V,
 
falling
 
27%
 
to
 
45%
 
below
 
advertised
 
marketing
 
claims.
 
Furthermore,
 
internal
 
DC
 
motor
 
inefficiency
 
and
 
high-resistance
 
metal
 
gear
 
trains
 
cause
 
stall
 
current
 
draw
 
to
 
jump
 
to
 
2.5
 
A,
 
causing
 
elevated
 
thermal
 
build-up
 
and
 
voltage
 
sag
 
under
 
sustained
 
continuous
 
loads.
 
SOURCE:
 
https://www.tinkered.ai/components/servo-mg996r-straight
 
CONFIDENCE:
 
SOLID
 
What  does  deadband  width  mean,  and  how  does  a  5  μ s  deadband  
limit
 
joint
 
resolution?
 
Deadband  width  defines  the  minimum  change  in  control  pulse  width  required  before  the  internal  
feedback
 
amplifier
 
drives
 
the
 
motor.
 
The
 
MG996R
 
features
 
a
 
specified
 
deadband
 
of
 
5
 
μ
s.
 
Assuming
 
a
 
standard
 
1000
 
μ
s
 
control
 
pulse
 
span
 
(from
 
1000
 
μ
s
 
to
 
2000
 
μ
s)
 
mapping
 
to
 
120°
 
of
 
physical
 
output
 
rotation,
 
each
 
microsecond
 
corresponds
 
to
 
0.12°
 
of
 
motion.
 
Consequently,
 
a
 
5
 
μ
s
 
deadband
 
introduces
 
an
 
uncorrected
 
blind
 
zone
 
of
 
0.6°
 
per
 
joint,
 
where
 
position
 
changes
 
are
 
completely
 
ignored
 
by
 
the
 
internal
 
drive
 
circuit.
 
SOURCE:
 
https://www.electronicoscaldas.com/datasheet/MG996R_Tower-Pro.pdf
 
CONFIDENCE:
 
SOLID
 
What  is  the  actual  internal  mechanical  angular  resolution  of  an  analog  
servo  driving  a  potentiometer?  
Internal  analog  servo  electronics  rely  on  a  feedback  potentiometer  connected  to  an  analog  
comparator
 
network.
 
While
 
an
 
external
 
microcontroller
 
can
 
generate
 
sub-microsecond
 
PWM
 
command
 
steps,
 
mechanical
 
wiper
 
contact
 
noise,
 
gear
 
train
 
backlash,
 
and
 
comparator
 
electrical
 
hysteresis
 
limit
 
actual
 
repeatable
 
positioning
 
resolution.
 
In
 
practice,
 
standard
 
MG996R
 
analog
 
units
 
achieve
 
a
 
true
 
repeatable
 
angular
 
resolution
 
between
 
0.5°
 
and
 
1.0°,
 
making
 
command
 
increments
 
smaller
 
than
 
0.5°
 
mechanically
 
ineffective.
 
SOURCE:
 
https://www.tinkered.ai/components/servo-mg996r-straight
 
CONFIDENCE:
 
COMMON
 
How  does  stacking  six  MG996R  servos  compound  torque  demands  
and
 
deadband
 
errors
 
across
 
an
 
arm?
 
In  a  6-DOF  vertical  stack,  distal  joint  masses  accumulate  down  to  the  base.  Five  MG996R  
servos
 
weigh
 
275
 
g
 
combined,
 
excluding
 
structural
 
links.
 
At
 
a
 
30
 
cm
 
extended
 
reach,
 
static
 
gravity
 
moment
 
on
 
Joint
 
2
 
easily
 
exceeds
 
8.0
 
kg·cm,
 
consuming
 
over
 
70%
 
of
 
available
 
clone
 
stall
 
torque.
 
Simultaneously,
 
angular
 
deadband
 
errors
 
(0.6°
 
per
 
joint)
 
compound
 
along
 
the
 
link
 
chain,
 
creating
 
significant
 
tip
 
displacement.
 
SOURCE:
 
https://robocomp.in/product/towerpro-mg996r-digital-metal-gear-high-torque-servo-motor-180-ro
tation/
 
CONFIDENCE:
 
SOLID
 Parameter  Genuine  TowerPro  Datasheet  
Market  Clone  Measured  Test  
Stacked  6-DOF  Impact  
Stall  Torque  (6.0V)  11.0  kgf·cm  6.0  –  8.0  kgf·cm  Severe  link  gravity  sag  Stall  Current  (6.0V)  1.4  A  2.5  A  Up  to  15.0  A  peak  total  draw  Deadband  Width  1.0  –  5.0  μ s  5.0  –  10.0  μ s  Cumulative  tip  unresponsiveness  No-Load  Speed  (6.0V)  0.14  s/60°  0.16  s/60°  High  dynamic  jerk  without  trajectory  control  
Section  B:  Power  Supply  Sizing,  Distribution,  and  
Transient
 
Behavior
 
What  is  the  difference  between  operational  running  current  and  peak  
stall
 
current
 
across
 
six
 
servos?
 
Idle  current  draw  per  MG996R  servo  is  approximately  10  mA.  Operating  current  during  unladen  
motion
 
ranges
 
from
 
500
 
mA
 
to
 
900
 
mA
 
per
 
joint.
 
However,
 
when
 
accelerating
 
heavy
 
links
 
or
 
holding
 
loads
 
against
 
gravity,
 
current
 
spikes
 
to
 
2.5
 
A
 
per
 
motor.
 
If
 
all
 
six
 
joints
 
experience
 
instantaneous
 
stall
 
or
 
simultaneous
 
rapid
 
acceleration,
 
peak
 
total
 
current
 
demand
 
spikes
 
transiently
 
to
 
15.0
 
A
 
at
 
6.0
 
V.
 
SOURCE:
 
https://www.tinkered.ai/components/servo-mg996r-straight
 
CONFIDENCE:
 
SOLID
 
How  should  a  6  V  DC  switching  power  supply  be  sized  for  a  6-DOF  
MG996R  robot  arm?  
Continuous  running  draw  across  six  moving  axes  sits  between  3.0  A  and  5.4  A  at  6.0  V.  
However,
 
sizing
 
a
 
power
 
supply
 
solely
 
for
 
running
 
current
 
results
 
in
 
brownouts
 
during
 
acceleration
 
spikes.
 
A
 
regulated
 
6.0
 
V
 
switching
 
power
 
supply
 
rated
 
for
 
10.0
 
A
 
to
 
15.0
 
A
 
continuous
 
output
 
(60
 
W
 
to
 
90
 
W)
 
is
 
required
 
to
 
supply
 
peak
 
multi-axis
 
current
 
surges
 
without
 
voltage
 
drop.
 
SOURCE:
 
https://www.tinkered.ai/components/servo-mg996r-straight
 
CONFIDENCE:
 
COMMON
 
What  electrical  protection  and  fusing  strategies  should  be  applied  to  
servo
 
distribution
 
boards?
 
Install  a  12  A  to  15  A  fast-acting  fuse  on  the  main  6.0  V  DC  supply  rail  to  protect  wiring  and  
traces
 
against
 
dead-short
 
circuit
 
conditions.
 
Furthermore,
 
place
 
low-ESR
 
electrolytic
 
capacitors
 
ranging
 
from
 
470
 
μ
F
 
to
 
1000
 
μ
F
 
across
 
power
 
and
 
ground
 
bus
 
rails
 
directly
 
adjacent
 
to
 
servo
 
connection
 
headers
 
to
 
absorb
 
sharp
 
inductive
 
voltage
 
spikes
 
and
 
suppress
 
transient
 
current
 
sags.
 
SOURCE:
 
https://www.tinkered.ai/components/servo-mg996r-straight
 
CONFIDENCE:
 
SOLID
 
What  brownout  symptoms  occur  during  high  servo  current  draw,  and  
why
 
do
 
they
 
mimic
 
software
 
bugs?
 
When  joint  movement  spikes  current  draw  beyond  power  supply  transient  capacity,  rail  voltage  
momentarily
 
drops
 
below
 
microcontroller
 
reset
 
thresholds
 
(typically
 
<4.5
 
V).
 
This
 
triggers
 
an
 
automatic
 
controller
 
brownout
 
reset
 
or
 
I2C
 
bus
 
freeze,
 
causing
 
servos
 
to
 
unexpectedly
 
snap
 
back
 
to
 
home
 
positions
 
or
 
stop
 
mid-trajectory,
 
symptoms
 
that
 
are
 
frequently
 
misdiagnosed
 
as
 
code
 
bugs.
 
SOURCE:
 
https://www.tinkered.ai/components/servo-mg996r-straight
 
CONFIDENCE:
 
SOLID
 
Why  is  common  ground  wiring  critical  between  the  logic  controller  
and
 
the
 
servo
 
power
 
supply?
 
Standard  servo  cabling  routes  power  via  red  (VCC)  and  brown  (GND),  with  control  pulses  on  
orange
 
(SIG).
 
If
 
the
 
microcontroller
 
and
 
external
 
6.0
 
V
 
servo
 
power
 
supply
 
do
 
not
 
share
 
a
 
common
 
ground
 
connection,
 
the
 
PWM
 
control
 
signal
 
lacks
 
a
 
stable
 
0
 
V
 
reference
 
voltage.
 
This
 
floating
 
signal
 
reference
 
causes
 
severe
 
servo
 
jitter,
 
erratic
 
pulse
 
decoding,
 
or
 
complete
 
non-responsiveness.
 
SOURCE:
 
https://www.tinkered.ai/components/servo-mg996r-straight
 
CONFIDENCE:
 
SOLID
 
Section  C:  PWM  Timing,  Driver  Hardware,  and  
Kinematic
 
Control
 
What  are  the  precise  PWM  timing  parameters  required  to  command  
MG996R
 
servos?
 
MG996R  analog  servos  operate  on  a  standard  50  Hz  PWM  frequency,  corresponding  to  a  20  
ms
 
frame
 
period.
 
Operating
 
position
 
is
 
set
 
by
 
pulse
 
high
 
duration.
 
Datasheets
 
specify
 
a
 
center
 
neutral
 
position
 
(90°)
 
at
 
1500
 
μ
s,
 
with
 
standard
 
endpoint
 
travel
 
spanning
 
1000
 
μ
s
 
(0°)
 
to
 
2000
 
μ
s
 
(180°).
 
Some
 
extended
 
range
 
controllers
 
utilize
 
900
 
μ
s
 
to
 
2100
 
μ
s
 
pulse
 
ranges.
 
SOURCE:
 
https://robocomp.in/product/towerpro-mg996r-digital-metal-gear-high-torque-servo-motor-180-ro
tation/
 
CONFIDENCE:
 
SOLID
 
How  does  the  PCA9685  controller  driver  board  manage  multi-channel  
servo
 
PWM
 
offloading?
 
The  PCA9685  offloads  timing  generation  from  host  microcontrollers  using  an  integrated  25  MHz  
clock
 
oscillator
 
and
 
16
 
independent
 
12-bit
 
PWM
 
channels
 
controlled
 
via
 
I2C
 
at
 
speeds
 
up
 
to
 
1
 
MHz.
 
At
 
50
 
Hz,
 
its
 
4096-step
 
counter
 
provides
 
a
 
timer
 
resolution
 
of
 
approximately
 
4.88
 
μ
s
 
per
 
tick,
 
allowing
 
precise
 
pulse
 
width
 
configuration
 
across
 
all
 
channels
 
without
 
host
 
processor
 
overhead.
 
SOURCE:
 
https://www.lisleapex.com/blog-pca9685-16-channel-led-controller-datasheet-by-nxp-semicondu
ctors
 
CONFIDENCE:
 
SOLID
 
Why  must  trajectory  generation  and  velocity  interpolation  be  
generated
 
in
 
host
 
software?
 
Analog  servo  drive  electronics  attempt  to  reach  target  positions  at  maximum  motor  velocity  
(~0.14
 
s/60°
 
at
 
6.0
 
V)
 
whenever
 
pulse
 
width
 
changes.
 
Transmitting
 
step-change
 
positions
 
causes
 
violent
 
arm
 
jerks
 
and
 
severe
 
structural
 
vibration.
 
Software
 
must
 
interpolate
 
joint
 
trajectories
 
using
 
acceleration-limited
 
S-curves
 
updated
 
every
 
10
 
ms
 
to
 
20
 
ms
 
to
 
produce
 
smooth
 
mechanical
 
motion.
 
SOURCE:
 
https://www.tinkered.ai/components/servo-mg996r-straight
 
CONFIDENCE:
 
COMMON
 
What  capabilities  and  control  modes  are  ruled  out  entirely  by  having  
no
 
position
 
feedback?
 
Standard  MG996R  servos  operate  strictly  open-loop  relative  to  host  software.  The  internal  
feedback
 
potentiometer
 
closes
 
the
 
control
 
loop
 
locally
 
inside
 
the
 
servo
 
casing,
 
but
 
sends
 
no
 
position
 
telemetry
 
back
 
to
 
the
 
controller.
 
Consequently,
 
host
 
software
 
cannot
 
detect
 
joint
 
stalls,
 
mechanical
 
obstruction,
 
skipped
 
motion,
 
manual
 
external
 
displacement,
 
or
 
actual
 
current
 
loads.
 
SOURCE:
 
https://www.robotshop.com/products/hiwonder-hiwonder-lx-16a-full-metal-gear-serial-bus-servo-
with-real-time-feedback-function-rc-robot-control-angle-240
 
CONFIDENCE:
 
SOLID
 
How  do  software  timing  delays  on  Windows  PCs  affect  real-world  
motion
 
smoothness?
 
Windows  is  not  a  real-time  operating  system,  introducing  non-deterministic  USB/serial  thread  
scheduling
 
delays
 
between
 
1
 
ms
 
and
 
15
 
ms.
 
If
 
host
 
software
 
sends
 
real-time
 
trajectory
 
frames
 
individually
 
over
 
serial
 
without
 
timing
 
buffers,
 
uneven
 
pulse
 
transmission
 
intervals
 
cause
 
stuttered
 
joint
 
velocity
 
profiles
 
and
 
audible
 
mechanical
 
chatter
 
during
 
arm
 
movement.
 
SOURCE:
 
https://www.lisleapex.com/blog-pca9685-16-channel-led-controller-datasheet-by-nxp-semicondu
ctors  CONFIDENCE:  COMMON  
Section  D:  Kinematic  Error  Propagation,  Backlash,  
and
 
Positional
 
Accuracy
 
What  is  the  physical  gear  backlash  in  MG996R  metal  gear  trains?  
The  internal  metal  gear  train  of  MG996R  units  exhibits  inherent  mechanical  tooth  play.  
Measured
 
gear
 
backlash
 
at
 
the
 
output
 
spline
 
shaft
 
ranges
 
from
 
0.5°
 
to
 
1.5°.
 
This
 
angular
 
clearance
 
allows
 
free
 
movement
 
of
 
the
 
output
 
horn
 
even
 
when
 
the
 
internal
 
motor
 
shaft
 
is
 
locked,
 
establishing
 
a
 
mechanical
 
accuracy
 
limit
 
independent
 
of
 
electronics.
 
SOURCE:
 
https://www.tinkered.ai/components/servo-mg996r-straight
 
CONFIDENCE:
 
SOLID
 
How  does  structural  elastic  deflection  and  gravity  sag  affect  6-DOF  
robot
 
arm
 
positioning?
 
Beyond  gear  backlash  and  deadband,  cantilevered  arm  links  flex  elastically  under  load.  On  a  
6-DOF
 
arm
 
with
 
a
 
40
 
cm
 
maximum
 
reach
 
carrying
 
a
 
100
 
g
 
payload,
 
structural
 
link
 
flex
 
and
 
bearing
 
play
 
introduce
 
an
 
additional
 
2.0
 
mm
 
to
 
5.0
 
mm
 
of
 
uncompensated
 
vertical
 
gravity
 
sag
 
at
 
the
 
end-effector.
 
SOURCE:
 
https://robocomp.in/product/towerpro-mg996r-digital-metal-gear-high-torque-servo-motor-180-ro
tation/
 
CONFIDENCE:
 
COMMON
 
How  does  error  stack  mathematically  across  six  cascaded  articulated  
joints?
 
Total  joint  angular  uncertainty  (\Delta  \theta)  combines  0.6°  deadband  with  1.0°  backlash,  
totaling
 
~1.6°
 
(0.028
 
rad)
 
per
 
axis.
 
For
 
an
 
extended
 
arm
 
of
 
length
 
L
 
=
 
400\text{
 
mm},
 
worst-case
 
Cartesian
 
tool
 
tip
 
uncertainty
 
scales
 
as
 
\Delta
 
x
 
\approx
 
\sum
 
L_i
 
\Delta
 
\theta_i,
 
resulting
 
in
 
cumulative
 
tip
 
position
 
error
 
exceeding
 
15
 
mm
 
to
 
25
 
mm.
 
SOURCE:
 
https://www.tinkered.ai/components/servo-mg996r-straight
 
CONFIDENCE:
 
COMMON
 
What  is  the  honest,  realistic  millimeter  repeatability  figure  to  expect  at  
the
 
tool
 
tip?
 
When  approaching  a  target  coordinate  from  identical  directions  under  static  payload  conditions,  
tool
 
tip
 
positioning
 
repeatability
 
is
 
approximately
 
±5.0
 
mm
 
to
 
±8.0
 
mm.
 
When
 
approaching
 
targets
 
from
 
varying
 
directions
 
under
 
dynamic
 
payloads,
 
absolute
 
spatial
 
accuracy
 
degrades
 
to
 
±15.0
 
mm
 
to
 
±25.0
 
mm
 
at
 
a
 
40
 
cm
 
extension.
 
SOURCE:
 
https://www.tinkered.ai/components/servo-mg996r-straight
 
CONFIDENCE:
 
COMMON
 
How  does  thermal  drift  in  internal  analog  potentiometer  circuits  affect  
long-term
 
precision?
 
Continuous  holding  torque  heats  internal  servo  motors  and  potentiometer  electronics  from  
ambient
 
20
 
°C
 
up
 
to
 
55
 
°C.
 
Resistance
 
changes
 
within
 
the
 
analog
 
feedback
 
circuit
 
alter
 
internal
 
voltage  references,  introducing  a  baseline  position  drift  of  0.5°  to  1.0°  per  joint,  which  translates  
to
 
2.0
 
mm
 
to
 
5.0
 
mm
 
tool
 
tip
 
drift
 
over
 
30
 
minutes.
 
SOURCE:
 
https://www.electronicoscaldas.com/datasheet/MG996R_Tower-Pro.pdf
 
CONFIDENCE:
 
SOLID
 
Section  E:  Structural  and  Hardware  Upgrade  Paths  
What  performance  changes  occur  when  replacing  analog  servos  with  
digital
 
standard
 
servos?
 
Digital  servos  replace  analog  comparator  circuits  with  high-speed  microcontrollers  operating  
internal
 
control
 
loops
 
at
 
300
 
Hz
 
or
 
higher.
 
At
 
a
 
cost
 
of
 
roughly
 
€10
 
to
 
€15
 
per
 
unit,
 
digital
 
variants
 
reduce
 
deadband
 
below
 
1
 
μ
s,
 
drastically
 
increase
 
holding
 
torque
 
responsiveness,
 
and
 
eliminate
 
low-frequency
 
position
 
chatter.
 
SOURCE:
 
https://towerpro.com.tw/product/mg996r/
 
CONFIDENCE:
 
SOLID
 
What  capabilities  do  serial  bus  servos  like  Hiwonder  LX-16A  or  
Feetech
 
STS3215
 
provide?
 
Serial  bus  servos  (costing  €20  to  €28  per  unit)  replace  individual  PWM  control  wires  with  
daisy-chained
 
half-duplex
 
UART
 
communication.
 
They
 
deliver
 
up
 
to
 
17
 
kg·cm
 
to
 
19
 
kg·cm
 
torque
 
and
 
transmit
 
real-time
 
telemetry
 
(actual
 
angle,
 
voltage,
 
and
 
internal
 
temperature)
 
back
 
to
 
host
 
software.
 
SOURCE:
 
https://www.robotshop.com/products/hiwonder-hiwonder-lx-16a-full-metal-gear-serial-bus-servo-
with-real-time-feedback-function-rc-robot-control-angle-240
 
CONFIDENCE:
 
SOLID
 
How  does  mounting  external  AS5600  magnetic  encoders  improve  arm  
position
 
accuracy?
 
Adding  AS5600  12-bit  contactless  magnetic  rotary  encoders  (~€3.00  to  €5.00  per  axis)  directly  
to
 
joint
 
pivot
 
axes
 
bypasses
 
gearbox
 
backlash
 
and
 
potentiometer
 
thermal
 
drift.
 
Reading
 
direct
 
joint
 
angle
 
via
 
I2C
 
provides
 
4096
 
counts
 
per
 
revolution
 
(0.088°
 
resolution)
 
for
 
true
 
closed-loop
 
joint
 
position
 
control.
 
SOURCE:
 
https://www.laskakit.cz/en/magneticky-rotacni-enkoder-as5600--i2c--pwm/
 
CONFIDENCE:
 
SOLID
 
How  do  physical  counterweights  or  mechanical  springs  reduce  joint  
motor
 
torque
 
requirements?
 
Attaching  extension  springs  or  counterweight  masses  across  shoulder  and  elbow  joint  linkages  
balances
 
static
 
gravitational
 
loads.
 
Lowering
 
static
 
torque
 
load
 
by
 
50%
 
to
 
70%
 
reduces
 
continuous
 
running
 
current
 
from
 
900
 
mA
 
down
 
to
 
300
 
mA,
 
mitigating
 
motor
 
overheating
 
and
 
structural
 
gravity
 
sag
 
for
 
~€5.00
 
in
 
materials.
 
SOURCE:
 
https://www.tinkered.ai/components/servo-mg996r-straight
 
CONFIDENCE:
 
COMMON
 
When  is  upgrading  to  high-voltage  NEMA  17  stepper  motors  with  
planetary  gearboxes  warranted?  
When  applications  demand  sub-millimeter  precision  (<0.5  mm),  zero  backlash  drift,  silent  
holding,
 
and
 
payloads
 
over
 
500
 
g,
 
replacing
 
servos
 
with
 
NEMA
 
17
 
stepper
 
motors
 
featuring
 
10:1
 
to
 
50:1
 
planetary
 
gearboxes
 
is
 
warranted.
 
Total
 
conversion
 
costs
 
range
 
from
 
€120
 
to
 
€200
 
across
 
a
 
6-axis
 
arm.
 
SOURCE:
 
https://www.robotshop.com/products/hiwonder-hiwonder-lx-16a-full-metal-gear-serial-bus-servo-
with-real-time-feedback-function-rc-robot-control-angle-240
 
CONFIDENCE:
 
COMMON
 Upgrade  Path  Unit  Cost  Primary  Architectural  Benefit  
Key  Technical  Limitation  Digital  Standard  Servos  
€10  –  €15  Sub-microsecond  deadband,  higher  holding  torque  
Retains  open-loop  PWM  &  potentiometer  drift  Serial  Bus  Servos  (LX-16A  /  STS3215)  
€20  –  €28  Position,  voltage  &  temperature  feedback  
Requires  UART  conversion  board  External  AS5600  Magnetic  Encoders  
€3  –  €5  Direct  joint  measurement  (0.088°  resolution)  
Requires  custom  joint  mounting  &  software  integration  Mechanical  Counterweights  /  Springs  
~€5  50–70%  reduction  in  static  gravity  torque  
Adds  inertia  to  rapid  unweighted  movements  
Planetary  Stepper  Motors  (NEMA  17)  
€120  –  €200  Sub-millimeter  position  accuracy  (<0.5  mm)  
Requires  complete  mechanical  redesign  &  stepper  drivers  
Section  F:  Myths  and  Outdated  Advice  
Myth  1:  MG996R  servos  deliver  11  kg·cm  of  continuous  operational  
torque
 
in
 
robot
 
joints.
 
What  is  false:  Expecting  MG996R  servos  to  continuously  move  or  hold  loads  requiring  11  
kg·cm
 
torque.
 
What
 
is
 
true:
 
The
 
11.0
 
kgf·cm
 
specification
 
is
 
absolute
 
static
 
stall
 
torque
 
at
 
6.0
 
V
 
right
 
before
 
total
 
motor
 
stall.
 
Continuous
 
operating
 
torque
 
without
 
thermal
 
destruction
 
or
 
severe
 
voltage
 
drop
 
is
 
only
 
2.0
 
kg·cm
 
to
 
3.0
 
kg·cm
 
(~20%
 
to
 
25%
 
of
 
stall
 
rating).
 
Myth  2:  Powering  servos  directly  from  an  Arduino  5  V  pin  is  fine  for  
small
 
testing.
 
What  is  false:  Assuming  onboard  microcontroller  regulators  can  power  MG996R  servos.  What  
is
 
true:
 
An
 
MG996R
 
stall
 
current
 
reaches
 
2.5
 
A.
 
Microcontroller
 
onboard
 
5
 
V
 
regulators
 
supply
 
under
 
500
 
mA
 
total.
 
Connecting
 
even
 
one
 
servo
 
under
 
load
 
triggers
 
instantaneous
 
supply
 
brownouts
 
and
 
microcontroller
 
resets.
 
Myth  3:  A  PCA9685  driver  board  handles  motion  smoothing  and  
trajectory
 
planning
 
automatically.
 
What  is  false:  Expecting  the  PCA9685  to  smooth  joint  movement  between  commanded  
positions.  What  is  true:  The  PCA9685  is  strictly  a  hardware  PWM  timer  IC  that  holds  configured  
duty
 
cycles.
 
It
 
lacks
 
internal
 
trajectory
 
generation;
 
step
 
updates
 
to
 
registers
 
cause
 
instantaneous
 
full-speed
 
joint
 
snaps.
 
Myth  4:  Analog  MG996R  servos  provide  full  180°  rotation  under  
standard
 
1
 
ms
 
to
 
2
 
ms
 
PWM
 
signals.
 
What  is  false:  Believing  standard  1000  μ s  to  2000  μ s  pulses  produce  180°  of  rotation.  What  is  
true:
 
Standard
 
1000
 
μ
s
 
to
 
2000
 
μ
s
 
pulses
 
yield
 
approximately
 
120°
 
of
 
physical
 
rotation
 
on
 
standard
 
MG996R
 
units.
 
Reaching
 
180°
 
requires
 
extended
 
non-standard
 
pulses
 
(500
 
μ
s
 
to
 
2500
 
μ
s),
 
which
 
can
 
drive
 
motors
 
against
 
internal
 
mechanical
 
stops
 
and
 
cause
 
burnouts.
 
Myth  5:  Increasing  controller  PWM  pulse  resolution  improves  physical  
positioning
 
precision.
 
What  is  false:  Assuming  higher  timer  resolution  eliminates  positioning  error.  What  is  true:  
Sub-microsecond
 
PWM
 
resolution
 
cannot
 
bypass
 
mechanical
 
limits.
 
Internal
 
servo
 
deadband
 
(5
 
μ
s)
 
and
 
gear
 
backlash
 
(0.5°–1.5°)
 
impose
 
a
 
physical
 
precision
 
floor
 
regardless
 
of
 
control
 
pulse
 
resolution.
 
Myth  6:  Mathematical  Inverse  Kinematics  guarantees  millimeter  tool  
tip
 
positioning.
 
What  is  false:  Expecting  theoretical  Kinematic  software  outputs  to  match  physical  tool  
positions.
 
What
 
is
 
true:
 
Inverse
 
Kinematics
 
calculates
 
ideal
 
geometrical
 
angles
 
but
 
ignores
 
joint
 
gear
 
backlash,
 
deadband
 
hysteresis,
 
thermal
 
drift,
 
and
 
link
 
gravity
 
sag,
 
leading
 
to
 
actual
 
end-effector
 
errors
 
of
 
15
 
mm
 
to
 
25
 
mm.
 
Myth  7:  Digital  servos  draw  less  current  than  analog  servos  when  
holding
 
static
 
positions.
 
What  is  false:  Believing  digital  servos  are  more  power-efficient  under  load.  What  is  true:  
Digital
 
servos
 
drive
 
internal
 
motors
 
with
 
high-frequency
 
pulse
 
trains
 
(300
 
Hz+)
 
to
 
maintain
 
position,
 
drawing
 
higher
 
continuous
 
average
 
current
 
and
 
generating
 
significantly
 
more
 
heat
 
under
 
load
 
than
 
analog
 
servos.
 
Geciteerd  werk  
1.  TowerPro  MG996R  Digital  Metal  Gear  High  Torque  Servo  Motor  (180°  Rotation),  
https://robocomp.in/product/towerpro-mg996r-digital-metal-gear-high-torque-servo-motor-180-ro
tation/
 
2.
 
MG996R
 
-
 
Tower
 
Pro,
 
https://towerpro.com.tw/product/mg996r/
 
3.
 
MG996R
 
High
 
Torque
 
-
 
Metal
 
Gear
 
Dual
 
Ball
 
Bearing
 
Servo
 
-
 
Electronicos
 
Caldas,
 
https://www.electronicoscaldas.com/datasheet/MG996R_Tower-Pro.pdf
 
4.
 
TowerPro
 
MG996R
 
Digital
 
High
 
Torque
 
Servo
 
Motor
 
-
 
Robu.in,
 
https://robu.in/product/towardpro-mg996r-digital-high-torque-servo-motor/
 
5.
 
MG996R
 
Servo
 
Motor:
 
Specs,
 
Wiring
 
&
 
Arduino
 
Guide
 
|
 
Tinkered,
 
https://www.tinkered.ai/components/servo-mg996r-straight
 
6.
 
MG996R
 
All
 
Metal
 
Gear
 
Servo
 
Motor  -  UNTAG  SURABAYA  REPOSITORY,  
http://repository.untag-sby.ac.id/13415/9/LAMPIRAN%202.pdf
 
7.
 
PCA9685
 
16-channel
 
LED
 
Controller
 
Datasheet
 
by
 
NXP
 
Semiconductors
 
2025
 
|
 
Lisleapex,
 
https://www.lisleapex.com/blog-pca9685-16-channel-led-controller-datasheet-by-nxp-semicondu
ctors
 
8.
 
PCA9685
 
16-Channel,
 
12-bit
 
PWM/Servo/LED
 
Driver
 
IC
 
-
 
Components101,
 
https://components101.com/ics/pca9685-led-driver
 
9.
 
Hiwonder
 
LX-16A
 
Full
 
Metal
 
Gear
 
Serial
 
Bus
 
Servo
 
with
 
Real-Time
 
Feedback
 
Function
 
for
 
RC
 
Robot
 
(Control
 
Angle
 
240)
 
-
 
RobotShop,
 
https://www.robotshop.com/products/hiwonder-hiwonder-lx-16a-full-metal-gear-serial-bus-servo-
with-real-time-feedback-function-rc-robot-control-angle-240
 
10.
 
Smart
 
Servo
 
Motors
 
-
 
RobotShop,
 
https://www.robotshop.com/collections/smart-servo-motors
 
11.
 
Magnetic
 
rotary
 
encoder
 
AS5600,
 
I2C,
 
PWM
 
-
 
LaskaKit,
 
https://www.laskakit.cz/en/magneticky-rotacni-enkoder-as5600--i2c--pwm/
 
12.
 
Grove
 
12-bit
 
Magnetic
 
Rotary
 
Position
 
Sensor
 
(AS5600)
 
-
 
RobotShop,
 
https://www.robotshop.com/products/grove-12-bit-magnetic-rotary-position-sensor-as5600
 