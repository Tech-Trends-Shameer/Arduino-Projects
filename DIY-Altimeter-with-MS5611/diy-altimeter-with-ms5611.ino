/*
  GY-63 (MS5611) + 16x2 I2C LCD
  Arduino Uno — shared I2C bus

  Libraries needed:
    - MS5611 by Rob Tillaart
    - LiquidCrystal_I2C (Frank de Brabander or Marco Schwartz version)

  Wiring (shared I2C bus):
    MS5611 VCC -> 5V        LCD VCC -> 5V
    MS5611 GND -> GND       LCD GND -> GND
    MS5611 SDA -> A4        LCD SDA -> A4
    MS5611 SCL -> A5        LCD SCL -> A5
    MS5611 CSB -> 5V
    MS5611 PS  -> 5V
    Pull-ups (4.7k-5.6k) from SDA->5V and SCL->5V if not onboard

  If the LCD shows nothing/garbled: try changing 0x27 to 0x3F below,
  or run the I2C scanner sketch to confirm the LCD's address.
*/

#include <Wire.h>
#include <MS5611.h>
#include <LiquidCrystal_I2C.h>

MS5611 MS5611(0x77);

// Change 0x27 to 0x3F if your LCD backpack uses that address instead.
// 16 = columns, 2 = rows. Change to 20, 4 if you have a 20x4 LCD.
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Custom degree symbol (works on all LCD ROM variants, unlike code 223)
byte degreeSymbol[8] = {
  0b01100,
  0b10010,
  0b10010,
  0b01100,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

const float SEA_LEVEL_PRESSURE = 1013.25;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  lcd.init();
  lcd.backlight();
  lcd.createChar(0, degreeSymbol);
  lcd.setCursor(0, 0);
  lcd.print("MS5611 Init...");

  if (MS5611.begin() == true) {
    Serial.println("MS5611 found.");
  } else {
    Serial.println("MS5611 NOT found.");
    lcd.setCursor(0, 1);
    lcd.print("Sensor not found");
    while (1) delay(10);
  }

  MS5611.setOversampling(OSR_ULTRA_HIGH);

  lcd.clear(); 
  lcd.setCursor(3, 0);
  lcd.print("Tech Trends");
  lcd.setCursor(5, 1);
  lcd.print("Shameer");
  delay(1500);
}

void loop() {
  int result = MS5611.read();

  if (result != MS5611_READ_OK) {
    Serial.print("Read error: ");
    Serial.println(result);
    lcd.setCursor(0, 0);
    lcd.print("Sensor read err ");
    delay(1000);
    return;
  }

  float temperature = MS5611.getTemperature();
  float pressure     = MS5611.getPressure();
  float altitude      = calculateAltitude(pressure, SEA_LEVEL_PRESSURE);

  // --- Serial output (for debugging) ---
  Serial.print("Temp: ");
  Serial.print(temperature, 2);
  Serial.print(" C  Pressure: ");
  Serial.print(pressure, 2);
  Serial.print(" hPa  Alt: ");
  Serial.print(altitude, 2);
  Serial.println(" m");

  // --- LCD output ---
  // Line 1: Temperature and Pressure
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.write((byte)0); // custom degree symbol (slot 0)
  lcd.print("C P:");
  lcd.print(pressure, 0);
  lcd.print("   "); // clear leftover chars from longer previous values

  // Line 2: Altitude
  lcd.setCursor(0, 1);
  lcd.print("Alt: ");
  lcd.print(altitude, 2);
  lcd.print(" m   ");

  delay(1000);
}

float calculateAltitude(float pressure, float seaLevelPressure) {
  return 44330.0 * (1.0 - pow(pressure / seaLevelPressure, 0.1903));
}
