line = input()
ranges = line.split(',')
answer = 0
for value in ranges:
    L, R = map(int, value.split('-'))
    print(L, R)
    # 10^5 iterations atmost
    x = 1
    while True:
        # 123123
        # R = 10 digits => x can have atmost 5 digits
        # x = 123
        # xx = 123123 - this value is in range [L, R] or <= R
        invalid_value = int(str(x) * 2)
        # print(f'x = {x} x*2 = {invalid_value}')
        # break
        if L <= invalid_value and invalid_value <= R:
            answer += invalid_value

        if invalid_value > R:
            break
        x += 1


print(f'Part 1 answer = {answer}')
