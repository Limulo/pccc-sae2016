#define POT A0

void setup()
{
  Serial.begin( 9600 );
}

void loop()
{
  int value = analogRead( POT );
  float voltage = value * (5.0 / 1024.0);

  Serial.print(“value: “);
  Serial.print( value );
  Serial.print(“\t”);
  Serial.print(“volts: “);
  Serial.print(voltage);
  Serial.println();

  delay(250);
}
