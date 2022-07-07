#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <windows.h>
#include <regex>
#include <fstream>
#include <iomanip>
using namespace std;

#include "IEmployee.h"
#include "DailyEmployee.h"
#include "HourlyEmployee.h"
#include "ProductEmployee.h"
#include "Manager.h"

#include "EmployeeFactory.h"

#include "IConverter.h"
#include "DailyEmployeeUIConverter.h"
#include "HourlyEmployeeUIConverter.h"
#include "ManagerUIConverter.h"
#include "ProductEmployeeUIConverter.h"

struct {
	vector<IEmployee*> employees;
} state;



// Cấu hình GUI converter
map <string, IConverter*> ui{
	{(new DailyEmployee)->className(), new DailyEmployeeUIConverter},
	{(new HourlyEmployee)->className(), new HourlyEmployeeUIConverter},
	{(new ProductEmployee)->className(), new ProductEmployeeUIConverter},
	{(new Manager)->className(), new ManagerUIConverter}
};

// Cấu hình Input converter
map <string, IConverter*> inputui{
	{"DailyEmployee", new DailyEmployeeUIConverter},
	{"HourlyEmployee", new HourlyEmployeeUIConverter},
	{"ProductEmployee", new ProductEmployeeUIConverter},
	{"Manager", new ManagerUIConverter}
};

vector<IEmployee*> readEmFile(string Filename)
{
	vector<IEmployee*> result;
	fstream f;
	string get;

	f.open(Filename);

	while (!f.is_open())
	{
		cout << "Cannot open File. Please check the file name again. File name must have format as (MonthYear.txt)" << endl << endl;
		Sleep(1000);
		system("cls");
		cout << "Input FileName: ";
		getline(cin, Filename);
		f.open(Filename);
	}

	if (f.is_open())
	{
		do
		{
			getline(f, get, ':');
			IConverter* converter = inputui[get];

			// Get string data from file then convert that string to IEmployee*
			stringstream builder;

				// Get first line
			getline(f, get);
			builder << get << endl;
				// Get secong line
			getline(f, get);
			builder << get;

				// Convert From String to IEmployee*
			IEmployee* temp = converter->convertBackFromFile(builder.str());

			result.push_back(temp);

		} while (!f.eof());
	}
	f.close();

	return result;
}


tuple<bool, int, string, int> getChoose()
{
	bool success = 0;
	int errorCode = 0;
	string msg = "";
	int data = 0;

	string buffer;
	getline(cin, buffer);

	if (buffer.size() == 0)
	{
		errorCode = 1;
		msg = "Eror: Empty Input.";
	}
	else
	{
		string pattern = "\\d+";
		if (regex_match(buffer, regex(pattern)))
		{
			data = stoi(buffer);
			if (data < 1 || data > 3)
			{
				errorCode = 2;
				msg = "Error: Not Exist Selection.";
			}
			else
			{
				success = 1;
			}
		}
		else
		{
			errorCode = 3;
			msg = "Error: Invalid Number Format.";
		}
	}

	auto result = make_tuple(success, errorCode, msg, data);

	return result;
}


void main()
{
	bool shouldRepeat = 0;
	bool success = 0;
	int errorCode = 0;
	string msg = "";
	int data = 0;

	do
	{
		system("cls");
		cout << "----------EMPLOYEE SALARY APP----------" << endl;
		cout << "What do you want to do?" << endl
			<< "1. Calculate Salary From My Own File." << endl
			<< "2. Create An Employee List And Calculate Salary." << endl
			<< "3. Exit." << endl;
		cout << "Enter your choice: ";
			
		tie(success, errorCode, msg, data) = getChoose();

		if (success)
		{
			shouldRepeat = 0;

			if (data == 1)
			{
				system("cls");

				// Read File
				string filename;

				cout << "Input FileName: ";
				getline(cin, filename);

				vector<IEmployee*> getdata = readEmFile(filename);

				for (int i = 0; i < getdata.size(); i++)
					state.employees.push_back(getdata[i]);
				
				// Add some effects
				for (int i = 0; i < 10; i++)
				{
					cout << "."; Sleep(50);
				}

				cout << endl << "Load data successfully" << endl;
				cout << "Here is your employee list and salary: " << endl << endl;

				// Print Data
				for (int i = 0; i < state.employees.size(); i++)
				{
					IConverter* converter = ui[state.employees[i]->className()];
					string data = converter->convert((void*)state.employees[i]);

					cout << i + 1 << ". " << data << endl;
				}
				cout << endl;

				system("pause");
				return;
			}
			else if (data == 2)
			{
				system("cls");

				int shouldContinue = 1;

				while (shouldContinue == 1)
				{
					cout << "----------Choose Employee type:" << endl;
					cout << setiosflags(ios::left) << setw(15) << "1.Daily" << setw(15) << "2. Hourly"
						<< setw(15) << "3.Product" << setw(15) << "4. Manager" << endl;
					cout << "Enter your choice: ";

					int choice;
					cin >> choice;

					string code;
					switch (choice)
					{
					case 1:
					{code = "DailyEmployee"; break; }
					case 2:
					{code = "HourlyEmployee"; break; }
					case 3:
					{code = "ProductEmployee"; break; }
					case 4:
					{code = "Manager"; break; }
					}

					IConverter* converter = inputui[code];
					IEmployee* temp = converter->getInput();
					state.employees.push_back(temp);

					cout << endl << "Continue?   1.Yes // 2.No, show me calculated salary" << endl;
					cout << "Enter your choice: ";
					cin >> shouldContinue;
				}

				// Add some effects
				system("cls");

				for (int i = 0; i < 10; i++)
				{
					cout << "."; Sleep(50);
				}

				cout << endl << "Load data successfully" << endl;
				cout << "Here is your employee list and salary: " << endl << endl;

				// Print Data
				for (int i = 0; i < state.employees.size(); i++)
				{
					IConverter* converter = ui[state.employees[i]->className()];
					string data = converter->convert((void*)state.employees[i]);

					cout << i + 1 << ". " << data << endl;
				}
				cout << endl;

				system("pause");
				return;
			}
			else if (data == 3)
			{
				system("cls");
				cout << endl << endl << "Thanks for using. See you next time. ^_^";
				Sleep(1000);

				return;
			}
		}
		else
		{
			cout << endl << msg << " Please try again!" << endl << endl;
			Sleep(1000);
			shouldRepeat = 1;
		}

	} while (shouldRepeat);
}