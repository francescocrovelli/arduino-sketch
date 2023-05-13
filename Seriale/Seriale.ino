int i = 0;

void setup() {
  // inizializzo la porta seriale con baudrate 9600bps
  Serial.begin(9600);
}

void loop() {
  //stampo un messaggio sulla porta seriale
  // il messaggio può essere visto sul Serial Monitor

  // println mette anche a capo
  Serial.println("Bella zio");
  delay(500);

  // print di un numero che incrementa
  i++;
  Serial.print(i); // non ci vanno le "" perchè non è un testo ma una variabile
  delay(1000);
}
