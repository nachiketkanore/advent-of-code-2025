parts = open('in', 'r').read().split('\n\n')
ranges = parts[0].split('\n')
cords = parts[1].split('\n')
print(cords)

answer = 0
for c in cords:
    for lr in ranges:
        l, r = map(int, lr.split('-'))
        # print(f'l = {l} r = {r}')
        if len(c) > 0 and int(c) in range(l, r + 1):
            answer += 1
            break
print(f'part one answer = {answer}')
