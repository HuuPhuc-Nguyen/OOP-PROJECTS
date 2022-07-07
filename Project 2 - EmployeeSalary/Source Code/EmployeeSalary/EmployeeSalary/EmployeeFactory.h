#pragma once
#include <vector>
#include "IEmployee.h"
#include "DailyEmployee.h"
#include "HourlyEmployee.h"
#include "ProductEmployee.h"
#include "Manager.h"
#include "Fullname.h"

using namespace std;

class EmployeeFactory
{
private:
	static EmployeeFactory* _instance;
	vector<IEmployee*> _prototypes;
	EmployeeFactory();
public:
	int typeEmployees();
	static EmployeeFactory* instance();
	IEmployee* create(int,Fullname, double, double, double);
};

