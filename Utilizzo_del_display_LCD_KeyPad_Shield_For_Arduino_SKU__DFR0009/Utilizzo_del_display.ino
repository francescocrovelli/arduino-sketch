// UTILIZZO DEL DISPLAY LCD KEYPAD SHIELD (Aliverti - video n.206)
/*
Contenuti
- Ciclo if
- #define
- Switch...case...break
- Blocchi funzionali
- return
*/

//Questo display utilizza molti pin
//https://wiki.dfrobot.com/LCD_KeyPad_Shield_For_Arduino_SKU__DFR0009
//Rimangono liberi i pin 0,1,2,3,11,12,13
//Tutti i tasti vengono letti dal pin A0 e verificati leggendo il valore dalla seriale
/*
Nessun tasto premuto: 1023
Select: 722
Left: 481
Up: 133
Down: 309
Right: 0
*/

//Libreria LCD
//https://docs.arduino.cc/learn/electronics/lcd-displays
  #include <LiquidCrystal.h>

//Bisogna assegnare i pin del display LCD
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

//Assegnazione variabili
  int val;  // valori letti dai tasti
  int key;  // valore che ritorna il blocco funzione di lettura tasti
  
// Definizione delle soglie (ThresHold) dei tasti (i valori quando vengono premuti)
// #define NON crea una nuova variabile quindi non occupa spazio in memoria ma, durante la compilazione, 
// sostituisce nel programma tutti i nomi (es. TH_NONE) con il relativo valore (1023).
#define TH_NONE 1023 
#define TH_LEFT 481
#define TH_RIGHT 0
#define TH_UP 133
#define TH_DOWN 309
#define TH_SELECT 722
#define TOLL 5 // tolleranza di lettura

// Definizione del valori che si vogliono restituire quando si preme un tasto
#define KEY_NONE 0
#define KEY_LEFT 1
#define KEY_RIGHT 2
#define KEY_UP 3
#define KEY_DOWN 4
#define KEY_SELECT 5

void setup() {
  Serial.begin(9600);
  //inizializzazione del display
  lcd.begin(16, 2);
  //posiziono il cursore colonna 0, riga 0
  lcd.setCursor(0,0);
}

void loop() {
  //Richiamo il blocco funzione "readkeys" che ritorna la variabile nominata "key"
  key = readkeys();

  // Struttura Switch...case...break
  // Leggo il valore di ritorno "key" e scrivo sul display
  switch (key) {
    case KEY_LEFT:
      lcd.setCursor(0,0);
      lcd.print("LEFT");
    break;
    case KEY_RIGHT:
      lcd.setCursor(0,0);
      lcd.print("RIGHT");
    break;
  }

  // lcd.setCursor(0,1);
  // lcd.print(millis()/1000); // conteggio di secondi
  
}

  // Blocco funzione che legge i tasti e ritorna una variabile int
  int readkeys(){
  val = analogRead(A0); //leggo il valore dei tasti
  Serial.println(val);
    if ((val >= TH_LEFT-TOLL) && (val <= TH_LEFT+TOLL)) {
      return KEY_LEFT;
    }
    if ((val >= TH_RIGHT-TOLL) && (val <= TH_RIGHT+TOLL)) {
      return KEY_RIGHT;
    }
  }
  
