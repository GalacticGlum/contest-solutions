def execute(t, n, boxes):
    daysLeft = 0
    
    for i in range(n):
        if boxes[i] == 'B':
            daysLeft += t

        if daysLeft > 0:
            daysLeft -= 1    

    print(max(0, daysLeft))

for _ in range(10):
    t,n = [int(i) for i in input().split()]
    boxes = [input() for i in range(n)]
    execute(t, n, boxes)