int LED = 3;
int POT = A0;

void setup()
{
  Serial.begin( 9600 );
}

void loop()
{
  int value = analogRead( POT );
  int light = value / 4;
  Serial.print( "value: ");
  Serial.print( value );
  Serial.print( ";\tlight: " );
  Serial.println( light );
  
  analogWrite(LED, light);
  
  delay( 100 );
}
