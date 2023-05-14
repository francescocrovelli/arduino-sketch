#define step_pin 3  // Pin 3 collegato al pin Steps su EasyDriver
#define dir_pin 2   // Pin 2 collegato al pin Direzione
#define MS1 5       // Pin 5 collegato al pin MS1
#define MS2 4       // Pin 4 collegato al pin MS2
#define SLEEP 7     // Pin 7 collegato al pin SLEEP
#define X_pin A0    // Pin A0 collegato all'asse x del joystick
 
int direction;    // Variabile per impostare la rotazione (CW-CCW) del motore
int steps = 1025; // Presuppone che la clip da cintura sia al centro
 
void setup() {
   pinMode(MS1, OUTPUT);
   pinMode(MS2, OUTPUT);
   pinMode(dir_pin, OUTPUT);
   pinMode(step_pin, OUTPUT);
   pinMode(SLEEP, OUTPUT);
   
   digitalWrite(SLEEP, HIGH);  // Sveglia EasyDriver
   delay(5);  // Attendere l'attivazione di EasyDriver
   
 
/* Configura il tipo di passaggi su EasyDriver:
// MS1 MS2
//
// LOW LOW = Passo completo //
// HIGH LOW = Mezzo passo //
// LOW HIGH = Un quarto di passo //
// HIGH HIGH = Un ottavo di Step //
*/
 
   digitalWrite(MS1, LOW);      // Configura a passi completi
   digitalWrite(MS2, LOW);    // Configura a passi completi
   
}
 
void loop() {
  while (analogRead(X_pin) >= 0 && analogRead(X_pin) <= 100) {
    if (steps > 0) {
      digitalWrite(dir_pin, HIGH);  // (HIGH = in senso antiorario / LOW = in senso orario)
      digitalWrite(step_pin, HIGH);
      delay(1);
      digitalWrite(step_pin, LOW);
      delay(1);
      steps--;
    }      
  }
  
    while (analogRead(X_pin) > 100 && analogRead(X_pin) <= 400) {
      if (steps < 512) {
        digitalWrite(dir_pin, LOW);  // (HIGH = in senso antiorario / LOW = in senso orario)
        digitalWrite(step_pin, HIGH);
        delay(1);
         digitalWrite(step_pin, LOW);
        delay(1);
        steps++;
      }    
      if (steps > 512) {
        digitalWrite(dir_pin, HIGH);
        digitalWrite(step_pin, HIGH);
        delay(1);
         digitalWrite(step_pin, LOW);
        delay(1);
        steps--;
      }
    }    
      
    while (analogRead(X_pin) > 401 && analogRead(X_pin) <= 600) {
      if (steps < 1025) {
        digitalWrite(dir_pin, LOW);
        digitalWrite(step_pin, HIGH);
        delay(1);
         digitalWrite(step_pin, LOW);
        delay(1);
        steps++;
      }    
      if (steps > 1025) {
        digitalWrite(dir_pin, HIGH);
        digitalWrite(step_pin, HIGH);
        delay(1);
         digitalWrite(step_pin, LOW);
        delay(1);
        steps--;
      } 
    } 
 
    while (analogRead(X_pin) > 601 && analogRead(X_pin) <= 900) {
      if (steps < 1535) {
        digitalWrite(dir_pin, LOW);
        digitalWrite(step_pin, HIGH);
        delay(1);
         digitalWrite(step_pin, LOW);
        delay(1);
        steps++;
      }    
      if (steps > 1535) {
        digitalWrite(dir_pin, HIGH);
        digitalWrite(step_pin, HIGH);
        delay(1);
         digitalWrite(step_pin, LOW);
        delay(1);
        steps--;
      }    
    }   
   
    while (analogRead(X_pin) > 900 && analogRead(X_pin) <= 1024) {
      if (steps < 2050) {
        digitalWrite(dir_pin, LOW);
        digitalWrite(step_pin, HIGH);
        delay(1);
         digitalWrite(step_pin, LOW);
        delay(1);
        steps++;
      }
    }
}
