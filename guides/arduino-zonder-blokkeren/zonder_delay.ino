// Eén ledtaak en één knopinput, zonder delay().
// Optionele knop: pin 2 naar GND; INPUT_PULLUP gebruikt de interne pull-up.

const int KNOP_PIN = 2;
const unsigned long KNIPPER_INTERVAL_MS = 1000;
const unsigned long DENDER_INTERVAL_MS = 30;

unsigned long laatsteWisselMs = 0;
unsigned long laatsteKnopOvergangMs = 0;
bool ledAan = false;
bool vorigeRuweKnop = HIGH;
bool stabieleKnop = HIGH;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(KNOP_PIN, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  const unsigned long nu = millis();

  if (nu - laatsteWisselMs >= KNIPPER_INTERVAL_MS) {
    laatsteWisselMs = nu;
    ledAan = !ledAan;
    digitalWrite(LED_BUILTIN, ledAan ? HIGH : LOW);
    Serial.print(nu);
    Serial.println(F(" ms: led gewisseld"));
  }

  const bool ruweKnop = digitalRead(KNOP_PIN);
  if (ruweKnop != vorigeRuweKnop) {
    vorigeRuweKnop = ruweKnop;
    laatsteKnopOvergangMs = nu;
  }

  if (nu - laatsteKnopOvergangMs >= DENDER_INTERVAL_MS && ruweKnop != stabieleKnop) {
    stabieleKnop = ruweKnop;
    if (stabieleKnop == LOW) {
      Serial.print(nu);
      Serial.println(F(" ms: knop ingedrukt"));
    }
  }
}

