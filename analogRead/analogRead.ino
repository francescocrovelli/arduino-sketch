// SI VUOLE LEGGERE UN SENSORE DI LUCE
// definizione variabili
int luce;


void setup() {
  // abilito la seriale
  Serial.begin(9600);  
  // imposto il pin 13 come OUTPUT
  pinMode(13, OUTPUT);
}

void loop() {
// creo una variabile luce e la assegno alla lettura dell'ingresso A0
luce = analogRead(A0);

// abilito la porta seriale per tarare il sensore
Serial.println(luce);

  if (luce < 100) {
  digitalWrite(13, HIGH);
  } else {
  digitalWrite(13, LOW);
  }
delay(100);
}
