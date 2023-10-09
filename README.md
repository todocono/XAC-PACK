# XAC-PACK
Pack for Xbox Adaptive Controller, to allow bluetooth wheelchair controllers to play with XBOX. 

This project was developed for the Children's Hospital Eastern Ontario, under the frame of TETRA SOCIETY (https://tetrasociety.org/).

Credits for ideation and first trials go to:
- Omar Masaud (2020 -2021): name, architecture, and general solution
- Arash Abarghooei (2022-2023): research & tests
- Rodolfo Cossovich (2023): implementation

## Hardware req:

Raspberry Pi 3B+ (probably any other with Bluetooth capabilities could also work)
Arduino Nano 33 IoT (Leonardo or RP2040 with HID media USB capabilities could also work)

## Software:
Raspbian OS for 
XAC-PACK.py ---> handles Bluetooth 
XAC-PACK.ino ---> handles the i2c communication from Rpi, capturing the commands, and translating them into USB commands to the Xbox Adaptive controllers. The way to handle the USB-HID is heavily inspired by the FreedomWing board made by the AT makers (http://atmakers.org/freedomwing-build/)

## Installation:
Flash XAC-PACK.ino into the Arduino 33 IoT
Connect 3 cables for SCL, SDA and GND from Arduino to Rpi
Connect USB from Arduino to Xbox Adaptive controller 
Configure Rpi to run on Raspbberry Pi OS (https://www.raspberrypi.com/software/)
Make sure Rpi and the wheelchair controller can see each other (use bluetoothctl, pair, trust, connect if the GUI fails)
Configure Rpi to run XAC-PACK.py to run on startup (similar to https://www.instructables.com/Raspberry-Pi-Launch-Python-script-on-startup/)



## Future work:
- have a configuration page to connect to different BT devices
- capture gestures to configure the different movements
- embed the Rpi, Arduino and a 3.5" touch screen in a case
