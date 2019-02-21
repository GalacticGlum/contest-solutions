blocks = [int(input()) for i in range(3)]
if blocks[0] <= blocks[1] and blocks[1] <= blocks[2]:
    print('Good job!')
else:
    print('Try again!')
