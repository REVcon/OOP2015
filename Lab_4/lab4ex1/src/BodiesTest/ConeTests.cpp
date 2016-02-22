#include "stdafx.h"
#include "../Bodies/Cone.h"

static const double EXPECTED_RADIUS = 3;
static const double EXPECTED_HEIGHT = 4;
static const double EXPECTED_DENSITY = 7700;

struct ConeFixture
{
	CCone cone;

	ConeFixture()
		: cone(EXPECTED_RADIUS, EXPECTED_HEIGHT, EXPECTED_DENSITY)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(Cone, ConeFixture)

BOOST_AUTO_TEST_CASE(HasDimensions)
{
	BOOST_CHECK_EQUAL(cone.GetHeight(), EXPECTED_HEIGHT);
	BOOST_CHECK_EQUAL(cone.GetRadius(), EXPECTED_RADIUS);
}

BOOST_AUTO_TEST_CASE(HasDensity)
{
	BOOST_CHECK_EQUAL(cone.GetDensity(), EXPECTED_DENSITY);
}

BOOST_AUTO_TEST_CASE(HasVolume)
{
	const double EXPECTED_VOLUME = (1.0 / 3) * (M_PI * EXPECTED_RADIUS * EXPECTED_RADIUS) *
		EXPECTED_HEIGHT;
	BOOST_CHECK_EQUAL(cone.GetVolume(), EXPECTED_VOLUME);

	CBody &coneAsBody = cone;
	BOOST_CHECK_EQUAL(coneAsBody.GetVolume(), EXPECTED_VOLUME);
}

BOOST_AUTO_TEST_CASE(HasMass)
{
	const double EXPECTED_MASS = cone.GetVolume() * cone.GetDensity();
	BOOST_CHECK_EQUAL(cone.GetMass(), EXPECTED_MASS);
}

BOOST_AUTO_TEST_SUITE_END()
