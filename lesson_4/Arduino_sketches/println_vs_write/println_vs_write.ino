boolean bSendSerial = false;
void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  if(bSendSerial)
  {
    Serial.println(1, BIN);
   // Serial.write(97);
  }
    delay(1000);
}

void serialEvent()
{
  byte start=Serial.read();
  if(start == '1')
    bSendSerial=true;
  else if (start=='0')
    bSendSerial=false;
  }
