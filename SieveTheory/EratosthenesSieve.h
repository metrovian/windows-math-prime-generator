#pragma once
#include "Sieve.h"

class EratosthenesSieve : public Sieve
{
protected: /* parts */
	bool erase_exist(std::string _max);
	bool erase_new(std::string _max);

protected: /* virtual */
	bool step(std::string _max) override;
};