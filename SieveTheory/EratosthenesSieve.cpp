#include "EratosthenesSieve.h"

bool EratosthenesSieve::erase_exist(std::string _max)
{
    std::string num;
    std::string prm;
    std::string sqr;
    std::string ptr;

    uint64_t idx = 0;

    while (primes >> prm)
    {
        sqr = modcross(prm, prm, "-");
        idx = 0;

        if (!modsub(sqr, _max, "-").empty()) break;

        while (data >> num)
        {
            if (!conds[idx]) 
            { 
                ++idx; continue; 
            }

            if (modiv(num, prm) == "0") 
            {
                ptr = std::to_string(idx);

                while (idx < unit)
                {
                    conds[idx] = false;

                    ptr = modplus(ptr, prm, "-");

                    if (!modsub(ptr, _max, "-").empty()) break;
                    else idx = std::stoull(ptr);
                }

                break;
            }

            else ++idx;
        }

        data.clear();
        data.seekg(0, data.beg);
    }

    primes.clear();
    primes.seekg(0, primes.beg);

    return true;
}

bool EratosthenesSieve::erase_new(std::string _max)
{
    std::string num;
    std::string mum;
    std::string ptr;

    uint64_t idx = 0;
    uint64_t jdx = 0;

    while (data >> num)
    {
        if (!conds[idx])
        {
            ++idx; continue;
        }

        if (!modsub(modcross(num, num, "-"), _max, "-").empty())
        {
            primes << num << " ";
            ++count;

            ++idx; continue;
        }

        primes << num << " ";
        ++count;

        ptr = std::to_string(idx);
        jdx = idx++;
       
        while (jdx < unit)
        {
            conds[jdx] = false;

            ptr = modplus(ptr, num, "-");

            if (!modsub(ptr, _max, "-").empty()) break;
            else jdx = std::stoull(ptr);
        }
    }

    return true;
}

bool EratosthenesSieve::step(std::string _max)
{
    if (!erase_exist(_max)) return false;
    if (!erase_new(_max)) return false;

    return true;
}
