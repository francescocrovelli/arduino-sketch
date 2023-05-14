
// variabili utilizzate nel programma
int pulsante = LOW; // variabile di stato del pulsante, valore iniziale 0 (LOW)
int i; // variabile utilizzata nei cicli for
int j; // variabile utilizzata nei cicli for
/* Le routine che seguono vengono eseguite solo quando sono richiamate da istruzioni presenti
nella sezione void loop ()*/
// ************************ routine di visualizzazione del numero 1 **************
void uno(void)
{
 for (j=1;j<=8;j++)
 digitalWrite(j,HIGH); // attiva tutte le porte e spegne preventivamente tutti i led
 digitalWrite(4,LOW); // disattiva la porta 4 e accende il segmento verticale destro alto
 digitalWrite(6,LOW); // disattiva la porta 6 e accende il segmento verticale destro basso
}
// *********************** routine di visualizzazione del numero 2 **********************
void due(void)
{
 for (j=1;j<=8;j++)
 digitalWrite(j,LOW); // disattiva tutte le porte e accende preventivamente tutti i led
 digitalWrite(6,HIGH); // attiva la porta 6 e spegne il segmento verticale destro basso
 digitalWrite(2,HIGH); // attiva la porta 2 e spegne il segmento verticale sinistro alto
 digitalWrite(5,HIGH); // attiva la porta 5 e spegne il punto decimale
}

// ********************** routine di visualizzazione del numero 3 *********************
void tre(void)
{
 for (j=1;j<=8;j++)
 digitalWrite(j,LOW); // disattiva tutte le porte e accende preventivamente tutti i led
 digitalWrite(2,HIGH); // attiva la porta 2 e spegne il segmento verticale alto di sinistra
 digitalWrite(8,HIGH); // attiva la porta 8 e spegne il segmento verticale basso di sinistra
 digitalWrite(5,HIGH); // attiva la porta 5 e spegne il punto decimale
}
// ********************* routine di visualizzazione del numero 4 **********************
void quattro(void)
{
 digitalWrite(j,LOW); // disattiva tutte le porte e quindi accende preventivamente tutti i led
 digitalWrite(5,HIGH); // attiva la porta 5 e spegne il punto decimale
 digitalWrite(7,HIGH); // attiva la porta 7 e spegne il segmento orizzontale basso
 digitalWrite(8,HIGH); // attiva la porta 8 e spegne il segmento verticale sinistro basso
 digitalWrite(3,HIGH); // attiva la porta 3 e spegne il segmento orizzontale alto
}
// *************************** routine di visualizzazione del numero 5 **********************
void cinque(void)
// Arduino: countdown, cifra digitale
{
 for (j=1;j<=8;j++)
 digitalWrite(j,LOW); // disattiva tutte le porte e quindi accende preventivamente tutti i led
 digitalWrite (5, HIGH); // attiva la porta 5 e spegne il punto decimale
 digitalWrite (4, HIGH); // attiva la porta 4 e spegne il segmento verticale alto destro
 digitalWrite (8, HIGH); // attiva la porta 8 e spegne il segmento verticale basso sinistro
}
// ************************ routine di visualizzazione del numero 6 ****************************
void six(void) // e’ stato usato il termine six al posto di “sei” poiche’ “sei”
{ // e’ parola “riservata” che manda in crisi il compilatore
 for (j=1;j<=8;j++)
 digitalWrite(j,LOW); // disattiva tutte le porte e quindi accende preventivamente tutti i led
 digitalWrite(5, HIGH); // attiva la porta 5 e spegne il punto decimale
 digitalWrite(4,HIGH); // attiva la porta 4 e spegne il segmento verticale alto destro
}
// ***************************** routine di visualizzazione del numero 7 ************************
void sette(void)
{
 for (j=1;j<=8;j++)
 digitalWrite(j,HIGH); // disattiva tutte le porte e quindi spegne preventivamente tutti i led
digitalWrite(3,LOW); // disattiva la porta 3 e accende il segmento orizzontale alto
digitalWrite(4,LOW); // disattiva la porta 4 e accende il segmento verticale alto destro
digitalWrite(6,LOW); // disattiva la porta 6 e accende il segmento verticale basso destro
}
// ********************************* routine di visualizzazione del numero 8 ********************
void otto(void)
{
 for (j=1;j<=8;j++)
 digitalWrite(j,LOW); // disattiva tutte le porte e quindi accende preventivamente tutti i led
 digitalWrite(5,HIGH); // attiva la porta 5 e spegne il punto decimale
}
// ************************ routine di visualizzazione del numero 9 ***********************
void nove(void)
{
 for (j=1;j<=8;j++)
 digitalWrite(j,LOW); // disattiva tutte le porte e quindi accende preventivamente tutti i led
 digitalWrite(5,HIGH); // attiva la porta 5 e spegne il punto decimale
 digitalWrite(8, HIGH); // attiva la porta 8 e quindi spegne il segmento verticale basso sinistro
}
// **************************** routine di visualizzazione del numero zero *************************
void zero(void)
{
 for (j=1;j<=8;j++)
 digitalWrite(j,LOW); // disattiva tutte le porte e quindi accende preventivamente tutti i led
 digitalWrite(5,HIGH); // attiva la porta 5 e spegne il punto decimale
 digitalWrite(1, HIGH); // attiva la porta 1 e spegne il segmento orizzontale centrale
}
void setup()
{
 for(i=1;i<=8;i++)
// Arduino: countdown, cifra digitale
 pinMode(i,OUTPUT); // definisce le porte da 1 a 8 come porte di output
 pinMode(11,INPUT); // definisce la porta 11, alla quale e' collegato il pulsante,
 // come una porta di input
 pinMode(12,OUTPUT); // definisce la porta 12, alla quale e' collegato il buzzer, come
 // una porta di output
 pinMode(13,OUTPUT); // definisce la porta 13, alla quale e' collegato il led, come una
 // porta di output
}
void loop()
{
 for (j=1;j<=8;j++)
 digitalWrite(j,HIGH); // attiva tutte le porte e quindi spegne tutti i led della cifra digitale
pulsante = digitalRead(11); // legge lo stato del pulsante
 while (pulsante) // esegue le istruzioni successive solo se il valore del pulsante e' 1 (High)
 // e cioe’ se il pulsante e’ premuto
 {
 nove(); // lancia la routine di visualizzazione del numero 9
 delay(1000); // attende 1 secondo
 otto(); // lancia la routine di visualizzazione del numero 8 .....
 delay(1000);
 sette();
 delay(1000);
 six();
 delay(1000);
 cinque();
 delay(1000);
 quattro();
 delay(1000);
 tre();
 delay(1000);
 due();
 delay(1000);
 uno();
 delay(1000);
 zero();
 delay(1000);
 for (j=1;j<=8;j++)
 digitalWrite(j,HIGH); // attiva tutte le porte e quindi spegne tutti i led
 for (i=1;i<=20;i++) //routine per l'emissione del segnale sonoro e per il lampeggio del led
 {
 digitalWrite(13, HIGH); // accende il led
 digitalWrite(12, LOW); // spegne il buzzer
 digitalWrite(5, LOW); // accende il punto decimale
 delay (70);
 digitalWrite(13, LOW); // spegne il led
 digitalWrite(12,HIGH); // attiva il buzzer
 digitalWrite (5, HIGH); // spegne il punto decimale
 delay (70);
 pulsante = LOW; // pone il pulsante in stato LOW, in modo da non ripetere il countdown
 // fino a quando il pulsante non verra’ nuovamente premuto
 digitalWrite(12,LOW); // spegne il buzzer
 }
 }
}
