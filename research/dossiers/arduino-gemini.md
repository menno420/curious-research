<!-- RAW RESEARCH — do not edit. Rewrite into Dutch cards in site/kennis.html instead. -->
> **Topic:** arduino · **Tool:** Gemini deep research · **Received:** 2026-08-07
> **Source:** the owner's Drive folder <https://drive.google.com/drive/folders/1Vg9HJxbKaBuv31Ovm4uSlIIMFyi7Yun3>
> Text extracted from the delivered PDF (`Arduino Advanced Hobby Dossier.pdf`, Drive id `1zfPeCkP8wTEustQdn4mI245YWk7CRcDF`); PDF layout means headings and tables may run together.
> Saved unedited, per `research/deep-research-prompts.md` § After the research comes back.

---

Arduino  Technical  Reference  Dossier:  
Hardware
 
Architecture,
 
Interfacing,
 
and
 
System
 
Design
 Section  A:  Boards  Worth  Knowing  
What  makes  the  Arduino  Uno  R4  Minima  superior  to  the  classic  
ATmega328P
 
Uno
 
R3?
 
The  Uno  R4  Minima  replaces  the  8-bit,  16  MHz  ATmega328P  with  a  32-bit  Renesas  RA4M1  
Arm
 
Cortex-M4
 
processor
 
running
 
at
 
48
 
MHz.
 
Memory
 
expands
 
from
 
2
 
KB
 
SRAM
 
and
 
32
 
KB
 
Flash
 
to
 
32
 
KB
 
SRAM
 
and
 
256
 
KB
 
Flash.
 
Operating
 
at
 
5V
 
logic
 
for
 
retro-shield
 
compatibility,
 
its
 
buck
 
regulator
 
accepts
 
input
 
voltages
 
from
 
6V
 
to
 
24V
 
via
 
VIN,
 
supplying
 
up
 
to
 
1.2A
 
at
 
5V.
 
Features
 
include
 
a
 
true
 
12-bit
 
DAC
 
on
 
pin
 
A0,
 
14-bit
 
ADC
 
resolution,
 
a
 
CAN
 
2.0B
 
controller,
 
HID
 
USB-C
 
support,
 
and
 
an
 
RTC.
 
However,
 
maximum
 
GPIO
 
source/sink
 
current
 
decreases
 
from
 
40mA
 
to
 
8mA
 
per
 
pin.
 SOURCE:  https://docs.arduino.cc/resources/datasheets/ABX00080-datasheet.pdf  
CONFIDENCE:
 
SOLID
 
When  is  an  Arduino  Mega  2560  Rev3  necessary,  and  when  is  it  an  
unnecessary
 
expense?
 
The  Mega  2560  Rev3  runs  an  8-bit  ATmega2560  at  16  MHz  with  256  KB  Flash,  8  KB  SRAM,  
and
 
4
 
KB
 
EEPROM.
 
Its
 
value
 
lies
 
in
 
physical
 
pin
 
count:
 
54
 
digital
 
I/O
 
pins
 
(15
 
PWM
 
capable),
 
16
 
analog
 
inputs,
 
and
 
4
 
hardware
 
UART
 
ports.
 
It
 
is
 
necessary
 
for
 
multi-axis
 
CNC
 
machines
 
or
 
3D
 
printers
 
requiring
 
dozens
 
of
 
direct
 
digital
 
pins.
 
Spending
 
€40
 
on
 
a
 
Mega
 
is
 
wasted
 
if
 
pin
 
demand
 
is
 
low,
 
as
 
its
 
16
 
MHz
 
8-bit
 
core
 
lacks
 
floating-point
 
acceleration,
 
performing
 
far
 
slower
 
than
 
cheaper
 
32-bit
 
boards
 
like
 
the
 
Uno
 
R4
 
(€20)
 
or
 
RP2040
 
(€5).
 SOURCE:  https://docs.arduino.cc/resources/datasheets/A000067-datasheet.pdf  CONFIDENCE:  
SOLID
 
How  do  the  Nano  Every  and  Nano  ESP32  fit  compact  custom  builds?  
The  Nano  Every  uses  an  8-bit  ATmega4809  at  20  MHz  with  48  KB  Flash  and  6  KB  SRAM  in  a  
45x18mm
 
footprint,
 
providing
 
5V
 
logic
 
compatibility
 
at
 
€10.
 
The
 
Nano
 
ESP32
 
integrates
 
an
 
ESP32-S3
 
dual-core
 
32-bit
 
Xtensa
 
LX7
 
processor
 
at
 
240
 
MHz,
 
featuring
 
16
 
MB
 
Flash,
 
512
 
KB
 
SRAM,
 
8
 
MB
 
PSRAM,
 
Wi-Fi,
 
and
 
Bluetooth
 
5.0
 
at
 
3.3V
 
logic.
 
Choosing
 
between
 
them
 
depends
 
on
 
logic
 
level:
 
5V
 
sensor
 
setups
 
favor
 
the
 
Nano
 
Every,
 
whereas
 
wireless
 
connectivity,
 
high
 
processing
 
speed,
 
and
 
complex
 
kinematics
 
require
 
the
 
Nano
 
ESP32.
 SOURCE:  https://docs.arduino.cc/tutorials/nano-esp32/cheat-sheet/  CONFIDENCE:  SOLID  
How  does  the  Raspberry  Pi  RP2040  compare  for  real-time  motion  
control?  
The  RP2040  is  a  32-bit  dual-core  Arm  Cortex-M0+  microcontroller  running  at  133  MHz  with  264  
KB
 
SRAM
 
and
 
external
 
QSPI
 
flash.
 
Operating
 
at
 
3.3V
 
logic,
 
its
 
key
 
strength
 
for
 
motion
 
control
 
is
 
its
 
eight
 
Programmable
 
I/O
 
(PIO)
 
state
 
machines.
 
These
 
hardware-timed
 
state
 
machines
 
execute
 
deterministically
 
at
 
clock
 
speed,
 
offloading
 
quadrature
 
encoding,
 
step/dir
 
pulse
 
generation,
 
and
 
custom
 
protocols
 
from
 
the
 
CPU.
 
Priced
 
under
 
€1
 
for
 
silicon
 
or
 
~€5
 
on
 
boards,
 
the
 
RP2040
 
outperforms
 
8-bit
 
AVRs
 
in
 
timing
 
accuracy.
 
However,
 
interfacing
 
with
 
5V
 
sensors
 
