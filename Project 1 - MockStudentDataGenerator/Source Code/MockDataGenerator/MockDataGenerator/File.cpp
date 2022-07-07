#include "File.h"
#include "StringHelper.h"

vector<string> File::readRowInFile(string FileName)
{
	fstream f;
	string line;
	vector<string>lines;

	f.open(FileName);
	if (f.is_open())
	{
		do
		{
			getline(f, line);
			lines.push_back(line);
		} while (!f.eof());
	}

	f.close();

	return lines;
}

/// <summary>
/// Hàm đọc file sinh viên
/// </summary>
/// <param name="FileName"></param>
/// <returns>trả về Vector<student> đọc từ file</returns>
vector<Student> File::readStudentFile(string FileName)
{
	fstream f;
	vector<Student> list;
	string dumb, id, getName, getGpa, phone, mail, getDob, getAddr;

	f.open(FileName, ios :: in);
	if (f.is_open())
	{
		do
		{
			// read No.
			getline(f, dumb);

			// read id
			getline(f, dumb, '=');
			getline(f, id);

			// read full name
			Fullname fullname;
			getline(f, dumb, '=');
			getline(f, getName, ' ');
			fullname.setFirstName(getName);
			getline(f, getName, ' ');
			fullname.setMiddleName(getName);
			getline(f, getName);
			fullname.setLastName(getName);

			// read gpa
			getline(f, dumb, '=');
			getline(f, getGpa);
			float gpa = stof(getGpa);

			// read phone number
			getline(f, dumb, '=');
			getline(f, phone);

			// read mail
			getline(f, dumb, '=');
			getline(f, mail);

			// read dob
			Date dob;
			getline(f, dumb, '=');
			getline(f, getDob, '/');
			dob.setDay(stoi(getDob));
			getline(f, getDob, '/');
			dob.setMonth(stoi(getDob));
			getline(f, getDob);
			dob.setYear(stoi(getDob));

			// read address
			HCMAddress addr;
			getline(f, dumb, '=');
			getline(f, getAddr, ' ');
			addr.setNumber(getAddr);
			getline(f, getAddr, ',');
			addr.setStreet(getAddr);
			getline(f, dumb, ' ');
			getline(f, getAddr, ',');
			addr.setWard(getAddr);
			getline(f, dumb, ' ');
			getline(f, getAddr, ',');
			addr.setDistrict(getAddr);
			getline(f, dumb);

			// create Student and push to list
			Student temp(id, fullname, gpa, phone, mail, dob, addr);
			
			list.push_back(temp);
		} while (!f.eof());
	}

	f.close();

	return list;
}

void File::overwriteStudentFile(vector<Student> list, string FileName)
{
	fstream f;
	f.open(FileName, ios::out);

	string get = StringHelper::vectorStudentToString(list);
	
	f << get;

	f.close();
}