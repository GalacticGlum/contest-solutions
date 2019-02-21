n=int(input())
a=input()
b=input()

if a.count('F') % 2 == b.count('F')%2 and a.count('A')%2 == b.count('A')%2:
    print('YES')
else:
    print('NO')