#pragma once
#include <string>
#include <sstream>

using namespace std;

class HCMAddress {
private:
	string _number;
	string _street;
	string _ward;
	string _district;
	string _city;
public:
	string Number() { return _number; }
	string Street() { return _street; }
	string Ward() { return _ward; }
	string District() { return _district; }
	string City() { return _city; }
	void setNumber(string value) { _number = value; }
	void setStreet(string value) { _street = value; }
	void setWard(string value) { _ward = value; }
	void setDistrict(string value) { _district = value; }
	void setCity(string value) { _city = value; }
public:
	HCMAddress(string, string, string, string);
	HCMAddress();
	~HCMAddress();
public:
	void getInput();
	string toString();
};

