//Tech Trends Shameer
//Soil Moisture Measurement

#include <LiquidCrystal.h>

//Assign the Arduino Pin to the LCD Pin
const int rs = 4, e = 5, d4 = 6, d5 = 7, d6 = 8, d7 = 9;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
int sensoroutput = A0;
int sensorvalue=0;
int prev=0;
int pres=0;
void setup() 
{
  // Initialize the LCD
  lcd.begin(16, 2);              //Tell Arduino to start your 16 column 2 row LCD
  lcd.setCursor(0,0);            //Set cursor to first column of first row
  lcd.print(" Soil Moisture  "); //Print the text Soil Moisture in row 1
  Serial.begin(9600);
}

void loop() 
{
  sensorvalue=analogRead(sensoroutput);
  sensorvalue=map(sensorvalue,0,982,148,0);
  pres=sensorvalue;
  if(sensorvalue>100)
  sensorvalue=100;
  else if(sensorvalue<0)
  sensorvalue=0;
  lcd.setCursor(6,1);       //Set cursor to sixth column of second row
  lcd.print(sensorvalue);
  lcd.print("%  ");
  Serial.println(sensorvalue);
  prev=sensorvalue;
  delay(500);
  
}
