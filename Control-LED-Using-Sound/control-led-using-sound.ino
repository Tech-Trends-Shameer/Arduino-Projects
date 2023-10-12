//Tech Trends Shameer
//Control LED Using Sound

int sound = 5; //This is the pin number in arduino to connect the output pin from sound sensor.
int led1=7;  //Connect the positive end of LED to pin 7 in Arduino

boolean LEDStatus = false;

void setup()
{
  pinMode (sound,INPUT);
  pinMode (led1, OUTPUT);

}

void loop()
{
  int sensor = digitalRead(sound);

  if (sensor == 1)
  {
    if(LEDStatus==false)
    {
      LEDStatus=true;
      digitalWrite(led1,HIGH);

    }
   else
   {
    LEDStatus=false;
    digitalWrite(led1, LOW);
 
   }
 }
}
