n=int(input())
cache = [0]*100001
index=0

def sort(lo, hi):
    global index
    if lo < hi:
        mid=(lo+hi)//2
        sort(lo,mid)
        sort(mid+1,hi)
        index += merge(lo, mid, hi)

def merge(lo,mid,hi):
    global cache

    copy = [0]*(hi-lo+1)
    nl = lo
    nm = mid + 1
    k = 0

    result = 0
    while nl <= mid and nm <= hi:
        if cache[nl] <= cache[nm]:
            copy[k]=cache[nl]
            k+=1
            nl+=1
        else:
            copy[k]=cache[nm]
            k+=1
            nm+=1
            result+=mid+1-nl
        
    while nl <= mid:
        copy[k]=cache[nl]
        k+=1
        nl+=1
    
    while nm <= hi:
        copy[k]=cache[nm]
        k+=1
        nm+=1

    for i in range(lo, hi+1):
        cache[i]=copy[i-lo]

    return result

for i in range(n):
    cache[i]=int(input())
sort(0,n-1)
print('{0:.2f}'.format((index+n)/n))
