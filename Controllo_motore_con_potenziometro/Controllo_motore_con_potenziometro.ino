// CONTROLLO DI UN MOTORE ELETTRICO A 12VDC CON MOSFET e POTENZIOMETRO (Aliverti - video n.34 e n.40)
// Motore a 12VDC, Diodo 1N4007, Mosfet IRF520, Potenziometro 10kOhm
// Per controllare la velocità del motore uso il segnale PWM in uscita dal pin9
// Bisogna tarare il potenziometro e settare i valori di correzione

//definizione variabili
int SpeedRef;
int MotSpeed;

// fattori di taratura per il potenziometro
int RefMax = 255; //valore letto a potenziometro 100%
int RefMin = 0; //valore letto a potenziometro 0%
int m;



void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);

}

void loop() {
  // leggo il valore dal potenziometro dal pinA0
  SpeedRef = analogRead(A0);
  Serial.println(SpeedRef);
  delay(100);

  // Equazione di conversione lineare
  m = RefMax / 255;
  MotSpeed = SpeedRef / m;
  
  // utilizzo il segnale PWM da pin9
  analogWrite(9, MotSpeed);
}
