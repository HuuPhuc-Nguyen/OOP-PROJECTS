#include "RandomGradeGenerator.h"

/// <summary>
/// Hàm random gpa trong khoảng (5;10)
/// </summary>
/// <returns></returns>
float RandomGradeGenerator::next()
{
	return _rng.next(5, 10);
}