#include <iostream>
#include <vector>
// #include <priority_queue>
#include <queue>
#include <unordered_set>
using namespace std;
#define INF 1000000000

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n+1];
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    queue<int> q;
    q.push(1);   
    
    vector<int> distances(n+1,INF);
    distances[1]=0;
    
    unordered_set<int> visited;
    
    while(!q.empty()) {
        int c=q.front();
        q.pop();
        
        for(pair<int,int>& conn : adj[c]) {
            int newdistance = distances[c] + conn.second;
            if(newdistance < distances[conn.first]) {
                distances[conn.first]=newdistance;
                q.push(conn.first);
            }
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        cout << (distances[i]==INF?-1:distances[i]) << "\n";
    }
}