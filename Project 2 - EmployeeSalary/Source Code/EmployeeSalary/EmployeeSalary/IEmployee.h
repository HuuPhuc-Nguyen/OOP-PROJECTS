#pragma once
#include "Fullname.h"

class IEmployee
{
public:
	virtual double calculateSalary() = 0;
	virtual IEmployee* generate(Fullname, double, double, double) = 0;
	virtual string className() = 0;
};

