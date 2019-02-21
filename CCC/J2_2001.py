x,m=[int(input())for i in range(2)]
r=-1
for n in range(1,m):
    if (x*n)%m==1:
        r=n
        break
    
if r!=-1:
    print(r)
else:
    print('No such integer exists.')
