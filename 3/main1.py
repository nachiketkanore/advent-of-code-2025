lines = open('in', 'r').read().split('\n')

answer = 0
for line in lines:
    if len(line) > 0:
        # print(f'line is {line}')
        N = len(line)
        best = 0
        for i in range(N):
            for j in range(N):
                if i < j:
                    best = max(best, int(line[i] + line[j]))
        answer += best

print(f'Part one answer = {answer}')
