#include "stdafx.h"
#include <memory>
#include "../Bodies/Compound.h"
#include "../Bodies/Sphere.h"
#include "../Bodies/Cone.h"
#include "../Bodies/Cylinder.h"
#include "../Bodies/Parallelepiped.h"

using namespace std;

struct CompoundFixture
{
	CCompound comp;

	CSphere sphere;
	CCone cone;
	CCylinder cylinder;
	CParallelepiped par;

	CompoundFixture()
		: sphere(10, 5), cone(10, 15, 60), cylinder(10, 15, 30), par(10, 15, 20, 50)
	{
		comp.AddBody(make_shared<CSphere>(sphere));
		comp.AddBody(make_shared<CCone>(cone));
		comp.AddBody(make_shared<CCylinder>(cylinder));
		comp.AddBody(make_shared<CParallelepiped>(par));
	}
};

BOOST_FIXTURE_TEST_SUITE(Compound, CompoundFixture)

BOOST_AUTO_TEST_CASE(HasVolume)
{
	double volume = comp.GetVolume();
	double expectedVolume = sphere.GetVolume() + cone.GetVolume() + cylinder.GetVolume() + par.GetVolume();
	BOOST_CHECK_EQUAL(volume, expectedVolume);
}

BOOST_AUTO_TEST_CASE(HasMass)
{
	double mass = comp.GetMass();
	double expectedMass = sphere.GetMass() + cone.GetMass() + cylinder.GetMass() + par.GetMass();
	BOOST_CHECK_EQUAL(mass, expectedMass);
}

BOOST_AUTO_TEST_CASE(HasDensity)
{
	double density = comp.GetDensity();
	double expectedVolume = sphere.GetVolume() + cone.GetVolume() + cylinder.GetVolume() + par.GetVolume();
	double expectedMass = sphere.GetMass() + cone.GetMass() + cylinder.GetMass() + par.GetMass();
	double expectedDensity = expectedMass / expectedVolume;
	BOOST_CHECK_EQUAL(density, expectedDensity);
}

BOOST_AUTO_TEST_CASE(EmptyCompoundBody)
{
	CCompound compound;
	CBody &compoundAsBody = compound;

	{
		bool exceptionCaught = false;
		try
		{
			compoundAsBody.GetDensity();
		}
		catch (const runtime_error &e)
		{
			(void)e;
			exceptionCaught = true;
		}
		BOOST_CHECK(exceptionCaught);
	}

	BOOST_CHECK_EQUAL(compoundAsBody.GetVolume(), 0);
	BOOST_CHECK_EQUAL(compoundAsBody.GetMass(), 0);
}

BOOST_AUTO_TEST_CASE(TestDirectSelfInclusion)
{
	shared_ptr<CCompound> compound(new CCompound());

	BOOST_CHECK_EQUAL(compound->AddBody(compound), false);
}

BOOST_AUTO_TEST_CASE(AddCompoundToItselfChained)
{
	shared_ptr<CCompound> compound1(new CCompound());
	shared_ptr<CCompound> compound2(new CCompound());

	compound2->AddBody(shared_ptr<CParallelepiped>(new CParallelepiped(10, 3.6, 6, 40)));
	BOOST_CHECK_EQUAL(compound1->AddBody(compound2), true);
	BOOST_CHECK_EQUAL(compound2->AddBody(compound1), false);
}

BOOST_AUTO_TEST_SUITE_END()
