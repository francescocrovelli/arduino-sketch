int Buzzer = 9;  //Il buzzer è collegato al pin digitale 9
int Fotores = 0;  //La fotoresistenza è collegata al pin analogico 0
int Nota;  //Variabile in cui è salvato il valore della nota

void setup() {
  pinMode (Buzzer, OUTPUT);  //Il pin a cui è connesso il buzzer è impostato come uscita
  }
  
void loop () {
  Nota = 3*(analogRead (Fotores)) + 500;  //Calcolo della nota
  tone (Buzzer, Nota);  //Scrittura della nota sul pin 9
  delay (10);  //Aspetta 10 ms prima di cambiare nota
  }
