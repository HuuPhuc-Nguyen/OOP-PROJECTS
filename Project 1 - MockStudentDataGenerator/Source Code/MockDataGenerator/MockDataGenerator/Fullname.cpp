#include "Fullname.h"
#include "StringHelper.h"
#include <iostream>
#include <vector>

using namespace std;

Fullname::Fullname(string first, string middle, string last)
{
	_firstname = first;
	_middlename = middle;
	_lastname = last;
}

Fullname::Fullname()
{
	_firstname = "";
	_middlename = "";
	_lastname = "";
}

Fullname::~Fullname() {}

string Fullname::toString() 
{
	stringstream builder;

	builder << _firstname << " "
		<< _middlename << " "
		<< _lastname;

	string result = builder.str();
	return result;
}

void Fullname::getInput()
{
	string get;
	getline(cin, get);

	vector<string> getName = StringHelper::split(get, " ");

	_firstname = getName[0];
	_lastname = getName[getName.size() - 1];
	
	string getMiddleName = "";
	for (int i = 1; i < getName.size() - 1; i++)
		getMiddleName = getName[i] + ' ';
	getMiddleName = getMiddleName.substr(0, getMiddleName.size() - 1); // ignore the last space

	_middlename = getMiddleName;
}