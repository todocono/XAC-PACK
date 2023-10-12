# Part of of https://github.com/todocono/XAC-PACK

# Clients: Children's Hospital Eastern Ontario
# Organization: Tetra Society

# Released under RG-M Pacifist License, which is basically a MIT modified license.
# (original MIT license is available on http://www.opensource.org/licenses/mit-license).
# The main amendment prevents the work under license or any other drived work from:
# war purposes, or purposes related to death penalty.

# Part of of https://github.com/todocono/XAC-PACK

# Coded by Rodolfo Cossovich
# Latest update: 2023-10-09

from smbus import SMBus
addr = 0x08
bus = SMBus(1)

def fnDOWN_down():
    print('DOWN pressed')
    bus.write_byte(addr, 0x03)
def fnDOWN_up():
    print('DOWN released')
    bus.write_byte(addr, 0x13)
def fnLEFT_down():
    print('LEFt pressed!')
    bus.write_byte(addr, 0x02)
def fnLEFT_up():
    print('LEFt released!')
    bus.write_byte(addr, 0x12)
def fnRIGHT_down():
    print('RIGHT pressed')
    bus.write_byte(addr, 0x04)
def fnRIGHT_up():
    print('RIGHT released')
    bus.write_byte(addr, 0x14)
def fnUP_down():
    print('UP pressed')
    bus.write_byte(addr, 0x01)
def fnUP_up():
    print('UP released')
    bus.write_byte(addr, 0x11)
def fnCLICK_down():
    print('CLICK pressed')
    bus.write_byte(addr, 0x05)
def fnCLICK_up():
    print('CLICK released')
    bus.write_byte(addr, 0x15)
def fnRCLICK_down():
    print('R-CLICK pressed')
    bus.write_byte(addr, 0x06)
def fnRCLICK_up():
    print('R-CLICK released')
    bus.write_byte(addr, 0x16)