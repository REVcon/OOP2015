// task3test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../task3/Car.h"

struct CarFixture
{
	CCar car;
};

BOOST_FIXTURE_TEST_SUITE(Car, CarFixture)

BOOST_AUTO_TEST_CASE(TurnedOffByDefault)
{
	BOOST_CHECK(!car.IsEngineTurnedOn());
}

BOOST_AUTO_TEST_CASE(EngineCanBeTurnedOn)
{  
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.IsEngineTurnedOn());
}

BOOST_AUTO_TEST_CASE(EngineCanBeTurnedOff)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.TurnOffEngine());
	BOOST_CHECK(!car.IsEngineTurnedOn());
}

BOOST_AUTO_TEST_CASE(EngineCanNotBeTurnedOffWhenItTurnedOff)
{
	BOOST_CHECK(!car.TurnOffEngine());
}

BOOST_AUTO_TEST_CASE(EngineCanNotBeTurnedOnWhenItTurnedOn)
{
	car.TurnOnEngine();
	BOOST_CHECK(!car.TurnOnEngine());
}

BOOST_AUTO_TEST_CASE(Is0GearIs0SpeedIs0DirectionWhenEngineTurnedOff)
{
	BOOST_CHECK_EQUAL(car.GetGear(), 0);
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	BOOST_CHECK_EQUAL(car.GetDirection(), 0);
}

BOOST_AUTO_TEST_CASE(SpeedCaNotBeIncreasedOn0Gear)
{
	car.TurnOnEngine();
	BOOST_CHECK(!car.SetSpeed(100));
}

BOOST_AUTO_TEST_CASE(Gear1or0CanBeSetedWhenEngineTurnedOn)
{
	car.TurnOnEngine();
	BOOST_CHECK(car.SetGear(1));
}

BOOST_AUTO_TEST_CASE(Gear0CanBeSetedWhenEngineTurnedOff)
{
	BOOST_CHECK(car.SetGear(0));
}

BOOST_AUTO_TEST_CASE(Speed20CanBeSetedWhenEngineTurnedOnAndSeted1Gear)
{
	car.TurnOnEngine();
	car.SetGear(1);
	BOOST_CHECK(car.SetSpeed(20));
}

BOOST_AUTO_TEST_CASE(EveryGearsHasRangeOfSpeed)
{
	car.TurnOnEngine();
	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK(car.SetSpeed(20));
	BOOST_CHECK(car.SetGear(2));
	BOOST_CHECK(car.SetSpeed(30));
	BOOST_CHECK(car.SetGear(3));
	BOOST_CHECK(car.SetSpeed(40));
	BOOST_CHECK(car.SetGear(4));
	BOOST_CHECK(car.SetSpeed(50));
	BOOST_CHECK(car.SetGear(5));
	BOOST_CHECK(car.SetSpeed(150));
	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK(car.SetSpeed(20));
	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(car.TurnOffEngine());
}

BOOST_AUTO_TEST_CASE(HasDirection)
{
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(20);
	BOOST_CHECK_EQUAL(car.GetDirection(), 1);
	car.SetSpeed(0);
	BOOST_CHECK_EQUAL(car.GetDirection(), 0);
	car.SetGear(-1);
	car.SetSpeed(20);
	BOOST_CHECK_EQUAL(car.GetDirection(), -1);
}

BOOST_AUTO_TEST_SUITE_END()