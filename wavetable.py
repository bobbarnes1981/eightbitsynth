import math

def mapNumber(x, in_min, in_max, out_min, out_max):
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

pi = 3.14159

samples = 256
step = (int)(314159 * 2 / samples) + 1

data = []
i = 0;
for x in range(0, 314159 * 2, step):
    y = x / 100000
    z = mapNumber(math.sin(y), -1, 1, 0, 255)
    s = str(round(z))
    data.append(s)
    i+=1

print(','.join(data))
