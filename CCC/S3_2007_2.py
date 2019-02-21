from queue import Queue

n = int(input())
connections = {}

for i in range(n):
    a, b = map(int, input().split())
    if a not in connections:
        connections[a] = set()

    connections[a].add(b)

while True:
    a, b = map(int, input().split())
    if a == b == 0: break

    # check whether a is in the same circle as b
    q = Queue()
    q.put(a)

    visited = set()

    in_same_circle = False
    separation = 0    
    while not q.empty():
        u = q.get()
        if u == b: 
            in_same_circle = True
            break

        if u in visited: continue

        separation += 1
        visited.add(u)
        
        if u not in connections or len(connections[u]) == 0:
            separation -= 1
            continue

        for child in connections[u]:
            q.put(child)   

    if in_same_circle:
        print('Yes', separation-1)
    else:
        print('No')