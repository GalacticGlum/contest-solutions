#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include <bitset>

#define MAXN 20000001
typedef long long ll;

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    ll n, m;
    std::cin >> n >> m;
    std::vector<ll> prime_cache;
    long long sieve_size = std::ceil(std::sqrt(m));
    std::bitset<MAXN> sieve;
    sieve.set();
    // bool* sieve = new bool[sieve_size+1];
    // memset(&sieve, true, sizeof(bool) * (sieve_size+1));
    // memset(sieve, true, sizeof(bool)*(sieve_size+1));
    for (int i = 2; i <= sieve_size; ++i) {
        if (!sieve[i]) continue;
        prime_cache.push_back(i);
        for (int j = i; j < sieve_size; j += i) {
            sieve[j] = false;
        }
    }

    sieve.set();
    // sieve = new bool[m+1];
    // memset(sieve, true, sizeof(bool)*(m+1));
    for (int p : prime_cache) {
        ll s = (m/p)*p;
        for (ll j = s; j >= n; j -= p) {
            if (p == j) break;
            if (sieve[m-j]) {
                sieve[m-j] = false;
            }
        }
    }

    int count = n <= 2 ? -1 : 0;
    for (int i = 1; i <= m-n; ++i) {
        if (!sieve[i]) continue;
        count += 1;
    }

    std::cout << count << "\n";
}