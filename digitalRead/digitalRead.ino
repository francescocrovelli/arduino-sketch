// SI VUOLE ACCENDERE UN LED SE SI PREME UN PULSANTE
// Nota sul circuito di collegamento del pulsante
/* il pin 7 va messo a GND perchè dobbiamo essere sicuri di avere 0VDC sul pin quando non premo il pulsante.
Sul circuito di collegamento del pulsante va messa un resistenza verso GND
perchè altrimenti si creerebbe un corto circuito quando si preme il tasto.
*/

void setup() {
  // abilito la seriale
  Serial.begin(9600);
  
  // imposto il pin 13 come OUTPUT
  pinMode(13, OUTPUT);
  // imposto il pin 7 come INPUT
  pinMode(7, INPUT);
}

void loop() {
  // Ciclo IF
  // il Ciclo IF vuole il ==
  // se sul pin 7 leggo un valore HIGH, allora metto HIGH anche il pin 13 
  if (digitalRead(7) == HIGH ) {
  digitalWrite(13, HIGH);
  } else {
  digitalWrite(13, LOW);
  }
}
