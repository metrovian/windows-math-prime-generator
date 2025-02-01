#pragma once
#include "Sieve.h"

class PritchardSieve : public Sieve
{
protected: /* overload */
	static bool greater_pair(const std::pair<std::string, std::string>& _num, const std::pair<std::string, std::string>& _min);

protected: /* virtual */
	bool process_pre(std::string _min, std::string _max) override;
	bool process_post(std::string _min, std::string _max) override;
};