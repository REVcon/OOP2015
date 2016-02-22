#include "stdafx.h"
#include "../CRectangle/Canvas.h"
#include <sstream>

struct MyCanvasFixture
{
	CCanvas canvas;
};

BOOST_FIXTURE_TEST_SUITE(Canvas, MyCanvasFixture)

BOOST_AUTO_TEST_CASE(MayGetHeight)
{
	CCanvas canvas1(80, 550);
	BOOST_CHECK_EQUAL(canvas1.GetHeight(), 550);
}

BOOST_AUTO_TEST_CASE(MayGetWidth)
{
	CCanvas canvas1(90, 50);
	BOOST_CHECK_EQUAL(canvas1.GetWidth(), 90);
}

BOOST_AUTO_TEST_CASE(WithHeight20AndWidth60ByDefault)
{
	CCanvas canvas1;
	BOOST_CHECK_EQUAL(canvas1.GetHeight(), 20);
	BOOST_CHECK_EQUAL(canvas1.GetWidth(), 60);
}

BOOST_AUTO_TEST_CASE(TestSetPixel)
{
	canvas.SetPixel(40, 20, '+');
	BOOST_CHECK_EQUAL(canvas.GetPixel(40, 20), '+');
}

BOOST_AUTO_TEST_CASE(TestWrite)
{
	std::ostringstream outStrm;
	CCanvas test(5, 5);
	test.SetPixel(5, 5, '+');
	std::string result = "      \n      \n      \n      \n      \n     +\n";
	test.Write(outStrm);
	BOOST_CHECK_EQUAL(outStrm.str(), result);
}

BOOST_AUTO_TEST_CASE(TestClear)
{
	canvas.SetPixel(40, 20, '+');
	canvas.SetPixel(30, 20, '+');
	canvas.SetPixel(60, 20, '+');
	canvas.SetPixel(40, 30, '+');
	canvas.Clear();
	for (unsigned i = 0; i <= canvas.GetHeight(); ++i)
	{
		for (unsigned j = 0; j <= canvas.GetWidth(); ++j)
		{
			BOOST_CHECK_EQUAL(canvas.GetPixel(i, j), ' ');
		}
	}
}

BOOST_AUTO_TEST_SUITE_END()