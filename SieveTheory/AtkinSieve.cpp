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

            if (modsub(_min, num, "-").empty() && modsub(num, _max, "-").empty())
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

            if (modsub(_min, num, "-").empty() && modsub(num, _max, "-").empty())
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

            if (modsub(j, i, "-").empty() && modsub(_min, num, "-").empty() && modsub(num, _max, "-").empty())
            {
                cand = modiv(num, "12");

                if (cand == "11")
                {
                    conds[std::stoull(modsub(num, _min, "-"))] = !conds[std::stoull(modsub(num, _min, "-"))];
                }
            }
        }
    }

    for (uint64_t i = 3; i < unit; ++i)
    {
        if (!conds[i])
        {
            for (uint64_t j = (i + 2) * (i + 2); j < unit; j += (i + 2) * (i + 2))
            {
                conds[j - 2] = true;
            }
        }
    }

    for (uint64_t i = 0; i < unit; ++i)
    {
        if (!conds[i])
        {
            primes << modplus(_min, std::to_string(i), "-") << " ";
            ++count;
        }
    }

    return true;
}