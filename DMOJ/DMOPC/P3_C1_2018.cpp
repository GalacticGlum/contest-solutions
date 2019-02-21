#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::vector<int> op[10000];
    
    int n;
    std::cin >> n;
    
    int a[n+1];
    for (int i = 1; i < n + 1; ++i)
    {
        std::cin >> a[i];
    }
    
    a[0] = 0;
    int o = 0;
    while (!std::is_sorted(a, a+(n+1)))
    {
        for(int i = 1; i < n + 1; ++i)
        {
            if(a[i] != i)
            {
                op[o].push_back(2);
                op[o].push_back(a[i]);
                op[o].push_back(i);
                std::swap(a[i], a[a[i]]);
                ++o;
            }
        }
    }
    
    std::cout << o << "\n";
    for (int i = 0; i < o; ++i)
    {
        std::cout << op[i][0] << " " << op[i][1] << " " << op[i][2] << "\n";
    }
}