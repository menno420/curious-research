<!-- RAW RESEARCH — do not edit. Rewrite into Dutch cards in site/kennis.html instead. -->
> **Topic:** fusion360 · **Tool:** Gemini deep research · **Received:** 2026-08-07
> **Source:** the owner's Drive folder <https://drive.google.com/drive/folders/1Vg9HJxbKaBuv31Ovm4uSlIIMFyi7Yun3>
> Text extracted from the delivered PDF (`Fusion 360 Advanced Reference Dossier.pdf`, Drive id `1d5Qn07d-W4HbZbHyMvRzq7nyNbdKqtvD`); PDF layout means headings and tables may run together.
> Saved unedited, per `research/deep-research-prompts.md` § After the research comes back.

---

Fusion  360  Beyond  Everyday  Drawing:  
Parametric
 
Technique
 
and
 
Python
 
API
 
Reference
 Section  A:  Parametric  Modelling  Properly  
How  are  user  parameters  created  and  managed  in  Fusion?  
In  the  Design  workspace,  navigating  to  Design  >  Solid  >  Modify  >  Change  Parameters  (or  
pressing
 
S
 
and
 
searching
 
"parameters")
 
opens
 
the
 
parameters
 
dialog.
 
Clicking
 
Add
 
User
 
Parameter
 
(+
 
icon)
 
allows
 
defining
 
named
 
variables.
 
Each
 
parameter
 
requires
 
a
 
unique
 
Name,
 
Unit
 
(mm,
 
cm,
 
degree,
 
count,
 
Text),
 
and
 
Expression.
 
Parameters
 
can
 
be
 
referenced
 
in
 
feature
 
inputs
 
or
 
equations
 
using
 
arithmetic
 
operators
 
(+,
 
-,
 
*,
 
/,
 
^)
 
or
 
logical
 
functions
 
like
 
if(Condition;
 
TrueValue;
 
FalseValue).
 
Defining
 
parameters
 
on
 
the
 
fly
 
inside
 
active
 
tool
 
fields
 
(e.g.,
 
Width=50)
 
automatically
 
saves
 
them
 
to
 
Favorites.
 SOURCE:  
https://help.autodesk.com/view/fusion360/ENU/?guid=SLD-MODIFY-CHANGE-PARAMETERS
 
CONFIDENCE:
 
SOLID
 
What  is  the  technical  difference  between  user  parameters,  model  
parameters,
 
and
 
driven
 
dimensions?
 
Model  parameters  are  generated  automatically  when  features  or  dimensions  are  created  (e.g.,  
d1,
 
d2).
 
User
 
parameters
 
are
 
variables
 
defined
 
in
 
Design
 
>
 
Solid
 
>
 
Modify
 
>
 
Change
 
Parameters
 
that
 
drive
 
multiple
 
dimensions
 
across
 
features.
 
Driven
 
dimensions
 
(reference
 
dimensions)
 
are
 
passive
 
sketch
 
measurements
 
displaying
 
calculated
 
values
 
without
 
constraining
 
geometry.
 
Model
 
and
 
user
 
parameters
 
actively
 
drive
 
geometry,
 
whereas
 
driven
 
dimensions
 
monitor
 
geometric
 
outcomes.
 
Editing
 
a
 
user
 
parameter
 
instantly
 
updates
 
all
 
referencing
 
model
 
parameters
 
throughout
 
the
 
timeline.
 SOURCE:  https://help.autodesk.com/view/fusion360/ENU/?guid=SLD-MODIFY-PARAMETERS  
CONFIDENCE:
 
SOLID
 
Why  do  poorly  built  sketches  collapse  during  parametric  size  
changes?
 
Sketch  failure  during  parameter  changes  occurs  due  to  unconstrained  degrees  of  freedom,  
missing
 
geometric
 
relationships,
 
and
 
fragile
 
topological
 
references.
 
When
 
a
 
parameter
 
changes
 
significantly
 
(e.g.,
 
reducing
 
length
 
from
 
140
 
mm
 
to
 
120
 
mm),
 
unconstrained
 
lines
 
can
 
invert
 
across
 
axes
 
or
 
flip
 
direction.
 
Relying
 
on
 
absolute
 
spatial
 
distances
 
rather
 
than
 
geometric
 
constraints
 
(like
 
collinearity,
 
tangency,
 
or
 
horizontal/vertical
 
alignment)
 
causes
 
projected
 
references
 
to
 
detach.
 
Consequently,
 
downstream
 
timeline
 
features
 
such
 
as
 
chamfers
 
or
 
fillets
 
fail
 
because
 
their
 
parent
 
geometry
 
flipped
 
or
 
vanished.
 
SOURCE:  https://blog.prusa3d.com/parametric-modeling-in-fusion360_37411/  CONFIDENCE:  
SOLID
 
How  should  sketch  constraints  and  parametric  equations  be  
structured
 
for
 
stability?
 
Stable  parametric  sketches  anchor  primary  geometry  to  the  origin  using  explicit  constraints  
(Coincident,
 
Collinear,
 
Horizontal/Vertical)
 
rather
 
than
 
floating
 
dimensions.
 
Dimensions
 
should
 
reference
 
named
 
user
 
parameters
 
or
 
