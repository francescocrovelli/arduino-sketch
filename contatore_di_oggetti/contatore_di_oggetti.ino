/////////////////////////////////////////////

// ARDUINO CONTATORE DI OGGETTI 

// Autore Francesco Crovelli

// Per maggiori info visita: http://francescocrovelli.sofr.app/

/////////////////////////////////////////////

#include <Wire.h>                      
#include <LiquidCrystal_I2C.h> 
// addr en,rw,rs,d4,d5,d6,d7,bl,blpol 
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
int state=LOW;
int lastState=LOW;
int count=0;

void setup(){
  
  lcd.begin(16, 2);          
  
Serial.begin(9600);
pinMode(8, INPUT);
state=digitalRead(8);
}
void loop(){
if (state==HIGH && lastState==LOW){
count++;
delay (100);
Serial.println(count);
lcd.setCursor(0, 0);     
    lcd.print("Num. Oggetti: ");  
    lcd.setCursor(0, 1);
    lcd.print(count);    

}
lastState=state;
state=digitalRead(8);
}
