#pragma once
#include "CCreature.h"

class CDog final : public CCreature<Gender>
{
public:	
	CDog(std::string name, Gender gender)
		:CCreature<Gender>(name, gender)
	{
	}
};