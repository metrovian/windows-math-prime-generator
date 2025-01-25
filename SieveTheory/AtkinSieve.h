#pragma once
#include "Sieve.h"

class AtkinSieve : public Sieve
{
protected: /* condition */
	bool reverse_cond1(std::string _nsqr, std::string _msqr, std::string _min, std::string _max);
	bool reverse_cond2(std::string _nsqr, std::string _msqr, std::string _min, std::string _max);
	bool reverse_cond3(std::string _nsqr, std::string _msqr, std::string _min, std::string _max);

protected: /* virtual */
	bool erase_exist(std::string _min, std::string _max) override;
	bool erase_new(std::string _min, std::string _max) override;
};