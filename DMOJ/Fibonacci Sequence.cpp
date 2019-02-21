#include <iostream>
#include <unordered_map>
#define MOD 1000000007
#define exists(D,V) D.find(V) != D.end()
typedef unsigned long long ull;
std::unordered_map<ull, ull> cache;

ull fib(ull n) {
    if (n < 2) return 1;
    if(exists(cache,n)) return cache[n];
    
    ull a = fib((n+1)/2) * fib(n/2);
    ull b = fib((n-1)/2) * fib((n-2)/2);
    ull solution = (a+b)%MOD;
    cache[n] = solution;
    return solution;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    ull n;
    std::cin >> n;
    std::cout << fib(n-1) << "\n";
}