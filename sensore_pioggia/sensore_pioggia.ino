

// ITA: Assegno i pin ai led
int pinIngresso=2;
int pinLed=3;

void setup()
{
   // ENG: Enable Serial Port (9600 baud)
   // ITA: Abilito la porta seriale (9600 baud)
  Serial.begin(9600);
  
  // ENG: Setup pins for INPUT and OUTPUT  
  // ITA: Imposto i pin come INPUT e come OUTPUT
  pinMode(pinIngresso, INPUT);
  pinMode(pinLed,OUTPUT);
  
}

//ENG: Variable declaration 
//ITA: Dichiarazione variabili 

int pioggia=0;
int misurazione=0;

void loop()
{
  // ITA: Leggo l'ingresso digitale
  // ENG: Reading digital input
  pioggia = digitalRead(pinIngresso);
  
  if(pioggia==1) 
    digitalWrite(pinLed,LOW);
  if(pioggia==0)
    digitalWrite(pinLed,HIGH);
    
    // ITA: Leggo l'ingresso analogico
    // ENG: Reading analog input
    misurazione = analogRead(A0);
    Serial.println(misurazione);
  
  
  
  delay(1000);
  
}
