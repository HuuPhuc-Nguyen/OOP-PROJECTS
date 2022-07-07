#include "HourlyEmployeeUIConverter.h"

string HourlyEmployeeUIConverter::convert(void* Employee)
{
    HourlyEmployee* hourlyemployee = (HourlyEmployee*)Employee;

    stringstream builder;

    builder << hourlyemployee->className() << ": "
        << hourlyemployee->FullName().toString() << endl
        << "HourlyPayment= " << hourlyemployee->HourSalary() << "$; "
        << "TotalHours= " << hourlyemployee->Hours() << endl
        << "TotalSalary= " << hourlyemployee->calculateSalary() << "$";

    return builder.str();
}

IEmployee* HourlyEmployeeUIConverter::convertBackFromFile(string fromfile)
{
    stringstream sin;
    sin << fromfile;

    string get, dumb;
    double salary, amount;
    double fixed = 0;

    getline(sin, get);
    Fullname fullname(get);

    getline(sin, dumb, '=');
    getline(sin, get, ';');
    salary = stoi(get);

    getline(sin, dumb, '=');
    getline(sin, get, ';');
    amount = stoi(get);

    sin.ignore();

    IEmployee* temp = EmployeeFactory::instance()->create(1, fullname, salary, amount, fixed);

    return temp;
}

IEmployee* HourlyEmployeeUIConverter::getInput()
{
    string getfullname;
    double salary, amount;
    double fixed = 0;

    cout << "Enter full name: ";
    cin.ignore();
    getline(cin, getfullname);

    Fullname fullname(getfullname);

    cout << "Enter HourlySalary: ";
    cin >> salary;

    cout << "Enter Hours: ";
    cin >> amount;

    IEmployee* temp = EmployeeFactory::instance()->create(1, fullname, salary, amount, fixed);

    return temp;
}
