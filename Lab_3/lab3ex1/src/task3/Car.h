#pragma once

class CCar
{
public:
	enum Direction
	{
		BACKWARD = -1,
		STILL,
		FORWARD
	};
	enum Err
	{
		EngineTurnedOffSpeed,
		EngineTurnedOffGear,
		AlreadyTurnedOff,
		CanNotTurnOff,
		InvalidGear,
		InvalidGearForGivenSpeed,
		InvalidSpeed,
		InvalidSpeedForGivenGear,
	};

	CCar();
	~CCar();
	bool IsEngineTurnedOn() const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	int GetGear() const;
	int GetSpeed() const;
	Direction GetDirection() const;
	Err GetLastErr() const;
	bool SetGear(int gear);
	bool SetSpeed(int speed);
private:
	bool m_isEngineTurnedOn;
	int m_gear;
	int m_speed;
	Direction m_direction;
	Err m_lastErr;
};

