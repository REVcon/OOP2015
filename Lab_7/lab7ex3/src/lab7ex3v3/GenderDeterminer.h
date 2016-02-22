#pragma once

template <
	typename Creature,
	typename T
>
class CStandartGenderDeterminer
{
public:
	T operator() (Creature const& creature) const
	{
		return creature.GetGender();
	}
};