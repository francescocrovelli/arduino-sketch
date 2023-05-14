// GENERATORE DI FUNZIONI DI FRANCESCO CROVELLI
void setup()
{
Serial.begin(9600); 
}
void loop()
{
float angolo = 0;
for (angolo = 0; angolo <= 90; angolo = angolo + 0.1)//Sfasamento seno e coseno
{
float seno = sin(angolo);// Variabile angolo seno
float coseno = cos(angolo);// Variabile angolo coseno
Serial.print(seno);
Serial.print(" ");
Serial.println(coseno);
delay(1);
}
for (float i = 0; i <= 90; i = i + 1)//Generatore funzione dente di sega
{
Serial.println(i);
delay(1);
}
for (int a = 0; a <= 100; a++)//Generatore funzione onda quadra
{
int b = 0;
Serial.println(b);
delay(1);
}
for (int a = 0; a <= 100; a++)
{
int b = 100;
Serial.println(b);
delay(1);
}
for (float i = 0; i <= 100; i = i + 1)//Generatore funzione onda triangolare
{
Serial.println(i);
delay(1);
}
for (float i = 100; i >= 0; i = i - 1)
{
Serial.println(i);
delay(1);
}
}
