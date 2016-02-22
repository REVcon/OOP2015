#pragma once
#include "CCreature.h"

class CCat final : public CCreature<Gender>
{
public:
	CCat(std::string name, Gender gender)
		:CCreature<Gender>(name, gender)
	{
	}
};