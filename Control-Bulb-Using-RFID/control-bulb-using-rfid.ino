//Tech Trends Shameer
//Control Bulb Using RFID

#include <SPI.h>
#include <MFRC522.h> 

 
#define SS_PIN 10
#define RST_PIN 9
int relay=6; 
int buzzer = 7;

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
void setup() 
{

  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  /* lcd.begin();


  lcd.backlight();
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Tech Trends");
  lcd.setCursor(5,1);
  lcd.print("Shameer");
  delay(3000);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("RFID Security");
  lcd.setCursor(5,1);
  lcd.print("System");
  delay(3000);
  display();*/
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
  if (content.substring(1) == "2C 83 4C 4A") //Change the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();   
     
    digitalWrite(relay, HIGH);
    digitalWrite(buzzer, LOW);
    delay(3000);
    digitalWrite(relay, LOW); 
  }
 
 else   {
    Serial.println(" Access denied");
   
    digitalWrite(relay, LOW); 
    digitalWrite(buzzer, HIGH);
    delay(3000); 
    digitalWrite(buzzer, LOW);
     

       
      
  }
} 
 
