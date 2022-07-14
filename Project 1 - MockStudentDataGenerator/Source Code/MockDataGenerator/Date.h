#pragma once
#include <string>
#include <sstream>

using namespace std;

class Date {
private:
	int _day;
	int _month;
	int _year;
public:
	int Day() { return _day; }
	int Month() { return _month; }
	int Year() { return _year; }
	void setDay(int value) { _day = value; }
	void setMonth(int value) { _month = value; }
	void setYear(int value) { _year = value; }
public:
	Date(int, int, int);
	Date();
	~Date();
public:
	void getInput();
	string toString();
	static int dayOfMonth(int, int);
	static int isLeapYear(int);
};

