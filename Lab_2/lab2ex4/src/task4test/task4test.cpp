// task4test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../task4/GenerateSet.h"

using namespace std;

bool SetsAreEqual(set<int> const& x, set<int> const& y)
{
	return x == y;
}


BOOST_AUTO_TEST_CASE(GivenZero)
{
	auto result = GeneratePrimeNumbersSet(0);
	BOOST_CHECK(result.empty());
}

BOOST_AUTO_TEST_CASE(GivenNegativeNumber)
{
	auto result = GeneratePrimeNumbersSet(-200);
	BOOST_CHECK(result.empty());
}

BOOST_AUTO_TEST_CASE(SeveralNumber)
{
	auto result = GeneratePrimeNumbersSet(23);
	BOOST_CHECK(SetsAreEqual(result, { 2, 3, 5, 7, 11, 13, 17, 19, 23 }));
}

