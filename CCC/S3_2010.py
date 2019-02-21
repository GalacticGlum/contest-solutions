h = int(input())
houses = sorted([int(input()) for _ in range(h)])
k = int(input())

MAX = 1000000

def find(distance):
    result = h
    ptr = 0

    while ptr < h and houses[ptr] <= houses[0] + distance:
        current_length = 1
        last = houses[ptr]
        j = ptr + 1
        while j < h and houses[j] < houses[ptr] - distance + MAX:
            if houses[j] > last:
                last = houses[j] + distance
                current_length += 1

            j += 1
        
        result = min(current_length, result)
        ptr += 1

    return result

lo = -1
hi = MAX
while lo < hi - 1:
    mid = (lo + hi) // 2
    if find(mid * 2) > k:
        lo = mid
    else:
        hi = mid

print(hi)