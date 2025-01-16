#include "EratosthenesSieve.h"

bool EratosthenesSieve::erase_exist(std::string _max)
{
    std::stringstream part;

    std::string num;
    std::string prm;
    std::string sqr;

    while (primes >> prm)
    {
        sqr = modcross(prm, prm, "-");

        if (modsub(_max, sqr, "-").empty()) break;

        while (data >> num)
        {
            if (modiv(num, prm) != "0")
            {
                part << num << " ";
            }
        }

        data.clear();
        data.str(part.str());

        part.clear();
        part.str("");
    }

    primes.clear();
    primes.seekg(0, primes.beg);

    return true;
}

bool EratosthenesSieve::erase_new(std::string _max)
{
    std::stringstream part;

    std::string num;
    std::string mum;
    std::string sqr;

    while (data >> num)
    {
        sqr = modcross(num, num, "-");

        if (modsub(_max, sqr, "-").empty())
        {
            primes << num << " ";
            ++count;

            continue;
        }

        primes << num << " ";
        ++count;

        while (data >> mum)
        {
            if (modiv(mum, num) != "0")
            {
                part << mum << " ";
            }
        }

        data.clear();
        data.str(part.str());

        part.clear();
        part.str("");
    }

    return true;
}

bool EratosthenesSieve::step(std::string _max)
{
    if (!erase_exist(_max)) return false;
    if (!erase_new(_max)) return false;

    return true;
}
