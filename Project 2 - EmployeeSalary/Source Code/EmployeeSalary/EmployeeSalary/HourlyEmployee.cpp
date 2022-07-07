#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee()
{
	_fullname;
	_hoursalary = 0;
	_hours = 0;
}

HourlyEmployee::HourlyEmployee(Fullname fullname, double salary, double hours)
{
	_fullname = fullname;
	_hoursalary = salary;
	_hours = hours;
}

HourlyEmployee::~HourlyEmployee() {}

double HourlyEmployee::calculateSalary()
{
	double result = _hoursalary * _hours;

	return result;
}

IEmployee* HourlyEmployee::generate(Fullname fullname, double salary, double amount, double fixed)
{
	return new HourlyEmployee(fullname, salary, amount);
}

string HourlyEmployee::className()
{
	string classname = "HourlyEmployee";
	return classname;
}

