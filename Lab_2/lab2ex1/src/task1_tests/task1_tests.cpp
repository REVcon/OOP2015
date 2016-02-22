// task1_tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../task1/VectorProcessor.h"

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}

BOOST_AUTO_TEST_CASE(EmptyVectorProducesEmptyVector)
{
	vector<double> emptyVector;
	ProcessVector(emptyVector);
	BOOST_CHECK(emptyVector.empty());
}


BOOST_AUTO_TEST_CASE(VectorWithOneNotPositiveUnevenElement)
{
	vector<double> numbers = { -1 };
	ProcessVector(numbers);
	BOOST_CHECK(VectorsAreEqual(numbers, { -1 }));
}

BOOST_AUTO_TEST_CASE(VectorWithoutPositivesDoesNotChangeUnevenElem)
{
	vector<double> numbers = { -4, 0, -3 };
	vector<double> copy = { -4, 0, -3 };
	ProcessVector(numbers);
	BOOST_CHECK(numbers == copy);
}

BOOST_AUTO_TEST_CASE(VectorWithOnePositiveElement)
{
	vector<double> numbers = { -1, 3 };
	ProcessVector(numbers);
	BOOST_CHECK(VectorsAreEqual(numbers, { -4, 6 }));
}

BOOST_AUTO_TEST_CASE(VectorWithSeveralPositivesElements)
{
	vector<double> numbers = { 1, 2, 3 };
	ProcessVector(numbers);
	BOOST_CHECK(VectorsAreEqual(numbers, { -5, 4, -3 }));
}