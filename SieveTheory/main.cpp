#include "Sieve.h"
#include "EratosthenesSieve.h"
#include "EulerSieve.h"
#include <windows.h>

void getTime(void (*func)())
{
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    double elapsedTime;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    func();

    QueryPerformanceCounter(&end);
    elapsedTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("Elapsed Time: %f seconds\n", elapsedTime);
}

uint64_t max = 10000000;

void test1() { EratosthenesSieve s; s.run(std::to_string(max), "test1.txt"); }
void test2() { EulerSieve s; s.run(std::to_string(max), "test2.txt"); }

int main()
{
    getTime(test1);
    getTime(test2);

	return 0;
}