#include "stdafx.h"
#include "Student.h"
#include <iostream>

using namespace std;

CStudent::CStudent(string const& name, string const & surname, int age, string const & patronymic)
{
	Rename(name, surname, patronymic);
	SetAge(age);
}


CStudent::~CStudent()
{
}

string CStudent::GetName() const
{
	return m_name;
}

string CStudent::GetSurname() const
{
	return m_surname;
}

string CStudent::GetPatronymic() const
{
	return m_patronymic;
}

int CStudent::GetAge() const
{
	return m_age;
}

void CStudent::Rename(string const & name, string const & surname, string const & patronymic)
{
	string tmpName;
	string tmpSurname;
	string tmpPatronymic;
	if (ValidArg(name) && name.size() > 0 && ValidArg(surname) && surname.size() > 0 && ValidArg(patronymic))
	{
		tmpName = name;
		tmpSurname = surname;
		tmpPatronymic = patronymic;
		m_name.swap(tmpName);
		m_surname.swap(tmpSurname);
		m_patronymic.swap(tmpPatronymic);
	}
	else
	{
		throw std::invalid_argument("Name, surname, patronymic must not contain spaces");
	}
}

void CStudent::SetAge(int age)
{
	if (age < 14 || age > 60)
	{
		throw out_of_range("Age must be in range 14-60");
	}
	else if (age < m_age)
	{
		throw domain_error("New age must be more than the previous");
	}
	m_age = age;
}


bool CStudent::ValidArg(string const & arg)
{
	string result;
	try
	{
		result = arg;
	}
	catch (bad_alloc)
	{
		return false;
	}
	for (size_t i = 0; i < result.size(); ++i)
	{
		if (result[i] == ' ')
		{
			return false;
		}
	}
	return true;
}
