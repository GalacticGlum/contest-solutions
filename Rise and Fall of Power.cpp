#include <cmath>
#include <iostream>
#include <iomanip>

using ull = unsigned long long;

ull get_last_k(ull base, ull power, ull mod) 
{
    ull result = 1;
    while(power > 0) 
	{
        if(power & 1) 
		{
            result = (result*base) % mod;
        }

        base = (base * base) % mod;
        power = power / 2;
    }

    return result % mod;
}

void run(unsigned n, unsigned k)
{
	ull k_power_10 = std::lround(std::pow(10, k));
	unsigned first = std::pow(10, std::fmod(std::log10(static_cast<long double>(n)) * n, 1)) * (k_power_10 / 10);
	unsigned last = get_last_k(n, n, k_power_10);

	std::cout << first << " " << std::setfill('0') << std::setw(k) << last << "\n";
}

int main(int argc, char** argv)
{
	unsigned test_cases;
	std::cin >> test_cases;

	for(unsigned i = 0; i < test_cases; ++i)
	{
		unsigned n, k;
		std::cin >> n >> k;

		run(n, k);
	}

	// for (int i = 50; i < 1000; i++)
	// {
	// 	std::cout << "i=" << i << " | ";
	// 	run(i, 2);
	// }

	return 0;
}