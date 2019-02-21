#include <bits/stdc++.h>
using namespace std;

#define MAXN 2000000

int main() {
    bitset<MAXN+1> primes;
    primes.set();
    
    for(int i = 2; i*i <= MAXN; ++i) {
        if(!primes[i]) continue;
        for(int j = i*i; j<=MAXN; j+=i) {
            primes[j]=false;
        }
    }

    int n,t,a,b;
    cin>>t;
    for(int ti=0; ti < t; ++ti) {
        cin>>n;
        for(a=2;a<=MAXN;++a) {
            if(!primes[a]) continue;
            b=2*n-a;
            if(!primes[b]) continue;
            cout << a << " " << b << "\n";
            break;
        }
    }
}