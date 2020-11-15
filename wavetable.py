import math

def mapNumber(x, in_min, in_max, out_min, out_max):
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

samples = 256
resolution = 256

# sin
step = (int)(314159 * 2 / samples) + 1
d = []
for x in range(0, 314159 * 2, step):
    y = x / 100000
    z = mapNumber(math.sin(y), -1, 1, 0, 255)
    s = str(round(z))
    d.append(s)
print(f'byte wave_sin[{len(d)}] = {{')
print(','.join(d))
print("}")

# tan
step = (int)(314159 * 2 / samples) + 1
d = []
for x in range(0, 314159 * 2, step):
    y = x / 100000
    z = mapNumber(math.tan(y), -6, 6, 0, 255)
    s = str(round(z % 256))
    d.append(s)
print(f'byte wave_tan[{len(d)}] = {{')
print(','.join(d))
print("}")

# squ
d = []
for i in range(0, samples):
    if i < (resolution / 2):
        d.append("0")
    else:
        d.append("255")
print(f'byte wave_squ[{len(d)}] = {{')
print(','.join(d))
print("}")

# tri
d = []
val = 0
for i in range(0, (int)(samples / 2)):
    val += 2
    d.append(str(val))
val += 2
for i in range((int)(samples / 2), samples):
    val -= 2
    d.append(str(val))
print(f'byte wave_tri[{len(d)}] = {{')
print(','.join(d))
print("}")

# saw
d = []
for i in range(0, samples):
    d.append(str(i))
print(f'byte wave_saw[{len(d)}] = {{')
print(','.join(d))
print("}")

# rnd
import random
d = []
for i in range(0, samples):
    d.append(str(random.randint(0, 256)))
print(f'byte wave_rnd[{len(d)}] = {{')
print(','.join(d))
print("}")
