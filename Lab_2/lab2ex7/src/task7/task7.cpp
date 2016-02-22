// task7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "SetOfImpermissibleWords.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (argc != 2)
	{
		cout << "Invalid parametrs, expected <input file>.\n";
		return 1;
	}
	if (!WasLoaded(argv[1]))
	{
		cout << "Invalid input data.\n";
		return 1;
	}
	string curStr, word;
	string symbols = " \n\t(){}[]+-/*";
	while (getline(cin, curStr))
	{
		int b, e = 0;
		curStr.push_back('\n');
		while ((b = curStr.find_first_not_of(symbols, e)) != curStr.npos)
		{
			e = curStr.find_first_of(symbols, b);
			word = curStr.substr(b, e - b);
			if (IsImpermissible(word))
			{
				curStr.erase(b, e - b);
				e = b;
			}
			else
			{
				b = e;
			}
		}
		cout << curStr;
	}
	return 0;
}

