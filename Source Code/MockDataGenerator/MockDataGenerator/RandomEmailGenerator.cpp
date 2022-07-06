#include "RandomEmailGenerator.h"

RandomEmailGenerator::RandomEmailGenerator(string FileName)
{
	_domain = File::readRowInFile(FileName);
}

RandomEmailGenerator::RandomEmailGenerator() {}

RandomEmailGenerator::~RandomEmailGenerator() {}

string RandomEmailGenerator::next(Fullname name)
{
	int index = _rng.next(_domain.size());
	string domain = _domain[index];

	stringstream getUser;
	getUser << name.FirstName()[0] << name.MiddleName()[0] << name.LastName();

	string user = getUser.str();
	StringHelper::getLowerCase(user);

	string email = user + domain;

	return email;
}