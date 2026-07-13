// ============================================================================
//  spool_scale.ino  --  honest "how much filament is left?" gauge
//  Part of: curious-research / projects/spool-weight-scale
// ----------------------------------------------------------------------------
//  WHAT THIS IS
//  A cheap load cell (a little metal bar that bends a hair under weight) read
//  through an HX711 amplifier board by an Arduino, reporting grams. Set a spool
//  on it, and it tells you roughly how much filament is left -- an ON-DEMAND
//  spot-check you re-zero, NOT an always-on precision shelf display. A cheap
//  load cell drifts a few grams with temperature and time (see the README and
//  ideas/spool-weight-scale.md), so trust it for "roughly half a spool left,"
//  not "exactly 3 g left to finish this print."
//
//  Bench words (one line each):
//    load cell    = a metal bar with a strain gauge inside that bends a tiny,
//                   measurable amount under weight.
//    HX711        = the amplifier + analog-to-digital chip that turns the load
//                   cell's microscopic voltage change into a number.
//    calibration  = the one-time "weigh a known mass" step that turns raw
//                   counts into real grams (the calibration factor).
//    tare         = subtracting a known weight (the empty spool) so the reading
//                   is filament-only.
//
// ----------------------------------------------------------------------------
//  YOU NEED ONE LIBRARY (two more for Stage 3). In the Arduino IDE:
//    Sketch > Include Library > Manage Libraries...  then search & Install:
//      * "HX711_ADC" by Olav Kallhovd    (used by all three stages)
//    For Stage 3 (the OLED screen) also install:
//      * "Adafruit SSD1306" by Adafruit  (click "Install All" if it offers deps)
//      * "Adafruit GFX Library" by Adafruit
//
// ----------------------------------------------------------------------------
//  WIRING  (all low-voltage, powered over the Arduino's USB -- no external
//  supply, nothing hot, nothing mains. Full numbered wiring is in the README.)
//
//    LOAD CELL (4 thin wires) -> HX711 board:
//        red   -> E+        black -> E-
//        white -> A-        green -> A+    (if grams read backwards/negative,
//                                           swap white<->green)
//    HX711 board -> Arduino:
//        VCC -> 5V     GND -> GND
//        DT  -> pin 4  (data)      SCK -> pin 5  (clock)
//    STAGE 3 EXTRAS:
//        Read button: one leg -> pin 6, other leg -> GND (uses the chip's
//                     built-in pull-up; no resistor needed)
//        SSD1306 OLED (I2C): VCC -> 5V  GND -> GND  SDA -> A4  SCL -> A5
//                     (on an Uno/Nano, SDA is A4 and SCL is A5)
//
//    CHECK THIS YOURSELF (the one real caution -- mechanical, not electrical):
//    bolt the load cell with ONE end rigidly fixed and the load on the FREE
//    end, and never twist or over-torque the bar. Bending it the wrong way or
//    cranking the screws too hard permanently damages the strain gauge inside.
// ============================================================================

// ---------------------------------------------------------------------------
//  PICK YOUR STAGE  --  change this ONE number, re-upload, watch what happens.
//    1 = CALIBRATE       : find your calibration factor with a known weight.
//    2 = GRAMS REMAINING : report total - saved empty-spool weight, in Serial.
//    3 = OLED STANDALONE  : press the button to show grams on the little screen.
// ---------------------------------------------------------------------------
#define STAGE 1

#include <HX711_ADC.h>
#if STAGE == 3
  #include <Wire.h>
  #include <Adafruit_GFX.h>
  #include <Adafruit_SSD1306.h>
#endif

// ---------------------------------------------------------------------------
//  YOUR CALIBRATION FACTOR
//  Stage 1 prints this number for you. Copy the value it gives into the line
//  below, then Stages 2 and 3 report real grams. (Starts at 1.0 = uncalibrated.)
// ---------------------------------------------------------------------------
float calibrationFactor = 1.0;   // <-- paste YOUR Stage-1 number here

