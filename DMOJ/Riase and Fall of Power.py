from math import gcd, log10, floor, ceil, fmod

def get_last_k(base, power, mod):
    result = 1
    while power > 0:
        if power % 2 == 1:
            result = (result * base) % mod
        
        base = (base * base) % mod
        power //= 2
    
    return int(result % mod)

def run(n, k):   
    k_power_10 = round(10**k)
    first = int(pow(10, fmod(log10(float(n)) * n, 1)) * (k_power_10 / 10))
    last = get_last_k(n, n, k_power_10)

    print(first, str(last).zfill(k)) 

test_cases = int(input())
for i in range(test_cases):
    n, k = [int(part) for part in input().split()]
    run(n,k)
  

# for i in range(50, 10**3):
#     print(f'i={i} | ', end='')
#     run(i, 2)