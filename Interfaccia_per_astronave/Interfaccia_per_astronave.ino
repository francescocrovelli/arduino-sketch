int switchState = 0;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  switchState = digitalRead(2);
  // questo è un commento
  if (switchState == LOW) {
  // il pulsante viene premuto
  digitalWrite(3, HIGH); // LED verde
  digitalWrite(4, LOW); // LED rosso
  digitalWrite(5, LOW); // LED rosso
  }

  else { // il pulsante è premuto
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(4, HIGH);

    delay(250); // aspetta un quarto di secondo

    // cambia gli stati dei LED
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    delay (250); // aspetta un quarto di secondo

  }
} // torna indietro all'inizio del loop
