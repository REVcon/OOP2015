// labyrinth.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iostream>

const int maxSize = 100;
const int block = -2;
const int initValue = -3;
const int wayValue = -1;
const int startValue = 1;
const int access = 0;

using namespace std;


struct coordinates
{
	int y;
	int x;
};

int** Init()
{
	int **inpMap = new int*[maxSize];
	for (int i = 0; i < maxSize; ++i)
	{
		inpMap[i] = new int[maxSize];
		for (int j = 0; j < maxSize; ++j)
		{
			inpMap[i][j] = initValue;
		}
	}
	return inpMap;
}

void FreeMemory(int **inpMap)
{
	for (int i = 0; i < maxSize; ++i) 
	{
		delete inpMap[i];
	}
	delete[] inpMap;
}

bool WasInputDataRead(_TCHAR* inpFileName, int **inpMap, int& strCount, coordinates &beginPoint, coordinates &endPoint)
{
	ifstream inpFile(inpFileName);
	if (!inpFile.is_open())
	{
		return false;
	}
	string curStr;
	curStr.reserve(maxSize);
	bool wasBeginFound = false;
	bool wasEndFound = false;
	int j = 0;
	while (getline(inpFile, curStr))
	{
		int strLen = curStr.size();
		if (strLen > maxSize)
		{
			inpFile.close();
			return false;
		}
		if (strCount == maxSize)
		{
			inpFile.close();
			return false;
		}
		for (size_t i = 0; i < curStr.size(); ++i)
		{
			if (curStr[i] == ' ')
			{
				inpMap[j][i] = access;
			}
			else if (curStr[i] == 'A')
			{
				inpMap[j][i] = startValue;
				beginPoint.x = i;
				beginPoint.y = j;
				wasBeginFound = true;
			}
			else if (curStr[i] == 'B')
			{
				endPoint.x = i;
				endPoint.y = j;
				inpMap[j][i] = access;
				wasEndFound = true;
			}
			else if (curStr[i] == '#')
			{
				inpMap[j][i] = block;
			}
			else
			{
				return false;
			}
		}
		++j;
		strCount++;
	}
	if (wasBeginFound && wasEndFound)
	{
		return true;
	}
	return false;
}

bool Wave(int** inpMap, coordinates const endPoint)
{
	int curStep = 0;
	bool isChanged = false;
	do
	{
		isChanged = false;
		curStep++;
		for (int r = 0; r < maxSize; r++)
		{
			for (int c = 0; c < maxSize; c++)
			{
				if (inpMap[r][c] == curStep)
				{
					if (c < (maxSize - 1))
					{
						if (inpMap[r][c + 1] == 0)
						{
							inpMap[r][c + 1] = curStep + 1;
							isChanged = true;
						}							
					}
					if (r < (maxSize - 1))
					{
						if (inpMap[r + 1][c] == 0)
						{
							inpMap[r + 1][c] = curStep + 1;
							isChanged = true;
						}
					}

					if (r > 0)
					{
						if (inpMap[r - 1][c] == 0)
						{
							inpMap[r - 1][c] = curStep + 1;
							isChanged = true;
						}
					}

					if (c > 0)
					{
						if (inpMap[r][c - 1] == 0)
						{
							inpMap[r][c - 1] = curStep + 1;
							isChanged = true;
						}
					}					
				}
			}
		}

	} while ((inpMap[endPoint.y][endPoint.x] == 0) && (isChanged));
	return isChanged;
}

void FindWay(int **inpMap, coordinates const beginPoint, coordinates const endPoint)
{
	int curStep = inpMap[endPoint.y][endPoint.x];
	inpMap[endPoint.y][endPoint.x] = wayValue;
	int r = endPoint.y;
	int c = endPoint.x;
	do
	{
		if (r < (maxSize - 1))
		{
			if (inpMap[r + 1][c] == curStep - 1)
			{
				inpMap[r + 1][c] = wayValue;
				r += 1;
				continue;
			}
		}
		if (c > 0)
		{
			if (inpMap[r][c - 1] == curStep - 1)
			{
				inpMap[r][c - 1] = wayValue;
				c -= 1;
				continue;
			}
		}
		if (r > 0)
		{
			if (inpMap[r - 1][c] == curStep - 1)
			{
				inpMap[r - 1][c] = wayValue;
				r -= 1;
				continue;
			}
		}
		if (c < (maxSize - 1))
		{
			if (inpMap[r][c + 1] == curStep - 1)
			{
				inpMap[r][c + 1] = wayValue;
				c += 1;
				continue;
			}
		}
		curStep -= 1;
	} while (inpMap[beginPoint.y][beginPoint.x] == startValue);
}

bool WasResultWritten(bool hasWaveReached, _TCHAR* outFileName, int **inpMap, int& strCount, coordinates const beginPoint, coordinates const endPoint)
{
	ofstream outFile(outFileName);
	if (!outFile.is_open())
	{
		return false;
	}
	if (hasWaveReached)
	{
		for (int r = 0; r < strCount; r++)
		{
			int c = 0;
			while (inpMap[r][c] != initValue)
			{
				if ((r == beginPoint.y) && (c == beginPoint.x))
				{
					outFile << 'A';
				}
				else if ((r == endPoint.y) && (c == endPoint.x))
				{
					outFile << 'B';
				}
				else if (inpMap[r][c] == wayValue)
				{
					outFile << '.';
				}
				else if (inpMap[r][c] == block)
				{
					outFile << '#';
				}
				else
				{
					outFile << ' ';
				}
				c++;
			}
			if (r != strCount - 1)
			{
				outFile << endl;
			}
		}
	}
	else
	{
		for (int r = 0; r < maxSize; r++)
		{
			int c = 0;
			while (inpMap[r][c] != -3)
			{
				if ((r == beginPoint.y) && (c == beginPoint.x))
				{
					outFile << 'A';
				}
				else if ((r == endPoint.y) && (c == endPoint.x))
				{
					outFile << 'B';
				}
				else if (inpMap[r][c] == block)
				{
					outFile << '#';
				}
				else
				{
					outFile << ' ';
				}
				c++;
			}
			if (r != strCount - 1)
			{
				outFile << endl;
			}
		}
	}
	outFile.close();
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid parametrs, expected <input file> <output file>\n";
		return 1;
	}
	int** inpMap = Init();
	int strCount = 1;	
	coordinates beginPoint, endPoint;
	if (!WasInputDataRead(argv[1], inpMap, strCount, beginPoint, endPoint))
	{
		cout << "Invalid input data\n";
		FreeMemory(inpMap);
		return 1;
	}
	if (Wave(inpMap, endPoint))
	{
		FindWay(inpMap, beginPoint,endPoint);
		if (!WasResultWritten(true, argv[2], inpMap, strCount, beginPoint, endPoint))
		{
			cout << "Couldn't show out result\n";
			FreeMemory(inpMap);
			return 1;
		}
	}
	else
	{
		if (!WasResultWritten(false, argv[2], inpMap, strCount, beginPoint, endPoint))
		{
			cout << "Couldn't show out result\n";
			FreeMemory(inpMap);
			return 1;
		}
	}
	FreeMemory(inpMap);
	return 0;
}

