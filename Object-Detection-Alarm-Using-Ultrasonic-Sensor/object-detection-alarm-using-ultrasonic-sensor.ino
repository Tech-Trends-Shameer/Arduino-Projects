//Tech Trends Shameer
//Object Detection Alarm

// Define pins numbers
const int trigPin = 13;  //Connect Trig pin in Ultrasonic Sensor to Arduino Pin 13
const int echoPin = 12;  //Connect Echo pin in Ultrasonic Sensor to Arduino Pin 13
const int buzzer = 11;   //Connect Positive pin of Buzzer to Arduino Pin 11
const int ledPin = 10;   //Connect Positive pin of LED to Arduino Pin 10

// Define variables
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 15 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculate the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 8){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}

// Print the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
