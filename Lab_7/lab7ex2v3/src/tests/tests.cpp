// tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../lab7ex2v3/MySet.h"
#include "../lab7ex2v3/Node.h"
#include <string>
#include "vld.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(CMySetTest)

BOOST_AUTO_TEST_CASE(EmptyByDefault)
{
	CMySet<string> test;
	BOOST_CHECK(test.IsEmpty());
	BOOST_CHECK_EQUAL(test.GetSize(), 0);
}

BOOST_AUTO_TEST_CASE(TestContainsMethod)
{
	CMySet<string> test;
	BOOST_CHECK(!test.Contains("1"));
}

BOOST_AUTO_TEST_CASE(TestAddMethod)
{
	CMySet<string> test;
	test.Add("1");
	test.Add("2");
	BOOST_CHECK(test.Contains("1"));
	BOOST_CHECK(test.Contains("2"));
	test.Add("2");
	BOOST_CHECK_EQUAL(test.GetSize(), 2);
}

BOOST_AUTO_TEST_CASE(TestUnion)
{
	{
		CMySet<int> first;
		first.Add(1);
		first.Add(2);
		CMySet<int> second;		
		CMySet<int> result = first.Union(second);
		BOOST_CHECK_EQUAL(result.GetSize(), 2);
		BOOST_CHECK(result.Contains(1));
		BOOST_CHECK(result.Contains(2));
	}
	{
		CMySet<int> first;
		first.Add(1);
		first.Add(2);
		CMySet<int> second;
		second.Add(3);
		second.Add(2);
		CMySet<int> result;
		result = first.Union(second);
		BOOST_CHECK_EQUAL(result.GetSize(), 3);
		BOOST_CHECK(result.Contains(1));
		BOOST_CHECK(result.Contains(2));
		BOOST_CHECK(result.Contains(3));
	}	
}

BOOST_AUTO_TEST_CASE(TestIntersection)
{
	{
		CMySet<int> first;		
		CMySet<int> second;			
		CMySet<int> result = first.Intersection(second);
		BOOST_CHECK_EQUAL(result.GetSize(), 0);
	}
	{
		CMySet<int> first;
		first.Add(1);
		first.Add(2);
		CMySet<int> second;
		second.Add(3);
		second.Add(2);
		CMySet<int> result;
		result = first.Intersection(second);
		BOOST_CHECK_EQUAL(result.GetSize(), 1);
		BOOST_CHECK(!result.Contains(1));
		BOOST_CHECK(result.Contains(2));
		BOOST_CHECK(!result.Contains(3));
	}	
}

BOOST_AUTO_TEST_CASE(TestDifference)
{
	{
		CMySet<int> first;
		CMySet<int> second;
		CMySet<int> result = first.Difference(second);
		BOOST_CHECK_EQUAL(result.GetSize(), 0);
	}
	{
		CMySet<int> first;
		first.Add(1);
		first.Add(2);
		first.Add(5);
		first.Add(6);
		CMySet<int> second;
		second.Add(3);
		second.Add(2);
		CMySet<int> result;
		result = first.Difference(second);
		BOOST_CHECK_EQUAL(result.GetSize(), 3);
		BOOST_CHECK(result.Contains(1));
		BOOST_CHECK(!result.Contains(2));
		BOOST_CHECK(result.Contains(5));
		BOOST_CHECK(result.Contains(6));
	}	
}

BOOST_AUTO_TEST_CASE(TestSymmetricDifference)
{
	{
		CMySet<int> first;
		CMySet<int> second;
		CMySet<int> result = first.SymmetricDifference(second);
		BOOST_CHECK_EQUAL(result.GetSize(), 0);
	}
	{
		CMySet<int> first;
		first.Add(1);
		first.Add(2);
		first.Add(5);
		first.Add(6);
		CMySet<int> second;
		second.Add(3);
		second.Add(2);
		CMySet<int> result;
		result = first.SymmetricDifference(second);
		BOOST_CHECK_EQUAL(result.GetSize(), 4);
		BOOST_CHECK(result.Contains(1));
		BOOST_CHECK(result.Contains(3));
		BOOST_CHECK(result.Contains(5));
		BOOST_CHECK(result.Contains(6));
		BOOST_CHECK(!result.Contains(2));
	}	
}

BOOST_AUTO_TEST_CASE(TestContainsSubset)
{
	CMySet<int> first;
	first.Add(1);
	first.Add(2);
	first.Add(5);
	first.Add(6);
	CMySet<int> second;
	second.Add(1);
	second.Add(2);
	BOOST_CHECK(first.ContainsSubset(second));
	BOOST_CHECK(!second.ContainsSubset(first));	
}

BOOST_AUTO_TEST_CASE(TestEqual)
{
	{
		CMySet<int> first;
		first.Add(1);
		first.Add(2);
		CMySet<int> second;
		second.Add(1);
		second.Add(2);
		BOOST_CHECK(first.Equal(second));
		BOOST_CHECK(second.Equal(first));
	}
	{
		CMySet<int> first;
		first.Add(1);
		first.Add(2);
		first.Add(5);
		first.Add(6);
		CMySet<int> second;
		second.Add(1);
		second.Add(2);
		BOOST_CHECK(!second.Equal(first));
		BOOST_CHECK(!first.Equal(second));
	}	
}



BOOST_AUTO_TEST_SUITE_END()