or
 
drivers
 
requires
 
external
 
level
 
shifters
 
to
 
protect
 
GPIOs
 
from
 
voltages
 
above
 
3.3V.
 SOURCE:  https://nl.wikipedia.org/wiki/RP2040  CONFIDENCE:  SOLID  
When  is  paying  extra  for  high-end  32-bit  boards  like  the  GIGA  R1  WiFi  
justified?
 
The  Arduino  GIGA  R1  WiFi  features  a  dual-core  STM32H747XI  (Cortex-M7  at  480  MHz  and  
Cortex-M4
 
at
 
240
 
MHz)
 
with
 
2
 
MB
 
Flash
 
and
 
1
 
MB
 
SRAM,
 
providing
 
76
 
digital
 
I/O
 
pins
 
in
 
a
 
Mega
 
form
 
factor.
 
At
 
€75,
 
this
 
cost
 
is
 
justified
 
when
 
projects
 
require
 
simultaneous
 
multi-axis
 
motor
 
control,
 
edge
 
machine
 
learning,
 
high-resolution
 
display
 
output,
 
and
 
dual-band
 
Wi-Fi/Bluetooth
 
gateway
 
capabilities.
 
For
 
basic
 
motion
 
control
 
or
 
sensor
 
logging,
 
purchasing
 
a
 
GIGA
 
R1
 
is
 
wasted
 
capital.
 
A
 
€20
 
Uno
 
R4
 
Minima
 
or
 
€10
 
Nano
 
ESP32
 
provides
 
sufficient
 
processing
 
power
 
for
 
standard
 
robotic
 
tasks.
 SOURCE:  https://docs.arduino.cc/resources/datasheets/ABX00063-datasheet.pdf  
CONFIDENCE:
 
SOLID
 
Section  B:  Getting  Signals  In  
What  is  the  precise  electrical  behavior  and  value  range  of  Arduino  
internal
 
pull-up
 
resistors?
 
On  ATmega328P  8-bit  AVR  boards,  internal  pull-up  resistors  are  enabled  via  software  
(INPUT_PULLUP)
 
by
 
connecting
 
an
 
internal
 
resistor
 
between
 
the
 
GPIO
 
pin
 
and
 
V_{CC}.
 
Datasheet
 
specs
 
define
 
this
 
internal
 
resistance
 
between
 
20
 
k
Ω
 
and
 
50
 
k
Ω,
 
with
 
35
 
k
Ω
 
as
 
a
 
typical
 
nominal
 
value.
 
On
 
a
 
5V
 
supply,
 
the
 
resistor
 
sources
 
100
 
µA
 
to
 
250
 
µA
 
when
 
pulled
 
to
 
GND.
 
This
 
weak
 
pull-up
 
holds
 
an
 
idle
 
input
 
HIGH,
 
preventing
 
floating
 
states
 
during
 
open
 
switch
 
conditions.
 
High-noise
 
industrial
 
environments
 
or
 
wire
 
runs
 
over
 
1
 
meter
 
require
 
lower
 
external
 
pull-ups
 
(1
 
k
Ω
 
to
 
4.7
 
k
Ω)
 
to
 
prevent
 
electromagnetic
 
interference.
 SOURCE:  
https://hackingmajenkoblog.wordpress.com/2016/08/12/measuring-arduino-internal-pull-up-resis
tors/
 
CONFIDENCE:
 
SOLID
 
What  happens  to  floating  input  pins  and  how  do  pull  resistors  
stabilize
 
them?
 
An  un-terminated  input  pin  operates  in  a  high-impedance  state  (>100  M Ω  input  impedance),  
making
 
it
 
sensitive
 
to
 
ambient
 
electrostatic
 
fields.
 
Floating
 
pins
 
randomly
 
flip
 
between
 
logic
 
LOW
 
(0V)
 
and
 
HIGH
 
(5V/3.3V),
 
generating
 
false
 
triggers.
 
A
 
10
 
k
Ω
 
pull-up
 
resistor
 
to
 
V_{CC}
 
holds
 
the
 
pin  at  a  stable  HIGH  state  when  a  switch  is  open,  drawing  negligible  current.  Closing  the  switch  
to
 
GND
 
pulls
 
the
 
pin
 
cleanly
 
to
 
0V
 
while
 
drawing
 
0.5
 
mA
 
at
 
5V.
 
Conversely,
 
a
 
10
 
k
Ω
 
pull-down
 
resistor
 
to
 
GND
 
holds
 
the
 
pin
 
LOW
 
until
 
switched
 
to
 
V_{CC}.
 SOURCE:  
https://electronics.stackexchange.com/questions/263291/understanding-microcontroller-adc-inp
ut-pins-atmega328
 
CONFIDENCE:
 
COMMON
 
How  do  ADC  resolution  and  reference  voltages  affect  analog  sensor  
measurement
 
precision?
 
On  8-bit  AVR  Arduinos,  the  10-bit  ADC  divides  the  reference  voltage  (V_{REF})  into  2^{10}  =  
1024
 
steps
 
(0–1023),
 
yielding
 
4.88
 
mV
 
per
 
step
 
at
 
5V.
 
Unstable
 
power
 
supplies
 
cause
 
voltage
 
fluctuations
 
that
 
degrade
 
reading
 
accuracy.
 
Selecting
 
the
 
internal
 
1.1V
 
reference
 
increases
 
resolution
 
to
 
1.07
 
mV
 
per
 
step
 
for
 
small
 
signal
 
inputs.
 
The
 
32-bit
 
Uno
 
R4
 
Minima
 
features
 
up
 
to
 
14-bit
 
ADC
 
resolution
 
(2^{14}
 
=
 
16384
 
steps),
 
achieving
 
0.305
 
mV
 
resolution
 
across
 
a
 
5V
 
range.
 
Higher
 
ADC
 
resolution
 
minimizes
 
quantization
 
error,
 
enabling
 
precise
 
measurement
 
of
 
analog
 
sensors
 
across
 
mechanical
 
assemblies.
 SOURCE:  https://docs.arduino.cc/tutorials/uno-r4-minima/adc-resolution  CONFIDENCE:  SOLID  
What  causes  mechanical  switch  contact  bounce  and  how  is  it  
suppressed?
 
When  mechanical  contacts  in  switches  or  limit  sensors  close,  physical  spring  tension  causes  
them
 
to
 
bounce
 
repeatedly
 
for
 
1
 
ms
 
to
 
