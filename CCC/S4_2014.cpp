#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

struct entry 
{
  int x1, y1, x2, y2, tint;
  entry(int x1, int y1, int x2, int y2, int tint) : x1(x1), y1(y1), x2(x2), y2(y2), tint(tint) {}
};

typedef long long ll;
#define MAXN 2002

int find(const std::set<int>& array, int value)
{
    return std::distance(array.begin(), array.lower_bound(value));
}

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, threshold;
    std::cin >> n >> threshold;
    
    int** tints = new int*[MAXN];
    for (int i = 0; i < MAXN; ++i)
    {
        tints[i] = new int[MAXN];
    }

    std::set<int> h, v;
    std::vector<entry> glasses;
    
    for (int i = 0; i < n; ++i)
    {
        int x1, y1, x2, y2, tint;
        std::cin >> x1 >> y1 >> x2 >> y2 >> tint;
        glasses.push_back(entry(x1,y1,x2,y2,tint));
        
        h.insert(x1);
        h.insert(x2);
        v.insert(y1);
        v.insert(y2);
    }
   
    for (entry& glass : glasses)
    {
        int start = find(v, glass.y1);
        int end = find(v, glass.y2);

        int x1_idx = find(h, glass.x1);
        int x2_idx = find(h, glass.x2);   
        for (int i = start; i < end; ++i)
        {
            tints[i][x1_idx] += glass.tint;
            tints[i][x2_idx] -= glass.tint;
        }
    }

    std::vector<int> sh, sv;
    sh.assign(h.begin(), h.end());
    sv.assign(v.begin(), v.end());
     
    ll r = 0;
    for (int i = 0; i < sv.size(); ++i)
    {
        int ct = 0;
        for (int j = 0; j < sh.size(); ++j)
        {
            ct += tints[i][j];
            if (ct >= threshold)
            {
                r += (ll)(sh[j+1]-sh[j])*(sv[i+1] - sv[i]);
            }
        }
    }
    
    std::cout << r << "\n";
}