line = input()
ranges = line.split(',')
answer = 0
vals = set()
for value in ranges:
    L, R = map(int, value.split('-'))
    print(L, R)
    x = 1
    while True:

        for appends in range(2, 15):
            invalid_value = int(str(x) * appends)
            if L <= invalid_value and invalid_value <= R:
                # answer += invalid_value
                vals.add(invalid_value)
                print(f'taken = {invalid_value}')

            if invalid_value > R:
                break

        invalid_value = int(str(x) * 2)
        if invalid_value > R:
            break
        x += 1


answer = sum(vals)
print(f'Part 2 answer = {answer}')
