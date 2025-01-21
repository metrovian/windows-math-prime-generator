#pragma once
#include "Sieve.h"

class AtkinSieve : public Sieve
{
protected: /* virtual */
	bool erase_exist(std::string _min, std::string _max) override;
	bool erase_new(std::string _min, std::string _max) override;
};