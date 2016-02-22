#pragma once
#include <string>

using namespace std;

bool WasInpDictRead(_TCHAR* dictName, map<string, string> &dictionary);
void DialogWithUser(map<string,string> &dictionary, bool &wasChanges);
bool WasFoundInDictionary(string const & curQuery, string & curAnswer, map<string, string> &dictionary);
void AddToDict(string const& curQuery, string const& translation, map<string, string> &dictionary);
void RemoveExtraSpaces(string& arg);
bool IsCorrectQuery(string & query);
void ToLower(string& arg);
bool SaveChanges(_TCHAR* dictName, map<string, string> &dictionary);