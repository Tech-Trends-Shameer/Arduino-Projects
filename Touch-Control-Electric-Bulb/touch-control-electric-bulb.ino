//Tech Trends Shameer
//Touch Control Bulb

int LD = 200;  

void setup() {
    Serial.begin(9600);
    // out pins
    pinMode(10, OUTPUT);// LED for button 1         

    // input pins
    pinMode(2, INPUT);// Button 1 input pin 2     

    Serial.println("Robojax Test: TTP223B touch");
}

void loop() {
    // button 1 action
    if(digitalRead(2)){
      Serial.println("Button Touched "); 
      digitalWrite(10, LOW); // Turn the LED ON     
      delay(LD); 
    }else{
      digitalWrite(10, HIGH);// Turn OFF the LED
    }

}

    



  
