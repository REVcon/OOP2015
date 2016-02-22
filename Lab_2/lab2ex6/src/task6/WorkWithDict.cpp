#include "stdafx.h"
#include "WorkWithDict.h"

using namespace std;

bool WasInpDictRead(_TCHAR* dictName, map<string,string> &dictionary)
{
	ifstream inpDict(dictName);
	if (!inpDict.is_open())
	{
		return false;
	}
	string key, value, curLine;
	while (getline(inpDict, curLine))
	{
		int pos = curLine.find("]");
		if (pos == string::npos)
		{
			return false;
		}
		key = curLine.substr(0, pos + 1);
		value = curLine.substr(pos + 2);
		if ((key[0] != '[') || (key[key.size() - 1] != ']'))
		{
			return false;
		}
		key = key.substr(1, key.size() - 2);
		auto it = dictionary.find(key);
		if (it == dictionary.end())
		{
			dictionary[key] = value;
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool WasFoundInDictionary(string const& curQuery, string& curAnswer, map<string, string> &dictionary)
{
	auto it = dictionary.find(curQuery);
	if (it == dictionary.end())
	{
		curAnswer = "";
		return false;
	}
	else
	{
		curAnswer = dictionary[curQuery];
		return true;
	}
}

void AddToDict(string const& curQuery, string const& translation, map<string, string> &dictionary)
{
	dictionary[curQuery] = translation;
}

void RemoveExtraSpaces(string& arg)
{
	bool ignoreSpaces = true;
	bool wasNotSpace = false;
	string result;
	size_t strLen = arg.length();
	for (size_t i = 0; i < strLen; i++)
	{
		if (arg[i] == ' ')
		{
			ignoreSpaces = true;
		}
		else
		{
			if (wasNotSpace && ignoreSpaces)
			{
				result.push_back(' ');
			}
			result.push_back(arg[i]);
			wasNotSpace = true;
			ignoreSpaces = false;
		}
	}
	arg = result;
}

bool IsCorrectQuery(string& query)
{
	RemoveExtraSpaces(query);
	unsigned int len = query.size();
	if (len > 0)
	{
		for (size_t i = 0; i < len; ++i)
		{
			if (query[i] != ' ')
			{
				if (!((query[i] >= 'a' && query[i] <= 'z') || (query[i] <= 'Z' && query[i] >= 'A')))
				{
					return false;
				}
			}			
		}		
		ToLower(query);
		return true;
	}
	else
	{
		return false;
	}
}

void ToLower(string& arg)
{
	string result;
	transform(arg.begin(), arg.end(), back_inserter(result), [](char curCh){
		return tolower(curCh);
	});
	arg = result;
}

bool SaveChanges(_TCHAR* dictName, map<string, string> &dictionary)
{
	cout << "В словарь были внесены изменения. Введите Y или у для сохранения перед выходом.\n";
	char answer;
	cin.get(answer);
	if (tolower(answer) == 'y')
	{
		ofstream dict(dictName);
		if (!dict.is_open())
		{
			return false;
		}
		for (auto &it : dictionary)
		{
			dict << "[" << it.first << "] " << it.second << endl;
		}
		dict.close();
		return true;
	}
	return false;
}



void DialogWithUser(map<string, string>& dictionary, bool &wasChanges)
{
	string curQuery, curAnswer;
	bool toContinue = true;
	do
	{
		if (!getline(cin, curQuery))
		{
			toContinue = false;
		}
		else if (curQuery == "...")
		{
			toContinue = false;
		}
		else if (!IsCorrectQuery(curQuery))
		{
			cout << "Введите английское слово или словосочетание для перевода.\n";
			continue;
		}
		else
		{
			if (WasFoundInDictionary(curQuery, curAnswer, dictionary))
			{
				cout << curAnswer << endl;
			}
			else
			{
				cout << "Неизвестное слово \"" << curQuery << "\". Введите перевод или пустую строку для отказа.\n";
				string translation;
				if (getline(cin, translation))
				{
					RemoveExtraSpaces(translation);
					if (translation.size() > 0)
					{
						AddToDict(curQuery, translation, dictionary);
						wasChanges = true;
						cout << "Слово \"" << curQuery << "\" сохранено в словаре как \"" << translation << "\".\n";
					}
					else
					{
						cout << "Слово \"" << curQuery << "\" проигнорировано.\n";
					}
				}
				else
				{
					toContinue = false;
				}
			}
		}
	} while (toContinue);
}