
int pins[17]= { 99, 5, 4, 3, 2, 14, 15, 16, 17, 13, 12, 11, 10, 9, 8, 7, 6};
/* nella tabella cols viene definita la correlazione tra le colonne (dalla 1 alla 8) e le porte di Arduino
cui sono collegate. Considerando la precedente tabella si deduce che la prima colonna e’ collegata
alla porta definita da pins[13] e cioe’ dal tredicesimo elemento della tabella pins (considerando il
primo come elemento zero) e quindi alla porta 9; la seconda colonna e’ collegata alla porta definita
da pins[10], il decimo elemento della tabella pins e cioe’ 12….. */
int cols[8] = { pins[13], pins[10], pins[15], pins[9], pins[4], pins[16], pins[6], pins[1]};
/* nella tabella rows viene definita la correlazione tra le righe (dalla 1 alla 8) e le porte alle quali
sono collegate. Come gia’ visto per le colonne, si deduce che la prima riga e’ collegata alla porta
definita da pins[8] e cioe’ alla porta 17 (A4); la seconda riga e’ collegata al pins[7] e cioe’ alla porta
16 (A3)….. */
int rows[8] = {pins[8], pins[7], pins[3], pins[14], pins[2], pins[12], pins[11], pins[5]};
void setup()
{
 for (int i = 1; i <= 16; i++) // definisce come output tutte le porte definite nella tabella pins)
 {
 pinMode(pins[i], OUTPUT);
 }
 for (int i = 1; i <= 8; i++) // definisce low tutti i pin e pertanto spegne tutti i led
 {
 digitalWrite(cols[i - 1], LOW);
 digitalWrite(rows[i - 1], LOW);
 }
}
void loop()
{

 for (int i = 1; i <= 8; i++)
 {
 digitalWrite(rows[i - 1], HIGH); // accende progressivamente tutti i led di ogni riga
 delay(100);
 }
 for (int i = 1; i <= 8; i++)
 {
 digitalWrite(rows[i - 1], LOW); // spegne progressivamente tutti i led di ogni riga
 delay(100);
 }
}
