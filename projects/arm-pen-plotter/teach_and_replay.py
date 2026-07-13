#!/usr/bin/env python3
# ============================================================================
#  teach_and_replay.py  --  teach-mode waypoint recorder + replayer
#  Part of: curious-research / projects/arm-pen-plotter
# ----------------------------------------------------------------------------
#  WHAT THIS IS
#  A tiny, safe tool for the 6-servo arm. You physically "teach" the arm poses
#  by nudging each joint a few degrees at a time (that's "jogging"), snapshot
#  the pose as a "waypoint", and build up a little list of waypoints. Then you
#  can "replay" that list slowly to redraw the same move -- the honest,
#  no-math path to a first wobbly line (this is how BrachioGraph-class plotters
#  actually work).
#
#  Bench words, one line each:
#    - servo     = a motor you command to an exact angle (0..180 deg). Six here.
#    - jog       = nudge one joint a small step at a time, by eye.
#    - waypoint  = one snapshot of all six joint angles, saved to replay later.
#    - clamp     = trim any angle back inside the safe min/max you measured, so
#                  a bad number can NEVER reach a motor. clamp(200, 20, 120)=120.
#    - envelope  = the safe angle range per joint, measured by hand once and
#                  written into arm/calibration.json (YOUR file, YOUR numbers).
#
#  THE HARD SAFETY RULES (binding -- see repo CLAUDE.md and the envelope guide):
#    1. This tool REFUSES to run without arm/calibration.json. No calibration,
#       no motion. There is no override.
#    2. EVERY value sent to the serial port goes through ONE function --
#       _send_servo() -- and that function clamps first, always. There is no
#       other way to reach the port. That is the whole safety design: it is
#       structurally impossible to send an unclamped angle.
#    3. Servo power is a SEPARATE, FUSED 5-6 V supply with a shared ground and
#       a reachable switch -- NEVER the Arduino's 5 V pin.
#    4. A human watches every powered move, hand on the switch. Nothing here is
#       ever "safe unattended". Cut power first, ask questions after.
#
#  DEPENDENCIES: standard library only, plus `pyserial` (import serial) IF you
#  actually connect to hardware. You can browse/record/save waypoints with NO
#  serial connection at all -- serial is only opened when you choose to move.
#
#    pip install pyserial
#
#  `python3 -m py_compile teach_and_replay.py` must pass with no extra installs
#  (pyserial is imported lazily, only when a move is requested).
# ============================================================================

import argparse
import json
import os
import sys
import time

# ---------------------------------------------------------------------------
#  Paths. calibration.json lives in the repo's arm/ lane; this file lives in
#  projects/arm-pen-plotter/. We look upward for arm/calibration.json so the
#  tool works no matter which folder you launch it from.
# ---------------------------------------------------------------------------
HERE = os.path.dirname(os.path.abspath(__file__))
REPO_ROOT = os.path.abspath(os.path.join(HERE, os.pardir, os.pardir))
CALIBRATION_PATH = os.path.join(REPO_ROOT, "arm", "calibration.json")
ENVELOPE_GUIDE = "guides/arm-envelope-explained/guide.md"

# The six joints, in the order they appear on the wire (index 0..5). This must
# match the servo order your Arduino sketch expects at the pins.
JOINT_ORDER = ["base", "shoulder", "elbow", "wrist_tilt", "wrist_rotate", "gripper"]

# Replay defaults -- deliberately SLOW. A first move should crawl so you have
# time to hit the switch. Faster only once you trust the path.
DEFAULT_STEP_DEG = 2          # jog nudge size, degrees
DEFAULT_MOVE_DELAY = 0.02     # seconds between each 1-degree sub-step on replay
DEFAULT_SETTLE = 0.6          # seconds to pause at each waypoint on replay
DEFAULT_BAUD = 115200


# ---------------------------------------------------------------------------
#  THE CLAMP -- the single most important function in this file.
#  Trims `value` into [lo, hi]. Every angle that goes to a motor passes here.
# ---------------------------------------------------------------------------
def clamp(value, lo, hi):
    """Return value trimmed into the inclusive range [lo, hi].

    clamp(200, 20, 120) -> 120   (too high, trimmed down to the safe max)
    clamp(5,   20, 120) -> 20    (too low,  trimmed up to the safe min)
    clamp(75,  20, 120) -> 75    (already safe, unchanged)
    """
    if lo > hi:
        # A calibration file with min > max is nonsense and unsafe. Refuse.
        raise ValueError("bad limits: lo (%s) is greater than hi (%s)" % (lo, hi))
    if value < lo:
        return lo
    if value > hi:
        return hi
    return value


