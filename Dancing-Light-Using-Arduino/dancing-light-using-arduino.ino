//Tech Trends Shameer
//Dancing LED

int sound = 5;
int led1=7;
int led2=8;
int led3=9;
int led4=10;
int led5=11;
int led6=12;
boolean LEDStatus = false;

void setup()
{
  pinMode (sound,INPUT);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);
  pinMode (led5, OUTPUT);
  pinMode (led6, OUTPUT);
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
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led4,HIGH);
      digitalWrite(led5,HIGH);
      digitalWrite(led6,HIGH);
    }
   else
   {
    LEDStatus=false;
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
   }
 }
}
