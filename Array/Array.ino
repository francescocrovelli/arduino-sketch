// CAMBIO LO STATO DI 3 USCITE CON TRE PULSANTI
// UTILIZZO DEGLI ARRAY
/*
Contenuti
- Array
- Ciclo if
- Ciclo for
- Cambio stato variabile
*/

// definizione variabili
int i;

// definisco un array chiamato "stati" con 3 posizioni
int stati [3] = {LOW, LOW, LOW};
// definisco un array chiamato "pin" con i pin utilizzati
int pin [3] = {7, 8, 9};


void setup() {
// inizializzo la seriale
Serial.begin(9600);

// definizione dei pin nell'array con il ciclo FOR
  for (i = 0; i < 3; i++) {
  pinMode(pin[i], INPUT);
  }
pinMode(13, OUTPUT);
}

void loop() {
  // leggo con un ciclo FOR lo stato dei pin
  for (i = 0; i < 3; i++) {
    // inverto il valore che trovo nell'array stati, posizione [i] se un pin è HIGH
    if (digitalRead(pin[i]) == HIGH) {
      stati[i] =!stati[i] ;
    }
  }

// ciclo FOR che legge i 3 stati all'interno dell'array e scrive sulla seriale
  for (i = 0; i < 3; i++) {
    if (stati[i] == HIGH) {
      Serial.print("PIN");
      Serial.print(pin[i]); // prendo il valore dei pin nell'array
      Serial.println("ON"); 
    } else {
      Serial.print("PIN");
      Serial.print(pin[i]); // prendo il valore dei pin nell'array
      Serial.println("OFF");
    }
    delay(500);
  }
}
