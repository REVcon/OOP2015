#pragma once

template <typename Creature>
class CStandartCreatureCreator
{
public:
	Creature operator() () const
	{
		return Creature();
	}
};

template <
	typename Creature,
	typename T
>
class CAnimalCreator
{
public:
	CAnimalCreator(std::string name, T gender)
		:m_name(name)
		, m_gender(gender)
	{
	}

	Creature operator() () const
	{
		return Creature(m_name, m_gender);
	}
private:
	std::string m_name;
	T m_gender;
};

template <
	typename Creature,
	typename T
>
class CHumanCreator
{
public:
	CHumanCreator(std::string name, T gender, int number)
		:m_name(name)
		, m_gender(gender)
		, m_number(number)
	{
	}

	Creature operator() () const
	{
		return Creature(m_name, m_gender, m_number);
	}
private:
	std::string m_name;
	T m_gender;
	int m_number;
};