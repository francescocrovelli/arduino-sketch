
/* Welcome to DmxSimple. This library allows you to control DMX stage and
** architectural lighting and visual effects easily from Arduino. DmxSimple
** is compatible with the Tinker.it! DMX shield and all known DIY Arduino
** DMX control circuits.
**
** DmxSimple is available from: http://code.google.com/p/tinkerit/
** Help and support: http://groups.google.com/group/dmxsimple       */

/* To use DmxSimple, you will need the following line. Arduino will
** auto-insert it if you select Sketch > Import Library > DmxSimple.

Modified by Boris Landoni
open-electronics.org


 */

#include <DmxSimple.h>


const int jrde =  2;
const int jdi  =  3;
const int jro  =  4;
const int lr   =  7;
const int ly   =  8;

#define SIZE    255
#define DELAY    10
#define HUE_MAX  6.0
#define HUE_DELTA 0.01
 
long deltas[3] = { 
  5, 6, 7 };
long rgb[3];
long rgbval;
// for reasons unknown, if value !=0, the LED doesn't light. Hmm ...
// and saturation seems to be inverted
float hue=0.0, saturation=1.0, value=1.0;

/*
chosen LED SparkFun sku: COM-09264
 has Max Luminosity (RGB): (2800, 6500, 1200)mcd
 so we normalize them all to 1200 mcd -
 R  1200/2800  =  0.428571428571429   =   109/256
 G  1200/6500  =  0.184615384615385   =    47/256
 B  1200/1200  =  1.0                 =   256/256
 */
long bright[3] = {
  109, 47, 256};
 
long k, temp_value;

int address=1;


void setup() {
  




  
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
  DmxSimple.maxChannel(10);
  
  randomSeed(analogRead(4));
  for (k=0; k<3; k++) {
    //pinMode(RED + k, OUTPUT);
    rgb[k]=0;
    DmxSimple.write(k+address, rgb[k] * bright[k]/256);
    //DmxSimple.write(3, brightness);
    DmxSimple.write(3+address, 189);
    
    if (random(100) > 50) {
      deltas[k] = -1 * deltas[k]; // randomize direction
    }
  }
}




// HSV fade/bounce for Arduino - scruss.com - 2010/09/12
// Note that there's some legacy code left in here which seems to do nothing
// but should do no harm ...
 

 


 
void loop() {
  hue += HUE_DELTA;
  if (hue > HUE_MAX) {
    hue=0.0;
  }
  rgbval=HSV_to_RGB(hue, saturation, value);
  rgb[0] = (rgbval & 0x00FF0000) >> 16; // there must be better ways
  rgb[1] = (rgbval & 0x0000FF00) >> 8;
  rgb[2] = rgbval & 0x000000FF;
  digitalWrite(lr, HIGH);
  for (k=0; k<3; k++) { // for all three colours
    //analogWrite(RED + k, rgb[k] * bright[k]/256);
    
    /* Update DMX channel 1 to new brightness */
    //DmxSimple.write(1, brightness);
    DmxSimple.write(k+address, rgb[k] * bright[k]/256);
    //DmxSimple.write(3, brightness);
    
    
    /* Small delay to slow down the ramping */
   // delay(10);
    
    
  }
  DmxSimple.write(address+3, 180);
  delay(DELAY);
  digitalWrite(lr, LOW);
}
 
long HSV_to_RGB( float h, float s, float v ) {
  /* modified from Alvy Ray Smith's site: http://www.alvyray.com/Papers/hsv2rgb.htm */
  // H is given on [0, 6]. S and V are given on [0, 1].
  // RGB is returned as a 24-bit long #rrggbb
  int i;
  float m, n, f;
 
  // not very elegant way of dealing with out of range: return black
  if ((s<0.0) || (s>1.0) || (v<1.0) || (v>1.0)) {
    return 0L;
  }
 
  if ((h < 0.0) || (h > 6.0)) {
    return long( v * 255 ) + long( v * 255 ) * 256 + long( v * 255 ) * 65536;
  }
  i = floor(h);
  f = h - i;
  if ( !(i&1) ) {
    f = 1 - f; // if i is even
  }
  m = v * (1 - s);
  n = v * (1 - s * f);
  switch (i) {
  case 6:
  case 0: 
    return long(v * 255 ) * 65536 + long( n * 255 ) * 256 + long( m * 255);
  case 1: 
    return long(n * 255 ) * 65536 + long( v * 255 ) * 256 + long( m * 255);
  case 2: 
    return long(m * 255 ) * 65536 + long( v * 255 ) * 256 + long( n * 255);
  case 3: 
    return long(m * 255 ) * 65536 + long( n * 255 ) * 256 + long( v * 255);
  case 4: 
    return long(n * 255 ) * 65536 + long( m * 255 ) * 256 + long( v * 255);
  case 5: 
    return long(v * 255 ) * 65536 + long( m * 255 ) * 256 + long( n * 255);
  }
} 
