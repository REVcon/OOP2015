#pragma once
#include <string>

using namespace std;

class CStudent
{
public:
	CStudent(string const& name, string const & surname, int age, string const & patronymic = "");
	~CStudent();
	string GetName() const;
	string GetSurname() const;
	string GetPatronymic() const;
	int GetAge() const;
	void Rename(string const & name, string const & surname, string const & patronymic = "");
	void SetAge(int age);
private:
	bool ValidArg(string const& arg);
	string m_name;
	string m_surname;
	string m_patronymic;
	int m_age;
};

