#pragma once
#include "Float.h"

class RandomGradeGenerator {
private:
	RandomFloatGenerator _rng;
public:
	float next(); 
};

