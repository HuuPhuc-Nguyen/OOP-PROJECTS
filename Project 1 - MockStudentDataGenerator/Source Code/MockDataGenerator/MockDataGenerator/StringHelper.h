#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "Student.h"
using namespace std;

class StringHelper {
public:
	static void getLowerCase(string&);
	static vector<string> split(string, string);
	static string vectorStudentToString(vector<Student>);
};

