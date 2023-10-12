//Tech Trends Shameer

#include <SimpleDHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
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

int pinDHT11 = 6;
SimpleDHT11 dht11(pinDHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);
  
void setup() {
  Serial.begin(115200);
}

void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) 
  {
    Serial.print("Read DHT11 failed, err="); 
    Serial.println(err);
    delay(1000);
    return;
  }
  

    lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
 /* lcd.setCursor(0,0);
  lcd.print("Temperature &");
  lcd.setCursor(0,1);
  lcd.print("Humidity Monitor");
  delay(2000);
  lcd.clear();*/
  lcd.setCursor(0,0);
  lcd.print("Temperature "); 
  lcd.print((int)temperature);
  lcd.setCursor(0, 1);
  lcd.print("Humidity    ");
  lcd.print((int)humidity);
  lcd.setCursor(14,0);
  lcd.write(1);
  lcd.createChar(1, degree_symbol);
  lcd.setCursor(15,0);
  lcd.print("C");
  lcd.setCursor(14,1);
  lcd.print("%");
  delay(1000);
}
