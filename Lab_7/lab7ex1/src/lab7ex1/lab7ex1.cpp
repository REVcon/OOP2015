#include "stdafx.h"
#include "assert.h"
#include <string>
using namespace std;

template <typename T, typename Comp = std::less<T>>
bool FindMax(std::vector<T> const& arr, T &maxValue, Comp const& comp = std::less<T>())
{
	if (arr.empty())
	{
		return false;
	}

	size_t max = 0;
	for (size_t i = 1; i < arr.size(); ++i)
	{
		if (comp(arr[max], arr[i]))
		{
			max = i;
		}
	}
	maxValue = arr[max];
	return true;
}

struct Sportsman
{
	string name;
	int weight;
	int height;
};


void main()
{
	std::vector<int> a = { 1, 4, -2, 0, 12, -6 };
	int max;
	assert(FindMax(a, max));
	assert(max == 12);

	std::vector<string> strings = { "cat", "dog", "apple", "cow" };
	string maxString;
	assert(FindMax(strings, maxString));
	assert(maxString == "dog");


	vector<Sportsman> sportsman = {
		{ "Ivan Petrov", 100, 150 },
		{ "Eugene Dolgushev", 87, 188 },
		{ "Vladimir Alitov", 62, 175 },
		{"Mike Tayson", 100, 190 },
		{ "Fedor Emelyanenko", 110, 189}
	};
	Sportsman tallestSportsman;
	assert(FindMax(sportsman, tallestSportsman, [](Sportsman const& a, Sportsman const& b){
		return a.height < b.height;
	}));
	assert(tallestSportsman.name == "Mike Tayson");
	Sportsman heaviestSportsman;
	assert(FindMax(sportsman, heaviestSportsman, [](Sportsman const& a, Sportsman const& b){
		return a.weight < b.weight;
	}));
	assert(heaviestSportsman.name == "Fedor Emelyanenko");
}