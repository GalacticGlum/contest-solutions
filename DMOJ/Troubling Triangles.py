n = int(input())
for _ in range(n):
    x1, y1, x2, y2, x3, y3 = map(int, input().split())
    A = ((x1-x2)**2+(y1-y2)**2)**0.5
    B = ((x1-x3)**2+(y1-y3)**2)**0.5
    C = ((x2-x3)**2+(y2-y3)**2)**0.5
    
    s = (A+B+C)/2
    area = (s*(s-A)*(s-B)*(s-C))**0.5
    print(round(area, 2), round(s*2, 2))