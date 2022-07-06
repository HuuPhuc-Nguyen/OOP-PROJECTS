#pragma once
#include "RandomIntegerGenerator.h"
#include "Fullname.h"
#include "File.h"
#include "StringHelper.h"

class RandomEmailGenerator
{
private:
	RandomIntGenerator _rng;
	vector<string> _domain;
public:
	RandomEmailGenerator(string);
	RandomEmailGenerator();
	~RandomEmailGenerator();
public:
	string next(Fullname);
};


