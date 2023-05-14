

int pulsante = LOW; // variabile di memorizzazione dello stato del pulsante
int i; // variabile intera utilizzata nei cicli di for
int j; // variabile intera utilizzata nei cicli di for
int z; // variabile intera utilizzata nei cicli di for
int h; // variabile intera utilizzata nei cicli di for
long tempo=61; // tempo di countdown, in minuti; viene inizializzato a 61 per forzare
 // il ciclo di prima volta
long tempoinizio = 0; // momento di inizio pressione del pulsante (millisecondi trascorsi
 // dal momento di accensione di arduino)
int decaminuti = 0; // decine di minuti da visualizzare sul display
int minuti = 0; // minuti da visualizzare sul display
int decasecondi = 0; // decine di secondi da visualizzare sul display
int secondi =0; // secondi da visualizzare sul display
int numero = 0; // numero da visualizzate nella cifra che viene di volta in volta trattata
int secondiresidui= 0; // tempo residuo, in secondi,
int lapse= 0; // tempo di suono del buzzer, in millisecocndi)
long iniziocountdown= 0; // momento di inizio del countdown, in millisecondi
long iniziobuzzer=0; // momento di inizio del suono del buzzer, in millisecondi
// Le routine che seguono hanno il compito di visualizzare i numeri e vengono eseguite solo
// nel momento in cui sono richiamate da istruzioni presenti nel percorso attivo del programma
// *************************** routine di visualizzazione del numero 1 ********************
void uno(void)
// Arduino: timer da cucina, display a 4 cifre
{
 digitalWrite(4,LOW);
 digitalWrite(6,LOW);
}
// ************************ routine di visualizzazione del numero 2 ***********************
void due(void)
{
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(1,LOW);
 digitalWrite(8,LOW);
 digitalWrite(7,LOW);
}
// ************************ routine di visualizzazione del numero 3 ************************
void tre(void)
{
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(1,LOW);
 digitalWrite(6,LOW);
 digitalWrite(7,LOW);
}
// ********************** routine di visualizzazione del numero 4 ************************
void quattro(void)
{
 digitalWrite(2,LOW);
 digitalWrite(1,LOW);
 digitalWrite(4,LOW);
 digitalWrite(6,LOW);
}
// *********************** routine di visualizzazione del numero 5 ***********************
void cinque(void)
{
 digitalWrite(3,LOW);
 digitalWrite(2,LOW);
 digitalWrite(1,LOW);
 digitalWrite(6,LOW);
 digitalWrite(7,LOW);
}
// ************************** routine di visualizzazione del numero 6 ***********************
void six(void)
{
 digitalWrite(2,LOW);
 digitalWrite(1,LOW);
digitalWrite(6,LOW);
 digitalWrite(7,LOW);
 digitalWrite(8,LOW);
}
// ************************* routine di visualizzazione del numero 7 *************************
void sette(void)
// Arduino: timer da cucina, display a 4 cifre
{
 digitalWrite(3,LOW); // disattiva la porta 3 e accende il segmento orizzontale alto
 digitalWrite(4,LOW); // disattiva la porta 4 e accende il segmento verticale alto destro
 digitalWrite(6,LOW); // disattiva la porta 6 e accende il segmento verticale basso destro
}
// *********************** routine di visualizzazione del numero 8 ****************************
void otto(void)
{
 digitalWrite(1,LOW);
 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(6,LOW);
 digitalWrite(7,LOW);
 digitalWrite(8,LOW);
}
// *********************** routine di visualizzazione del numero 9 *************************
void nove(void)
{
 digitalWrite(1,LOW);
 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(6,LOW);
}
// **************************** routine di visualizzazione del numero 0 ***********************
void zero(void)
{
 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(6,LOW);
 digitalWrite(7,LOW);
 digitalWrite(8,LOW);
}
// ********** routine di gestione del display (di esposizione del tempo residuo) ***************
// viene gestita una cifra per volta attivando e disattivando le porte da 9 a 12 alle quali sono
// collegati gli anodi delle quattro cifre del display
void esponi (void)
{
 for (z=9; z<=12; z++) // for di gestione delle porte (da 9 a 12, alle quali sono
 // collegati i quattro anodi delle quattro cifre)
 {
 for (j=1; j<=8; j++)
 digitalWrite (j, HIGH); // attiva tutti i catodi, per iniziare con tutti i segmenti spenti
 digitalWrite (z, HIGH); // attiva l'anodo della cifra da esporre
 switch (z) {
 case 9: // se si sta trattando la porta 9 (prima cifra di sinistra)
 numero = decaminuti; // inserisce le decine di minuti nel numero da esporre
 break;
// Arduino: timer da cucina, display a 4 cifre
 case 10: // se si sta trattando la porta 10 ( seconda cifra da sinistra)
 numero = minuti; // inserisce i minuti nel numero esporre
 digitalWrite (5, LOW); // accende il punto decimale come separatore dei minuti dai secondi
 break;
 case 11: // se si sta trattando la porta 11 (terza cifra da sinistra)
 numero = decasecondi; // inserisce le decine di secondi nella porta da esporre
 break;
 case 12 : // se si sta trattando la porta 12 (quarta ed ultima cifra a destra)
 numero = secondi; // inserisce i secondi nel numero da esporre
 break;
 }
 visualizzanumeri (); // lancia la routine di visualizzazione del numero nella cifra corrente
 digitalWrite (z,LOW); // disattiva (spegne) l'anodo della cifra appena visualizzata
 }
}
// ******************routine di visualizzazione dei numeri ****************************
// La routine si limita ad attivare i catodi dei vari segmenti
// poiche' l'anodo della cifra corrente e' stato gia' attivato dalla routine chiamante
void visualizzanumeri (void)
{
 switch (numero) {

case 0:
 zero ();
 break;

case 1:
 uno();
 break;

case 2:
 due();
 break;
case 3:
 tre();
 break;

case 4:
 quattro();
 break;

case 5:
 cinque();
 break;

case 6:
 six();
 break;
 
// Arduino: timer da cucina, display a 4 cifre
case 7:
 sette();
 break;

case 8:
 otto();
 break;

case 9:
 nove();
 break;
 }
}
void setup()
{
 for(i=0;i<=12;i++)
 pinMode(i,OUTPUT); // definisce le porte da 0 a 12 come porte di output
 pinMode (13, INPUT); // definisce la porta 13 (il pulsante) come porta di input
}
void loop()
{
 pulsante = 0;
 pulsante = digitalRead (13); // acquisisce lo stato del pulsante
 while (pulsante==1) // settaggio del timer; se il pulsante e' premuto si innesca
 // la routine di settaggio, che aumenta di 1 minuto il tempo
// di countdown per ogni secondo continuativo di pressione;
// arrivati a 60 minuti il settaggio ricomincia da 0
 {
 pulsante = digitalRead (13);
 if (tempo >= 60) { // se sono stati superati i 60 minuti, ricomincia il settaggio da 0 minuti
 tempo = 0;
 tempoinizio = millis ();
 }
 else
 {
 tempo = (millis() - tempoinizio)/1000; //calcola il tempo trascorso dall’inizio pressione pulsante
 }
 decaminuti = (tempo / 10); // memorizza nelle decine di minuti il risultato di tempo/10
 minuti = (tempo%10); // memorizza in minuti il resto della divisione per 10 del tempo
 decasecondi = 0;
 secondi = 0;
 esponi (); // visualizza i minuti di settaggio del timer
 secondiresidui = tempo * 60; // memorizza i secondi sino ad ora settati (minuti * 60)
 iniziocountdown = millis(); // memorizza il momento di inizio del countdown, da utilizzare
 // nel caso il pulsante fosse stato rilasciato e dovesse iniziare il countdown
 }
 // *********************ciclo di gestione del countdown **************************************
 tempoinizio = millis();
 if (secondiresidui >=1) { // gestione del tempo residuo e della relativa visualizzazione
 decaminuti = secondiresidui/600;
 minuti = (secondiresidui - (decaminuti*600))/60;
 decasecondi = (secondiresidui - (decaminuti*600)-(minuti*60))/10;
 secondi = (secondiresidui - (decaminuti*600)-(minuti*60) - (decasecondi*10)); 
// Arduino: timer da cucina, display a 4 cifre
 esponi ();
 secondiresidui = ((iniziocountdown + tempo*60000)-millis())/1000; //calcola i secondi residui di
 // coundown
 iniziobuzzer = millis ();
 }
 else
 { // gestione del fine countdown e attivazione del buzzer
 if ((tempo <= 60) && (lapse < 5000))
 {
 digitalWrite (0,HIGH); //attiva il buzzer per 5 secondi (5000 millisecondi)
 decaminuti =0;
 minuti = 0;
 decasecondi = 0;
 secondi = 0;
 esponi ();
 lapse = millis() - iniziocountdown;
 }
 else // se e’ cessato l’allarme predispone il sistema ad un nuovo settaggio
 {
 digitalWrite (0,LOW);
 tempo = 61;
 lapse = 0;
 }
 }
}
