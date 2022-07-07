#include "ProductEmployee.h"

ProductEmployee::ProductEmployee()
{
	_fullname;
	_productsalary = 0;
	_products = 0;
}

ProductEmployee::ProductEmployee(Fullname fullname, double salary, double products)
{
	_fullname = fullname;
	_productsalary = salary;
	_products = products;
}

ProductEmployee::~ProductEmployee() {}

double ProductEmployee::calculateSalary()
{
	double result = _productsalary * _products;

	return result;
}

ProductEmployee* ProductEmployee::generate(Fullname fullname, double salary, double amount, double fixed)
{
	return new ProductEmployee(fullname, salary, amount);
}

string ProductEmployee::className()
{
	string classname = "ProductEmployee";
	return classname;
}


