int i; // definisce la variabile “i” utilizzata in un ciclo di for
void setup()
{
  pinMode(7, OUTPUT); // definisce la porta 7 come una porta di output
  pinMode(4, OUTPUT); // definisce la porta 4 come una porta di output
}
void loop()
{
  for (i = 0; i < 350; i++) // definisce la durata del primo suono (350 cicli da 2 millisecondi).
    // La descrizione estesa dell’utilizzo dell’istruzione for e’ reperibile
    // nell’esercizio 05 – carosello di luci
  {
    digitalWrite(7, HIGH); // attiva il suono
    digitalWrite(4, HIGH); // accende il led
    delay(1); // attende 1 millisecondo. Di fatto ripete il suono ogni 2 millisecondi e
    // quindi con una frequenza di 500 ripetizioni al secondo
    digitalWrite(7, LOW); // disattiva il suono
    delay(1); // attende 1 millisecondo e riparte dall’istruzione for (350 ripetizioni)
  }
  delay (50); // attende 50 millisecondi prima di lanciare il secondo ciclo di suoni
  for (i = 0; i < 150; i++) // definisce la durata del secondo suono (150 cicli da 4 millisecondi)
  {
    digitalWrite(7, HIGH); // attiva il suono
    digitalWrite(4, LOW); // spegne il led
    delay(2); // attende 2 millisecondi (ripete il suono ogni 4 millisecondi e quindi
    // 250 volte al secondo)
    digitalWrite(7, LOW); // spegne il suono
    delay(2); // attende 2 millisecondi e ripete il ciclo per 150 volte
  }
}
