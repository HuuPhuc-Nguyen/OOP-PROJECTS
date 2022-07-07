#include "Float.h"

RandomFloatGenerator::RandomFloatGenerator()
{ 
	srand(time(NULL)); 
}

RandomFloatGenerator::~RandomFloatGenerator() {}

float RandomFloatGenerator::next(int max)
{
	return (float)rand() / (RAND_MAX / max); 
}

float RandomFloatGenerator::next(int left, int right) 
{
	return left + ((float)rand() / (RAND_MAX / (right - left))); 
}