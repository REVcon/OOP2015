// task3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Car.h"
#include <string>
#include <iostream>
#include <map>

using namespace std;

enum Commands
{
	Info,
	EngineOn,
	EngineOff,
	SetGear,
	SetSpeed,
};

int StringToInt(const char* str, bool &err)
{
	char *pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

bool AssignCommand(string const & curQuery, Commands & command, int &value)
{
	string symbols = " \n";
	string strValue, strCommand;
	int b = 0;
	int e = 0;
	int count = 2;
	if ((b = curQuery.find_first_not_of(symbols, e)) != curQuery.npos)
	{
		e = curQuery.find_first_of(symbols, b);
		strCommand = curQuery.substr(b, e - b);
		b = e;
	}
	else
	{
		return false;
	}
	if (strCommand == "Info")
	{
		command = Info;
		return true;
	}
	if (strCommand == "EngineOn")
	{
		command = EngineOn;
		return true;
	}
	if (strCommand == "EngineOff")
	{
		command = EngineOff;
		return true;
	}
	if (strCommand == "SetSpeed")
	{
		if ((b = curQuery.find_first_not_of(symbols, e)) != curQuery.npos)
		{
			e = curQuery.find_first_of(symbols, b);
			strValue = curQuery.substr(b, e - b);
			bool err;
			value = StringToInt(strValue.c_str(), err);
			command = SetSpeed;
			return !err;
		}
		return false;		
	}
	if (strCommand == "SetGear")
	{
		if ((b = curQuery.find_first_not_of(symbols, e)) != curQuery.npos)
		{
			e = curQuery.find_first_of(symbols, b);
			strValue = curQuery.substr(b, e - b);
			bool err;
			value = StringToInt(strValue.c_str(), err);
			command = SetGear;
			return !err;
		}
		return false;
	}
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CCar car;
	map<CCar::Direction, string> directionToString =
	{
		{ CCar::Direction::FORWARD, "forward" },
		{ CCar::Direction::BACKWARD, "backward" },
		{ CCar::Direction::STILL, "still" }
	};

	map<CCar::Err, string> errToStr =
	{
		{ CCar::Err::EngineTurnedOffSpeed, "Engine turned off, impossible to set given speed." },
		{ CCar::Err::EngineTurnedOffGear, "Engine turned off, impossible to set given gear." },
		{ CCar::Err::AlreadyTurnedOff, "Engine is already turned off." },
		{ CCar::Err::CanNotTurnOff, "Engine can not be turned off at current speed and gear." },
		{ CCar::Err::InvalidGear, "No such gear." },
		{ CCar::Err::InvalidSpeed, "Impossible to set given speed." },
		{ CCar::Err::InvalidSpeedForGivenGear, "Impossible to set given speed at current gear." },
		{ CCar::Err::InvalidGearForGivenSpeed, "Impossible to set given gear at current speed." }
	};

	map<bool, string> isEngineTurnedOnToStr =
	{
		{ true, " is turned on" },
		{ false, " is turned off" },
	};
	
	string curQuery;
	Commands command;
	int value;
	while (getline(cin, curQuery))
	{
		curQuery.push_back('\n');
		if (AssignCommand(curQuery, command, value))
		{
			switch (command)
			{
			case Info:
				if (car.IsEngineTurnedOn())
				{
					cout << "Engine turned on.\n";
				}
				else
				{
					cout << "Engine turned off.\n";
				}
				cout << "Direction - " << directionToString[car.GetDirection()] << ".\n";
				cout << "Speed - " << car.GetSpeed() << ".\n";
				cout << "Gear - " << car.GetGear() << ".\n";
				break;
			case EngineOn:
				if (!car.TurnOnEngine())
				{
					cout << "Engine is already turned on.\n";
				}
				break;
			case EngineOff:
				if (!car.TurnOffEngine())
				{
					cout << errToStr[car.GetLastErr()] << '\n';
				}
				break;
			case SetGear:
				if (!car.SetGear(value))
				{
					cout << errToStr[car.GetLastErr()] << '\n';
				}
				break;
			case SetSpeed:
				if (!car.SetSpeed(value))
				{
					cout << errToStr[car.GetLastErr()] << '\n';
				}
				break;
			}
		}
		else
		{
			cout << "Available commands:Info, EngineOn, EngineOff, SetSpeed <speed>, SetGear <gear>.\n";
		}		
	}
	return 0;
}

