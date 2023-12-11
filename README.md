# XAC-PACK
Pack for Xbox Adaptive Controller (XAC), to allow bluetooth wheelchair controllers to play with XBOX. 

This project was developed for the Children's Hospital Eastern Ontario (CHEO), by volunteers at TETRA SOCIETY (https://tetrasociety.org/).


![Playing](https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExbjRmMGhqbmMybnAwbHF4aThmczUzYXN3ZHcwa2wzanZsenhpdDF3aCZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/BelkuHviGIwJeQ5Tob/giphy-downsized.gif)


![Alt Text](https://media.giphy.com/media/vFKqnCdLPNOKc/giphy.gif)

## Set Up:
If the wheelchair BLE controller is already added, the setup would only need:
- Plug the aux cable outputs from Arduino Leonardo in the XAC-Pack to the XAC.
  
![Aux cable](AB.jpg?raw=true "Aux cables")
- Plug in the USB-C power of the Raspberry Pi of the XAC-Pack.
- Turn on the power (switch on the USB-C cable)

![USB cable](USB.jpg?raw=true "USB")
- Wait until the full booting-up process is done. You should see a Raspberry Pi splash screen, and then a light yellow screen showing XAC-PACK

![Booting](boot.jpg?raw=true "Splash Screen")
![Fnctioning Screen](screen.jpg?raw=true "Functioning Screen")

## Usage:
- As the BLE pairs automatically, the movements of the wheelchair controller should translate into XAC movements.
- Moving UP, LEFT, RIGHT, DOWN are all mapped (with a sensitivity threshold) to the 4 digital inputs of the XAC.
- Pressing A or B buttons are linked to left-click and right-click respectively. This, in the Permobil chair are programmed gestures to rapid-left and rapid-right gestures.

## Testing:
With the XAC connected to a PC, run the XBOX accessories app. The test lab mode shows what the XAC is sensing.

## Adding New Devices:
By default, BLE should be pair/trusted/connected automatically. But if it's a new device, there are two ways to add them.

You will need a keyboard connected to any of the USB of the Raspberry Pi. After connecting the keyboard, you should press the ESC key. The mouse is optional because the device has a touchscreen, but recommended.

![Keyboard & Mouse](image.jpg?raw=true "Keyboard & Mouse")

Below are general detail instructions; in-detail instructions are at https://pimylifeup.com/raspberry-pi-bluetooth/#:~:text=To%20load%20the%20Bluetooth%20GUI,Manager%20%E2%80%9D%20(2.).


#Using Graphical User Interface (GUI):
- Click on the Bluetooth symbol. Click on the Add a new device. Pair the device with it.
- Click again and select Connect from the drop-down menu.
If the above steps are not working, you can try to go to Preferences/Bluetooth Manager

#Using Command Line Interpreter (CLI):
- From the terminal, enter 'bluetoothctl' and within it, type 'agent on', 'discoverable on', and 'scan on'
- You will have a list of MAC addresses to pair with. Sometimes (like Permobil), the addresses do not show a name.
- You need to find the MAC corresponding to the device (or guess) and type 'pair nn:nn:nn:nn', 'connect n:nn:nn:nn', 'trust n:nn:nn:nn'






## Hardware req:
Raspberry Pi 3B+ (probably any other with Bluetooth capabilities could also work)
Arduino Leonardo (Nano 33 IoT (or RP2040 with HID media USB capabilities could also work)

![Booting](guts.jpg?raw=true "Inner cabling")

## Software:
Raspbian OS 
buttons.py ---> handles the communication from the Raspberry to Arduino, sending commands over i2c
init.py ---> handles the GUI and captures the mouse movement.
XAC-PACK.ino ---> handles the i2c communication from Rpi, capturing the commands, and translating them into USB commands to the Xbox Adaptive controllers. The way to handle the USB-HID is heavily inspired by the FreedomWing board made by the AT makers (http://atmakers.org/freedomwing-build/)

## Installation:
Flash XAC-PACK.ino into the Arduino 33 IoT
Connect 3 cables for SCL, SDA and GND from Arduino to Rpi
Connect USB from Arduino to Xbox Adaptive controller 
Configure Rpi to run on Raspbberry Pi OS (https://www.raspberrypi.com/software/)
Configure Rpi to enable Bluetooth, and i2c
Make sure Rpi and the wheelchair controller can see each other (use bluetoothctl, pair, trust, connect if the GUI fails)
Configure Rpi to run init.py on startup (similar to https://www.instructables.com/Raspberry-Pi-Launch-Python-script-on-startup/)


## Future work:
- have a configuration page to connect to different BT devices
- Fully functional simulation. A mockup was created here: https://replit.com/@todocono/XAC-PACK#main.py

## Credits
- Omar Masaud (2020 -2021): name, architecture, and general solution (v1.0)
- Arash Abarghooei (2022-2023): research & tests (v1.1)
- Rodolfo Cossovich (2023): implementation (v1.2 and v1.3)
- Alison Baker from CHEO
- Tetra Society - Ottawa Chapter


