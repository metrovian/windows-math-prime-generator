#include "EratosthenesSieve.h"

bool EratosthenesSieve::step(std::string _max)
{
    std::stringstream part;

    std::string num;
    std::string mum;
    std::string prm;
    std::string sqr;

    while (primes >> prm)
    {
        sqr = modcross(num, num, "-");

        if (modsub(_max, sqr, "-").empty()) break;

        while (data >> num)
        {
            if (modiv(num, prm) != "0")
            {
                part << num << " ";
            }
        }

        data.str(part.str());
        data.clear();

        part.str("");
        part.clear();
    }

    primes.clear();
    primes.seekg(0, primes.beg);

    while (data >> num)
    {
        sqr = modcross(num, num, "-");

        if (modsub(_max, sqr, "-").empty()) break;

        primes << num << " ";

        while (data >> mum)
        {
            if (modiv(mum, num) != "0")
            {
                part << mum << " ";
            }
        }

        data.str(part.str());
        data.clear();

        part.str("");
        part.clear();
    }

    primes << data.rdbuf();

    return true;
}
