#include <bits/stdc++.h>
#include<string.h>
#define INF 0x3f3f3f3f 
#define MAXN 100001

std::vector<int> connections[MAXN];
int distances[MAXN];

void find(int source, int n) {
    memset(distances,INF,sizeof(int)*(n+1));
    distances[source] = 0;
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int> >, std::greater<std::pair<int,int> > > pq;
    // std::set<std::pair<int,int> > q;
    // q.insert({0,source});
    pq.push({0,source});
    while (!pq.empty()) {
        int u = pq.top().second;
        //if (u == target) return distances[u];
        pq.pop();
        // q.erase(q.begin());
        for (auto c : connections[u]) 
            if (distances[c] > distances[u] + 1) {
                distances[c]=distances[u]+1;
                pq.push({distances[c],c});
            }
    }
    //return INF;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int n,m,q,c;
    std::cin >> n >> m >> q >> c;
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    find(c,n);

    for (int i = 0; i < q;++i){
        int a,b;
        std::cin >> a >> b;
        
        int d1=distances[a];
        int d2=distances[b];
        if (d1 == INF || d2 == INF) {
            std::cout << "This is a scam!\n";
        }
        else {
            std::cout << (d1+d2) << "\n";
        }
    }

    return 0;
}