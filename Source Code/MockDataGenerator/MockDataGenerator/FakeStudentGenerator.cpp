#include "FakeStudentGenerator.h"

FakeStudentGenerator::FakeStudentGenerator()
{
	RandomFullNameGenerator rngname("./Data/ListName.txt");
	_rngname = rngname;
	RandomPhoneGenerator rngphone("./Data/ListPhone.txt");
	_rngphone = rngphone;
	RandomEmailGenerator rngemail("./Data/ListEmail.txt");
	_rngemail = rngemail;
	RandomHCMAddressGenerator rngaddr("./Data/ListDistrict.txt");
	_rngaddr = rngaddr;
}

FakeStudentGenerator::FakeStudentGenerator(string fname, string fphone, string fmail, string fdistrict)
{
	RandomFullNameGenerator rngname(fname);
	_rngname = rngname;
	RandomPhoneGenerator rngphone(fphone);
	_rngphone = rngphone;
	RandomEmailGenerator rngemail(fmail);
	_rngemail = rngemail;
	RandomHCMAddressGenerator rngaddr(fdistrict);
	_rngaddr = rngaddr;
}

FakeStudentGenerator::~FakeStudentGenerator() {}

Student FakeStudentGenerator::next()
{
	string id = _rngid.next();
	Fullname name = _rngname.next();
	float gpa = _rnggpa.next();
	string phone = _rngphone.next();
	string email = _rngemail.next(name);
	Date dob = _rngdob.next();
	HCMAddress addr = _rngaddr.next();

	Student result(id, name, gpa, phone, email, dob, addr);

	return result;
}