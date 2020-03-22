#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>

using namespace std;

struct Owner {
	char Surname[256], Name[256], Patronymic[256], Postcode[25];
	char Country[256], Region[256], District[256], City[256], Street[256];
	int House, Flat;
	char Number[15];
};

int Quantity(int& size)
{
tryagain:
	cout << "Введите количество владельцев стационарных телефонов: ";
	while (!(cin >> size))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неправильный ввод. Повторите еще раз.\n\n";
		goto tryagain;
	}
	if (size < 1)
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Неправильный ввод, пожалуйста введите натуральное число.\n\n";
		goto tryagain;
	}
	cout << "\n";
	return size;
}

void ReadLine(Owner* structure, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Введите фамилию: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(structure[i].Surname, 256);

		cout << "Введите имя: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(structure[i].Name, 256);

		cout << "Введите отчество: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(structure[i].Patronymic, 256);

		cout << "Введите почтовый индекс: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(structure[i].Postcode, 25);

		cout << "Введите страну: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(structure[i].Country, 256);

		cout << "Введите область: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(structure[i].Region, 256);

		cout << "Введите район: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(structure[i].District, 256);

		cout << "Введите город: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(structure[i].City, 256);

		cout << "Введите улицу: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(structure[i].Street, 256);

		do
		{
			cin.clear();
			cout << "Введите номер дома: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> structure[i].House;
		} while (structure[i].House < 1 || cin.get() != '\n');

		do
		{
			cin.clear();
			cout << "Введите номер квартиры: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> structure[i].Flat;
		} while (structure[i].Flat < 1 || cin.get() != '\n');

		cout << "Введите № телефона: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(structure[i].Number, 15);

		cin.clear();
		cout << "\n\n";
	}
}

void Print(Owner* structure, int size)
{
	cout << "\nПолная информация о владельцах стационарных телефонов:" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "\nФамилия: " << structure[i].Surname << endl;
		cout << "Имя: " << structure[i].Name << endl;
		cout << "Отчество: " << structure[i].Patronymic << endl;
		cout << "Почтовый индекс: " << structure[i].Postcode << endl;
		cout << "Страна: " << structure[i].Country << endl;
		cout << "Область: " << structure[i].Region << endl;
		cout << "Район: " << structure[i].District << endl;
		cout << "Город: " << structure[i].City << endl;
		cout << "Улица: " << structure[i].Street << endl;
		cout << "Дом: " << structure[i].House << endl;
		cout << "Квартира: " << structure[i].Flat << endl;
		cout << "№ телефона: " << structure[i].Number << "\n\n";
	}
}

