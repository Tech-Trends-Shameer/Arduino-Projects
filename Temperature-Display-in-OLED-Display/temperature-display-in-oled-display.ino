//Tech Trends Shameer
//Temperature and Humidity Display in OLED

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>  
#include <Adafruit_Sensor.h>
#include "DHT.h"


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET 4
//Adafruit_SH1106 display(OLED_RESET);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);  
#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define BLUE 0x001F

// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
 // display.begin(SH1106_SWITCHCAPVCC, 0x3C);
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  delay(2000);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
 //  display.setTextColor(BLUE);
}

void loop() {
  delay(2000);

  //read temperature and humidity
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
  }
Serial.println(t);
Serial.println(h);
  //clear display
  display.clearDisplay();

  // display temperature
  display.setTextSize(1);
  display.setCursor(0,7);
  //display.setTextColor(BLUE);
  display.print("Temperature: ");
  display.setTextSize(2);
  display.setCursor(0,16);
  display.print(t);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");
  
  // display humidity
  display.setTextSize(1);
  display.setCursor(0, 37);
  display.print("Humidity: ");
  display.setTextSize(2);
  display.setCursor(0, 50);
  display.print(h);
  display.print(" %"); 
  
  display.display(); 
}
