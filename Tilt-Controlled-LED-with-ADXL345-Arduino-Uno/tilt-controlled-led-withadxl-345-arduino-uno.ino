#include <Wire.h>

#define ADXL_ADDR 0x53
#define MODE_LEVEL 1     // 1 = one LED moves, 0 = bar fills up
#define USE_PITCH 0      // 0 = use roll, 1 = use pitch

const int ledPins[5] = {2, 3, 4, 5, 6};
float smoothAngle = 0;

void writeReg(byte reg, byte val) {
  Wire.beginTransmission(ADXL_ADDR);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();
}

void readAccel(float &x, float &y, float &z) {
  Wire.beginTransmission(ADXL_ADDR);
  Wire.write(0x32);
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL_ADDR, 6);
  int16_t rx = Wire.read() | (Wire.read() << 8);
  int16_t ry = Wire.read() | (Wire.read() << 8);
  int16_t rz = Wire.read() | (Wire.read() << 8);
  x = rx / 256.0;
  y = ry / 256.0;
  z = rz / 256.0;
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
  writeReg(0x2D, 0x08);
  writeReg(0x31, 0x08);
  for (int i = 0; i < 5; i++) pinMode(ledPins[i], OUTPUT);
}

void loop() {
  float x, y, z;
  readAccel(x, y, z);

  float roll  = atan2(y, z) * 180.0 / PI;
  float pitch = atan2(-x, sqrt(y * y + z * z)) * 180.0 / PI;

  float angle = USE_PITCH ? pitch : roll;
  angle = constrain(angle, -60, 60);
  smoothAngle = 0.8 * smoothAngle + 0.2 * angle;

  for (int i = 0; i < 5; i++) digitalWrite(ledPins[i], LOW);

#if MODE_LEVEL
  int pos = ((int)smoothAngle + 75) / 30;
  pos = constrain(pos, 0, 4);
  digitalWrite(ledPins[pos], HIGH);
#else
  int level = map((int)smoothAngle, -60, 60, 0, 6);
  level = constrain(level, 0, 5);
  for (int i = 0; i < level; i++) digitalWrite(ledPins[i], HIGH);
#endif

  Serial.print("X: ");     Serial.print(x, 2);
  Serial.print("  Y: ");   Serial.print(y, 2);
  Serial.print("  Z: ");   Serial.print(z, 2);
  Serial.print("  Roll: ");  Serial.print(roll, 1);
  Serial.print("  Pitch: "); Serial.print(pitch, 1);
  Serial.print("  Used: "); Serial.println(smoothAngle, 1);

  delay(50);
}
