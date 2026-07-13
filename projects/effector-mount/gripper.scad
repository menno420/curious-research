// =============================================================================
// gripper.scad — a single-servo, 2-finger RACK-AND-PINION gripper for the arm
// =============================================================================
//
// WHAT THIS IS
//   The family's first ACTIVE tool: a two-finger gripper driven by ONE hobby
//   servo, built on the shared mount plate (mount_standard.scad) so it clicks
//   onto the arm's wrist exactly like the pen holder and the magnet pickup do.
//   One servo turns a round gear (the "pinion"). That pinion drives TWO straight
//   toothed bars (the "racks") that sit on OPPOSITE sides of it — so when the
//   servo turns one way, one rack slides left and the other slides right, and
//   both jaws close together (or open together) at the same speed. One motor,
//   two jaws, always symmetric. That is the whole trick of rack-and-pinion.
//
//   Like the rest of the family this file is a DESIGN, not a finished STL, and
//   it pulls in the shared plate:
//         use <mount_standard.scad>
//   then builds the servo cradle + gear mechanism on top of the plate.
//
// HOW TO USE IT (makers)
//   1. Keep this file in the SAME folder as mount_standard.scad (it pulls it in).
//   2. Pick your servo: set  servo_type = "MG90S";  (metal-gear 9 g, the default)
//      or  "MG996R";  for the bigger/stronger one. Read the SERVO note below —
//      do NOT use an SG90: its plastic gears strip when a gripper stalls.
//   3. Measure YOUR servo and edit the body/shaft/tab numbers for that type.
//   4. Press F5 to preview, F6 to render, then export/slice and print.
//   5. CHECK THE GEAR MESH BY HAND before any power (README, step 2): turn the
//      pinion, watch both racks slide opposite ways, jaws move together, nothing
//      binds. Nudge  mesh_tweak  if the teeth jam or the gap is sloppy.
//
// NO RENDERER HERE
//   Written in a container with NO OpenSCAD installed — this file has NOT been
//   rendered, sliced, or test-fitted. YOU open it, render (F6), slice, load,
//   start, and watch every print. Every "it meshes / it grips" is YOUR call.
//
// HONEST ABOUT THE GEAR TEETH
//   This file is SELF-CONTAINED — it does NOT depend on a gear library, so the
//   teeth are a SIMPLIFIED straight-flanked (trapezoidal) profile, not proper
//   involute gear teeth. It is close enough to print and try, but the mesh WILL
//   want hand-checking, and you may want to nudge  mesh_tweak / clearance . If
//   you have a real gear library (e.g. BOSL2's  rack()/spur_gear() ), you can
//   swap the pinion()/rack() modules here for those and keep the rest.
//
// SAFETY (arm rails + a thing that CLAMPS)
//   * There is NO motion code in this .scad — it is a passive printed part.
//   * A gripper is LOAD-BEARING: a dropped part is on the human to prevent.
//     Confirm the jaws actually hold YOUR object, by hand, at the bench, BEFORE
//     any arm lift (README ⚠ callout).
//   * Servo power is a SEPARATE, FUSED 5-6 V supply with shared ground and a
//     reachable switch — NEVER the Arduino's 5 V pin. A gripping servo can stall
//     and gulp far more current than the board can give.
//   * Bench-test the servo ALONE with gripper_test.ino first. Arm-mounted motion
//     goes ONLY through the clamped path (projects/arm-pen-plotter/
//     teach_and_replay.py against arm/calibration.json) — never a raw servo
//     write. That calibration file does not exist yet, so no arm motion runs.
// =============================================================================

use <mount_standard.scad>


