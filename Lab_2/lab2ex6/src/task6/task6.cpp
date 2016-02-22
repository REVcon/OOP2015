// task6.cpp: определяет точку входа для консольного приложения.
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
		cout << "Неверные параметры запуска, ожидалось <input dictionary>\n";
		return 1;
	}
	map<string, string> dictionary;
	if (!WasInpDictRead(argv[1], dictionary))
	{
		cout << "Переданный файл не содержал записи словаря.\n";
	}
	bool wasChanges = false;
	DialogWithUser(dictionary, wasChanges);
	if (wasChanges)
	{
		if (SaveChanges(argv[1], dictionary))
		{
			cout << "Изменения сохранены. До свидания.\n";
		}
		else
		{
			cout << "Изменения не сохранены. До свидания.\n";
		}
	}
	return 0;
}

