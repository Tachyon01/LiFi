#include <AltSoftSerial.h>              //including the library for communication channel for both the ends

String to_send,rec;
char msg;
int sendmsg;

//AltSoftSerial recieving;                // creating instance for recieving the text
AltSoftSerial sending;                  // creating instance for sending the text

void setup() {
  
Serial.begin(9600);                     //starting the serial communication
sending.begin(800);                     //starting the transmission channel
}

void loop() 
{  
  if(Serial.available()!=0)    //waiting till someting is recieved
  {          
  Serial.println("Recieving the message:");
  to_send = Serial.read();
  flag=1;                 //We have to send something
  file++;                 //File Number
  Serial.flush();
  }
 
  if(flag!=0)     //Need to transmit
  {
  sendmsg = to_send.toInt();  
  msg = (char)sendmsg;
  sending.print(msg);
  flag--;
  Serial.flush();
  }
}
