#pragma once
#include <time.h>
#include <stdlib.h>

class RandomFloatGenerator {
public:
	RandomFloatGenerator();
	~RandomFloatGenerator();
public:
	float next(int);
	float next(int, int);
};
