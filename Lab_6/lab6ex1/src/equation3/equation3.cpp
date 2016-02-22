// equation3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Solve3.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Enter coefs of cubic equation\n";
	double a, b, c, d;
	while (!cin.eof())
	{
		if (cin >> a >> b >> c >> d)
		try
		{
			auto sol = Solve3(a, b, c, d);
			cout << fixed;
			for (int i = 0; i < sol.numRoots; ++i)
			{
				cout << setprecision(3) << sol.roots[i] << ' ';
			}
			cout << endl;
		}
		catch (exception const& e)
		{
			cout << e.what() << endl;
		}
	}

	return 0;
}