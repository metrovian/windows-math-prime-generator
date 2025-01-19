#include "EulerSieve.h"

bool EulerSieve::erase_exist(std::string _max)
{
    static std::string psv = "2";

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

            if (!modsub(ptr, psv, "-").empty())
            {
                ptr = modsub(ptr, psv, "-");
                conds[std::stoull(ptr)] = false;
            }

            if (modiv(num, prm) == "0") break;
        }

        num = modplus(num, "1", "-");
    }

    psv = modplus(psv, std::to_string(unit), "-");

    primes.clear();
    primes.seekg(0, primes.beg);

    return true;
}

bool EulerSieve::erase_new(std::string _max)
{
    static std::string psv = "2";

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
            else
            {
                ptr = modsub(ptr, psv, "-");
                conds[std::stoull(ptr)] = false;
            }

            if (modiv(num, prm) == "0") break;
        }

        ++idx;
    }

    psv = modplus(psv, std::to_string(unit), "-");

    primes.clear();
    primes.seekg(0, primes.beg);

    return true;
}

bool EulerSieve::step(std::string _max)
{
    if (!erase_exist(_max)) return false;
    if (!erase_new(_max)) return false;

    return true;
}
