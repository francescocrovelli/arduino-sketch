#define ledVerde 13
#define ledRosso 12
#define ledGiallo 11
#define ledBlu 10

#define buttonVerde 9
#define buttonRosso 8
#define buttonGiallo 7
#define buttonBlu 6

int livello = 0;
bool risultato = true;
int gioco[10];
int risposta[10];

void setup() {
  // put your setup code here, to run once:
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRosso, OUTPUT);
  pinMode(ledGiallo, OUTPUT);
  pinMode(ledBlu, OUTPUT);

  pinMode(buttonVerde, INPUT_PULLUP);
  pinMode(buttonRosso, INPUT_PULLUP);
  pinMode(buttonGiallo, INPUT_PULLUP);
  pinMode(buttonBlu, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  risultato = true;
  livello = 0;
  for (int n = 0; n < 10; n++) {
    gioco[n] = random(0, 4);
    risposta[n] = 4;
    //Serial.print(gioco[n]);
  }
  //Serial.println();

  do {
    for (int i = 0; i <= livello; i++) {
      accendi(gioco[i]);
      delay(200);
    }
    //delay(1000);
    prova();
    //livello++;
    /*if (livello == 10)
      risultato = false;*/
    if (risultato)
      livello++;
  } while ((risultato) && (livello < 10));

  if (livello == 10) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledRosso, LOW);
      digitalWrite(ledGiallo, LOW);
      digitalWrite(ledBlu, LOW);
      delay(100);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledRosso, HIGH);
      digitalWrite(ledGiallo, LOW);
      digitalWrite(ledBlu, LOW);
      delay(100);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledRosso, LOW);
      digitalWrite(ledGiallo, HIGH);
      digitalWrite(ledBlu, LOW);
      delay(100);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledRosso, LOW);
      digitalWrite(ledGiallo, LOW);
      digitalWrite(ledBlu, HIGH);
      delay(100);
    }
  } else {
    for (int i = 0; i < 3; i++) {
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledRosso, HIGH);
      digitalWrite(ledGiallo, HIGH);
      digitalWrite(ledBlu, HIGH);
      delay(200);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledRosso, LOW);
      digitalWrite(ledGiallo, LOW);
      digitalWrite(ledBlu, LOW);
      delay(200);
    }
  }
}

void accendi(int val) {
  if (val == 0) {
    digitalWrite(ledVerde, HIGH);
    delay(500);
    digitalWrite(ledVerde, LOW);
  } else if (val == 1) {
    digitalWrite(ledRosso, HIGH);
    delay(500);
    digitalWrite(ledRosso, LOW);
  } else if (val == 2) {
    digitalWrite(ledGiallo, HIGH);
    delay(500);
    digitalWrite(ledGiallo, LOW);
  } else if (val == 3) {
    digitalWrite(ledBlu, HIGH);
    delay(500);
    digitalWrite(ledBlu, LOW);
  }
}

void prova() {
  int s = 0;
  do {
    Serial.println();
    if (digitalRead(buttonVerde) == 0) {
      risposta[s] = 0;
      //Serial.print(risposta[s]);
      delay(300);
      if (risposta[s] != gioco[s])
        risultato = false;
      s++;
    }
    if (digitalRead(buttonRosso) == 0) {
      risposta[s] = 1;
      //Serial.print(risposta[s]);
      delay(300);
      if (risposta[s] != gioco[s])
        risultato = false;
      s++;
    }
    if (digitalRead(buttonGiallo) == 0) {
      risposta[s] = 2;
      Serial.print(risposta[s]);
      delay(300);
      if (risposta[s] != gioco[s])
        risultato = false;
      s++;
    }
    if (digitalRead(buttonBlu) == 0) {
      risposta[s] = 3;
      //Serial.print(risposta[s]);
      delay(300);
      if (risposta[s] != gioco[s])
        risultato = false;
      s++;
    }
  } while ((risposta[livello] == 4) && (risultato));

  for (int i = 0; i < 10; i++) {
    risposta[i] = 4;
  }
}
