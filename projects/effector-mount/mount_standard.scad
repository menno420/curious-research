// =============================================================================
// mount_standard.scad — the shared wrist-mount interface for the robot arm
// =============================================================================
//
// WHAT THIS IS
//   One printed "adapter plate" that bolts to the last servo's horn on your arm.
//   EVERY tool the arm carries (the pen holder, this magnet pickup, a future
//   gripper...) is built starting from THIS plate, so they all mount the same
//   way, in the same spot, facing the same direction. Design a tool once and it
//   clicks onto the arm like the others — no re-measuring, no re-drilling.
//
//   This file is a LIBRARY, not a finished part. A tool file pulls it in with:
//         use <mount_standard.scad>
//   then calls  mount_plate();  and builds its own body on top of it.
//
// HOW TO USE IT (makers)
//   1. Open this file in OpenSCAD and press F5 to preview the bare plate.
//   2. Measure YOUR servo horn (each parameter below says what to measure) and
//      edit the numbers. This one file is the single place the interface lives.
//   3. Don't slice THIS file for real use — slice a TOOL file (e.g.
//      magnet_tool.scad) that includes it. The bare plate is only handy as a
//      quick "does my horn fit?" test print.
//
// NO RENDERER HERE
//   This was written in a container with no OpenSCAD installed, so it has NOT
//   been rendered or sliced. You are the one who opens it, renders (F6), slices,
//   loads, starts, and watches every print. Treat any "it'll fit / it'll hold"
//   as YOUR call to check.
//
// SAFETY (arm rails)
//   This file makes ONLY the passive mounting interface — there is no motion
//   code here and none belongs here. The arm moves only inside its calibrated
//   envelope, through routines that clamp to it, with a human watching. Any tool
//   that lifts a load is a "check this yourself."
// =============================================================================


// ---- BENCH WORDS (one line each) --------------------------------------------
// servo horn    : the star/arm-shaped disc bolted to the servo shaft that moves.
// bolt pattern  : the spacing + size of the screw holes. Match it, tools fit.
// key / keying  : a shape that fits only one way so the tool can't spin or sit
//                 crooked. Here: a round recess that seats the horn's raised hub,
//                 plus a notch that marks the mounting ("back") edge.
// clearance hole: a hole a bit BIGGER than the screw so the screw slides through
//                 freely (it grips the horn underneath, not this plate).


// =============================================================================
// PARAMETERS — measure your horn, then edit. Each has its own note.
// =============================================================================

// -- The two horn screws (the bolt pattern every tool shares) --
horn_span     = 16.0;   // centre-to-centre distance between the two horn screws
                        // (mm). Measure hole-centre to hole-centre on your horn.
horn_screw_d  = 2.2;    // screw CLEARANCE diameter (mm). The M2 self-tappers that
                        // ship with 9 g servos slide freely at 2.2. Bigger screw?
                        // Use its shaft diameter + about 0.2 mm.

// -- Plate size + thickness --
mount_th      = 3.0;    // plate thickness (mm). 3 mm is stiff enough for light
                        // tools in PETG; go 4 mm if a tool feels bendy.
plate_w       = 28.0;   // plate width, across the two screws (mm).
plate_front   = 10.0;   // how far the plate reaches FORWARD of the horn centre
                        // (mm). Tools that need more room pass a bigger value.
plate_back    =  8.0;   // how far it reaches BEHIND the horn centre (mm).

// -- Keying feature #1: the hub recess (centres the plate, resists wobble) --
// Most 9 g horns have a raised round hub around the centre boss. A shallow recess
// that drops over that hub self-centres the plate on the shaft. With the two
// offset screws, it stops the plate shifting or pivoting.
horn_hub_d    = 8.0;    // diameter of your horn's raised centre hub (mm).
                        // Set to 0 to switch the hub recess OFF.
horn_hub_th   = 1.2;    // recess depth (mm) — keep it a little LESS than the hub's
                        // real height so the plate still clamps flat on the screws.

// -- Keying feature #2: the orientation notch (marks the mounting edge) --
// A small notch cut into the BACK edge. Convention for this whole tool family:
// build every tool with its working end (pen tip, magnet, fingers) pointing to
// +Y, and the notch always marks the opposite, "back", edge. Same notch = every
// tool goes on the arm the same way round, every time.
key_notch     = true;   // set false to remove the notch.
key_notch_w   = 5.0;    // notch width (mm).
key_notch_d   = 1.5;    // notch depth (mm).

// -- Print quality --
$fn = 48;               // roundness of holes/cylinders in preview + render.


// =============================================================================
// mount_top() — height of the plate's top face. A tool stacks its body on top:
//     translate([0, 0, mount_top()]) my_tool_body();
// =============================================================================
function mount_top() = mount_th;


// =============================================================================
// mount_bolt_holes() — just the two horn-screw clearance holes (to subtract).
// A tool that wants to draw its own custom plate can reuse only this pattern.
// =============================================================================
module mount_bolt_holes() {
    for (sx = [-horn_span/2, horn_span/2])
        translate([sx, 0, -0.5])
            cylinder(h = mount_th + 1, d = horn_screw_d);
}


// =============================================================================
// mount_plate() — the full shared interface plate.
//   * flat plate centred on the origin, top face at Z = mount_th
//   * the two horn-screw clearance holes (bolt pattern) on the origin line
//   * a shallow hub recess on the BOTTOM (key #1 — centres it on the horn)
//   * a notch on the BACK edge (key #2 — marks the mounting orientation)
//   front / back = how far the plate reaches in +Y / -Y. A tool passes a bigger
//   `front` when it needs plate under a part that sits forward of the screws.
// =============================================================================
module mount_plate(front = plate_front, back = plate_back) {
    difference() {
        // the plate itself
        translate([-plate_w/2, -back, 0])
            cube([plate_w, back + front, mount_th]);

        // the two horn-screw clearance holes (the shared bolt pattern)
        mount_bolt_holes();

        // key #1 — hub recess, cut into the BOTTOM face, only if enabled
        if (horn_hub_d > 0)
            translate([0, 0, -0.01])
                cylinder(h = horn_hub_th + 0.01, d = horn_hub_d);

        // key #2 — orientation notch on the BACK edge (at -Y)
        if (key_notch)
            translate([-key_notch_w/2, -back - 0.5, -0.5])
                cube([key_notch_w, key_notch_d + 0.5, mount_th + 1]);
    }
}


// =============================================================================
// PREVIEW — draws the bare plate when you open THIS file directly.
// (A tool file that `use`s this library does NOT run this line — `use` pulls in
//  the modules/function but not top-level calls, so you get the plate to build
//  on without a stray copy floating in your tool.)
// =============================================================================
mount_plate();
