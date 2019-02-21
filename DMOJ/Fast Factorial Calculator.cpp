#include <iostream>
typedef unsigned long long ull;

#define MOD 4294967296
#include <unordered_map>
std::unordered_map<int,ull> cache;

ull fact(int n) {
    if (n < 2) return 1;
    if (cache.find(n) != cache.end()) return cache[n];
    ull s = (fact(n-1)*n)%MOD;
    cache[n]=s;
    return s;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    ull n;
    std::cin >> n;

    for (ull i = 0; i < n; ++i) {
        ull x;
        std::cin >> x;
        ull r=0;
        if(x<34) {
            r=fact(x);
        }
        std::cout << r << "\n";
    }
}