void sort_alphabetically(Owner* structure, int size)
{
	cout << "\nАлфавитный список владельцев стационарного телефона:" << endl;
	Owner Temp;
	for (int i = 0; i <= size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (strcmp(structure[j].Surname, structure[j - 1].Surname) < 0)
			{
				Temp = structure[j];
				structure[j] = structure[j - 1];
				structure[j - 1] = Temp;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ". " << structure[i].Surname << endl;
	}
}

void search(Owner* structure, int size)
{
	cout << "\nПожалуйста, введите фамилию владельца стационарного телефона для поиска: ";
	string Surname;
	cin >> Surname;
	for (int i = 0; i < size; i++)
	{
		if (structure[i].Surname == Surname)
		{
			cout << "\nФамилия: " << structure[i].Surname << endl;
			cout << "Имя: " << structure[i].Name << endl;
			cout << "Отчество: " << structure[i].Patronymic << endl;
			cout << "Почтовый индекс: " << structure[i].Postcode << endl;
			cout << "Страна: " << structure[i].Country << endl;
			cout << "Область: " << structure[i].Region << endl;
			cout << "Район: " << structure[i].District << endl;
			cout << "Город: " << structure[i].City << endl;
			cout << "Улица: " << structure[i].Street << endl;
			cout << "Дом: " << structure[i].House << endl;
			cout << "Квартира: " << structure[i].Flat << endl;
			cout << "№ телефона: " << structure[i].Number << "\n\n";
			break;
		}
	}
}

void AddStructure(Owner* structure, int size)
{
	int change = 0;
	Owner* own_new_struct;
	do
	{
		cin.clear();
		cout << "\nВведите количество добавляемых владельцев:";
		cin >> change;
	} while (change < 1 || cin.get() != '\n');
	size += change;
	own_new_struct = (Owner*)realloc(structure, size * sizeof(Owner));
	for (int i = size - change; i < size; i++)
	{
		cout << "\nВведите фамилию: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(own_new_struct[i].Surname, 256);

		cout << "Введите имя: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(own_new_struct[i].Name, 256);

		cout << "Введите отчество: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(own_new_struct[i].Patronymic, 256);

		cout << "Введите почтовый индекс: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(own_new_struct[i].Postcode, 25);

		cout << "Введите страну: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(own_new_struct[i].Country, 256);

		cout << "Введите область: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(own_new_struct[i].Region, 256);

		cout << "Введите район: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(own_new_struct[i].District, 256);

		cout << "Введите город: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(own_new_struct[i].City, 256);

		cout << "Введите улицу: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(own_new_struct[i].Street, 256);

		do
		{
			cin.clear();
			cout << "Введите номер дома: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> own_new_struct[i].House;
		} while (own_new_struct[i].House < 1 || cin.get() != '\n');

		do
		{
			cin.clear();
			cout << "Введите номер квартиры: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> own_new_struct[i].Flat;
		} while (own_new_struct[i].Flat < 1 || cin.get() != '\n');

		cout << "Введите № телефона: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(own_new_struct[i].Number, 15);

		cin.clear();
		cout << "\n\n";
	}

	cout << "\nПолная информация о владельцах стационарных телефонов:" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "\nФамилия: " << own_new_struct[i].Surname << endl;
		cout << "Имя: " << own_new_struct[i].Name << endl;
		cout << "Отчество: " << own_new_struct[i].Patronymic << endl;
		cout << "Почтовый индекс: " << own_new_struct[i].Postcode << endl;
		cout << "Страна: " << own_new_struct[i].Country << endl;
		cout << "Область: " << own_new_struct[i].Region << endl;
		cout << "Район: " << own_new_struct[i].District << endl;
		cout << "Город: " << own_new_struct[i].City << endl;
		cout << "Улица: " << own_new_struct[i].Street << endl;
		cout << "Дом: " << own_new_struct[i].House << endl;
		cout << "Квартира: " << own_new_struct[i].Flat << endl;
		cout << "№ телефона: " << own_new_struct[i].Number << "\n\n";
	}
	free(own_new_struct);
}

void Choice(Owner* structure, int size)
{
	bool isCorrect = false;
	string choice;
	do
	{
		cout << "\nЕсли вы хотите выполнить поиска владельца, то введите 'search'." << endl;
		cout << "Если вы хотите отобразить имена владельцев в алфавитном порядке, то введите 'list'." << endl;
		cout << "Если вы хотите добавить нового владельца и вывести информацию о всех владельцах стационарных телефонов, то введите 'add'." << endl;
		cout << "Если вы хотите вывести информацию о всех владельцах стационарных телефонов, то введите 'show'." << endl;
		cout << "Если вы хотите выйти из программы, то введите 'exit'." << endl;
	choice:
		cout << "Ввод:";
		cin >> choice;
		if (choice == "search")
		{
			search(structure, size);
		}
		else if (choice == "list")
		{
			sort_alphabetically(structure, size);
		}
		else if (choice == "add")
		{
			AddStructure(structure, size);
			isCorrect = true;
		}
		else if (choice == "show")
		{
			Print(structure, size);
		}
		else if (choice == "exit")
		{
			exit(0);
		}
		else
		{
			cout << "Неверный ввод, пожалуйста, повторите ввод." << endl;
			goto choice;
		}
	} while (isCorrect != true);
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(0, "");

	int size;
	Quantity(size);
	Owner* structure = new Owner[size];
	ReadLine(structure, size);
	Choice(structure, size);
}