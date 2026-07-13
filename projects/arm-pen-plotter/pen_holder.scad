// ============================================================================
//  pen_holder.scad  --  compliant (floating) pen holder for the plotter arm
//  Part of: curious-research / projects/arm-pen-plotter
// ----------------------------------------------------------------------------
//  OWNER RENDERS THIS LOCALLY. OpenSCAD is a verified wall in the build
//  environment that generates these files -- there is no openscad/slicer here,
//  so this ships as .scad SOURCE ONLY. You open it in OpenSCAD, press F6, then
//  File > Export > STL, and slice it on your own machine. About a minute.
//  (Same rule as projects/tolerance-test-coin -- see docs/CAPABILITIES.md.)
//
//  SAFETY (repo rule): Claude designed this file. YOU slice it, YOU load the
//  filament, YOU start the print and watch it. Nothing here is "safe to print
//  unattended".
// ----------------------------------------------------------------------------
//  WHAT THIS IS  --  and why it "floats"
//  A carriage that clips onto the arm's end (a common 9g-servo horn, or any
//  flat mount) and holds a pen in a sleeve that can SLIDE UP AND DOWN a few
//  millimetres against gravity (and, optionally, a light printed spring).
//
//  Why bother? A hobby arm can never hold the pen at a perfectly constant
//  height -- the paper is never dead level to the arm base, and every joint
//  has a little slop. A rigid pen would dig in on one corner of the page and
//  float off the paper on the opposite corner. A FLOATING pen rides those
//  bumps: gravity keeps light, even pressure on the tip across an uneven
//  surface. This is the "compliance" the idea file asked for -- and this
//  printed part is the physical bridge between your printer and your arm.
//
//  bench words:
//    compliance / float = the holder gives a few mm so pen pressure stays even.
//    travel             = how far the pen sleeve can slide up/down (mm).
//    servo horn         = the little splined arm that bolts onto a servo output.
//
//  TWO FLOAT MODES (set float_mode below):
//    "gravity" = the pen's own weight is the down-force. Simplest; the
//                Robertleoj arm proved "the weight of the pen is enough".
//    "spring"  = adds a thin printed serpentine flexure that pushes the pen
//                down gently, so a very light pen still presses evenly. Print
//                the flexure in the SAME part; it flexes because it is thin.
// ============================================================================

/* ============================  EDIT THESE  =============================== */

pen_d        = 9.0;    // pen barrel diameter (mm). A Sharpie is ~9; a Bic ~8;
                       // measure YOUR pen with calipers and set it here.
pen_clear    = 0.4;    // clearance so the pen slides freely in the sleeve (mm,
                       // per side). Use your tolerance-test-coin number if you
                       // have one; 0.4 is a safe loose-ish start.
grip_screw_d = 3.2;    // clearance hole for the side thumb-screw that pinches
                       // the pen at the right height (M3 = 3.2). Set 0 to omit.

travel       = 8.0;    // how far the pen sleeve can float up/down (mm).
sleeve_len   = 34.0;   // length of the pen sleeve (mm) -- longer = steadier pen.
wall         = 2.4;    // wall thickness everywhere (mm). >=2.0 prints strong.

float_mode   = "gravity";  // "gravity" or "spring"  (see notes above)

// --- printed spring (only used when float_mode == "spring") --------------
spring_turns = 3;      // number of serpentine bends in the flexure
spring_th    = 1.0;    // flexure thickness (mm). Thinner = softer push. Keep
                       // >= your nozzle width so it prints as a solid ribbon.
spring_w     = 6.0;    // flexure width (mm)

// --- the mount that clips to the arm end ---------------------------------
mount_mode   = "horn"; // "horn" = holes for a generic 9g servo horn (2 screws)
                       // "flat" = a plain flat tab with two M3 holes you drill
                       //          into whatever bracket you already have.
horn_screw_d = 2.2;    // servo-horn screw clearance (M2 self-tapper ~2.2 mm)
horn_span    = 16.0;   // centre-to-centre of the two horn screws (mm) -- measure
                       // YOUR horn; 16 is typical for a 9g single-arm horn.
mount_th     = 3.0;    // mount plate thickness (mm)

$fn          = 64;     // roundness of circles -- higher = smoother, slower

/* =====================  (you rarely edit below here)  ==================== */

sleeve_or = pen_d/2 + pen_clear + wall;      // sleeve outer radius
sleeve_ir = pen_d/2 + pen_clear;             // sleeve inner (bore) radius
rail_len  = sleeve_len + travel + wall;      // outer rail the sleeve floats in
rail_or   = sleeve_or + pen_clear + wall;    // outer rail outer radius
rail_ir   = sleeve_or + pen_clear;           // outer rail inner radius (gap)

