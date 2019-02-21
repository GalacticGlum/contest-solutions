from math import gcd, floor

a = int(input())
b = int(input())

ab_gcd = gcd(a,b)
if a%b!=0:
    a /= ab_gcd
    b /= ab_gcd
    
    m = int(floor(a/b))
    r = int(a%b)
    if m == 0:
            print('{0}/{1}'.format(r, int(b)))
    else:
        print('{0} {1}/{2}'.format(m, r, int(b)))
else:
    print(ab_gcd)