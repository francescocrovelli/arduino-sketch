
/////////////////////////////////////////////////

// SENSORE TEMPERATURA DS18B20 CON DISPLAY LCD

// AUTORE Francesco Crovelli

// Per maggiori info: http://francescocrovelli.sofr.app/

/////////////////////////////////////////////////
 
#include <Wire.h> // libreria wire presente, di fault, nell'IDE
#include <LiquidCrystal_I2C.h> // libreria di gestione del display lcd
#include <DallasTemperature.h>
#include <OneWire.h> // dichiarazione di utilizzo della libreria OneWire.h
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
#define ONE_WIRE_BUS 2 // assegna il valore 2 al nome ONE_WIRE_BUS
OneWire oneWire(ONE_WIRE_BUS); // associa alla porta 2 (valore di ONE_WIRE_BUS) il
// canale dati dei sensori
DallasTemperature sensors(&oneWire); //trasferisce alle routine della libreria DallasTemperature
// il controllo delle funzioni OneWire
#include <DallasTemperature.h> // dichiarazione di utilizzo della libreria DallasTemperature.h
void setup(void)
{
Serial.begin(9600); // inizializza la porta seriale per l'utilizzo del monitor seriale
lcd.begin(16, 2);
sensors.begin(); // inizializza i sensori
}
void loop(void)
{
Serial.print("Richiedi temperatura...");


sensors.requestTemperatures(); // invia ai sensori la richiesta di misurare la temperatura
delay (1000); // attende un secondo per dare tempo ai sensori di effettuare la misurazione
Serial.println("fatto");


Serial.print("La temperatura del sensore 1 (indice 0) e': ");
Serial.println(sensors.getTempCByIndex(0)); // invia la monitor seriale la temperatura rilevata
delay (3000); // attende 3 secondi prima di verificare nuovamente la temperatura

  lcd.setCursor(0, 0); // posiziona il cursore all'inizio della prima riga
  lcd.print ("Temperatura: ");
  lcd.setCursor(0, 1);
  lcd.print (sensors.getTempCByIndex(0)); // espone il livello sul display lcd

  
}
