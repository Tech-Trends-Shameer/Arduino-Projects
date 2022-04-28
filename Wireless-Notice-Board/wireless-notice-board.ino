//Tech Trends Shameer
//Wireless Display Board

#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

//Create Liquid Crystal Object called LCD
LiquidCrystal lcd (4, 5, 6, 7, 8, 9);
SoftwareSerial mySerial (2, 3);   //(Connect TX, RX from bluetooth to Pin 2,3 in Arduino);

String val = "No Data";
String oldval;
String newval = "No Data";
int i = 0;

void setup() 
{
  // Initialize the LCD
  lcd.begin(16,2);  //Tell Arduino to start your 16 column 2 row LCD
  mySerial.begin(9600);
  Serial.begin(9600);
  lcd.setCursor(0, 0);  //Set cursor to first column of first row
  lcd.print("Tech Trends");
  lcd.setCursor(0, 1);          //Set cursor to first column of second row
  lcd.print("          ");
  delay(280000);
  lcd.clear();
  lcd.print("Welcome!");
  delay(8000);
}

void loop() 
{
  val = mySerial.readString();
  val.trim();
  Serial.println(val);
  if(val != oldval)
  {
    newval = val;
  }
  lcd.clear();
  lcd.setCursor(i, 0);
  lcd.print(newval);
  i++;
  if(i >= 15)
  {
    i = 0;
  }
  val = oldval;
}
