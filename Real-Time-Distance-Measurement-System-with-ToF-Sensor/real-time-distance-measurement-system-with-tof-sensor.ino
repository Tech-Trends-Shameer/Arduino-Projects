#include <Wire.h>
#include <Adafruit_VL53L0X.h>
#include <LiquidCrystal_I2C.h>

// Initialize VL53L0X sensor
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

// Initialize LCD (I2C Address 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Serial.begin(115200);
    Wire.begin();

    // Initialize LCD
    lcd.init();
    lcd.backlight();

    // Display Name
    lcd.setCursor(3, 0);
    lcd.print("Tech Trends");
    lcd.setCursor(5, 1);
    lcd.print("Shameer");
    delay(2000);

    // Display Title
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance");
    lcd.setCursor(0, 1);
    lcd.print("Measurement");
    delay(2000);

    // Initialize VL53L0X Sensor
    if (!lox.begin()) {
        Serial.println("Failed to initialize VL53L0X!");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("VL53L0X Error!");
        while (1);
    }

    Serial.println("VL53L0X Ready");
    lcd.clear();
}

void loop() {
    VL53L0X_RangingMeasurementData_t measure;

    // Perform distance measurement
    lox.rangingTest(&measure, false);

    lcd.setCursor(0, 0);
    lcd.print("Distance: ");

    if (measure.RangeStatus != 4) { 
        Serial.print("Distance: ");
        Serial.print(measure.RangeMilliMeter);
        Serial.println(" mm");

        lcd.setCursor(0, 1);
        lcd.print(measure.RangeMilliMeter);
        lcd.print(" mm ");
        delay(2000);
    } else {
        Serial.println("Out of range");

        lcd.setCursor(0, 1);
        lcd.print("Out of range  ");
        delay(3000);
        lcd.clear();
    }

    delay(500);
}
