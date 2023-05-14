#include <LiquidCrystal.h>

LiquidCrystal lcd ( 2,   //RS
                    3,  //EN
                    4,  //D4
                    5,  //D5
                    6,  //D6
                    7); //D7  
// ****************************** variabili ********************************
int livello = 0; // variabile di memorizzazione del livello dell'acqua
int valoremin = 500; // variabile in cui viene memorizzato il valore minimo
// rilevabile dal sensore (definito sperimentalmente,
// con la bacinella vuota)
int valoremax = 700; // variabile in cui viene memorizzato il valore
// massimo rilevabile dal
// sensore (definito sperimentalmente, con la
// bacinella piena di acqua)
int i = 0; // indice utilizzato nel ciclo for per lo spegnimento
// preventivo dei led
void setup()
{
  Serial.begin(9600); // inizializza la comunicazione sul monitor seriale
  lcd.begin(16, 2); // inizializza il display (16 caratteri per due righe)
 
  pinMode (9, OUTPUT); // led verde collegato alla porta 9
  pinMode (10, OUTPUT); // led verde collegato alla porta 10
  pinMode (11, OUTPUT); // led giallo collegato alla porta 11
  pinMode (12, OUTPUT); // led rosso collegato alla porta 12
  digitalWrite (12, HIGH); // accende la spia rossa di livello basso (questa
  // spia resta sempre accesa poiche' segnala la
  // situazione di serbatoio con meno del 20% di acqua
  // e quindi la situazione peggiore
}
void loop()
{
  livello = analogRead (0); //acquisisce il segnale dal sensore livello acqua
  Serial.print ("livello: = ");
  Serial.print (livello);
  if (livello < 500) // se il segnale e’ sotto il minimo
    livello = 500; // lo porta al minimo
  if (livello > 700) // se il segnale e’ sopra il massimo
    livello = 700; // lo riporta al massimo
  livello = map(livello, valoremin, valoremax, 0, 100); // rimappa il livello
  // fornito dal sensore, portandolo su di una scala
  // da 0 a 100
  Serial.print (" - ");
  Serial.print(livello); // espone sul monitor seriale la % di riempimento
  Serial.println ("%");
  lcd.clear ();
  lcd.setCursor(0, 0); // posiziona il cursore all'inizio della prima riga
  lcd.print ("livello: ");
  lcd.print (livello); // espone il livello sul display lcd
  lcd.print ("%");
  for (i = 9; i <= 11; i ++)
    digitalWrite (i, LOW); // Spegne preventivamente i led giallo e verdi
  if (livello > 20)
    digitalWrite (11, HIGH); // se il livello e' piu' del 20% accende la spia
  // gialla (livello medio/basso)
  if (livello > 50)
    digitalWrite (10, HIGH); // se il livello e' piu' del 50% accende la prima
  // spia verde (livello medio/alto)
  if (livello > 80)
    digitalWrite (9, HIGH); // se il livello e' piu' del 80% accende la seconda
  // spia verde (livello alto)
  delay (1000); // attende un secondo prima di effettuare una nuova
  // rilevazione
}

