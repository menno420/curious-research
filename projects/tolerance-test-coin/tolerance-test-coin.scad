// ============================================================================
//  tolerance-test-coin.scad  —  parametric clearance / tolerance test
//  Part of: curious-research / projects/tolerance-test-coin
// ----------------------------------------------------------------------------
//  WHAT THIS IS
//  A small round "coin" full of holes. Every hole is the same shape but a
//  slightly bigger gap (clearance) than the last. You print the coin plus a
//  few matching loose "pins", then push ONE pin through each hole and feel the
//  fit: which hole grips (press fit), which slides, which is loose. The number
//  engraved next to the best-feeling hole is YOUR printer's real clearance
//  number -- reuse it in every future design that has to fit together.
//
//  "clearance" = the deliberate air gap left between two parts so they fit.
//  It is measured PER SIDE here: a hole labelled 0.20 has 0.20 mm of gap on
//  every side, so the two sides add up to 0.40 mm across the diameter -- the
//  classic gotcha (see the guide, step 11).
//
//  SAFETY (repo rule): Claude designed this file. YOU slice it, YOU load the
//  filament, YOU start the print and watch it. Nothing here is "safe to print
//  unattended".
// ============================================================================

/* =====================  EDIT THESE -- everything is parametric  =========== */

pin_d      = 5.0;    // diameter of the standard test pin (mm)
clear_min  = 0.10;   // smallest radial clearance to test (mm, per side)
clear_max  = 0.50;   // largest  radial clearance to test (mm, per side)
clear_step = 0.05;   // gap between tested clearances (mm)

coin_h     = 4.0;    // coin thickness = how deep each hole is (mm)
pin_len    = 14.0;   // length of the loose test pins (mm) -- longer than the
                     // coin so you have something to grip
n_pins     = 3;      // how many loose pins to print alongside the coin

wall       = 3.0;    // solid coin material around/between the holes (mm)
label_h    = 0.8;    // how deep the engraved numbers cut into the coin (mm)
label_size = 3.0;    // engraved number text height (mm)
chamfer    = 0.6;    // funnel at each hole mouth so the pin starts easily (mm)

$fn        = 64;     // roundness of every circle -- higher = smoother, slower

/* =====================  (you rarely need to touch below)  ================= */

// --- derive the list of clearances to test -------------------------------
steps      = floor((clear_max - clear_min) / clear_step + 0.5) + 1;
clearances = [ for (i = [0:steps-1]) clear_min + i*clear_step ];

// --- grid layout for the holes -------------------------------------------
cols   = ceil(sqrt(steps));                       // roughly square grid
rows   = ceil(steps / cols);
cell   = pin_d + 2*clear_max + wall;              // centre-to-centre spacing
grid_w = cols * cell;
grid_h = rows * cell;
coin_r = 0.5 * sqrt(grid_w*grid_w + grid_h*grid_h) + wall; // enclosing disc

// Format a clearance like 0.20 as the string "0.20" (assumes 0 <= c < 1).
function fmt(c) = let (h = floor(c*100 + 0.5))
                 str("0.", h < 10 ? str("0", h) : h);

echo(str("Testing ", steps, " clearances: ", clearances));

// --- the coin ------------------------------------------------------------
module coin() {
    difference() {
        cylinder(h = coin_h, r = coin_r);            // the disc

        for (i = [0:steps-1]) {
            c   = clearances[i];
            hr  = pin_d/2 + c;                        // hole radius for this test
            col = i % cols;
            row = floor(i / cols);
            x   = (col - (cols-1)/2) * cell;
            y   = ((rows-1)/2 - row) * cell;

            // the through-hole (goes all the way through so you can push the
            // pin out the bottom by hand)
            translate([x, y, -0.5])
                cylinder(h = coin_h + 1, r = hr);

            // funnel the top mouth so the pin finds the hole
            translate([x, y, coin_h - chamfer])
                cylinder(h = chamfer + 0.01, r1 = hr, r2 = hr + chamfer);

            // engrave the clearance value beneath the hole
            translate([x, y - hr - label_size*0.75, coin_h - label_h])
                linear_extrude(height = label_h + 0.01)
                    text(fmt(c), size = label_size, halign = "center",
                         valign = "center",
                         font = "Liberation Sans:style=Bold");
        }
    }
}

// --- the loose test pins (all the same diameter = pin_d) ------------------
module pins() {
    for (j = [0:n_pins-1])
        translate([coin_r + wall + pin_d/2 + j*(pin_d + 3), 0, 0])
            union() {
                cylinder(h = pin_len - chamfer, r = pin_d/2);
                // small lead-in chamfer on the tip so it starts into a hole
                translate([0, 0, pin_len - chamfer])
                    cylinder(h = chamfer, r1 = pin_d/2, r2 = pin_d/2 - chamfer*0.6);
            }
}

coin();
pins();

// ============================================================================
//  REUSE YOUR NUMBER -- the whole point of this coin
//  Once you know your snug gap, set it ONCE and every future hole uses it:
//
//      clearance = 0.20;   // YOUR snug number (per side) from the test
//      module shaft_hole(shaft_r, depth) {
//          cylinder(h = depth, r = shaft_r + clearance);
//      }
//
//  Change printer or filament later? Change that one line. Full walkthrough:
//  projects/tolerance-test-coin/print-and-test-guide.md
// ============================================================================
