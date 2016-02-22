// replace.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ReplaceSubstring(_TCHAR* strForSearch, _TCHAR* subStr, ifstream& inputFile, ofstream& outputFile);

int _tmain(int argc, _TCHAR* argv[])
{	
	if (argc != 5)
	{
		std::cout << "Program replace a substring in the given file, expected <input file> <output file> <search string> <replace string>";
		return 1;
	}

	ifstream inputFile(argv[1]);

	if (!inputFile.is_open())
	{
		std::cout << "Error: cannot open input file\n";
		return 1;
	}
	ofstream outputFile(argv[2]);

	if (!outputFile.is_open())
	{
		std::cout << "Error: cannot open output file\n";
		return 1;
	}
	if (strlen(argv[3]) == 0)
	{
		std::cout << "Empty search string";
		return 1;
	}

	ReplaceSubstring(argv[3], argv[4], inputFile, outputFile);
	outputFile.close();
	return 0;
}

void ReplaceSubstring(_TCHAR* argcStrForSearch, _TCHAR* argcSubstr, ifstream& inputFile, ofstream& outputFile)
{
	string strForSearch = argcStrForSearch;	
	string subStr = argcSubstr;
	string curLine;
	int strForSearchLen = strForSearch.size();
	bool isFirstLine = true;
	while (!inputFile.eof())
	{
		getline(inputFile, curLine);
		int j = 0;
		int matchesCount = 0;
		int curLineLen = curLine.size();
		if (isFirstLine)
		{
			isFirstLine = false;
		}
		else
		{
			outputFile << endl;
		}
		int i = 0;
		while (i < (curLineLen - strForSearchLen + 1))
		{
			bool isStringFound = true;
			if (curLine[i] == strForSearch[0])
			{				
				for (int j = 1; j < strForSearchLen; ++j)
				{
					if (curLine[i + j] != strForSearch[j])
					{
						isStringFound = false;
						break;
					}
				}
				if (isStringFound)
				{
					outputFile << subStr;
					i = i + strForSearchLen;
				}
				else
				{
					outputFile << curLine[i];
					++i;
				}
			}
			else
			{
				outputFile << curLine[i];
				++i;
			}			
		}
		while (i < curLine.size())
		{
			outputFile << curLine[i];
			++i;
		}
	}
}