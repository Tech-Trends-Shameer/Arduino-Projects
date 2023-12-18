//Tech Trends Shameer
//Display Temperature, Pressure & Altitude in LCD
 
/*
 * 
***************************************************************************
  This is a library for the BMP280 humidity, temperature & pressure sensor
  Get library from: https://github.com/adafruit/Adafruit_BMP280_Library
  This code has been downloaded from Robojax.com 
  Watch video instruction of this code: https://youtu.be/InNHrtnZgUQ
  Video Recorded Jane 22, 2019 in Ajax, Ontario Canada
  by Ahmad Shamshiri

  Designed specifically to work with the Adafruit BMEP280 Breakout
  ----> http://www.adafruit.com/products/2651

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 **************************************************************************
*/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include <LiquidCrystal_I2C.h>

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);


LiquidCrystal_I2C lcd(0x27, 16, 2); 
  byte degree_symbol[8] = 
              {
                0b00111,
                0b00101,
                0b00111,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000
              };
void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));

  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */



  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Tech Trends");
  lcd.setCursor(5,1);
  lcd.print("Shameer");
  delay(5000);
  lcd.clear();
}

void loop() {
   
    float temp = bmp.readTemperature();
    float pressure = bmp.readPressure();
    float alt = bmp.readAltitude(1013.25);
    Serial.print(F("Temperature = "));
    Serial.print(temp);
    Serial.println(" *C");
    
    Serial.print(F("Pressure = "));
    Serial.print(pressure);
    Serial.println(" Pa");

    Serial.print(F("Approx altitude = "));
    Serial.print(alt); /* Adjusted to local forecast! */
    Serial.println(" m");



    Serial.println();
   // delay(2000);

    lcd.setCursor(0,0);
    lcd.print("Temperature "); 
    lcd.setCursor(0,1);
    lcd.print(temp);
    lcd.setCursor(6,1);
    lcd.write(1);
    lcd.createChar(1, degree_symbol);
    lcd.setCursor(7,1);
    lcd.print("C");
    delay(8000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pressure    ");
    lcd.setCursor(0,1);
    lcd.print(pressure);
    lcd.print(" pa");
    delay(8000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Altitude "); 
    lcd.setCursor(0,1);    
    lcd.print(alt);
    lcd.print(" m");
    delay(8000);
    lcd.clear();
    
  
}
