#include "stdafx.h"
#include "SetOfImpermissibleWords.h"

using namespace std;
set<string> impermissibleWords;

bool WasLoaded(_TCHAR* fileName)
{
	ifstream inpFile(fileName);
	if (!inpFile.is_open())
	{
		return false;
	}
	string curWord;
	while (inpFile >> curWord)
	{
		impermissibleWords.insert(curWord);
	}
	inpFile.close();
	return true;
}

bool IsImpermissible(string const& arg)
{
	string wordLowerCase = ToLower(arg);
	set<string>::iterator it;
	it = impermissibleWords.find(wordLowerCase);
	if (it != impermissibleWords.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

string ToLower(string const& arg)
{
	string wordLowerCase;
	for (size_t i = 0; i < arg.size(); ++i)
	{
		if (arg[i] >= -64 && arg[i] <= -33)
		{
			wordLowerCase.push_back((arg[i] + 32));
		}
		else if (arg[i] == -88)
		{
			wordLowerCase.push_back((arg[i] + 16));
		}
		else
		{
			wordLowerCase.push_back(tolower(arg[i]));
		}		
	}
	return wordLowerCase;
}