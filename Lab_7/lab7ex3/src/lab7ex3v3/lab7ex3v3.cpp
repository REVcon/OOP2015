// lab7ex3v3.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "Windows.h"
#include "iostream"
#include "CCat.h"
#include "CDog.h"
#include "CHuman.h"
#include "CFamily.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	{
		std::string name1 = "Бобик";
		std::string name2 = "Жучка";
		std::string name3 = "Тузик";
		std::string name4 = "Шарик";
		std::string name5 = "Кнопочка";
		CDog spouse1(name1, MALE);
		CDog spouse2(name2, FEMALE);
		CFamily<CDog, Gender, CStandartGenderDeterminer<CDog, Gender>, CAnimalCreator<CDog, Gender>> dogs(spouse1, spouse2);
		dogs.MakeChild(CAnimalCreator<CDog, Gender>(name3, MALE));
		dogs.MakeChild(CAnimalCreator<CDog, Gender>(name4, MALE));
		dogs.MakeChild(CAnimalCreator<CDog, Gender>(name5, FEMALE));
		cout << "Самец - " << dogs.GetSpouse1().GetName() << ", самка - " << dogs.GetSpouse2().GetName() << ".\nДетеныши:";
		for (size_t i = 0; i < dogs.GetChildCount(); ++i)
		{
			if (i != dogs.GetChildCount() - 1)
			{
				cout << dogs.GetChild(i).GetName() << ", ";
			}
			else
			{
				cout << dogs.GetChild(i).GetName() << ".\n";
			}
		}
	}
	{
		std::string name1 = "Васька";
		std::string name2 = "Мурка";
		std::string name3 = "Том";
		std::string name4 = "Мурзик";
		std::string name5 = "Пушок";
		std::string name6 = "Машка";
		CCat spouse1(name1, MALE);
		CCat spouse2(name2, FEMALE);
		CFamily<CCat, Gender, CStandartGenderDeterminer<CCat, Gender>, CAnimalCreator<CCat, Gender>> cats(spouse1, spouse2);
		cats.MakeChild(CAnimalCreator<CCat, Gender>(name3, MALE));
		cats.MakeChild(CAnimalCreator<CCat, Gender>(name4, MALE));
		cats.MakeChild(CAnimalCreator<CCat, Gender>(name5, MALE));
		cats.MakeChild(CAnimalCreator<CCat, Gender>(name6, FEMALE));
		cout << "Самец - " << cats.GetSpouse1().GetName() << ", самка - " << cats.GetSpouse2().GetName() << ".\nДетеныши:";
		for (size_t i = 0; i < cats.GetChildCount(); ++i)
		{
			if (i != cats.GetChildCount() - 1)
			{
				cout << cats.GetChild(i).GetName() << ", ";
			}
			else
			{
				cout << cats.GetChild(i).GetName() << ".\n";
			}
		}
	}
	{
		std::string name1 = "Руслан";
		std::string name2 = "Людмила";
		std::string name3 = "Гвидон";
		std::string name4 = "Салтан";
		std::string name5 = "Василиса";
		CHuman spouse1(name1, MALE, 1);
		CHuman spouse2(name2, FEMALE, 2);
		CFamily<CHuman, Gender, CStandartGenderDeterminer<CHuman, Gender>, CHumanCreator<CHuman, Gender>> humans(spouse1, spouse2);
		humans.MakeChild(CHumanCreator<CHuman, Gender>(name3, MALE, 10));
		humans.MakeChild(CHumanCreator<CHuman, Gender>(name4, MALE, 11));
		humans.MakeChild(CHumanCreator<CHuman, Gender>(name5, FEMALE, 12));
		cout << "Супруг - " << humans.GetSpouse1().GetName() << ", супруга - " << humans.GetSpouse2().GetName() << ".\nДети:";
		for (size_t i = 0; i < humans.GetChildCount(); ++i)
		{
			if (i != humans.GetChildCount() - 1)
			{
				cout << humans.GetChild(i).GetName() << ", ";
			}
			else
			{
				cout << humans.GetChild(i).GetName() << ".\n";
			}
		}
	}
	return 0;
}

