#include "stdafx.h"
#include "Solve3.h"
#include <complex>
#include <math.h>

using namespace std;

bool IsEqualy(double num1, double num2)
{
	return std::abs(num1 - num2) < DBL_EPSILON;
}

double sgn(double arg)
{
	if (IsEqualy(arg, 0))
	{
		return 0;
	}
	if (arg > 0)
	{
		return 1;
	}
	return -1;
}

EquationRoots3 CardanoViete(double a, double b, double c)
{
	long double Q = ((a * a) - 3 * b) / 9;
	long double R = (2 * pow(a, 3) - 9 * a * b + 27 * c) / 54;
	double S = pow(Q, 3) - pow(R, 2);
	EquationRoots3 solution;
	if (IsEqualy(S, 0))
	{
		solution.numRoots = 2;
		double u = 
		solution.roots[0] = -2 * cbrt(R) - a / 3;
		solution.roots[1] = cbrt(R) - a / 3;
	}
	else if (S < 0)
	{
		solution.numRoots = 1;
		if (IsEqualy(Q, 0))
		{
			solution.roots[0] = -cbrt(c - (pow((a), 3.0) / 27)) - (a / 3.0);
		}
		else if (Q > 0)
		{
			long double phi = (1.0 / 3.0) * acosh(abs(R) / sqrt(pow(Q, 3.0)));
			solution.roots[0] = -2.0 * sgn(R) * sqrt(abs(Q)) * cosh(phi) - a / 3;
		}
		else
		{
			long double phi = (1.0 / 3.0) * asinh(abs(R) / sqrt(pow(abs(Q), 3)));
			solution.roots[0] = -2.0 * sgn(R) * sqrt(abs(Q)) * sinh(phi) - a / 3;
		}
		
	}
	else 
	{
		solution.numRoots = 3;
		double phi = (1.0 / 3) * acos(R / sqrt(pow(Q, 3)));
		solution.roots[0] = -2 * sqrt(Q) * cos(phi) - a / 3;
		solution.roots[1] = -2 * sqrt(Q) * cos(phi + (2.0 * M_PI) / 3) - a / 3;
		solution.roots[2] = -2 * sqrt(Q) * cos(phi - (2.0 * M_PI) / 3) - a / 3;
	}
	return solution;
}


EquationRoots3 Solve3(double a, double b, double c, double d)
{
	if (IsEqualy(a, 0))
	{
		throw invalid_argument("This equation not cubic!");
	}

	b /= a;
	c /= a;
	d /= a;
	return CardanoViete(b, c, d);
}