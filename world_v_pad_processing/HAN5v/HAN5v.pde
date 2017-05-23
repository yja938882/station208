import processing.net.*;

import netP5.*;
import oscP5.*;


OscP5 oscP5;
NetAddress myRemoteLocation;
/**
 * Simple Read
 * 
 * Read data from the serial port and change the color of a rectangle
 * when a switch connected to a Wiring or Arduino board is pressed and released.
 * This example works with the Wiring / Arduino program that follows below.
 */


import processing.serial.*;

Serial myPort1;  // Create object from Serial class
Serial myPort2;
int val1;      // Data received from the serial port
int val2;
int pv1;
int pv2;
void setup() 
{
  size(200, 200);
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName1 = Serial.list()[2];
  String portName2 = Serial.list()[3];
  
  printArray(Serial.list());
  myPort1 = new Serial(this, portName1, 9600);
  myPort2 = new Serial(this, portName2, 9600);
    oscP5 = new OscP5(this,4690);
     myRemoteLocation = new NetAddress("127.0.0.1",5001);
}

void draw()
{
  

  if ( myPort1.available() > 0){
    val1 = myPort1.read();
  }
    if( myPort2.available()>0) {
    val2 = myPort2.read();
  }
     fill(0);    
  
  background(255);             // Set background to white
 // if (val != pv && val==1) {
    if(val1>=100|| val2>=100) {
  OscMessage myMessage = new OscMessage("/test");
  
  myMessage.add(1.1); /* add an int to the osc message */

  oscP5.send(myMessage, myRemoteLocation); 
           fill(204);        // set fill to black
  } 

  rect(50, 50, 100, 100);

  
  
  
   text(val1, 50, 50);
   text(val2,100,50);
}



/*

// Wiring / Arduino Code
// Code for sensing a switch status and writing the value to the serial port.

int switchPin = 4;                       // Switch connected to pin 4

void setup() {
  pinMode(switchPin, INPUT);             // Set pin 0 as an input
  Serial.begin(9600);                    // Start serial communication at 9600 bps
}

void loop() {
  if (digitalRead(switchPin) == HIGH) {  // If switch is ON,
    Serial.write(1);               // send 1 to Processing
  } else {                               // If the switch is not ON,
    Serial.write(0);               // send 0 to Processing
  }
  delay(100);                            // Wait 100 milliseconds
}

*/