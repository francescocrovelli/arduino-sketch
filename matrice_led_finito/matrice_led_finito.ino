
int pins[17]= { 99, 5, 4, 3, 2, 14, 15, 16, 17, 13, 12, 11, 10, 9, 8, 7, 6};
/* nella seguente tabella viene definita la correlazione tra le colonne (dalla 1 alla 8) e le porte di
Arduino cui sono collegate. Guardando la precedente tabella si puo’ arguire che la colonna 1 e’
collegata alla porta definita da pins[13] e cioe’ alla porta 9; la colonna 2 e’ collegata al pins[10] e
cioe’ porta 12….. */
int cols[8] = {pins[13], pins[10], pins[15], pins[9], pins[4], pins[16], pins[6], pins[1]};
/* nella seguente tabella viene definita la correlazione tra le righe (dalla 1 alla 8) e le porte di
arduino cui sono collegate. Guardando la precedente tabella si puo’ arguire che la riga 1 e’
collegata alla porta definita dal pins[8] e cioe’ alla porta 17 (A4); la riga 2 e’ collegata al pins[7] e
cioe’ porta 16 (A3)….. */
int rows[8] = {pins[8], pins[7], pins[3], pins[14], pins[2], pins[12], pins[11], pins[5]};
int comodo [65]; // area di lavoro utilizzata dalla routine di esposizione della matrice
int carcomodo [65]; // area di lavoro utilizzata dalla routine di gestione dello scorrimento testo
int refr = 0; // indice utilizzato per il refresh del display
 // Arduino: matrice led 8x8, scrivi e disegna
