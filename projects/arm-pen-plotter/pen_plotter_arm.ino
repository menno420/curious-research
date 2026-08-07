// ============================================================================
//  pen_plotter_arm.ino  --  Arduino sketch for the 6-servo pen-plotter arm
//  Part of: curious-research / projects/arm-pen-plotter
// ----------------------------------------------------------------------------
//  WHAT THIS DOES
//  Listens on the USB serial line for two simple text commands from the laptop
//  (from teach_and_replay.py) and drives the six arm servos. It ALSO clamps
//  every normal command on-board against numeric per-joint limits received
//  from the laptop. This is a second numeric guard, not collision detection;
//  setup() still writes before those limits exist.
//
//  THE TWO COMMANDS (plain text, one per line, ending in newline '\n'):
//    L,<i>,<min>,<max>   Set measured limits for joint <i> (0..5), in degrees.
//                        The laptop sends these six lines at handshake, before
//                        controlled S commands. Until a joint has received its
//                        limits, S commands are refused. IMPORTANT: setup()
//                        still attaches every servo and writes 90 degrees once;
//                        a board reset can therefore cause startup movement
//                        before this handshake. Read the project README.
//    S,<i>,<angle>       Move joint <i> to <angle> degrees. The board clamps
//                        <angle> to that joint's [min,max] before writing it.
//
//  Every accepted command is echoed back on serial (e.g. "OK S,1,95") so the
//  laptop can see what actually happened -- including a clamp ("CLAMP S,1,120").
//
// ----------------------------------------------------------------------------
//  WIRING  --  READ THIS BEFORE YOU CONNECT ANYTHING (binding safety rule)
//
//    SERVO POWER IS A SEPARATE, EXTERNAL SUPPLY. NEVER THE ARDUINO'S 5 V PIN.
//
//    * Use a dedicated supply within the ACTUAL servo model's voltage range,
//      sized for representative peak load -- a stalling servo draws
//      far more current than the Arduino's onboard regulator can give. Powering
//      servos from the Arduino 5 V pin can cause voltage drop, resets, damage
//      or unpredictable behaviour.
//
//      SIZE THIS FOR THE ACTUAL SERVOS. "MG996R-class" does not identify an
//      exact manufacturer or electrical specification. Record the real model,
//      use its primary datasheet where available, and measure current under a
//      supervised representative load. The combined peak/stall current and a
//      suitable supply rating have not yet been verified for this arm.
//    * SHARED GROUND: the servo supply's ground (-) MUST connect to the
//      controller GND in the conventional wiring shown. Without a shared
//      reference the control signal is not reliably defined; do not diagnose
//      every twitch as a ground fault without measuring.
//    * FUSE the servo supply's positive lead. Size the fuse to YOUR servos and
//      YOUR supply -- above the current the arm actually draws while moving,
//      below what the wiring and supply can safely deliver. Select fuse type
//      and rating from the measured load, wire capacity and exact supply; this
//      repository does not yet contain enough verified data to prescribe one.
//      CHECK THIS YOURSELF before first power-up -- see CLAUDE.md section 2.
//    * A REACHABLE POWER SWITCH on the servo supply, within arm's reach, so you
//      can cut motor power instantly WITHOUT unplugging the USB.
//    * The six pin numbers below are legacy placeholders, not a verified map
//      of the owned controller or physical axes. Confirm board, pin support,
//      physical joint order and direction before power. Servo + (red) goes
//      to the EXTERNAL supply +, servo - (brown/black) to the shared ground.
//
//         Arduino GND  ------+------------------  Servo supply (-)
//                            |
//         (shared ground)    +--  each servo (-)
//
//         Servo supply (+) --[FUSE]--[SWITCH]--  each servo (+)
//
//         Controller pin 3  ---------------------  software joint index 0
//         Controller pin 5  ---------------------  software joint index 1
//         Controller pin 6  ---------------------  software joint index 2
//         Controller pin 9  ---------------------  software joint index 3
//         Controller pin 10 ---------------------  software joint index 4
//         Controller pin 11 ---------------------  software joint index 5
//
//    CHECK THIS YOURSELF: the fuse, the shared ground, and the reachable switch
//    are load/​power items -- verify them on your own bench before energizing.
//    A human watches every powered move, hand on the switch. Nothing here is
//    ever "safe unattended".
// ============================================================================

#include <Servo.h>

