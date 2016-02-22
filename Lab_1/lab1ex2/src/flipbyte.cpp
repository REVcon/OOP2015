// flipbyte.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "stdlib.h"

using namespace std;

const unsigned char size = 8;

unsigned char StringToInt(const char *str, bool &err);
unsigned char FlipByte(short int *param);

int _tmain(int argc, _TCHAR* argv[])
{
	bool err;
	if (argc != 2)
	{
		printf("Program takes a number and flips bites therein \n");
		return 1;
	}

	short int param = StringToInt(argv[1], err);
	if (err)
	{
		printf("Program takes a number in the range 0-255 \n");
		return 1;
	}

	param = FlipByte(&param);
	printf("%d", param);
	return 0;
}

unsigned char StringToInt(const char *str, bool &err)
{
	char *pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0') || (param > 255) || (param < 0));
	return param;
}

unsigned char FlipByte(short int* param)
{
	unsigned short int result(0);
	for (int i = 0; i < size; ++i)
	{
		result = (((*param >> i) & 1) << (size - i - 1)) | result;
	}
	return result;
}