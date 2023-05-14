/* Attenzione: facendo il copia/incolla dal PDF all’IDE si perde la formattazione del testo. Per
  rendere piu’ facilmente leggibile il programma e’ opportuno formattarlo subito dopo il trasferimento
  nell’IDE, premendo CTRL+T
  In questo esercizio si utilizza l'istruzione "for" e si sperimenta il richiamo di una subroutine.
  Per ragioni scenografiche sarebbe opportuno collegare i led alle porte secondo questo schema:
  led rossi: porta 1 e porta 6
  led verdi: porta 2 e porta 5
  led gialli: porta 3 e porta 4
******************************** definizione delle variabili ********************************** */
unsigned char j;  // definisce la variabile j, di un carattere e priva di segno
unsigned char k;  // definisce la variabile k, di un carattere privo di segno
unsigned char i;  // definisce la variabile i, di un carattere privo di segno
/* In questa zona, che precede la sezione di setup, sono inserite le subroutine che
  verranno poi lanciate da istruzioni presenti nella sezione di loop o nella routine attiva.
************************************ subroutine stile1 **************************************** */
void stile1(void)  // subroutine per l'accensione in sequenza dei led e per il loro
// spegnimento, sempre in sequenza, partendo dal fondo
{
  for (j = 1; j <= 6; j++)  // innesca un ciclo "for" che si ripete fino a quando il valore di j,
  // inizialmente a 1, diventa 6 grazie all’incremento di 1 (j++) ad ogni
  // ripetizione
  {
    digitalWrite(j, HIGH);  // accende il led collegato alla porta j (da 1 a 6)
    delay(200);             // si ferma per 200 millisecondi prima di ricominciare il ciclo "for" e
    // accendere il led successivo
  }
  for (j = 6; j >= 1; j--)  // ripete il precedente ciclo "for" al contrario, con j che va da 6 a 1
  // decrementando di 1 (j--) il valore di j ad ogni ripetizione
  {
    digitalWrite(j, LOW);  // spegne il led collegato alla porta j
    delay(200);            // aspetta 200 millisecondi prima di ricominciare il ciclo "for" e
    // spegnere il led precedente
  }
}
/************************************* subroutine lampo****************************************/
void lampo(void)  // subroutine per il lampeggio contemporaneo dei led (ripetuto due volte)
{
  for (k = 0; k <= 1; k++)  // ciclo for ripetuto due volte (con k che va da 0 a 1,incrementato di 1
  // ad ogni ciclo (k++))
  {
    for (j = 1; j <= 6; j++)  // ciclo for, interno al precedente, ripetuto 6 volte
      digitalWrite(j, HIGH);  // accende il led in posizione j
    delay(200);               // aspetta 200 millisecondi
    for (j = 1; j <= 6; j++)  // altro ciclo ripetuto 6 volte
      digitalWrite(j, LOW);   // spegne il led in posizione j
    delay(200);               // aspetta 200 millisecondi
  }
}
/********************************** subroutine stile2 ****************************************/
void stile2(void)  // subroutine per l'accensione e lo spegnimento progressivo
// dei led, partendo da quelli centrali
{
  k = 1;
  for (j = 3; j >= 1; j--)  // ciclo di accensione
  {
    digitalWrite(j, HIGH);
    digitalWrite(j + k, HIGH);
    delay(400);
    k += 2;  // incrementa di 2 il valore di k e ripete il ciclo di for
  }
  k = 5;
  for (j = 1; j <= 3; j++)  // ciclo di spegnimento
  {
    digitalWrite(j, LOW);
    digitalWrite(j + k, LOW);
    delay(400);
    k -= 2;  // decrementa di 2 il valore di k e ripete il ciclo di for
  }
}
/******************************************* subroutine stile3 ************************************/
void stile3(void)  // subroutine per l’accensione e lo spegnimento dei led a coppie di 2,
// partendo da quelli periferici
{
  k = 5;
  for (j = 1; j <= 3; j++)  // ciclo di accensione e spegnimento dei led: 1 e 6; 2 e 5; 3 e 4
  {
    digitalWrite(j, HIGH);
    digitalWrite(j + k, HIGH);
    delay(400);
    digitalWrite(j, LOW);
    digitalWrite(j + k, LOW);
    k -= 2;
  }
  k = 3;
  for (j = 2; j >= 1; j--)  // ciclo di accensione e spegnimento dei led: 3 e 4; 2 e 5; 1 e 6
  {
    digitalWrite(j, HIGH);
    digitalWrite(j + k, HIGH);
    delay(400);
    digitalWrite(j, LOW);
    digitalWrite(j + k, LOW);
    k += 2;
  }
}
/********************************** sezione di setup **************************************/
void setup()  // inizio della sezione di setup, le cui istruzioni vengono eseguite
// una sola volta, all’attivazione del programma
{
  for (i = 1; i <= 6; i++)  // ciclo di for per definire le porte da 1 a 6 come porte di output
    pinMode(i, OUTPUT);
}
/*************************************** sezione di loop *************************************/
void loop()  // sezione di loop, che si ripete sino a quando non viene tolta
// l’alimentazione alla scheda o viene premuto il tasto reset
{
  stile1();  // attivazione della subroutine “stile1”
  lampo();   // attivazione della subroutine “lampo”
  stile2();  // attivazione della subroutine “stile2”
  lampo();   // attivazione della subroutine “lampo”
  stile3();  // attivazione della subroutine “stile3”
  lampo();   // attivazione della subroutine “lampo”
}
