//Tech Trends Shameer
//Facial Expressions Display

#include "LedControl.h"
#include "binary.h"

/*
 DIN connects to pin 12 10
 CLK connects to pin 11  8
 CS connects to pin 10 9
*/
LedControl lc=LedControl(10,8,9,1);

unsigned long delaytime=5000; //Delay time between each expression display


byte hf[8]= {B00111100,B01000010,B10100101,B10000001,B10100101,B10011001,B01000010,B00111100}; //Happy Face
byte sf[8]= {B00111100,B01000010,B10100101,B10000001,B10011001,B10100101,B01000010,B00111100}; //Sad Face
byte nf[8]={B00111100, B01000010,B10100101,B10000001,B10111101,B10000001,B01000010,B00111100}; //Neutral Faec
byte A[8]= {B00000000,B00111100,B01100110,B01100110,B01111110,B01100110,B01100110,B01100110};  //Alphabet
byte heart[8] = {B01100110,B11111111, B11111111, B11111111, B01111110, B00111100, B00011000, B00000000}; //Heart
byte thumbsup[8]= {B00000000, B01000000, B01100000, B01111100, B01000010, B01000010, B01111100, B00000000}; //Thumbsup
 
 
void setup() {
  lc.shutdown(0,false);
  // Set brightness to a medium value
  lc.setIntensity(0,8);
  // Clear the display
  lc.clearDisplay(0);  
}

void drawFaces(){

  // Display Happy Face
  lc.setRow(0,0,hf[0]);
  lc.setRow(0,1,hf[1]);
  lc.setRow(0,2,hf[2]);
  lc.setRow(0,3,hf[3]);
  lc.setRow(0,4,hf[4]);
  lc.setRow(0,5,hf[5]);
  lc.setRow(0,6,hf[6]);
  lc.setRow(0,7,hf[7]);
  delay(delaytime);

  //Display Sad Face
  lc.setRow(0,0,sf[0]);
  lc.setRow(0,1,sf[1]);
  lc.setRow(0,2,sf[2]);
  lc.setRow(0,3,sf[3]);
  lc.setRow(0,4,sf[4]);
  lc.setRow(0,5,sf[5]);
  lc.setRow(0,6,sf[6]);
  lc.setRow(0,7,sf[7]);
  delay(delaytime);
  
  //Display Neutral Face
  lc.setRow(0,0,nf[0]);
  lc.setRow(0,1,nf[1]);
  lc.setRow(0,2,nf[2]);
  lc.setRow(0,3,nf[3]);
  lc.setRow(0,4,nf[4]);
  lc.setRow(0,5,nf[5]);
  lc.setRow(0,6,nf[6]);
  lc.setRow(0,7,nf[7]);
  delay(delaytime);

 


  //Display Alphabet
  lc.setRow(0,0,A[0]);
  lc.setRow(0,1,A[1]);
  lc.setRow(0,2,A[2]);
  lc.setRow(0,3,A[3]);
  lc.setRow(0,4,A[4]);
  lc.setRow(0,5,A[5]);
  lc.setRow(0,6,A[6]);
  lc.setRow(0,7,A[7]);
  delay(delaytime);
  
  //Display Heart
  lc.setRow(0,0,heart[0]);
  lc.setRow(0,1,heart[1]);
  lc.setRow(0,2,heart[2]);
  lc.setRow(0,3,heart[3]);
  lc.setRow(0,4,heart[4]);
  lc.setRow(0,5,heart[5]);
  lc.setRow(0,6,heart[6]);
  lc.setRow(0,7,heart[7]);
  delay(delaytime);

  //Display Thumbsup
  lc.setRow(0,0,thumbsup[0]);
  lc.setRow(0,1,thumbsup[1]);
  lc.setRow(0,2,thumbsup[2]);
  lc.setRow(0,3,thumbsup[3]);
  lc.setRow(0,4,thumbsup[4]);
  lc.setRow(0,5,thumbsup[5]);
  lc.setRow(0,6,thumbsup[6]);
  lc.setRow(0,7,thumbsup[7]);
  delay(delaytime);   
}

void loop(){
  drawFaces();
}
