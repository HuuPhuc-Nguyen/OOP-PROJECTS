#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <time.h>
#include <stdlib.h>

class RandomIntGenerator {
public:
	RandomIntGenerator();
	~RandomIntGenerator();
public:
	int next();
	int next(int);
	int next(int, int);
};


