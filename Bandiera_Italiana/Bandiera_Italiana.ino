void setup() {
  // imposto i pin LED come uscite
  pinMode(3, OUTPUT);   // dichiaro il pin 3 (LED verde) come uscita
  pinMode(4, OUTPUT);   // dechiaro il pin 4 (LED giallo) come uscita
  pinMode(5, OUTPUT);   // dichiaro il pin 5 (LED rosso) come uscita
  pinMode(2, INPUT);    // dichiaro il pin 2 (pulsante) come ingresso
}

void loop() {
  if (digitalRead(2) == LOW) { // se non premo il pulsante
      digitalWrite(3, HIGH);   // accendo il LED verde sul pin 3
      digitalWrite(4, LOW);    // spengo il LED giallo sul pin 4
      digitalWrite(5, LOW);    // spengo il LED rosso sul pin 5

      delay(3000);             // attendo 3 secondi

      digitalWrite(3, LOW);    // spengo il LED verde sul pin 3
      digitalWrite(4, HIGH);   // accendo il LED giallo sul pin 4
      digitalWrite(5, LOW);    // spengo il LED rosso sul pin 5
      digitalWrite(3, LOW);    // spengo il LED verde sul pin 3
      digitalWrite(4, LOW);    // spengo il LED giallo sul pin 4
      digitalWrite(5, HIGH);   // accendo il LED rosso sul pin 5

      delay(3000)              // attendo 3 secondi
  }
if (digitalRead(2) == HIGH) { // se premo il pulsante
  digitalWrite(4, LOW);       // spengo il LED giallo sul pin 4
  digitalWrite(5, LOW);       // spengo il LED rosso sul pin 5
  digitalWrite(3, HIGH);      // accendo il LED verde sul pin 3

  delay(500);                 // attendo mezzo secondo

  digitalWrite(3, LOW);       // spengo il LED verde sul pin 3

  delay(500);                 // attendo mezzo secondo
  }
}