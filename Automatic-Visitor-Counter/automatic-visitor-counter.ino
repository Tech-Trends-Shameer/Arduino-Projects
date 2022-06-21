
//Tech Trends Shameer
//Visitor Counter

#include <Wire.h>
#include <LiquidCrystal.h>
#define trigPin 13 //Sensor Echo pin connected to Arduino pin 13
#define echoPin 12 //Sensor Trip pin connected to Arduino pin 12
//Create Liquid Crystal Object called LCD
LiquidCrystal lcd(11, 10, 5, 4, 3, 2);
int counter = 0;
int currentState1 = 0;
int previousState1 = 0;
int currentState2 = 0;
int previousState2 = 0;
int inside = 0;
int outside = 0;

void setup()
{
// Initialize the LCD
lcd.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD
//Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop()
{
lcd.setCursor(0, 0); //Set cursor to first column of first row
lcd.print("IN: ");
lcd.setCursor(8, 0);
lcd.print("OUT: ");
lcd.setCursor(0, 1);  //Set cursor to first column of second row
lcd.print("Total Inside: ");
long duration, distance;
digitalWrite(trigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH);
delayMicroseconds(10); 
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance <= 7){
currentState1 = 1;
}
else {
currentState1 = 0;
}
delay(100);
if(currentState1 != previousState1){
if(currentState1 == 1){
counter = counter + 1;}
lcd.setCursor(14, 1);
lcd.print(counter);
inside = inside +1;}
lcd.setCursor(4, 0);
lcd.print(inside);
if (distance > 7 && distance <= 14){
currentState2 = 1;
}
else {
currentState2 = 0;
}
delay(100);
if(currentState2 != previousState2){
if(currentState2 == 1){
counter = counter - 1;}
lcd.setCursor(14, 1);
lcd.print(counter);
outside = outside +1;}
lcd.setCursor(13, 0);
lcd.print(outside);
lcd.setCursor(14, 1);
lcd.print(counter);
if (counter > 9 || counter < 0){
lcd.setCursor(14, 1);
lcd.print(counter);
delay(100);
lcd.clear();
 }
}
