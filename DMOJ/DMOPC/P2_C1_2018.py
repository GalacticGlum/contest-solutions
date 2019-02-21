## not working!

n,k = [int(i) for i in input().split()]
permutation = [int(i) for i in input().split()]

sorted_permutation = sorted(permutation)
index_map = {sorted_permutation[i]:i for i in range(n)}

result = True
for i in range(n-1,-1,-1):
    if abs(i - index_map[permutation[i]]) != k:
        result = False
        break

if result:
    print('YES')
else:
    print('NO')