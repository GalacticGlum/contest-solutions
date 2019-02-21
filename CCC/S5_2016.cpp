// okay, take two!
// time to implement this in C++ and AC !!!!!?!?!?!

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

long long n, t;

int get_index(long long i)
{
    i %= n;
    return i < 0 ? i + n : i;
}

std::vector<bool> readBinary(int n)
{
    static const int BUFFER_SIZE = 100000;
    char buffer[BUFFER_SIZE];
    std::vector<bool> result;
    result.reserve(n);

    std::cin.read(buffer, n+1);

    for (int i = 0; i < n+1; ++i)
    {
      if (buffer[i] == '0')
        result.push_back(false);
      else if(buffer[i] == '1')
        result.push_back(true);
    }

  return result;
}

long long largest_binary_power(long long n)
{
    unsigned long long power = 1;
    for (int i = 0; i < 64; ++i)
    {
        power <<=  1;
        if (power > n)
        {
            power >>= 1;
            return (long long)power;
        }
    }

    return 0;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> t;
    std::vector<bool> sequence = readBinary(n);

    std::vector<bool> new_sequence(n);
    std::fill(new_sequence.begin(), new_sequence.end(), false);
    
    while (t > 0)
    {
        long long n_generations = largest_binary_power(t);
        
        t -= n_generations;
        for (int i = 0; i < n; ++i)
        {
            new_sequence[i] = sequence[get_index(i-n_generations)] ^ sequence[get_index(i+n_generations)];
        }
        
        std::copy(new_sequence.begin(), new_sequence.end(), sequence.begin());
        std::fill(new_sequence.begin(), new_sequence.end(), false);
    }
    
    for (int i = 0; i < n; ++i)
    {
        std::cout << sequence[i];
    }
    
    std::cout << "\n";
}