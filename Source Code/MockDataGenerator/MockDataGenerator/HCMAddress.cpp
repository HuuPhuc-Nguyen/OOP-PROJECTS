#include "HCMAddress.h"
#include <iostream>

using namespace std;

HCMAddress::HCMAddress(string number, string street, string ward, string district)
{
	_number = number;
	_street = street;
	_ward = ward;
	_district = district;
	_city = "Ho Chi Minh";
}

HCMAddress::HCMAddress()
{
	_number = "";
	_street = "";
	_ward = "";
	_district = "";
	_city = "Ho Chi Minh";
}

HCMAddress::~HCMAddress() {}

void HCMAddress::getInput()
{
	cout << "Enter house number: ";
	getline(cin, _number);
	cout << "Enter street: ";
	getline(cin, _street);
	cout << "Enter ward: ";
	getline(cin, _ward);
	cout << ("Enter district: ");
	getline(cin, _district);
}

string HCMAddress::toString()
{
	stringstream builder;

	builder << _number << " " << _street
		<< ",Ward " << _ward
		<< ",District " << _district
		<< "," << _city << " city";

	return builder.str();
}