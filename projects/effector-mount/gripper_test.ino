// ============================================================================
//  gripper_test.ino  --  BENCH test for the gripper's ONE servo, alone
//  Part of: curious-research / projects/effector-mount
// ----------------------------------------------------------------------------
//  WHAT THIS IS  --  AND WHAT IT IS NOT
//  A tiny bench sketch to exercise the gripper's SINGLE servo on the BENCH,
//  BY ITSELF, so you can find its open and closed positions and watch the jaws
//  move before you ever trust them on anything. It sweeps the servo slowly
//  between an OPEN pulse and a CLOSE pulse, pausing at each end, forever.
//
//  THIS IS NOT ARM MOTION CODE. It drives one servo on a breadboard, not the
//  arm. Do NOT graft this onto the 6-servo arm.
//    * Arm-mounted use MUST go through the CLAMPED path:
//        projects/arm-pen-plotter/teach_and_replay.py  (the laptop side)
//        projects/arm-pen-plotter/pen_plotter_arm.ino  (the board side)
//      driven against  arm/calibration.json  (your measured safe envelope).
//      In that path the gripper is joint index 5, and EVERY angle passes
//      through clamp() before it can reach a motor. A raw servo write like the
//      one in THIS sketch has no envelope behind it — that is exactly why it
//      stays on the bench and off the arm.
//    * The repository's controlled arm workflow requires arm/calibration.json.
//      That does not guarantee that other sketches or board startup cannot move
//      hardware. This bench sketch needs separate, measured gripper limits.
//
//  HOW TO USE IT (makers)
//    1. Wire ONE servo per the WIRING block below (external fused supply!).
//    2. Set GRIP_OPEN_US and GRIP_CLOSE_US to numbers YOU measured (see below).
//    3. Upload, open Serial Monitor at 115200 baud, READ the banner, keep a
//       hand on the power switch, and watch the jaws sweep.
// ----------------------------------------------------------------------------
//  WIRING  --  READ THIS BEFORE YOU CONNECT ANYTHING (binding safety rule)
//
//    SERVO POWER IS A SEPARATE, EXTERNAL, FUSED SUPPLY. NEVER THE ARDUINO 5 V PIN.
//
//    A gripper servo CAN STALL if commanded farther than the jaws or object can
//    move. A stalling servo draws far more current than the Arduino regulator
//    can give — powering it from the 5 V pin browns out the board (it resets or
//    acts drunk) or fries it outright.
//
//    * Use a dedicated supply within the ACTUAL servo's voltage range and size
//      it from that exact model's specification plus a supervised measurement.
//    * FUSE the positive lead. Choose the fuse from measured current, supply
//      capability and wire capacity; no universal rating is asserted here.
//    * A REACHABLE POWER SWITCH on the servo supply, within arm's reach, so you
//      can cut motor power instantly WITHOUT unplugging the USB.
//    * SHARED GROUND: the servo supply's (-) MUST connect to the Arduino GND, or
//      the signal has no common reference and the servo twitches randomly.
//
//        Arduino GND  ------+------------------  Servo supply (-)
//                           |
//        (shared ground)    +--  servo (-)  (brown/black)
//
//        Servo supply (+) --[FUSE]--[SWITCH]--  servo (+)  (red)
//
//        Arduino pin 9  ------------------------  servo signal (orange/yellow)
//
//    CHECK THIS YOURSELF: the fuse, the shared ground, and the reachable switch
//    are power items — verify them on your own bench before energizing. A human
//    watches every powered move, hand on the switch. Nothing here is ever "safe
//    unattended". Cut power first, ask questions after.
// ============================================================================

#include <Servo.h>

// ---- The signal pin the servo listens on (power comes from the EXTERNAL supply) ----
const int SERVO_PIN = 9;

