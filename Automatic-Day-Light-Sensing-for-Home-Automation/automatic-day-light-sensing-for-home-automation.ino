//Tech Trends Shameer
//Automatic Day Light Sensing for Home Automation

const int sensorPin = A0; // Connect TEMP600 to analog pin A0
const int relayPin = 2;  // Connect relay or transistor to digital pin D2

void setup() {
  Serial.begin(115200);
  pinMode(sensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  int lightIntensity = analogRead(sensorPin);

  // Adjust the threshold value based on your environment
  //int threshold = 500;
  Serial.print("Light Intensity");
  Serial.println(lightIntensity);
  if (lightIntensity < 150) {
    // Turn on the light
    digitalWrite(relayPin, HIGH);
  } else {
    // Turn off the light
    digitalWrite(relayPin, LOW);
  }

  delay(2000); // Adjust the delay based on your needs
}
