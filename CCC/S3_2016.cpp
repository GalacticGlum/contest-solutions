#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int n, m;
int distances[100000];
bool visited[100000];
bool pho_restaurants[100000];
std::vector<int> connections[100000];
bool pho_leaf[100000];

void bfs(int node)
{
    std::queue<int> q;
    q.push(node);
    
    std::fill(visited, visited + n, false);
    visited[node] = true;
    
    std::fill(distances, distances + n, -1);
    distances[node] = 0;
    
    while (!q.empty())
    {
        int current_node = q.front();
        q.pop();
        
        for (int connection : connections[current_node])
        {
            if(visited[connection]) continue;
            visited[connection] = true;
            distances[connection] = distances[current_node] + 1;
            q.push(connection);
        }
    }
}

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> m;
    
    std::fill(pho_restaurants, pho_restaurants + n, false);

    int x;
    for (int i = 0; i < m; ++i)
    {
        std::cin >>x;
        pho_restaurants[x] = true;
    }

    int a, b;
    for (int i = 0; i < n - 1; ++i)
    {
        std::cin >> a >> b;
        
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    std::fill(pho_leaf, pho_leaf + n, true);
    
    std::queue<int> q_nodes;
    std::fill(visited, visited + n, false);

    for (int i = 0; i < n; ++i)
    {
        if (connections[i].size() > 1 || pho_restaurants[i]) continue;

        pho_leaf[i] = false;
        visited[i] = true;
        q_nodes.push(i);
    }

    while (!q_nodes.empty())
    {
        int current_node = q_nodes.front();
        q_nodes.pop();

        int child = connections[current_node][0];
        
        for (int to_remove : connections[current_node])
        {
            auto& connection = connections[to_remove];
            connection.erase(std::remove(connection.begin(), connection.end(), current_node), connection.end());
        }
        
        connections[current_node].clear();
        
        if (connections[child].size() > 1 || pho_restaurants[child] || visited[child]) continue;
        pho_leaf[child] = false;
        visited[child] = true;
        q_nodes.push(child);
    }
    
    int d = -1;
    for (int i = 0; i < n; ++i)
    {
        if(!pho_leaf[i]) continue;
        
        bfs(i);
        int max_distance = -1;
        int from_node = -1;
        
        for(int j = 0; j < n; ++j)
        {
            if(pho_leaf[j])
            {
                if(distances[j] > max_distance)
                {
                    max_distance = distances[j];
                    from_node = j;
                }
            }
        }
                
        bfs(from_node);
        for (int j = 0; j < n; ++j)
        {
            if(pho_leaf[j])
            {
                d = std::max(d, distances[j]);
            }
        }
        
        // lololol
        // i was micro optimizing when i think
        // this was the issue; i wasn't breaking
        // rip life
        // programming at 2:39 am is not good
        break;
    }
    
    int leaf_count = 0;
    for (int i = 0; i < n; ++i)
    {
        if(pho_leaf[i])
        {
            leaf_count += 1;
        }
    }
    
    std::cout << 2*(leaf_count-1)-d << "\n";
}