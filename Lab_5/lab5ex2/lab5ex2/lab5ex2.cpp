#include "stdafx.h"
#include "MyString.h"

using namespace std;


BOOST_AUTO_TEST_SUITE(StringTests)

BOOST_AUTO_TEST_CASE(StringEmptyByDefault)
{
	CMyString default;
	BOOST_CHECK_EQUAL(default.GetStringData(), "");
}

BOOST_AUTO_TEST_CASE(CanBeConstructedFromArrayOfChar)
{
	const char test[] = "string";
	CMyString str(test);
	BOOST_CHECK_EQUAL(memcmp(str.GetStringData(), test, 6), 0);
	BOOST_CHECK_EQUAL(str.GetLength(), strlen(test));
}

BOOST_AUTO_TEST_CASE(CanBeConstructedFromArrayOfCharWithZeroSymbolInMiddle)
{
	const char test[] = "stri\0g";
	CMyString str(test, 6);
	BOOST_CHECK_EQUAL(memcmp(str.GetStringData(), test, 6), 0);
	BOOST_CHECK_EQUAL(str.GetLength(), 6);
}

BOOST_AUTO_TEST_CASE(CanBeConstructedFromArrayOfCharWithPointingLength)
{
	const char test[] = "stringstring";
	CMyString str(test, 6);
	BOOST_CHECK_EQUAL(memcmp(str.GetStringData(), "string", 6), 0);
}

BOOST_AUTO_TEST_CASE(CanBeConstructedFromSTLString)
{
	string test = "string";
	CMyString str(test);
	BOOST_CHECK_EQUAL(memcmp(str.GetStringData(), test.c_str(), 6), 0);
}

BOOST_AUTO_TEST_CASE(CanBeConstructedFromSTLStringWithZeroSymbol)
{
	string test("stri\0g", 6);
	CMyString str(test);
	BOOST_CHECK_EQUAL(memcmp(str.GetStringData(), test.c_str(), 6), 0);
}

BOOST_AUTO_TEST_CASE(CanBeConstructedFromOtherCMyString)
{
	{
		string test("string");
		CMyString str1(test);
		CMyString str2(str1);
		BOOST_CHECK_EQUAL(str2.GetLength(), 6);
		BOOST_CHECK_EQUAL(memcmp(str1.GetStringData(), str2.GetStringData(), 6), 0);
	}
	{
		string test("stri\0g", 6);
		CMyString str1(test);
		CMyString str2(str1);
		BOOST_CHECK_EQUAL(str2.GetLength(), 6);
		BOOST_CHECK_EQUAL(memcmp(str1.GetStringData(), str2.GetStringData(), 6), 0);
	}
}

BOOST_AUTO_TEST_CASE(TestMoveConstructor)
{
	{
		char* test = "string";
		CMyString str1(test);
		CMyString str2(move(str1));
		BOOST_CHECK_EQUAL(strcmp(str2.GetStringData(), test), 0);
		BOOST_CHECK_EQUAL(str2.GetLength(), 6);
		BOOST_CHECK_EQUAL(str1.GetLength(), 0);
	}
	{
		char* test("stri\0g");
		CMyString str1(test, 6);
		CMyString str2(move(str1));
		BOOST_CHECK_EQUAL(strcmp(str2.GetStringData(), test), 0);
		BOOST_CHECK_EQUAL(str2.GetLength(), 6);
		BOOST_CHECK_EQUAL(str1.GetLength(), 0);
	}
	
}

BOOST_AUTO_TEST_CASE(CanGetLength)
{
	const char* test = "stringstring";
	CMyString str(test);
	BOOST_CHECK_EQUAL(strlen(test), str.GetLength());
}

BOOST_AUTO_TEST_CASE(CanGetSubstring)
{
	{
		CMyString str("string string string");
		CMyString sub(str.SubString(0, 6));
		BOOST_CHECK_EQUAL(strcmp(sub.GetStringData(), "string"), 0);
		BOOST_CHECK_EQUAL(sub.GetLength(), 6);
	}
	{
		CMyString str("string string string");
		CMyString sub(str.SubString(7, 6));
		BOOST_CHECK_EQUAL(strcmp(sub.GetStringData(), "string"), 0);
		BOOST_CHECK_EQUAL(sub.GetLength(), 6);
	}
	{
		CMyString str("string string string");
		BOOST_REQUIRE_NO_THROW(str.SubString(19, 6));
		BOOST_REQUIRE_THROW(str.SubString(20, 6), invalid_argument);
	}
	{
		CMyString str("stri\0g stri\0g stri\0g", 20);
		CMyString sub(str.SubString(7, 6));
		BOOST_CHECK_EQUAL(memcmp(sub.GetStringData(), "stri\0g", 6), 0);
		BOOST_CHECK_EQUAL(sub.GetLength(), 6);

	}
}

BOOST_AUTO_TEST_CASE(CanClear)
{
	{
		const char* test = "string";
		CMyString str(test);
		str.Clear();
		BOOST_CHECK_EQUAL(strcmp(str.GetStringData(), ""), 0);
		BOOST_CHECK_EQUAL(str.GetLength(), 0);
	}
}

BOOST_AUTO_TEST_CASE(TestCopyAssigningOperator)
{
	{
		const char* test = "string";
		CMyString str1 = test;
		CMyString str2 = str1;
		BOOST_CHECK_EQUAL(memcmp(str1.GetStringData(), test, 6), 0);
		BOOST_CHECK_EQUAL(memcmp(str1.GetStringData(), str2.GetStringData(), 6), 0);
	}
	{
		const char* test = "stri\0g";
		CMyString str1(test,6);
		CMyString str2 = str1;
		BOOST_CHECK_EQUAL(memcmp(str1.GetStringData(), test, 6), 0);
		BOOST_CHECK_EQUAL(memcmp(str1.GetStringData(), str2.GetStringData(), 6), 0);
	}
}

