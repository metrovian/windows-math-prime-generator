#include "Sieve.h"
#include "EratosthenesSieve.h"
#include <windows.h>

int main()
{
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    double elapsedTime;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    uint64_t max = 10000000;
    //std::vector<bool> is_prime(max, true);

    //is_prime[0] = false;
    //is_prime[1] = false;

    //for (size_t i = 2; i * i < max; ++i)
    //{
    //    if (!is_prime[i]) continue;
    //    for (size_t j = i + i; j * j < max; j += i)
    //    {
    //        is_prime[j] = false;
    //    }
    //}

	EratosthenesSieve s;
	s.run(std::to_string(max), "test.txt");

    QueryPerformanceCounter(&end);
    elapsedTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("Elapsed Time: %f seconds\n", elapsedTime);

	return 0;
}