// ============================================================================
//  THE TWO NUMBERS YOU MEASURE  --  in MICROSECONDS of pulse width.
//  A hobby servo reads repeated control pulses, but its accepted pulse range is
//  model-specific. Do NOT assume a universal 500..2500 us range. The exact pulse
//  for "jaws just open" and "jaws just touching" depends on YOUR
//  servo, YOUR pinion, and how you clocked the horn on the shaft — so YOU find
//  them, once, by hand. There is no universal value.
//
//  HOW TO FIND THEM SAFELY (power OFF between tries, tiny steps):
//    1. Start both equal to GRIP_MID_US (below) so the servo just centres.
//    2. Power on, watch, note where the jaws are. Power OFF.
//    3. Nudge one value by ~25 us, power on, look, power OFF. Repeat.
//    4. GRIP_OPEN_US  = the pulse where the jaws are open as wide as you need.
//    5. GRIP_CLOSE_US = the pulse where the jaws JUST MEET / just touch your
//       object -- and NO FURTHER. Do NOT drive them harder into a closed stall:
//       a stalled servo can overheat or damage its gears.
//    6. Record the values with the exact servo and mechanism revision; recheck
//       after mechanical changes.
//
//  The starting values below are UNVERIFIED placeholders near nominal centre.
//  They can still cause motion or a jam on your mechanism. REPLACE them with
//  values established by a supervised incremental bench test.
// ============================================================================
const int GRIP_MID_US   = 1500;   // placeholder only; NOT a proven centre
const int GRIP_OPEN_US  = 1300;   // <-- MEASURE: pulse for "jaws open"
const int GRIP_CLOSE_US = 1600;   // <-- MEASURE: pulse for "jaws just meet"
                                  //     (set so they TOUCH, never stall harder)

// ---- Sweep gentleness. Small step + short delay = slow, watchable motion. ----
const int SWEEP_STEP_US  = 4;      // microseconds moved per step (smaller = slower)
const int SWEEP_DELAY_MS = 12;     // pause between steps (bigger = slower)
const int END_PAUSE_MS   = 1200;   // pause at each end (open / closed)

Servo gripper;
int currentUs = GRIP_MID_US;       // where we believe the servo is, in us

// ---- Ease from currentUs to targetUs in small steps, so motion is gentle. ----
void sweepTo(int targetUs) {
  int step = (targetUs >= currentUs) ? SWEEP_STEP_US : -SWEEP_STEP_US;
  while ((step > 0 && currentUs < targetUs) ||
         (step < 0 && currentUs > targetUs)) {
    currentUs += step;
    // don't overshoot the target on the final step
    if ((step > 0 && currentUs > targetUs) ||
        (step < 0 && currentUs < targetUs)) {
      currentUs = targetUs;
    }
    gripper.writeMicroseconds(currentUs);
    delay(SWEEP_DELAY_MS);
  }
  currentUs = targetUs;
}

void printBanner() {
  String line = "==========================================================================";
  Serial.println(line);
  Serial.println("  GRIPPER BENCH TEST  --  ONE servo, on the bench, NOT on the arm.");
  Serial.println(line);
  Serial.println("  BEFORE you let this run:");
  Serial.println("   * SERVO POWER = a SEPARATE, FUSED supply within the ACTUAL servo");
  Serial.println("     voltage range, sized from its spec and measurement; ground shared to");
  Serial.println("     Arduino GND, with a REACHABLE switch. NEVER the Arduino's 5 V pin --");
  Serial.println("     a gripping servo stalls and browns out or fries the board.");
  Serial.println("   * KEEP A HAND ON THE POWER SWITCH. Watch every sweep. If it buzzes,");
  Serial.println("     smells hot, or jams closed, CUT POWER FIRST, ask questions after.");
  Serial.println("   * BENCH ONLY. This drives one servo. It is NOT arm motion code --");
  Serial.println("     arm-mounted use goes through the clamped teach_and_replay.py path");
  Serial.println("     against a measured arm/calibration.json. That is separate from this test.");
  Serial.println("   * Set GRIP_CLOSE_US so the jaws JUST MEET -- never a hard stall.");
  Serial.println(line);
  Serial.print("  open pulse  = "); Serial.print(GRIP_OPEN_US);  Serial.println(" us");
  Serial.print("  close pulse = "); Serial.print(GRIP_CLOSE_US); Serial.println(" us");
  Serial.println(line);
}

void setup() {
  Serial.begin(115200);
  // A short wait so the Serial Monitor catches the banner from a fresh open.
  delay(600);
  printBanner();

  gripper.attach(SERVO_PIN);
  // This immediately commands the UNVERIFIED centre placeholder. It may move.
  currentUs = GRIP_MID_US;
  gripper.writeMicroseconds(currentUs);
  delay(END_PAUSE_MS);
}

void loop() {
  Serial.println("  -> opening");
  sweepTo(GRIP_OPEN_US);
  delay(END_PAUSE_MS);

  Serial.println("  -> closing (to JUST meet -- watch it, hand on the switch)");
  sweepTo(GRIP_CLOSE_US);
  delay(END_PAUSE_MS);
}