mathematical
 
formulas
 
(thickness
 
*
 
2)
 
rather
 
than
 
hardcoded
 
numbers.
 
Relationships
 
between
 
features
 
should
 
be
 
chained
 
hierarchically.
 
When
 
modifying
 
extensive
 
parameter
 
tables
 
in
 
Design
 
>
 
Solid
 
>
 
Modify
 
>
 
Change
 
Parameters,
 
unchecking
 
Automatic
 
Update
 
pauses
 
recalculation
 
until
 
all
 
formulas
 
are
 
entered,
 
preventing
 
compute
 
errors
 
from
 
incomplete
 
intermediate
 
values.
 SOURCE:  https://help.autodesk.com/view/fusion360/ENU/?guid=SLD-MODIFY-PARAMETERS  
CONFIDENCE:
 
SOLID
 
How  can  user  parameters  be  exported  and  imported  across  projects?  
User  parameters  can  be  externalized  to  maintain  consistent  design  standards  across  multiple  
projects.
 
Inside
 
Design
 
>
 
Solid
 
>
 
Modify
 
>
 
Change
 
Parameters,
 
clicking
 
Export
 
Parameters
 
writes
 
defined
 
user
 
parameters
 
to
 
a
 
standard
 
CSV
 
file.
 
To
 
load
 
parameters
 
into
 
a
 
new
 
design,
 
clicking
 
Import
 
Parameters
 
imports
 
the
 
CSV
 
data
 
into
 
the
 
active
 
parameter
 
table.
 
The
 
external
 
CSV
 
file
 
must
 
retain
 
exact
 
header
 
formatting,
 
unique
 
parameter
 
names,
 
and
 
valid
 
unit
 
syntax
 
to
 
prevent
 
syntax
 
errors
 
during
 
parameter
 
evaluation.
 SOURCE:  https://help.autodesk.com/view/fusion360/ENU/?guid=SLD-MODIFY-PARAMETERS  
CONFIDENCE:
 
SOLID
 Parameter  Category  Origin  /  Creation  Method  
Functional  Role  Timeline  Behavior  
User  Parameter  Manual  entry  in  Change  Parameters  dialog  or  on-the-fly  (Name=Value)  
Drive  variable  referenced  across  features  
Propagates  changes  across  all  referencing  timeline  steps  
Model  Parameter  Automatically  created  by  sketches  or  features  (d1,  d2)  
Direct  dimension  driver  for  specific  geometry  node  
Recalculates  specific  node  upon  variable  update  Driven  Dimension  Placed  manually  on  fully  constrained  sketch  profiles  
Passive  reference  display;  non-driving  readout  
Updates  readout  value  without  driving  geometry  
Section  B:  The  Python  API  
How  do  Python  scripts  differ  from  add-ins  in  Autodesk  Fusion?  
Scripts  and  add-ins  differ  in  execution  lifecycle  and  persistence.  A  script  is  executed  manually  
from
 
UTILITIES
 
>
 
Scripts
 
and
 
Add-Ins
 
and
 
terminates
 
immediately
 
after
 
its
 
run()
 
function
 
finishes.
 
An
 
add-in
 
stays
 
loaded
 
in
 
memory
 
continuously,
 
typically
 
launching
 
automatically
 
at
 
startup
 
via
 
Run
 
on
 
Startup.
 
Add-ins
 
can
 
create
 
custom
 
toolbar
 
buttons,
 
monitor
 
event
 
handlers,
 
and  react  to  user  actions.  Scripts  reside  in  %appdata%\Autodesk\Autodesk  Fusion\API\Scripts,  
while
 
add-ins
 
live
 
in
 
%appdata%\Autodesk\Autodesk
 
Fusion\API\AddIns.
 SOURCE:  
https://help.autodesk.com/view/fusion360/ENU/?guid=GUID-9701BBA7-EC0E-4016-A9C8-964
AA4838954
 
CONFIDENCE:
 
SOLID
 
How  is  the  Fusion  API  object  model  structured  in  plain  terms?  
The  API  follows  a  strict  parent-child  hierarchy  starting  at  adsk.core.Application.get().  The  
Application
 
object
 
provides
 
access
 
to
 
the
 
active
 
document
 
via
 
app.activeProduct,
 
which
 
yields
 
a
 
Design
 
object
 
(adsk.fusion.Design).
 
The
 
Design
 
contains
 
the
 
rootComponent
 
(adsk.fusion.Component),
 
which
 
holds
 
all
 
geometric
 
collections.
 
Sub-objects
 
like
 
sketches,
 
bRepBodies,
 
and
 
constructionPlanes
 
are
 
accessed
 
as
 
collections
 
off
 
components.
 
Features
 
(e.g.,
 
extrusions)
 
are
 
created
 
by
 
passing
 
input
 
definitions
 
to
 
feature
 
collections
 
on
 
a
 
component.
 SOURCE:  https://python.ju.se/Applications/fusion360api.html  CONFIDENCE:  SOLID  
What  is  the  internal  unit  trap  in  the  Fusion  API?  
While  Fusion  displays  user  dimensions  in  millimeters,  the  internal  API  engine  strictly  evaluates  
all
 
physical
 
lengths
 
in
 
centimeters
 
and
 
