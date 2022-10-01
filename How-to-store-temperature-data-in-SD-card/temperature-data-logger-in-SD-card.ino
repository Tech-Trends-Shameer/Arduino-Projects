//Tech Trends Shameer
//Temperature Data Log into SD Card

#include <SPI.h>        // Include SPI library (needed for the SD card)
#include <SD.h>         // Include SD library
#include <DHT.h>        // Include DHT sensor library
 
File dataFile;
 
#define DHTPIN 4            // DHT11 data pin is connected to Arduino pin 4
#define DHTTYPE DHT11       // DHT11 sensor is used
DHT dht(DHTPIN, DHTTYPE);   // Initialize DHT library
 
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial)
    ; // wait for serial port to connect. Needed for native USB port only
  Serial.print("Initializing SD card...");
  if (!SD.begin()) 
  {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  delay(2000);
  dht.begin();
}
 
uint16_t line = 1;
 
void loop() {
  delay(1000);
  // Read humidity
  byte RH = dht.readHumidity();
  //Read temperature in degree Celsius
  byte Temp = dht.readTemperature();
  
  dataFile = SD.open("DHT11Log.txt", FILE_WRITE);
  
  // if the file opened okay, write to it:
  if (dataFile) 
  {
    Serial.print(line);
    Serial.print(":    Temperature = ");
    Serial.print(Temp);
    Serial.print("°C,    Humidity = ");
    Serial.print(RH);
    Serial.println("%");
    // Write data to SD card file (DHT11Log.txt)
    dataFile.print(line++);
    dataFile.print(":    Temperature = ");
    dataFile.print(Temp);
    dataFile.print("°C,    Humidity = ");
    dataFile.print(RH);
    dataFile.println("%");
    dataFile.close();
    
  }
  // if the file didn't open, print an error:
  else
    Serial.println("error opening DHT11Log.txt");
}
