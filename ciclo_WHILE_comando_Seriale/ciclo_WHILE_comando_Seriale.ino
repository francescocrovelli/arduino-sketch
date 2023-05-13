// definizione variabili
int i;
bool RUN;
char comando;

void setup() {
// Inizializzo la seriale
Serial.begin(9600);
// Definizione dei pin
pinMode(7, INPUT);
}

void loop() {
comando = Serial.read();
RUN = true;
  while(RUN) {

    if (comando == 'a') {
    RUN = false;    
    }
  
  // scrivi "." senza andare a capo
  Serial.print(".");
  delay(200);
  }
  
// quando esco da ciclo While scrivo "END"
Serial.println ("END");
delay(1000);
}
