#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
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
        
        int k;
        cin >> k;
        
        unordered_map<int,int> p;
        for(int i = 0; i < k; ++i) {
            int z, pz;
            cin >> z >> pz;
            p[z]=pz;
        }
        
        int d;
        cin >> d;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,d});   
        
        vector<int> distances(n+1,INF);
        distances[d]=0;
        
        unordered_set<int> visited;
        
        while(!pq.empty()) {
            int cd=pq.top().first;
            int c=pq.top().second;
            pq.pop();
            
            if(visited.find(c)!=visited.end()) continue;
            visited.insert(c);
            
            for(pair<int,int>& conn : adj[c]) {
                int newdistance = distances[c] + conn.second;
                if(newdistance < distances[conn.first]) {
                    distances[conn.first]=newdistance;
                    pq.push({newdistance,conn.first});
                }
            }
        }
        
        int r=INF;
        for(auto it = p.begin(); it != p.end(); ++it) {
            int nr = distances[it->first] + it->second;
            if(nr < r) {
                r=nr;
            }
        }
        
        std::cout << r << "\n";
}