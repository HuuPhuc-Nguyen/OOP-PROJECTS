#include "DailyEmployeeUIComverter.h"

string DailyEmployeeUIComverter::convert(void* Employee)
{
    DailyEmployee* dailyemployee = (DailyEmployee*) Employee;
    
    stringstream builder;

    builder << dailyemployee->className() << ": "
        << dailyemployee->FullName().toString() << endl
        << "DailyPayment= " << dailyemployee->DaySalary() << "$; "
        << "TotalDays= " << dailyemployee->Days() << endl
        << "TotalSalary= " << dailyemployee->calculateSalary() << "$";

    return builder.str();
}
