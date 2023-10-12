//Tech Trends Shameer
//Real Time Clock

// Include the libraries
#include "RTClib.h"
#include <TM1637Display.h>
 
// Define the connections pins
#define CLK 2
#define DIO 3
 
// Create rtc and display object
RTC_DS3231 rtc;
TM1637Display display = TM1637Display(CLK, DIO);
 
void setup() {
  // Begin serial communication
  Serial.begin(9600);
 
  // Check if RTC is connected correctly
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  // Check if the RTC lost power and if so, set the time
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // The following line sets the RTC to the date & time this sketch was compiled:
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
 
  // Set the display brightness (0-7)
  display.setBrightness(5);
  
  // Clear the display
  display.clear();
}
 
void loop() {
  // Get current date and time
  DateTime now = rtc.now();
 
  // Create time format to display
  int displaytime = (now.hour() * 100) + now.minute();
 
  // Display the current time in 24 hour format with leading zeros and a center colon enabled
  display.showNumberDecEx(displaytime, 0b11100000, true);
 
  delay(1000);
}
