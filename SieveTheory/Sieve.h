#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <limits>

class Sieve 
{
protected: /* data */
	std::stringstream data;
	std::stringstream primes;

protected: /* modular */
	static std::string modiv(const std::string& _num, const std::string& _mod);
	static std::string modplus(const std::string& _num, const std::string& _mum, const std::string& _mod);
	static std::string modsub(const std::string& _num, const std::string& _mum, const std::string& _mod);
	static std::string modcross(const std::string& _num, const std::string& _mum, const std::string& _mod);

protected: /* control */
	bool set(std::string _min, std::string _max);
	bool save(std::string _fname);

public: /* public */
	bool run(std::string _max, std::string _fname);

protected: /* virtual */
	virtual bool step(std::string _max) = 0;
};