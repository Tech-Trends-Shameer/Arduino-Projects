#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

#define REPORTING_PERIOD_MS     1000

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte smile[] = {
  B00000,
  B01010,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};
byte mod[] = {
  B00000,
  B00000,
  B01010,
  B00000,
  B11111,
  B00000,
  B00000,
  B00000
};
byte sad[] = {
  B00000,
  B01010,
  B00000,
  B00000,
  B01110,
  B10001,
  B00000,
  B00000
};
byte heart[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};
byte neutral[] = {
  B00000,
  B00100,
  B01110,
  B10101,
  B10101,
  B01110,
  B00100,
  B00000
};
PulseOximeter pox;
uint32_t tsLastReport = 0;

void onBeatDetected()
{

  Serial.println("Beat!!!");

}

void setup()
{
  Serial.begin(115200);
  lcd.begin();
  lcd.backlight();
  lcd.createChar(1 , smile);
  lcd.createChar(2 , mod);
  lcd.createChar(3 , sad);
  lcd.createChar(4, heart);  // Add the heart symbol
  lcd.createChar(5, neutral);  // New neutral symbol
  
  // Display "Tech Trends Shameer"
  lcd.setCursor(3, 0);
  lcd.print("Tech Trends ");
  lcd.setCursor(3, 1);
  lcd.print("  Shameer    ");
  delay(3000);  // Wait for 3 seconds

  // Clear the LCD and display "Pulse Oximeter"
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Pulse ");
  lcd.setCursor(3, 1);
  lcd.print("Oximeter   ");
  lcd.setCursor(12, 0);  // Adjust the position for the heart symbol
  lcd.write(4);         // Display the heart symbol
  delay(2000);

  if (!pox.begin()) {
    Serial.println("FAILED");
    for (;;);
  } else {
    Serial.println("SUCCESS");
  }
  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);

  pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop()
{
  pox.update();
  if (millis() - tsLastReport > REPORTING_PERIOD_MS) {

    lcd.clear();
    lcd.setCursor(0 , 0);
    lcd.print("BPM : ");
    lcd.print(pox.getHeartRate());
    lcd.setCursor(12, 0);  // Adjust the position for the heart symbol
    lcd.write(4);         // Display the heart symbol
    lcd.setCursor(0 , 1);
    lcd.print("Sp02: ");
    lcd.print(pox.getSpO2());
    lcd.print("%");
    tsLastReport = millis();

    if (pox.getSpO2() >= 96) {
      lcd.setCursor(12 , 1);
      lcd.write(1);                 
    }
    else if (pox.getSpO2() <= 95 && pox.getSpO2() >= 91) {
      lcd.setCursor(12 , 1);
      lcd.write(2);                 
    }
    else if (pox.getSpO2() <= 90 && pox.getSpO2() >= 1 ) {
      lcd.setCursor(12 , 1);
      lcd.write(3);
    }
    else {
      lcd.setCursor(12 , 1);
      lcd.write(5);  // Display neutral symbol by default
    }
  }
} 
