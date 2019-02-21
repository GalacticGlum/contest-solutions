from math import floor

matrix=[]
for i in range(3):
    row=input().split()
    matrix.append([int(c)if c!='X'else 'X' for c in row])

def solve_row_columns():
    # solve rows
    # while any(matrix[y].count('X')==1 for y in range(3)):
    for y in range(3):
        xcount=matrix[y].count('X')
        if xcount != 1: continue

        dest=0
        for x in range(3):
            if matrix[y][x]=='X':
                dest=x
                break

        if dest == 0:
            matrix[y][0]=2*matrix[y][1]-matrix[y][2]
        elif dest == 2:
            matrix[y][2]=2*matrix[y][1]-matrix[y][0]
        else:
            matrix[y][1]=int((matrix[y][0]+matrix[y][2])/2)

    # solve columns
    for x in range(3):
        xcount = 0
        dest = 0
        for y in range(3):
            if matrix[y][x]=='X':
                xcount+=1
                dest=y
        
        if xcount != 1: continue
        if dest == 0:
            matrix[0][x]=2*matrix[1][x]-matrix[2][x]
        elif dest == 2:
            matrix[2][x]=2*matrix[1][x]-matrix[0][x]
        else:
            matrix[1][x]=int((matrix[0][x]+matrix[2][x])/2)

while any(row.count('X')>0 for row in matrix):
    # solve (1,0)
    if matrix[0][0] != 'X' and matrix[0][1]==matrix[1][0]=='X':
        matrix[1][0]=matrix[0][0]

    # solve (0,1) using (1,2), (2,1), and (1,0)
    if matrix[1][0]!='X' and matrix[1][2]!='X' and matrix[2][1]!='X':
        matrix[0][1]=matrix[1][0]+(matrix[1][2]-matrix[2][1])

    if matrix[0][0]!='X' and matrix[0][1]!='X' and matrix[1][0]=='X':
        matrix[1][0]=2*matrix[0][0]-matrix[0][1]+1

    if matrix[0][0]=='X' and matrix[0][1]!='X' and matrix[1][0]!='X':
        matrix[0][0]=floor((matrix[0][1]+matrix[1][0])/2)

    # solve a b c 
    #       d X X
    #       g X X         
    if all(matrix[0][x]!='X' for x in range(3)) and all(matrix[y][0]!='X' for y in range(3)) and sum(row.count('X') for row in matrix)==4:
        matrix[1][1]=matrix[2][1]=matrix[0][1]
        matrix[1][2]=matrix[2][2]=matrix[0][2]

    solve_row_columns()
    # print(matrix)
            
for row in matrix:
    print(' '.join(str(i) for i in row))