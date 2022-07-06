#include "RandomIDGenerator.h"

string RandomIDGenerator::next()
{
	int int_id = _rng.next(20100000, 29999999);

	string result = to_string(int_id);

	return result;
}