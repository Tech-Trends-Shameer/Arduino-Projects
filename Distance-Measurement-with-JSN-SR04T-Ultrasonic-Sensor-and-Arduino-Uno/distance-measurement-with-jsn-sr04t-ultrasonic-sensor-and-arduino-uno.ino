//Tech Trends Shameer
//Distance Measurement

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define TRIG 11 //Module pins
#define ECHO 12

void setup() {

Serial.begin(9600); // Serial monitoring
pinMode(TRIG, OUTPUT); // Initializing Trigger Output and Echo Input
pinMode(ECHO, INPUT_PULLUP);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Welcome To");
  lcd.setCursor(3,1);
  lcd.print("Tech Trends ");
  delay(3000);
  lcd.clear();
}

void loop() {

digitalWrite(TRIG, LOW); // Set the trigger pin to low for 2uS
delayMicroseconds(2);

digitalWrite(TRIG, HIGH); // Send a 10uS high to trigger ranging
delayMicroseconds(20);

digitalWrite(TRIG, LOW); // Send pin low again
int distance = pulseIn(ECHO, HIGH,26000); // Read in times pulse

distance= distance/58; //Convert the pulse duration to distance
//You can add other math functions to calibrate it well

Serial.print("Distance ");
Serial.print(distance);
Serial.println("cm");

lcd.clear();
lcd.print("Distance:");
lcd.setCursor(0,1);
lcd.print(distance,1);
lcd.setCursor(6,1);
lcd.print("cm");
delay(500); 

}
