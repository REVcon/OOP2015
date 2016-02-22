#include "stdafx.h"
#include "GenerateSet.h"


using namespace std;

std::set <int> GeneratePrimeNumbersSet(int upperBound)
{
	set <int> primeSet;
	if (upperBound < 2)
	{
		return primeSet;
	}
	vector <bool> isPrime(upperBound + 1, true);
	for (int i = 2; i <= sqrt(upperBound); ++i)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= upperBound; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	for (int i = 2; i <= upperBound; ++i)
	{
		if (isPrime[i])
		{
			primeSet.insert(i);
		}
	}
	return primeSet;
}