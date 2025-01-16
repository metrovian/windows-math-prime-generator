#pragma once
#include "Sieve.h"

class EratosthenesSieve : public Sieve
{
protected: /* virtual */
	bool step(std::string _max) override;
};