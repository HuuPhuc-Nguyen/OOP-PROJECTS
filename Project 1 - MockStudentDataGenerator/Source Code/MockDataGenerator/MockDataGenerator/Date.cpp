#include "Date.h"
#include "StringHelper.h"
#include <string>
#include <iostream>
using namespace std;

Date::Date(int day, int month, int year)
{
	_day = day;
	_month = month;
	_year = year;
}

Date::Date()
{
	_day = 0;
	_month = 0;
	_year = 0;
}

Date::~Date() {};

void Date::getInput()
{
	string get;
	getline(cin, get);

	vector<string> getDate = StringHelper::split(get, "/");

	_day = stoi(getDate[0]);
	_month = stoi(getDate[1]);
	_year = stoi(getDate[2]);
}

string Date::toString()
{
	stringstream builder;

	if (_day < 10)
	{
		if (_month < 10)
			builder << "0" << _day << "/" << "0" << _month << "/" << _year;
		else
			builder << "0" << _day << "/" << _month << "/" << _year;
	}
	else
	{
		if (_month < 10)
			builder << _day << "/" << "0" << _month << "/" << _year;
		else
			builder << _day << "/" << _month << "/" << _year;
	}
	return builder.str();
}

int Date::dayOfMonth(int month, int year)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
	{
		if (isLeapYear(year))
			return 29;
		else return 28;
	}
	}
}

int Date::isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	return 0;
}