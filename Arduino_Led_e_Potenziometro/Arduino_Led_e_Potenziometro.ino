//Arduino Led e potenziometro, Facciamo lampeggiare un led in base al valore dato dal potenziometro
//Per maggiori info: www.ProgettiArduino.com

int Ledpin = 9; //Il pin a cui è connesso il led 

void setup() { 
pinMode(Ledpin, OUTPUT); //Il pin è in uscita 
} 

void loop() { 
digitalWrite(Ledpin, HIGH); //Il led è acceso 
delay(analogRead(0)); //Attendi il valore letto dal pin analogico 0 
digitalWrite(Ledpin, LOW); //Spegni il led 
delay(analogRead(0)); //Attendi nuovamente il tempo letto dal pin analogico 0 
}
