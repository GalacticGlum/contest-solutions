def find_cycle(node, count=0, visited=None):
  if visited == None:
    visited = {node}
  else:
    visited.add(node)

  for k in connections:
    if k == node:
      if connections[k] not in visited:
        find_cycle(connections[k], count+1, visited)
      else:
        cycles.append(count + 1)


for i in range(5):
  n = int(input())
  connections = {}

  for j in range(n):
    a, b = [int(i) for i in input().split()]
    connections[a] = b

  cycles = []
  for node in connections:
    find_cycle(node)

  print(min(cycles))