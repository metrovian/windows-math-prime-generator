#include "EulerSieve.h"

bool EulerSieve::erase_exist(std::string _min, std::string _max)
{
    std::string num = "2";
    std::string mum;
    std::string prm;
    std::string ptr;

    while (modsub(num, _max, "-").empty())
    {
        primes.clear();
        primes.seekg(0, primes.beg);

        while (primes >> prm)
        {
            ptr = modcross(num, prm, "-");

            if (!modsub(ptr, _max, "-").empty()) break;
            if (!modsub(ptr, _min, "-").empty()) conds[std::stoull(modsub(ptr, _min, "-"))] = false;

            if (modiv(num, prm) == "0") break;
        }

        num = modplus(num, "1", "-");
    }

    primes.clear();
    primes.seekg(0, primes.beg);

    return true;
}

bool EulerSieve::erase_new(std::string _min, std::string _max)
{
    std::string num;
    std::string mum;
    std::string prm;
    std::string ptr;

    uint64_t idx = 0;

    while (data >> num)
    {
        if (conds[idx])
        {
            primes << num << " ";
            ++count;
        }

        primes.clear();
        primes.seekg(0, primes.beg);

        while (primes >> prm)
        {
            ptr = modcross(num, prm, "-");

            if (!modsub(ptr, _max, "-").empty()) break;
            else conds[std::stoull(modsub(ptr, _min, "-"))] = false;

            if (modiv(num, prm) == "0") break;
        }

        ++idx;
    }

    primes.clear();
    primes.seekg(0, primes.beg);

    return true;
}