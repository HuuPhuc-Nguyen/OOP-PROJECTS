#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "ProductEmployee.h"
#include "IConverter.h"
#include "EmployeeFactory.h"
using namespace std;

class ProductEmployeeUIConverter : public IConverter
{
public:
	string convert(void* Employee);
	IEmployee* convertBackFromFile(string);
	IEmployee* getInput();
};

