#include "AtkinSieve.h"

bool AtkinSieve::erase_exist(std::string _min, std::string _max)
{
    return true;
}

bool AtkinSieve::erase_new(std::string _min, std::string _max)
{
    if (_min == "2")
    {
        if (!modsub(_max, "2", "-").empty()) conds[0] = false;
        if (!modsub(_max, "3", "-").empty()) conds[1] = false;
    }

    for (std::string i = "1"; modsub(modcross(i, i, "-"), _max, "-").empty(); i = modplus(i, "1", "-"))
    {
        for (std::string j = "1"; modsub(modcross(j, j, "-"), _max, "-").empty(); j = modplus(j, "1", "-"))
        {
            std::string num;
            std::string cand;
            
            num = modplus
            (
                modcross(modcross(i, i, "-"), "4", "-"), 
                modcross(j, j, "-"), "-"
            );

            if (!modsub(num, _min, "-").empty() && modsub(num, _max, "-").empty())
            {
                cand = modiv(num, "12");

                if (cand == "1" || cand == "5")
                {
                    conds[std::stoull(modsub(num, _min, "-"))] = !conds[std::stoull(modsub(num, _min, "-"))];
                }
            }

            num = modplus
            (
                modcross(modcross(i, i, "-"), "3", "-"),
                modcross(j, j, "-"), "-"
            );

            if (!modsub(num, _min, "-").empty() && modsub(num, _max, "-").empty())
            {
                cand = modiv(num, "12");

                if (cand == "7")
                {
                    conds[std::stoull(modsub(num, _min, "-"))] = !conds[std::stoull(modsub(num, _min, "-"))];
                }
            }

            num = modsub
            (
                modcross(modcross(i, i, "-"), "3", "-"),
                modcross(j, j, "-"), "-"
            );

            if (num.empty()) continue;

            if (modsub(j, i, "-").empty() && !modsub(num, _min, "-").empty() && modsub(num, _max, "-").empty())
            {
                cand = modiv(num, "12");

                if (cand == "11")
                {
                    conds[std::stoull(modsub(num, _min, "-"))] = !conds[std::stoull(modsub(num, _min, "-"))];
                }
            }
        }
    }

    for (std::string i = _min; modsub(i, _max, "-").empty(); i = modplus(i, "1", "-"))
    {
        if (!conds[std::stoull(modsub(i, _min, "-"))])
        {
            for (std::string j = modcross(i, i, "-"); modsub(j, _max, "-").empty(); j = modplus(j, modcross(i, i, "-"), "-"))
            {
                conds[std::stoull(modsub(j, _min, "-"))] = true;
            }
        }
    }

    std::string prm;

    while (primes >> prm)
    {
        std::string mul = modcross(prm, prm, "-");
        std::string sqr = mul;

        while (modsub(mul, _max, "-").empty())
        {
            if (!modsub(mul, _min, "-").empty())
            {
                conds[std::stoull(modsub(mul, _min, "-"))] = true;
            }

            mul = modplus(mul, sqr, "-");
        }
    }

    primes.clear();
    primes.seekg(0, primes.beg);

    for (uint64_t i = 0; i < unit; ++i)
    {
        if (!modsub(modplus(std::to_string(i), _min, "-"), _max, "-").empty()) break;

        if (!conds[i])
        {
            primes << modplus(_min, std::to_string(i), "-") << " ";
            ++count;
        }
    }

    return true;
}