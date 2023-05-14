////////////////////////////////////////////
//ALLARME MAGNETICO PER PORTE E FINESTRE CON ARDUINO
// Autore> Francesco Crovelli
// Per maggiori info visitare http://francescocrovelli.softr.app/
///////////////////////////////////////////


#include <Wire.h> // libreria wire presente, di fault, nell'IDE
#include <LiquidCrystal_I2C.h> // libreria di gestione del display lcd
// addr en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // definisce la tipologia del display

// Definiamo delle costanti  
const int rosso = 9; 
const int verde = 8; 
const int pulsante = 7; 
int stato=0; // All`apertura il sistema è spento 
int val=0; // Memorizza il valore dello stato tra un ciclo e l'altro 
int magnete;


void setup() {
   Serial.begin(9600); // inizializza la comunicazione sul monitor seriale
  lcd.begin(16, 2); // inizializza il display (16 caratteri per due righe)
 pinMode(verde, OUTPUT); // Inizializzo l'uscita del led verde. 
 pinMode(rosso, OUTPUT); // Inizializzo l'uscita del led rosso. 
 pinMode(pulsante, INPUT); // Inizializzo l'uscita dei pin in ingresso del pulsante 
 pinMode(2,INPUT);
}
 
 void loop() { 
 val = digitalRead(pulsante); // Leggo lo stato del segnale 

 
 if (val == HIGH) { // conserviamo il valore 
 stato = 1 - stato; // della scelta fatta col pulsante. 
 } 
 
 if (stato == HIGH) { // Se premo il pulsante accendo il sistema 
    lcd.setCursor(0, 0); // posiziona il cursore all'inizio della prima riga
  lcd.print ("Allarme Porta");
   lcd.setCursor(0, 1); // posiziona il cursore all'inizio della prima riga
  lcd.print (" ON");
 digitalWrite(rosso, LOW); 
 digitalWrite(verde, HIGH);  
 magnete = digitalRead(2); 
 
 if (magnete == LOW) { 
 tone(3, 500); 

 }
 
 } 
 
 else { // Se premo il pulsante accendo il red rosso e spengo il sistema
  
  lcd.setCursor(0, 0); // posiziona il cursore all'inizio della prima riga
  lcd.print ("Allarme Porta");
  lcd.setCursor(0, 1); // posiziona il cursore all'inizio della prima riga
  lcd.print ("OFF");

 noTone(3); 
 digitalWrite(verde, LOW); 
 digitalWrite(rosso, HIGH); 
 } 
}
