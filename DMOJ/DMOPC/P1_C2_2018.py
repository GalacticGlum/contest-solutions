p = int(input())

max_x = 0
min_x = 0
max_y = 0
min_y = 0

for _ in range(p):
    x, y = [int(i) for i in input().split()]
    if x > max_x:
        max_x = x
        
    if x < min_x:
        min_x = x
    
    if y > max_y:
        max_y = y
        
    if y < min_y:
        min_y = y
        
print(2*(max_x-min_x+max_y-min_y))