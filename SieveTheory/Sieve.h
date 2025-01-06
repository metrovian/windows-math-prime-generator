#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

class Sieve 
{
protected: /* data */
	std::ofstream data;

protected: /* modular */
public:
	static std::string modiv(const std::string& _num, const std::string& _mod);
	static std::string modmult(const std::string& _num, const std::string& _mum, const std::string& _mod);
	static std::string modplus(const std::string& _num, const std::string& _mum, const std::string& _mod);
	static std::string modsub(const std::string& _num, const std::string& _mum, const std::string& _mod);

public: /* virtual */
	//virtual bool run(std::string _max, std::string _out) = 0;
};