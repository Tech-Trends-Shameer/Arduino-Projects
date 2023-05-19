//Tech Trends Shameer
//Temperature-Monitor-Using-DS18B20-Temperature-Sensor

#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#define DS18B20 4
 
OneWire ourWire(DS18B20);
DallasTemperature sensor(&ourWire);
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
void setup()
{
  Serial.begin(9600);
  delay(1000);
  sensor.begin();
  lcd.begin();
  lcd.createChar(1, degree_symbol);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Tech Trends");
  lcd.setCursor(5,1);
  lcd.print("Shameer");
  delay(3000);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Temp Monitor");
  lcd.setCursor(1,1);
  lcd.print("Using DS18B20");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
}
 
void loop()
{
sensor.requestTemperatures();
Serial.print("Celsius temperature: ");
Serial.print(sensor.getTempCByIndex(0));
Serial.println("°C");
Serial.print("Fahrenheit temperature: ");
Serial.println(sensor.getTempFByIndex(0));
lcd.setCursor(7,0);
lcd.print(sensor.getTempCByIndex(0));
lcd.write(1);
lcd.print("C");
lcd.setCursor(7,1);
lcd.print(sensor.getTempFByIndex(0));
lcd.write(1);
lcd.print("F");
delay(1000);
}
