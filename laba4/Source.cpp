#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <ctype.h>
#include <fstream>

using namespace std;

string s1, s2;
vector<string> vec;

int checkparam() // функция проверки выбранного действия
{
	int par;
	char value[256]; // переменная, которая хранит выбранное значение
	cin >> value; // вводим выбранное значение 
	if (strlen(value) == 1) // проверяем количество введенных символов. Если много, то просим ввести еще раз, иначе проверям дальше
	{
		switch (value[0]) // проверям, взяв первый символ переменной value
		{
		case 'y': // если соглашаемся
			par = 1;
			return par;
			break;
		case 'n': // если отказываемся
			par = 0;
			return par;
			break;
		default: // если число не подходит ни к одному из
			cout << "Значение введено неверно. Введите заново" << endl;
			checkparam();
			break;
		}
	}
	else // если введено символов больше необходимого
	{
		cout << "Необходимо ввести один символ. Попробуйте ввести заново" << endl;
		checkparam();
	}
}

void fill_str()
{
	cout << "Введите строку: " << endl;
	s1.clear();
	s2.clear();
	while (s2.find('.') == -1)
	{
		getline(cin, s2);
		s1 += s2;
	}
	s1.erase(s1.find('.') + 1);
}

void fill_str_via_file()
{

}

void choosefill() // функция выбора заполнения матрицы
{
	int m;
	unsigned int mat_n;
	char value[256]; // переменная, которая хранит выбранное значение
	cin >> value; // считываем выбранное значение
	if (strlen(value) == 1) // проверяем количество введенных символов. Если много, то просим ввести еще раз, иначе проверям дальше
	{
		switch (value[0]) // проверям, взяв первый символ переменной value
		{
		case '1': // ручное заполнение
			fill_str();
			break;

		case '2': // заполнение через текстовый файл
			fill_str_via_file();
			break;

		default: // если число не подходит ни к одному из
			cout << "Число введено неверно. Введите заново" << endl;
			choosefill();
		}
	}
	else // если введено символов больше необходимого
	{
		cout << "Необходимо ввести один символ. Попробуйте ввести заново" << endl;
		choosefill();
	}
}

void check_ch()
{
	string s3 = ",/][;:()?!_- ";
	int count = 0;
	int index = 0;

	for (int i = 0; i < s3.size(); i++)
	{
		index = 0;
		count = 0;
		while (index < s1.size())
		{
			if (s1[index] != s3[i])
			{
				count = 0;
			}
			else
			{
				count++;
			}
			if (count > 1)
			{
				s1.erase(index, 1);
				index--;
			}
			index++;
		}
	}
}

void check_reg()
{
	for (int i = 0; i < s1.size(); i++)
	{
		if (i != 0)
		{
			s1[i] = tolower(s1[i]);
			cout << s1[i];
		}
		else
		{
			s1[i] = toupper(s1[i]);
			cout << s1[i];
		}
	}
	cout << endl;
}

void print_str_col()
{
	int index = 0;
	int count = 0;
	s2 = s1;
	index = 0;
	while (index < s1.size())
	{
		if (s1[index] == ' ' or s1[index] == '.')
		{
			s2.erase(0, index + 1);
			vec.push_back(s1.erase(index));
			index = -1;
		}
		index++;
		s1 = s2;
	}
	vec[vec.size() - 1] = vec[vec.size() - 1] + '.';
	count = 0;
	int max = vec[0].size();
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].size() > max)
			max = vec[i].size();
	}
	for (int i = 0; i < vec.size(); i++)
	{
		cout.width(max);
		cout << right << vec[i] << "| " << '\t';
		count++;
		if (count == 3)
		{
			cout << right << endl;
			count = 0;
		}
	}
}

int main()
{
	bool par = true;
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (par == 1)
	{
		cout << "Как вы хотите ввести строку:" << endl;
		cout << "1 - Ввести строку вручную" << endl;
		cout << "2 - Ввести строку из файла" << endl << endl;

		cout << "Выберите один из пунктов ";

		choosefill();
		check_ch();
		cout << "Исправленная строка - ";
		check_reg();
		print_str_col();
		

		cout << endl << "Хотите продолжить? (y/n)";
		par = checkparam();
	}
	return 0;
}