#pragma once
#include "CCreature.h"

class CHuman final : public CCreature<Gender>
{
public:
	CHuman(std::string name, Gender gender, int number)
		:CCreature<Gender>(name, gender)
		, m_number(number)
	{
	}
	int GetNumberOfTheBirthCertificate()
	{
		return m_number;
	}
private:
	int m_number;
};