#include <AltSoftSerial.h>              //including the library for communication channel for both the ends

AltSoftSerial recieving;                // creating instance for recieving the text
String incoming="";                     //declaring the string variable for message to be sent
void setup() {
  
Serial.begin(9600);                     //starting the serial communication
recieving.begin(800);                   //starting the recieving channel
}

void loop() 
{
  if(recieving.available()!=0)    //waiting till someting is recieved
  {           
  Serial.println("Recieving the message:");
  incoming = recieving.readString(); 
  Serial.print(incoming);               //printing the recieved message on serial monitor
  Serial.flush();
  }
}
