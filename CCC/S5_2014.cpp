#include <iostream>
#include <vector>
#include <algorithm>

struct query
{
    int a;
    int b;
    int d;
    
    query(int a, int b, int d) : a(a), b(b), d(d) {}
};

struct point
{
    int x;
    int y;
    point(int x, int y) : x(x), y(y) {}
};

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    int distances[2001];
    int prev_result[2001];
    int result[2001];
    
    std::fill(distances, distances + 2001, 0);
    std::fill(prev_result, prev_result + 2001, 0);
    std::fill(result, result + 2001, 0);
    
    int a, b;
    std::vector<point> points;
    points.push_back(point(0,0));
    
    std::vector<query> queries;
    
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a >> b;
        points.push_back(point(a,b));
        for (int j = i-1; j >= 0; --j)
        {
            int dx = points[i].x - points[j].x;
            int dy = points[i].y - points[j].y;
            queries.push_back(query(j,i,dx*dx+dy*dy));
        }
    }
    
    std::sort(queries.begin(), queries.end(), [](const query& a, const query& b) -> bool
    { 
        return a.d < b.d; 
    });
    
    for (query& q : queries)
    {
        if(q.d > distances[q.a])
        {
            distances[q.a] = q.d;
            prev_result[q.a] = result[q.a];
        }
        
        if(q.d > distances[q.b])
        {
            distances[q.b] = q.d;
            prev_result[q.b] = result[q.b];
        }
        
        result[q.a]=std::max(result[q.a],prev_result[q.b]+1);
        if (q.a!=0)
        {
            result[q.b]=std::max(result[q.b],prev_result[q.a]+1);
        }
    }
    
    std::cout << result[0]<<"\n";
}