// ---- BENCH WORDS (one line each) --------------------------------------------
// rack          : a straight bar with teeth along one edge — a "flattened gear".
// pinion        : the round gear that meshes the rack; the servo turns this.
// rack-and-pinion: pinion spins -> rack slides. Two racks on opposite sides of
//                 one pinion slide OPPOSITE ways -> two jaws move symmetrically.
// module (gear) : the tooth-size number, in mm. Same module on two gears = teeth
//                 that fit. (NOT the same word as an OpenSCAD "module {}".)
// tooth pitch   : centre-to-centre spacing of teeth = PI * module, in mm.
// mesh          : two sets of teeth engaging cleanly — rolling, not jamming or
//                 slipping. This is the thing you check by hand.
// pitch circle  : the imaginary circle where a gear's teeth "roll"; its diameter
//                 = module * number-of-teeth. Racks line up to this circle.
// addendum/dedendum : how far a tooth sticks OUT past / IN behind the pitch line.
// jaw travel    : how far ONE jaw moves from fully closed to fully open, in mm.
// clearance     : the little gap left for print swell so parts still fit/slide.


// =============================================================================
// PARAMETERS — measure your servo, then edit. Each has its own note.
// =============================================================================

// -- WHICH SERVO ---------------------------------------------------------------
// MG90S  = metal-gear 9 g class, ~2.2 kg-cm. The DEFAULT: gentle, light, enough
//          for small parts, and its metal gears survive the odd stall.
// MG996R = the STRONGER option, ~10 kg-cm, but 55 g of weight hanging at the end
//          of the arm (that eats your payload) and a bigger stall-current draw.
// SG90   = DO NOT USE for a gripper. Its PLASTIC gears STRIP when the servo
//          stalls against the object it's gripping — and a gripper stalls by
//          design. (Straight from ideas/printed-end-effectors.md.)
servo_type = "MG90S";     // "MG90S" (default) or "MG996R". Not "SG90".

// A hard guard: refuse to silently build for an SG90.
assert(servo_type == "MG90S" || servo_type == "MG996R",
       "servo_type must be \"MG90S\" or \"MG996R\" — SG90 strips its gears on a gripper.");

// -- SERVO BODY DIMENSIONS (measure YOURS; these are typical starting values) --
// The two value sets below are picked by servo_type. Reach for calipers and
// correct them for the exact servo in your hand — brands vary a millimetre or
// two, and that millimetre decides whether the body drops into its cradle.
is_996 = (servo_type == "MG996R");

body_l   = is_996 ? 40.7 : 22.8;  // body LENGTH, along the arm's forward axis (mm)
body_w   = is_996 ? 19.7 : 12.2;  // body WIDTH, across (mm)
body_h   = is_996 ? 37.0 : 22.5;  // body HEIGHT from plate to the top face (mm),
                                  // NOT counting the output-shaft boss.
// Output shaft: where it sits and how thick it is. The shaft is offset from the
// body centre toward one end — measure that offset.
shaft_off_l = is_996 ? 9.0 : 5.0; // shaft offset from body-length centre (mm)
shaft_d     = is_996 ? 5.9 : 4.8; // output-spline diameter (mm). The pinion's
                                  // centre hole uses this + clearance; better
                                  // still, screw the pinion to a servo HORN.
// Mounting tabs (the flanged "ears" with screw holes, one each end lengthwise).
tab_span   = is_996 ? 49.5 : 32.0; // hole-centre to hole-centre, tab-to-tab (mm)
tab_hole_d = is_996 ? 3.2  : 2.2;  // tab screw CLEARANCE hole (mm)

// -- GEARS ---------------------------------------------------------------------
pinion_teeth = 12;      // teeth on the pinion. Fewer = jaws move MORE per servo
                        // degree (faster, weaker); more = slower, stronger.
gear_module  = 1.5;     // tooth size (mm). Same on pinion + rack so they fit.
                        // Tooth pitch works out to PI*module ~= 4.7 mm here.
pinion_h     = 8.0;     // pinion thickness (mm). A hair TALLER than rack_th so
                        // the pinion fully covers the rack teeth (no half-mesh).
mesh_tweak   = 0.0;     // fine nudge of both racks toward/away from the pinion
                        // (mm, +tighter). Start at 0; adjust after the hand-check
                        // if the teeth jam (raise clearance / lower this) or the
                        // gap is sloppy (raise this).

