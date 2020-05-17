import sys
input=sys.stdin.readline
n=int(input())
measurements=[list(map(float,input().split())) for _ in range(n)]
# get maximum velocity
max_velocity = float('-inf')
# for i in range(n):
#     for j in range(i,n):
#         if i==j: continue
#         velocity=(measurements[i][1]-measurements[j][1])/(measurements[i][0]-measurements[j][0])
#         max_velocity=max(max_velocity,abs(velocity))
measurements=sorted(measurements,key=lambda x:x[0],reverse=True)
for i in range(n-1):
    j=i+1
    velocity=(measurements[i][1]-measurements[j][1])/(measurements[i][0]-measurements[j][0])
    max_velocity=max(max_velocity,abs(velocity))
        
print(max_velocity)