50
 
ms
 
before
 
making
 
clean
 
contact.
 
Microcontrollers
 
running
 
at
 
16
 
MHz
 
register
 
these
 
bounces
 
as
 
multiple
 
distinct
 
button
 
presses.
 
Hardware
 
debouncing
 
suppresses
 
noise
 
using
 
an
 
RC
 
low-pass
 
filter
 
(10
 
k
Ω
 
resistor
 
and
 
100
 
nF
 
capacitor,
 
giving
 
a
 
1
 
ms
 
time
 
constant)
 
paired
 
with
 
a
 
Schmitt
 
trigger
 
buffer.
 
Software
 
debouncing
 
works
 
non-blockingly
 
by
 
recording
 
millis()
 
timestamps
 
and
 
verifying
 
that
 
an
 
input
 
state
 
remains
 
unchanged
 
for
 
a
 
set
 
interval
 
(typically
 
10
 
ms
 
to
 
20
 
ms)
 
before
 
confirming
 
a
 
valid
 
state
 
change.
 SOURCE:  https://www.bettlink.com/blog/atmega328p-microcontroller-guide  CONFIDENCE:  
COMMON
 
How  do  digital  sensor  protocols  compare  to  analog  inputs  regarding  
noise
 
and
 
pin
 
use?
 
Analog  sensors  transmit  variable  voltages  (0–5V)  proportional  to  physical  measurements,  
making
 
signals
 
susceptible
 
to
 
voltage
 
drops
 
and
 
electromagnetic
 
noise
 
across
 
wire
 
lengths
 
exceeding
 
0.5
 
meters.
 
Each
 
analog
 
sensor
 
requires
 
a
 
dedicated
 
ADC
 
pin.
 
Digital
 
sensors
 
convert
 
measurements
 
into
 
data
 
packets
 
onboard,
 
transmitting
 
values
 
over
 
shared
 
buses
 
like
 
I2C
 
or
 
SPI.
 
Digital
 
protocols
 
maintain
 
high
 
noise
 
immunity
 
over
 
longer
 
wire
 
runs
 
and
 
allow
 
dozens
 
of
 
sensors
 
to
 
share
 
two
 
or
 
three
 
bus
 
lines.
 
However,
 
digital
 
sensors
 
require
 
protocol
 
communication
 
handling
 
in
 
firmware
 
compared
 
to
 
simple
 
analogRead()
 
sampling.
 SOURCE:  
https://docs.arduino.cc/language-reference/fun%C3%A7%C3%B5es/communication/wire/
 
CONFIDENCE:
 
SOLID
 
Section  C:  Getting  Things  to  Move  
What  are  the  electrical  and  thermal  limits  of  driving  MG996R  servos  
from
 
microcontroller
 
rails?
 
An  MG996R  servo  operates  at  4.8V  to  7.2V,  drawing  100  mA  to  250  mA  idle,  but  demanding  up  
to
 
2.5A
 
peak
 
stall
 
current
 
at
 
6V
 
under
 
heavy
 
load.
 
Powering
 
MG996R
 
servos
 
from
 
an
 
Arduino's
 
5V
 
pin
 
or
 
USB
 
rail
 
causes
 
voltage
 
sags
 
that
 
trigger
 
brown-out
 
resets
 
on
 
ATmega328P
 
(BOD
 
threshold
 
2.7V/4.3V)
 
or
 
damage
 
the
 
voltage
 
regulator.
 
A
 
6-DOF
 
robot
 
arm
 
with
 
six
 
MG996R
 
servos
 
requires
 
a
 
dedicated
 
6V,
 
10A–15A
 
external
 
power
 
supply.
 
Common
 
ground
 
wires
 
between
 
the
 
supply,
 
servos,
 
and
 
microcontroller
 
must
 
be
 
tied
 
together
 
to
 
ensure
 
proper
 
signal
 
transmission.
 SOURCE:  https://docs.arduino.cc/tutorials/uno-r4-minima/cheat-sheet  CONFIDENCE:  SOLID  
Why  is  the  legacy  L298N  motor  driver  obsolete  compared  to  modern  
drivers?
 
The  L298N  is  a  dual  full-bridge  driver  based  on  bipolar  junction  transistors  (BJTs),  rated  up  to  
46V
 
and
 
2A
 
per
 
channel.
 
Due
 
to
 
internal
 
BJT
 
saturation
 
losses,
 
the
 
L298N
 
drops
 
2V
 
to
 
4.9V,
 
generating
 
significant
 
heat
 
and
 
requiring
 
large
 
aluminum
 
heatsinks.
 
Modern
 
drivers
 
like
 
the
 
A4988
 
or
 
TMC2209
 
use
 
low
 
R_{DS(on)}
 
MOSFETs,
 
reducing
 
conduction
 
losses
 
substantially.
 
Additionally,
 
the
 
L298N
 
lacks
 
active
 
current
 
chopping
 
or
 
microstepping,
 
whereas
 
modern
 
drivers
 
provide
 
active
 
PWM
 
current
 
regulation
 
and
 
microstepping
 
up
 
to
 
1/256,
 
enabling
 
cooler
 
operation,
 
silent
 
stepper
 
movement,
 
and
 
higher
 
positioning
 
accuracy.
 SOURCE:  
https://www.st.com/resource/en/application_note/an240-applications-of-monolithic-bridge-driver
s-stmicroelectronics.pdf
 
CONFIDENCE:
 
SOLID
 
How  do  A4988  and  TMC2209  stepper  driver  ICs  control  current  and  
microstepping?
 
The  A4988  operates  from  8V  to  35V  at  up  to  2A,  providing  hardware  microstepping  down  to  
1/16
 
step
 
via
 
MS1–MS3
 
pins.
 
Current
 
limits
 
are
 
set
 
manually
 
by
 
measuring
 
reference
 
voltage
 
(V_{REF})
 
on
 
an
 
adjustable
 
potentiometer.
 
The
 
Trinamic
 
TMC2209
 
operates
 
from
 
4.8V
 
to
 
29V,
 
delivering
 
2A
 
RMS
 
(2.8A
 
peak).
 
It
 
features
 
StealthChop2
 
silent
 
PWM
 
chopping,
 
SpreadCycle
 
dynamic
 
current
 
control,
 
StallGuard4
 
sensorless
 
homing,
 
and
 
UART
 
control
 
for
 
microstepping
 
up
 
to
 
1/256
 
interpolation.
 
The
 
