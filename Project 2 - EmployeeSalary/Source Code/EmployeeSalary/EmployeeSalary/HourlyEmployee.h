#pragma once
#include "IEmployee.h"
#include "Fullname.h"

class HourlyEmployee : public IEmployee
{
private:
	Fullname _fullname;
	double _hoursalary;
	double _hours;
public:
	HourlyEmployee();
	HourlyEmployee(Fullname, double, double);
	~HourlyEmployee();
public:
	Fullname FullName() { return _fullname; }
	double HourSalary() { return _hoursalary; }
	double Hours() { return _hours; }
	void setFullName(Fullname value) { _fullname = value; }
	void setHourSalary(double value) { _hoursalary = value; }
	void setHours(double value) { _hours = value; }
public:
	double calculateSalary();
	IEmployee* generate(Fullname, double, double, double);
	string className();
};

