#include <iostream>
#include <unordered_map>
#include <unordered_set>

struct query
{
    int a, b, x, y;
};

std::unordered_map<int, std::unordered_set<int> > to_lookup;
std::unordered_map<int,int> current_freq;
std::unordered_map<int, std::unordered_map<int, int> > freq;

void add_lookup(int index, int value)
{
    if(to_lookup.find(index) != to_lookup.end())
    {
        to_lookup[index].insert(value);
    }
    else
    {
        to_lookup[index]= std::unordered_set<int>({value});
    }
    
    current_freq[value]=0;
}

int get_freq_at(int i, int val)
{
    if(freq[i].find(val) == freq[i].end()) return 0;
    return freq[i][val];
}

int get_freq(int start, int end, int val)
{
    return get_freq_at(end,val) - get_freq_at(start, val);
}

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n,k,q;
    std::cin >> n >> k >> q;
    
    freq[0] = std::unordered_map<int, int>();
    int ps[n+1];
    std::fill(ps, ps+n+1,0);
    
    int values[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> values[i];
    }

    query queries[q];
    for (int i = 0; i < q; ++i)
    {    
        int a, b, x, y;
        std::cin >> a >> b >> x >> y;
        add_lookup(x-1, a);
        add_lookup(y,a);
        
        add_lookup(x-1,b);
        add_lookup(y,b);
        
        queries[i] = {a,b,x,y};
    }
    
    for (int i = 1; i <= n; ++i)
    {
        int value = values[i-1];
        if (current_freq.find(value) != current_freq.end())
        {
            current_freq[value] += 1;
        }
        
        if(to_lookup.find(i) != to_lookup.end())
        {
            freq[i] = std::unordered_map<int, int>();
            for (int j : to_lookup[i])
            {
                freq[i][j] = current_freq[j];
            }
        }
        
        ps[i] = ps[i-1]+value;
    }
    
    for(int i = 0; i < q; ++i)
    {
        query query_i = queries[i];
        if ((ps[query_i.y]-ps[query_i.x-1]) > k)
        {
            int a_freq = get_freq(query_i.x-1, query_i.y, query_i.a);
            int b_freq = get_freq(query_i.x-1, query_i.y, query_i.b);
            
            if(a_freq > 0 && b_freq > 0)
            {
                std::cout <<"Yes\n";
            }
            else
            {
                std::cout <<"No\n";
            }
        }
        else
        {
            std::cout << "No\n";
        }
    }
}