BOOST_AUTO_TEST_CASE(TestMoveAssigningOperator)
{
	{
		const char* test = "string";
		CMyString str1 = test;
		CMyString str2 = move(str1);
		BOOST_CHECK_EQUAL(memcmp(str2.GetStringData(), test, 6), 0);
		BOOST_CHECK_EQUAL(str2.GetLength(), 6);
		BOOST_CHECK_EQUAL(str1.GetLength(), 0);
	}
	{
		const char* test = "stri\0g";
		CMyString str1(test, 6);
		CMyString str2 = move(str1);
		BOOST_CHECK_EQUAL(memcmp(str2.GetStringData(), test, 6), 0);
		BOOST_CHECK_EQUAL(str2.GetLength(), 6);
		BOOST_CHECK_EQUAL(str1.GetLength(), 0);
	}
}


BOOST_AUTO_TEST_CASE(CanGetAndSetCharByIndex)
{
	CMyString str("string");
	BOOST_CHECK_EQUAL(str[0], 's');
	BOOST_CHECK_EQUAL(str[5], 'g');
	str[1] = 'S';
	BOOST_CHECK_EQUAL(str[1], 'S');
	BOOST_REQUIRE_NO_THROW(str[5]);
	BOOST_REQUIRE_THROW(str[6], out_of_range);
}

BOOST_AUTO_TEST_CASE(CompareOperators)
{
	{
		CMyString first("string"), second("string");
		BOOST_CHECK(first == second);
		BOOST_CHECK(!(first != second));
		BOOST_CHECK(!(first > second));
		BOOST_CHECK(!(first < second));
		BOOST_CHECK(first >= second);
		BOOST_CHECK(first <= second);
	}
	{
		CMyString first("test"), second("string");
		BOOST_CHECK(!(first == second));
		BOOST_CHECK(first != second);
		BOOST_CHECK(first > second);
		BOOST_CHECK(!(first < second));
		BOOST_CHECK(first >= second);
		BOOST_CHECK(!(first <= second));
	}
	{
		CMyString first("apple"), second("string");
		BOOST_CHECK(!(first == second));
		BOOST_CHECK(first != second);
		BOOST_CHECK(!(first > second));
		BOOST_CHECK(first < second);
		BOOST_CHECK(!(first >= second));
		BOOST_CHECK(first <= second);
	}
	{
		CMyString first("string"), second("stringtest");
		BOOST_CHECK(!(first == second));
		BOOST_CHECK(first != second);
		BOOST_CHECK(!(first > second));
		BOOST_CHECK(first < second);
		BOOST_CHECK(!(first >= second));
		BOOST_CHECK(first <= second);
	}
	{
		CMyString first("stri/0g", 6), second("stri/0g", 6);
		BOOST_CHECK(first == second);
		BOOST_CHECK(!(first != second));
		BOOST_CHECK(!(first > second));
		BOOST_CHECK(!(first < second));
		BOOST_CHECK(first >= second);
		BOOST_CHECK(first <= second);
	}
	{
		CMyString first("test"), second("stri\0g", 6);
		BOOST_CHECK(!(first == second));
		BOOST_CHECK(first != second);
		BOOST_CHECK(first > second);
		BOOST_CHECK(!(first < second));
		BOOST_CHECK(first >= second);
		BOOST_CHECK(!(first <= second));
	}
}

BOOST_AUTO_TEST_CASE(TestAssigningConcatenation)
{
	{
		CMyString first("string "), second("test");
		first += second;
		BOOST_CHECK_EQUAL(first, "string test");
	}
	{
		CMyString first("stri\0g ", 7);
		CMyString second("test");
		first += second;
		BOOST_CHECK_EQUAL(memcmp(first.GetStringData(),"stri\0g test",11), 0);
	}
}

BOOST_AUTO_TEST_CASE(CanConcatenate)
{
	{
		CMyString first("string "), second("test");
		CMyString str = first + second;
		BOOST_CHECK_EQUAL(str, "string test");
	}
	{
		CMyString first("string ");
		char *second = "test";
		CMyString str = first + second;
		BOOST_CHECK_EQUAL(str, "string test");
	}
	{
		CMyString first("string ");
		string second = "test";
		CMyString str = first + second;
		BOOST_CHECK_EQUAL(str, "string test");
	}
	{
		CMyString first("stri\0g ", 7), second("test");
		CMyString str = first + second;
		BOOST_CHECK_EQUAL(memcmp(str.GetStringData(), "stri\0g test", 11), 0);
	}
}


BOOST_AUTO_TEST_CASE(CanReadFromStream)
{
	{
		istringstream iss("string test");
		CMyString str;
		iss >> str;
		BOOST_CHECK_EQUAL(str, "string");
	}
	{
		istringstream iss("stri\0g test");
		CMyString str;
		iss >> str;
		BOOST_CHECK_EQUAL(str, "stri");
	}
}

BOOST_AUTO_TEST_CASE(CanWriteToStream)
{
	{
		ostringstream oss;
		oss << CMyString("string test");
		BOOST_CHECK(oss.str() == "string test");
	}
	{
		ostringstream oss;
		oss << CMyString("stri\0g test");
		BOOST_CHECK(oss.str() == "stri\0g test");
	}
	
}

BOOST_AUTO_TEST_SUITE_END()
