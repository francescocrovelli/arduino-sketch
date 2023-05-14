#include <LiquidCrystal.h>
int triggerPort = 7;
int echoPort = 8;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// connessione display (pin)
void setup() {
pinMode( triggerPort, OUTPUT );
pinMode( echoPort, INPUT );
Serial.begin( 9600 );
Serial.println( "Sensore ultrasuoni: ");
lcd.begin(16, 2);
// imposto il tipo di display (colonne, righe)
lcd.print("Distanza:");
}
void loop() {
//porta bassa l'uscita del trigger
digitalWrite( triggerPort, LOW );
//invia un impulso di 10microsec su trigger
digitalWrite( triggerPort, HIGH );
delayMicroseconds( 10 );
digitalWrite( triggerPort, LOW );
long duration = pulseIn( echoPort, HIGH );
long r = 0.034 * duration / 2;
Serial.print( "durata: " );
Serial.print( duration );
Serial.print( " , " );
Serial.print( "distanza: " );
if( duration > 38000 ) Serial.println( "fuori portata");
else { Serial.print( r ); Serial.println( "cm" );}
// posiziono il cursore alla colonna 12 e riga 0
if(r > 99){
lcd.setCursor(13, 0);
lcd.print(r);}
if(r <= 99 && r > 9){
lcd.setCursor(13, 0);
lcd.print(r);
lcd.setCursor(15, 0);
lcd.print(" ");}
if(r <= 9){
lcd.setCursor(13, 0);
lcd.print(r);
lcd.setCursor(14, 0);
lcd.print("  ");}
delay(300);
}
