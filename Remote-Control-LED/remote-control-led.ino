//Tech Trends Shameer
//Remote Control LED

#include <IRremote.h>

int RECV_PIN = 11; // the pin where you connect the output pin of sensor
int led1 = 3;
int led2 = 5;
int led3 = 7;
int itsONled[] = {0,0,0,0};
 
#define code1 29070 // Code received from remote button no. 4
#define code2 61710 // Code received from remote button no. 5
#define code3 5100 //  Code received from remote button no. 6

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
Serial.begin(9600); 
Serial.println("Press the keys in Remote");
irrecv.enableIRIn(); // Start the receiver
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
}

void loop() {
if (irrecv.decode(&results)) 
{
  unsigned int value = results.value;
  switch(value) 
  {
    case code1:
    if(itsONled[1] == 1) 
    { // if first led is on then
      digitalWrite(led1, LOW); // Turn the LED off when button is pressed
      itsONled[1] = 0; // and set its state as off
    } 
    else 
    { // else if first led is off
      digitalWrite(led1, HIGH); // Turn the LED ON when the button is pressed
      itsONled[1] = 1; // and set its state as on
    }
    break;
    case code2:
    if(itsONled[2] == 1) 
    {
      digitalWrite(led2, LOW);
      itsONled[2] = 0;
    } 
    else 
    {
      digitalWrite(led2, HIGH);
      itsONled[2] = 1;
    }
    break;
    case code3:
    if(itsONled[3] == 1) 
    {
      digitalWrite(led3, LOW);
      itsONled[3] = 0;
    } 
    else 
    {
      digitalWrite(led3, HIGH);
      itsONled[3] = 1;
    }
    break;
  }
  Serial.println(value); // Print the value in Serial Monitor
  irrecv.resume(); // Receive the next value
  }
}
