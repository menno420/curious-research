// =============================================================================
// magnet_tool.scad — a PASSIVE magnet-pickup tool for the robot arm
// =============================================================================
//
// WHAT THIS IS
//   The first tool built on the shared mount standard. It's the standard plate
//   (from mount_standard.scad) with a little cup on top that holds one round
//   neodymium magnet. The arm carries it to a small steel/iron part, the magnet
//   grabs it, the arm moves it, and you pull the part off by hand at the far end.
//   There are NO servos, NO wires, NO electronics — the magnet does all the work
//   and holds even with the arm powered off. Passive does NOT mean risk-free:
//   the magnet can pinch, attract unexpected metal, damage sensitive items or
//   drop a load. Test the exact magnet, part and orientation before any lift.
//
// HOW TO USE IT (makers)
//   1. Keep this file in the SAME folder as mount_standard.scad (it pulls it in).
//   2. Measure your magnet + servo horn, edit the parameters below.
//   3. Press F5 to preview, F6 to render, then export/slice and print.
//   4. Press-fit the magnet into the cup (fit + glue note in the README).
//
// NO RENDERER HERE — authored with no OpenSCAD installed, so this has NOT been
//   rendered or sliced. You render (F6), slice, load, start, and watch. Any
//   "it lifts fine" is YOUR call to verify.
//
// SAFETY (arm rails + lifting)
//   No motion code lives here. This passive model cannot guarantee arm startup
//   or motion safety; powered use needs a reviewed route and supervision. A lift is load-bearing:
//   CHECK THE MAGNET HOLDS YOUR PART — at the height and speed you'll use —
//   BEFORE trusting the arm to carry it. Neodymium magnets are brittle and pinch
//   skin; keep them away from cards, drives, and pacemakers.
// =============================================================================

use <mount_standard.scad>


// ---- BENCH WORDS ------------------------------------------------------------
// neodymium disc : a small, very strong round magnet, sold as "D x H", e.g.
//                  "12 x 3 mm". Cheap in bags of 10-20.
// press-fit      : a pocket a hair SMALLER than the magnet so it wedges in and
//                  stays with no glue. Loose? A drop of glue fixes it.
// payload        : the load this exact arm/tool combination can carry under the
//                  tested conditions. No payload value is established here.


// =============================================================================
// MAGNET PARAMETERS — measure YOUR magnet, then edit. Each in its own note.
// =============================================================================

// -- Magnet size (calipers, or read the bag label "D x H") --
magnet_d      = 12.0;   // magnet DIAMETER (mm). Common discs: 10, 12, 15, 20.
magnet_h      =  3.0;   // magnet HEIGHT / thickness (mm).

// -- Press-fit tightness --
magnet_fit    = 0.15;   // EXPERIMENTAL: amount subtracted from magnet_d (mm).
                        // Larger positive = SMALLER/tighter pocket. Won't go in?
                        // Lower this value. Too loose? Raise it in small steps or
                        // use a separately validated retention method.

// -- Cup + stem --
cup_wall      = 1.8;    // wall thickness around the magnet (mm).
cup_floor     = 1.2;    // solid floor UNDER the magnet (mm). Keep this: the pull
                        // goes through plastic, so no metal-on-metal clack and the
                        // magnet can't fall through.
stem_h        = 5.0;    // how far the cup stands off the plate (mm). Taller reaches
                        // into tighter spots; shorter is stiffer.
magnet_offset_y = 12.0; // how far FORWARD of the horn screws the cup sits (mm).
                        // Forward keeps the two mounting screws reachable with a
                        // screwdriver and puts the pickup point where you can see
                        // it. Don't go below ~11 or the cup covers the screws.

// -- Print quality --
$fn = 64;


// =============================================================================
// magnet_cup() — the cup that holds the magnet. Pocket opens UPWARD (+Z), with a
// solid floor beneath. Built from Z = 0 up; lifted onto the plate by magnet_tool.
// =============================================================================
module magnet_cup() {
    cup_od   = magnet_d + 2 * cup_wall;   // outer diameter of the cup
    pocket_d = magnet_d - magnet_fit;     // press-fit pocket (a touch smaller)
    difference() {
        cylinder(h = cup_floor + magnet_h, d = cup_od);   // solid cup body
        translate([0, 0, cup_floor])                       // the magnet pocket
            cylinder(h = magnet_h + 0.5, d = pocket_d);
    }
}


// =============================================================================
// cup_on_stem() — the magnet cup lifted on a short tapered stem.
// =============================================================================
module cup_on_stem() {
    cup_od = magnet_d + 2 * cup_wall;
    // tapered stem blends the wide plate up to the cup (prints without supports)
    cylinder(h = stem_h, d1 = cup_od + 3, d2 = cup_od);
    translate([0, 0, stem_h])
        magnet_cup();
}


// =============================================================================
// magnet_tool() — the finished part: shared plate + magnet cup, forward of the
// screws so a screwdriver can still reach the two mounting screws.
// =============================================================================
module magnet_tool() {
    cup_od      = magnet_d + 2 * cup_wall;
    // reach the plate forward far enough to fully support the cup
    plate_reach = magnet_offset_y + cup_od / 2 + 2;

    mount_plate(front = plate_reach);          // the shared interface plate

    translate([0, magnet_offset_y, mount_top()])
        cup_on_stem();                          // the magnet cup, out front
}


// =============================================================================
// PREVIEW / RENDER — this IS the finished part. F5 preview, F6 render, slice.
// =============================================================================
magnet_tool();
