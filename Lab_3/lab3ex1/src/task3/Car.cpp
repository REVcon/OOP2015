#include "stdafx.h"
#include "Car.h"
#include <map>
using namespace std;

struct range
{
	int min;
	int max;
};

const map<int, range> GearSpeedRanges = 
{
	{ -1, {0, 20} },
	{ 0, {0, 150} },
	{ 1, {0, 30} },
	{ 2, {20, 50} },
	{ 3, {30, 60} },
	{ 4, {40, 90} },
	{ 5, {50, 150} }
};

CCar::CCar()
	:m_isEngineTurnedOn(false)
	,m_gear(0)
	,m_direction(STILL)
	,m_speed(0)
{
}


CCar::~CCar()
{
}

bool CCar::TurnOnEngine()
{
	if (!m_isEngineTurnedOn)
	{
		m_isEngineTurnedOn = true;
		return true;
	}
	return false;
}

bool CCar::TurnOffEngine()
{
	if (!m_isEngineTurnedOn)
	{
		m_lastErr = AlreadyTurnedOff;
		return false;
	}
	if (m_direction == 0 && m_gear == 0 && m_speed == 0)
	{
		m_isEngineTurnedOn = false;
		return true;
	}
	m_lastErr = CanNotTurnOff;
	return false;
}

bool CCar::IsEngineTurnedOn() const
{
	return m_isEngineTurnedOn;
}

int CCar::GetGear() const
{
	return m_gear;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

CCar::Direction CCar::GetDirection() const
{
	return m_direction;
}

CCar::Err CCar::GetLastErr() const
{
	return m_lastErr;
}

bool CCar::SetSpeed(int speed)
{
	if (m_isEngineTurnedOn)
	{
		if (speed < 0 || speed > 150)
		{
			m_lastErr = InvalidSpeed;
			return false;
		}
		if (m_gear == 0 && speed > m_speed)
		{
			m_lastErr = InvalidSpeedForGivenGear;
			return false;
		}
		auto it = GearSpeedRanges.find(m_gear);
		if (speed <= it->second.max && speed >= it->second.min)
		{
			m_speed = speed;
			if (m_speed == 0)
			{
				m_direction = STILL;
			}
			else if (m_gear == -1 && m_speed != 0)
			{
				m_direction = BACKWARD;
			}
			else
			{
				m_direction = FORWARD;
			}
			return true;
		}
		m_lastErr = InvalidSpeedForGivenGear;
		return false;
	}
	m_lastErr = EngineTurnedOffSpeed;
	return false;
}

bool CCar::SetGear(int gear)
{
	if (m_isEngineTurnedOn)
	{
		if (gear < -1 || gear > 5)
		{
			m_lastErr = InvalidGear;
			return false;
		}
		if ((gear == -1 && m_gear == 0 && m_speed == 0) || (gear == -1 && m_gear == 1 && m_speed == 0))
		{
			m_gear = -1;
			return true;
		}
		else if (gear == -1)
		{
			m_lastErr = InvalidGearForGivenSpeed;
			return false;
		}
		if (gear == 1 && m_direction == BACKWARD)
		{
			m_lastErr = InvalidGearForGivenSpeed;
			return false;
		}
		auto it = GearSpeedRanges.find(gear);
		if (m_speed <= it->second.max && m_speed >= it->second.min)
		{
			m_gear = gear;
			return true;
		}
		m_lastErr = InvalidGearForGivenSpeed;
		return false;
	}
	if (!m_isEngineTurnedOn && gear == 0)
	{
		m_gear = gear;
		return true;
	}
	m_lastErr = EngineTurnedOffGear;
	return false;
}