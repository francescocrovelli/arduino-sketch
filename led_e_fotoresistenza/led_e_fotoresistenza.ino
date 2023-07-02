// Arduino led e fotoresistenza, Accendiamo un led quando il fotoresistore è al buio
// Per maggiori info: https://francescocrovelli.softr.app

int luminosita;  // Il valore letto dalla fotoresistenza
int ledPin = 10;  // Il pin del led

void setup() {
}

void loop() {
  luminosita = analogRead(A0);  // Lettura della luminosità
  luminosita = luminosita/4;  // Adeguiamo il valore della luminosità
  analogWrite(ledPin,luminosita);  // Mettiamo il valore letto per il led
  delay(10);  // Aspetta 10 ms
}

