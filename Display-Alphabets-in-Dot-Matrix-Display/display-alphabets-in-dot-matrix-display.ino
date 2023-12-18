//Tech Trends Shameer
//Display Alphabets in Dot Matrix Display

#include "LedControl.h"
#include "binary.h"

/*
 DIN connects to pin 12 10
 CLK connects to pin 11  8
 CS connects to pin 10 9
*/
LedControl lc=LedControl(10,8,9,1);

unsigned long delaytime=2000; //Delay time between each expression display

 
byte A[]= {B00000000,B00111100,B01100110,B01100110,B01111110,B01100110,B01100110,B01100110};    
byte B[] = {B01111000,B01001000,B01001000,B01110000,B01001000,B01000100,B01000100,B01111100};
byte C[] = {B00000000,B00011110,B00100000,B01000000,B01000000,B01000000,B00100000,B00011110};
byte D[] = {B00000000,B00111000,B00100100,B00100010,B00100010,B00100100,B00111000,B00000000};
byte E[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00111100,B00000000};
byte F[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00100000,B00000000};
byte G[] = {B00000000,B00111110,B00100000,B00100000,B00101110,B00100010,B00111110,B00000000};
byte H[] = {B00000000,B00100100,B00100100,B00111100,B00100100,B00100100,B00100100,B00000000};
byte I[] = {B00000000,B00111000,B00010000,B00010000,B00010000,B00010000,B00111000,B00000000};
byte J[] = {B00000000,B00011100,B00001000,B00001000,B00001000,B00101000,B00111000,B00000000};
byte K[] = {B00000000,B00100100,B00101000,B00110000,B00101000,B00100100,B00100100,B00000000};
byte L[] = {B00000000,B00100000,B00100000,B00100000,B00100000,B00100000,B00111100,B00000000};
byte M[] = {B00000000,B00000000,B01000100,B10101010,B10010010,B10000010,B10000010,B00000000};
byte N[] = {B00000000,B00100010,B00110010,B00101010,B00100110,B00100010,B00000000,B00000000};
byte O[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000};
byte P[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100000,B00100000,B00000000};
byte Q[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000110,B00111110,B00000001};
byte R[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100100,B00100100,B00000000};
byte S[] = {B00000000,B00111100,B00100000,B00111100,B00000100,B00000100,B00111100,B00000000};
byte T[] = {B00000000,B01111100,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000};
byte U[] = {B00000000,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000,B00000000};
byte V[] = {B00000000,B00100010,B00100010,B00100010,B00010100,B00010100,B00001000,B00000000};
byte W[] = {B00000000,B10000010,B10010010,B01010100,B01010100,B00101000,B00000000,B00000000};
byte X[] = {B00000000,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B00000000};
byte Y[] = {B00000000,B01000100,B00101000,B00010000,B00010000,B00010000,B00010000,B00000000};
byte Z[] = {B00000000,B00111100,B00000100,B00001000,B00010000,B00100000,B00111100,B00000000};
//byte AZ[] = {B00000000,B00000000,B11100111,B10100001,B11100010,B10100111,B00000000,B00000000};
 
void setup() {
  lc.shutdown(0,false);
  // Set brightness to a medium value
  lc.setIntensity(0,8);
  // Clear the display
  lc.clearDisplay(0);  
}

