#include "ReadEmployeeFile.h"
using namespace std;

vector<IEmployee*> readEmFile(string Filename)
{
	vector<IEmployee*> result;
	fstream f;
	string dumb, get;
	double salary, amount;
	double fixed = 0;

	f.open(Filename);

	while (!f.is_open())
	{
		cout << "Cannot open File. Please check the file name again. File name must have format as (MonthYear.txt)" << endl << endl;
		cout << "Input FileName: ";
		getline(cin, Filename);
		f.open(Filename);
	}

	if (f.is_open())
	{
		do
		{
			getline(f, dumb, ':');
			getline(f, get);
			Fullname fullname(get);

			if (dumb == "DailyEmployee")
			{
				getline(f, dumb, '=');
				f >> salary;

				getline(f, dumb, '=');
				f >> amount;

				f.ignore();

				IEmployee* temp = EmployeeFactory::instance()->create(0, fullname, salary, amount, fixed);
				result.push_back(temp);
			}
			else if (dumb == "HourlyEmployee")
			{
				getline(f, dumb, '=');
				f >> salary;

				getline(f, dumb, '=');
				f >> amount;

				f.ignore();

				IEmployee* temp = EmployeeFactory::instance()->create(1, fullname, salary, amount, fixed);
				result.push_back(temp);
			}
			else if (dumb == "ProductEmployee")
			{
				getline(f, dumb, '=');
				f >> salary;

				getline(f, dumb, '=');
				f >> amount;

				f.ignore();

				IEmployee* temp = EmployeeFactory::instance()->create(2, fullname, salary, amount, fixed);
				result.push_back(temp);
			}
			else if (dumb == "Manager")
			{
				getline(f, dumb, '=');
				f >> fixed;

				getline(f, dumb, '=');
				f >> salary;

				getline(f, dumb, '=');
				f >> amount;

				f.ignore();

				IEmployee* temp = EmployeeFactory::instance()->create(3, fullname, salary, amount, fixed);
				result.push_back(temp);
			}

		} while (!f.eof());
	}

	f.close();

	return result;
}