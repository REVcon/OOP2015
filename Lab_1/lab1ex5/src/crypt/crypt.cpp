// crypt.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

const unsigned char cryptArr[8] = { 2, 3, 4, 6, 7, 0, 1, 5 };
const unsigned char decryptArr[8] = { 5, 6, 0, 1, 2, 7, 3, 4 };

unsigned char StringToInt(_TCHAR* str, bool &err)
{
	char *pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0') || (param < 0) || (param > 255));
	return param;
}

char Shuffle(unsigned char param, const unsigned char shuffleArr[])
{
	unsigned char result(0);
	for (int i = 0; i < 8; ++i)
	{
		result = (((param >> i) & 1) << (shuffleArr[i])) | result;
	}
	return result;
}

bool Crypt(_TCHAR* inpFileName, _TCHAR* outFileName, unsigned char key)
{
	ifstream inpFile(inpFileName);
	if (!inpFile.is_open())
	{
		return false;
	}
	ofstream outFile(outFileName);
	if (!outFile.is_open())
	{
		return false;
	}
	char curCh;
	while (inpFile.get(curCh))
	{
		curCh = Shuffle(curCh ^ key, cryptArr);
		outFile << curCh;
	}
	return true;
}

bool Decrypt(_TCHAR* inpFileName, _TCHAR* outFileName, unsigned char key)
{
	ifstream inpFile(inpFileName);
	if (!inpFile.is_open())
	{
		return false;
	}
	ofstream outFile(outFileName);
	if (!outFile.is_open())
	{
		return false;
	}
	char curCh;
	while (inpFile.get(curCh))
	{
		curCh = Shuffle(curCh, decryptArr) ^ key;
		outFile << curCh;
	}
	return true;
}


int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 5)
	{
		cout << "Invalid parametrs, expected <command> <input file> <output file> <key>(number in range 0-255)\n";
		return 1;

	}
	bool isInvalidKey = false;
	unsigned char key = StringToInt(argv[4], isInvalidKey);
	if (isInvalidKey)
	{
		cout << "The key must be in range from 0 to 255\n";
		return 1;
	}
	bool withoutErr = false;
	if ((strcmp(argv[1], "crypt") == 0))
	{
		withoutErr = Crypt(argv[2], argv[3], key);
	}
	else if ((strcmp(argv[1], "decrypt") == 0))
	{
		withoutErr = Decrypt(argv[2], argv[3], key);
	}
	else
	{
		cout << "Invalid command, expected <crypt/decrypt>\n";
		return 1;
	}	
	if (!withoutErr)
	{
		cout << "Error opening file\n ";
		return 1;
	}
	return 0;
}

