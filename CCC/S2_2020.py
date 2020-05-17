import sys
input=sys.stdin.readline
m=int(input())
n=int(input())
grid=[[int(v) for v in input().split()] for _ in range(m)]

sieve=[True]*(1000001)
sieve[0]=sieve[1]=False
for i in range(2,int(1000001**0.5)):
    if not sieve[i]: continue
    for j in range(i**2,1000001,i):
        sieve[j]=False
        
factors={}
for i in range(1,m+1):
    for j in range(1,n+1):
        x=i*j
        if x not in factors:
            factors[x]=set()
        factors[x].add((i,j))
        factors[x].add((j,i))
        
# factors={}
# for i in range(1,1000001):
#     factors[i]=set()
#     for j in range(1,int(i**0.5)+1):
#         if i % j!=0:continue
#         d=i//j
#         factors[i].add((d,j))
#         factors[i].add((j,d))
# print(factors)
q=[(0,0)]
result='no'
visited=set()
while len(q)>0:
    current_pos=q.pop(0)
    if current_pos in visited: continue
    visited.add(current_pos)
    if current_pos==(m-1,n-1):
        result='yes'
        break
    x=grid[current_pos[0]][current_pos[1]]
    if sieve[x]:
        if x <= m:
            q.append((x-1,0))
        if x <= n:
            q.append((0,x-1))
    elif x in factors:
        for factor in factors[x]:
            i,d=factor[0],factor[1]
            if i <= m and d <= n:
                q.append((i-1,d-1))
            if i <= n and d <= m:
                q.append((d-1,i-1))
                
        # for i in range(1,int(x**0.5)+1):
        #     if x%i != 0: continue
        #     d=x//i
        #     if i <= m and d <= n:
        #         q.append((i-1,d-1))
        #     if i <= n and d <= m:
        #         q.append((d-1,i-1))
print(result)