#include "Sieve.h"

std::string Sieve::modiv(const std::string& _num, const std::string& _mod)
{
	if (_num.empty() || _mod.empty()) return "0";
    return _num;
}

std::string Sieve::modmult(const std::string& _num, const std::string& _mum, const std::string& _mod)
{
    return std::string();
}

std::string Sieve::modplus(const std::string& _num, const std::string& _mum, const std::string& _mod)
{
    uint64_t nlen = _num.length();
    uint64_t mlen = _mum.length();

	uint64_t plen = std::min(nlen, mlen);
	uint64_t flen = std::max(nlen, mlen) + 1;

    std::string ret(flen, '0');

	for (uint64_t i = 0; i < plen; ++i)
	{
		char num = _num[nlen - i - 1] - '0';
		char mum = _mum[mlen - i - 1] - '0';

		char res = num + mum;

		ret[flen - i - 1] += res % 10;
		ret[flen - i - 2] += res / 10;

		if (ret[flen - i - 1] > 57)
		{
			ret[flen - i - 1] -= 10;
			ret[flen - i - 2] += 1;
		}
	}

	if (mlen == plen)
	{
		for (uint64_t i = plen; i < flen - 1; ++i)
		{
			ret[flen - i - 1] += _num[flen - i - 2] - '0';

			if (ret[flen - i - 1] > '9')
			{
				ret[flen - i - 1] -= 10;
				ret[flen - i - 2] += 1;
			}
		}
	}

	else
	{
		for (uint64_t i = plen; i < flen - 1; ++i)
		{
			ret[flen - i - 1] += _mum[flen - i - 2] - '0';

			if (ret[flen - i - 1] > '9')
			{
				ret[flen - i - 1] -= 10;
				ret[flen - i - 2] += 1;
			}
		}
	}

	ret.erase(0, ret.find_first_not_of('0'));
	ret.shrink_to_fit();

	return modiv(ret, _mod);
}

std::string Sieve::modsub(const std::string& _num, const std::string& _mum, const std::string& _mod)
{

    return std::string();
}
