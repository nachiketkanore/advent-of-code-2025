import math
lines = list(line for line in open(
    'in', 'r').read().split('\n') if len(line) > 0)

cords = []
for line in lines:
    x, y = map(int, line.split(','))
    cords.append((x, y))


ans = 0
for i in range(len(cords)):
    for j in range(len(cords)):
        x1, y1 = cords[i]
        x2, y2 = cords[j]
        best = (abs(x1 - x2) + 1) * (abs(y1 - y2) + 1)
        if ans < best:
            ans = best

print(ans)
