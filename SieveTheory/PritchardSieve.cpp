#include "PritchardSieve.h"

bool PritchardSieve::greater_pair(const std::pair<std::string, std::string>& _num, const std::pair<std::string, std::string>& _min)
{
	return greater(_num.first, _min.first);
}

bool PritchardSieve::process_pre(std::string _min, std::string _max)
{
	return true;
}

bool PritchardSieve::process_post(std::string _min, std::string _max)
{
	static std::unordered_map<std::string, std::string> cpm;
	static std::priority_queue
		<
			std::pair<std::string, std::string>,
			std::vector<std::pair<std::string, std::string>>,
			decltype(&PritchardSieve::greater_pair)
		> cps(&PritchardSieve::greater_pair);

	std::pair<std::string, std::string> next;

	for (std::string i = _min; less(i, _max); i = increase(i))
	{
		if (cpm[i].empty())
		{
			next = std::make_pair(square(i), i);

			primes << i << " ";
			++count;

			cps.push(next);
			cpm.insert(next);
		}

		else
		{
			while (!cps.empty())
			{
				if (cps.top().first != i) break;

				std::string cmp = cps.top().first;
				std::string prm = cps.top().second;

				next = std::make_pair(plus(cmp, prm), prm);

				cps.pop();
				cps.push(next);
				cpm.insert(next);
			}

			cpm.erase(i);
		}
	}

	return true;
}
