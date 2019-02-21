l = int(input())

for _ in range(l):
    n = int(input())
    names = [input() for i in range(n)]
    visited = {names[n-1]}
    
    t = 0
    r = 0
    for i in range(n):
        if names[i] in visited:
            t -= 1
        else:
            visited.add(names[i])
            t += 1
            if t > r:
                r = t
                
    print((n-r*2)*10)