int rosso1 = 2;
int giallo1 = 3;
int verde1 = 4;
int rosso2 = 5;
int giallo2 = 6;
int verde2 = 7;
void setup ()
{
  pinMode(rosso1, OUTPUT);
  pinMode(giallo1, OUTPUT);
  pinMode(verde1, OUTPUT);
  pinMode(rosso2, OUTPUT);
  pinMode(giallo2, OUTPUT);
  pinMode(verde2, OUTPUT);
}
void loop ()
{
  digitalWrite (rosso1, HIGH);
  digitalWrite (verde2, HIGH);
  digitalWrite (rosso2, LOW);
  delay (5000);
  digitalWrite (giallo2, HIGH);
  delay (5000);
  digitalWrite (rosso1, LOW);
  digitalWrite (verde1, HIGH);
  digitalWrite (verde2, LOW);
  digitalWrite (giallo2, LOW);
  digitalWrite (rosso2, HIGH);
  delay (5000);
  digitalWrite (giallo1, HIGH);
  delay (5000);
  digitalWrite (verde1, LOW);
  digitalWrite (giallo1, LOW);
}

