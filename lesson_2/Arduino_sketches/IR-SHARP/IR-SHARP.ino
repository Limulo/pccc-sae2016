/*
* Sketch di prova per la misurazione della distanza tramite 
* sensori IR Sharp
* v1 - GP2Y0A02YK0F
* v2 - GP2Y0A21YK0F
*/

#define IR A0

int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin( 9600 );
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead( IR );
  
  //int range =  (15837 / (sensorValue + 18)) - 11; // v1
  int range =  (6787 / (sensorValue - 3)) - 4; // v2
  
  Serial.print(range);
  Serial. println(" cm;");
  
  delay( 100 );
}
