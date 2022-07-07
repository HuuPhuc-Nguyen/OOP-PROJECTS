#pragma once
#include "File.h"
#include "RandomIntegerGenerator.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class RandomPhoneGenerator {
private:
	RandomIntGenerator _rng;
	vector<string> _head;
public:
	RandomPhoneGenerator(string);
	RandomPhoneGenerator();
	~RandomPhoneGenerator();
public:
	string next();
};

