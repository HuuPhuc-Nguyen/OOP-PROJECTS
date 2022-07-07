#include "Manager.h"

Manager::Manager()
{
	_fullname;
	_managementsalary = 0;
	_employees = 0;
	_fixedsalary = 0;
}

Manager::Manager(Fullname fullname, double salary, double employees, double fixed)
{
	_fullname = fullname;
	_managementsalary = salary;
	_employees = employees;
	_fixedsalary = fixed;
}

Manager::~Manager() {}

double Manager::calculateSalary()
{
	double result = _managementsalary * _employees + _fixedsalary;

	return result;
}

Manager* Manager::generate(Fullname fullname,double salary, double amount, double fixed)
{
	return new Manager(fullname, salary, amount, fixed);
}

string Manager::className()
{
	string classname = "Manager";
	return classname;
}

