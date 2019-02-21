n=int(input())
a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]

idx=0
sum_a=0
sum_b=0
for i in range(n):
    sum_a+=a[i]
    sum_b+=b[i]
    if sum_a==sum_b:
        idx=i+1
    
print(idx)