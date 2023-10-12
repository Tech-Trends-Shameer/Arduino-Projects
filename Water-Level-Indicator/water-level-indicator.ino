//Tech Trends Shameer
//Water Level Indicator

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int resval = 0;  // holds the value
int respin = A3; // Water Level Sensor Pin 

  
void setup()
{
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Tech Trends  ");
  lcd.setCursor(0,0);
  delay(2000);
  lcd.setCursor(3,0);
  lcd.print("Water Level");
  lcd.setCursor(4,1);
  lcd.print("Indicator");
  delay(8000);
  lcd.clear();
  
}

void loop()
{
    // set the cursor to column 0, line 1 
  lcd.setCursor(0, 0); 
  lcd.println("Water Level     "); 
  lcd.setCursor(0, 1); 
    
  resval = analogRead(respin); //Read data from analog pin and store it to resval variable
   
  if (resval<=100)
  { 
    lcd.println("Empty           "); 
  } 
  else if (resval>10 && resval<=200)
  { 
    lcd.println("Low              "); 
  } 
  else if (resval>200 && resval<=250)
  { 
    lcd.println("Medium           "); 
  } 
  else if (resval>250)
  { 
    lcd.println("High              "); 
  }
  delay(1000); 
}
