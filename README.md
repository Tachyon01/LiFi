# LiFi
Project for Prototype

We will be trying to demonstrate communication using LiFi technology.

STAGE-1
We are able to transfer character by character in a one sided communication

STAGE-2
We are able to do chatting using Serial Monitor, as we now have 2 sided communication

We can now transfer txt files using:
          type 'filename' > COMx

Image files can be transferred by encoding image to base64 and transfer the file and then decode it.
File size is limited to around 1.3KB due to arduino memory size

For transferring data through Python2.7:

import serial

ser = serial.Serial('COMport',9600)

ser.write('Your text here')
