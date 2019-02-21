n=int(input())
for _ in range(n):
    s=input()
    s_cache = []
    for i in range(len(s)):
        s_cache.append(s[i:])
    
    s_cache.sort()
    c = len(s_cache[0])+1
    for i in range(1,len(s)):
        sn=min(len(s_cache[i]),len(s_cache[i-1]))
        lc = sn
        for j in range(sn):
            if s_cache[i][j:j+1] != s_cache[i-1][j:j+1]:
                lc = j
                break
                                
        c += len(s_cache[i])-lc
        
    print(c)