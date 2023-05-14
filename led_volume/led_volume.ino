int valoresuono = 0; // variabile valoresuono, che contiene il valore rilevato
// sulla porta 0 (il segnale in uscita dal microfono)
int i = 0; // indice utilizzato per le routine di gestione dei led
int base = 360; // valore di base, utilizzato per definire la soglia minima di accensione
// dei led, che varia in maniera imprevedibile (da 180 a 400) ad ogni
// nuovo utilizzo del sistema.
void setup()
{
 for (i = 7; i <= 12; i++) // ciclo di for per definire le porte da 7 a 12 come porte di output
 pinMode(i, OUTPUT);
 Serial.begin(9600); //inizializza il monitor seriale, per l'esposizione della traccia di debug
}
void loop()
{
 valoresuono = analogRead(A0); // rileva il valore (il volume) del suono
 Serial.println (valoresuono); // traccia di debug
 for (i = 7; i <= 12; i++)
 digitalWrite(i, LOW); // spegne preventivamente tutti i led
 if (valoresuono >= base) // Se il suono supera il valore base
 digitalWrite (12, HIGH); // accende il primo led da sinistra
 if (valoresuono >= base + 16) // Se il suono supera il valore base + 15
 digitalWrite (11, HIGH); //accende il secondo led da sinistra
 if (valoresuono >= base + 31) // Se il suono supera il valore base + 30
 digitalWrite (10, HIGH); // accende il terzo led da sinistra
 if (valoresuono >= base + 46) // Se il suono supera il valore base + 45
 digitalWrite (9, HIGH); // accende il quarto led da sinistra
 if (valoresuono >= base + 61) // Se il suono supera il valore base + 60
 digitalWrite (8, HIGH); // accende il quinto led da sinistra
 if (valoresuono >= base + 76) // Se il suono supera il valore base + 75
 digitalWrite (7, HIGH); //accende il sesto led da sinistra
}
