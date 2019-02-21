n, m = [int(i) for i in input().split()]
values = [int(i) for i in input().split()]

start_ptr, end_ptr, result, = 0, 1, 0

current = sum(values[start_ptr:end_ptr])
while end_ptr <= n:
    if current >= m:
        diff = end_ptr - start_ptr
        if result == 0:
            result = diff
        else:
            result = min(result, diff)
        
        current -= values[start_ptr]
        start_ptr += 1
    else:
        end_ptr += 1
        if end_ptr <= n:
            current += values[end_ptr - 1]
            
print('-1' if result == 0 else result)
