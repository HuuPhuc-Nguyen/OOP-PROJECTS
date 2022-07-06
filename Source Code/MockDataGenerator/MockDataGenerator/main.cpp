#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "FakeStudentGenerator.h"
#include "RandomIntegerGenerator.h"
#include "File.h"
#include <iomanip>

using namespace std;

void main()
{
	// Read students from file and add to vector
	vector<Student> myList = File::readStudentFile("./Data/student.txt");

	// Generate number
	cout << "Generate randomly a number n in the range of [5,10]: ";

	RandomIntGenerator i_rng;

	cout << i_rng.next(5, 10) << endl << endl;

	// Generate student and add to vector
	cout << "Generate randomly n Students and add to the previous vector: " << endl;
	cout << "Input the number of students (n): ";

	int n;
	do
	{
		cin >> n;
	} while (n < 0);

	FakeStudentGenerator s_rng;

	for (int i = 0; i < n; i++)
	{
		Student student = s_rng.next();
		myList.push_back(student);
	}

	//Overwrite student list back to file
	File::overwriteStudentFile(myList, "./Data/student.txt");
	cout << "Write successfully!" << endl << endl;

	// Print Average gpa
	float avg = 0;

	for (int i = 0; i < myList.size(); i++)
		avg += myList[i].GPA();

	avg = avg / myList.size();
	cout << "Average GPA: " << setprecision(3) << avg << endl << endl;

	// Print all students have GPA greater than Average GPA
	cout << "--------------students have GPA greater than Average------------\n";
	for (int i = 0; i < myList.size(); i++)
		if (myList[i].GPA() > avg)
			cout << myList[i].toString() << endl;
	
	system("pause");
}