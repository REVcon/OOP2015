
#include "stdafx.h"
#include <stdio.h>
#include <cstdlib>
#include <conio.h>


int StringToInt(_TCHAR* str, bool &err)
{
	char *pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

int _tmain(int argc, _TCHAR* argv[])
{
	bool err;
	int count = 0;
	if (argc <= 1)
	{
		printf("You must tell a border \n");
		return 0;

	}
	int param = StringToInt(argv[1], err);
	if (err)
	{
		printf("Argument is not a number \n");
		return 1;
	}
	if ((param < 1) || (param > 47))
	{
		printf("Too big or too small number \n");
		_getch();
		return 0;
	}
	if (param >= 1)
	{
		printf("%d", 1);
		count++;
	}
	if (param >= 2)
	{
		printf(", %d", 1);
		count++;
	}
	long int fib1 = 1;
	long int fib2 = 0;
	long int fibn = 0;
	for (int i = 3; i <= param; ++i)
	{
		if (count == 5)
		{ 
			count = 0;
			fibn = fib1 + fib2;
			fib2 = fib1;
			fib1 = fibn;
			printf(",\n%d", fibn);
		}
		else
		{
			count++;
			fibn = fib1 + fib2;
			fib2 = fib1;
			fib1 = fibn;
			printf(", %d", fibn);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}