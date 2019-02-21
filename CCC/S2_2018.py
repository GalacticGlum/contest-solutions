n = int(input())
values = [[int(j) for j in input().split()] for i in range(n)]

top_left = values[0][0]
top_right = values[0][n - 1]
bottom_left = values[n - 1][0]
bottom_right = values[n - 1][n - 1]

min_corner = min(top_left, top_right, bottom_left, bottom_right)

def rotate_clockwise(matrix, degree):
    return matrix if not degree else rotate_clockwise(list(zip(*matrix[::-1])), degree - 90)

if min_corner == top_right:
    values = rotate_clockwise(values, 270)
elif min_corner == bottom_left:
    values = rotate_clockwise(values, 90)
elif min_corner == bottom_right:
    values = rotate_clockwise(values, 180)

for row in values:
    print(*row, sep=' ')