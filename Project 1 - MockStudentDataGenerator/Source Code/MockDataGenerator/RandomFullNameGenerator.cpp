#include "RandomFullNameGenerator.h"

RandomFullNameGenerator::RandomFullNameGenerator(string FileName)
{
	//vector 3 phần tử, mỗi phần tử chứa ds họ, tên đệm, tên cách nhau bởi ký tự ","
	vector<string> lines = File::readRowInFile(FileName);

	_firstname = StringHelper::split(lines[0], ","); // từ 1->14 là các họ thống kế trên wiki; 15->22 họ dân tộc
	_middlename = StringHelper::split(lines[1], ",");
	_lastname = StringHelper::split(lines[2], ",");
}

RandomFullNameGenerator::RandomFullNameGenerator() {}

RandomFullNameGenerator::~RandomFullNameGenerator() {}

Fullname RandomFullNameGenerator::next()
{
	int i_middlename = _rng.next(_middlename.size());
	int i_lastname = _rng.next(_lastname.size());
	int i_firstname;

	float rate = (float)rand() / RAND_MAX; // random 1 số trong phạm vi 0 -> 1 

	// chọn ra họ của sv theo tỉ lệ thống kê từ trang wiki
	if (rate < 0.005) i_firstname = 13;
	else if (rate < 0.015) i_firstname = 12;
	else if (rate < 0.028) i_firstname = 11;
	else if (rate < 0.041) i_firstname = 10;
	else if (rate < 0.062) i_firstname = 9;
	else if (rate < 0.087) i_firstname = 8;
	else if (rate < 0.118) i_firstname = 7;
	else if (rate < 0.152) i_firstname = 6;
	else if (rate < 0.192) i_firstname = 5;
	else if (rate < 0.247) i_firstname = 4;
	else if (rate < 0.314) i_firstname = 3;
	else if (rate < 0.396) i_firstname = 2;
	else if (rate < 0.499) i_firstname = 1;
	else if (rate < 0.883) i_firstname = 0;
	else i_firstname = _rng.next(14, 21); // các họ khác (dân tộc thiểu số)

	string firstname = _firstname[i_firstname];
	string middlename = _middlename[i_middlename];
	string lastname = _lastname[i_lastname];

	Fullname result(firstname, middlename, lastname);

	return result;
}