// -- RACKS + TRAVEL ------------------------------------------------------------
rack_len    = 34.0;     // length of each toothed bar (mm). Must comfortably fit
                        // jaw_travel PLUS a few teeth always engaged.
rack_th     = 6.0;      // rack thickness in Z (mm); keep <= pinion_h.
rack_body_w = 5.0;      // solid backing behind the rack teeth (mm) — the part the
                        // guide channel holds and the finger bolts to.
jaw_travel  = 12.0;     // how far EACH jaw moves closed<->open (mm). Total opening
                        // between the jaws changes by ~2x this.

// -- FINGERS (the jaws) --------------------------------------------------------
finger_len   = 36.0;    // how far each finger reaches FORWARD (+Y), past the gears
                        // to the gripping zone (mm). Must clear the pinion: keep
                        // it longer than the pitch diameter (module*teeth).
finger_width = 8.0;     // finger width across (mm).
finger_th    = 5.0;     // finger thickness — the gripping wall (mm).
finger_h     = 14.0;    // how tall the jaw stands in Z (mm) — the contact height.
wall         = 2.0;     // general wall thickness for the cradle + guides (mm).
clearance    = 0.25;    // print-fit gap for sliding/inserted parts (mm). PLA/PETG
                        // swell a little; 0.2-0.3 is a usual sliding fit.

// -- SOFT GRIP PADS (optional) -------------------------------------------------
tpu_pad     = true;     // true = recess a shallow pocket in each jaw's inner face
                        // so you can press in a soft TPU pad for grip + give.
pad_len     = 18.0;     // pad pocket length along the finger (mm)
pad_w       = 6.0;      // pad pocket width (mm)
pad_depth   = 1.5;      // pad pocket depth into the jaw face (mm)

// -- PREVIEW / PRINT quality ---------------------------------------------------
preview_open = true;    // preview only: draw the jaws OPEN (true) or CLOSED.
                        // Has no effect on the printed parts themselves.
$fn = 48;               // roundness of holes/cylinders in preview + render.


// =============================================================================
// DERIVED GEAR GEOMETRY — the tooth math, in one place.
// Simplified straight-flank teeth (see the HONEST note in the header).
// =============================================================================
function pitch_radius()   = gear_module * pinion_teeth / 2;      // rolling circle
function circ_pitch()     = PI * gear_module;                    // tooth spacing
function addendum()       = gear_module;                         // tooth stick-out
function dedendum()       = 1.25 * gear_module;                  // tooth root depth
function tooth_height()   = addendum() + dedendum();             // root -> tip
function tooth_base_w()   = circ_pitch() * 0.50;                 // wide at the root
function tooth_tip_w()    = circ_pitch() * 0.30;                 // narrower at tip

// One simplified tooth, drawn in 2D pointing +Y, its ROOT line on y = 0.
module tooth_2d() {
    polygon([
        [-tooth_base_w()/2, 0],
        [ tooth_base_w()/2, 0],
        [ tooth_tip_w()/2,  tooth_height()],
        [-tooth_tip_w()/2,  tooth_height()],
    ]);
}


// =============================================================================
// pinion() — the round gear the servo turns. Axis along Z, built from z = 0 up.
// Centre hole fits the output spline (or, better, a servo horn you screw to).
// =============================================================================
module pinion() {
    root_r = pitch_radius() - dedendum();   // body radius (base of the teeth)
    difference() {
        union() {
            cylinder(h = pinion_h, r = root_r);          // gear body
            for (i = [0 : pinion_teeth - 1])             // teeth around it
                rotate([0, 0, i * 360 / pinion_teeth])
                    translate([0, root_r, 0])
                        linear_extrude(pinion_h)
                            tooth_2d();
        }
        // centre bore for the servo spline (+clearance). Screw to a horn for the
        // real grip — a bare press-fit on the spline slips under gripping load.
        translate([0, 0, -0.5])
            cylinder(h = pinion_h + 1, d = shaft_d + clearance);
    }
}


