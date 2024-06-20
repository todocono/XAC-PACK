// Part of of https://github.com/todocono/XAC-PACK

// Released under a Pacifist License, which is basically a MIT modified license.
// (original MIT license is available on http://www.opensource.org/licenses/mit-license).
// The main amendment prevents the work under license or any other drived work from:
// war purposes, or purposes related to death penalty.

// Coded by Rodolfo Cossovich
// Uses code from Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Latest update: 2024-06-18

//#include "HID-Project.h"
#include <Wire.h>
#include "Joystick.h"

Joystick_ Joystick;
//=================================================================================
// THOUGH IT DOES WORK FINE WHEN PLUGGED INTO THE COMPUTER AS A NORMAL JOYSTICK
#define XBOX_AC_STICK_BUTTON 10


void setup() {
  Wire.begin(8);                 // join I2C bus with address #8
  Wire.onReceive(receiveEvent);  // register event
  Serial.begin(9600);            // start serial for output
    // Sends a clean report to the host. This is important on any Arduino type.
  //Gamepad.begin();

  // initialize digital pins.
  pinMode(13, INPUT_PULLUP);
  digitalWrite(13, HIGH);  // turn the LED on (HIGH is the voltage level)
  pinMode(12, INPUT_PULLUP);
  digitalWrite(12, HIGH);
  pinMode(11, INPUT_PULLUP);
  digitalWrite(11, HIGH);
  pinMode(10, INPUT_PULLUP);
  digitalWrite(10, HIGH);
  pinMode(9, INPUT_PULLUP);
  digitalWrite(9, HIGH);
  pinMode(8, INPUT_PULLUP);
  digitalWrite(8, HIGH);

  Joystick.begin(false);  // false indicates that sendState method call required (so we do all changes at once).
  delay(1000);
  Joystick.setXAxis(512);
  Joystick.setYAxis(512);
  Joystick.sendState();
  //Serial.print("starting");
  delay(1000);
  //test2();
}

void loop() {
  delay(1);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  //if (howMany == 2) {
  byte valueArray[2];
  while (2 < Wire.available()) {  // loop through all but the last
    byte c = Wire.read();         // receive byte as a character
    //Serial.print(c);              // print the character
  }
  valueArray[1] = Wire.read();
  valueArray[0] = Wire.read();
  // while (1 < Wire.available()) {  // loop through all but the last
  //   byte c = Wire.read();         // receive byte as a character
  //   //Serial.print(c);              // print the character
  // }
  int x = (24 * (valueArray[0] - 128)) + 512;
  x = constrain(x, 0, 1023);
  int y = (24 * (valueArray[1] - 128)) + 512;
  y = constrain(y, 0, 1023);
  // Serial.print(x);
  // Serial.print("\t");
  // Serial.println(y);
  Joystick.setXAxis(x);
  Joystick.setYAxis(y);
  Joystick.sendState();
}

// int value = Wire.read();  // receive byte as an integer

// if (value != 0) {
//   // Serial.println(value, HEX);  // print the integer
//   int y = value & 0x0F;
//   int x = value & 0xF0;
//   //x = x << 4;
//   // Joystick.setXAxis(x * 4);
//   // Joystick.setYAxis(y * 4);
//   // Joystick.sendState();
//   x = x >> 4;
//   x = x * 64;
//   y = y * 64;
// Serial.print(x);
// Serial.print("\t");
// Serial.println(y);
// Joystick.setXAxis(x);
// Joystick.setYAxis(y);
// Joystick.sendState();
//}


// if (x == 0x01) {
//   pinMode(13, OUTPUT);
//   digitalWrite(13, LOW);
//   Joystick.setYAxis(0);
//   Joystick.sendState();
// }
// if (x == 0x11) {  //up released
//   pinMode(13, INPUT_PULLUP);
//   digitalWrite(13, HIGH);
//   Joystick.setYAxis(512);
//   Joystick.sendState();
// }

// if (x == 0x02) {  //left
//   pinMode(12, OUTPUT);
//   digitalWrite(12, LOW);
//   Joystick.setXAxis(0);
//   Joystick.sendState();
// }
// if (x == 0x12) {  //left released
//   pinMode(12, INPUT_PULLUP);
//   digitalWrite(12, HIGH);
//   Joystick.setXAxis(512);
//   Joystick.sendState();
// }

// if (x == 0x03) {  //down
//   pinMode(11, OUTPUT);
//   digitalWrite(11, LOW);
//   Joystick.setYAxis(1023);
//   Joystick.sendState();
// }
// if (x == 0x13) {  // down released
//   pinMode(11, INPUT_PULLUP);
//   digitalWrite(11, HIGH);
//   Joystick.setYAxis(512);
//   Joystick.sendState();
// }

// if (x == 0x04) {  //right
//   pinMode(10, OUTPUT);
//   digitalWrite(10, LOW);  // turn the LED off by making the voltage LOW
//   Joystick.setXAxis(1023);
//   Joystick.sendState();
// }
// if (x == 0x14) {  //right released
//   pinMode(10, INPUT_PULLUP);
//   digitalWrite(10, HIGH);
//   Joystick.setXAxis(512);
//   Joystick.sendState();
// }

// if (x == 0x05) {
//   pinMode(9, OUTPUT);
//   digitalWrite(9, LOW);  // turn the LED off by making the voltage LOW
// }
// if (x == 0x15) {
//   pinMode(9, INPUT_PULLUP);
//   digitalWrite(9, HIGH);  // turn the LED on (HIGH is the voltage level)
// }

// if (x == 0x06) {
//   pinMode(8, OUTPUT);
//   digitalWrite(8, LOW);  // turn the LED off by making the voltage LOW
// }
// if (x == 0x16) {
//   pinMode(8, INPUT_PULLUP);
//   digitalWrite(8, HIGH);  // turn the LED on (HIGH is the voltage level)
// }
//}


void test2() {
  Joystick.setXAxis(0);
  Joystick.setYAxis(512);
  Joystick.sendState();
  Serial.print("left");
  delay(1000);
  Joystick.setXAxis(512);
  Joystick.setYAxis(512);
  Joystick.sendState();
  Serial.print("stop");
  delay(1000);
  Joystick.setXAxis(1023);
  Joystick.setYAxis(512);
  Joystick.sendState();
  Serial.print("right");
  delay(1000);
  Joystick.setXAxis(512);
  Joystick.setYAxis(512);
  Joystick.sendState();
  delay(1000);
  Joystick.setXAxis(512);
  Joystick.setYAxis(0);
  Joystick.sendState();
  Serial.print("down");
  delay(1000);
  Joystick.setXAxis(512);
  Joystick.setYAxis(512);
  Joystick.sendState();
  delay(1000);
  Joystick.setXAxis(512);
  Joystick.setYAxis(1023);
  Joystick.sendState();
  Serial.print("up");
  delay(1000);
  Joystick.setXAxis(512);
  Joystick.setYAxis(512);
  Joystick.sendState();
  Serial.print("stop");
  delay(1000);
}

void test() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);            // wait for a second
  pinMode(13, INPUT_PULLUP);
  digitalWrite(13, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);             // wait for a second
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);            // wait for a second
  pinMode(12, INPUT_PULLUP);
  digitalWrite(12, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);            // wait for a second
  pinMode(11, INPUT_PULLUP);
  digitalWrite(11, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);            // wait for a second
  pinMode(10, INPUT_PULLUP);
  digitalWrite(10, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);           // wait for a second
  pinMode(9, INPUT_PULLUP);
  digitalWrite(9, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);           // wait for a second
  pinMode(8, INPUT_PULLUP);
  digitalWrite(8, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);
}
