#define BUTTON 2

void setup() 
{
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);
}

void loop() 
{
  int value = digitalRead(BUTTON);
  Serial.println(value);
  delay(150);
}
