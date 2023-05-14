// www.ProgettiArduino.com
// Arduino blink facciamo lampeggiare un led  
  
  #define LED 13            // LED collegato al pin digitale 13  
  
void setup() {  
  pinMode(LED, OUTPUT);     // imposta il pin digitale come output  
}  
  
void loop() {  
  digitalWrite(LED, HIGH);  // accende il LED  
  delay(1000);              // aspetta un secondo  
  digitalWrite(LED, LOW);   // spegne il LED  
  delay(1000);              // aspetta un secondo  
}  
