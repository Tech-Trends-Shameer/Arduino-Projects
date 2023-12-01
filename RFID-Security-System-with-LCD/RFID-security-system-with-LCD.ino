//Tech Trends Shameer
//RFID Security System with LCD  

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

 
#define SS_PIN 10
#define RST_PIN 9
 
int buzzer = 5;

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

LiquidCrystal_I2C lcd(0x27, 16, 2); 
void setup() 
{
  
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
   lcd.begin();


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
  display();
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
     
    lcd.clear();
    lcd.print("Authorized Access");
    delay(3000);
    lcd.clear();
    display();
  }
 
 else   {
    Serial.println(" Access denied");
  
    lcd.clear();
    digitalWrite(buzzer, HIGH);
    lcd.print("Access denied");
    
    delay(3000);
    lcd.clear();
    digitalWrite(buzzer, LOW);
    display();

       
      
  }
} 

void display()
{
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Swipe the Card");
}
