from queue import Queue

n = int(input())
vertices = {i:{int(j)-1 for j in input().split()[1:]} for i in range(n)}

nodes = Queue()
nodes.put(0)

current_length = 0
destination_length = float('inf')

visited = {0}

while not nodes.empty():
    current_node = nodes.get()
    current_length += 1

    if len(vertices[current_node]) == 0:
        destination_length = min(destination_length, current_length)
    
    for neighbour in vertices[current_node]:
        if neighbour not in visited:
            visited.add(neighbour)
            nodes.put(neighbour)
            
print('Y' if len(visited) == n else 'N', destination_length, sep='\n')