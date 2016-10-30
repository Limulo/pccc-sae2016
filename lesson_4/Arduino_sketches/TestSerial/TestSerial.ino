// ---------------------------------------------- //
#define LED 13
#define BUTTON 7
#define POT A0

/* addresses */
#define POT_ADDR 0
#define BUTT_ADDR 1

boolean bSendSerial = false;
boolean bLedStatus = false;
byte lastAddress = 0;

// SETUP ///////////////////////////////////////////////////////////////////////////////
void setup() 
{
  Serial.begin( 9600, SERIAL_8N1 );
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  digitalWrite(LED, bLedStatus);
}

// LOOP ////////////////////////////////////////////////////////////////////////////////
void loop() 
{  
  int value = -1;
  value = analogRead(POT);
  if(bSendSerial)
  {
    Serial.write(128 + POT_ADDR);
    Serial.write(value>>3); //divisione per 8
  }
  value = digitalRead(BUTTON);
  if(bSendSerial)
  {
    Serial.write(128 + BUTT_ADDR);
    Serial.write(value);
  }
  digitalWrite(LED, bLedStatus);
  delay(100);
}


// SERIAL EVENT ////////////////////////////////////////////////////////////////////////
void serialEvent()
{
  byte b = Serial.read();
  
  if(b>127)
  {
	// the byte is an address
    lastAddress = b;
  }
  else
  {
    switch(lastAddress)
    {
	  // the byte is a value
      case 255:
        if (b == 1)
          bSendSerial = true;
        else
          bSendSerial = false;
        break;
      case 240:
        if (b == 1)
          bLedStatus = true;
        else
          bLedStatus = false;
        break; 
      default:
        // do nothing
        break;
   }
 }   
}
