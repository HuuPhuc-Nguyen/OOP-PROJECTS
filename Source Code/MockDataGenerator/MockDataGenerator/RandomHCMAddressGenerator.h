#pragma once
#include "HCMAddress.h"
#include "RandomIntegerGenerator.h"
#include "StringHelper.h"
#include "File.h"

class RandomHCMAddressGenerator {
private:
	RandomIntGenerator _rng;
	vector<string> _number;
	vector<string> _street;
	vector<string> _ward;
	vector<string> _district;
	vector<string> _city;
public:
	RandomHCMAddressGenerator(string);
	RandomHCMAddressGenerator();
	~RandomHCMAddressGenerator();
public:
	HCMAddress next();
};

