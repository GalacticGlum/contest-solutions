#include <iostream>
#include <queue>
#include <string.h>

#define MAXN 1000000
std::vector<int> connections [MAXN];
bool visited[MAXN];

bool find(int p, int q) {
    memset(visited, false, sizeof(visited));
    std::queue<int> queue;
    queue.push(p);
    
    while (!queue.empty()) {
        int current_node = queue.front();
        queue.pop();
        
        if (current_node == q) return true;
        for (int i = 0; i < connections[current_node].size(); ++i) {
            int connection = connections[current_node][i];
            if (visited[connection]) continue;
            visited[connection] = true;
            queue.push(connection);
        }
    }
    
    return false;
}

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        
        connections[a].push_back(b);
    }
    
    int p, q;
    std::cin >> p >> q;
    
    if (find(p,q)) {
        std::cout << "yes\n";
    } else if(find(q,p)) {
        std::cout << "no\n";
    } else {
        std::cout << "unknown\n";
    }
}