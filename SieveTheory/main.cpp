#include "Sieve.h"
#include "EratosthenesSieve.h"

int main()
{
	EratosthenesSieve s;
	s.run(std::to_string(1000000), "test.txt");

	return 0;
}