#pragma once 
template < typename T>

class CCreature
{
public:
	CCreature(std::string name, T gender)
		:m_name(name)
		, m_gender(gender)
	{
	}
	T GetGender() const
	{
		return m_gender;
	}	
	std::string GetName() const
	{
		return m_name;
	}

private:
	std::string m_name;
	T m_gender;
};

enum Gender
{
	MALE = 1,
	FEMALE
};