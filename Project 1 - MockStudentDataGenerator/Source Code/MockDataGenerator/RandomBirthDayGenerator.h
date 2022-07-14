#pragma once
#include "RandomIntegerGenerator.h"
#include "Date.h"

class RandomBirthDayGenerator {
private:
	RandomIntGenerator _rng;
public:
	RandomBirthDayGenerator() {};
	~RandomBirthDayGenerator() {};
public:
	Date next();
	Date next(int);
};
