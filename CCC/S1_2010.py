n = int(input())
if n > 0 and n <= 10000:
    computers = []
    for i in range(n):
        components = input().split()
        specs = [int(j) for j in components[1:]]

        value = 2 * specs[0] + 3 * specs[1] + specs[2]
        computers.append((components[0], value))

    def get_top(values): return max(values, key=lambda x: x[1])

    first = get_top(computers)
    computers.remove(first)

    if len(computers) == 0:
        second = first
    else:
        second = get_top(computers)

    names = [first[0], second[0]]
    if names[0] == names[1]:
        print(names[0])
    else:
        if first[1] == second[1]:
            names.sort()

        print(names[0], names[1], sep='\n')