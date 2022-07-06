#include "RandomPhoneGenerator.h"

RandomPhoneGenerator::RandomPhoneGenerator(string FileName)
{
	_head = File::readRowInFile(FileName);
}

RandomPhoneGenerator::RandomPhoneGenerator() {}
RandomPhoneGenerator::~RandomPhoneGenerator() {}

string RandomPhoneGenerator::next()
{
	int index = _rng.next(_head.size());
	int phone = _rng.next(1000000, 9999999);

	stringstream builder;

	builder << _head[index] << phone;

	string result = builder.str();
	result.insert(4, "-");
	result.insert(8, "-");
	return result;
}