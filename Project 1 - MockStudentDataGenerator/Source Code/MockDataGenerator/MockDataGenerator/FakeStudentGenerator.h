#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "File.h"
#include "Student.h"
#include "RandomIntegerGenerator.h"
#include "RandomBirthDayGenerator.h"
#include "RandomEmailGenerator.h"
#include "RandomFullNameGenerator.h"
#include "RandomGradeGenerator.h"
#include "RandomHCMAddressGenerator.h"
#include "RandomIDGenerator.h"
#include "RandomPhoneGenerator.h"

class FakeStudentGenerator {
private:
	RandomIDGenerator _rngid;
	RandomFullNameGenerator _rngname;
	RandomGradeGenerator _rnggpa;
	RandomPhoneGenerator _rngphone;
	RandomEmailGenerator _rngemail;
	RandomBirthDayGenerator _rngdob;
	RandomHCMAddressGenerator _rngaddr;
public:
	FakeStudentGenerator();
	FakeStudentGenerator(string, string, string, string);
	~FakeStudentGenerator();
public:
	Student next();
};

