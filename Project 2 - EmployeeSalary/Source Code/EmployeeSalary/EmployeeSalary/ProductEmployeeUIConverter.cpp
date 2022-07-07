#include "ProductEmployeeUIConverter.h"

string ProductEmployeeUIConverter::convert(void* Employee)
{
    ProductEmployee* productemployee = (ProductEmployee*)Employee;

    stringstream builder;

    builder << productemployee->className() << ": "
        << productemployee->FullName().toString() << endl
        << "ProductPayment= " << productemployee->ProductSalary() << "$; "
        << "TotalProducts= " << productemployee->Products() << endl
        << "TotalSalary= " << productemployee->calculateSalary() << "$";

    return builder.str();
}

IEmployee* ProductEmployeeUIConverter::convertBackFromFile(string fromfile)
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

    IEmployee* temp = EmployeeFactory::instance()->create(2, fullname, salary, amount, fixed);

    return temp;
}

IEmployee* ProductEmployeeUIConverter::getInput()
{
    string getfullname;
    double salary, amount;
    double fixed = 0;

    cout << "Enter full name: ";
    cin.ignore();
    getline(cin, getfullname);

    Fullname fullname(getfullname);

    cout << "Enter ProductSalary: ";
    cin >> salary;

    cout << "Enter Products: ";
    cin >> amount;

    IEmployee* temp = EmployeeFactory::instance()->create(2, fullname, salary, amount, fixed);

    return temp;
}

