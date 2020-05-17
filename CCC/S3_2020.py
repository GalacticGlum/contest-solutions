n=input()
h=input()

# checks if a is a permutation of b
def is_perm(a,b):
    # must be a permutation if character count is the same....
    s=set(b)
    for c in s:
        if a.count(c)==b.count(c): continue
        return False
        
    return True

result=0
visited=set()
for i in range(len(h)-len(n)+1):
    substring=h[i:i+len(n)]
    if substring in visited: continue
    visited.add(substring)
    if is_perm(substring,n):
        result+=1

print(result)