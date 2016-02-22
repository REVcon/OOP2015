#pragma once
#include <map>


std::map<std::string, int> MakeDictionary();
void ProcessChar(const char &symbol, std::map<std::string, int> &dict, std::string &curWord);
void PrintDictionary(std::map<std::string, int> &dict);