// Part of of https://github.com/todocono/XAC-PACK

// Released under RG-M Pacifist License, which is basically a MIT modified license.
// (original MIT license is available on http://www.opensource.org/licenses/mit-license).
// The main amendment prevents the work under license or any other drived work from:
// war purposes, or purposes related to death penalty.

// Coded by Rodolfo Cossovich
// Uses code from Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Latest update: 2023-10-12

//#include "HID-Project.h"
#include <Wire.h>

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
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) {  // loop through all but the last
    char c = Wire.read();         // receive byte as a character
    Serial.print(c);              // print the character
  }
  int x = Wire.read();  // receive byte as an integer
  Serial.println(x);    // print the integer

  if (x == 0x01) {
    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);  // turn the LED off by making the voltage LOW
  }
  if (x == 0x11) {
    pinMode(13, INPUT_PULLUP);
    digitalWrite(13, HIGH);  // turn the LED on (HIGH is the voltage level)
  }

  if (x == 0x02) {
    pinMode(12, OUTPUT);
    digitalWrite(12, LOW);  // turn the LED off by making the voltage LOW
  }
  if (x == 0x12) {
    pinMode(12, INPUT_PULLUP);
    digitalWrite(12, HIGH);  // turn the LED on (HIGH is the voltage level)
  }

  if (x == 0x03) {
    pinMode(11, OUTPUT);
    digitalWrite(11, LOW);  // turn the LED off by making the voltage LOW
  }
  if (x == 0x13) {
    pinMode(11, INPUT_PULLUP);
    digitalWrite(11, HIGH);  // turn the LED on (HIGH is the voltage level)
  }

  if (x == 0x04) {
    pinMode(10, OUTPUT);
    digitalWrite(10, LOW);  // turn the LED off by making the voltage LOW
  }
  if (x == 0x14) {
    pinMode(10, INPUT_PULLUP);
    digitalWrite(10, HIGH);  // turn the LED on (HIGH is the voltage level)
  }

  if (x == 0x05) {
    pinMode(9, OUTPUT);
    digitalWrite(9, LOW);  // turn the LED off by making the voltage LOW
  }
  if (x == 0x15) {
    pinMode(9, INPUT_PULLUP);
    digitalWrite(9, HIGH);  // turn the LED on (HIGH is the voltage level)
  }

  if (x == 0x06) {
    pinMode(8, OUTPUT);
    digitalWrite(8, LOW);  // turn the LED off by making the voltage LOW
  }
  if (x == 0x16) {
    pinMode(8, INPUT_PULLUP);
    digitalWrite(8, HIGH);  // turn the LED on (HIGH is the voltage level)
  }
}


void test(){
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
