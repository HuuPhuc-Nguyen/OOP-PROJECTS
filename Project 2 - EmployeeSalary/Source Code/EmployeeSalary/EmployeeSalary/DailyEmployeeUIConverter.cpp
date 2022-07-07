#include "DailyEmployeeUIConverter.h"

string DailyEmployeeUIConverter::convert(void* Employee)
{
    DailyEmployee* dailyemployee = (DailyEmployee*)Employee;

    stringstream builder;

    builder << dailyemployee->className() << ": "
        << dailyemployee->FullName().toString() << endl
        << "DailyPayment= " << dailyemployee->DaySalary() << "$; "
        << "TotalDays= " << dailyemployee->Days() << endl
        << "TotalSalary= " << dailyemployee->calculateSalary() << "$";

    return builder.str();
}

IEmployee* DailyEmployeeUIConverter::convertBackFromFile(string fromfile)
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

    IEmployee* temp = EmployeeFactory::instance()->create(0, fullname, salary, amount, fixed);

    return temp;
}

IEmployee* DailyEmployeeUIConverter::getInput()
{
    string getfullname;
    double salary, amount;
    double fixed = 0;

    cout << "Enter full name: ";
    cin.ignore();
    getline(cin, getfullname);

    Fullname fullname(getfullname);

    cout << "Enter DailySalary: ";
    cin >> salary;

    cout << "Enter Days: ";
    cin >> amount;

    IEmployee* temp = EmployeeFactory::instance()->create(0, fullname, salary, amount, fixed);

    return temp;
}
