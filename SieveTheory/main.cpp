#include "Sieve.h"
#include "EratosthenesSieve.h"

int main()
{
    uint64_t max = UINT32_MAX - 1;
    std::vector<bool> is_prime(max, true);

    is_prime[0] = false;
    is_prime[1] = false;

    for (size_t i = 2; i * i < max; ++i)
    {
        if (!is_prime[i]) continue;
        for (size_t j = i + i; j * j < max; j += i)
        {
            is_prime[j] = false;
        }

        std::cout << i << std::endl;
    }

	EratosthenesSieve s;
	s.run(std::to_string(UINT32_MAX), "test.txt");

	return 0;
}