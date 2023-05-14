////////////////////////////////////////////
//ALLARME LASER CON ARDUINO
// Autore> Francesco Crovelli
// Per maggiori info visitare http://francesco.crovelli.softr.app/
///////////////////////////////////////////

// Definiamo delle costanti  
const int rosso = 9; 
const int verde = 8; 
const int pulsante = 7; 
const int laser = 5; 
int stato=0; // All`apertura il sistema è spento 
int val=0; // Memorizza il valore dello stato tra un ciclo e l'altro 
int luce;
void setup() {
pinMode(verde, OUTPUT); // Inizializzo l'uscita del led verde. 
 pinMode(rosso, OUTPUT); // Inizializzo l'uscita del led rosso. 
 pinMode(pulsante, INPUT); // Inizializzo l'uscita dei pin in ingresso del pulsante 
 pinMode(laser, OUTPUT); 
 pinMode(A0,INPUT);
}
 
 void loop() { 
 val = digitalRead(pulsante); // Leggo lo stato del segnale 
 delay(5); 
 
 if (val == HIGH) { // conserviamo il valore 
 stato = 1 - stato; // della scelta fatta col pulsante. 
 } 
 
 if (stato == HIGH) { // Se premo il pulsante accendo il sistema 
 digitalWrite(rosso, LOW); 
 digitalWrite(verde, HIGH); 
 digitalWrite(laser, 1); 
 luce = analogRead(A0); 
 
 if (luce<100) { 
 tone(3, 500); 
 }
 
 } 
 
 else { // Se premo il pulsante accendo il red rosso e spengo il sistema
 noTone(3); 
 digitalWrite(verde, LOW); 
 digitalWrite(rosso, HIGH); 
 digitalWrite(laser, 0); 
 } 
}
