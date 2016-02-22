// CalculateDistance.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "math.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define G 9.8
#define PI 3.14159265

double StringToInt(const char* str, bool &err)
{
	char *pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

double CalculateDistance(double v0, double a0)
{
	double distance = (pow(v0, 2) * sin(2*a0*PI / 180))/G;
	return distance;
}

int _tmain(int argc, _TCHAR* argv[])
{
	double v0 = 0;
	double a0 = 0;
	string strTemp;
	bool err;
	while (true)
	{
		do
		{
			cout << "Enter v0 (or type 'exit')>";
			getline(cin, strTemp);
			if (strTemp == "exit")
			{
				cout << "Goodbye" << endl;
				return 0;
			}			
			v0 = StringToInt(strTemp.c_str(), err);
		}while (err);

		do
		{
			cout << "Enter a0 (or type 'exit')>";
			getline(cin, strTemp);
			if (strTemp == "exit")
			{
				cout << "Goodbye" << endl;
				return 0;
			}			
			a0 = StringToInt(strTemp.c_str(), err);
		} while (err);
		
		double distance = CalculateDistance(v0, a0);
		cout << "Distance is: " << fixed << setprecision(3) << distance << endl;
	}
	return 0;
}