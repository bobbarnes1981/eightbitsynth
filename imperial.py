import serial
import time

s = serial.Serial("COM3", 115200)
time.sleep(2)

bar = 2

def setProgram(program_number):
    count = s.write([0xC0, program_number])

def playNote(note, length):
    count = s.write([0x90, note, 0x00])
    time.sleep(length);
    count = s.write([0x80, note, 0x00])

def playQuarter(note):
    playNote(note, bar/16*3)
    time.sleep(bar/16*1)

def playEight(note):
    time.sleep(bar/64*1)
    playNote(note, bar/64*6)
    time.sleep(bar/64*1)

def playHalf(note):
    playNote(note, bar/4)
    time.sleep(bar/4)

setProgram(0x00)

playQuarter(57)
playQuarter(57)
playQuarter(57)
playEight(53)
playEight(60)

playQuarter(57)
playEight(53)
playEight(60)
playHalf(57)

playQuarter(64)
playQuarter(64)
playQuarter(64)
playEight(65)
playEight(60)

playQuarter(56)
playEight(53)
playEight(60)
playHalf(57)

time.sleep(1)
