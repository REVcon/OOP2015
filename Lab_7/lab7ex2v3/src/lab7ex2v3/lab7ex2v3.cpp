// lab7ex2v3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MySet.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void PrintDifference(CMySet<string> const& first, CMySet<string> const& second)
{
	CMySet<string> result = first.Difference(second);
	for (size_t i = 1; i <= result.GetSize(); ++i)
	{
		cout << result.GetElement(i) << endl;
	}
}

CMySet<string> VectorToSet(vector<string> const &array)
{
	CMySet<string> result;
	for (size_t j = 0; j < array.size(); ++j)
	{
		result.Add(array[j]);
	}
	return result;
}

CMySet<string> ChooseParticipants(CMySet<string> & set)
{
	srand(0);
	int count = 5;
	CMySet<string> result;
	while (count > 0)
	{
		size_t index = rand() % 15;
		string elem = set.GetElement(index);
		if (!result.Contains(elem))
		{
			result.Add(elem);
			count--;
		}
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> firstGroup = { "AAlitov", "ABogdanov", "ABorisov", "AVeselov", "AVinokurov", "AGavrilenko", "ADolgushev",
		"AEmelyanov", "AEfremov", "AJiryakov", "AIvanov", "AKalinnikov", "AKirillov", "AKornev", "AKorotkov" };
	vector<string> secondGroup = { "BAlitov", "BBogdanov", "BBorisov", "BVeselov", "BVinokurov", "BGavrilenko", "BDolgushev",
		"BEmelyanov", "BEfremov", "BJiryakov", "BIvanov", "BKalinnikov", "BKirillov", "BKornev", "BKorotkov" };
	vector<string> thirdGroup = { "CAlitov", "CBogdanov", "CBorisov", "CVeselov", "CVinokurov", "CGavrilenko",
		"CDolgushev", "CEmelyanov", "CEfremov", "CJiryakov", "CIvanov", "CKalinnikov", "CKirillov", "CKornev", "CKorotkov" };
	CMySet<string> firstGroupSet = VectorToSet(firstGroup);
	CMySet<string> secondGroupSet = VectorToSet(secondGroup);
	CMySet<string> thirdGroupSet = VectorToSet(thirdGroup);
	CMySet<string> firstGrParticipants = ChooseParticipants(firstGroupSet);
	CMySet<string> secondGrParticipants = ChooseParticipants(secondGroupSet);
	CMySet<string> thirdGrParticipants = ChooseParticipants(thirdGroupSet);
	CMySet<string> participants = firstGrParticipants.Union(secondGrParticipants).Union(thirdGrParticipants);
	CMySet<string> winners;
	srand(0);
	int count = 3;
	while (count > 0)
	{
		size_t index = rand() % 15;
		string elem = participants.GetElement(index);
		if (!winners.Contains(elem))
		{
			winners.Add(elem);
			--count;
		}
	}
	PrintDifference(firstGrParticipants, winners);
	PrintDifference(secondGrParticipants, winners);
	PrintDifference(thirdGrParticipants, winners);
	return 0;
}