class Calibration:
    """Your measured safe envelope: per-joint min / max / center, in degrees.

    Loaded from arm/calibration.json. If that file is missing or still holds
    the template's PLACEHOLDER values, we refuse to run -- those numbers are
    not safe for YOUR arm.
    """

    def __init__(self, joints, measured_by, measured_on):
        self.joints = joints            # {name: {"min":.., "max":.., "center":..}}
        self.measured_by = measured_by
        self.measured_on = measured_on

    @classmethod
    def load(cls, path):
        if not os.path.exists(path):
            _refuse_no_calibration(path)

        with open(path, "r", encoding="utf-8") as fh:
            try:
                data = json.load(fh)
            except json.JSONDecodeError as exc:
                _die(
                    "Could not read %s -- it is not valid JSON.\n"
                    "  Details: %s\n"
                    "  Fix the file (compare it to arm/calibration.example.json) and try again."
                    % (path, exc)
                )

        raw_joints = data.get("joints", {})
        joints = {}
        placeholders = []

        for name in JOINT_ORDER:
            spec = raw_joints.get(name)
            if not spec:
                _die(
                    "Your %s is missing joint '%s'. All six joints must be present:\n  %s"
                    % (path, name, ", ".join(JOINT_ORDER))
                )
            # A joint still carrying the template's _status field is unmeasured.
            if "_status" in spec and "PLACEHOLDER" in str(spec.get("_status", "")):
                placeholders.append(name)
            lo = spec.get("min")
            hi = spec.get("max")
            center = spec.get("center")
            if lo is None or hi is None or center is None:
                _die("Joint '%s' in %s needs min, max, and center." % (name, path))
            if lo > hi:
                _die(
                    "Joint '%s' in %s has min (%s) above max (%s) -- that is unsafe. Re-measure."
                    % (name, path, lo, hi)
                )
            joints[name] = {"min": lo, "max": hi, "center": center}

        if placeholders:
            _die(
                "Your %s still holds TEMPLATE placeholder values for: %s.\n"
                "These are NOT safe for your arm. Measure each joint by hand and replace them --\n"
                "the how-to is in %s."
                % (path, ", ".join(placeholders), ENVELOPE_GUIDE)
            )

        return cls(
            joints=joints,
            measured_by=data.get("measured_by", ""),
            measured_on=data.get("measured_on", ""),
        )

    def limits(self, name):
        spec = self.joints[name]
        return spec["min"], spec["max"]

    def center_pose(self):
        """The neutral rest pose -- every joint at its measured center."""
        return {name: self.joints[name]["center"] for name in JOINT_ORDER}


def _refuse_no_calibration(path):
    _die(
        "\n"
        "  NO CALIBRATION FILE -- refusing to run.\n"
        "  ------------------------------------------------------------------\n"
        "  Expected: %s\n\n"
        "  This tool will not move the arm until YOU have measured each servo's\n"
        "  safe min / max / center by hand and written them into that file.\n"
        "  The clamp is only as safe as those numbers, and nobody else's numbers\n"
        "  are safe for your arm.\n\n"
        "  How to make it (about 20 minutes, power OFF first):\n"
        "    1. Read %s\n"
        "    2. Copy the template:\n"
        "         cp arm/calibration.example.json arm/calibration.json\n"
        "    3. Fill in your measured min/max/center for all six joints.\n\n"
        "  Then run this tool again.\n"
        % (path, ENVELOPE_GUIDE)
    )


def _die(message):
    print("\nERROR: " + message + "\n", file=sys.stderr)
    sys.exit(1)


