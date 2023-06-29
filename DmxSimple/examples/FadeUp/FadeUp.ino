
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
  DmxSimple.maxChannel(5);
}

void loop() {
  int brightness;
  /* Simple loop to ramp up brightness */  
  for (brightness = 0; brightness <= 255; brightness++) {
    digitalWrite(lr, HIGH);
    /* Update DMX channel 1 to new brightness */
    //DmxSimple.write(1, brightness);
    DmxSimple.write(2, brightness);
    //DmxSimple.write(3, brightness);
    DmxSimple.write(4, 189);
    
    /* Small delay to slow down the ramping */
    delay(10);
    digitalWrite(lr, LOW);
  }

}
