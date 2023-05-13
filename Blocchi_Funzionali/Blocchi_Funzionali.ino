//DEFINIRE UN BLOCCO FUNZIONE (maffucci.it)
// https://www.maffucci.it/2020/11/15/arduino-strutturare-il-codice-in-blocchi-funzionali/


//chiave è la variabile che consente l'esecuzione della chiamata della funzione lampegga una sola volta
int chiave = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // richiamiamo la funzione lampeggia() passando il valore specificato all'interno delle parentesi tonde
  if (chiave == 0) {
    chiave = 1;
    lampeggia(250, 1000, 5);
  }
}

// BLOCCO FUNZIONE LAMPEGGIA: blink LED una volta
// Per far si che la funzione accetti tre parametri in input bisogna dichiarare il tipo per ogni parametro in ingresso
// nella funzione lampeggia: int pausaOn, int pausaOff, int contatore
// La variabile contatore definisce il numero di cicli di lampeggio
void lampeggia(int pausaOn, int pausaOff, int contatore)
{
  for (int i = 0; i < contatore; i++) {
    digitalWrite(LED_BUILTIN, HIGH); // accende il LED
    delay(pausaOn); // delay LED ON
    digitalWrite(LED_BUILTIN, LOW); // spegne il LED
    delay(pausaOff); // delay LED OFF

  }
}
