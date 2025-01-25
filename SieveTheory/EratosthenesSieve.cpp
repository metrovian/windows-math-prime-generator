#include "EratosthenesSieve.h"

bool EratosthenesSieve::erase_exist(std::string _min, std::string _max)
{
    std::string num;
    std::string prm;
    std::string ptr;

    while (primes >> prm)
    {
        if (!less(square(prm), _max)) break;

        for (uint64_t i = 0; less(iton(i, _min), _max); ++i)
        {
            if (conds[i])
            {
                num = iton(i, _min);

                if (mod(num, prm) == "0")
                {
                    for (std::string j = num; less(j, _max); j = plus(j, prm))
                    {
                        conds[ntoi(j, _min)] = false;
                    }

                    break;
                }
            }
        }
    }

    primes.clear();
    primes.seekg(0, primes.beg);

    return true;
}

bool EratosthenesSieve::erase_new(std::string _min, std::string _max)
{
    std::string num;

    for (uint64_t i = 0; less(iton(i, _min), _max); ++i)
    {
        if (!conds[i]) continue;

        num = iton(i, _min);

        primes << num << " ";
        ++count;

        for (std::string j = num; less(j, _max); j = plus(j, num))
        {
            conds[ntoi(j, _min)] = false;
        }
    }

    return true;
}