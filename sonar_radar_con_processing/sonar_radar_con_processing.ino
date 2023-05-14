// Includi la libreria Servo
#include <Servo.h>

// Definisce i pin Tirg ed Echo del sensore a ultrasuoni
const int trigPin = 10;
const int echoPin = 11;

// Variabili per la durata e la distanza
long duration;
int distance;
Servo myServo; // Crea un oggetto servo per controllare il servomotore
void setup() {
  pinMode(trigPin, OUTPUT); // Imposta il trigPin come Output
  pinMode(echoPin, INPUT); // Imposta l'echoPin come Input
  Serial.begin(9600);
  myServo.attach(12); // Definisce su quale pin è collegato il servomotore
}
void loop() {

  // ruota il servomotore da 15 a 165 gradi
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance(); // Richiama una funzione per il calcolo della distanza misurata dal sensore a Ultrasuoni per ogni grado
  
  Serial.print(i); // Invia il grado corrente nella porta seriale
  Serial.print(","); // Invia il carattere di addizione proprio accanto al valore precedente necessario successivamente nell'IDE di elaborazione per l'indicizzazione
  Serial.print(distance); // Invia il valore della distanza nella porta seriale
  Serial.print("."); // Invia il valore della distanza nella porta seriale
  }
  
  // Repeats the previous lines from 165 to 15 degrees
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