# ---------------------------------------------------------------------------
#  THE ARM -- owns the ONE clamped send path to the serial port.
#  Nothing else in this file talks to the port. If you want to move a servo,
#  you call move_to()/goto_pose(), which call _send_servo(), which clamps.
# ---------------------------------------------------------------------------
class Arm:
    def __init__(self, calib, port=None, baud=DEFAULT_BAUD, dry_run=False):
        self.calib = calib
        self.port = port
        self.baud = baud
        self.dry_run = dry_run or port is None
        self._serial = None
        # Current believed pose starts at the measured center of every joint.
        self.pose = calib.center_pose()

    # -- connection ---------------------------------------------------------
    def connect(self):
        """Open the serial port and hand the Arduino our clamp limits.

        In dry-run mode (no --port) we never open anything -- you can still
        record and save waypoints, just not move a real arm.
        """
        if self.dry_run:
            print("[dry-run] No serial port -- moves are printed, not sent.")
            return

        try:
            import serial  # pyserial, imported lazily so browsing needs no install
        except ImportError:
            _die(
                "pyserial is not installed, but you asked to open a real port.\n"
                "  Install it:  pip install pyserial\n"
                "  Or run without --port to record/replay in dry-run (no motion)."
            )

        self._serial = serial.Serial(self.port, self.baud, timeout=2)
        time.sleep(2.0)  # give the board a moment to reset after the port opens

        # Defense in depth: send the safe limits to the Arduino so it can clamp
        # on-board too. Even if this laptop code had a bug, the board still
        # refuses out-of-range angles. Handshake format matches the .ino sketch:
        #   L,<joint_index>,<min>,<max>\n
        for i, name in enumerate(JOINT_ORDER):
            lo, hi = self.calib.limits(name)
            self._write_line("L,%d,%d,%d" % (i, int(lo), int(hi)))
            time.sleep(0.02)
        print("Sent safe limits to the board (it will clamp on-board too).")

    def close(self):
        if self._serial is not None:
            self._serial.close()
            self._serial = None

    def _write_line(self, text):
        if self.dry_run or self._serial is None:
            return
        self._serial.write((text + "\n").encode("ascii"))

    # -- THE ONE CLAMPED SEND PATH -----------------------------------------
    def _send_servo(self, name, angle):
        """The ONLY function that sends a servo angle. It clamps first, always.

        Returns the angle actually sent (post-clamp) so callers can update the
        believed pose with the real, safe value -- never the raw request.
        """
        lo, hi = self.calib.limits(name)
        safe = clamp(angle, lo, hi)
        idx = JOINT_ORDER.index(name)
        # Wire format matches the .ino sketch:  S,<joint_index>,<angle>\n
        line = "S,%d,%d" % (idx, int(round(safe)))
        if self.dry_run:
            tag = "" if safe == angle else "  (clamped from %s)" % angle
            print("  [dry-run] -> %s%s" % (line, tag))
        else:
            self._write_line(line)
        return safe

    # -- movement (all routed through _send_servo) --------------------------
    def move_to(self, name, angle):
        """Move ONE joint to an angle (clamped). Updates the believed pose."""
        safe = self._send_servo(name, angle)
        self.pose[name] = safe
        return safe

    def goto_pose(self, target, move_delay=DEFAULT_MOVE_DELAY):
        """Ease ALL joints from the current pose to `target`, one degree at a
        time, slowly. Every intermediate value still goes through the clamp.

        Interpolating in 1-degree sub-steps keeps the motion gentle instead of
        snapping, which matters a lot on a wobbly hobby arm."""
        # Pre-clamp the target so our step count matches what will actually move.
        safe_target = {}
        for name in JOINT_ORDER:
            lo, hi = self.calib.limits(name)
            safe_target[name] = clamp(target.get(name, self.pose[name]), lo, hi)

        # How many 1-degree steps does the furthest-travelling joint need?
        spans = [abs(safe_target[n] - self.pose[n]) for n in JOINT_ORDER]
        steps = int(max(spans)) if spans else 0
        if steps <= 0:
            # Nothing moves; still (re)assert the pose once, clamped.
            for name in JOINT_ORDER:
                self.move_to(name, safe_target[name])
            return

        start = dict(self.pose)
        for s in range(1, steps + 1):
            frac = s / steps
            for name in JOINT_ORDER:
                a = start[name] + (safe_target[name] - start[name]) * frac
                self.move_to(name, a)   # clamped inside move_to -> _send_servo
            time.sleep(move_delay)


# ---------------------------------------------------------------------------
#  Waypoint file I/O. A waypoint file is plain JSON: a name plus a list of
#  poses. Anyone can open it in a text editor.
# ---------------------------------------------------------------------------
def load_waypoints(path):
    if not os.path.exists(path):
        return {"name": os.path.basename(path), "waypoints": []}
    with open(path, "r", encoding="utf-8") as fh:
        data = json.load(fh)
    data.setdefault("waypoints", [])
    return data


def save_waypoints(path, data):
    with open(path, "w", encoding="utf-8") as fh:
        json.dump(data, fh, indent=2)
        fh.write("\n")
    print("Saved %d waypoint(s) to %s" % (len(data["waypoints"]), path))


