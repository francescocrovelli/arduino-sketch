// definizione variabili
char comando;

void setup() {
// inizializzazione seriale
Serial.begin(9600);
// definizione pin
pinMode(13, OUTPUT);

}

void loop() {
// scrivo nella variabile "comando" i valori letti dalla seriale 
comando = Serial.read();

// utilizzo le uscite PWM
// se dalla seriale leggo "a", accendo il led sul pin11
  if (comando == 'a') {
  analogWrite(11, 255);
  Serial.println("pin 11 FULL ON");
  }
// se leggo "z", accendo il led a metà intensità
  if (comando == 'z') {
  analogWrite(11, 110);
  Serial.println("pin 11 HALF ON");
  }
// se dalla seriale leggo "s", spengo il led sul pin11
  if (comando == 's') {
  digitalWrite(11, LOW);
  Serial.println("pin 11 OFF");
  }
}
