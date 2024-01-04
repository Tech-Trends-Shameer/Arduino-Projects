//Tech Trends Shameer
//Distance Measurement Display in OLED

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>  
#include <Adafruit_Sensor.h>
 


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET 4
//Adafruit_SH1106 display(OLED_RESET);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);  
 

#define BLUE 0x001F
 

#define trigPin 7 //Sensor Echo pin connected to Arduino pin 7
#define echoPin 6 //Sensor Trip pin connected to Arduino pin 6

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 // display.begin(SH1106_SWITCHCAPVCC, 0x3C);
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  delay(2000);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
 //  display.setTextColor(BLUE);
}

void loop() {
  delay(2000);

 long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
    Serial.print(distance);
  //clear display
  display.clearDisplay();

  // display Distance
  display.setTextSize(1);
  display.setCursor(0,7);
  //display.setTextColor(BLUE);
  display.print("Distance: ");
  display.setTextSize(2);
  display.setCursor(0,16);
  display.print(distance);
  display.print(" ");
  display.setTextSize(1);
 // display.cp437(true);
//  display.write(167);
  display.setTextSize(2);
 // display.print("C");
   
  
  display.display(); 
}
