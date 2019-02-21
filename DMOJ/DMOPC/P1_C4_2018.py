k = int(input())
mx = float(input())
mean=0

for i in range(k):
    mean+=sum([float(i) for i in input().split()[1:]])+mx
    
print(mean/k)