// ---------------------------------------------------------------------------
//  YOUR KNOWN WEIGHT (Stage 1 only)
//  The mass, in grams, of the object you place to calibrate. A labelled kitchen
//  weight, or anything you weighed on a kitchen scale (a full 500 mL water
//  bottle is ~500 g). Bigger and heavier gives a steadier calibration.
// ---------------------------------------------------------------------------
float knownMassGrams = 500.0;

// ---------------------------------------------------------------------------
//  YOUR SPOOL LIBRARY  (Stages 2 and 3)
//  grams-remaining = total-on-scale  -  this spool's EMPTY weight.
//  The empty weight is the hard part: empty spools range ~80-306 g, so guessing
//  is useless. WEIGH YOUR OWN SPOOL EMPTY ONCE and put that number in slot 0 --
//  your measured gram beats any table below. The seeded numbers are only
//  ballpark starting points (Prusament ~201 g, Bambu ~256 g -- from the
//  empty-spool catalogs cited in the README); confirm them on your own bench.
// ---------------------------------------------------------------------------
struct Spool {
  const char* name;       // shows in the Serial Monitor / on the OLED
  float       emptyGrams; // this spool's weight with NO filament on it
};

Spool spoolLibrary[] = {
  { "MY SPOOL (measure me!)", 0.0   },  // slot 0: YOUR measured empty weight
  { "Prusament (approx)",     201.0 },
  { "Bambu (approx)",         256.0 },
  { "Hatchbox (approx)",      225.0 },
  { "eSun (approx)",          224.0 },
};

// Which spool from the list above is on the scale right now (0 = your own).
#define ACTIVE_SPOOL 0

// ---------------------------------------------------------------------------
//  PINS  (match the wiring comment at the top)
// ---------------------------------------------------------------------------
const int HX711_dout  = 4;
const int HX711_sck   = 5;
const int READ_BUTTON = 6;   // Stage 3 only

HX711_ADC LoadCell(HX711_dout, HX711_sck);

#if STAGE == 3
  #define SCREEN_WIDTH  128
  #define SCREEN_HEIGHT 64
  #define OLED_ADDR     0x3C   // most 0.96" I2C OLEDs; try 0x3D if the screen stays blank
  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
#endif

// ===========================================================================
//  SETUP
// ===========================================================================
void setup() {
  Serial.begin(57600);
  delay(300);
  Serial.println();
  Serial.println("spool_scale -- starting up");

  LoadCell.begin();
  // Let the cell settle, and tare (zero) it with NOTHING on the platform.
  unsigned long stabilizingTime = 2000;  // ms to let the reading settle
  boolean doTare = true;                 // zero the empty platform at startup
  LoadCell.start(stabilizingTime, doTare);

  if (LoadCell.getTareTimeoutFlag()) {
    Serial.println("ERROR: HX711 not responding. Check the DT (pin 4) and SCK (pin 5) wiring.");
    while (true) { }   // stop here -- nothing works until the wiring is fixed
  }

  LoadCell.setCalFactor(calibrationFactor);
  Serial.println("Startup done. Keep the platform EMPTY until asked.");

#if STAGE == 1
  Serial.println();
  Serial.println("=== STAGE 1: CALIBRATE ===");
  Serial.println("1) Leave the platform empty. 2) Type 't' + Enter to zero it.");
  Serial.print("3) Place your known weight (");
  Serial.print(knownMassGrams);
  Serial.println(" g). 4) Type 'r' + Enter to read the calibration factor.");
#endif

#if STAGE == 3
  pinMode(READ_BUTTON, INPUT_PULLUP);  // pressing the button connects the pin to GND
  startOLED();
#endif
}

// ===========================================================================
//  MAIN LOOP  --  one behaviour per stage
// ===========================================================================
void loop() {
  LoadCell.update();  // must be called often -- keeps fresh data flowing in

#if STAGE == 1
  loopCalibrate();
#elif STAGE == 2
  loopGramsRemaining();
#elif STAGE == 3
  loopOledStandalone();
#endif
}

