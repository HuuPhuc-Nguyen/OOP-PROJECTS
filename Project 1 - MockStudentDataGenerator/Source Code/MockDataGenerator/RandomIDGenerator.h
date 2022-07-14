#pragma once
#include "RandomIntegerGenerator.h"
#include <string>

using namespace std;

class RandomIDGenerator {
private:
	RandomIntGenerator _rng;
public:
	string next();
};


