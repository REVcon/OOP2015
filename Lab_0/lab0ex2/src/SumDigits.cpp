// SumDigits.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <cstdlib>

int SumDigits(int num)
{
	int sum = 0;
	while (num != 0)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

int StringToInt(_TCHAR *str)
{
	int param = atoi(str);
	return param;
}

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc <= 1)
	{
		printf("You must tell a border \n");
		return 0;

	}
	int param = StringToInt(argv[1]);
	if (param == 0)
	{
		printf("Argument is not a number \n");
		return 1;
	}
	
	for (int i = 1; i <= param; ++i)
	{
		if (i % SumDigits(i) == 0)
		{
			printf("%d ", i);
		}
		
	}
	printf("\n");
	system("pause");
	return 0;
}

