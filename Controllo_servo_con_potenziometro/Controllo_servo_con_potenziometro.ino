// CONTROLLO DI UN SERVOMOTORE CON POTENZIOMETRO (segnale filtrato) (Aliverti - video n.35, n.40 e n.331)
// Per controllare la rotazione del servo uso il segnale PWM in uscita dal pin9
// Bisogna tarare il potenziometro e settare i valori di correzione
// Per filtrare il segnale si usa un filtro a media mobile -> si fa la media tra un campione di numeri letti continuamente

/*
Contenuti
- funzioni matematiche
- ciclo for
- media mobile
- array usato come buffer
- funzione map
*/

//definizione variabili
int AngleRef; // ingresso potenziometro
int AngleServo; // valore di rotazione al servo

// variabile per la creazione del filtro a media mobile
int const fsize = 15; // numero di campioni da considerare per la media
int fil[fsize]; // creo un array usato come buffer di valori
float avgAngleRef = 0;  // media
int i;
int j;

// fattori di taratura per il potenziometro
int RefMax = 1023; //valore letto a potenziometro 100%
int RefMin = 0; //valore letto a potenziometro 0%
int m;

// importo libreria servomotori
//https://www.arduino.cc/reference/en/libraries/servo/
#include <Servo.h>
// Creo un oggetto di tipo Servo (simile alla definizione di una variabile)
Servo servo1;

void setup() {
  Serial.begin(9600);
// definisco il pin a cui è attaccato il servomotore
  servo1.attach(11);
  servo1.write(0);
}

void loop() {
  // leggo il valore dal potenziometro dal pinA0
  AngleRef = analogRead(A0);
 

  // riempo continuamente il buffer con le lettue
  fil[i] = AngleRef;
  if (i < (fsize-1)) {
    i++;  
  } else {
    i=0;
  }

  //sommo tutti i valori presenti nel buffer e faccio la media
  for (j=0; j < fsize; j++) {
    avgAngleRef += (float)fil[j]; // trasformo i valori di fil in (float)
  }
  avgAngleRef = avgAngleRef / (float)(fsize);
  

  // Conversione proporzionale tra valore potenziometro e gradi motore
  AngleServo = map (avgAngleRef, 0, 1023, 0, 180);
  
  /*
  // Equazione di conversione lineare
  m = RefMax / 180;
  AngleServo = avgAngleRef / m;
  */
  
  // utilizzo il segnale PWM per impostare i gradi sul servo
    servo1.write(AngleServo);
 

  // Letture porta seriale
  Serial.print("Angle Ref ");
  Serial.println(AngleRef);
  Serial.print("avgAngle Ref ");
  Serial.println(avgAngleRef);
  Serial.print("AngleServo ");
  Serial.println(AngleServo);
}
