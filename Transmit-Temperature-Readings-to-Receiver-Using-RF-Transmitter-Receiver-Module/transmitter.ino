//Tech Trends Shameer
//Transmitter Program 

// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 

// Include DHT Libraries from Adafruit
// Dependant upon Adafruit_Sensors Library
#include "DHT.h";

// Define Constants

#define DHTPIN 7       // DHT-22 Output Pin connection
#define DHTTYPE DHT11   // DHT Type is DHT 22 (AM2302)

// Define Variables

float hum;    // Stores humidity value in percent
float temp;   // Stores temperature value in Celcius

// Define output strings

String str_humid;
String str_temp;
String str_out;

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

void setup() {

  // Initialize ASK Object
  rf_driver.init();
  // Start DHT Sensor
  dht.begin();

   Serial.begin(9600);

}

void loop()
{

  delay(2000);  // Delay so DHT-22 sensor can stabalize
   
    hum = dht.readHumidity();  // Get Humidity value
    temp= dht.readTemperature();  // Get Temperature value
    
    // Convert Humidity to string
    str_humid = String(hum);
    
    // Convert Temperature to string
    str_temp = String(temp);

    // Combine Humidity and Temperature
    str_out = str_humid + "," + str_temp;
    
    // Compose output character
    static char *msg = str_out.c_str();
    
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();

     Serial.print("Humidity: ");
      Serial.print(str_humid);
      Serial.print("  - Temperature: ");
      Serial.println(str_temp);
  
}
