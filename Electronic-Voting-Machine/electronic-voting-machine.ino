//Tech Trends Shameer
//Electronic Voting Machine

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define v1 7
#define v2 6
#define v3 5
#define v4 4
#define v5 3
int vote1=0;
int vote2=0;
int vote3=0;
int vote4=0;

void setup()
{

 pinMode(v1, INPUT);
 pinMode(v2,INPUT);
 pinMode(v3,INPUT);
 pinMode(v4,INPUT);
 pinMode(v5,INPUT);
 pinMode(13,OUTPUT);
 pinMode(12,OUTPUT);
 
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Tech Trends");
  delay(5000);
  lcd.setCursor(0,0);
  lcd.print("Electronic      ");
  lcd.setCursor(0,1);
  lcd.print("Voting Machine");

  delay(26000);
  digitalWrite(v1, HIGH);
  digitalWrite(v2, HIGH);
  digitalWrite(v3, HIGH);
  digitalWrite(v4, HIGH);
  digitalWrite(v5, HIGH);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("A");
  lcd.setCursor(5,0);
  lcd.print("B");
  lcd.setCursor(9,0);
  lcd.print("C");
  lcd.setCursor(13,0);
  lcd.print("D");
}

void loop()
{
  lcd.setCursor(1,0);
  lcd.print("A");
  lcd.setCursor(1,1);
  lcd.print(vote1);
  lcd.setCursor(5,0);
  lcd.print("B");
  lcd.setCursor(5,1);
  lcd.print(vote2);
  lcd.setCursor(9,0);
  lcd.print("C");
  lcd.setCursor(9,1);
  lcd.print(vote3);
  lcd.setCursor(13,0);
  lcd.print("D");
  lcd.setCursor(13,1);
  lcd.print(vote4);

if(digitalRead(v1)==0)
{ 
  digitalWrite(12,HIGH);
  vote1++;
  while(digitalRead(v1)==0);
  digitalWrite(12,LOW);
  delay(1000);
}

if(digitalRead(v2)==0)
{
  vote2++;
  digitalWrite(12,HIGH);
  while(digitalRead(v2)==0);
  digitalWrite(12,LOW);
  delay(1000);
}

if(digitalRead(v3)==0)
{
  digitalWrite(12,HIGH);
  vote3++;
  while(digitalRead(v3)==0);
  digitalWrite(12,LOW);
  delay(1000);
}

if(digitalRead(v4)==0)
{
digitalWrite(12,HIGH);
vote4++;
while(digitalRead(v4)==0);
digitalWrite(12,LOW);
delay(1000 );
}

if(digitalRead(v5)==0)
{
digitalWrite(13,HIGH);
int vote=vote1+vote2+vote3+vote4;
if(vote)
{
if((vote1 > vote2 && vote1 > vote3 && vote1 > vote4))
{
lcd.clear();
lcd.print("A Wins");
delay(5000);
lcd.clear();
}
else if((vote2 > vote1 && vote2 > vote3 && vote2 > vote4))
{
lcd.clear();
lcd.print("B Wins");
delay(5000);
lcd.clear();
}
else if((vote3 > vote1 && vote3 > vote2 && vote3 > vote4))
{
lcd.clear();
lcd.print("C Wins");
delay(5000);
lcd.clear();
}
else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
{
lcd.setCursor(0,0);
lcd.clear();
lcd.print("D Wins");
delay(5000);
lcd.clear();
} 

else
{
lcd.clear();
lcd.print(" Vote Tied ");
lcd.setCursor(0,1);
lcd.print("   ");
delay(5000);
lcd.clear();
}

}
else
{
  lcd.clear();
  lcd.print("No Vote Polled");
  delay(5000);
  lcd.clear();
}
vote1=0;
vote2=0;
vote3=0;
vote4=0;
vote=0;
lcd.clear();
digitalWrite(12,HIGH);
digitalWrite(13,LOW);
}

}
