#include "Sieve.h"
#include "EratosthenesSieve.h"
#include "EulerSieve.h"
#include "AtkinSieve.h"
#include "PritchardSieve.h"
#include "SundaramSieve.h"
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

    printf("Elapsed Time: %f seconds\n\n", elapsedTime);
}

uint64_t max = 1000000;

void test1() { EratosthenesSieve s; s.run(std::to_string(max), "test1.txt"); }
void test2() { EulerSieve s; s.run(std::to_string(max), "test2.txt"); }
void test3() { AtkinSieve s; s.run(std::to_string(max), "test3.txt"); }
void test4() { PritchardSieve s; s.run(std::to_string(max), "test4.txt"); }
void test5() { SundaramSieve s; s.run(std::to_string(max), "test5.txt"); }

int main()
{
    getTime(test1);
    getTime(test2);
    getTime(test3);
    getTime(test4);
    getTime(test5);

	return 0;
}