#pragma once
#include "GenderDeterminer.h"
#include "CreatureCreator.h"
#include <vector>

template<
	typename Creature,
	typename T,
	typename GenderDeterminer = CStandartGenderDeterminer<Creature, T>,
	typename CreatureCreator = CStandartCreatureCreator<Creature>
>
class CFamily
{
public:
	CFamily(Creature const spouse1, Creature const spouse2)
	{
		std::vector<Creature> temp;
		temp.push_back(spouse1);
		temp.push_back(spouse2);
		m_parents.swap(temp);
	}

	Creature GetSpouse1() const
	{
		return m_parents[0];
	}

	Creature GetSpouse2() const
	{
		return m_parents[1];
	}

	Creature GetChild(size_t index) const
	{
		return m_children[index];
	}

	size_t GetChildCount() const
	{
		return m_children.size();
	}

	Creature MakeChild(CreatureCreator const& creatureCreator = CreatureCreator())
	{
		GenderDeterminer genderDeterminer;
		T gender1 = genderDeterminer(GetSpouse1());
		T gender2 = genderDeterminer(GetSpouse2());
		if (gender1 == gender2)
		{
			throw std::logic_error("Impossible to create child in homosexual family");
		}
		Creature child = creatureCreator();
		m_children.push_back(child);
		return child;
	}

private:
	std::vector<Creature> m_children;
	std::vector<Creature> m_parents;
};
