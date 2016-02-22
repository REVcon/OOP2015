// task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "RemoveExtraSpaces.h"

using namespace std;

void RemoveExtraSpacesInStream(istream &inpStream, ostream &outStream)
{
	vector <string> textWithoutSpaces;
	string curLine;
	while (getline(inpStream, curLine))
	{
		textWithoutSpaces.push_back(RemoveExtraSpaces(curLine));
	}
	copy(textWithoutSpaces.begin(), textWithoutSpaces.end(), ostream_iterator<string>(outStream, "\n"));
}

int _tmain(int argc, _TCHAR* argv[])
{
	RemoveExtraSpacesInStream(cin, cout);
	return 0;
}

