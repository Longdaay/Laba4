#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <ctype.h>
#include <fstream>

using namespace std;

int main()
{
	string s1,s2;
	vector<string> vec;
	string s3 = ",/][;:()?!_ ";
	int count = 0;
	bool par = true;
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int index = 0;

	while (par == true)
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
		cout << "Исправленная строка с одним предложением - " << s1 << endl;
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
		cout << endl << "Исправленная строка без лишних знаков - ";
		cout << s1 << endl;
		index = 0;
		cout << "Исправленный регистр слов - ";
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
		cout << endl << "Хотите продолжить? (1/0)";
		cin >> par;
	}
	return 0;
}