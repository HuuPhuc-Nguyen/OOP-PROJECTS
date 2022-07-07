#pragma once
#include "IEmployee.h"
#include "Fullname.h"

class DailyEmployee : public IEmployee
{
private:
	Fullname _fullname;
	double _daysalary;
	double _days;
public:
	DailyEmployee();
	DailyEmployee(Fullname, double, double);
	~DailyEmployee();
public:
	Fullname FullName() { return _fullname; }
	double DaySalary() { return _daysalary; }
	double Days() { return _days; }
	void setFullName(Fullname value) { _fullname = value; }
	void setDaySalary(double value) { _daysalary = value; }
	void setDays(double value) { _days = value; }
public:
	double calculateSalary();
	DailyEmployee* generate(Fullname, double, double, double);
	string className();
};

