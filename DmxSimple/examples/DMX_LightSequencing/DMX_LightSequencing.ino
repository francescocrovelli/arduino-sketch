/*
The purpose of this code is to allow the Arduino to use the 
generic serial output of vixen lights to control 5 channels of LEDs. 
Author: Matthew Strange
Created: 14 October 2010
Modifier: Ben Towner
Modified: 19-OCT-2010
Changes: Addition of 20 Digital On/Off Channels - Setup for Arduino Mega 2560
Modified by Boris Landoni
open-electronics.org

*/

#include <DmxSimple.h>


const int jrde =  2;
const int jdi  =  3;
const int jro  =  4;
const int lr   =  7;
const int ly   =  8;


#define DELAY    10

int i = 0;     // Loop counter
int incomingByte[25];   // array to store the 25 values from the serial port
int address=1;
int ch=16;
int k;


//setup the pins/ inputs & outputs
void setup()
{
  Serial.begin(9600);        // set up Serial at 9600 bps


  
  pinMode(jrde, OUTPUT);
  pinMode(jdi,  OUTPUT);
  pinMode(jro,  INPUT);
  pinMode(lr, OUTPUT);
  pinMode(ly, OUTPUT);
  
  digitalWrite(jrde, HIGH);
  
  /* The most common pin for DMX output is pin 3, which DmxSimple
  ** uses by default. If you need to change that, do it here. */
  DmxSimple.usePin(jdi);

  /* DMX devices typically need to receive a complete set of channels
  ** even if you only need to adjust the first channel. You can
  ** easily change the number of channels sent here. If you don't
  ** do this, DmxSimple will set the maximum channel number to the
  ** highest channel you DmxSimple.write() to. */
  DmxSimple.maxChannel(ch);
  
  
  for (k=0; k<ch+1; k++) {
    DmxSimple.write(k+address,0);  
 }

  
}

void loop()
{  // 25 channels are coming in to the Arduino
   if (Serial.available() >= ch) {
    // read the oldest byte in the serial buffer:
      for (k=0; k<ch+1; k++) {      
        incomingByte[k] = Serial.read();
      }
      //for (k=0; k<ch+1; k++) {
      //Serial.print ("ch "); Serial.print (k); Serial.print (" - value "); Serial.println (incomingByte[k]); 
      //}
    
      digitalWrite(lr, HIGH);
    
      for (k=0; k<ch+1; k++) { // for all three colours
        DmxSimple.write(k+address, incomingByte[k]);
      }
    }  
     
  //delay(DELAY);
  digitalWrite(lr, LOW);
}

