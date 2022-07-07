#include "EmployeeFactory.h"
#include <cstdlib>

EmployeeFactory* EmployeeFactory::_instance = NULL;

int EmployeeFactory::typeEmployees()
{
	return _prototypes.size();
}

EmployeeFactory* EmployeeFactory::instance()
{
	if (_instance == NULL)
		_instance = new EmployeeFactory;
	
	return _instance;
}

EmployeeFactory::EmployeeFactory()
{
	_prototypes.push_back(new DailyEmployee);
	_prototypes.push_back(new HourlyEmployee);
	_prototypes.push_back(new ProductEmployee);
	_prototypes.push_back(new Manager);
}

IEmployee* EmployeeFactory::create(int type,Fullname fullname, double salary, double amount, double fixed)
{
	IEmployee* employee = _prototypes[type]->generate(fullname, salary, amount, fixed);

	return employee;
}