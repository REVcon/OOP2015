// CRectangle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Rectangle.h"
#include "Canvas.h"

using namespace std;

void InitRectangle(CRectangle &rectangle, ifstream &inputFile)
{
	int width, height, left, top;
	inputFile >> left >> top >> width >> height;
	rectangle.SetLeft(left);
	rectangle.SetTop(top);
	rectangle.SetWidth(width);
	rectangle.SetHeight(height);
}

void MoveRectangle(CRectangle &rectangle, ifstream &inputFile)
{
	int dx, dy;
	inputFile >> dx >> dy;
	rectangle.Move(dx, dy);
}

void ScaleRectangle(CRectangle &rectangle, ifstream &inputFile)
{
	int sx, sy;
	inputFile >> sx >> sy;
	rectangle.Scale(sx, sy);
}

void ReadFromFile(const string &fileName, CRectangle &rectangle)
{
	ifstream inputRectangle;
	inputRectangle.open(fileName);
	string action;
	while (inputRectangle.good())
	{
		inputRectangle >> action;
		if (action == "Rectangle")
		{
			InitRectangle(rectangle, inputRectangle);
		}
		if (action == "Move")
		{
			MoveRectangle(rectangle, inputRectangle);
		}
		if (action == "Scale")
		{
			ScaleRectangle(rectangle, inputRectangle);
		}
	}
}

void PrintRectangleInfo(const CRectangle &rectangle)
{
	cout << "\tLeft Top : " << rectangle.GetLeft() << " , " << rectangle.GetTop() << "\n";
	cout << "\tSize : " << rectangle.GetWidth() << " * " << rectangle.GetHeight() << "\n";
	cout << "\tRight Bottom : " << rectangle.GetRight() << " , " << rectangle.GetBottom() << "\n";
	cout << "\tArea : " << rectangle.GetSquare() << "\n";
	cout << "\tPerimetr : " << rectangle.GetPerimetr() << "\n";
}

void FillRectangle(const CRectangle &rect, char code, CCanvas &canvas)
{
	unsigned x = rect.GetLeft();
	unsigned y = rect.GetTop();
	for (size_t i = 0; i < rect.GetWidth(); ++i)
	{
		for (size_t j = 0; j < rect.GetHeight(); ++j)
		{
			canvas.SetPixel(i + x, j + y, code);
		}
	}
}

void PrintRectangles(ostream &outStrm, CCanvas &canvas, const vector<CRectangle> &rectangles, const CRectangle &intersect)
{
	FillRectangle(rectangles[0], '+', canvas);
	FillRectangle(rectangles[1], '-', canvas);
	FillRectangle(intersect, '#', canvas);
	canvas.Write(outStrm);
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Not enough arguments, expected 2 files with parametrs of rectangles\n";
	}
	CCanvas canvas;
	vector<CRectangle> rectangles;	
	for (size_t i = 0; i < 2; i++)
	{
		
		cout << "Rectangle " << i + 1 << ":" << endl;
		CRectangle rect;
		ReadFromFile(argv[i + 1], rect);
		rectangles.push_back(rect);
		PrintRectangleInfo(rect);
	}
	cout << "Intersection of rectangles:\n";
	CRectangle intersect = rectangles[0];
	intersect.Intersect(rectangles[1]);
	PrintRectangleInfo(intersect);
	if (argc > 3)
	{
		ofstream outStrm(argv[3]);
		PrintRectangles(outStrm, canvas, rectangles, intersect);
	}
	else
	{
		PrintRectangles(cout, canvas, rectangles, intersect);
	}
	return 0;
}

