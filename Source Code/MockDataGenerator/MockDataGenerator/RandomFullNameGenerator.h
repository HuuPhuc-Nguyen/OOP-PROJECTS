#pragma once
#include "RandomIntegerGenerator.h"
#include "Fullname.h"
#include "StringHelper.h"
#include "File.h"

class RandomFullNameGenerator {
private:
	RandomIntGenerator _rng;
	vector<string> _firstname;
	vector<string> _middlename;
	vector<string> _lastname;
public:
	RandomFullNameGenerator(string);
	RandomFullNameGenerator();
	~RandomFullNameGenerator();
public:
	Fullname next();
};

