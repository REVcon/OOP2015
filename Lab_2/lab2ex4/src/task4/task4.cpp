// task4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "GenerateSet.h"

using namespace std;

int StringToInt(const char* str, bool &err)
{
	char *pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

int _tmain(int argc, _TCHAR* argv[])
{
	bool err;
	if (argc != 2)
	{
		cout << "Invalid parametrs\n";
		return 1;
	}
	int param = StringToInt(argv[1], err);
	if (err)
	{
		cout << "Argument is not a number\n";
		return 1;
	}

	if (param > 100000000)
	{
		cout << "Upper bound must be < 100000000";
		return 1;
	}
	auto primeNumbers = GeneratePrimeNumbersSet(param);
	copy(primeNumbers.begin(), primeNumbers.end(), ostream_iterator<int>(cout, "  "));
	return 0;
}

