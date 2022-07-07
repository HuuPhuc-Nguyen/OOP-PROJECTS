#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "HourlyEmployee.h"
#include "IConverter.h"
#include "EmployeeFactory.h"
using namespace std;

class HourlyEmployeeUIConverter : public IConverter
{
public:
	string convert(void* Employee);
	IEmployee* convertBackFromFile(string);
	IEmployee* getInput();
};

