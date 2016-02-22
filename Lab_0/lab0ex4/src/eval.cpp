// eval.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdlib.h"

double StringToInt(_TCHAR* str, bool &err)
{
	char *pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc <= 1)
	{
		printf("Program calculates the expression entered in the command line.\n");
		return 0;
	}

	double firstArg = 0, secondArg = 0;

	for (int i = 1; i < argc; i +=2)
	{
		bool err;		
		double param = StringToInt(argv[i], err);
		if (err)
		{
			printf("Argument #%d is uncorrect\n", i);
			printf("%s", argv[i]);
			return 1;
		}
		printf("%s ", argv[i]);
		if (i != argc - 1)
		{
			printf("%s ", argv[i + 1]);
		}		
		firstArg = secondArg;
		secondArg = param;
		if (i > 2)
		{
			if (argv[i - 1][0] == '+')
			{
				secondArg = firstArg + secondArg;
			}
			else if (argv[i - 1][0] == '-')
			{
				secondArg = firstArg - secondArg;
			}
			else if (argv[i - 1][0] == '*')
			{
				secondArg = firstArg * secondArg;
			}
			else if (argv[i - 1][0] == '/')
			{
				if (secondArg != 0)
				{
					secondArg = firstArg / secondArg;
				}
				else
				{
					printf("Operation #%d is uncorrect\n", i - 1);
					return 1;
				}
			}
			else
			{
				printf("Operation #%d is uncorrect\n", i - 1);
				return 1;
			}
		}			
	}
	printf("= %.3lf", secondArg);
	return 0;
}

