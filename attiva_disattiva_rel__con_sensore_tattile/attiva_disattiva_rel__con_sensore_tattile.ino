//////////////////////////////////////

// Arduino attiva disattiva relè con sensore tattile

// Autore Francesco Crovelli
// http://francescocrovelli.softr.app/

//////////////////////////////////////

const int sensore=7; // Pin alla quale e’ collegato il sensore tattile
const int portarel = 12; // Pin alla quale e’ collegato il relè
int statosensore=0; // variabile di memorizzazione dello stato del sensore
void setup()
{
 pinMode(sensore,INPUT);
 pinMode(portarel,OUTPUT);
}
void loop()
{
 statosensore=digitalRead(sensore); //rileva lo stato del sensore
 if(statosensore==HIGH) // se lo stato e’ HIGH (se il sensore e’ sotto tocco)
 {
 digitalWrite(portarel,HIGH); // Attiva il relè
 }
 else // se il sensore non e’ sotto tocco
 {
 digitalWrite(portarel,LOW); // disattiva il relè
 }
}