// =============================================================================
// rack() — one straight toothed bar. Length along X, teeth on the +Y edge with
// their ROOT line on y = 0; solid backing on -Y. Built from z = 0 up.
// =============================================================================
module rack() {
    n = floor(rack_len / circ_pitch());      // how many whole teeth fit
    linear_extrude(rack_th) {
        // solid backing bar (behind the teeth, on -Y)
        translate([-rack_len/2, -rack_body_w, 0])
            square([rack_len, rack_body_w]);
        // the teeth, evenly spaced along X, centred on the bar
        for (i = [0 : n - 1])
            translate([-rack_len/2 + circ_pitch()/2 + i * circ_pitch(), 0, 0])
                tooth_2d();
    }
}


// =============================================================================
// finger() — one jaw: a wall that reaches FORWARD (+Y) from a rack and grips on
// its inner face. Optional TPU-pad pocket recessed into that inner face.
//   inner_x = which side is the gripping face (+1 grips toward +X, -1 toward -X)
// Built from z = 0 up; the caller lifts it to rack height.
// =============================================================================
module finger(inner_x = 1) {
    difference() {
        // the jaw blade: reaches +Y, stands up in Z
        translate([-finger_th/2, 0, 0])
            cube([finger_th, finger_len, finger_h]);

        // soft-pad pocket in the INNER face (the side that touches the object)
        if (tpu_pad)
            translate([inner_x * (finger_th/2 - pad_depth/2),
                       finger_len - pad_len - 2,
                       (finger_h - pad_w)/2])
                cube([pad_depth + 0.1, pad_len, pad_w], center = false);
    }
}


// =============================================================================
// servo_cradle() — a pocket that holds the servo body flat on the plate, shaft
// pointing UP (+Z), with clearance-fit walls and the two tab screw holes.
// The servo is placed so its OUTPUT SHAFT lands on the tool centreline at the
// pinion position (see gripper_mechanism for where that is).
// Built from z = 0 (plate top) up.
// =============================================================================
module servo_cradle() {
    // outer block that the body sits inside
    ox = body_w + 2 * wall;
    oy = body_l + 2 * wall;
    difference() {
        translate([-ox/2, -oy/2, 0])
            cube([ox, oy, body_h + wall]);           // walls up to the body top

        // the body pocket (clearance fit)
        translate([-(body_w + clearance)/2, -(body_l + clearance)/2, wall])
            cube([body_w + clearance, body_l + clearance, body_h + 1]);

        // open the TOP so the shaft/horn and the geartrain clear the cradle
        translate([-(body_w + clearance)/2, -(body_l + clearance)/2, body_h])
            cube([body_w + clearance, body_l + clearance, wall + 1]);

        // the two mounting-tab screw holes, on the body-length centreline
        for (ty = [-tab_span/2, tab_span/2])
            translate([0, ty, -0.5])
                cylinder(h = body_h + wall + 1, d = tab_hole_d);
    }
}


// =============================================================================
// rack_guide() — a low channel that keeps ONE rack sliding STRAIGHT along X and
// stops it lifting or twisting. A slot a touch taller/wider than the rack, open
// at both X ends so the rack can travel. Built at the rack's Z height.
// =============================================================================
module rack_guide(len) {
    slot_w = rack_body_w + clearance;      // across the backing (Y)
    slot_h = rack_th + clearance;          // rack thickness (Z)
    difference() {
        // the guide block
        translate([-len/2, -slot_w/2 - wall, -wall])
            cube([len, slot_w + 2 * wall, slot_h + 2 * wall]);
        // the through-slot the rack backing slides in
        translate([-len/2 - 0.5, -slot_w/2, 0])
            cube([len + 1, slot_w, slot_h]);
    }
}


