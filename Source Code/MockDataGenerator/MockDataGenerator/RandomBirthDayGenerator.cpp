#include "RandomBirthDayGenerator.h"

Date RandomBirthDayGenerator::next()
{
	int year = _rng.next(2000, 2004); // sinh viên đang học tại trường từ 2k -> 2k4
	int month = _rng.next(1, 12);
	int day = _rng.next(1, Date::dayOfMonth(month, year));

	Date result(day, month, year);

	return result;
}

/// <summary>
/// Hàm sinh ngẫu nhiên ngày/tháng/năm sinh theo đúng độ tuổi nhập vào
/// </summary>
/// <param name="age">Tuổi hiện tại</param>
/// <returns>ngày/tháng/năm sinh ứng với tuổi hiện tại</returns>
Date RandomBirthDayGenerator::next(int age)
{
	time_t t = time(0);
	tm* now = localtime(&t);
	int year = (now->tm_year + 1900) - age;
	int month = _rng.next(1, 12);
	int day = _rng.next(1, Date::dayOfMonth(month, year));

	Date result(day, month, year);

	return result;
}