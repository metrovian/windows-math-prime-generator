#include "Sieve.h"

bool test()
{
	int a = rand();
	int b = rand();

	std::string sa = std::to_string(a);
	std::string sb = std::to_string(b);

	std::string sm = Sieve::modplus(sa, sb, "1000000000");

	int c = a + b;
	int d = std::stoi(sm);

	return c == d;
}

int main()
{
	srand(time(NULL));

	for (int i = 0; i < 1000000; ++i)
	{
		if (!test())
		{
			std::cout << "Test Failed!" << std::endl;
			return 1;
		}
	}

	std::cout << "Test Passed!" << std::endl;

	return 0;
}