angles
 
in
 
radians.
 
Passing
 
a
 
raw
 
number
 
like
 
50
 
to
 
an
 
API
 
function
 
expecting
 
length
 
results
 
in
 
a
 
physical
 
dimension
 
of
 
50
 
cm
 
(500
 
mm).
 
To
 
avoid
 
scaling
 
errors,
 
raw
 
inputs
 
must
 
be
 
converted
 
by
 
multiplying
 
by
 
0.1
 
or
 
dividing
 
by
 
10.
 
Alternatively,
 
passing
 
expressions
 
with
 
explicit
 
unit
 
strings
 
(such
 
as
 
"50
 
mm"
 
or
 
"10
 
deg")
 
bypasses
 
raw
 
centimeter
 
interpretation.
 SOURCE:  
https://help.autodesk.com/cloudhelp/ENU/Fusion-360-API/files/MotionLinkInput_valueOne.htm
 
CONFIDENCE:
 
SOLID
 
How  do  you  load  and  execute  an  external  Python  script  in  Fusion  on  
Windows?
 
To  load  a  Python  script  on  Windows,  copy  the  script  folder  containing  .py  and  .manifest  files  into  
%appdata%\Autodesk\Autodesk
 
Fusion\API\Scripts.
 
Open
 
Fusion
 
and
 
navigate
 
to
 
UTILITIES
 
>
 
Scripts
 
and
 
Add-Ins
 
(or
 
press
 
Shift+S).
 
Under
 
the
 
Scripts
 
tab,
 
select
 
the
 
script
 
name.
 
If
 
the
 
script
 
is
 
stored
 
elsewhere,
 
click
 
the
 
green
 
+
 
icon
 
to
 
browse
 
and
 
add
 
the
 
folder.
 
Click
 
Run
 
to
 
execute.
 
To
 
edit
 
code
 
in
 
VS
 
Code,
 
select
 
the
 
script
 
and
 
click
 
Edit.
 SOURCE:  
https://help.autodesk.com/view/fusion360/ENU/?guid=GUID-9701BBA7-EC0E-4016-A9C8-964
AA4838954
 
CONFIDENCE:
 
SOLID
 
How  do  you  diagnose  and  debug  a  Python  script  that  fails  silently?  
Fusion  script  templates  wrap  code  inside  a  try...except  block  that  captures  runtime  errors.  
Unhandled
 
exceptions
 
do
 
not
 
crash
 
Fusion;
 
instead,
 
error
 
messages
 
are
 
written
 
to
 
the
 
Text
 
Commands
 
window.
 
To
 
view
 
logs,
 
open
 
the
 
Text
 
Commands
 
palette
 
via
 
File
 
>
 
View
 
>
 
Show
 
Text
 
Commands
 
or
 
shortcut
 
Ctrl+Alt+C.
 
Messages
 
logged
 
with
 
app.log()
 
or
 
tracebacks
 
formatted
 
via
 
traceback.format_exc()
 
display
 
in
 
this
 
console.
 
Checking
 
the
 
Text
 
Commands
 
window
 
reveals
 
line-specific  error  messages,  missing  variable  references,  or  API  argument  type  mismatches.  SOURCE:  https://blog.autodesk.io/lesson-1-the-basic-scripts-and-add-in/  CONFIDENCE:  
SOLID
 Program  Element  Target  Path  (Windows)  Execution  Trigger  UI  Presence  Python  Script  %appdata%\Autodesk\Autodesk  Fusion\API\Scripts  
Executed  manually  from  dialog  list  
Dialog  entry  under  Scripts  tab  
Python  Add-In  %appdata%\Autodesk\Autodesk  Fusion\API\AddIns  
Runs  continuously;  can  launch  at  startup  
Persistent  ribbon  buttons  &  context  menus  
Section  C:  Things  Worth  Scripting  
When  does  API  scripting  decisively  beat  manual  mouse  interaction?  
Scripting  outperforms  standard  GUI  interaction  during  repetitive  operations,  batch  exports,  
algorithmic
 
geometry
 
generation,
 
and
 
complex
 
array
 
creation.
 
Manually
 
creating
 
dozens
 
of
 
unique
 
hole
 
configurations
 
or
 
exporting
 
50
 
sub-components
 
requires
 
hundreds
 
of
 
manual
 
clicks
 
and
 
introduces
 
human
 
selection
 
error.
 
A
 
Python
 
script
 
loops
 
through
 
component
 
collections
 
(design.allComponents),
 
modifies
 
parameter
 
values
 
programmatically,
 
and
 
executes
 
ExportManager
 
functions
 
automatically.
 
Scripting
 
also
 
excels
 
at
 
mathematical
 
curve
 
generation—such
 
as
 
trochoidal
 
paths
 
or
 
involute
 
gears—that
 
standard
 
canvas
 
sketch
 
constraints
 
cannot
 
natively
 
construct.
 SOURCE:  
https://forums.autodesk.com/t5/fusion-api-and-scripts-forum/create-a-script-that-exports-each-co
mbination-of-components/td-p/10054567
 
CONFIDENCE:
 
SOLID
 
How  can  Python  scripts  automate  complex  hole  patterns  and  matrix  
arrays?
 
While  GUI  tools  handle  basic  rectangular  or  circular  patterns,  variable  grid  spacing  or  
conditional
 
hole
 
layouts
 
are
 
faster
 
to
 
script.
 
A
 
Python
 
script
 
calculates
 
matrix
 
coordinate
 
pairs
 
programmatically
 
and
 
invokes
 
HoleFeatures.add()
 
or
 
sketch
 
point
 
collections
 
in
 
a
 
single
 
execution
 
loop.
 
Scripts
 
can
 
apply
 
conditional
 
rules—such
 
as
 
suppressing
 
holes
 
near
 
component
 
edges
 
or
 
varying
 
drill
 
diameters
 
based
 
on
 
localized
 
panel
 
thickness.
 
Generating
 
hole
 
patterns
 
programmatically
 
avoids
 
manual
 
sketch
 
dimensioning
 
and
 
ensures
 
that
 
updating
 
underlying
 
variables
 
recalculates
 
hundreds
 
of
 
hole
 
features
 
reliably.
 SOURCE:  
https://www.autodesk.com/products/fusion-360/blog/build-your-own-fusion-add-ins-with-the-fusi
on-mcp/
 
CONFIDENCE:
 
SOLID
 
How  is  a  parametric  finger-jointed  box  generated  programmatically?  
Designing  laser-cut  finger-jointed  (box  joint)  enclosures  manually  requires  tedious  sketch  
profiles
 
across
 
six
 
faces.
 
A
 
Python
 
script
 
prompts
 
for
 
box
 
dimensions,
 
material
 
thickness,
 
and
 
tab
 
width,
 
then
 
calculates
 
tab
 
counts
 
using
 
integer
 
division
 
(floor(length
 
/
 
tab_width)).
 
The
 
script
 
constructs
 
sketch
 
profiles
 
programmatically
 
on
 
corresponding
 
face
 
planes
 
and
 
executes
 
Cut
 
extrusions  across  interlocking  panels.  Incorporating  kerf  compensation  directly  into  coordinate  
offsets
 
produces
 
ready-to-cut
 
joint
 
geometry
 
without
 
manual
 
trimming.
 
Updating
 
inputs
 
re-runs
 
the
 
script
 
to
 
rebuild
 
entire
 
custom
 
box
 
assemblies
 
instantly.
 SOURCE:  
https://help.autodesk.com/view/fusion360/ENU/?guid=GUID-76272551-3275-46C4-AE4D-10D5
8B408C20
 
CONFIDENCE:
 
SOLID
 
How  can  component  families  and  batch  file  exports  be  automated  via  
the
 
API?
 
Generating  families  of  components  (such  as  varying  bracket  sizes  or  modular  enclosures)  
requires
 
exporting
 
individual
 
STEP
 
or
 
STL
 
files.
 
Manual
 
exports
 
require
 
right-clicking
 
every
 
component
 
individually.
 
Using
 
adsk.fusion.ExportManager,
 
a
 
Python
 
script
 
loops
 
through
 
rootComp.allComponents
 
or
 
bRepBodies,
 
sets
 
parameter
 
combinations,
 
and
 
calls
 
createSTEPExportOptions()
 
or
 
createSTLExportOptions().
 
The
 
script
 
constructs
 
output
 
paths
 
on
 
Windows
 
(os.path.join(os.getenv('USERPROFILE'),
 
'Desktop'))
 
and
 
outputs
 
complete
 
file
 
sets
 
automatically.
 SOURCE:  
https://forums.autodesk.com/t5/fusion-api-and-scripts-forum/how-to-export-hundreds-of-bodies-
as-individual-steps-locally-on/td-p/9543819
 
CONFIDENCE:
 
SOLID
 
Section  D:  From  Fusion  to  a  Machine  
###  What  mesh  export  formats  are  best  suited  for  3D  printing  and  what  data  do  they  retain?  For  
additive
 
manufacturing
 
on
 
Bambu
 
Lab
 
printers,
 
3MF
 
and
 
STL
 
are
 
standard
 
mesh
 
export
 
formats.
 
Right-clicking
 
a
 
body
 
and
 
selecting
 
Save
 
As
 
Mesh
 
provides
 
access
 
to
 
both.
 
STL
 
represents
 
surfaces
 
as
 
uncolored
 
triangular
 
meshes,
 
stripping
 
unit
 
definitions,
 
material
 
colors,
 
and
 
parametric
 
CAD
 
geometry.
 
In
 
contrast,
 
3MF
 
preserves
 
triangular
 
mesh
 
geometry
 
alongside
 
explicit
 
unit
 
specifications,
 
material
 
colors,
 
multi-body
 
component
 
structures,
 
and
 
slicer
 
settings.
 
3MF
 
prevents
 
unit
 
scaling
 
errors
 
in
 
slicers
 
like
 
Bambu
 
Studio
 
while
 
producing
 
smaller
 
file
 
sizes
 
than
 
high-density
 
STLs.
 SOURCE:  
https://www.autodesk.com/products/fusion-360/blog/september-2021-product-update-whats-ne
w/
 
CONFIDENCE:
 
SOLID
 
How  should  2D  vectors  be  exported  for  laser  cutting,  and  what  
geometry
 
is
 
preserved?
 
2D  profiles  for  laser  cutting  are  exported  by  right-clicking  a  sketch  in  the  browser  tree  and  
choosing
 
Save
 
As
 
DXF.
 
DXF
 
preserves
 
precise
 
vector
 
geometry
 
including
 
true
 
arcs,
 
circles,
 
splines,
 
and
 
lines
 
at
 
1:1
 
scale.
 
However,
 
DXF
 
exports
 
strip
 
parametric
 
constraints,
 
timeline
 
history,
 
material
 
thickness,
 
and
 
3D
 
feature
 
data.
 
To
 
ensure
 
accurate
 
laser
 
kerf
 
cutting,
 
DXF
 
files
 
should
 
be
 
exported
 
directly
 
from
 
planar
 
sketches
 
created
 
on
 
face
 
projections
 
rather
 
than
 
raw
 
3D
 
body
 
edges.
 SOURCE:  
https://help.autodesk.com/view/fusion360/ENU/?guid=SLD-MODIFY-CHANGE-PARAMETERS
 
CONFIDENCE:  SOLID  
What  data  is  preserved  and  lost  when  exporting  STEP  files  for  CNC  
milling?
 
STEP  (.step  /  .stp)  is  a  boundary  representation  (B-Rep)  CAD  format  used  for  CNC  milling  
workflows.
 
Exporting
 
via
 
File
 
>
 
Export
 
or
 
ExportManager
 
preserves
 
precise
 
mathematical
 
NURBS
 
surfaces,
 
cylinder
 
centers,
 
solid
 
body
 
topologies,
 
and
 
assembly
 
component
 
structures.
 
This
 
allows
 
CAM
 
software
 
to
 
generate
 
accurate
 
toolpaths.
 
However,
 
STEP
 
exports
 
strip
 
parametric
 
timeline
 
history,
 
feature
 
dependencies,
 
sketch
 
constraints,
 
and
 
user
 
parameter
 
formulas.
 
Modifying
 
imported
 
STEP
 
geometry
 
requires
 
direct
 
modeling
 
tools
 
rather
 
than
 
editing
 
variable
 
tables.
 SOURCE:  
https://www.autodesk.com/products/fusion-360/blog/search/additive+manufacturing/feed/rss2/
 
CONFIDENCE:
 
SOLID
 
How  does  Fusion  CAM  process  toolpaths  and  export  G-code  for  CNC  
machines?
 
In  the  MANUFACTURE  workspace,  Fusion  converts  CAD  geometry  into  machine  motion  using  
post-processors
 
(MANUFACTURE
 
>
 
Milling
 
>
 
Actions
 
>
 
Post
 
Process).
 
Toolpath
 
operations
 
maintain
 
cutting
 
speeds,
 
feeds,
 
and
 
2.5D/3-axis
 
strategies.
 
During
 
post-processing,
 
parametric
 
CAD
 
relationships
 
are
 
flattened
 
into
 
explicit
 
X,
 
Y,
 
Z
 
coordinates
 
and
 
arc
 
commands
 
(G1,
 
G2,
 
G3).
 
Machine-specific
 
parameters
 
and
 
license
 
constraints—such
 
as
 
rapid
 
feedrate
 
capping
 
under
 
personal
 
licensing—are
 
compiled
 
directly
 
into
 
the
 
resulting
 
G-code
 
text
 
file
 
by
 
the
 
post-processor.
 SOURCE:  
https://forums.autodesk.com/t5/fusion-manufacture-forum/bug-drill-operation/td-p/9779575
 
CONFIDENCE:
 
SOLID
 |  Format  |  Machine  Target  |  Retained  Data  |  Stripped  /  Flattened  Data  |  |  :---  |  :---  |  :---  |  :---  |  |  
3MF
 
|
 
3D
 
Printer
 
(Bambu)
 
|
 
Mesh
 
topology,
 
unit
 
scales,
 
colors,
 
assemblies
 
|
 
Parametric
 
timeline,
 
B-Rep
 
NURBS
 
surfaces
 
|
 
|
 
STL
 
|
 
3D
 
Printer
 
|
 
Uncolored
 
triangular
 
mesh
 
|
 
Unit
 
definitions,
 
material
 
colors,
 
constraints
 
|
 
|
 
DXF
 
|
 
Laser
 
Cutter
 
|
 
2D
 
vector
 
curves,
 
true
 
arcs,
 
1:1
 
unit
 
scale
 
|
 
Material
 
thickness,
 
3D
 
body
 
height,
 
constraints
 
|
 
|
 
STEP
 
|
 
CNC
 
Mill
 
/
 
Router
 
|
 
B-Rep
 
NURBS
 
surfaces,
 
solid
 
topology,
 
assemblies
 
|
 
Timeline
 
history,
 
sketch
 
constraints,
 
parameters
 
|
 ##  Section  E:  Limits  of  the  Free  Personal  Licence  
What  are  the  exact  active  document  limits  on  the  Personal  License?  
The  Personal  License  restricts  accounts  to  a  maximum  of  10  active  (editable)  CAD  documents  
simultaneously.
 
Active
 
files
 
display
 
an
 
"Editable"
 
tag
 
in
 
the
 
Data
 
Panel.
 
All
 
additional
 
models
 
must
 
be
 
designated
 
as
 
"Read-Only".
 
Toggling
 
documents
 
between
 
Read-Only
 
and
 
Editable
 
can
 
be
 
performed
 
at
 
any
 
time
 
without
 
fees
 
via
 
the
 
Data
 
Panel
 
context
 
menu.
 
Read-only
 
files
 
can
 
be
 
opened,
 
viewed,
 
and
 
measured,
 
but
 
changes
 
cannot
 
be
 
saved
 
until
 
an
 
active
 
slot
 
is
 
freed
 
by
 
marking
 
another
 
file
 
as
 
Read-Only.
 
This
 
restriction
 
governs
 
concurrent
 
editing
 
slots
 
rather
 
than
 
total
 
cloud
 
storage
 
limits.
 SOURCE:  
https://www.autodesk.com/products/fusion-360/blog/search/additive+manufacturing/feed/rss2/  
CONFIDENCE:
 
SOLID
 
How  are  CAM  and  machining  exports  restricted  under  the  Personal  
License?
 
The  Personal  License  applies  functional  limits  in  the  MANUFACTURE  workspace.  Multi-axis  
toolpaths
 
are
 
disabled,
 
limiting
 
milling
 
to
 
2.5-axis
 
and
 
3-axis
 
indexing
 
strategies.
 
Automatic
 
tool
 
changes
 
(M06
 
commands)
 
are
 
stripped
 
from
 
exported
 
G-code,
 
requiring
 
separate
 
files
 
per
 
tool.
 
Rapid
 
traverse
 
moves
 
(G0)
 
are
 
capped
 
at
 
maximum
 
cutting
 
feed
 
rates
 
(G1),
 
generating
 
warning
 
flags
 
in
 
post-processor
 
logs.
 
Automated
 
hole
 
recognition,
 
probing,
 
and
 
5-axis
 
continuous
 
toolpathing
 
are
 
locked
 
behind
 
paid
 
extensions.
 SOURCE:  
https://forums.autodesk.com/t5/fusion-manufacture-forum/bug-drill-operation/td-p/9779575
 
CONFIDENCE:
 
SOLID
 
What  export  formats  and  drawing  capabilities  are  supported  vs  
restricted
 
on
 
the
 
Personal
 
License?
 
Personal  License  users  retain  local  CAD  and  mesh  export  support  for  STEP,  IGES,  DXF,  STL,  
3MF,
 
and
 
OBJ
 
formats.
 
STEP
 
export
 
remains
 
available
 
for
 
personal
 
accounts.
 
Proprietary
 
CAD
 
translators—such
 
as
 
native
 
SolidWorks
 
(.sldprt),
 
Parasolid
 
(.x_t),
 
or
 
Siemens
 
NX
 
files—cannot
 
be
 
exported.
 
In
 
the
 
DRAWING
 
workspace,
 
personal
 
users
 
are
 
limited
 
to
 
single-page
 
drawing
 
documents;
 
multi-sheet
 
technical
 
drawings
 
and
 
automated
 
BOM
 
table
 
exports
 
require
 
commercial
 
subscriptions.
 SOURCE:  
https://www.autodesk.com/products/fusion-360/blog/search/additive+manufacturing/feed/rss2/
 
CONFIDENCE:
 
SOLID
 
Are  Python  API  scripting  capabilities  restricted  on  the  Personal  
License?
 
Desktop  Python  API  scripting  is  fully  accessible  under  the  free  Personal  License.  Personal  
users
 
possess
 
identical
 
local
 
API
 
execution
 
privileges
 
to
 
commercial
 
subscribers,
 
including
 
parameter
 
manipulation,
 
geometry
 
creation,
 
UI
 
script
 
execution,
 
and
 
batch
 
exports
 
via
 
ExportManager.
 
Scripting
 
limitations
 
are
 
governed
 
strictly
 
by
 
workspace
 
access
 
rather
 
than
 
API
 
blocks:
 
calling
 
commercial-only
 
functions
 
(such
 
as
 
generative
 
design
 
or
 
5-axis
 
CAM
 
generation)
 
via
 
script
 
fails
 
due
 
to
 
underlying
 
subscription
 
locks
 
rather
 
than
 
API
 
restrictions.
 SOURCE:  
https://help.autodesk.com/view/fusion360/ENU/?guid=GUID-9701BBA7-EC0E-4016-A9C8-964
AA4838954
 
CONFIDENCE:
 
SOLID
 
Myths  and  Outdated  Advice  
1.  Myth:  STEP  file  export  is  blocked  on  the  free  Personal  License.  Reality:  Although  
Autodesk
 
initially
 
planned
 
to
 
remove
 
STEP
 
export
 
capabilities
 
from
 
Personal
 
License
 
accounts
 
in
 
late
 
2020,
 
user
 
feedback
 
led
 
Autodesk
 
to
 
reverse
 
this
 
decision.
 
Local
 
STEP
 
(.step  /  .stp)  file  exports  remain  supported  for  personal  accounts  via  File  >  Export  or  
scripts
 
using
 
ExportManager.
 2.  Myth:  The  Fusion  Python  API  requires  a  paid  commercial  subscription.  Reality:  
Desktop
 
Python
 
API
 
scripting
 
(UTILITIES
 
>
 
Scripts
 
and
 
Add-Ins)
 
is
 
completely
 
unlocked
 
for
 
Personal
 
License
 
holders.
 
Personal
 
accounts
 
can
 
create,
 
edit,
 
and
 
run
 
local
 
Python
 
scripts
 
to
 
manipulate
 
parameters,
 
construct
 
geometry,
 
or
 
batch
 
export
 
files
 
without
 
purchasing
 
a
 
paid
 
license.
 
Only
 
cloud-hosted
 
headless
 
automation
 
via
 
APS
 
Automation
 
API
 
requires
 
paid
 
tokens.
 3.  Myth:  Fusion  API  length  values  match  the  document's  active  UI  unit  settings.  
Reality:
 
Regardless
 
of
 
whether
 
active
 
document
 
units
 
are
 
set
 
to
 
millimeters
 
or
 
inches
 
in
 
the
 
user
 
interface,
 
the
 
internal
 
Fusion
 
API
 
engine
 
strictly
 
processes
 
all
 
physical
 
length
 
values
 
in
 
centimeters
 
and
 
angular
 
measurements
 
in
 
radians.
 
Raw
 
numerical
 
inputs
 
passed
 
to
 
API
 
functions
 
must
 
be
 
converted
 
manually
 
or
 
supplied
 
as
 
explicit
 
unit
 
string
 
expressions
 
(e.g.,
 
"50
 
mm")
 
to
 
avoid
 
ten-fold
 
scaling
 
errors.
 4.  Myth:  Personal  License  accounts  can  only  store  10  total  CAD  files  in  the  cloud.  
Reality:
 
The
 
10-document
 
limit
 
applies
 
exclusively
 
to
 
active,
 
concurrently
 
editable
 
files.
 
Users
 
can
 
store
 
an
 
unlimited
 
total
 
number
 
of
 
CAD
 
files
 
in
 
their
 
Autodesk
 
cloud
 
account
 
by
 
setting
 
inactive
 
models
 
to
 
"Read-Only"
 
in
 
the
 
Data
 
Panel.
 
Files
 
can
 
be
 
flipped
 
between
 
Read-Only
 
and
 
Editable
 
states
 
at
 
any
 
time.
 5.  Myth:  Custom  Python  scripts  must  be  reinstalled  whenever  Fusion  updates.  Reality:  
Fusion
 
stores
 
user
 
scripts
 
and
 
add-ins
 
in
 
dedicated
 
Windows
 
directories
 
(%appdata%\Autodesk\Au[span_182](start_span)[span_182](end_span)todesk
 
Fusion\API\Scripts
 
and
 
AddIns)
 
that
 
exist
 
outside
 
the
 
core
 
application
 
installation
 
folder.
 
Routine
 
Fusion
 
software
 
updates
 
leave
 
all
 
custom
 
Python
 
scripts,
 
subfolders,
 
and
 
manifest
 
files
 
completely
 
untouched.
 6.  Myth:  Personal  License  accounts  cannot  export  G-code  for  CNC  machines.  Reality:  
Personal
 
License
 
accounts
 
maintain
 
standard
 
2.5-axis
 
and
 
3-axis
 
CAM
 
milling
 
toolpath
 
generation
 
and
 
post-processing
 
capabilities.
 
Post-processors
 
generate
 
valid
 
G-code
 
for
 
CNC
 
machines.
 
License
 
restrictions
 
are
 
limited
 
to
 
stripping
 
automatic
 
tool
 
change
 
commands
 
(M06),
 
capping
 
rapid
 
moves
 
(G0
 
converted
 
to
 
G1),
 
and
 
locking
 
continuous
 
5-axis
 
toolpathing.
 
Geciteerd  werk  
1.  How  to  Create  and  Edit  Parameters  in  Fusion  for  Simplified  Design  Control  -  Autodesk,  
https://www.autodesk.com/products/fusion-360/blog/mastering-fusion-parameters-a-guide-for-si
mplified-design-control/
 
2.
 
Fusion
 
Help
 
|
 
Create
 
or
 
edit
 
parameters
 
-
 
Autodesk
 
product
 
documentation,
 
https://help.autodesk.com/view/fusion360/ENU/?guid=SLD-MODIFY-CHANGE-PARAMETERS
 
3.
 
Parameters
 
in
 
Fusion
 
-
 
Autodesk
 
product
 
documentation,
 
https://help.autodesk.com/view/fusion360/ENU/?guid=SLD-MODIFY-PARAMETERS
 
4.
 
Fusion
 
Help
 
|
 
Parameters
 
reference
 
-
 
Autodesk
 
product
 
documentation,
 
https://help.autodesk.com/view/fusion360/ENU/?guid=GUID-76272551-3275-46C4-AE4D-10D5
8B408C20
 
5.
 
Sketch
 
with
 
Fusion
 
-
 
Use
 
parameters
 
to
 
constrain
 
sketch
 
geometry
 
-
 
Autodesk,
 
https://www.autodesk.com/learn/ondemand/curated/sketch-with-fusion-360/5kns5wSM7JU0YhJl
kDebCO
 
6.
 
Parametric
 
modeling
 
in
 
Fusion360
 
-
 
Original
 
Prusa
 
3D
 
Printers,
 
https://blog.prusa3d.com/parametric-modeling-in-fusion360_37411/
 
7.
 
Lesson
 
1:
 
The
 
basic
 
scripts
 
and
 
Add-in
 
-
 
Autodesk
 
Developer
 
Blog,
 
https://blog.autodesk.io/lesson-1-the-basic-scripts-and-add-in/  8.  Fusion  Help  |  Creating  a  Script  
or
 
Add-In
 
-
 
Autodesk
 
product
 
documentation,
 
https://help.autodesk.com/view/fusion360/ENU/?guid=GUID-9701BBA7-EC0E-4016-A9C8-964
AA4838954
 
9.
 
How
 
to
 
install
 
an
 
add-in
 
or
 
script
 
in
 
Autodesk
 
Fusion,
 
https://www.autodesk.com/support/technical/article/caas/sfdcarticles/sfdcarticles/How-to-install-a
n-ADD-IN-and-Script-in-Fusion-360.html
 
10.
 
Add
 
CFD
 
2019
 
or
 
2021
 
to
 
Fusion
 
360
 
-
 
IMAGINiT,
 
https://resources.imaginit.com/support-blog/add-cfd-2019-or-2021-to-fusion-360
 
11.
 
Build
 
Your
 
Own
 
Fusion
 
Add-ins
 
with
 
the
 
Fusion
 
MCP
 
-
 
Autodesk,
 
https://www.autodesk.com/products/fusion-360/blog/build-your-own-fusion-add-ins-with-the-fusi
on-mcp/
 
12.
 
8.8
 
Fusion360
 
API
 
-
 
Scientific
 
Programming,
 
https://python.ju.se/Applications/fusion360api.html
 
13.
 
How
 
to
 
export
 
hundreds
 
of
 
bodies
 
as
 
individual
 
steps
 
locally
 
(on
 
my
 
HD)?,
 
https://forums.autodesk.com/t5/fusion-api-and-scripts-forum/how-to-export-hundreds-of-bodies-
as-individual-steps-locally-on/td-p/9543819
 
14.
 
Rendering
 
with
 
the
 
API
 
-
 
Autodesk
 
Community,
 
https://forums.autodesk.com/t5/fusion-api-and-scripts-forum/rendering-with-the-api/td-p/772495
1
 
15.
 
Create
 
a
 
script
 
that
 
exports
 
each
 
combination
 
of
 
components?
 
-
 
Autodesk
 
Community,
 
https://forums.autodesk.com/t5/fusion-api-and-scripts-forum/create-a-script-that-exports-each-co
mbination-of-components/td-p/10054567
 
16.
 
How
 
do
 
you
 
get
 
a
 
reference
 
to
 
Body
 
by
 
name?
 
-
 
Autodesk
 
Community,
 
https://forums.autodesk.com/t5/fusion-api-and-scripts-forum/how-do-you-get-a-reference-to-bod
y-by-name/td-p/12073986
 
17.
 
MotionLinkInput.valueOne
 
Property,
 
https://help.autodesk.com/cloudhelp/ENU/Fusion-360-API/files/MotionLinkInput_valueOne.htm
 
18.
 
ExportManager
 
and
 
Unit
 
Type
 
-
 
Autodesk
 
Community,
 
https://forums.autodesk.com/t5/fusion-api-and-scripts-forum/exportmanager-and-unit-type/td-p/1
0876325
 
19.
 
How
 
to
 
update
 
an
 
add-in
 
for
 
Autodesk
 
Fusion,
 
https://www.autodesk.com/support/technical/article/caas/sfdcarticles/sfdcarticles/How-to-update-
an-add-in-for-Autodesk-Fusion.html
 
20.
 
September
 
2021
 
Product
 
Update
 
-
 
What's
 
New
 
-
 
Fusion
 
Blog
 
-
 
Autodesk,
 
https://www.autodesk.com/products/fusion-360/blog/september-2021-product-update-whats-ne
w/
 
21.
 
Fusion
 
Support
 
Forum
 
-
 
Page
 
593
 
-
 
Autodesk
 
Community,
 
https://forums.autodesk.com/t5/fusion-support-forum/bd-p/fusion-support-forum-en/page/593
 
22.
 
You
 
searched
 
for
 
additive
 
manufacturing
 
-
 
Fusion
 
Blog
 
-
 
Autodesk,
 
https://www.autodesk.com/products/fusion-360/blog/search/additive+manufacturing/feed/rss2/
 
23.
 
BUG
 
-
 
drill
 
operation
 
-
 
Autodesk
 
Community,
 
https://forums.autodesk.com/t5/fusion-manufacture-forum/bug-drill-operation/td-p/9779575
 
24.
 
Fusion
 
Specific
 
Info
 
|
 
Automation
 
API
 
-
 
Autodesk
 
Platform
 
Services,
 
https://aps.autodesk.com/en/docs/design-automation/v3/developers_guide/fusion_specific
 
25.
 
Get
 
started
 
with
 
Automation
 
API
 
for
 
Fusion
 
-
 
Autodesk
 
Platform
 
Services,
 
https://aps.autodesk.com/blog/get-started-automation-api-fusion
 