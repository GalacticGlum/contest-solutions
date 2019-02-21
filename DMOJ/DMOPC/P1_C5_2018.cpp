#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> p(ll n) {
    vector<int> r;
    
    while(n>0) {
        int pw = static_cast<int>(floor(log2(n)));
        r.push_back(pw);
        n-=static_cast<int>(pow(2,pw));
    }
    
    return r;
}

int main() {
    ll n,m,k;
    cin >> n >> m >> k;
    vector<int> pn=p(n);
    vector<int> pm=p(m);
    
    int blue = 0;
    int purple = 0;
    for(int i = 1; i < k+1; ++i) {
        if ((find(pn.begin(),pn.end(),i-1) != pn.end()) != (find(pm.begin(),pm.end(),i-1) != pm.end())) {
            blue+=1;
        } else {
            purple+=1;
        }
    }
    
    cout << blue << " " << purple << "\n";
    
    return 0;
}