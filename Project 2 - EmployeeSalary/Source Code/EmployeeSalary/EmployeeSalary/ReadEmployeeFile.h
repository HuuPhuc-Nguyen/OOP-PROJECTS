#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "Fullname.h"
#include "IEmployee.h"
#include "EmployeeFactory.h"
using namespace std;

vector<IEmployee*> readEmFile(string Filename);