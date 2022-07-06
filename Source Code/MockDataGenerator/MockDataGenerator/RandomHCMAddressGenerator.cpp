#include "RandomHCMAddressGenerator.h"

RandomHCMAddressGenerator::RandomHCMAddressGenerator(string FileName)
{
	vector<string> getDistrict = File::readRowInFile(FileName);
	_district = StringHelper::split(getDistrict[0], ",");
}

RandomHCMAddressGenerator::RandomHCMAddressGenerator() {}

RandomHCMAddressGenerator::~RandomHCMAddressGenerator() {}

HCMAddress RandomHCMAddressGenerator::next()
{
	// Random district ABC
	int i_district = _rng.next(_district.size());

	// Load Filewards and streers of district ABC, File house number
	vector<string> getWardStreet = File::readRowInFile("./Data/ListWardStreetofDistrict"
		+ _district[i_district] + ".txt");
	vector<string> getHouseNumber = File::readRowInFile("./Data/ListHouseNumber.txt");

	_ward = StringHelper::split(getWardStreet[0], ",");
	_street = StringHelper::split(getWardStreet[1], ",");
	_number = StringHelper::split(getHouseNumber[0], ",");

	// Random ward, street, house number
	int i_ward = _rng.next(_ward.size());
	int i_street = _rng.next(_street.size());
	int i_number = _rng.next(_number.size());


	HCMAddress result(_number[i_number], _street[i_street], _ward[i_ward], _district[i_district]);

	return result;
}