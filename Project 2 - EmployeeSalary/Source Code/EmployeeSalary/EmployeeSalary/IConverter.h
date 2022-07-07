#pragma once
#include <string>
#include "IEmployee.h"
using namespace std;

class IConverter
{
public:
	virtual string convert(void* Employee) = 0;
	virtual IEmployee* convertBackFromFile(string) = 0;
	virtual IEmployee* getInput() = 0;
};

