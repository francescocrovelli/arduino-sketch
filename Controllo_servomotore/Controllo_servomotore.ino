// CONTROLLO DI UN SERVOMOTORE (Aliverti - video n.35)
/*
Contenuti
- Ciclo if
- Comando da seriale
*/

// importo libreria servomotori
//https://www.arduino.cc/reference/en/libraries/servo/
#include <Servo.h>

// definizione variabili
char comando;

// Creo un oggetto di tipo Servo (simile alla definizione di una variabile)
Servo servo1;

void setup() {
// abilito la seriale
Serial.begin(9600);
// definisco il pin a cui è attaccato il servomotore
  servo1.attach(9);

}

void loop() {
// scrivo i valori letti dalla seriale
  comando = Serial.read();

// leggo il comando da seriale e imposto i gradi da 0 a 180
  if (comando == 's') {
  servo1.write(0);
  delay(300); 
  }
  if (comando == 'a') {
  servo1.write(180);
  delay(300); 
  }
  if (comando == 'd') {
  servo1.write(-180);
  delay(300); 
  }
}
