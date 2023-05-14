#include <DHT.h>

#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 8
// 8 è il pin di Arduino a cui collego il sensore di temperatura
#define DHTTYPE DHT11
// dht11 è il tipo di sensore che uso
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// connessione display (pin)
 
void setup() {
lcd.begin(16, 2);
// imposto il tipo di display (colonne, righe)
lcd.print("Temperatura");
lcd.setCursor(0,1);
lcd.print("Umidita'");
}
void loop() {
int t = dht.readTemperature();
int h = dht.readHumidity();
// posiziono il cursore alla colonna 12 e riga 0
lcd.setCursor(14, 0);
lcd.print(t);
lcd.setCursor(14, 1);
lcd.print(h);
}
