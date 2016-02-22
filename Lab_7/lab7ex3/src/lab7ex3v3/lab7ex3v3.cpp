// lab7ex3v3.cpp: ���������� ����� ����� ��� ����������� ����������.
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
		std::string name1 = "�����";
		std::string name2 = "�����";
		std::string name3 = "�����";
		std::string name4 = "�����";
		std::string name5 = "��������";
		CDog spouse1(name1, MALE);
		CDog spouse2(name2, FEMALE);
		CFamily<CDog, Gender, CStandartGenderDeterminer<CDog, Gender>, CAnimalCreator<CDog, Gender>> dogs(spouse1, spouse2);
		dogs.MakeChild(CAnimalCreator<CDog, Gender>(name3, MALE));
		dogs.MakeChild(CAnimalCreator<CDog, Gender>(name4, MALE));
		dogs.MakeChild(CAnimalCreator<CDog, Gender>(name5, FEMALE));
		cout << "����� - " << dogs.GetSpouse1().GetName() << ", ����� - " << dogs.GetSpouse2().GetName() << ".\n��������:";
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
		std::string name1 = "������";
		std::string name2 = "�����";
		std::string name3 = "���";
		std::string name4 = "������";
		std::string name5 = "�����";
		std::string name6 = "�����";
		CCat spouse1(name1, MALE);
		CCat spouse2(name2, FEMALE);
		CFamily<CCat, Gender, CStandartGenderDeterminer<CCat, Gender>, CAnimalCreator<CCat, Gender>> cats(spouse1, spouse2);
		cats.MakeChild(CAnimalCreator<CCat, Gender>(name3, MALE));
		cats.MakeChild(CAnimalCreator<CCat, Gender>(name4, MALE));
		cats.MakeChild(CAnimalCreator<CCat, Gender>(name5, MALE));
		cats.MakeChild(CAnimalCreator<CCat, Gender>(name6, FEMALE));
		cout << "����� - " << cats.GetSpouse1().GetName() << ", ����� - " << cats.GetSpouse2().GetName() << ".\n��������:";
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
		std::string name1 = "������";
		std::string name2 = "�������";
		std::string name3 = "������";
		std::string name4 = "������";
		std::string name5 = "��������";
		CHuman spouse1(name1, MALE, 1);
		CHuman spouse2(name2, FEMALE, 2);
		CFamily<CHuman, Gender, CStandartGenderDeterminer<CHuman, Gender>, CHumanCreator<CHuman, Gender>> humans(spouse1, spouse2);
		humans.MakeChild(CHumanCreator<CHuman, Gender>(name3, MALE, 10));
		humans.MakeChild(CHumanCreator<CHuman, Gender>(name4, MALE, 11));
		humans.MakeChild(CHumanCreator<CHuman, Gender>(name5, FEMALE, 12));
		cout << "������ - " << humans.GetSpouse1().GetName() << ", ������� - " << humans.GetSpouse2().GetName() << ".\n����:";
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

