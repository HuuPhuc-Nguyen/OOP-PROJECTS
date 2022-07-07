#pragma once
#include "IEmployee.h"
#include "Fullname.h"

class Manager : public IEmployee
{
private:
	Fullname _fullname;
	double _managementsalary;
	double _employees;
	double _fixedsalary;
public:
	Manager();
	Manager(Fullname, double, double, double);
	~Manager();
public:
	Fullname FullName() { return _fullname; }
	double ManagementSalary() { return _managementsalary; }
	double Empolyees() { return _employees; }
	double FixedSalary() { return _fixedsalary; }
	void setFullName(Fullname value) { _fullname = value; }
	void setManagementSalary(double value) { _managementsalary = value; }
	void setEmployees(double value) { _employees = value; }
	void setFixedSalary(double value) { _fixedsalary = value; }
public:
	double calculateSalary();
	Manager* generate(Fullname, double, double, double);
	string className();
};

