int ledPin = 13;  //Il led è connesso al pin 13
int pulsante = 7;  //Il pulsante è connesso al pin 7
int val = 0; 
void setup() {
  pinMode(ledPin, OUTPUT);  //Il pin del led è un'uscita 
  pinMode(pulsante, INPUT);  //Il pin del pulsante è un'entrata 
  }
void loop() {
 
  val = digitalRead(pulsante);  //Lettura del pulsante  

  if (val == 1){  //Se il valore del pulsante è 1                        
    digitalWrite(ledPin, HIGH);  //Accendi il led    
  }  
  else {  //Altrimenti:                                        
    digitalWrite(ledPin, LOW);  //Spegni il led   
  }  
}  
