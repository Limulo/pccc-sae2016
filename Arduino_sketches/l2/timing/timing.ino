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
