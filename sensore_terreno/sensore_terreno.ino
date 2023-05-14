const int soglia_critica = 300; //Soglia alla quale il led sarà ON
void setup()
{
Serial.begin(9600);
pinMode(9, OUTPUT);
}
void loop()
{
int sensorValue = analogRead(A0); //Legge il valore analogico
Serial.println(sensorValue); //Stampa a schermo il valore
if (sensorValue <= soglia_critica)
digitalWrite(9,HIGH); //Accendi led
else
digitalWrite(9,LOW); //Spegni led
delay(2000); //Attende due secondi
}
