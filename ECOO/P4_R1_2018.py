storedSeq = {}

SQRT_5 = 2.23606798
ONE_OVER_SQRT_5 = 1 / SQRT_5
PHI = (1 + SQRT_5) / 2
PHI_SECONDARY = (1 - SQRT_5) / 2

def fib(n):
    if n in storedSeq: 
        return storedSeq[n]
    elif n <= 2:
        return 1
    else:
        newFib = (PHI**n + PHI_SECONDARY**n) * ONE_OVER_SQRT_5
        storedSeq[n] = newFib
        return newFib

def insideRect(rectX, rectY, rectWidth, rectHeight, x, y):
    if x >= rectX and x <= (rectX + rectWidth) and y >= rectY and y <= (rectY + rectHeight):
        return True
    else:
        return False

def buildRect(currentX, currentY, currentWidth, currentHeight, addFib, direction):
    if direction is 0:
        return (currentX - addFib), currentY, currentWidth + addFib, currentHeight
    elif direction is 1:
        return currentX, currentY, currentWidth, currentHeight + addFib
    elif direction is 2:
        return currentX, currentY, currentWidth + addFib, currentHeight
    else:
        return currentX, currentY - addFib, currentWidth, currentHeight + addFib

def execute(Px, Py):
    direction = -1
    x, y, width, height = 0, -1, 1, 1
    n  = 1
    inside = False
    while not inside:
        if not insideRect(x, y, width, height, Px, Py):
            direction = (direction + 1) % 4
            n += 1
            x, y, width, height = buildRect(x, y, width, height, fib(n), direction)
        else:
            inside = True

    return n

outputs = []
for _ in range(10):
    coords = input().split()
    outputs.append(execute(int(coords[0]), int(coords[1])))

for output in outputs:
    print(output)