// Tech Trends Shameer
// Rain Detection Alarm

int rainsense= A0; // analog sensor input pin 0
int buzzerout= 12; // digital output pin 12 in Arduino - buzzer output
int countval= 0; // counter value starting from 0 and goes up by 1 every second
int ledout= 10; // digital output pin 10 in Arduino- led output
 
void setup(){
   Serial.begin(9600);
   pinMode(buzzerout, OUTPUT);
   pinMode(ledout, OUTPUT); 
   pinMode(rainsense, INPUT);
}
void loop(){
   int rainSenseReading = analogRead(rainsense);
   Serial.println(rainSenseReading); // serial monitoring message 
   delay(250);// rain sensing value from 0 to 1023.
   // from heavy rain - no rain.
   if (countval >= 35){ 
      Serial.print("Heavy rain");
      digitalWrite(buzzerout, HIGH);  //raise an alert
      digitalWrite(ledout, HIGH);  // glow LED
   }
   //If its raining for long time increase buzzer sound
   //If there is no rain then reset the counter value
   if (rainSenseReading <500){ 
      countval++; // increment count value
   }
   else if (rainSenseReading >500) { // if there is no rain
      digitalWrite(buzzerout, LOW); // Turn OFF Buzzer 
      digitalWrite(ledout, LOW); // Turn OFF led
      countval = 0; // reset count to 0
   }
   delay(1000);
}
