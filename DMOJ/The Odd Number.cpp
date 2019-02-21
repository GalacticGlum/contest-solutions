#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        int value;
        std::cin >> value;

        result ^= value;
    }

    std::cout << result << "\n";

    return 0; 
}