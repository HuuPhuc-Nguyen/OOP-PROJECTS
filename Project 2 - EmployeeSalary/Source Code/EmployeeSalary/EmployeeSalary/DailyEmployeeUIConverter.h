#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "DailyEmployee.h"
#include "IConverter.h"
#include "EmployeeFactory.h"
using namespace std;

class DailyEmployeeUIConverter : public IConverter
{
public:
	string convert(void* Employee);
	IEmployee* convertBackFromFile(string);
	IEmployee* getInput();
};

