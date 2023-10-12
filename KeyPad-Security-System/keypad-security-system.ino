//Tech Trends Shameer
//KeyPad Security Lock System
 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include<EEPROM.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
char password[4];
char initial_password[4],new_password[4];
int i=0;
int relay_pin = 10;
char key_pressed=0;
const byte rows = 4; 
const byte columns = 4; 
char hexaKeys[rows][columns] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte row_pins[rows] = {9,8,7,6};
byte column_pins[columns] = {5,4,3,2};   
Keypad keypad_key = Keypad( makeKeymap(hexaKeys), row_pins, column_pins, rows, columns);

void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Tech Trends");
  delay(2000);
  pinMode(relay_pin, OUTPUT); 
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("KeyPad Lock");
  lcd.setCursor(4,1);
  lcd.print("System");
  delay(2000);
  lcd.clear();
  lcd.print("Enter Password");
  lcd.setCursor(0,1);
  initialpassword();
}

void loop()
{
  digitalWrite(relay_pin, HIGH);
  key_pressed = keypad_key.getKey();
  if(key_pressed=='#')
    change();
  if (key_pressed)
  {
    password[i++]=key_pressed;
    lcd.print(key_pressed);
  }
  if(i==4)
  {
    delay(200);
    for(int j=0;j<4;j++)
    initial_password[j]=EEPROM.read(j);
    if(!(strncmp(password, initial_password,4)))
    {
      lcd.clear();
      lcd.print("Pass Accepted");
      digitalWrite(relay_pin, LOW);
      delay(3000);
      lcd.setCursor(0,1);
      lcd.print("Pres # to change");
      delay(2000);
      lcd.clear();
      lcd.print("Enter Password:");
      lcd.setCursor(0,1);
      i=0;    
    }
    else
    {
      digitalWrite(relay_pin, HIGH);
      lcd.clear();
      lcd.print("Wrong Password");
      lcd.setCursor(0,1);
      delay(3000);
      lcd.print("Pres # to Change");
      delay(2000);
      lcd.clear();
      lcd.print("Enter Password");
      lcd.setCursor(0,1);
      i=0;
    }
  }
}

void change()
{
  int j=0;
  lcd.clear();
  lcd.print("Current Password");
  lcd.setCursor(0,1);
  while(j<4)
  {
    char key=keypad_key.getKey();
    if(key)
    {
      new_password[j++]=key;
      lcd.print(key);    
    }
    key=0;
  }
  delay(500);
  if((strncmp(new_password, initial_password, 4)))
  {
    lcd.clear();
    lcd.print("Wrong Password");
    lcd.setCursor(0,1);
    lcd.print("Try Again");
    delay(1000);
  }
  else
  {
    j=0;
    lcd.clear();
    lcd.print("New Password:");
    lcd.setCursor(0,1);
    while(j<4)
    {
      char key=keypad_key.getKey();
      if(key)
      {
        initial_password[j]=key;
        lcd.print(key);
        EEPROM.write(j,key);
        j++;
      }
    }
    delay(3000);
    lcd.print("Pass Changed");
    delay(1000);
  }
  lcd.clear();
  lcd.print("Enter Password");
  lcd.setCursor(0,1);
  key_pressed=0;
}

void initialpassword()
{
  for(int j=0;j<4;j++)
  EEPROM.write(j, j+49);
  for(int j=0;j<4;j++)
  initial_password[j]=EEPROM.read(j);
} 
