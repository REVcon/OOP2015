// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "VectorProcessor.h"

using namespace std;

int _tmain()
{
	vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));
	ProcessVector(numbers);
	sort(numbers.begin(), numbers.end(), [](double i, double j){
		return (i < j);
	});
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, ", "));	
	cout << "\nSize of vector: " << numbers.size() << "\n";
	
	return 0;
}