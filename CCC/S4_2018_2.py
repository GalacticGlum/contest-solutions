import math

n = int(input())
cache = {}

def find(w):
    if w == 1: return 1

    if w in cache:
        return cache[w]

    result = math.ceil(w / 2)
    for i in range(math.floor(w / 2), 1, -1):
        nw = math.floor(w / i)
        result += find(nw)

    cache[w] = result
    return result

print(find(n))