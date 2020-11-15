import serial
import time

s = serial.Serial("COM3", 115200)
time.sleep(2)

def setProgram(program_number):
    print("bytes: " + str(s.write([0xC0, program_number])))
    print(s.readline())

def playNote(note, length):
    print("bytes: " + str(s.write([0x90, note, 0x00]))) # key 48
    print(s.readline())
    time.sleep(length);
    print("bytes: " + str(s.write([0x80, note, 0x00]))) # key 48
    print(s.readline())

def playNotes():
    playNote(48, 0.5)
    time.sleep(0.25)
    playNote(50, 0.5)
    time.sleep(0.25)
    playNote(52, 0.5)
    time.sleep(0.25)
    playNote(53, 0.5)
    time.sleep(0.25)
    playNote(55, 0.5)
    time.sleep(0.25)
    playNote(57, 0.5)
    time.sleep(0.25)
    playNote(59, 0.5)
    time.sleep(0.25)
    playNote(60, 0.5)
    time.sleep(0.25)

setProgram(0x00)
playNotes()
time.sleep(1)

setProgram(0x01)
playNotes()
time.sleep(1)

setProgram(0x03)
playNotes()
time.sleep(1)

time.sleep(1)