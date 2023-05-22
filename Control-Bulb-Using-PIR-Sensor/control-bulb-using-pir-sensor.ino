//Tech Trends Shameer
//Control Electric Bulb using PIR Sensor

int pirsensor = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);  //Connect the Signal Pin of relay to Pin 13
  pinMode(4, OUTPUT);  //Connect the Positive Pin of Buzzer to Pin 4
  pinMode(2, INPUT);   //Connect the Output pin of PIR Sensor to Pin 2
  
}
void loop() {
  int pirsensor = digitalRead(2);
  Serial.println(pirsensor);
  if (pirsensor == 1) 
  {
    digitalWrite(13, HIGH);  
    digitalWrite(4, HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
    digitalWrite(4, LOW);
  }
  delay(10);
}
