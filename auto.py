import serial
import time

s = serial.Serial("COM5", 115200)
time.sleep(2)

while True:
    for w in range(0, 6):
        for n in range(0, 8):
            time.sleep(0.5)
            s.write(b'n')
        s.write(b'w')
    print('.')