TMC2209
 
eliminates
 
motor
 
hum,
 
reduces
 
mechanical
 
vibration
 
on
 
CNC
 
axes,
 
and
 
prevents
 
thermal
 
shutdown
 
during
 
high-speed
 
movement.
 SOURCE:  https://www.trinamic.com/products/integrated-circuits/details/tmc2209-la/  
CONFIDENCE:
 
SOLID
 
How  do  inductive  back-EMF  spikes  damage  microcontrollers  and  how  
is
 
protection
 
implemented?
 
Inductive  loads  (DC  motors,  steppers,  relays)  store  energy  in  magnetic  fields  (E  =  \frac{1}{2}  L  
I^2).
 
When
 
current
 
flow
 
is
 
stopped,
 
the
 
field
 
collapses,
 
producing
 
a
 
voltage
 
spike
 
(V
 
=
 
-L
 
\frac{di}{dt})  that  can  reach  hundreds  of  volts.  These  negative  back-EMF  spikes  exceed  silicon  
limits
 
(-0.5V
 
to
 
6.5V)
 
and
 
damage
 
GPIO
 
pins
 
or
 
MOSFET
 
gate
 
oxide.
 
Protection
 
requires
 
installing
 
a
 
fast
 
Schottky
 
flyback
 
diode
 
across
 
the
 
load
 
(cathode
 
to
 
positive
 
supply)
 
to
 
dissipate
 
reverse
 
current
 
safely
 
through
 
the
 
coil
 
loop.
 
Decoupling
 
capacitors
 
(100
 
nF
 
ceramic
 
and
 
100
 
µF
 
electrolytic)
 
filter
 
power
 
rail
 
ripple.
 SOURCE:  https://www.bettlink.com/blog/atmega328p-microcontroller-guide  CONFIDENCE:  
SOLID
 
What  are  the  current  drive  limits  of  Arduino  GPIO  pins  when  
controlling
 
external
 
switches?
 
On  ATmega328P  8-bit  AVR  boards,  maximum  DC  source  or  sink  current  per  GPIO  pin  is  40  mA,  
with
 
a
 
total
 
chip
 
supply
 
limit
 
across
 
V_{CC}/GND
 
pins
 
of
 
200
 
mA.
 
On
 
32-bit
 
boards
 
like
 
the
 
Uno
 
R4
 
Minima
 
(RA4M1),
 
GPIO
 
output
 
current
 
is
 
capped
 
at
 
8
 
mA
 
per
 
pin.
 
Exceeding
 
these
 
current
 
limits
 
causes
 
thermal
 
overstress
 
and
 
permanent
 
output
 
driver
 
silicon
 
failure.
 
Microcontrollers
 
should
 
not
 
power
 
high-current
 
loads
 
directly.
 
Driving
 
external
 
MOSFETs
 
or
 
relays
 
requires
 
a
 
220
 
Ω
 
series
 
gate
 
resistor
 
to
 
limit
 
transient
 
charging
 
current,
 
plus
 
a
 
10
 
k
Ω
 
pull-down
 
resistor
 
to
 
ensure
 
clean
 
OFF
 
states
 
during
 
boot.
 SOURCE:  https://docs.arduino.cc/resources/datasheets/ABX00080-datasheet.pdf  
CONFIDENCE:
 
SOLID
 
Section  D:  Beyond  the  Basic  Loop  
Why  does  delay()  paralyze  execution  and  how  does  millis()  enable  
non-blocking
 
multitasking?
 
Calling  delay(1000)  pauses  execution  by  spinning  the  CPU  in  a  loop  for  1000  ms,  leaving  the  
microcontroller
 
unable
 
to
 
process
 
sensors,
 
serial
 
inputs,
 
or
 
motor
 
timing.
 
In
 
contrast,
 
millis()
 
queries
 
internal
 
hardware
 
Timer0,
 
which
 
increments
 
every
 
1
 
ms
 
and
 
overflows
 
after
 
~49.7
 
days
 
(2^{32}-1
 
ms).
 
Non-blocking
 
execution
 
tracks
 
past
 
timestamps
 
and
 
evaluates
 
elapsed
 
time
 
(if
 
(currentMillis
 
-
 
previousMillis
 
>=
 
interval)).
 
This
 
allows
 
the
 
processor
 
to
 
execute
 
multiple
 
tasks
 
concurrently
 
across
 
loop
 
iterations
 
without
 
stalling
 
main
 
control
 
logic.
 SOURCE:  https://www.ultralibrarian.com/2026/04/21/atmega328p-microcontroller-ulc  
CONFIDENCE:
 
SOLID
 
When  should  hardware  interrupts  be  used  and  what  are  their  
execution
 
rules?
 
Hardware  interrupts  (attachInterrupt())  instantly  pause  main  loop  execution  to  process  urgent  
external
 
signals
 
on
 
dedicated
 
pins
 
(such
 
as
 
INT0/INT1
 
on
 
ATmega328P
 
pins
 
D2/D3)
 
within
 
microseconds.
 
Interrupt
 
Service
 
Routines
 
(ISRs)
 
must
 
run
 
quickly
 
(under
 
10
 
microseconds)
 
and
 
avoid
 
using
 
delay()
 
or
 
Serial.print(),
 
because
 
timer
 
interrupts
 
are
 
paused
 
during
 
execution.
 
Variables
 
modified
 
within
 
an
 
ISR
 
and
 
accessed
 
in
 
the
 
main
 
loop
 
must
 
be
 
marked
 
volatile
 
to
 
prevent
 
compiler
 
register
 
caching.
 
Interrupts
 
are
 
required
 
for
 
quadrature
 
encoder
 
pulse
 
counting,
 
limit
 
switches,
 
and
 
zero-crossing
 
detection.
 SOURCE:  https://docs.arduino.cc/retired/boards/arduino-mega-adk-rev3/  CONFIDENCE:  
SOLID  
How  do  finite  state  machines  structure  complex  automation  logic  
cleanly?
 
A  Finite  State  Machine  (FSM)  structures  machine  operations  into  discrete  states  (such  as  IDLE,  
HOMING,
 
RUNNING,
 
ERROR)
 
defined
 
using
 
enumerated
 
types
 
(enum).
 
Instead
 
of
 
complex
 
nested
 
if-else
 
blocks
 
or
 
blocking
 
delays,
 
an
 
FSM
 
uses
 
a
 
switch-case
 
statement
 
inside
 
loop().
 
