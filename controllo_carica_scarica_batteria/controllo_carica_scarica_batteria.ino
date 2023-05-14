
////////////////////////////////////////

// http://francescocrovelli.softr.app/
//Autore Francesco Crovelli

// ATTENZIONE; NON UTILIZZARE BATTERIE CON TENSIONI SUPERIORI 5V

///////////////////////////////////////

int valore;  //dichiaro la variabile valore che memorizzerà il valore dato dal convertitore analogico-digitale
int Rosso=8;  //dichiaro una variabile intera in cui collegherò il LED rosso
int Giallo=9; //dichiaro una variabile intera in cui collegherò il LED giallo
int Verde=10; //dichiaro una variabile intera in cui collegherò il LED verde

void setup()
 { 
  pinMode(8,OUTPUT);  //dico ad Arduino che il pin 8 (ENTRATA/USCITA DIGITALE) è da usare come OUTPUT 
  pinMode(9,OUTPUT);  //dico ad Arduino che il pin 9 (ENTRATA/USCITA DIGITALE) è da usare come OUTPUT  
  pinMode(10,OUTPUT); //dico ad Arduino che il pin 10(ENTRATA/USCITA DIGITALE) è da usare come OUTPUT  
 }
void loop()
{
 delay(100); //aspetto(100 millisecondi);
 valore=analogRead(0); //Leggo il valore analogico alla porta A0 e lo metto dentro "valore"
 if (valore>573) //se valore maggiore di 573 allora....
   {
     digitalWrite(Rosso,LOW);
     digitalWrite(Giallo,LOW);
     digitalWrite(Verde,HIGH);
   }
   if ((valore<573)&&(valore >=450)) //se valore maggiore di 450 e valore minore di 573 allora....
   {
     digitalWrite(Rosso,LOW);
     digitalWrite(Giallo,HIGH);
     digitalWrite(Verde,LOW);
   }
   if (valore<450)//se valore minore di 450 allora....
   {
     digitalWrite(Rosso,HIGH);
     digitalWrite(Giallo,LOW);
     digitalWrite(Verde,LOW);
   }

 delay(500); //aspetto mezzo secondo 
}
