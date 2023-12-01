//Tech Trends Shameer
//RFID Automatic Door
 
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
 
#define SS_PIN 10
#define RST_PIN 9 

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

Servo tap_servo;

//int sensor_pin = 4;
int tap_servo_pin =5;
int buzzer = 7;
 
void setup() 
{ 
  //pinMode(sensor_pin,INPUT);
  pinMode(buzzer, OUTPUT);
  tap_servo.attach(tap_servo_pin);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Place your RFID card to the reader...");
  Serial.println();
  

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "2C 83 4C 4A") //Replace with your UID of the card/cards that you need to give access
  {
    Serial.println("Authorized access");
    Serial.println(); 
  
  tap_servo.write(0);
    delay(2000);
    tap_servo.write(180);
    delay(3000); 
  }
 
 else   {
    Serial.println(" Access denied"); 
    digitalWrite(buzzer, HIGH);
    delay(3000);        
    digitalWrite(buzzer, LOW);
  }
}
