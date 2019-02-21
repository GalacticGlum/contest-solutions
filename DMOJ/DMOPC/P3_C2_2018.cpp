#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cstring>

#define MEM(a, b) memset(a, (b), sizeof(a))

std::map<int, std::vector<int> > connections;

void solve(int current, int* distances)
{
    std::queue<int> d;
    d.push(current);
    distances[current] = 0;

    while (!d.empty())
    {
        current = d.front();
        d.pop();

        for (int i = 0; i < connections[current].size(); ++i)
        {
            int next = connections[current][i];
            if (distances[next] == -1)
            {
                distances[next] = distances[current] + 1;
                d.push(next);
            }
        }
    }
}

int main() 
{
    int n, m, k, a, b;
    std::cin >> n >> m >> k >> a >> b;

    std::vector<int> gift;

    int gift_building;
    for (int i = 0; i < k; ++i)
    {
        std::cin >> gift_building;
        gift.push_back(gift_building);
    }

    int x, y;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> x >> y;
        connections[x].push_back(y);
        connections[y].push_back(x);
    }

    int dis1[100001];
    int dis2[100001];

    MEM(dis1, -1);
    MEM(dis2, -1);

    solve(a, dis1);
    solve(b, dis2);

    int s, minima = 0x3f3f3f3f;
    for (int i = 0; i < k; ++i)
    {
        s = gift[i];
        minima = std::min(minima, dis2[s] + dis1[s]);
    }

    std::cout << minima << "\n";
}