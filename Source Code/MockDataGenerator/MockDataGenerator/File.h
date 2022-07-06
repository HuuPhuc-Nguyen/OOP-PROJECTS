#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Fullname.h"
#include "HCMAddress.h"
#include "Date.h"
#include "Student.h"

using namespace std;

class File {
public:
	static vector<string> readRowInFile(string);
	static vector<Student> readStudentFile(string);
	static void overwriteStudentFile(vector<Student>,string);
};

