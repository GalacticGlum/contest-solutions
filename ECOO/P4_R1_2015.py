words = ('ook', 'ookook', 'oog', 'ooga', 'ug', 'mook', 'mookmook', 'oogam', 'oogum', 'ugug')
cache = {}

def find(statement):
    if statement in cache: return cache[statement]

    n = 0
    for word in words:
        if statement.startswith(word):
            if len(statement) == len(word):
                n += 1
            else:
                n += find(statement[len(word):])

    cache[statement] = n
    return n

for _ in range(10):
    print(find(input()))