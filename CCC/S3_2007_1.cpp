#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 10000

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, a, b;
    std::vector<int> connections[MAX_N];
    
    std::cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a >> b;
        connections[a].push_back(b);
    }
    
    bool visited[MAX_N];
    std::queue<int> q;

    while (true)
    {
        std::cin >> a >> b;
        if (a == 0 && b == 0) break;
        std::fill(visited, visited + MAX_N, false);
        q.push(a);
        
        bool in_same_circle = false;
        int separation = 0;
        
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            
            if (u == b)
            {
                in_same_circle = true;
                break;
            }
            
            if (visited[u]) continue;
            separation += 1;
            visited[u] = true;
            
            if (connections[u].size() == 0)
            {
                separation -= 1;
                continue;
            }
            
            for (int child : connections[u])
            {
                q.push(child);
            }
        }
        
        if (in_same_circle)
        {
            std::cout << "Yes " << separation-1 << "\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }
}