//Tech Trends Shameer
//Automatic Door Opening using IR Sensor

#include <Servo.h>

#include <Servo.h>

Servo tap_servo;

int sensor_pin = 4;
int tap_servo_pin =5;
int val;

void setup(){
  pinMode(sensor_pin,INPUT);
  tap_servo.attach(tap_servo_pin);
   Serial.begin(9600);
}

void loop(){
  val = digitalRead(sensor_pin);
  Serial.println(val);
  if (val==0)
  {
    tap_servo.write(0);
    delay(2000);
    tap_servo.write(180);
  }
  /*if (val==1)
  {
    tap_servo.write(180);
    
  }*/
}