# ---------------------------------------------------------------------------
#  BANNER -- printed every launch, because the danger is real every launch.
# ---------------------------------------------------------------------------
def print_banner(calib):
    line = "=" * 74
    print(line)
    print("  ARM PEN-PLOTTER  --  TEACH & REPLAY")
    print(line)
    print("  SAFETY, every single time:")
    print("   * HAND ON THE FUSED EXTERNAL SUPPLY SWITCH before any powered move.")
    print("   * WATCH every move. If it looks/sounds/smells wrong, KILL POWER first.")
    print("   * Servo power is a SEPARATE 5-6 V supply, shared ground, fused,")
    print("     reachable switch -- NEVER the Arduino's 5 V pin.")
    print("   * Every angle this tool sends is CLAMPED to your measured limits.")
    print("     The clamp is only as safe as the numbers YOU measured.")
    print(line)
    who = calib.measured_by or "(unnamed)"
    when = calib.measured_on or "(no date)"
    print("  Calibration loaded  --  measured by %s on %s" % (who, when))
    print("  Safe limits (min / max degrees):")
    for name in JOINT_ORDER:
        lo, hi = calib.limits(name)
        print("     %-13s %3d ... %3d   (center %d)"
              % (name, lo, hi, calib.joints[name]["center"]))
    print(line)


# ---------------------------------------------------------------------------
#  TEACH MODE -- an interactive prompt to jog, snapshot, list, save, replay.
# ---------------------------------------------------------------------------
TEACH_HELP = """
Teach-mode commands (type one and press Enter):

  j <joint> <deg>   Jog a joint by <deg> degrees (may be negative). Clamped.
                    Joints: base shoulder elbow wrist_tilt wrist_rotate gripper
                    You can also use the index 0..5. Example:  j shoulder 5
  set <joint> <deg> Send a joint to an ABSOLUTE angle (clamped). Ex: set base 90
  pose              Show the current believed pose (all six joints).
  rec               Record the current pose as a new waypoint.
  list              List the recorded waypoints.
  del <n>           Delete waypoint number <n> (as shown by 'list').
  center            Ease every joint to its measured center (the rest pose).
  save              Save waypoints to the file (--file, default waypoints.json).
  replay            Replay all recorded waypoints, slowly, through the clamp.
  step <deg>        Change the default jog step size (currently shown at prompt).
  help              Show this help.
  quit              Save-prompt and exit.
"""


def resolve_joint(token):
    """Accept either a joint name or its index 0..5; return the name or None."""
    token = token.strip().lower()
    if token in JOINT_ORDER:
        return token
    if token.isdigit():
        i = int(token)
        if 0 <= i < len(JOINT_ORDER):
            return JOINT_ORDER[i]
    return None


def print_pose(pose):
    parts = ["%s=%d" % (n, int(round(pose[n]))) for n in JOINT_ORDER]
    print("  pose:  " + "  ".join(parts))


def teach_loop(arm, wp_path, wp_data, step_deg):
    print(TEACH_HELP)
    print("Recording into: %s  (%d waypoint(s) already loaded)"
          % (wp_path, len(wp_data["waypoints"])))
    dirty = False

    while True:
        try:
            raw = input("teach [step=%d]> " % step_deg).strip()
        except (EOFError, KeyboardInterrupt):
            print()
            raw = "quit"

        if not raw:
            continue
        parts = raw.split()
        cmd = parts[0].lower()

        if cmd in ("quit", "q", "exit"):
            if dirty:
                ans = input("Save %d waypoint(s) before quitting? [y/N] "
                            % len(wp_data["waypoints"])).strip().lower()
                if ans == "y":
                    save_waypoints(wp_path, wp_data)
            print("Bye. Cut the servo power switch.")
            return

        elif cmd == "help":
            print(TEACH_HELP)

        elif cmd == "pose":
            print_pose(arm.pose)

        elif cmd == "step" and len(parts) == 2:
            try:
                step_deg = max(1, int(parts[1]))
            except ValueError:
                print("  step needs a whole number of degrees.")

        elif cmd == "center":
            print("  Easing to the rest pose (center of every joint)...")
            arm.goto_pose(arm.calib.center_pose())
            print_pose(arm.pose)

        elif cmd == "j" and len(parts) == 3:
            name = resolve_joint(parts[1])
            if not name:
                print("  Unknown joint. Use one of: %s" % ", ".join(JOINT_ORDER))
                continue
            try:
                delta = float(parts[2])
            except ValueError:
                print("  The nudge must be a number of degrees.")
                continue
            before = arm.pose[name]
            after = arm.move_to(name, before + delta)
            print("  %s: %d -> %d%s"
                  % (name, int(before), int(after),
                     "" if after == before + delta else "  (clamped at a safe limit)"))

        elif cmd == "set" and len(parts) == 3:
            name = resolve_joint(parts[1])
            if not name:
                print("  Unknown joint. Use one of: %s" % ", ".join(JOINT_ORDER))
                continue
            try:
                target = float(parts[2])
            except ValueError:
                print("  The angle must be a number of degrees.")
                continue
            after = arm.move_to(name, target)
            print("  %s -> %d%s"
                  % (name, int(after),
                     "" if after == target else "  (clamped to a safe limit)"))

        elif cmd == "rec":
            snapshot = {n: int(round(arm.pose[n])) for n in JOINT_ORDER}
            wp_data["waypoints"].append(snapshot)
            dirty = True
            print("  Recorded waypoint #%d." % len(wp_data["waypoints"]))
            print_pose(arm.pose)

        elif cmd == "list":
            wps = wp_data["waypoints"]
            if not wps:
                print("  (no waypoints yet -- jog the arm, then 'rec')")
            for i, wp in enumerate(wps, start=1):
                parts_s = ["%s=%d" % (n, wp.get(n, 0)) for n in JOINT_ORDER]
                print("  #%d  %s" % (i, "  ".join(parts_s)))

        elif cmd == "del" and len(parts) == 2:
            try:
                n = int(parts[1])
            except ValueError:
                print("  del needs a waypoint number (see 'list').")
                continue
            if 1 <= n <= len(wp_data["waypoints"]):
                wp_data["waypoints"].pop(n - 1)
                dirty = True
                print("  Deleted waypoint #%d." % n)
            else:
                print("  No waypoint #%d." % n)

        elif cmd == "save":
            save_waypoints(wp_path, wp_data)
            dirty = False

        elif cmd == "replay":
            run_replay(arm, wp_data)

        else:
            print("  Didn't understand that. Type 'help' for the command list.")


