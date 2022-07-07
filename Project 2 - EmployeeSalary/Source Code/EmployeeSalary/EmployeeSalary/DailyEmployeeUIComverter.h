#pragma once
#include <string>
#include <sstream>
#include "DailyEmployee.h"
#include "IConverter.h"
using namespace std;

class DailyEmployeeUIComverter : public IConverter
{
public:
	string convert(void* Employee);
};

