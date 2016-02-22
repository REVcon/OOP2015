#include "MakeDictionary.h"
#include "stdafx.h"

using namespace std;

void ProcessChar(const char &curCh, map<string, int> &dict, string &curWord)
{
	if (curCh == ' ' || curCh == '\t' || curCh == '\n')
	{
		if (curWord != "")
		{
			map <string, int>::iterator it = dict.find(curWord);
			if (it != dict.end())
			{
				dict[curWord]++;
			}
			else
			{
				dict[curWord] = 1;
			}
		}
		curWord = "";
	}
	else
	{
		curWord.push_back(curCh);
	}
}

map<string, int>  MakeDictionary()
{
	string curWord = "";
	map <std::string, int> dict;
	char curCh;
	while (cin.get(curCh))
	{
		ProcessChar(curCh, dict, curWord);
	}
	return dict;	
}


void PrintDictionary(std::map<string, int> &dict)
{
	for (auto it : dict)
	{
		cout << it.first << "->" << it.second << '\n';
	}
}
