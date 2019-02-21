#include <iostream>
#include <vector>
#include <string.h>
#define MAXN 500001

std::vector<int> connections[MAXN];
int distances[MAXN], distances_cache[MAXN], path_cache[MAXN], dp_cache[MAXN];

void search(int current, int previous) {
    for (int connection : connections[current]) {
        if (connection == previous) continue;
        search(connection, current);
        if (distances[connection] + 1 > distances[current]) {
            distances_cache[current] = distances[current];
            distances[current] = distances[connection] + 1;
            path_cache[current] = connection;
        }
        else if (distances[connection] + 1 > distances_cache[current]) {
            distances_cache[current]=distances[connection]+1;    
        }
    }
}

void search_cache(int current, int previous, int distance) {
    dp_cache[current]=std::max(distance,distances[current]);
    for (int connection : connections[current]) {
        if (connection==previous) continue;
        if (connection==path_cache[current]) {
            search_cache(connection, current, std::max(distance+1,distances_cache[current]+1));
        }
        else {
            search_cache(connection,current,std::max(distance+1,distances[current]+1));
        }
    }
}


int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    
    std::cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        std::cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    
    memset(distances, 0, (n+1)*sizeof(int));
    memset(distances_cache, 0, (n+1)*sizeof(int));
    memset(path_cache, 0, (n+1)*sizeof(int));
    memset(dp_cache, 0, (n+1)*sizeof(int));

    // execute a dfs search and build our distance data
    search(1,-1);
    // build our dp data
    search_cache(1,-1,0);

    // std::fill_n(distances, n+1, 0);
    for (int i = 1; i < n+1; ++i) {
        std::cout << dp_cache[i]+1 << "\n";
    }
}