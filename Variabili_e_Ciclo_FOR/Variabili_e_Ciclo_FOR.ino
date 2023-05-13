// ----------------------
// DEFINIZIONE VARIABILI
// creo una nuova variabile
int temperatura;
// creo una variabile e inizializzo con un valore
int velocita = 10;
int i = 0;
// definisco un nome al pin 13
int pin_led = 13;

// TIPO DI DATO
/*
float
long
double
*/

void setup() {
// imposto il pin_led come OUTPUT
pinMode(pin_led, OUTPUT); 
}

//----------------------
void loop() {
// assegno un valore alla variabile temperatura
temperatura = 12;

// incremento la variabile i
i=i+1;
i++;

// agisco sul pin_led assegnando un segnale digitale
digitalWrite(pin_led, HIGH);


// Ciclo FOR
// ciclo che incrementa la variabile i
// l'incremento della variabile aumenta la luminosità del led sul pin 11
  for (int i = 0; i < 255; i = i + 1) {
  analogWrite(11, i);
  delay(5);
  }
  for (int i = 255; i >=0; i = i - 1) {
  analogWrite(11, i);
  delay(5);
  }
    
}
