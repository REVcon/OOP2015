#include "stdafx.h"
#include "../task3/MakeDictionary.h"
#include <string>

using namespace std;

bool MapsAreEqual(map <string, int> const& x, map <string, int> const& y)
{
	return x == y;
}

BOOST_AUTO_TEST_CASE(EmptyMap)
{
	string input = "";
	map <string, int> result;
	string word;
	for (size_t i = 0; i < input.size(); ++i)
	{
		ProcessChar(input[i], result, word);
	}
	BOOST_CHECK(result.empty());
}

