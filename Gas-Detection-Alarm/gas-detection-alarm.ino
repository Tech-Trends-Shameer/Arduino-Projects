//Tech Trends Shameer
//Gas Detection Alarm

int redLed = 9;
int blueLed = 10;
int buzzer = 8;
int smokeA0 = A0;
// Threshold value
int sensorThres = 100;
 
void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
  
}
 
void loop() {
  int analogSensor = analogRead(smokeA0);
 
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
   
  // Checks if it has reached the threshold value
  if (analogSensor-50 > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    
    digitalWrite(blueLed, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, HIGH);
   
    noTone(buzzer);
  }
  delay(500); 
}
