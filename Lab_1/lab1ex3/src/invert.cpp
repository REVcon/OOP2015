// invert.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

bool WasInputDataRead(char const *nameInpFile, double inpMatrix[][3]);
double CalculateInpMatrixDet(double inpMatrix[][3]);
void CalcuateInvMatrix(double inpMatrix[][3], double invMatrix[][3]);

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid parametrs, expected <input file>";
		return 1;
	}
	double inpMatrix[3][3];
	if (!WasInputDataRead(argv[1], inpMatrix))
	{
		cout << "Error: cannot read input data\n";
		return 1;
	}
	if (CalculateInpMatrixDet(inpMatrix) == 0.0)
	{
		cout << "Impossible to find the inverse matrix for a given\n";
		return 1;
	}
	double invMatrix[3][3];
	CalcuateInvMatrix(inpMatrix, invMatrix);
	for (int i = 0; i < 3; ++i)
	{
		cout << fixed << setprecision(3) << invMatrix[i][0] << " " << invMatrix[i][1] << " " << invMatrix[i][2];
		if (i != 2)
		{
			cout << endl;
		}
	}
	return 0;	
}

bool WasInputDataRead(char const *nameInpFile, double inpMatrix[][3])
{
	ifstream inpFile(nameInpFile);
	if (!inpFile.is_open())
	{
		return false;
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (!(inpFile >> inpMatrix[i][j]))
			{
				return false;
			}

		}
	}
	return true;
}

double CalculateInpMatrixDet(double inpMatrix[][3])
{
	return inpMatrix[0][0] * ((inpMatrix[1][1] * inpMatrix[2][2]) - (inpMatrix[1][2] * inpMatrix[2][1])) -
		inpMatrix[0][1] * ((inpMatrix[1][0] * inpMatrix[2][2]) - (inpMatrix[1][2] * inpMatrix[2][0])) +
		inpMatrix[0][2] * ((inpMatrix[1][0] * inpMatrix[2][1]) - (inpMatrix[1][1] * inpMatrix[2][0]));
}

double CalculateDetMatrix2x2(double a1, double a2, double b1, double b2)
{
	return (a1 * b2) - (a2 * b1);
}

void CalcuateInvMatrix(double inpMatrix[][3], double invMatrix[][3])
{
	double adjMatrix[3][3];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if ((i == 1 && j != 1) || (i != 1 && j == 1))
			{
				adjMatrix[i][j] = -CalculateDetMatrix2x2(inpMatrix[(i + 1) % 3][(j + 2) % 3], inpMatrix[(i + 1) % 3][(j + 1) % 3],
					inpMatrix[(i + 2) % 3][(j + 2) % 3], inpMatrix[(i + 2) % 3][(j + 1) % 3]);
			}
			else
			{
				adjMatrix[i][j] = CalculateDetMatrix2x2(inpMatrix[(i + 1) % 3][(j + 1) % 3], inpMatrix[(i + 1) % 3][(j + 2) % 3],
					inpMatrix[(i + 2) % 3][(j + 1) % 3], inpMatrix[(i + 2) % 3][(j + 2) % 3]);
			}
		}
	}
	double det = CalculateInpMatrixDet(inpMatrix);
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			invMatrix[j][i] = adjMatrix[i][j] / det;
		}
	}
}

