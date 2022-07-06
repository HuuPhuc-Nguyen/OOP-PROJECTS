#pragma once
#include "Fullname.h"
#include "Date.h"
#include "HCMAddress.h"
#include <string>

using namespace std;

class Student {
private:
	string _id;
	Fullname _fullname;
	float _gpa;
	string _phone;
	string _email;
	Date _dob;
	HCMAddress _addr;
public:
	string ID() { return _id; }
	Fullname FullName() { return _fullname; }
	float GPA() { return _gpa; }
	string Phone() { return _phone; }
	string Email() { return _email; }
	Date DOB() { return _dob; }
	HCMAddress Address() { return _addr; }
	void setID(string value) { _id = value; }
	void setFullName(Fullname value) { _fullname = value; }
	void setGPA(float value) { _gpa = value; }
	void setPhone(string value) { _phone = value; }
	void setEmail(string value) { _email = value; }
	void setDOB(Date value) { _dob = value; }
	void setAddress(HCMAddress value) { _addr = value; }
public:
	Student(string, Fullname, float, string, string, Date, HCMAddress);
	Student();
	~Student();
public:
	void getInput();
	string toString();
};

