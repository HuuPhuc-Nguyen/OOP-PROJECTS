#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "Manager.h"
#include "IConverter.h"
#include "EmployeeFactory.h"

class ManagerUIConverter : public IConverter
{
public:
	string convert(void* Employee);
	IEmployee* convertBackFromFile(string);
	IEmployee* getInput();
};

