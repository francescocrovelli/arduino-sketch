/* 
Con questo sketch è possibile fare accendere un led o commutare un relè 
al passaggio di una tessera magnetica sul lettore RFID.
Se la tessera viene riconosciuta si accende un led verde e commuta il relè,
altrimenti un led rosso per indicarci l`inaccessibilità.  

Autore Francesco Crovelli

PINOUT:
  
RC522 MODULO    Uno/Nano    
SDA             D10
SCK             D13
MOSI            D11
MISO            D12
IRQ             N/A
GND             GND
RST             D9
3.3V            3.3V

led verde al Pin 3
Led rosso al Pin 4
Relè al Pin 2
*/
  
#include <SPI.h>
#include <RFID.h>
/* Vengono definiti PIN del RFID reader*/
#define SDA_DIO 10  // Pin 53 per Arduino Mega
#define RESET_DIO 9
#define delayRead 1000 // Tempo 
#define delayLed 2000 
#define ledVerde 3
#define ledRosso 4
#define rele 2
/* Viene creata una istanza della RFID libreria */
RFID RC522(SDA_DIO, RESET_DIO); 
  // inserire tutti i codici esadecimali delle schede magnetiche riconosciute 
String codiceAutorizzato1 = "FCA2333B56";
String codiceAutorizzato2 = "ESEMPIO479";
String codiceAutorizzato3 = "ESEMPIO480";
  
void setup()
{ 
  Serial.begin(9600);
  /* Abilita SPI*/
  SPI.begin(); 
  /* Viene inizilizzato RFID reader */
  RC522.init();
  Serial.println("Setup");
  pinMode(ledVerde,OUTPUT);
  pinMode(ledRosso,OUTPUT);
  pinMode(rele,OUTPUT);
}
  
void loop()
{
  /* Temporary loop counter */
  byte i;
  // Se viene letta una tessera
  if (RC522.isCard())
  {
    // Viene letto il suo codice 
    RC522.readCardSerial();
    String codiceLetto ="";
    Serial.println("Codice delle tessera letto:");
  
    // Viene caricato il codice della tessera, all'interno di una Stringa
    for(i = 0; i <= 4; i++)
    {
      codiceLetto+= String (RC522.serNum[i],HEX);
      codiceLetto.toUpperCase();
    }
    Serial.println(codiceLetto);
    if(verificaCodice(codiceLetto,codiceAutorizzato1)||verificaCodice(codiceLetto,codiceAutorizzato2)
    ||verificaCodice(codiceLetto,codiceAutorizzato3)){
      Serial.println("Tessera autorizzata");
      accendiLed(ledVerde);
      digitalWrite (rele, HIGH);
      delay (1000);     // Tempo relè in stato ON
      digitalWrite (rele, LOW);
    }else{
      Serial.println("Tessera non autorizzata");
      accendiLed(ledRosso);
    }
  delay(delayRead);  
  }
}
// Questa funzione verifica se il codice Letto è autorizzato
boolean verificaCodice(String codiceLetto, String codiceAutorizzato){
  if(codiceLetto.equals(codiceAutorizzato)){
    return true;
  }else{
    return false;
  }  
}    
// Questa funzione permette di accendere un LED per un determinato periodo
void accendiLed(int ledPin){
  digitalWrite(ledPin,HIGH);
  delay(delayLed);
  digitalWrite(ledPin,LOW);
}
