/*
  APDS-9960 Simple Color Detector + I2C LCD Display
  ----------------------------------------
  Reads RGB + Clear light values from the APDS-9960 sensor,
  prints raw RGB values to Serial Monitor, identifies the
  closest matching color name, and shows the result on a
  16x2 I2C LCD for standalone (no-PC) operation.

  Libraries required:
  - SparkFun_APDS9960  (Library Manager: search "SparkFun APDS9960")
  - LiquidCrystal_I2C  (Library Manager: search "LiquidCrystal I2C" by Frank de Brabander)

  Wiring - APDS-9960 (I2C):
  VCC -> 3.3V   (IMPORTANT: 3.3V only, not 5V)
  GND -> GND
  SDA -> A4 (Uno) / GPIO21 (ESP32)
  SCL -> A5 (Uno) / GPIO22 (ESP32)

  Wiring - 16x2 I2C LCD (shares the same I2C bus):
  VCC -> 5V (most LCD backpacks are 5V tolerant; check yours)
  GND -> GND
  SDA -> A4 (Uno) / GPIO21 (ESP32)   [same bus as sensor]
  SCL -> A5 (Uno) / GPIO22 (ESP32)   [same bus as sensor]

  Note: If the LCD doesn't show text, run an I2C scanner sketch
  first to confirm its address -- common addresses are 0x27 or 0x3F.
*/

#include <Wire.h>
#include <SparkFun_APDS9960.h>
#include <LiquidCrystal_I2C.h>

SparkFun_APDS9960 apds = SparkFun_APDS9960();

// Change 0x27 to 0x3F if your LCD isn't detected at 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

uint16_t redLight  = 0;
uint16_t greenLight = 0;
uint16_t blueLight  = 0;
uint16_t ambientLight = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("APDS-9960 Color Detector");

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Color Detector");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");

  if (apds.init()) {
    Serial.println("APDS-9960 initialization complete");
  } else {
    Serial.println("Something went wrong during APDS-9960 init!");
    lcd.clear();
    lcd.print("Sensor init");
    lcd.setCursor(0, 1);
    lcd.print("FAILED!");
  }

  if (apds.enableLightSensor(false)) {
    Serial.println("Light sensor enabled");
  } else {
    Serial.println("Something went wrong during light sensor init!");
  }

  // Increase ambient light gain -- helps a lot in dim rooms since
  // this sensor relies on ambient light bouncing off the object,
  // not a dedicated white LED.
  // Options: AGAIN_1X, AGAIN_4X, AGAIN_16X, AGAIN_64X
  apds.setAmbientLightGain(AGAIN_64X);

  delay(1000); // wait for first reading to be ready
  lcd.clear();
}

void loop() {
  bool readOk = apds.readAmbientLight(ambientLight) &&
                apds.readRedLight(redLight) &&
                apds.readGreenLight(greenLight) &&
                apds.readBlueLight(blueLight);

  if (!readOk) {
    Serial.println("Error reading sensor values");
    lcd.setCursor(0, 0);
    lcd.print("Sensor read err ");
  } else {
    Serial.print("Ambient: ");
    Serial.print(ambientLight);
    Serial.print("  R: ");
    Serial.print(redLight);
    Serial.print("  G: ");
    Serial.print(greenLight);
    Serial.print("  B: ");
    Serial.print(blueLight);

    String colorName = classifyColor(redLight, greenLight, blueLight);

    Serial.print("   --> Detected Color: ");
    Serial.println(colorName);

    updateLCD(colorName, redLight, greenLight, blueLight);
  }

  delay(500);
}

// Displays the detected color name on line 1 and raw RGB values
// on line 2 of the 16x2 LCD. Pads with spaces to clear leftover
// characters from longer previous readings.
void updateLCD(String colorName, uint16_t r, uint16_t g, uint16_t b) {
  lcd.setCursor(0, 0);
  lcd.print("Color: ");
  lcd.print(colorName);
  // Clear any leftover characters if new text is shorter than old
  for (int i = 7 + colorName.length(); i < 16; i++) {
    lcd.setCursor(i, 0);
    lcd.print(" ");
  }

  lcd.setCursor(0, 1);
  String rgbLine = "R" + String(r) + " G" + String(g) + " B" + String(b);
  lcd.print(rgbLine);
  for (int i = rgbLine.length(); i < 16; i++) {
    lcd.setCursor(i, 1);
    lcd.print(" ");
  }
}

// Classifies raw RGB readings into a human-readable color name
// by normalizing ratios (works better than raw values since
// raw brightness varies with distance/lighting).
String classifyColor(uint16_t r, uint16_t g, uint16_t b) {
  // Avoid divide-by-zero if sensor reads all zero (nothing in range)
  uint32_t total = (uint32_t)r + g + b;
  if (total < 5) {
    return "Too dark to read";
  }

  // Normalize to percentages of total light
  float rPct = (float)r / total;
  float gPct = (float)g / total;
  float bPct = (float)b / total;

  // Simple heuristic thresholds -- tune these based on your
  // own test objects and lighting conditions
  if (rPct > 0.42 && rPct > gPct && rPct > bPct) {
    return "Red";
  } else if (gPct > 0.42 && gPct > rPct && gPct > bPct) {
    return "Green";
  } else if (bPct > 0.42 && bPct > rPct && bPct > gPct) {
    return "Blue";
  } else if (rPct > 0.33 && gPct > 0.33 && bPct < 0.30) {
    return "Yellow";
  } else if (rPct > 0.33 && bPct > 0.33 && gPct < 0.30) {
    return "Purple/Magenta";
  } else if (gPct > 0.33 && bPct > 0.33 && rPct < 0.30) {
    return "Cyan";
  } else if (rPct > 0.30 && gPct > 0.30 && bPct > 0.30) {
    return "White/Gray";
  } else {
    return "Unknown";
  }
}
