#pragma once
#include <string>
#include <sstream>

using namespace std;

class File;

class Fullname {
private:
	string _firstname;
	string _middlename;
	string _lastname;
public:
	string FirstName() { return _firstname; }
	string MiddleName() { return _middlename; }
	string LastName() { return _lastname; }
	void setFirstName(string value) { _firstname = value; }
	void setMiddleName(string value) { _middlename = value; }
	void setLastName(string value) { _lastname = value; }
public:
	Fullname(string, string, string);
	Fullname(string);
	Fullname();
	~Fullname();
public:
	void getInput();
	string toString();
};

