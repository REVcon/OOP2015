// lab6ex2Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\lab6ex2\Student.h"

BOOST_AUTO_TEST_CASE(CanBeConstructedWithoutPatronymic)
{
	BOOST_REQUIRE_NO_THROW(CStudent("ivan", "ivanov", 16));
}

BOOST_AUTO_TEST_CASE(FieldsNameSurnamePatronymicMustBeWithoutSpaces)
{
	BOOST_REQUIRE_THROW(CStudent("  ", "   ivanov", 16, "   "), invalid_argument);
}

BOOST_AUTO_TEST_CASE(FieldsNameSurnameMustNotBeEmptyString)
{
	BOOST_REQUIRE_THROW(CStudent("", "ivanov", 16), invalid_argument);
	BOOST_REQUIRE_THROW(CStudent("ivan", "", 16), invalid_argument);
}

BOOST_AUTO_TEST_CASE(AgeMustBeInRange14to60)
{
	BOOST_REQUIRE_THROW(CStudent("ivan", "ivanov", 3, "petrov"), out_of_range);
	BOOST_REQUIRE_NO_THROW(CStudent("ivan", "ivanov", 60, "petrov"));
}

BOOST_AUTO_TEST_CASE(CanGetNameSurNamePatronymicAge)
{
	string name = "ivan";
	string surname = "ivanov";
	string patronymic = "petrovich";
	int age = 45;
	CStudent student(name, surname, age, patronymic);
	BOOST_CHECK_EQUAL(student.GetName(), name);
	BOOST_CHECK_EQUAL(student.GetSurname(), surname);
	BOOST_CHECK_EQUAL(student.GetPatronymic(), patronymic);
	BOOST_CHECK_EQUAL(student.GetAge(), age);
}

BOOST_AUTO_TEST_CASE(CanSetAge)
{
	{
		CStudent student("ivan", "ivanov", 15, "petrov");
		BOOST_REQUIRE_NO_THROW(student.SetAge(55));
	}
	{
		CStudent student("ivan", "ivanov", 20, "petrov");
		BOOST_REQUIRE_THROW(student.SetAge(15), domain_error);
	}
}

BOOST_AUTO_TEST_CASE(CanRename)
{
	{
		string name = "ivan";
		string surname = "ivanov";
		string patronymic = "petrovich";
		int age = 45;
		CStudent student(name, surname, age, patronymic);
		BOOST_REQUIRE_THROW(student.Rename("   ", "petrov", "andreevich"), invalid_argument);
		BOOST_CHECK_EQUAL(student.GetName(), name);
		BOOST_CHECK_EQUAL(student.GetSurname(), surname);
		BOOST_CHECK_EQUAL(student.GetPatronymic(), patronymic);
		BOOST_CHECK_EQUAL(student.GetAge(), age);
	}
	{
		string name = "ivan";
		string surname = "ivanov";
		string patronymic = "petrovich";
		int age = 45;
		CStudent student(name, surname, age, patronymic);
		BOOST_REQUIRE_NO_THROW(student.Rename("dmitriy", "lebedev", "sergeevich"));
		BOOST_CHECK_EQUAL(student.GetName(), "dmitriy");
		BOOST_CHECK_EQUAL(student.GetSurname(), "lebedev");
		BOOST_CHECK_EQUAL(student.GetPatronymic(), "sergeevich");
		BOOST_CHECK_EQUAL(student.GetAge(), age);
	}
}