// =============================================================================
// gripper_mechanism() — the pinion, the two racks, the two fingers, and the
// rack guides, all placed relative to the pinion centre at the local origin.
//   * pinion axis at local (0,0), turning about Z
//   * SOUTH rack at y = -pitch_radius (teeth up toward the pinion)
//   * NORTH rack at y = +pitch_radius (teeth down toward the pinion, rotated 180)
//   * the two racks therefore slide OPPOSITE ways when the pinion turns
// `open` shifts the jaws apart for preview only (0 = closed, 1 = open).
// =============================================================================
module gripper_mechanism(open = 0) {
    pr   = pitch_radius();
    jx   = open * jaw_travel;               // preview jaw shift along X
    guide_len = rack_len + jaw_travel + 4;  // guide covers the full travel

    // ---- the pinion, on the servo shaft ----
    pinion();

    // ---- SOUTH rack + its finger (the LEFT jaw) ----
    // teeth point +Y (up toward pinion); pitch line sits at y = -pr.
    translate([-jx, 0, 0]) {                        // open -> slides -X
        translate([0, -pr - dedendum() + mesh_tweak, 0])
            rack();
        // finger rises above the rack and reaches forward; grips toward +X
        translate([0, -pr, rack_th])
            finger(inner_x = 1);
    }
    // guide channel for the south rack (fixed to the base)
    translate([0, -pr - dedendum() - rack_body_w/2 + mesh_tweak, 0])
        rack_guide(guide_len);

    // ---- NORTH rack + its finger (the RIGHT jaw) ----
    // rotate the same rack 180 about Z: teeth now point -Y toward the pinion.
    translate([jx, 0, 0]) {                         // open -> slides +X
        translate([0, pr + dedendum() - mesh_tweak, 0])
            rotate([0, 0, 180])
                rack();
        // finger reaches forward; grips toward -X (mirror of the south jaw)
        translate([0, pr, rack_th])
            finger(inner_x = -1);
    }
    // guide channel for the north rack (fixed to the base)
    translate([0, pr + dedendum() + rack_body_w/2 - mesh_tweak, 0])
        rack_guide(guide_len);
}


// =============================================================================
// gripper() — THE FINISHED TOOL: the shared mount plate + servo cradle + the
// full rack-and-pinion mechanism, positioned forward of the horn screws so a
// screwdriver still reaches them (same courtesy as the magnet tool).
// =============================================================================
module gripper() {
    pr = pitch_radius();
    // push the whole mechanism forward of the two horn screws so they stay
    // reachable, and so the servo body clears the plate's back edge.
    mech_offset_y = body_l / 2 + 8;
    // reach the plate forward far enough to sit under the servo cradle + gears
    plate_reach = mech_offset_y + body_l / 2 + wall + 4;

    mount_plate(front = plate_reach);                       // shared interface

    // servo cradle: shaft must land at the pinion centre (mech_offset_y).
    // The shaft sits shaft_off_l from the body-length centre, so shift the body.
    translate([0, mech_offset_y - shaft_off_l, mount_top()])
        servo_cradle();

    // the geartrain, up on top of the servo (shaft pokes out the cradle top)
    translate([0, mech_offset_y, mount_top() + body_h + clearance])
        gripper_mechanism(open = preview_open ? 1 : 0);
}


// =============================================================================
// PREVIEW / RENDER — this IS the assembled tool. F5 preview, F6 render.
// A file that `use`s this library gets the modules (pinion, rack, finger,
// gripper, ...) but NOT this call, so nothing stray floats into it.
//
// PRINT ORIENTATION (read before slicing — it decides if the teeth survive)
//   FDM parts are WEAKEST between their layers. Gear teeth take their load
//   sideways (tooth pushing tooth), so:
//     * Print the PINION and both RACKS lying FLAT on the bed, so each tooth's
//       load runs IN-PLANE (along the layers), not across them. Teeth printed
//       standing UP shear off at the layer lines on the first hard grip.
//     * Print the FINGERS standing so the gripping load runs along the layers
//       too, or lay them flat and accept they're for gentle grips.
//   Use PETG (tougher, better layer bond) over PLA for these load-bearing gear
//   parts — PLA is stiff but snaps with no warning. (Echoes the idea file.)
//   You will likely print pinion, racks, fingers, and the plate/cradle as
//   SEPARATE oriented parts, not this one preview blob.
// =============================================================================
gripper();
