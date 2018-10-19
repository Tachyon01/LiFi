#include <SoftwareSerial.h>             

SoftwareSerial GSerial(11,12);               //Created instance for LiFi
char rec=0;

void setup()
{
  Serial.begin(9600);                       //Baud rate for Serial port      
  GSerial.begin(400);                       //Baud rate for LiFi
}

void loop()
{
  if(GSerial.available() != 0)
  {    
    rec = GSerial.read();
    Serial.print(rec);
  }
}
