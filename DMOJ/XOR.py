def find(n):
    mod = n % 4
    if mod == 0: return n
    if mod == 1: return 1
    if mod == 2: return n + 1
    if mod == 3: return 0

t = int(input())
for i in range(t):
    s, f = map(int, input().split())

    print(find(f) ^ find(s-1))