// ---------------------------------------------------------------------------
//  STAGE 1  --  find your calibration factor with a known weight
// ---------------------------------------------------------------------------
#if STAGE == 1
void loopCalibrate() {
  // Print a live raw reading a couple times a second so you can watch it settle.
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 500) {
    lastPrint = millis();
    Serial.print("reading (not real grams until you calibrate): ");
    Serial.println(LoadCell.getData());
  }

  // Single-character commands typed into the Serial Monitor.
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == 't') {
      LoadCell.tareNoDelay();      // zero the empty platform
      Serial.println(">> taring... (keep the platform empty)");
    }
    if (c == 'r') {
      // With the known mass sitting on the platform, compute the factor.
      LoadCell.refreshDataSet();   // average a fresh set of readings with the mass on
      float newCal = LoadCell.getNewCalibration(knownMassGrams);
      Serial.println();
      Serial.print(">> YOUR CALIBRATION FACTOR = ");
      Serial.println(newCal);
      Serial.println(">> Copy that number into 'calibrationFactor' near the top");
      Serial.println(">> of this sketch, set STAGE to 2, and upload again.");
      Serial.println();
    }
  }

  // Announce when a tare finishes.
  if (LoadCell.getTareStatus()) {
    Serial.println(">> tare done. Now place your known weight and type 'r'.");
  }
}
#endif

// ---------------------------------------------------------------------------
//  STAGE 2  --  grams of filament remaining, in the Serial Monitor
// ---------------------------------------------------------------------------
#if STAGE == 2
void loopGramsRemaining() {
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 1000) {
    lastPrint = millis();

    float total     = LoadCell.getData();                  // whole spool, grams
    float empty     = spoolLibrary[ACTIVE_SPOOL].emptyGrams;
    float remaining = total - empty;                       // filament only
    if (remaining < 0) remaining = 0;                      // never show negative

    Serial.print(spoolLibrary[ACTIVE_SPOOL].name);
    Serial.print(" | total ");    Serial.print(total, 0);
    Serial.print(" g  - empty "); Serial.print(empty, 0);
    Serial.print(" g  = ~");      Serial.print(remaining, 0);
    Serial.println(" g filament left");

    if (empty == 0.0) {
      Serial.println("   (slot 0's empty weight is still 0 -- weigh your spool");
      Serial.println("    empty once and put that gram number in the spool library.)");
    }
  }
}
#endif

// ---------------------------------------------------------------------------
//  STAGE 3  --  press the button, read grams on the little screen (no PC needed)
// ---------------------------------------------------------------------------
#if STAGE == 3
void startOLED() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("ERROR: OLED not found. Check SDA=A4, SCL=A5, and the 0x3C/0x3D address.");
    while (true) { }
  }
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("spool scale");
  display.println("press button to read");
  display.display();
}

void showReading(float remaining, float total) {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(spoolLibrary[ACTIVE_SPOOL].name);
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print(remaining, 0);
  display.println(" g");
  display.setTextSize(1);
  display.setCursor(0, 52);
  display.print("total ");
  display.print(total, 0);
  display.println("g spot-check");
  display.display();
}

void loopOledStandalone() {
  // The button pulls the pin LOW when pressed (INPUT_PULLUP).
  static bool wasPressed = false;
  bool pressed = (digitalRead(READ_BUTTON) == LOW);

  if (pressed && !wasPressed) {
    // A fresh, averaged reading makes the spot-check trustworthy.
    LoadCell.refreshDataSet();
    float total     = LoadCell.getData();
    float empty     = spoolLibrary[ACTIVE_SPOOL].emptyGrams;
    float remaining = total - empty;
    if (remaining < 0) remaining = 0;
    showReading(remaining, total);
  }
  wasPressed = pressed;
}
#endif
