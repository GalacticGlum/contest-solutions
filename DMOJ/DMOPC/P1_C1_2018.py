n = int(input())
numbers = [int(i) for i in input().split()]

def is_sorted(collection, key=lambda x: x):
    for i, element in enumerate(collection[1:]):
        if key(element) < key(collection[i]):
            return False

    return True

found_wildcard = False
first_wildcard = -1
replacement = 0
for i in range(n):
    if numbers[i] == 0:
        if first_wildcard == -1:
            first_wildcard = i

        found_wildcard = True
    elif found_wildcard:
        replacement = numbers[i]
        break

    if found_wildcard and i == n - 1:
        if first_wildcard != n - 1:
            replacement = numbers[first_wildcard + 1]
        else:
            replacement = numbers[first_wildcard - 1]

if found_wildcard:
    numbers = [replacement if x == 0 else x for x in numbers]

if is_sorted(numbers):
    print('YES')
else:
    print('NO')