Transitions
 
between
 
states
 
occur
 
non-blockingly
 
when
 
sensor
 
inputs
 
or
 
millis()
 
timer
 
thresholds
 
are
 
satisfied.
 
This
 
structure
 
ensures
 
predictable
 
machine
 
operation,
 
simplifies
 
debugging,
 
prevents
 
invalid
 
state
 
transitions
 
in
 
multi-axis
 
setups,
 
and
 
keeps
 
the
 
controller
 
responsive
 
to
 
emergency
 
stops
 
or
 
serial
 
commands
 
at
 
all
 
times.
 SOURCE:  https://forum.arduino.cc/t/atmega328-board-programming-issue/322530  
CONFIDENCE:
 
COMMON
 
How  does  the  hardware  Watchdog  Timer  prevent  system  lockups?  
The  Watchdog  Timer  (WDT)  is  an  independent  hardware  RC  oscillator  timer  that  operates  
separately
 
from
 
the
 
main
 
system
 
clock.
 
Once
 
configured,
 
the
 
WDT
 
counts
 
down
 
from
 
a
 
set
 
timeout
 
period
 
(15
 
ms
 
to
 
8
 
seconds).
 
Software
 
must
 
periodically
 
execute
 
a
 
reset
 
command
 
(wdt_reset())
 
inside
 
execution
 
loops.
 
If
 
a
 
crash,
 
infinite
 
loop,
 
or
 
EMI
 
spike
 
halts
 
CPU
 
execution,
 
the
 
watchdog
 
timer
 
expires
 
and
 
initiates
 
a
 
full
 
hardware
 
system
 
reset.
 
This
 
automatic
 
recovery
 
mechanism
 
restores
 
unattended
 
robotic
 
arms,
 
CNC
 
controllers,
 
or
 
remote
 
sensors
 
without
 
requiring
 
manual
 
power
 
cycling.
 SOURCE:  https://docs.arduino.cc/resources/datasheets/ABX00028-datasheet.pdf  
CONFIDENCE:
 
SOLID
 
How  is  internal  EEPROM  used  for  persistent  settings  without  wearing  
out
 
flash
 
memory?
 
Internal  EEPROM  retains  configuration  data  (calibration  parameters,  step  counts,  network  
settings)
 
across
 
power
 
cycles.
 
The
 
ATmega328P
 
includes
 
1
 
KB,
 
the
 
ATmega2560
 
has
 
4
 
KB,
 
and
 
the
 
RA4M1
 
provides
 
8
 
KB
 
of
 
data
 
flash
 
EEPROM.
 
EEPROM
 
cells
 
are
 
rated
 
for
 
100,000
 
write/erase
 
cycles.
 
Writing
 
to
 
EEPROM
 
continuously
 
inside
 
loop()
 
degrades
 
cells
 
within
 
minutes.
 
Software
 
should
 
use
 
EEPROM.update(address,
 
value)
 
instead
 
of
 
EEPROM.write().
 
The
 
update()
 
method
 
reads
 
the
 
cell
 
first
 
and
 
writes
 
only
 
if
 
the
 
value
 
has
 
changed,
 
extending
 
EEPROM
 
operational
 
lifespan.
 SOURCE:  
https://static6.arrow.com/aropdfconversion/65d19a89a4a2dbc52152b0afb98c31e87906937c/13
atmega328_p20avr20mcu20with20picopower20technology20data20sheet20.pdf
 
CONFIDENCE:
 
SOLID
 
Section  E:  Talking  to  Other  Things  
How  does  Hardware  UART  Serial  differ  from  SoftwareSerial  in  speed  
and  performance?  
Universal  Asynchronous  Receiver-Transmitter  (UART)  hardware  manages  asynchronous  serial  
communication
 
using
 
dedicated
 
silicon
 
registers
 
(pins
 
D0/D1
 
on
 
Uno
 
R3;
 
4
 
UARTs
 
on
 
Mega
 
2560).
 
Hardware
 
UART
 
operates
 
reliably
 
up
 
to
 
2
 
Mbps
 
without
 
CPU
 
overhead.
 
Conversely,
 
SoftwareSerial
 
bit-bangs
 
serial
 
timings
 
in
 
software
 
using
 
CPU
 
interrupts,
 
consuming
 
clock
 
cycles
 
and
 
becoming
 
unreliable
 
above
 
38,400
 
bps.
 
Additionally,
 
SoftwareSerial
 
cannot
 
transmit
 
and
 
receive
 
simultaneously
 
without
 
dropping
 
data.
 
Boards
 
with
 
multiple
 
hardware
 
UARTs
 
(Mega
 
2560,
 
Uno
 
R4,
 
Nano
 
ESP32)
 
eliminate
 
software
 
serial
 
overhead
 
entirely
 
when
 
connecting
 
motor
 
controllers
 
or
 
sensors.
 SOURCE:  https://docs.arduino.cc/hardware/mega-2560/  CONFIDENCE:  SOLID  
How  does  the  I2C  bus  operate  and  what  are  its  pull-up  and  addressing  
limits?
 
Inter-Integrated  Circuit  (I2C/TWI)  uses  two  bidirectional  open-drain  lines:  Serial  Data  (SDA)  and  
Serial
 
Clock
 
(SCL).
 
Operating
 
as
 
a
 
master-slave
 
bus
 
at
 
standard
 
(100
 
kHz)
 
or
 
fast
 
(400
 
kHz)
 
speeds,
 
7-bit
 
addressing
 
supports
 
up
 
to
 
127
 
devices
 
on
 
a
 
single
 
bus
 
(addresses
 
0–7
 
reserved).
 
Because
 
I2C
 
drivers
 
only
 
pull
 
lines
 
LOW,
 
external
 
pull-up
 
resistors
 
(2.2
 
k
Ω
 
to
 
10
 
k
Ω
 
connected
 
to
 
V_{CC})
 
are
 
required
 
to
 
pull
 
lines
 
HIGH.
 
Bus
 
capacitance
 
across
 
cables
 
longer
 
than
 
0.5
 
meters
 
distorts
 
signals,
 
causing
 
communication
 
errors.
 
Standard
 
Wire
 
library
 
implementations
 
allocate
 
a
 
32-byte
 
internal
 
buffer,
 
limiting
 
transmission
 
size.
 SOURCE:  
https://docs.arduino.cc/language-reference/fun%C3%A7%C3%B5es/communication/wire/
 
CONFIDENCE:
 
