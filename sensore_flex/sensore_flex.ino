#include <Servo.h>


Servo myservo;
int pos = 170;
int pos1 = 20;

int flexSensorPin = A0; //analog pin 0

void setup(){
  Serial.begin(9600);
  myservo.attach(9);
}

void loop(){
  int flexSensorReading = analogRead(flexSensorPin); 
  
  // qui potete vedere da monitor seriale i valori e decidere il grado 
  // del servo tramite la variabile pos e pos1

  if(flexSensorReading < 80){
  myservo.write(pos); // tell servo to go to position in variable 'pos' 
  delay(15);
  }
  if(flexSensorReading > 110){
  myservo.write(pos1); // tell servo to go to position in variable 'pos' 
  delay(15);
  }

  Serial.println(flexSensorReading);


  int flex0to100 = map(flexSensorReading, 512, 614, 0, 100);
  Serial.println(flex0to100);

  //delay(250); //just here to slow down the output for easier reading
}

