#include "StringHelper.h"

void StringHelper::getLowerCase(string& str)
{
	for (int i = 0; i < str.size(); i++)
		str[i] = tolower(str[i]);
}

vector<string> StringHelper::split(string line, string separator)
{
	vector<string> result;

	int startPosition = 0;
	size_t foundPosition = line.find(separator, startPosition);

	while (foundPosition != string::npos) {
		string token = line.substr(startPosition, foundPosition - startPosition);
		result.push_back(token);

		startPosition = foundPosition + separator.size();
		foundPosition = line.find(separator, startPosition);
	}

	// Chuoi con lai
	string token = line.substr(startPosition, line.size() - startPosition);
	result.push_back(token);
	return result;
}

string StringHelper::vectorStudentToString(vector<Student> list)
{
	stringstream builder;

	for (int i = 0; i < list.size(); i++)
		builder << i+1 << ".\n" << list[i].toString();

	string result = builder.str();
	result = result.substr(0, result.length() - 1); // ignore the last endl (in student::tostring)

	return result;
}