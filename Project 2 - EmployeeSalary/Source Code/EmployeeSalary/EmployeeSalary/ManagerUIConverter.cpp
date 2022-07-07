#include "ManagerUIConverter.h"

string ManagerUIConverter::convert(void* Employee)
{
    Manager* manager = (Manager*)Employee;

    stringstream builder;

    builder << manager->className() << ": "
        << manager->FullName().toString() << endl
        << "Fixed= " << manager->FixedSalary() << "$; "
        << "ManagementPayment= " << manager->ManagementSalary() << "$; "
        << "TotalEmloyees= " << manager->Empolyees() << endl
        << "TotalSalary= " << manager->calculateSalary() << "$";

    return builder.str();
}

IEmployee* ManagerUIConverter::convertBackFromFile(string fromfile)
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
    fixed = stoi(get);

    getline(sin, dumb, '=');
    getline(sin, get, ';');
    salary = stoi(get);

    getline(sin, dumb, '=');
    getline(sin, get, ';');
    amount = stoi(get);

    sin.ignore();

    IEmployee* temp = EmployeeFactory::instance()->create(3, fullname, salary, amount, fixed);

    return temp;
}

IEmployee* ManagerUIConverter::getInput()
{
    string getfullname;
    double salary, amount;
    double fixed = 0;

    cout << "Enter full name: ";
    cin.ignore();
    getline(cin, getfullname);

    Fullname fullname(getfullname);

    cout << "Enter FixedSalary: ";
    cin >> fixed;

    cout << "Enter ManagementSalary: ";
    cin >> salary;

    cout << "Enter Employees: ";
    cin >> amount;

    IEmployee* temp = EmployeeFactory::instance()->create(3, fullname, salary, amount, fixed);

    return temp;
}
