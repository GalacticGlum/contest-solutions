// STATUS: 10/100 (TLE)

#include <iostream>
typedef long long ll;

#define MAXN 200000
int main() {
    ll values[MAXN];
    int n, q;
    std::cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }

    for (int i = 0; i < q; ++i) {
        int l,r;
        ll k;
        std::cin >> l >> r >> k;

        ll greater = 0;
        ll less = 0;
        for(int j = l-1; j < r; ++j) {
            if (values[j]>=k) {
                greater += values[j];
            }
            else {
                less += values[j];
            }
        }

        std::cout << greater - less << "\n";
    }
}