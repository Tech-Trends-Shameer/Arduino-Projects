//Tech Trends Shameer
//Remote Control Home Automation

#include <IRremote.hpp>

#define IR_RECEIVE_PIN 11

int bulb1 = 3;
int bulb2 = 5;
int bulb3 = 7;
int bulb4 = 9;
int itsONled[] = {0, 0, 0, 0};

#define code1 0x758AFD01 // Code received from remote button no. 7
#define code2 0x748BFD01 // Code received from remote button no. 8
#define code3 0x3BC4FD01 // Code received from remote button no. 9
#define code4 0x7887FD01 // Code received from remote button no. 0 


void setup()
{
  Serial.begin(9600);
  Serial.println("Press the keys on the Remote");
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK); // Start the receiver without LED feedback
  pinMode(bulb1, OUTPUT);
  pinMode(bulb2, OUTPUT);
  pinMode(bulb3, OUTPUT);
  pinMode(bulb4, OUTPUT);
}

void loop()
{
  if (IrReceiver.decode())
  {
    uint32_t value = IrReceiver.decodedIRData.decodedRawData;

    switch (value)
    {
    case code1:
      if (itsONled[1] == 1)
      { // if first led is on then
        digitalWrite(bulb1, LOW); // Turn the LED off when the button is pressed
        itsONled[1] = 0;          // and set its state as off
      }
      else
      { // else if first led is off
        digitalWrite(bulb1, HIGH); // Turn the LED ON when the button is pressed
        itsONled[1] = 1;          // and set its state as on
      }
      break;
    case code2:
      if (itsONled[2] == 1)
      {
        digitalWrite(bulb2, LOW);
        itsONled[2] = 0;
      }
      else
      {
        digitalWrite(bulb2, HIGH);
        itsONled[2] = 1;
      }
      break;
    case code3:
      if (itsONled[3] == 1)
      {
        digitalWrite(bulb3, LOW);
        itsONled[3] = 0;
      }
      else
      {
        digitalWrite(bulb3, HIGH);
        itsONled[3] = 1;
      }
      break;
      case code4:
      if (itsONled[4] == 1)
      {
        digitalWrite(bulb4, LOW);
        itsONled[4] = 0;
      }
      else
      {
        digitalWrite(bulb4, HIGH);
        itsONled[4] = 1;
      }
      break;
    }

    Serial.println(value, HEX); // Print the value in Serial Monitor
    IrReceiver.resume();         // Receive the next value
  }
}
