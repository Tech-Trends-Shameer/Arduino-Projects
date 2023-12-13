/Tech Trends Shameer
//Light Intensity Measurement Using Arduino Uno

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int temt6000Pin = A0;
float light;
int light_value;


void setup() 
{
  Serial.begin(115200);
  lcd.begin();
  //lcd.backlight();
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Tech Trends");
   
  delay(3000);
  lcd.clear();
  pinMode(temt6000Pin, INPUT); //data pin for ambientlight sensor
  lcd.setCursor(0, 0);
  lcd.print("Light Intensity");
}
 
void loop() 
{
  int light_value = analogRead(temt6000Pin);
  light = light_value * 0.0976;// percentage calculation
  Serial.print("Light Value");
   Serial.println(light_value);
   Serial.print("Light %");
  Serial.println(light);
  lcd.setCursor(0, 1);
  lcd.print(light);
   lcd.setCursor(6, 1);
  lcd.print("%");
  delay(2000);
}
