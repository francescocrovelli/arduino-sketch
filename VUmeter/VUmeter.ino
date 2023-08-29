int analogPin = A0;               //setting A0 as analog pin
                   
int val = 0;                      //setting value for analog input to 0

void setup() {
  Serial.begin(9600);             //this line is used to setup SerialMonitor, to check value on our input
  for (int i = 2; i <=13; i++) {  //for loop that defines desired LED pins as Outputs
    pinMode(i, OUTPUT);
  }
          
}

void loop() {
  val = analogRead(analogPin);              //defining audio signal input on A0 as val variable
  Serial.println(val);                      //prints value of variable val in SerialMonitor
  int analogvalue=val/10;                   //dividing val and putting to variable analogvalue to match number of our LEDs
  for (int x = 2; x <= analogvalue; x++) {  //for loop that turns on so much LEDs, as big the analogvalue is
    digitalWrite(x, HIGH);
  }
  for (int y = 13; y >= analogvalue; y--) { //for loop that turns off so much LEDs, as big the analogvalue is
    digitalWrite(y, LOW);
  }
}
