lines = open('in', 'r').read().split('\n')

print(lines[-2])
ops = [x for x in lines[-2].split(' ') if len(x) > 0]
print(ops)

nums = []
for i in range(len(lines)-2):
    print(lines[i])
    nums.append([x for x in lines[i].split(' ') if len(x) > 0])

answer = 0
nums = [list(row) for row in zip(*nums)]
for comp in zip(nums, ops):
    vals = map(int, comp[0])
    symbol = comp[1]
    if symbol == '+':
        answer += sum(vals)
    else:
        import math
        answer += math.prod(vals)

print(f'part one answer = {answer}')
