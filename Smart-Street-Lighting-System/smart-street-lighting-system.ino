//Tech Trends Shameer
//Smart Street Lighting System

const int sensorPin = A0;  // Connect TEMP600 to analog pin A0
const int relayPins[] = {2, 3, 4, 5};  // Connect relays or transistors to digital pins D2, D3, D4, D5
const int numRelays = 4;  // Number of bulbs

void setup() {
  Serial.begin(115200);
  pinMode(sensorPin, INPUT);

  // Set relay pins as OUTPUT
  for (int i = 0; i < numRelays; i++) {
    pinMode(relayPins[i], OUTPUT);
  }
}

void loop() {
  int lightIntensity = analogRead(sensorPin);

  // Adjust the threshold value based on your environment
  int threshold = 500;
  Serial.print("Light Intensity: ");
  Serial.println(lightIntensity);

  if (lightIntensity < 150) {
    // Turn on all the bulbs with a delay
    for (int i = 0; i < numRelays; i++) {
      digitalWrite(relayPins[i], HIGH);
      delay(1000); // Adjust the delay based on your needs

    }
    
    // Turn off all the bulbs
  /*  for (int i = 0; i < numRelays; i++) {
      digitalWrite(relayPins[i], LOW);
    }*/
  } else {
    // Ensure all bulbs are off if the light intensity is sufficient
    for (int i = 0; i < numRelays; i++) {
      digitalWrite(relayPins[i], LOW);
       delay(1000); // Adjust the delay based on your needs
    }
  }

 
}