// Six legacy software indices, in the SAME order the laptop uses (0..5).
// Their physical axis names and controller mapping still need confirmation.
const int NUM_JOINTS = 6;

// Signal pins for each joint, index-aligned with the order above.
const int SERVO_PINS[NUM_JOINTS] = { 3, 5, 6, 9, 10, 11 };

Servo servos[NUM_JOINTS];

// Per-joint measured limits, in degrees. Filled by the "L" handshake command.
// Fallbacks (90..90) block later S commands from sweeping before limits arrive.
// They do NOT prove that 90 degrees is safe for this arm: setup() commands that
// angle once when each servo is attached.
int jointMin[NUM_JOINTS];
int jointMax[NUM_JOINTS];
bool jointReady[NUM_JOINTS];   // true once this joint has received its limits

// Serial line buffer.
const int BUF_LEN = 48;
char buf[BUF_LEN];
int bufPos = 0;

// ---- the clamp: identical idea to the Python side -------------------------
int clampAngle(int value, int lo, int hi) {
  if (value < lo) return lo;
  if (value > hi) return hi;
  return value;
}

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < NUM_JOINTS; i++) {
    servos[i].attach(SERVO_PINS[i]);
    // Known startup limitation: attaching and writing 90 may move the physical
    // joint before measured limits arrive. "Neutral" is a protocol default,
    // not a verified safe pose for this arm. Keep servo power off during reset
    // and read the supervised startup procedure in the README.
    jointMin[i] = 90;
    jointMax[i] = 90;
    jointReady[i] = false;
    servos[i].write(90);
  }

  Serial.println("READY pen_plotter_arm -- send L limits, then S moves.");
}

void loop() {
  // Read one full line (up to '\n'), then handle it.
  while (Serial.available() > 0) {
    char c = (char)Serial.read();
    if (c == '\n' || c == '\r') {
      if (bufPos > 0) {
        buf[bufPos] = '\0';
        handleLine(buf);
        bufPos = 0;
      }
    } else if (bufPos < BUF_LEN - 1) {
      buf[bufPos++] = c;
    } else {
      // Overlong garbage line -- drop it rather than overflow the buffer.
      bufPos = 0;
      Serial.println("ERR line too long");
    }
  }
}

void handleLine(char *line) {
  // Commands look like "L,0,20,120" or "S,1,95". Split on commas.
  char cmd = line[0];

  if (cmd == 'L') {
    int idx, lo, hi;
    // Expect exactly: L,<idx>,<min>,<max>
    if (sscanf(line, "L,%d,%d,%d", &idx, &lo, &hi) == 3) {
      if (idx >= 0 && idx < NUM_JOINTS && lo <= hi) {
        jointMin[idx] = lo;
        jointMax[idx] = hi;
        jointReady[idx] = true;
        Serial.print("OK L,");
        Serial.print(idx); Serial.print(","); Serial.print(lo);
        Serial.print(","); Serial.println(hi);
      } else {
        Serial.println("ERR L bad index or min>max");
      }
    } else {
      Serial.println("ERR L parse");
    }
    return;
  }

  if (cmd == 'S') {
    int idx, angle;
    // Expect exactly: S,<idx>,<angle>
    if (sscanf(line, "S,%d,%d", &idx, &angle) == 2) {
      if (idx < 0 || idx >= NUM_JOINTS) {
        Serial.println("ERR S bad index");
        return;
      }
      if (!jointReady[idx]) {
        // No measured limits yet -> refuse this controlled S command. This
        // does not undo the one 90-degree command issued in setup().
        Serial.print("ERR S joint ");
        Serial.print(idx);
        Serial.println(" has no limits yet (send L first)");
        return;
      }
      // DEFENSE IN DEPTH: clamp on-board too, regardless of what the laptop sent.
      int bounded = clampAngle(angle, jointMin[idx], jointMax[idx]);
      servos[idx].write(bounded);
      if (bounded != angle) {
        Serial.print("CLAMP S,");
        Serial.print(idx); Serial.print(","); Serial.print(bounded);
        Serial.print(" (asked "); Serial.print(angle); Serial.println(")");
      } else {
        Serial.print("OK S,");
        Serial.print(idx); Serial.print(","); Serial.println(bounded);
      }
    } else {
      Serial.println("ERR S parse");
    }
    return;
  }

  Serial.println("ERR unknown command");
}
