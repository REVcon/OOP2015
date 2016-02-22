// task2Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../task2/RemoveExtraSpaces.h"

bool StringsAreEqual(string const& x, string const& y)
{
	return x == y;
}

BOOST_AUTO_TEST_CASE(ExtraSpacesInBegin)
{
	string result = RemoveExtraSpaces("    456");
	BOOST_CHECK(StringsAreEqual(result, "456"));
}


BOOST_AUTO_TEST_CASE(ExtraSpacesInEnd)
{
	string result = RemoveExtraSpaces("456         ");
	BOOST_CHECK(StringsAreEqual(result, "456"));
}

BOOST_AUTO_TEST_CASE(ExtraSpacesInSeverealString)
{
	string result = RemoveExtraSpaces("    45       5    6          ");
	BOOST_CHECK(StringsAreEqual(result, "45 5 6"));
}

BOOST_AUTO_TEST_CASE(OnlySpaces)
{
	string result = RemoveExtraSpaces("                       ");
	BOOST_CHECK(StringsAreEqual(result, ""));
}

