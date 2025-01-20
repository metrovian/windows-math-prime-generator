#pragma once
#include "Sieve.h"

class AtkinSieve : public Sieve
{
protected: /* virtual */
	bool step(std::string _max) override;
};