SOLID
 
Why  is  SPI  the  preferred  bus  for  high-speed  displays  and  SD  card  
storage?
 
Serial  Peripheral  Interface  (SPI)  is  a  synchronous,  four-wire  protocol  using  MOSI,  MISO,  SCK,  
and
 
CS
 
lines.
 
Unlike
 
I2C,
 
SPI
 
uses
 
push-pull
 
CMOS
 
drivers
 
rather
 
than
 
open-drain
 
lines,
 
eliminating
 
pull-up
 
delays
 
and
 
supporting
 
clock
 
speeds
 
beyond
 
8
 
MHz
 
to
 
20
 
MHz
 
on
 
16
 
MHz
 
AVRs.
 
Dedicated
 
Chip
 
Select
 
(CS)
 
lines
 
enable
 
instant
 
hardware
 
device
 
selection
 
without
 
address
 
parsing
 
overhead.
 
These
 
higher
 
clock
 
speeds
 
and
 
continuous
 
data
 
streaming
 
capabilities
 
make
 
SPI
 
the
 
standard
 
choice
 
for
 
driving
 
high-resolution
 
TFT
 
graphic
 
displays,
 
reading
 
SD
 
cards,
 
and
 
sampling
 
high-speed
 
multi-channel
 
ADCs.
 SOURCE:  
https://www.wevolver.com/article/atmega328p-pinout-registers-fuses-and-arduino-pin-mapping
 
CONFIDENCE:
 
SOLID
 
How  does  CAN  bus  facilitate  robust  communication  in  industrial  and  
robotic
 
systems?
 
Controller  Area  Network  (CAN  2.0A/B)  is  a  differential  two-wire  (CAN  High,  CAN  Low)  
multi-master
 
bus
 
designed
 
for
 
harsh
 
industrial
 
environments.
 
Featuring
 
built-in
 
message
 
prioritization,
 
bitwise
 
arbitration,
 
hardware
 
noise
 
immunity,
 
and
 
error
 
detection,
 
CAN
 
operates
 
at
 
speeds
 
up
 
to
 
1
 
Mbps.
 
The
 
Renesas
 
RA4M1
 
MCU
 
on
 
the
 
Uno
 
R4
 
Minima
 
and
 
Nano
 
R4
 
includes
 
an  integrated  CAN  controller.  Physical  connection  to  a  CAN  network  requires  wiring  MCU  
CANRX/CANTX
 
pins
 
(pins
 
D5/D4
 
on
 
Uno
 
R4)
 
to
 
an
 
external
 
3.3V/5V
 
transceiver
 
IC
 
(such
 
as
 
SN65HVD230
 
or
 
MCP2551)
 
with
 
120
 
Ω
 
bus
 
termination
 
resistors.
 SOURCE:  https://docs.arduino.cc/tutorials/uno-r4-minima/can  CONFIDENCE:  SOLID  
How  should  3.3V  and  5V  logic  levels  be  interfaced  safely  across  
buses?
 
Connecting  a  5V  output  pin  directly  to  a  3.3V  microcontroller  GPIO  (e.g.,  ESP32,  RP2040)  
forces
 
current
 
through
 
internal
 
ESD
 
protection
 
diodes,
 
risking
 
permanent
 
silicon
 
damage.
 
Passive
 
voltage
 
dividers
 
using
 
resistor
 
pairs
 
(e.g.,
 
1
 
k
Ω
 
and
 
2
 
k
Ω)
 
safely
 
step
 
5V
 
signals
 
down
 
to
 
3.3V
 
on
 
unidirectional
 
serial
 
lines.
 
However,
 
bidirectional
 
open-drain
 
buses
 
like
 
I2C
 
require
 
active
 
level
 
shifters
 
using
 
N-channel
 
MOSFETs
 
(such
 
as
 
BSS138)
 
with
 
pull-up
 
resistors
 
on
 
both
 
3.3V
 
and
 
5V
 
rails.
 
Dedicated
 
level-shifter
 
ICs
 
(e.g.,
 
74LVC245
 
or
 
TXS0108E)
 
ensure
 
clean
 
level
 
conversion
 
and
 
noise
 
immunity
 
across
 
mixed-voltage
 
systems.
 SOURCE:  https://www.bettlink.com/blog/esp32-wroom-32-guide  CONFIDENCE:  SOLID  
Myths  and  Outdated  Advice  
Myth  1:  Arduino  GPIO  pins  can  power  small  5V  motors,  relays,  or  
servos
 
directly
 
A  common  misconception  is  that  Arduino  digital  output  pins  can  directly  supply  power  to  small  
motors
 
or
 
actuators.
 
In
 
reality,
 
Arduino
 
GPIO
 
pins
 
are
 
logic
 
signal
 
lines,
 
not
 
power
 
sources.
 
On
 
ATmega328P
 
boards,
 
the
 
maximum
 
absolute
 
current
 
limit
 
per
 
GPIO
 
pin
 
is
 
40
 
mA
 
(with
 
a
 
total
 
chip
 
limit
 
of
 
200
 
mA
 
across
 
all
 
pins),
 
while
 
32-bit
 
boards
 
like
 
the
 
Uno
 
R4
 
are
 
limited
 
to
 
8
 
mA
 
per
 
pin.
 
Servos
 
and
 
relays
 
demand
 
startup
 
currents
 
ranging
 
from
 
250
 
mA
 
to
 
over
 
2A.
 
Powering
 
them
 
directly
 
from
 
GPIO
 
pins
 
triggers
 
voltage
 
brown-outs
 
or
 
permanently
 
damages
 
the
 
microcontroller
 
output
 
silicon.
 
External
 
power
 
MOSFETs,
 
relays,
 
or
 
driver
 
circuits
 
powered
 
by
 
separate
 
power
 
supplies
 
must
 
always
 
be
 
used.
 
Myth  2:  The  analogRead()  function  provides  exact  absolute  voltage  
readings
 
without
 
calibration
 
It  is  often  assumed  that  an  analogRead()  value  of  512  on  a  10-bit  board  corresponds  exactly  to  
2.50V.
 
However,
 
a[span_57](start_span)[span_57](end_span)nalogRead()
 
measures
 
voltage
 
relative
 
to
 
the
 
analog
 
reference
 
voltage
 
rail
 
(V_{REF}).
 
By
 
default,
 
V_{REF}
 
uses
 
the
 
5V
 
supply
 
line,
 
which
 
fluctuates
 
