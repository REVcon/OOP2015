// test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../equation3/Solve3.h"
#include <iostream>
#include <math.h>

using namespace std;

double ToRound(double arg)
{
	return trunc(arg * 1000) / 1000;
}

BOOST_AUTO_TEST_SUITE(Solve4Tests)

BOOST_AUTO_TEST_CASE(ExceptionIfAZero)
{
	BOOST_CHECK_THROW(Solve3(0, 1, 1, 1), invalid_argument);
	BOOST_CHECK_NO_THROW(Solve3(1, 1, 1, 1));
}

BOOST_AUTO_TEST_CASE(OneRealRoot)
{
	EquationRoots3 solution;
	{
		solution = Solve3(1, 0, 1, 0);
		BOOST_CHECK_EQUAL(solution.numRoots, 1);
		BOOST_CHECK_EQUAL(solution.roots[0], 0);

	}
	{
		solution = Solve3(1, 9, 1, 1);
		BOOST_CHECK_EQUAL(solution.numRoots, 1);
		BOOST_CHECK_EQUAL(ToRound(solution.roots[0]), -8.900);
	}
	{
		solution = Solve3(1, 6, 12, 1);
		BOOST_CHECK_EQUAL(solution.numRoots, 1);
		BOOST_CHECK_EQUAL(ToRound(solution.roots[0]), -0.087);
	}
}

BOOST_AUTO_TEST_CASE(TwoRealRoots)
{
	{
		EquationRoots3 solution = Solve3(1, 0, 0, 0);
		BOOST_CHECK_EQUAL(solution.numRoots, 2);
		BOOST_CHECK_EQUAL(solution.roots[0], 0);
		BOOST_CHECK_EQUAL(solution.roots[1], 0);
	}
	{
		EquationRoots3 solution = Solve3(1, 1, 0, 0);
		BOOST_CHECK_EQUAL(solution.numRoots, 2);
		BOOST_CHECK_EQUAL(solution.roots[0], -1);
		BOOST_CHECK_EQUAL(solution.roots[1], 0);
	}	
}

BOOST_AUTO_TEST_CASE(ThreeRealRoots)
{
	EquationRoots3 solution = Solve3(1, -4, 1, 1);
	BOOST_CHECK_EQUAL(solution.numRoots, 3);
	BOOST_CHECK_EQUAL(ToRound(solution.roots[0]), -0.377);
	BOOST_CHECK_EQUAL(ToRound(solution.roots[1]), 3.651);
	BOOST_CHECK_EQUAL(ToRound(solution.roots[2]), 0.726);
}

BOOST_AUTO_TEST_SUITE_END()