#include "Sieve.h"

std::string Sieve::modiv(const std::string& _num, const std::string& _mod)
{
	if (_num.empty() || _mod.empty()) return "";

	if (_mod == "0") return "";
	if (_mod == "1") return "0";

	if (_mod == "-") return _num;

	try
	{
		uint64_t num = std::stoull(_num);
		uint64_t mod = std::stoull(_mod);
		
		return std::to_string(num % mod);
	}

	catch (const std::out_of_range& err)
	{
		std::string ret = "";

		uint64_t nlen = _num.length();
		uint64_t mlen = _mod.length();

		for (uint64_t i = 0; i < nlen; ++i)
		{
			ret.push_back(_num[i]);
			ret.erase(0, ret.find_first_not_of('0'));

			if (ret.empty()) ret = "0";

			if (modsub(ret, _mod, "-").empty()) continue;

			for (uint64_t j = 9; j > 0; --j)
			{
				std::string sub = modcross(_mod, std::to_string(j), "-");
				std::string res = modsub(ret, sub, "-");

				if (!res.empty())
				{
					ret = res;
					break;
				}
			}
		}

		return ret;
	}
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

		if (ret[flen - i - 1] > '9')
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
	uint64_t nlen = _num.length();
	uint64_t mlen = _mum.length();

	if (nlen < mlen) return modiv("", _mod);

	if (nlen == mlen)
	{
		if (_num == _mum) return modiv("0", _mod);

		for (uint64_t i = 0; i < mlen; ++i)
		{
			if (_num[i] < _mum[i]) return modiv("", _mod);
			if (_num[i] > _mum[i]) break;
		}
	}

	uint64_t plen = std::min(nlen, mlen);
	uint64_t flen = std::max(nlen, mlen) + 1;

	std::string ret(flen, '0');

	for (uint64_t i = 0; i < plen; ++i)
	{
		char num = _num[nlen - i - 1] - '0';
		char mum = _mum[mlen - i - 1] - '0';

		char res = num - mum;

		ret[flen - i - 1] += res;

		if (res < 0)
		{
			ret[flen - i - 1] += 10;
			ret[flen - i - 2] -= 1;
		}

		if (ret[flen - i - 1] < '0')
		{
			ret[flen - i - 1] += 10;
			ret[flen - i - 2] -= 1;
		}
	}

	for (uint64_t i = plen; i < flen - 1; ++i)
	{
		ret[flen - i - 1] += _num[flen - i - 2] - '0';

		if (ret[flen - i - 1] < '0')
		{
			ret[flen - i - 1] += 10;
			ret[flen - i - 2] -= 1;
		}
	}

	ret.erase(0, ret.find_first_not_of('0'));
	ret.shrink_to_fit();

	return modiv(ret, _mod);
}

std::string Sieve::modcross(const std::string& _num, const std::string& _mum, const std::string& _mod)
{
	uint64_t nlen = _num.length();
	uint64_t mlen = _mum.length();

	try
	{
		uint64_t tnum = std::stoull(_num);
		uint64_t tmum = std::stoull(_mum);

		return modiv(std::to_string(tnum * tmum), _mod);
	}

	catch (const std::out_of_range& err)
	{
		std::string ret = "";
		std::string rep = "";
		std::string req = "";

		for (uint64_t i = 0; i < nlen; ++i)
		{
			req.resize(mlen + 1, '0');

			for (uint64_t j = 0; j < mlen; ++j)
			{
				char num = _num[nlen - i - 1] - '0';
				char mum = _mum[mlen - j - 1] - '0';

				char res = num * mum;

				req[mlen - j] += res % 10;
				req[mlen - j - 1] += res / 10;

				if (req[mlen - j] > '9')
				{
					req[mlen - j] -= 10;
					req[mlen - j - 1] += 1;
				}
			}

			ret = modplus(ret, req + rep, _mod);

			rep.push_back('0');
			req.clear();
		}

		ret.erase(0, ret.find_first_not_of('0'));
		ret.shrink_to_fit();

		return modiv(ret, _mod);
	}
}

bool Sieve::set(std::string _min, std::string _max)
{
	std::string num = _min;

	conds.clear();
	conds.resize(unit, true);

	data.clear();
	data.str("");

	while (modsub(num, _max, "-").empty())
	{
		data << num << " ";
		num = modplus(num, "1", "-");
	}

	return true;
}

bool Sieve::select(std::string _min, std::string _max)
{
	if (!erase_exist(_min, _max)) return false;
	if (!erase_new(_min, _max)) return false;

	return true;
}

bool Sieve::save(std::string _fname)
{
	std::ofstream ofs(_fname);
	
	if (ofs.is_open())
	{
		ofs << primes.rdbuf();
		ofs.close();

		return true;
	}

	return false;
}

bool Sieve::run(std::string _max, std::string _fname)
{
	std::string min = std::to_string(2);
	std::string max = std::to_string(2 + unit);

	std::string rep = modplus(_max, "1", "-");

	bool cond = true;

	while (cond)
	{
		if (modsub(rep, max, "-").empty())
		{
			cond = false;
			max = rep;
		}

		set(min, max);
		select(min, max);

		std::cout << "pi(" << modsub(max, "1", "-") << ") = " << count << std::endl;

		min = max;
		max = modplus(max, std::to_string(unit), "-");
	}

	return save(_fname);
}
