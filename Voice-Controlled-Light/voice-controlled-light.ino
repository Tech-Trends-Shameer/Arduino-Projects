//Tech Trends Shameer
//Voice Controlled Light

String voice;

#define relay 12

void setup() 
{                                            // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW); 
}

  int relayVal; 

void loop() {
 
  while (Serial.available())   //Check if there is an available byte to read
  {                            
  delay(10);                   //Delay added to make thing stable
  char c = Serial.read();      //Conduct a serial read
  if (c == '#') {break;}       //Exit the loop when the # is detected after the word
  voice += c;                  //Shorthand for voice = voice + c
  } 

  if (voice.length() > 0) {
    Serial.println(voice);
  //----------Control Light----------// 

       if(voice == "*turn on the light")       // To tune ON the bulb                   
     {
     digitalWrite(relay, HIGH); 
     }  
  else if(voice == "*turn off the light")      // To turn OFF the bulb                        
     {
    digitalWrite(relay, LOW);
     }  
  
voice="";                            //Reset the variable after initiating
}
}
