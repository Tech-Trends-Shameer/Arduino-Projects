//Tech Trends Shameer
//Control LED using PIR Sensor

int pirsensor = 0; 

void setup() {
Serial.begin(9600);
   pinMode(13, OUTPUT);  //Connect LED Positive to Pin 13
   pinMode(4, OUTPUT);  //Connect Buzzer Positive to Pin 4
   pinMode(2, INPUT);   //Connect PIR Sensor Out pin to Pin 2
  
}
void loop() {
  int pirsensor = digitalRead(2);
  Serial.println(pirsensor);
  if (pirsensor == 1) {
    digitalWrite(13, HIGH); // The Relay Input works Inversly
    digitalWrite(4, HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
    digitalWrite(4, LOW);
  }
  delay(10);
}
