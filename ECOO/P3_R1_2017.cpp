#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define MAX_N 10000

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    int heights[MAX_N];
    int counts[MAX_N];
    
    // loop through each test case
    for (int ti = 0; ti < 10; ++ti)
    {
        std::fill(heights, heights + MAX_N, 0);
        std::fill(counts, counts + MAX_N, 0);

        std::cin >> n;
        for(int i = 0; i < n; ++i)
        {
            std::cin >> heights[i];
        }
        
        for (int i = 0; i < n; ++i)
        {
            counts[i]=0;
            for(int j = 0; j < n; ++j)
            {
                if(i==j) continue;
                float m = (float)(heights[j]-heights[i])/(j-i);
                float b = heights[i]-m*i;
                bool is_visible = true;
                for(int k = std::min(i,j)+1; k < std::max(i,j); ++k)
                {
                    if(heights[k] >= m*k+b)
                    {
                        is_visible=false;
                        break;
                    }
                }
                
                if(is_visible)
                {
                    counts[i]+=1;
                }
            }
        }
        
        int max_count = 0;
        int index = 0;
        for(int i = 0; i < n; ++i)
        {
            if(counts[i]>max_count)
            {
                max_count=counts[i];
                index=i;
            }
        }
        
        std::cout << index+1 << "\n";
    }