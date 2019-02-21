matrix=[[1,2],[3,4]]

for i in input():
    if i == 'H':
        matrix[0],matrix[1]=matrix[1],matrix[0]
    if i == 'V':
        matrix[0][0],matrix[0][1]=matrix[0][1],matrix[0][0]
        matrix[1][0],matrix[1][1]=matrix[1][1],matrix[1][0]

for i in matrix:
    print(' '.join(str(x) for x in i))