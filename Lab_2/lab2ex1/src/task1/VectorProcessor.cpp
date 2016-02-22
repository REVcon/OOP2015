#include "stdafx.h"
#include "VectorProcessor.h"
#include <numeric>

using namespace std;


void ProcessVector(std::vector<double> & numbers)
{
	auto IsPos = [](double number){return number > 0; };
	auto sumOfPositives = accumulate(
		numbers.begin(), numbers.end(),
		0.0,
		[](double acc, double current) {
		if (current > 0.0)
		{
			return acc + current;
		}
		return acc;
	});
	bool isEven = false;
	for_each(numbers.begin(), numbers.end(), [sumOfPositives, &isEven](double &number){
		if (isEven)
		{
			number *= 2;
			isEven = false;
		}
		else
		{
			number -= sumOfPositives;
			isEven = true;
		}
	});
}