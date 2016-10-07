/*
* Come fare uso della funzione millis() per 
* tenere traccia dello scorrere del tempo e temporizzare
* il comportamento del circuito.
* millis() ritorna il numero di millisecondi (long) 
* a partire dall'ultima volta che il programma è stato
* lanciato. Si resetta a 0 dopo 50 giorni.
*/


unsigned long int start, actual;
unsigned int T;
boolean led_status;

#define LED 7

void setup() 
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  T = 1000;
  led_status = false;
  digitalWrite(LED, led_status);
  start = millis();
  actual = start;

}

void loop() 
{
  actual = millis();
  if((actual-start)>=T)
  {
    led_status = !led_status;
    digitalWrite(LED, led_status);
    start = actual;
    Serial.println("cambio stato");
    }
  /* ... */
  Serial.println("***");
}
