//Tech Trends Shameer
//Temperature, Pressure, Altitude Data Log into SD Card

#include <SPI.h>        // Include SPI library (needed for the SD card)
#include <SD.h>         // Include SD library
//#include <DHT.h>        // Include DHT sensor library
#include <Adafruit_BMP280.h>
 
File dataFile;
 

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

Adafruit_BMP280 bmp; // I2C

  byte degree_symbol[8] = 
              {
                0b00111,
                0b00101,
                0b00111,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000
              };
 
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

  Serial.println(F("BMP280 test"));

  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  delay(2000);
  //dht.begin();
}
 
uint16_t line = 1;
 
void loop() {
  delay(1000);
  // Read humidity
  //byte RH = dht.readHumidity();
  //Read temperature in degree Celsius
  //byte Temp = dht.readTemperature();

   float temp = bmp.readTemperature();
   float pressure = bmp.readPressure();
   float alt = bmp.readAltitude(1013.25);
  
  dataFile = SD.open("BMP280.txt", FILE_WRITE);
  
  // if the file opened okay, write to it:
  if (dataFile) 
  {
    Serial.print(line);
    Serial.print(":    Temperature = ");
    Serial.print(temp);
    Serial.print("°C,    Pressure = ");
    Serial.print(pressure);
    Serial.println("%,   Altitude = ");
    Serial.print(alt);
     Serial.println("m");
    // Write data to SD card file (DHT11Log.txt)
    dataFile.print(line++);
    dataFile.print(":    Temperature = ");
    dataFile.print(temp);
    dataFile.print("°C,    Pressure = ");
    dataFile.print(pressure);
    dataFile.print("%,    Altitude =");    
    dataFile.print(alt);
    dataFile.println("m");
    dataFile.close();
    
  }
  // if the file didn't open, print an error:
  else
    Serial.println("error opening BMP280.txt");
}
