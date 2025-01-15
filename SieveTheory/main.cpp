#include "Sieve.h"

static bool test_plus()
{
	int a = rand();
	int b = rand();

	std::string sa = std::to_string(a);
	std::string sb = std::to_string(b);

	std::string sm = Sieve::modplus(sa, sb, "-");

	int c = a + b;
	int d = std::stoi(sm);

	return c == d;
}

static bool test_minus()
{
	int a = 1 + rand();
	int b = rand();

	std::string sa = std::to_string(a + b);
	std::string sb = std::to_string(b);

	std::string sm = Sieve::modsub(sa, sb, "-");
	int d = std::stoi(sm);

	return a == d;
}

static bool test_cross()
{
	int a = 1 + rand();
	int b = 1 + rand();

	std::string sa = std::to_string(a);
	std::string sb = std::to_string(b);

	std::string sm = Sieve::modcross(sa, sb, "-");
	int d = std::stoi(sm);

	return a * b == d;
}

static bool test_slash()
{
	int a = 1 + rand();
	int b = 1 + rand();

	std::string sa = std::to_string(a);
	std::string sb = std::to_string(b);

	std::string sm = Sieve::modiv(sa, sb);
	int d = std::stoi(sm);

	return a % b == d;
}

int main()
{
	srand(time(NULL));

	for (int i = 0; i < 100000; ++i)
	{
		if (!test_plus())
		{
			std::cout << "Plus Test Failed!" << std::endl;
			return -1;
		}

		if (!test_minus())
		{
			std::cout << "Minus Test Failed!" << std::endl;
			return -1;
		}

		if (!test_cross())
		{
			std::cout << "Cross Test Failed!" << std::endl;
			return -1;
		}

		if (!test_slash())
		{
			std::cout << "Slash Test Failed!" << std::endl;
			return -1;
		}
	}

	std::cout << "Test Passed!" << std::endl;

	return 0;
}