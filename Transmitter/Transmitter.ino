#include <Keypad.h>
#include <SoftwareSerial.h>

const byte ROWS = 4;
const byte COLS = 4;
char customKey;

char hexaKeys[ROWS][COLS] = {       //Keypad definiton
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {11,12,A0,A1}; 
byte colPins[COLS] = {A2,A3,A4,A5}; 
SoftwareSerial GSerial(2,3);                            //LiFi serial instance
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
char keycount=0;
char code[5];

void setup() 
{
  delay(1000);
  Serial.begin(9600);         //Set Baud rate
  Serial.println("Keyboard Test:");
  GSerial.begin(400);         //Set Transfer rate for LiFi
  GSerial.print('&');         
}

void loop() 
{    
  customKey = customKeypad.getKey();
  if(customKey && (customKey !='='))
  {      
      Serial.print(customKey);
      GSerial.print(customKey);
  }  
}
