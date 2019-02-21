class Entry:
    def __init__(self, id, n_values, values):
        self.id = id
        self.n_values = n_values
        self.values = values

def execute(n, entries):
    minimums = []
    for entry in entries:
        minimums.append(min(entry.values))

    smallest_min = min(minimums)
    output = '{0} '.format(smallest_min) + '{'

    entries_to_add = []
    for i in range(n):
        if smallest_min in entries[i].values:
            entries_to_add.append(entries[i])

    entries_to_add.sort(key=lambda x: x.id)
    for j in range(len(entries_to_add)):
        output += '{0}'.format(entries_to_add[j].id) + (',' if j != len(entries_to_add) - 1 else '')
            
    output += '}'
    return output
    
outputs = []
for _ in range(10):
    n = int(input())
    entries = []
    for i in range(n):
        line = input().split()
        n_values = int(line[1])

        values = line[2:n_values + 2]
        entry = Entry(int(line[0]), n_values, [int(value) for value in values])
        entries.append(entry)

    outputs.append(execute(n, entries))

for output in outputs:
    print(output)