between
 
4.5V
 
and
 
5.2V
 
depending
 
on
 
USB
 
power
 
delivery
 
and
 
current
 
draw
 
from
 
connected
 
peripherals.
 
A
 
10-bit
 
reading
 
of
 
512
 
against
 
an
 
uncalibrated
 
4.6V
 
supply
 
equals
 
2.30V,
 
resulting
 
in
 
a
 
200
 
mV
 
measurement
 
error.
 
Precise
 
measurements
 
require
 
using
 
stable
 
internal
 
voltage
 
references
 
(such
 
as
 
the
 
1.1V
 
internal
 
reference
 
on
 
ATmega328P)
 
or
 
providing
 
a
 
precise
 
external
 
voltage
 
reference
 
to
 
AREF.
 
Myth  3:  The  Arduino  Uno  form  factor  is  strictly  an  8-bit  AVR  hardware  
platform
 
A  widespread  belief  is  that  choosing  an  Arduino  Uno  limits  projects  to  an  8-bit  ATmega328P  
processor
 
running
 
at
 
16
 
MHz
 
with
 
2
 
KB
 
of
 
SRAM.
 
While
 
this
 
applied
 
to
 
older
 
Uno
 
revisions
 
(R1–R3),
 
the
 
official
 
Uno
 
R4
 
Minima
 
and
 
Uno
 
R4
 
WiFi
 
feature
 
a
 
32-bit
 
Renesas
 
RA4M1
 
Arm
 
Cortex-M4
 
microcontroller
 
running
 
at
 
48
 
MHz.
 
The
 
R4
 
retains
 
5V
 
logic
 
and
 
shield
 
compatibility
 
while
 
increasing
 
memory
 
to
 
32
 
KB
 
SRAM
 
and
 
256
 
KB
 
Flash,
 
adding
 
a
 
12-bit
 
DAC,
 
14-bit
 
ADC,
 
CAN
 
bus
 
support,
 
and
 
USB
 
HID
 
functionality.
 
Myth  4:  Hardware  interrupts  are  the  best  mechanism  for  debouncing  
pushbuttons
 
and
 
limit
 
switches
 
Beginners  frequently  attach  hardware  interrupts  (attachInterrupt())  to  limit  switches  or  
pushbuttons
 
believing
 
it
 
guarantees
 
clean
 
signal
 
detection.
 
Mechanical
 
switch
 
contacts
 
bounce
 
rapidly
 
upon
 
opening
 
or
 
closing,
 
generating
 
dozens
 
of
 
edge
 
triggers
 
within
 
milliseconds.
 
When
 
attached
 
to
 
an
 
interrupt,
 
this
 
forces
 
the
 
CPU
 
into
 
repeated
 
execution
 
calls,
 
starving
 
the
 
main
 
loop
 
and
 
causing
 
counter
 
errors.
 
Mechanical
 
inputs
 
should
 
be
 
sampled
 
non-blockingly
 
using
 
millis()
 
state
 
checks
 
in
 
the
 
main
 
loop
 
or
 
debounced
 
electrically
 
using
 
an
 
RC
 
low-pass
 
filter
 
(10
 
k
Ω
 
resistor
 
and
 
100
 
nF
 
capacitor)
 
before
 
reaching
 
the
 
pin.
 
Myth  5:  EEPROM  can  be  written  continuously  inside  loop()  without  
hardware
 
degradation
 
A  common  programming  error  is  writing  persistent  variables  to  EEPROM  inside  every  iteration  
of
 
loop().
 
Microcontroller
 
internal
 
EEPROM
 
cells
 
have
 
a
 
hardware
 
endurance
 
limit
 
rated
 
for
 
approximately
 
100,000
 
write/erase
 
cycles.
 
A
 
fast-executing
 
loo[span_11](start_span)[span_11](end_span)[span_13](start_span)[span_13](end_span)[span_
15](start_span)[span_15](end_span)[span_17](start_span)[span_17](end_span)p()
 
writing
 
data
 
thousands
 
of
 
times
 
per
 
second
 
permanently
 
degrades
 
EEPROM
 
memory
 
cells
 
within
 
minutes.
 
Non-volatile
 
memory
 
should
 
only
 
be
 
written
 
during
 
explicit
 
user
 
saving
 
actions
 
or
 
updated
 
using
 
EEPROM.update(),
 
which
 
checks
 
the
 
existing
 
cell
 
byte
 
first
 
and
 
performs
 
a
 
write
 
operation
 
only
 
if
 
the
 
stored
 
value
 
has
 
actually
 
changed.
 
Myth  6:  Floating-point  math  executes  efficiently  on  classic  8-bit  
Arduino
 
boards
 
Many  developers  assume  8-bit  Arduinos  perform  floating-point  math  (float/double)  as  efficiently  
as
 
integer
 
operations.
 
8-bit
 
AVR
 
microcontrollers
 
(ATmega328P,
 
ATmega2560)
 
lack
 
a
 
hardware
 
Floating-Point
 
Unit
 
(FPU).
 
Every
 
floating-point
 
operation
 
is
 
emulated
 
via
 
software
 
routines
 
consuming
 
hundreds
 
of
 
CPU
 
clock
 
cycles.
 
On
 
8-bit
 
boards,
 
fixed-point
 
integer
 
arithmetic
 
(e.g.,
 
calculating
 
values
 
in
 
millivolts
 
or
 
micrometers)
 
should
 
be
 
preferred.
 
High-throughput
 
floating-point
 
calculations
 
require
 
32-bit
 
processors
 
with
 
integrated
 
FPUs,
 
such
 
as
 
the
 
Renesas
 
RA4M1
 
on
 
the
 
Uno
 
R4.
 
Myth  7:  SoftwareSerial  is  required  whenever  an  Arduino  Mega  2560  
interfaces
 
with
 
secondary
 
serial
 
modules
 
A  frequent  mistake  on  the  Arduino  Mega  2560  is  using  SoftwareSerial  to  connect  additional  
serial
 
devices,
 
such
 
as
 
motor
 
drivers
 
or
 
telemetry
 
modules.
 
The
 
ATmega2560
 
integrates
 
four
 
hardware  UART  peripherals  (Serial[span_110](start_span)[span_110](end_span),  Serial1,  
Serial2,
 
Serial3[span_62](start_span)[span_62](end_span))
 
on
 
dedicated
 
pins
 
(D0/D1,
 
D18/D19,
 
D16/D17,
 
D14/D15).
 
