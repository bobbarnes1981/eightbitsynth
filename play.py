import serial
import time

s = serial.Serial("COM5", 115200)
time.sleep(2)

def setProgram(program_number):
    count = s.write([0xC0, program_number])
    #print("bytes: " + str(count))
    #print(s.readline())

def playNote(note, length):
    count = s.write([0x90, note, 0x00])
    #print("bytes: " + str(count))
    #print(s.readline())
    time.sleep(length);
    count = s.write([0x80, note, 0x00])
    #print("bytes: " + str(count))
    #print(s.readline())

def playNotes(length, pause):
    playNote(48, length)
    time.sleep(pause)
    playNote(50, length)
    time.sleep(pause)
    playNote(52, length)
    time.sleep(pause)
    playNote(53, length)
    time.sleep(pause)
    playNote(55, length)
    time.sleep(pause)
    playNote(57, length)
    time.sleep(pause)
    playNote(59, length)
    time.sleep(pause)
    playNote(60, length)
    time.sleep(pause)

for program in range(0, 6):
    setProgram(program)
    playNotes(0.25, 0.0)
    time.sleep(0.25)

time.sleep(1)
