/*
05/07/2016
Applicazione realizzata da Francesco Crovelli, 
tutto il materiale 
disponibile sul sito  
https://francescocrovelli.softr.app/
Contatti: https://francescocrovelli.softr.app/parliamoci
*/
#include <SoftwareSerial.h>
#define bluetooth Serial
SoftwareSerial mySerial(0, 1); 
// imposto i pin per la comunicazione seriale
// Collegare i pin nel seguente modo: RX=>1 TX=>0
float tempC;
int tempPin = 0;


void setup()
{
  pinMode (tempPin, INPUT); // Sensore Temperatura sul pin A0
  pinMode(2, OUTPUT); // Linea prese Soggiorno
  pinMode(3, OUTPUT); // Linea prese Cucina
  pinMode(4, OUTPUT); // Linea prese Camera
  pinMode(5, OUTPUT); // Linea prese Giardino
  pinMode(6, OUTPUT); // Linea luce Soggiorno
  pinMode(7, OUTPUT); // Linea luce Cucina
  pinMode(8, OUTPUT); // Linea luce Camera
  pinMode(9, OUTPUT); // Linea luce Giardino
  pinMode(10, OUTPUT); // Riscaldamento
  pinMode(11, OUTPUT); // Condizionatore
  pinMode(12, OUTPUT); // Cancello
  pinMode(13, OUTPUT);

 bluetooth.begin(9600);
   mySerial.begin(9600); // setto la comunicazione
   delay(1000);
}


void loop()
{
  tempC = analogRead (tempPin);
  tempC = (5.0 * tempC * 100.0)/1024.0;
   Serial.println (tempC);
  delay (1000);
   while (bluetooth.available())
   {





    
       char dato= bluetooth.read(); 
       // "dato" è il valore che viene ricevuto dalla seriale
       switch(dato)
       {
         case 'A': // Se ricevo la lettera A,
         {
  digitalWrite(2, HIGH); // eccito il relè collegato al pin2
            
           break;
         }
         case 'a': // Se ricevo la lettera a
         {
  digitalWrite(2, LOW); // Spenfo il relè
           
           break;
         }    
                   // E così anche di seguito...
                  case 'B':
         {
  digitalWrite(3, HIGH);
           
           break;
         }
         case 'b':
         {
  digitalWrite(3, LOW);
          
           break;
         }    


         case 'C':
         {
  digitalWrite(4, HIGH);
            
           break;
         }
         case 'c':
         {
  digitalWrite(4, LOW);
           
           break;
         }    
                  case 'D':
         {
  digitalWrite(5, HIGH);
            
           break;
         }
         case 'd':
         {
  digitalWrite(5, LOW);
          
           break;
         }    
                  case 'E':
         {
  digitalWrite(6, HIGH);
            
           break;
         }
         case 'e':
         {
  digitalWrite(6, LOW);
           
           break;
         }    
                  case 'F':
         {
  digitalWrite(7, HIGH);
            
           break;
         }
         case 'f':
         {
  digitalWrite(7, LOW);
           
           break;
         }    
                  case 'G':
         {
  digitalWrite(8, HIGH);
            
           break;
         }
         case 'g':
         {
  digitalWrite(8, LOW);
          
           break;
         }    
                  case 'H':
         {
  digitalWrite(9, HIGH);
            
           break;
         }
         case 'h':
         {
  digitalWrite(9, LOW);
           
           break;
         }    
       case 'I': 
         {
  digitalWrite(10, HIGH); 
            
           break;
         }
         case 'i': // Se ricevo la lettera i
         {
  digitalWrite(10, LOW); // Spengo il relè
          
           break;
         }    
 case 'L': 
         {
  digitalWrite(11, HIGH); 
            
           break;
         }
         case 'l': // Se ricevo la lettera l
         {
  digitalWrite(11, LOW); // Spengo il relè
           
           break;
         }    
case 'M':
         {
  digitalWrite(12, HIGH);
            delay (1000);
            digitalWrite(12, LOW);
           break;
         }
         case 'm':
         {
  digitalWrite(12, HIGH);
           delay (1000);
           digitalWrite(12, LOW);
           break;
         }    
       case 'N':
         {
  digitalWrite(13, HIGH);
            
           break;
         }
         case 'n':
         {
  digitalWrite(13, LOW);
           
           break;
         }    
       
       }       
   } 
}

