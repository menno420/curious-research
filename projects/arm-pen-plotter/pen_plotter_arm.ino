// ============================================================================
//  pen_plotter_arm.ino  --  Arduino sketch for the 6-servo pen-plotter arm
//  Part of: curious-research / projects/arm-pen-plotter
// ----------------------------------------------------------------------------
//  WHAT THIS DOES
//  Listens on the USB serial line for two simple text commands from the laptop
//  (from teach_and_replay.py) and drives the six arm servos. It ALSO clamps
//  every angle on-board against per-joint limits it was handed at startup --
//  so even if the laptop side had a bug, a bad number still cannot reach a
//  servo. That is "defense in depth": two independent guards, laptop AND board.
//
//  THE TWO COMMANDS (plain text, one per line, ending in newline '\n'):
//    L,<i>,<min>,<max>   Set the safe limits for joint <i> (0..5), in degrees.
//                        The laptop sends these six lines at handshake, before
//                        any motion. Until a joint has received its limits, it
//                        will NOT move (its "ready" flag is false).
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
//    * Use a dedicated 5-6 V supply (a battery pack or a bench PSU) sized for
//      the STALL current of all six servos at once -- a stalling servo gulps
//      far more current than the Arduino's onboard regulator can give. Powering
//      servos from the Arduino 5 V pin will brown out the board (it resets or
//      acts drunk) or fry it.
//    * SHARED GROUND: the servo supply's ground (-) MUST connect to the
//      Arduino's GND. Without a shared ground the signal wires have no common
//      reference and the servos twitch randomly.
//    * FUSE the servo supply's positive lead (a 3-5 A fuse is typical for six
//      9g-class servos -- size it to your servos' stall spec).
//    * A REACHABLE POWER SWITCH on the servo supply, within arm's reach, so you
//      can cut motor power instantly WITHOUT unplugging the USB.
//    * Servo signal wires go to the Arduino PWM pins below. Servo + (red) goes
//      to the EXTERNAL supply +, servo - (brown/black) to the shared ground.
//
//         Arduino GND  ------+------------------  Servo supply (-)
//                            |
//         (shared ground)    +--  each servo (-)
//
//         Servo supply (+) --[FUSE]--[SWITCH]--  each servo (+)
//
//         Arduino pin 3  ------------------------  base       servo signal
//         Arduino pin 5  ------------------------  shoulder   servo signal
//         Arduino pin 6  ------------------------  elbow      servo signal
//         Arduino pin 9  ------------------------  wrist_tilt servo signal
//         Arduino pin 10 ------------------------  wrist_rot  servo signal
//         Arduino pin 11 ------------------------  gripper    servo signal
//
//    CHECK THIS YOURSELF: the fuse, the shared ground, and the reachable switch
//    are load/​power items -- verify them on your own bench before energizing.
//    A human watches every powered move, hand on the switch. Nothing here is
//    ever "safe unattended".
// ============================================================================

#include <Servo.h>

// Number of joints, in the SAME order the laptop uses (index 0..5):
//   0 base   1 shoulder   2 elbow   3 wrist_tilt   4 wrist_rotate   5 gripper
const int NUM_JOINTS = 6;

// Signal pins for each joint, index-aligned with the order above.
const int SERVO_PINS[NUM_JOINTS] = { 3, 5, 6, 9, 10, 11 };

Servo servos[NUM_JOINTS];

// Per-joint safe limits, in degrees. Filled by the "L" handshake command.
// Sensible fallbacks (90..90 = a single safe pose) mean a joint that has NOT
// yet been given real limits can only hold one angle -- it cannot sweep into
// something until the laptop teaches it the measured envelope.
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
    // Start every joint locked to a single safe angle until real limits arrive.
    jointMin[i] = 90;
    jointMax[i] = 90;
    jointReady[i] = false;
    servos[i].write(90);   // neutral hold; harmless with min==max==90
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
        // No measured limits yet -> refuse to move. This is the on-board
        // equivalent of the laptop's "no calibration, no motion" rule.
        Serial.print("ERR S joint ");
        Serial.print(idx);
        Serial.println(" has no limits yet (send L first)");
        return;
      }
      // DEFENSE IN DEPTH: clamp on-board too, regardless of what the laptop sent.
      int safe = clampAngle(angle, jointMin[idx], jointMax[idx]);
      servos[idx].write(safe);
      if (safe != angle) {
        Serial.print("CLAMP S,");
        Serial.print(idx); Serial.print(","); Serial.print(safe);
        Serial.print(" (asked "); Serial.print(angle); Serial.println(")");
      } else {
        Serial.print("OK S,");
        Serial.print(idx); Serial.print(","); Serial.println(safe);
      }
    } else {
      Serial.println("ERR S parse");
    }
    return;
  }

  Serial.println("ERR unknown command");
}
