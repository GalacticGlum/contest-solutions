t = int(input())
for case in range(t):
    n = int(input())
    cars = [int(input()) for i in range(n)]

    branch = []
    next_in_lake = 1;

    for i in range(n-1, -1, -1):
        car = cars[i]
        branch.append(car)
        while len(branch) > 0 and branch[len(branch) - 1] == next_in_lake:
            branch.pop()
            next_in_lake += 1

    if len(branch) == 0:
        print('Y')
    else:
        print('N')