int z = 0; // indice utilizzato per spostare in tabella comodo i dati della matrice da visualizzare
int r = 0; // indice utilizzato per la scansione delle righe nella routine di gestione della matrice
int c = 0; // indice utilizzato per la scansione delle colonne nella routine di gestione matrice
int i = 0; // indice utilizzato in diverse parti del programma per pilotare righe e colonne
int colonna [8]; // tabella di memorizzazione della colonna da inviare alla routine di scorrimento
int semaforo = 0; // deviatore utilizzato per fornire il segnale di "colonna da visualizzare"
int r1 = 0; // indice di riga nella routine "esponi"
int c1 = 0; // indice di colonna nella routine "esponi"
int r2 = 0; // indice di riga nella routine "visualizzacolonna"
int c2 = 0; // indice di colonna nella routine "visualizza colonna"
// matrice di base per il disegno dei caratteri
// int carBase [65] = {
// 99, // il valore "99" e' un filler, utilizzato solo per riempire il primo (ed inutile) campo della tabella
// 0,0,0,0,0,0,0,0,
// 0,0,0,0,0,0,0,0,
// 0,0,0,0,0,0,0,0, // matrice di base per il disegno dei caratteri
// 0,0,0,0,0,0,0,0,
// 0,0,0,0,0,0,0,0,
// 0,0,0,0,0,0,0,0,
// 0,0,0,0,0,0,0,0,
// 0,0,0,0,0,0,0,0,
// };
// matrice della lettera "R" maiuscola, corsiva
int carR [65] = {
 99, // il valore "99" e' un filler, utilizzato solo per riempire il primo (ed inutile) campo della tabella
 0,0,0,0,0,0,0,0,
 1,1,1,0,0,0,0,0,
 1,0,0,1,0,0,0,0,
 1,0,0,1,0,0,0,0,
 1,1,1,0,0,0,0,0,
 1,1,0,0,0,0,0,0,
 1,0,1,0,1,0,0,0,
 1,0,0,1,0,0,0,0,
};
// matrice della lettera i minuscola, corsiva
int carI [65] = {
 99, // il valore "99" e' un filler, utilizzato solo per riempire il primo (ed inutile) campo della tabella
 0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,
 0,0,1,0,0,0,0,0,
 0,0,0,0,0,0,0,0,
 0,0,1,0,0,0,0,0,
 0,0,1,0,0,0,0,0,
 0,0,1,0,0,0,0,0,
 0,0,0,1,0,0,0,0,
};
// matrice della lettera m minuscola, corsiva
int carM [65] = {
 99,
 0,0,0,0,0,0,0,0,
 // Arduino: matrice led 8x8, scrivi e disegna
 0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,
 0,1,1,0,1,1,0,0,
 1,0,0,1,0,0,1,0,
 1,0,0,1,0,0,1,0,
 1,0,0,1,0,0,0,1,
};
// Matrice della lettera n minuscola, corsiva
int carN [65] = {
 99,
 0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,
 0,0,1,1,0,0,0,0,
 0,1,0,0,1,0,0,0,
 0,1,0,0,1,0,0,0,
 0,1,0,0,0,1,0,0,
};
// matrice per la definizione del primo disegno dell'animazione
int ca [65] = {
 99,
 0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,
 0,0,0,1,0,1,0,0,
 0,0,0,1,1,1,0,0,
 0,0,0,1,1,1,0,0,
 0,0,0,0,1,0,0,0,
};
// matrice per la definizione del secondo disegno dell'animazione
int cb [65] = {
 99,
 0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,
 0,0,0,1,0,1,0,0,
 0,0,1,1,1,1,1,0,
 0,0,1,1,1,1,1,0,
 0,0,0,1,1,1,0,0,
 0,0,0,0,1,0,0,0,
};
// matrice per la definizione del quarto disegno dell'animazione
int cd [65] = {
 99,
 0,0,0,0,0,0,0,0,
 0,0,1,1,0,1,1,0,
 0,1,0,0,1,0,0,1,
 0,1,0,0,0,0,0,1,
 0,1,0,0,0,0,0,1,
 // Arduino: matrice led 8x8, scrivi e disegna
 0,0,1,0,0,0,1,0,
 0,0,0,1,0,1,0,0,
 0,0,0,0,1,0,0,0,
};
// matrice per la definizione del terzo disegno dell'animazione
int cc [65] = {
 99,
 0,0,0,0,0,0,0,0,
 0,0,1,1,0,1,1,0,
 0,1,1,1,1,1,1,1,
 0,1,1,1,1,1,1,1,
 0,1,1,1,1,1,1,1,
 0,0,1,1,1,1,1,0,
 0,0,0,1,1,1,0,0,
 0,0,0,0,1,0,0,0,
};
// **************routine di esposizione della matrice memorizzata in tabella "comodo"***********
void esponi (void)
{
 for (refr = 1;refr<=300; refr++) // ripete 300 volte la routine di esposizione (fa il refresh) per
 { // ottenere qualche attimo di visibilita', prima di passare alla matrice successiva
 for (r1 = 1; r1 <= 8; r1 ++)
 {
 for (c1 = 1; c1 <= 8; c1 ++)
 {
 if (comodo [(r1-1)*8 + c1] ==1){ // se il byte in esame e' = 1 (led da accendere)
 digitalWrite (rows [r1-1], HIGH); // attiva la riga (anodo)
 digitalWrite (cols [c1-1], LOW); // disattiva la colonna (catodo) ed accende il led sul display
 }
 // in ogni caso spegne il led in esame. Anche se e' stato appena acceso l'effetto
 // persistenza lo manterra' comunque visibile fino al prossimo refresh:
 digitalWrite (rows [r1-1], LOW); // disattiva la riga (anodo)
 digitalWrite (cols [c1-1], HIGH); // attiva la colonna (catodo) e spegne il led
 }
 }
 }
}
// *** routine di preparazione della colona da inserire a destra del display in modalita’ scorrimento
void scorri (void)
{
 // ciclo di preparazione della nuova colonna da visualizzare
 for (c = 1; c <=8;c++)
 {
 for (r = 1; r<=8; r++)
 {
 colonna [r-1] = carcomodo [(r-1)*8 + c]; // trasferisce nella tabella "colonna" la colonna in
 // esame della matrice da esporre
 if (colonna[r-1] == 1) semaforo = 1; // attiva il semaforo di "colonna piena" se almeno un
 // led della colonna deve essere acceso
 // Arduino: matrice led 8x8, scrivi e disegna
 }
 if (semaforo ==1)
 { // al cambio di colonna verifica se deve essere
 // visualizzata la colonna precedente
 visualizzacolonna (); // se deve essere visualizzata lancia la routine di gestione scorrimento
 semaforo = 0;
 }
 }
}
// ****************** routine di preparazione della matrice da esporre in modalita’ scorrimento
void visualizzacolonna (void)
{
 for (c2 = 1; c2<=7; c2++)
 {
 for (r2 = 1; r2<=8; r2++)
 {
 comodo [(r2-1)*8+c2] = comodo [(r2-1)*8+c2+1]; // sposta a sinistra ogni colonna
 // della matrice "comodo"
 if (c2 == 7) comodo [(r2-1)*8+c2+1] = colonna [r2-1]; // inserisce la nuova colonna da
 // esporre nell'ottava colonna della matrice "comodo"
 }
 }
 esponi (); // lancia la routine di visualizzazione della matrice "comodo"
}
void setup()
{ // definisce come output le porte definite nella tabella pins
 for (i = 1; i <= 16; i++)
 {
 pinMode(pins[i], OUTPUT);
 }
}
void loop()
{
 for (i=1; i<=8;i++)
 { // spegne preventivamente tutti i led del display
 digitalWrite(rows[i - 1], LOW); // spegne tutte le righe (anodi) e spegne tutti i led
 digitalWrite(cols[i - 1], LOW); // spegne tutte le colonne (catodi) e predispone la matrice
 } // al suo utilizzo nel programma

 // ciclo di avvio: accende e spegne progressivamente, riga per riga, tutti i led
 for (i = 1; i <= 8; i++)
 {
 digitalWrite(rows[i - 1], HIGH); // accende progressivamente tutte le righe
 delay(100);
 }
 // Arduino: matrice led 8x8, scrivi e disegna
 for (i = 1; i <= 8; i++)
{
 digitalWrite(rows[i - 1], LOW); // spegne progressivamente tutte le righe
 delay(100);
 }
 // ************* modalita’ di scorrimento del testo**********************
for (i=1;i<=8;i++)
 {
 digitalWrite (cols [i-1], HIGH); // mette in stato di HIGH tutte le colonne (i catodi)
 digitalWrite (rows [i-1], LOW); // mette in stato di LOW tutte le righe (gli anodi)
 for (z = 1; z<=64; z++)
 {
 carcomodo [z] = 0; // pulisce le tabelle (le matrici) di lavoro
 comodo [z] = 0;
 }
 }
 // ************************ gestione della lettera R
 for (i=0; i<=64;i++)
 {
 carcomodo [i] = carR [i]; // inserisce la matrice della lettera R in carcomodo, che e’ la tabella
 // di input alla routine di scorrimento
 }
 scorri (); // lancia la routine di scorrimento e visualizzazione della matrice
 // ************************* gestione della lettera i
 for (i=0; i<=64;i++)
 {
 carcomodo [i] = carI [i];
 }
 scorri ();
 // *********************** gestione della lettera m
 for (i=0; i<=64;i++)
 {
 carcomodo [i] = carM [i];
 }
 scorri ();
 // *********************** gestione della lettera i
 for (i=0; i<=64;i++)
 {
 carcomodo [i] = carI [i];
 }
 scorri ();
 // ************************ gestione della lettera n
 for (i=0; i<=64;i++)
 {
 carcomodo [i] = carN [i];
 // Arduino: matrice led 8x8, scrivi e disegna
 }
 scorri ();
 // ************************* gestione della lettera i
 for (i=0; i<=64;i++)
{
 carcomodo [i] = carI [i];
 }
 scorri ();
 // ************************ gestione della fase di fine scorrimento
 for (i =0;i<=7;i++)
 {
 colonna [i] = 0; // Prepara una colonna spenta (la tabella colonna e' usata
} // dalla routine visualizzacolonna)
 for (z=0;z<=8;z++)
{
 visualizzacolonna (); // visualizza la colonna spenta, facendola scorrere 8 volte sul display
}
 // ************************** animazione finale
 // *********************** visualizzazione del primo sprite
 for (z = 0; z <=64;z++)
 {
 comodo [z] = ca [z]; // trasferisce nella tabella "comodo" la matrice da visualizzare
 }
 esponi();
 // *********************** visualizzazione del secondo sprite
 for (z = 0; z <=64;z++)
 {
 comodo [z] = cb [z]; // trasferisce nella tabella "comodo" la matrice da visualizzare
 }
 esponi();
 for (int a = 0; a<=4;a++)
{ //ripete per cinque volte gli ultimi due sprite della sequenza animata
 // ********************** routine di visualizzazione del terzo sprite
 for (z = 0; z <=64;z++)
 {
 comodo [z] = cc [z]; // trasferisce nella tabella "comodo" la matrice da visualizzare
 }
 esponi();
 // ******************* routine di visualizzazione del quarto sprite
 for (z = 0; z <=64;z++)
 {
 comodo [z] = cd [z]; // trasferisce nella tabella "comodo" la matrice da visualizzare
 // Arduino: matrice led 8x8, scrivi e disegna
 }
 esponi();
 }
}
