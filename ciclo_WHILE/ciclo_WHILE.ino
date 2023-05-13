// definizione variabili
int i;

void setup() {
// Inizializzo la seriale
Serial.begin(9600);
}

void loop() {
  i = 0;
  while(i < 10) {
  // scrivi "." senza andare a capo
  Serial.print(".");
  i ++;
  }
  // quando finisce il ciclo While scrivi "END" e vai a capo
  Serial.println ("END");
  delay(1000);
}