# ---------------------------------------------------------------------------
#  REPLAY -- step through saved waypoints, slowly, all clamped.
# ---------------------------------------------------------------------------
def run_replay(arm, wp_data, settle=DEFAULT_SETTLE):
    wps = wp_data["waypoints"]
    if not wps:
        print("  Nothing to replay -- no waypoints recorded yet.")
        return
    print("\n  REPLAY: %d waypoint(s), slow speed, all clamped." % len(wps))
    print("  HAND ON THE POWER SWITCH. Watch every move.\n")
    try:
        input("  Press Enter to start (or Ctrl-C to abort)... ")
    except (EOFError, KeyboardInterrupt):
        print("\n  Replay aborted.")
        return

    try:
        for i, wp in enumerate(wps, start=1):
            print("  -> waypoint #%d" % i)
            arm.goto_pose(wp)          # eases there, every sub-step clamped
            print_pose(arm.pose)
            time.sleep(settle)
        print("\n  Replay done. Returning to the rest pose.")
        arm.goto_pose(arm.calib.center_pose())
    except KeyboardInterrupt:
        print("\n  Replay interrupted -- CUT POWER if the arm is not where you expect.")


# ---------------------------------------------------------------------------
#  Entry point.
# ---------------------------------------------------------------------------
def build_parser():
    p = argparse.ArgumentParser(
        description="Teach-mode waypoint recorder + replayer for the pen-plotter arm. "
                    "Refuses to run without arm/calibration.json; clamps every servo value."
    )
    p.add_argument("--port", default=None,
                   help="Serial port of the Arduino (e.g. /dev/ttyUSB0 or COM3). "
                        "Omit for dry-run: record/replay with NO motion, moves are printed.")
    p.add_argument("--baud", type=int, default=DEFAULT_BAUD,
                   help="Serial baud rate (default %d, must match the sketch)." % DEFAULT_BAUD)
    p.add_argument("--file", default="waypoints.json",
                   help="Waypoint file to load/save (default waypoints.json).")
    p.add_argument("--step", type=int, default=DEFAULT_STEP_DEG,
                   help="Default jog step in degrees (default %d)." % DEFAULT_STEP_DEG)
    p.add_argument("--replay", action="store_true",
                   help="Skip teach mode: just replay the waypoint file, then exit.")
    return p


def main(argv=None):
    args = build_parser().parse_args(argv)

    # Rule 1: no calibration, no run. Load (and validate) it before anything.
    calib = Calibration.load(CALIBRATION_PATH)
    print_banner(calib)

    wp_data = load_waypoints(args.file)

    arm = Arm(calib, port=args.port, baud=args.baud)
    arm.connect()
    try:
        if args.replay:
            run_replay(arm, wp_data)
        else:
            teach_loop(arm, args.file, wp_data, args.step)
    finally:
        arm.close()


if __name__ == "__main__":
    main()
