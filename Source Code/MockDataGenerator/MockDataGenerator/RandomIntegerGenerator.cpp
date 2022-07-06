#include "RandomIntegerGenerator.h"

RandomIntGenerator::RandomIntGenerator() 
{
	srand(time(NULL)); 
}

RandomIntGenerator::~RandomIntGenerator() {}

int RandomIntGenerator::next() 
{ 
	return rand(); 
}

int RandomIntGenerator::next(int right) 
{ 
	return rand() % right; 
}

int RandomIntGenerator::next(int left, int right) 
{ 
	return rand() % (right - left + 1) + left;
}