void displayAlphabets(){
 

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

  //Display B
  lc.setRow(0,0,B[0]);
  lc.setRow(0,1,B[1]);
  lc.setRow(0,2,B[2]);
  lc.setRow(0,3,B[3]);
  lc.setRow(0,4,B[4]);
  lc.setRow(0,5,B[5]);
  lc.setRow(0,6,B[6]);
  lc.setRow(0,7,B[7]);
  delay(delaytime);

    //Display C
  lc.setRow(0,0,C[0]);
  lc.setRow(0,1,C[1]);
  lc.setRow(0,2,C[2]);
  lc.setRow(0,3,C[3]);
  lc.setRow(0,4,C[4]);
  lc.setRow(0,5,C[5]);
  lc.setRow(0,6,C[6]);
  lc.setRow(0,7,C[7]);
  delay(delaytime);

      //Display D
  lc.setRow(0,0,D[0]);
  lc.setRow(0,1,D[1]);
  lc.setRow(0,2,D[2]);
  lc.setRow(0,3,D[3]);
  lc.setRow(0,4,D[4]);
  lc.setRow(0,5,D[5]);
  lc.setRow(0,6,D[6]);
  lc.setRow(0,7,D[7]);
  delay(delaytime);

      //Eisplay E
  lc.setRow(0,0,E[0]);
  lc.setRow(0,1,E[1]);
  lc.setRow(0,2,E[2]);
  lc.setRow(0,3,E[3]);
  lc.setRow(0,4,E[4]);
  lc.setRow(0,5,E[5]);
  lc.setRow(0,6,E[6]);
  lc.setRow(0,7,E[7]);
  delay(delaytime);

      //Fisplay F
  lc.setRow(0,0,F[0]);
  lc.setRow(0,1,F[1]);
  lc.setRow(0,2,F[2]);
  lc.setRow(0,3,F[3]);
  lc.setRow(0,4,F[4]);
  lc.setRow(0,5,F[5]);
  lc.setRow(0,6,F[6]);
  lc.setRow(0,7,F[7]);
  delay(delaytime);

      //Gisplay G
  lc.setRow(0,0,G[0]);
  lc.setRow(0,1,G[1]);
  lc.setRow(0,2,G[2]);
  lc.setRow(0,3,G[3]);
  lc.setRow(0,4,G[4]);
  lc.setRow(0,5,G[5]);
  lc.setRow(0,6,G[6]);
  lc.setRow(0,7,G[7]);
  delay(delaytime);

      //Hisplay H
  lc.setRow(0,0,H[0]);
  lc.setRow(0,1,H[1]);
  lc.setRow(0,2,H[2]);
  lc.setRow(0,3,H[3]);
  lc.setRow(0,4,H[4]);
  lc.setRow(0,5,H[5]);
  lc.setRow(0,6,H[6]);
  lc.setRow(0,7,H[7]);
  delay(delaytime);

      //Iisplay I
  lc.setRow(0,0,I[0]);
  lc.setRow(0,1,I[1]);
  lc.setRow(0,2,I[2]);
  lc.setRow(0,3,I[3]);
  lc.setRow(0,4,I[4]);
  lc.setRow(0,5,I[5]);
  lc.setRow(0,6,I[6]);
  lc.setRow(0,7,I[7]);
  delay(delaytime);

      //JJsplay J
  lc.setRow(0,0,J[0]);
  lc.setRow(0,1,J[1]);
  lc.setRow(0,2,J[2]);
  lc.setRow(0,3,J[3]);
  lc.setRow(0,4,J[4]);
  lc.setRow(0,5,J[5]);
  lc.setRow(0,6,J[6]);
  lc.setRow(0,7,J[7]);
  delay(delaytime);

      //KKsplay K
  lc.setRow(0,0,K[0]);
  lc.setRow(0,1,K[1]);
  lc.setRow(0,2,K[2]);
  lc.setRow(0,3,K[3]);
  lc.setRow(0,4,K[4]);
  lc.setRow(0,5,K[5]);
  lc.setRow(0,6,K[6]);
  lc.setRow(0,7,K[7]);
  delay(delaytime);

      //LLsplay L
  lc.setRow(0,0,L[0]);
  lc.setRow(0,1,L[1]);
  lc.setRow(0,2,L[2]);
  lc.setRow(0,3,L[3]);
  lc.setRow(0,4,L[4]);
  lc.setRow(0,5,L[5]);
  lc.setRow(0,6,L[6]);
  lc.setRow(0,7,L[7]);
  delay(delaytime);

      //MMspMay M
  lc.setRow(0,0,M[0]);
  lc.setRow(0,1,M[1]);
  lc.setRow(0,2,M[2]);
  lc.setRow(0,3,M[3]);
  lc.setRow(0,4,M[4]);
  lc.setRow(0,5,M[5]);
  lc.setRow(0,6,M[6]);
  lc.setRow(0,7,M[7]);
  delay(delaytime);

      //NNspNay N
  lc.setRow(0,0,N[0]);
  lc.setRow(0,1,N[1]);
  lc.setRow(0,2,N[2]);
  lc.setRow(0,3,N[3]);
  lc.setRow(0,4,N[4]);
  lc.setRow(0,5,N[5]);
  lc.setRow(0,6,N[6]);
  lc.setRow(0,7,N[7]);
  delay(delaytime);

    //Display O
  lc.setRow(0,0,O[0]);
  lc.setRow(0,1,O[1]);
  lc.setRow(0,2,O[2]);
  lc.setRow(0,3,O[3]);
  lc.setRow(0,4,O[4]);
  lc.setRow(0,5,O[5]);
  lc.setRow(0,6,O[6]);
  lc.setRow(0,7,O[7]);
  delay(delaytime);

      //Display P
  lc.setRow(0,0,P[0]);
  lc.setRow(0,1,P[1]);
  lc.setRow(0,2,P[2]);
  lc.setRow(0,3,P[3]);
  lc.setRow(0,4,P[4]);
  lc.setRow(0,5,P[5]);
  lc.setRow(0,6,P[6]);
  lc.setRow(0,7,P[7]);
  delay(delaytime);

      //Display q
  lc.setRow(0,0,Q[0]);
  lc.setRow(0,1,Q[1]);
  lc.setRow(0,2,Q[2]);
  lc.setRow(0,3,Q[3]);
  lc.setRow(0,4,Q[4]);
  lc.setRow(0,5,Q[5]);
  lc.setRow(0,6,Q[6]);
  lc.setRow(0,7,Q[7]);
  delay(delaytime);

  //Display R
  lc.setRow(0,0,R[0]);
  lc.setRow(0,1,R[1]);
  lc.setRow(0,2,R[2]);
  lc.setRow(0,3,R[3]);
  lc.setRow(0,4,R[4]);
  lc.setRow(0,5,R[5]);
  lc.setRow(0,6,R[6]);
  lc.setRow(0,7,R[7]);
  delay(delaytime);

  //Display S
  lc.setRow(0,0,S[0]);
  lc.setRow(0,1,S[1]);
  lc.setRow(0,2,S[2]);
  lc.setRow(0,3,S[3]);
  lc.setRow(0,4,S[4]);
  lc.setRow(0,5,S[5]);
  lc.setRow(0,6,S[6]);
  lc.setRow(0,7,S[7]);
  delay(delaytime);

  //Display T
  lc.setRow(0,0,T[0]);
  lc.setRow(0,1,T[1]);
  lc.setRow(0,2,T[2]);
  lc.setRow(0,3,T[3]);
  lc.setRow(0,4,T[4]);
  lc.setRow(0,5,T[5]);
  lc.setRow(0,6,T[6]);
  lc.setRow(0,7,T[7]);
  delay(delaytime);

  //Display U
  lc.setRow(0,0,U[0]);
  lc.setRow(0,1,U[1]);
  lc.setRow(0,2,U[2]);
  lc.setRow(0,3,U[3]);
  lc.setRow(0,4,U[4]);
  lc.setRow(0,5,U[5]);
  lc.setRow(0,6,U[6]);
  lc.setRow(0,7,U[7]);
  delay(delaytime);

  //Display V
  lc.setRow(0,0,V[0]);
  lc.setRow(0,1,V[1]);
  lc.setRow(0,2,V[2]);
  lc.setRow(0,3,V[3]);
  lc.setRow(0,4,V[4]);
  lc.setRow(0,5,V[5]);
  lc.setRow(0,6,V[6]);
  lc.setRow(0,7,V[7]);
  delay(delaytime);

  //Display W
  lc.setRow(0,0,W[0]);
  lc.setRow(0,1,W[1]);
  lc.setRow(0,2,W[2]);
  lc.setRow(0,3,W[3]);
  lc.setRow(0,4,W[4]);
  lc.setRow(0,5,W[5]);
  lc.setRow(0,6,W[6]);
  lc.setRow(0,7,W[7]);
  delay(delaytime);

  //Display X
  lc.setRow(0,0,X[0]);
  lc.setRow(0,1,X[1]);
  lc.setRow(0,2,X[2]);
  lc.setRow(0,3,X[3]);
  lc.setRow(0,4,X[4]);
  lc.setRow(0,5,X[5]);
  lc.setRow(0,6,X[6]);
  lc.setRow(0,7,X[7]);
  delay(delaytime);

  //Display Y
  lc.setRow(0,0,Y[0]);
  lc.setRow(0,1,Y[1]);
  lc.setRow(0,2,Y[2]);
  lc.setRow(0,3,Y[3]);
  lc.setRow(0,4,Y[4]);
  lc.setRow(0,5,Y[5]);
  lc.setRow(0,6,Y[6]);
  lc.setRow(0,7,Y[7]);
  delay(delaytime);

  //Display Z
  lc.setRow(0,0,Z[0]);
  lc.setRow(0,1,Z[1]);
  lc.setRow(0,2,Z[2]);
  lc.setRow(0,3,Z[3]);
  lc.setRow(0,4,Z[4]);
  lc.setRow(0,5,Z[5]);
  lc.setRow(0,6,Z[6]);
  lc.setRow(0,7,Z[7]);
  delay(delaytime);

   //Display AZ
 /* lc.setRow(0,0,AZ[0]);
  lc.setRow(0,1,AZ[1]);
  lc.setRow(0,2,AZ[2]);
  lc.setRow(0,3,AZ[3]);
  lc.setRow(0,4,AZ[4]);
  lc.setRow(0,5,AZ[5]);
  lc.setRow(0,6,AZ[6]);
  lc.setRow(0,7,AZ[7]);
  delay(delaytime);*/
}

void loop(){
  displayAlphabets();
}
