// digits.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>


int _tmain(int argc, _TCHAR* argv[])
{
	bool isFirst = true;
	for (int i = 100; i > 1; (i -= 2))
	{
		if (isFirst)
		{
			printf("%d", i);
			isFirst = false;
		}
		else
		{
			printf(", %d", i);
		}
	}
	printf("\n");
	_getch();
	return 0;
}

