#include <iostream>

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, mass;
    std::cin >> n;
    
    int* ps = new int[n+1];
    ps[0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> mass;
        ps[i] = ps[i-1] + mass;
    }   

    int nq, a, b;
    std::cin >> nq;
    for (int i = 0; i < nq; ++i)
    {
        std::cin >> a >> b;
        std::cout << ps[b+1]-ps[a] << "\n";
    }
}