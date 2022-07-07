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

string StringHelper::deleteExtraSpace(string input)
{
	for (int i = 0; i < input.size(); i++)
		if (input[i] == ' ' && input[i + 1] == ' ')
			input.erase(input.begin() + i);

	string result = input;
	
	return result;
}