// ---- the pen sleeve: a tube the pen sits in, with a side pinch screw -----
module pen_sleeve() {
    difference() {
        cylinder(h = sleeve_len, r = sleeve_or);
        // pen bore, all the way through
        translate([0, 0, -0.5])
            cylinder(h = sleeve_len + 1, r = sleeve_ir);
        // side thumb-screw hole to pinch the pen at a chosen height
        if (grip_screw_d > 0)
            translate([0, 0, sleeve_len * 0.5])
                rotate([0, 90, 0])
                    cylinder(h = sleeve_or + 2, r = grip_screw_d/2);
        // a slit down one side so the pinch screw can actually squeeze the bore
        if (grip_screw_d > 0)
            translate([sleeve_ir - 0.2, -0.6, sleeve_len*0.2])
                cube([wall + 1.2, 1.2, sleeve_len*0.7]);
    }
    // a small collar/flange at the top so the sleeve can't fall through the rail
    translate([0, 0, sleeve_len - wall])
        cylinder(h = wall, r = rail_ir - 0.15);
}

// ---- the outer rail: a sheath the sleeve slides up/down inside -----------
module float_rail() {
    difference() {
        cylinder(h = rail_len, r = rail_or);
        // the bore the sleeve floats in
        translate([0, 0, wall])
            cylinder(h = rail_len, r = rail_ir);
        // open the bottom mouth so the pen tip pokes out
        translate([0, 0, -0.5])
            cylinder(h = wall + 0.5, r = sleeve_ir + 0.4);
    }
}

// ---- the printed serpentine flexure ("spring") ---------------------------
//  A thin ribbon that folds back and forth. Because it is thin it flexes,
//  giving a gentle downward push on the sleeve. Printed flat between the
//  rail top and a cap; it compresses as the sleeve floats up.
module flexure() {
    step = travel / max(spring_turns, 1);
    for (i = [0 : spring_turns - 1]) {
        // alternate the bends left/right to make a serpentine
        y = (i % 2 == 0) ? spring_w/2 : -spring_w/2;
        translate([0, y - sign(y)*spring_w/2, i*step])
            cube([spring_w, spring_th, step + 0.01], center = false);
        // short cross-links joining the bends
        translate([0, -spring_w/2, i*step])
            cube([spring_w, spring_w, spring_th], center = false);
    }
}

// ---- the mount that clips to the arm's end -------------------------------
module arm_mount() {
    if (mount_mode == "horn") {
        difference() {
            // a plate wide enough to span the two horn screws
            translate([-(horn_span/2 + 6), -8, 0])
                cube([horn_span + 12, 16, mount_th]);
            // two horn screw holes
            for (sx = [-horn_span/2, horn_span/2])
                translate([sx, 0, -0.5])
                    cylinder(h = mount_th + 1, r = horn_screw_d/2);
        }
    } else {   // "flat"
        difference() {
            translate([-14, -8, 0]) cube([28, 16, mount_th]);
            for (sx = [-9, 9])
                translate([sx, 0, -0.5])
                    cylinder(h = mount_th + 1, r = 1.6);  // M3 pilot, drill out
        }
    }
}

// ---- assemble everything -------------------------------------------------
module pen_holder() {
    // the floating rail stands up from the mount plate
    union() {
        arm_mount();
        translate([0, 0, mount_th]) float_rail();
        // the spring cap + flexure sit on top of the rail in spring mode
        if (float_mode == "spring") {
            translate([0, 0, mount_th + rail_len])
                cylinder(h = wall, r = rail_or);      // cap
            translate([0, 0, mount_th + rail_len - travel])
                flexure();
        }
    }
    // The pen sleeve is printed SEPARATELY (it must be a loose, sliding part) --
    // laid down beside the rail so it prints in the same job without fusing.
    translate([rail_or + sleeve_or + 6, 0, 0])
        pen_sleeve();
}

pen_holder();

echo(str("float_mode=", float_mode, "  pen_d=", pen_d,
         "  travel=", travel, "  mount=", mount_mode));

// ============================================================================
//  PRINT NOTES
//   * Two loose parts: the rail-with-mount, and the pen sleeve beside it. They
//     print unfused; after printing, drop the sleeve into the rail -- it should
//     slide up/down `travel` mm freely. If it's tight, raise pen_clear a touch.
//   * "gravity" mode needs no spring -- the pen's weight is the down-force.
//     Start here. Add "spring" mode only if a light pen skips on the paper.
//   * Orientation: print the rail STANDING UP (bore vertical) for a round bore,
//     or on its side with supports if your printer bridges poorly.
//   * Fit the pen, pinch the side screw at a height where the tip pokes ~2-3 mm
//     below the rail mouth at rest, then teach your pen-down waypoint from there.
//  Full walkthrough: projects/arm-pen-plotter/README.md
// ============================================================================
