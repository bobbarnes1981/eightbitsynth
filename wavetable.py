import math

def mapNumber(x, in_min, in_max, out_min, out_max):
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

samples = 256
resolution = 256

print("square")
d = []
for i in range(0, samples):
    if i < (resolution / 2):
        d.append("0")
    else:
        d.append("1")
print(','.join(d))

print("saw")
d = []
for i in range(0, samples):
    d.append(str((int)(i / 2) * 2))
print(','.join(d))

print("triangle")
d = []
for i in range(0, (int)(samples / 2)):
    d.append(str(i * 2))
d.append("255")
for i in range((int)(samples / 2), 0, -1):
    d.append(str(d[i]))
print(','.join(d))


#step = (int)(314159 * 2 / samples) + 1

#data = []
#i = 0;
#for x in range(0, 314159 * 2, step):
#    y = x / 100000
#    z = mapNumber(math.sin(y), -1, 1, 0, 255)
#    s = str(round(z))
#    data.append(s)
#    i+=1

