// STATUS: 5/100 (TLE)
#include <iostream>
#include <unordered_map>
#include <vector>
#define MOD 4294967291
typedef unsigned long long ull;

std::unordered_map<int,std::pair<ull,ull>> cache;

ull bc(ull v) {
    ull w=v-((2863311530&v) >> 1);
    w=(w&858993459)+((w>>2)&858993459);
    w = w + (w>>4)&252645135;
    w += w >> 8;
    w += w >> 16;
    return v-(w&255);
}

ull prod(ull n, ull m) {
    if(m<=(n+1)) return n;
    if(m==(n+2)) return n*m;
    int k = (n+m)/2;
    if((k&1)!=1) {
        k-=1;
    }
    
    return prod(n,k)*prod(k+2,m);
}

ull p, r;
void mul(ull n) {
    if (n<=2)return;
    if (cache.find(n)!=cache.end()) {
        auto pair = cache[n];
        p=pair.first;
        r=pair.second;
    } else {
        mul(n/2);
        p*=prod(n/2+1+((n/2)&1),n-1+(n&1));
        r*=p;
        cache[n]={p,r};
    }
}

ull fact(ull n) {
    p=1;
    r=1;
    mul(n);
    return (r<<bc(n))%MOD;
}

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        ull x;
        std::cin >> x;
        std::cout << fact(x) << "\n";
    }
}