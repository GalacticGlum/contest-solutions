r,x,y = map(int,input().split())
ax,ay,ma = map(int,input().split())
bx,by,mb = map(int,input().split())
cx,cy,mc = map(int,input().split())

def get_distance(px,py):
    return ((x-px)**2+(y-py)**2)**0.5

m = min(ma,mb,mc)
if m == ma:
    d=get_distance(ax,ay)
elif m == mb:
    d=get_distance(bx,by)
else:
    d=get_distance(cx,cy)

if d < r:
    print('What a beauty!')
else:
    print('Time to move my telescope!')
