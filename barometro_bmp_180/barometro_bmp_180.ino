/*####################################################################
 FILE: barometro_BMP_180
 VERSION: 1.0
 Applicazione realizzata da Francesco Crovelli
 Sito http://francescocrovelli.softr.app/
 
 This example code is in the public domain.
 #################################################################### */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <BMP180.h>
LiquidCrystal_I2C lcd(0x27,16,2); 

BMP180 barometer;

int indicatorLed = 13; 
// Inserisci qui i dati relativi alla tua posizione calcolati con il tool
float seaLevelPressure = 101325;
void setup()
{

  
  Serial.begin(9600);
  
  Wire.begin();
 
  pinMode(indicatorLed, OUTPUT);
  
  barometer = BMP180();
  
  if(barometer.EnsureConnected())
  {
    Serial.println("Connesso con BMP180."); 
    digitalWrite(indicatorLed, HIGH); // Set our LED.
   
    barometer.SoftReset();
  
    barometer.Initialize();
  }
  else
  { 
    Serial.println("Sensore non coll");
    digitalWrite(indicatorLed, LOW); 
  }
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Test BMP180");
  lcd.setCursor(0, 1);
  lcd.print("progettiarduino.weebly.com");
  delay(5000);
}
void loop()
{
  if(barometer.IsConnected)
  {
    
    long currentPressure = barometer.GetPressure();
   
    float altitude = barometer.GetAltitude(seaLevelPressure);
  
    float currentTemperature = barometer.GetTemperature();
    Serial.println(); 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(currentPressure);
    lcd.print(" Pa");
    lcd.setCursor(0, 1);
    lcd.print (altitude);
    lcd.print (" m");
    lcd.setCursor(9, 1);
    lcd.print (currentTemperature);
    lcd.print (" C");
    delay(1000); 
  }
}
