/*
  SHT40 Direct Measurement — Live Temp/Humidity on 16x2 I2C LCD
  Arduino Uno + SHT40 + 16x2 I2C LCD (PCF8574 backpack)

  Simple, no cloud/dashboard: reads the SHT40 directly and prints
  temperature (C) and humidity (%) to a 16x2 character LCD.

  Wiring (Uno):
  - SHT40 SDA   -> Uno A4 (fixed I2C data pin on Uno, no need to define)
  - SHT40 SCL   -> Uno A5 (fixed I2C clock pin on Uno)
  - SHT40 VCC   -> 5V
  - SHT40 GND   -> GND

  - LCD SDA     -> Uno A4 (shared I2C bus)
  - LCD SCL     -> Uno A5 (shared I2C bus)
  - LCD VCC     -> 5V
  - LCD GND     -> GND

  Unlike the ESP32 version, the Uno's I2C pins are fixed at A4 (SDA) and
  A5 (SCL) — you don't set them in code, Wire.begin() uses them automatically.
  Both devices share the same two lines since they sit at different I2C
  addresses (SHT40 defaults to 0x44, LCD backpack usually 0x27 or 0x3F).

  Libraries needed (install via Arduino Library Manager):
  - "Adafruit SHT4x" by Adafruit
  - "LiquidCrystal I2C" by Frank de Brabander (or similar fork)

  Note: the Uno has much less RAM than the ESP32 (2KB vs ~300KB), so keep
  this sketch lean if you extend it later — avoid adding heavy libraries
  (e.g. cloud/WiFi ones don't apply here anyway since Uno has no WiFi).

  Before uploading:
  - Run an I2C scanner sketch once if unsure of your LCD's address
    (0x27 and 0x3F are the two most common) and update LCD_ADDRESS below.
*/

#include <Wire.h>
#include <Adafruit_SHT4x.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDRESS 0x27   // change to 0x3F if 0x27 doesn't work
#define LCD_COLS    16
#define LCD_ROWS    2

Adafruit_SHT4x sht4 = Adafruit_SHT4x();
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLS, LCD_ROWS);

void setup() {
  Serial.begin(9600);
  Wire.begin(); // Uno uses fixed A4 (SDA) / A5 (SCL), no pins to pass

  // --- Init LCD ---
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Tech Trends");
  lcd.setCursor(3,1);
  lcd.print("Shameer");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SHT40 starting..");

  // --- Init SHT40 ---
  if (!sht4.begin()) {
    Serial.println("SHT40 not found. Check wiring.");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SHT40 not found");
    lcd.setCursor(0, 1);
    lcd.print("Check wiring");
    while (1) delay(10);
  }

  // balance accuracy vs power/heat; medium precision is fine for direct display
  sht4.setPrecision(SHT4X_MED_PRECISION);
  sht4.setHeater(SHT4X_NO_HEATER);

  lcd.clear();
  Serial.println("SHT40 + LCD ready.");
}

void loop() {
  sensors_event_t humidity, temp;
  sht4.getEvent(&humidity, &temp); // populates temp and humidity objects

  float tempC = temp.temperature;
  float humidityPct = humidity.relative_humidity;

  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.print(" C   Humidity: ");
  Serial.print(humidityPct);
  Serial.println(" %");

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC, 1);
  lcd.print((char)223); // degree symbol
  lcd.print("C   ");    // trailing spaces to clear leftover digits

  lcd.setCursor(0, 1);
  lcd.print("Hum:  ");
  lcd.print(humidityPct, 1);
  lcd.print("%   ");

  delay(1000); // update every second
}
