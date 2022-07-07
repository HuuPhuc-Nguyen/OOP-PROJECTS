#pragma once
#include "IEmployee.h"
#include "Fullname.h"

class ProductEmployee : public IEmployee
{
private:
	Fullname _fullname;
	double _productsalary;
	double _products;
public:
	ProductEmployee();
	ProductEmployee(Fullname, double, double);
	~ProductEmployee();
public:
	Fullname FullName() { return _fullname; }
	double ProductSalary() { return _productsalary; }
	double Products() { return _products; }
	void setFullName(Fullname value) { _fullname = value; }
	void setProductSalary(double value) { _productsalary = value; }
	void setProducts(double value) { _products = value; }
public:
	double calculateSalary();
	ProductEmployee* generate(Fullname, double, double, double);
	string className();
};

