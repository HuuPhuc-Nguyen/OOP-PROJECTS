#include "Student.h"
#include <iomanip>
#include <iostream>

using namespace std;

Student::Student(string id, Fullname name, float gpa, string phone, string email, Date dob, HCMAddress addr)
{
	_id = id;
	_fullname = name;
	_gpa = gpa;
	_phone = phone;
	_email = email;
	_dob = dob;
	_addr = addr;
}

Student::Student() 
{
	_id = "";
	_fullname; // constructor is called when create object student
	_gpa = 0;
	_phone = "";
	_email;
	_dob;
	_addr;
}

Student::~Student() {}

void Student::getInput()
{
	cout << "Enter ID: "; 
	cin >> _id;
	cout << "Enter FullName: "; 
	_fullname.getInput();
	cout << "Enter GPA: "; 
	cin >> _gpa;
	cout << "Enter Telephone: "; 
	cin >> _phone;
	cout << "Enter Email: "; 
	cin >> _email;
	cout << "Enter DOB: "; 
	_dob.getInput();
	cout << "Enter Address: ";
	_addr.getInput();
}

string Student::toString()
{
	stringstream builder;

	builder << "Student=" << _id << endl
		<< "Name=" << _fullname.toString() << endl
		<< "GPA=" << setprecision(2) << fixed << _gpa << endl
		<< "Telephone=" << _phone << endl
		<< "Email=" << _email << endl
		<< "DOB=" << _dob.toString() << endl
		<< "Address=" << _addr.toString() << endl;

	return builder.str();
}