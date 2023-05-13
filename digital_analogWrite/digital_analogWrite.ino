
/*
Contenuti
- assegnazione pin INPUT/OUTPUT
- digitalWrite
- analogWrite
*/

// ----------------------
// DEFINIZIONE VARIABILI
// assegnazione variabile pin
int pin_led = 11;
int brightness = 10;

//-----------------------
void setup() {
// impostazioni di pin
// imposto il pin 13 come OUTPUT
pinMode(13, OUTPUT);
// imposto il pin 8 come INPUT
pinMode(8, INPUT);
}

//-----------------------
void loop() {
// istruzioni all'interno del loop -> vengono ripetute ciclicamene
// CONTROLLO USCITE DIGITALI
// HIGH -> 1
// LOW -> 0
digitalWrite(13, HIGH); // "alzo" il pin 13
delay(1000); // attesa di 1 secondo
digitalWrite(13, LOW);
delay(1000);

// CONTROLLO USCITE ANALOGICHE
// si utilizzano i pin con la funzione PWM
// il range di valori va da 0 a 255 (0-100%)
analogWrite(11, 255);     // senza variabili
analogWrite(pin_led, brightness); // con variabili
}
