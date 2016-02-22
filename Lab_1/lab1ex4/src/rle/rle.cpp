// rle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

bool Pack(_TCHAR* inpFileName, _TCHAR* outFileName)
{
	ifstream inpFile(inpFileName, ios::binary);
	if(!inpFile.is_open())
	{
		return false;
	}
	ofstream outFile(outFileName, ios::binary);
	if (!outFile.is_open())
	{
		return false;
	}
	unsigned char repCount = 1;
	char prevCh;
	inpFile.read(&prevCh, sizeof(prevCh));
	char curCh;
	while (inpFile.read(&curCh, sizeof(curCh)))
	{		
		if (curCh == prevCh && repCount < 255)
		{
			repCount++;
		}
		else
		{
			outFile.write((char*)&repCount, sizeof(repCount));
			outFile.write(&prevCh, sizeof(prevCh));
			repCount = 1;
			prevCh = curCh;
		}		
	}
	outFile.write((char*)&repCount, sizeof(repCount));
	outFile.write(&curCh, sizeof(curCh));
	outFile.close();
	return true;
}

bool Unpack(_TCHAR* inpFileName, _TCHAR* outFileName)
{
	ifstream inpFile(inpFileName);
	if (!inpFile.is_open())
	{
		return false;
	}
	inpFile.seekg(0, inpFile.end);
	int fileSize = inpFile.tellg();
	inpFile.seekg(0, inpFile.beg);
	if (fileSize % 2 != 0)
	{
		return false;
	}
	ofstream outFile(outFileName);
	if (!outFile.is_open())
	{
		return false;
	}
	unsigned char repCount = 0;
	char curCh;
	while ((inpFile.read((char*)&repCount, sizeof(repCount))) && (inpFile.read(&curCh, sizeof(curCh))))
	{
		if (repCount == 0)
		{
			outFile.close();
			return false;
		}
		else
		{
			for (int i = 0; i < repCount; ++i)
			{
				outFile << curCh;
			}
			repCount = 0;
		}
	}
	outFile.close();
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 4)
	{
		cout << "Invalid parametrs, expected <pack/unpack> <input file> <output file>\n";
		return 1;
	}
	bool withoutErr = false;
	if ((strcmp(argv[1], "pack") == 0))
	{
		withoutErr = Pack(argv[2], argv[3]);
	}
	else if ((strcmp(argv[1], "unpack") == 0))
	{
		withoutErr = Unpack(argv[2], argv[3]);
	}
	else
	{
		cout << "Invalid command";
		return 1;
	}
	if (!withoutErr)
	{
		cout << "Invalid data\n";
		return 1;
	}
	return 0;
}

