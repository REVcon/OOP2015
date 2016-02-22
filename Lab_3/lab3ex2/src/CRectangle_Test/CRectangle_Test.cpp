#include "stdafx.h"
#include "../CRectangle/Rectangle.h"

struct MyRectangleFixture
{
	CRectangle rectangle;
};

BOOST_FIXTURE_TEST_SUITE(Rectangle, MyRectangleFixture)

BOOST_AUTO_TEST_CASE(MayCreateRectangleWithZeroArgByDefault)
{
	BOOST_CHECK_EQUAL(rectangle.GetWidth(), 0);
	BOOST_CHECK_EQUAL(rectangle.GetHeight(), 0);
	BOOST_CHECK_EQUAL(rectangle.GetBottom(), 0);
	BOOST_CHECK_EQUAL(rectangle.GetLeft(), 0);
}

BOOST_AUTO_TEST_CASE(HaveWidthAndHeight)
{
	rectangle.SetWidth(1);
	BOOST_CHECK_EQUAL(rectangle.GetWidth(), 1);
	rectangle.SetHeight(1);
	BOOST_CHECK_EQUAL(rectangle.GetHeight(), 1);
}

BOOST_AUTO_TEST_CASE(UnpositiveSidesChangedToZeroSides)
{
	rectangle.SetWidth(-1);
	rectangle.SetHeight(-1);
	BOOST_CHECK_EQUAL(rectangle.GetWidth(), 0);
	BOOST_CHECK_EQUAL(rectangle.GetHeight(), 0);
}

BOOST_AUTO_TEST_CASE(RectangleHaveGotPositiveCoordinates)
{
	rectangle.SetWidth(1);
	rectangle.SetHeight(1);
	rectangle.SetLeft(2);
	BOOST_CHECK_EQUAL(rectangle.GetLeft(), 2);
	rectangle.SetTop(5);
	BOOST_CHECK_EQUAL(rectangle.GetTop(), 5);
	BOOST_CHECK_EQUAL(rectangle.GetRight(), 3);
	BOOST_CHECK_EQUAL(rectangle.GetBottom(), 6);
}

BOOST_AUTO_TEST_CASE(HavePerimetrAndSquare)
{
	rectangle.SetWidth(1);
	rectangle.SetHeight(1);
	BOOST_CHECK_EQUAL(rectangle.GetPerimetr(), 4);
	BOOST_CHECK_EQUAL(rectangle.GetSquare(), 1);
}

BOOST_AUTO_TEST_CASE(CanMoveRectangleByCoordinates)
{
	rectangle.SetLeft(3);
	rectangle.SetTop(4);
	rectangle.Move(3, 4);
	BOOST_CHECK_EQUAL(rectangle.GetLeft(), 6);
	BOOST_CHECK_EQUAL(rectangle.GetTop(), 8);
}

BOOST_AUTO_TEST_CASE(RectangleChangeSizeIfValuesArePositive)
{
	rectangle.SetWidth(2);
	rectangle.SetHeight(4);
	BOOST_CHECK_EQUAL(rectangle.GetSquare(), 8);
	BOOST_CHECK_EQUAL(rectangle.GetPerimetr(), 12);
	rectangle.Scale(2, 4);
	BOOST_CHECK_EQUAL(rectangle.GetWidth(), 4);
	BOOST_CHECK_EQUAL(rectangle.GetHeight(), 16);
	BOOST_CHECK_EQUAL(rectangle.GetSquare(), 64);
	BOOST_CHECK_EQUAL(rectangle.GetPerimetr(), 40);
}

BOOST_AUTO_TEST_CASE(AtScaleDontChangesLeftTopCoordinates)
{
	rectangle = CRectangle(3, 4, 2, 4);
	rectangle.Scale(2, 4);
	BOOST_CHECK_EQUAL(rectangle.GetLeft(), 3);
	BOOST_CHECK_EQUAL(rectangle.GetTop(), 4);
}

BOOST_AUTO_TEST_CASE(AtScaleChangesRightBottomCoordinates)
{
	rectangle = CRectangle(3, 4, 2, 4);
	BOOST_CHECK_EQUAL(rectangle.GetRight(), 5);
	BOOST_CHECK_EQUAL(rectangle.GetBottom(), 8);
	rectangle.Scale(2, 4);
	BOOST_CHECK_EQUAL(rectangle.GetRight(), 7);
	BOOST_CHECK_EQUAL(rectangle.GetBottom(), 20);
}

BOOST_AUTO_TEST_CASE(RectangleHaveRightAndBottomCoordinates)
{
	rectangle.SetRight(10);
	BOOST_CHECK_EQUAL(rectangle.GetRight(), 10);
	BOOST_CHECK_EQUAL(rectangle.GetLeft(), 0);
	BOOST_CHECK_EQUAL(rectangle.GetWidth(), 10);

	rectangle.SetBottom(10);
	BOOST_CHECK_EQUAL(rectangle.GetBottom(), 10);
	BOOST_CHECK_EQUAL(rectangle.GetTop(), 0);
	BOOST_CHECK_EQUAL(rectangle.GetHeight(), 10);
}

BOOST_AUTO_TEST_SUITE_END();

struct TestIntersectRectangleFixture
{
	CRectangle rect1 = CRectangle(0, 0, 10, 10);
};

BOOST_FIXTURE_TEST_SUITE(TestIntersectRectangle, TestIntersectRectangleFixture)

BOOST_AUTO_TEST_CASE(TestNonIntersectRectangle)
{
	CRectangle rect2 = CRectangle(11, 11, 10, 10);
	BOOST_CHECK(!rect1.Intersect(rect2));
	BOOST_CHECK_EQUAL(rect1.GetHeight(), 0);
	BOOST_CHECK_EQUAL(rect1.GetWidth(), 0);
}

BOOST_AUTO_TEST_CASE(TestIntersectionRectangleBottomRight)
{
	CRectangle rect2(8, 8, 10, 10);
	BOOST_CHECK(rect1.Intersect(rect2));
	BOOST_CHECK_EQUAL(rect1.GetHeight(), 2);
	BOOST_CHECK_EQUAL(rect1.GetWidth(), 2);
}

BOOST_AUTO_TEST_CASE(TestIntersectionRectangleBottomRight1)
{
	CRectangle rect2(8, 7, 10, 10);
	BOOST_CHECK(rect2.Intersect(rect1));
	BOOST_CHECK_EQUAL(rect2.GetHeight(), 3);
	BOOST_CHECK_EQUAL(rect2.GetWidth(), 2);
	BOOST_CHECK_EQUAL(rect2.GetLeft(), 8);
	BOOST_CHECK_EQUAL(rect2.GetTop(), 7);
}

BOOST_AUTO_TEST_CASE(TestIntersectionRectangleTopLeft)
{
	CRectangle rect2(-8, -8, 10, 10);
	BOOST_CHECK(rect1.Intersect(rect2));
}

BOOST_AUTO_TEST_CASE(TestIntersectionRectangleBottomLeft)
{
	CRectangle rect2(-8, 8, 10, 10);
	BOOST_CHECK(rect1.Intersect(rect2));
}

BOOST_AUTO_TEST_SUITE_END()
