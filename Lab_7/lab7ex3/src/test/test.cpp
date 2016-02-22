// test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../lab7ex3v3/CFamily.h"
#include "../lab7ex3v3/CDog.h"
#include "../lab7ex3v3/CCat.h"
#include "../lab7ex3v3/CHuman.h"


BOOST_AUTO_TEST_SUITE(TestCDog)

BOOST_AUTO_TEST_CASE(CanGetName)
{
	CDog test("bobik", MALE);
	BOOST_CHECK_EQUAL(test.GetName(), "bobik");
}

BOOST_AUTO_TEST_CASE(CanGetGender)
{
	CDog test("bobik", MALE);
	BOOST_CHECK_EQUAL(test.GetGender(), MALE);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestCCat)

BOOST_AUTO_TEST_CASE(CanGetName)
{
	CCat test("tom", MALE);
	BOOST_CHECK_EQUAL(test.GetName(), "tom");
}

BOOST_AUTO_TEST_CASE(CanGetGender)
{
	CCat test("tom", MALE);
	BOOST_CHECK_EQUAL(test.GetGender(), MALE);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(TestCHuman)

BOOST_AUTO_TEST_CASE(CanGetName)
{
	CHuman test("tom", MALE, 1);
	BOOST_CHECK_EQUAL(test.GetName(), "tom");
}

BOOST_AUTO_TEST_CASE(CanGetGender)
{
	CHuman test("ruslan", MALE, 1);
	BOOST_CHECK_EQUAL(test.GetGender(), MALE);
}

BOOST_AUTO_TEST_CASE(CanGetNumberOfBirthCertificate)
{
	CHuman test("ruslan", MALE, 1);
	BOOST_CHECK_EQUAL(test.GetNumberOfTheBirthCertificate(), 1);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestCMyFamily)

BOOST_AUTO_TEST_CASE(CanCreateFromTwoSpouses)
{
	CHuman ruslan("ruslan", MALE, 1);
	CHuman julia("julia", FEMALE, 2);
	CFamily<CHuman, Gender, CStandartGenderDeterminer<CHuman, Gender>, CHumanCreator<CHuman, Gender>> family(ruslan, julia);
}

BOOST_AUTO_TEST_CASE(CanGetSeveralSpouse)
{
	CHuman ruslan("ruslan", MALE, 1);
	CHuman julia("julia", FEMALE, 2);
	CFamily<CHuman, Gender, CStandartGenderDeterminer<CHuman, Gender>, CHumanCreator<CHuman, Gender>> family(ruslan, julia);
	BOOST_CHECK_EQUAL(family.GetSpouse1().GetName(), "ruslan");
	BOOST_CHECK_EQUAL(family.GetSpouse1().GetGender(), MALE);
	BOOST_CHECK_EQUAL(family.GetSpouse1().GetNumberOfTheBirthCertificate(), 1);
	BOOST_CHECK_EQUAL(family.GetSpouse2().GetName(), "julia");
	BOOST_CHECK_EQUAL(family.GetSpouse2().GetGender(), FEMALE);
	BOOST_CHECK_EQUAL(family.GetSpouse2().GetNumberOfTheBirthCertificate(), 2);
}

BOOST_AUTO_TEST_CASE(CanMakeChildInHeterosexualFamily)
{
	{
		CHuman ruslan("ruslan", MALE, 1);
		CHuman julia("julia", FEMALE, 2);
		CFamily<CHuman, Gender, CStandartGenderDeterminer<CHuman, Gender>, CHumanCreator<CHuman, Gender>> family(ruslan, julia);
		BOOST_REQUIRE_NO_THROW(family.MakeChild(CHumanCreator<CHuman, Gender>("ilya", MALE, 3)));
	}
	{
		CHuman ruslan("helen", FEMALE, 1);
		CHuman julia("julia", FEMALE, 2);
		CFamily<CHuman, Gender, CStandartGenderDeterminer<CHuman, Gender>, CHumanCreator<CHuman, Gender>> family(ruslan, julia);
		BOOST_REQUIRE_THROW(family.MakeChild(CHumanCreator<CHuman, Gender>("ilya", MALE, 3)), std::logic_error);
	}
}

BOOST_AUTO_TEST_CASE(CanGetChildCount)
{
	CHuman ruslan("ruslan", MALE, 1);
	CHuman julia("julia", FEMALE, 2);
	CFamily<CHuman, Gender, CStandartGenderDeterminer<CHuman, Gender>, CHumanCreator<CHuman, Gender>> family(ruslan, julia);
	family.MakeChild(CHumanCreator<CHuman, Gender>("ilya", MALE, 3));
	family.MakeChild(CHumanCreator<CHuman, Gender>("helen", FEMALE, 4));
	family.MakeChild(CHumanCreator<CHuman, Gender>("anna", FEMALE, 5));
	BOOST_CHECK_EQUAL(family.GetChildCount(), 3);
}

BOOST_AUTO_TEST_CASE(CanGetSeveralChild)
{
	CHuman ruslan("ruslan", MALE, 1);
	CHuman julia("julia", FEMALE, 2);
	CFamily<CHuman, Gender, CStandartGenderDeterminer<CHuman, Gender>, CHumanCreator<CHuman, Gender>> family(ruslan, julia);
	family.MakeChild(CHumanCreator<CHuman, Gender>("ilya", MALE, 3));
	family.MakeChild(CHumanCreator<CHuman, Gender>("helen", FEMALE, 4));
	family.MakeChild(CHumanCreator<CHuman, Gender>("anna", FEMALE, 5));
	BOOST_CHECK_EQUAL(family.GetChild(0).GetName(), "ilya");
	BOOST_CHECK_EQUAL(family.GetChild(1).GetName(), "helen");
	BOOST_CHECK_EQUAL(family.GetChild(2).GetName(), "anna");
}

BOOST_AUTO_TEST_SUITE_END()



