#include "DailyEmployee.h"
#include "Fullname.h"

DailyEmployee::DailyEmployee()
{
	_fullname;
	_daysalary = 0;
	_days = 0;
}

DailyEmployee::DailyEmployee(Fullname fullname, double salary, double days)
{
	_fullname = fullname;
	_daysalary = salary;
	_days = days;
}

DailyEmployee::~DailyEmployee() {}

double DailyEmployee::calculateSalary()
{
	double result = _daysalary * _days;

	return result;
}

DailyEmployee* DailyEmployee::generate(Fullname fullname, double salary, double amount, double fixed)
{
	return new DailyEmployee(fullname, salary, amount);
}

string DailyEmployee::className()
{
	string classname = "DailyEmployee";
	return classname;
}

