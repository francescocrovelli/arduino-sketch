/* Arduino semaforo con chiamata pedoni

autore Francesco Crovelli
*/

int vm = 2;   //sono delle abbreviazioni: vm=verde macchine
int gm = 3;
int rm = 4;
int vp = 5;
int gp = 6;
int rp = 7;
int pulsante1 = 8;
int stato_pulsante1 = 0;
int pulsante2 = 9;
int stato_pulsante2 = 0;

void setup() {
pinMode(vm, OUTPUT);
pinMode(gm, OUTPUT);
pinMode(rm, OUTPUT);
pinMode(vp, OUTPUT);
pinMode(gp, OUTPUT);
pinMode(rp, OUTPUT);
pinMode(pulsante1, INPUT);
pinMode(pulsante2, INPUT);
}

void loop() {
digitalWrite (vm, HIGH);
digitalWrite (rp, HIGH);
stato_pulsante1=digitalRead(pulsante1);
stato_pulsante2 = digitalRead(pulsante2);
if (stato_pulsante1 == 1) {
delay (3500);
digitalWrite (gm, HIGH);
digitalWrite (vm, LOW);
delay (1500);
digitalWrite (gm, LOW);
digitalWrite (rm, HIGH);
digitalWrite (rp, LOW);
digitalWrite (vp, HIGH);
delay (4000);
digitalWrite (gp, HIGH);
digitalWrite (vp, LOW);
delay (1500);
digitalWrite (gp, LOW);
digitalWrite (rp, HIGH);
digitalWrite (rm, LOW);
digitalWrite (vm, HIGH);
}
if (stato_pulsante2 == 1) {
delay (3500);
digitalWrite (gm, HIGH);
digitalWrite (vm, LOW);
delay (1500);
digitalWrite (gm, LOW);
digitalWrite (rm, HIGH);
digitalWrite (rp, LOW);
digitalWrite (vp, HIGH);
delay (4000);
digitalWrite (gp, HIGH);
digitalWrite (vp, LOW);
delay (1500);
digitalWrite (gp, LOW);
digitalWrite (rp, HIGH);
digitalWrite (rm, LOW);
digitalWrite (vm, HIGH);
}
}
