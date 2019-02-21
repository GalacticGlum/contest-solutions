#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 10000000
ll precalc_cache[MAXN+1];
unordered_map<int,ll> secondary;

ll solve(int n) {
  if (n <= MAXN && precalc_cache[n]) return precalc_cache[n];
  else if (n > MAXN && secondary[n]) return secondary[n];

  ll r = 0;
  int i = 1;
  int m = n;
  while (i < n) {
    int d = n/i - n/(i+1);
    r += solve(i) * d;
    m -= d;
    i = n / (m);
  }

  if (n <= MAXN) return precalc_cache[n]=r;
  else return secondary[n] = r;
}

int main() {
  int n;
  precalc_cache[1] = precalc_cache[2] = 1;
  cin>>n;
  cout << solve(n) << "\n";
}