SoftwareSerial
 
consumes
 
CPU
 
cycles
 
and
 
relies
 
on
 
software
 
timing,
 
leading
 
to
 
dropped
 
bytes
 
above
 
38,400
 
bps.
 
Using
 
hardware
 
UART
 
ports
 
on
 
the
 
Mega
 
2560
 
guarantees
 
high-speed
 
communication
 
up
 
to
 
2
 
Mbps
 
without
 
CPU
 
overhead.
 
Geciteerd  werk  
1.  ATmega328P  Microcontroller  Guide:  Pinout,  Datasheet,  Specs,  and  Applications  -  Bettlink,  
https://www.bettlink.com/blog/atmega328p-microcontroller-guide
 
2.
 
Arduino®
 
UNO
 
R4
 
Minima,
 
https://docs.arduino.cc/resources/datasheets/ABX00080-datasheet.pdf
 
3.
 
Arduino
 
UNO
 
R4
 
Minima
 
User
 
Manual,
 
https://docs.arduino.cc/tutorials/uno-r4-minima/cheat-sheet
 
4.
 
UNO
 
R4
 
Minima
 
-
 
Arduino
 
Documentation,
 
https://docs.arduino.cc/hardware/uno-r4-minima
 
5.
 
Arduino
 
UNO
 
R4
 
Minima
 
ADC
 
Resolution,
 
https://docs.arduino.cc/tutorials/uno-r4-minima/adc-resolution
 
6.
 
Arduino
 
UNO
 
R4
 
Minima
 
CAN
 
Bus,
 
https://docs.arduino.cc/tutorials/uno-r4-minima/can
 
7.
 
Arduino®
 
Mega
 
2560
 
Rev3
 
-
 
Description
 
Target
 
Areas,
 
https://docs.arduino.cc/resources/datasheets/A000067-datasheet.pdf
 
8.
 
Mega
 
2560
 
Rev3
 
|
 
Arduino
 
Documentation,
 
https://docs.arduino.cc/hardware/mega-2560/
 
9.
 
Nano
 
Every
 
|
 
Arduino
 
Documentation,
 
https://docs.arduino.cc/hardware/nano-every
 
10.
 
Arduino®
 
Nano
 
Every,
 
https://docs.arduino.cc/resources/datasheets/ABX00028-datasheet.pdf
 
11.
 
Arduino
 
Nano
 
ESP32
 
User
 
Manual,
 
https://docs.arduino.cc/tutorials/nano-esp32/cheat-sheet/
 
12.
 
Nano
 
ESP32
 
-
 
Arduino
 
Documentation,
 
https://docs.arduino.cc/nano-esp32
 
13.
 
ESP32-WROOM-32
 
Guide
 
|
 
Pinout,
 
Datasheet,
 
Arduino
 
...
 
-
 
Bettlink,
 
https://www.bettlink.com/blog/esp32-wroom-32-guide
 
14.
 
Arduino®
 
GIGA
 
R1
 
WiFi
 
-
 
Description
 
Target
 
Areas,
 
https://docs.arduino.cc/resources/datasheets/ABX00063-datasheet.pdf
 
15.
 
ATmega328/P,
 
https://static6.arrow.com/aropdfconversion/65d19a89a4a2dbc52152b0afb98c31e87906937c/13
atmega328_p20avr20mcu20with20picopower20technology20data20sheet20.pdf
 
16.
 
Measuring
 
Arduino
 
Internal
 
Pull-up
 
Resistors
 
|
 
Majenko's
 
Hardware
 
Hacking
 
Blog,
 
https://hackingmajenkoblog.wordpress.com/2016/08/12/measuring-arduino-internal-pull-up-resis
tors/
 
17.
 
Understanding
 
microcontroller
 
ADC
 
input
 
pins
 
(atmega328)
 
-
 
Electronics
 
Stack
 
Exchange,
 
https://electronics.stackexchange.com/questions/263291/understanding-microcontroller-adc-inp
ut-pins-atmega328
 
18.
 
ATMega328
 
board
 
programming
 
issue
 
-
 
General
 
Guidance
 
-
 
Arduino
 
Forum,
 
https://forum.arduino.cc/t/atmega328-board-programming-issue/322530
 
19.
 
ATmega328P
 
Microcontroller
 
Datasheet:
 
Explained
 
-
 
Ultra
 
Librarian,
 
https://www.ultralibrarian.com/2026/04/21/atmega328p-microcontroller-ulc
 
20.
 
Wire
 
|
 
Arduino
 
Documentation,
 
https://docs.arduino.cc/language-reference/fun%C3%A7%C3%B5es/communication/wire/
 
21.
 
Applications
 
of
 
monolithic
 
bridge
 
drivers,
 
https://www.st.com/resource/en/application_note/an240-applications-of-monolithic-bridge-driver
s-stmicroelectronics.pdf
 
22.
 
TMC2209
 
Datasheet
 
and
 
Product
 
Info
 
-
 
Analog
 
Devices,
 
https://www.trinamic.com/products/integrated-circuits/details/tmc2209-la/
 
23.
 
DMOS
 
Microstepping
 
Driver
 
with
 
Translator
 
and
 
Overcurrent
 
Protection
 
-
 
Allegro
 
MicroSystems,
 
https://www.allegromicro.com/-/media/files/datasheets/a5985-datasheet.pdf
 
24.
 
Arduino
 
Mega
 
ADK
 
Rev3,
 
https://docs.arduino.cc/retired/boards/arduino-mega-adk-rev3/
 
25.
 
Universal
 
Asynchronous
 
Receiver-Transmitter
 
(UART)
 
-
 
Arduino
 
Documentation,
 
https://docs.arduino.cc/learn/communication/uart/
 
26.
 
ATmega328P:
 
Pinout,
 
Registers,
 
Fuses,
 
and
 
Arduino
 
Pin
 
Mapping
 
-
 
Wevolver,
 
https://www.wevolver.com/article/atmega328p-pinout-registers-fuses-and-arduino-pin-mapping  
27.
 
8-bit
 
Microcontrollers
 
32-bit
 
Microcontrollers
 
and
 
Application
 
Processors
 
-
 
Nicer
 
Land,
 
https://ww1.microchip.com/downloads/en/DeviceDoc/doc4064.pdf
 
28.
 
Nano
 
R4
 
-
 
Arduino
 
Documentation,
 
https://docs.arduino.cc/hardware/nano-r4/
 