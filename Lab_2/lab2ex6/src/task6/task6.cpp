// task6.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "WorkWithDict.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (argc != 2)
	{
		cout << "�������� ��������� �������, ��������� <input dictionary>\n";
		return 1;
	}
	map<string, string> dictionary;
	if (!WasInpDictRead(argv[1], dictionary))
	{
		cout << "���������� ���� �� �������� ������ �������.\n";
	}
	bool wasChanges = false;
	DialogWithUser(dictionary, wasChanges);
	if (wasChanges)
	{
		if (SaveChanges(argv[1], dictionary))
		{
			cout << "��������� ���������. �� ��������.\n";
		}
		else
		{
			cout << "��������� �� ���������. �� ��������.\n";
		}
	}
	return 0;
}

