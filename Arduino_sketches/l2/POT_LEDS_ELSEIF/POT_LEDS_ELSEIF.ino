int NUM_LEDS = 3;

void setup()
{
  for(int i=0; i<NUM_LEDS; i++)
    pinMode(8+i, OUTPUT);
}

void loop()
{
  // spegnimento LEDs
  for(int i=0; i<NUM_LEDS; i++)
    digitalWrite(8+i, LOW);

  // lettura POT
  int value = map( analogRead( A0 ), 0, 1023, 0, NUM_LEDS);

  // accensione LED  
  if( value < 1 )
    digitalWrite( 8, HIGH );
  else if( value < 2 )
    digitalWrite( 9, HIGH );
  else
    digitalWrite( 10, HIGH );
    
  delay( 100 );
}
