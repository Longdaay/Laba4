#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <ctype.h>
#include <fstream>

using namespace std;

string s1, s2;
vector<string> vec;

int checkparam() // ������� �������� ���������� ��������
{
	int par;
	char value[256]; // ����������, ������� ������ ��������� ��������
	cin >> value; // ������ ��������� �������� 
	if (strlen(value) == 1) // ��������� ���������� ��������� ��������. ���� �����, �� ������ ������ ��� ���, ����� �������� ������
	{
		switch (value[0]) // ��������, ���� ������ ������ ���������� value
		{
		case 'y': // ���� �����������
			par = 1;
			return par;
			break;
		case 'n': // ���� ������������
			par = 0;
			return par;
			break;
		default: // ���� ����� �� �������� �� � ������ ��
			cout << "�������� ������� �������. ������� ������" << endl;
			checkparam();
			break;
		}
	}
	else // ���� ������� �������� ������ ������������
	{
		cout << "���������� ������ ���� ������. ���������� ������ ������" << endl;
		checkparam();
	}
}

void fill_str()
{
	cout << "������� ������: " << endl;
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

void choosefill() // ������� ������ ���������� �������
{
	int m;
	unsigned int mat_n;
	char value[256]; // ����������, ������� ������ ��������� ��������
	cin >> value; // ��������� ��������� ��������
	if (strlen(value) == 1) // ��������� ���������� ��������� ��������. ���� �����, �� ������ ������ ��� ���, ����� �������� ������
	{
		switch (value[0]) // ��������, ���� ������ ������ ���������� value
		{
		case '1': // ������ ����������
			fill_str();
			break;

		case '2': // ���������� ����� ��������� ����
			fill_str_via_file();
			break;

		default: // ���� ����� �� �������� �� � ������ ��
			cout << "����� ������� �������. ������� ������" << endl;
			choosefill();
		}
	}
	else // ���� ������� �������� ������ ������������
	{
		cout << "���������� ������ ���� ������. ���������� ������ ������" << endl;
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
		cout << "��� �� ������ ������ ������:" << endl;
		cout << "1 - ������ ������ �������" << endl;
		cout << "2 - ������ ������ �� �����" << endl << endl;

		cout << "�������� ���� �� ������� ";

		choosefill();
		check_ch();
		cout << "������������ ������ - ";
		check_reg();
		print_str_col();
		

		cout << endl << "������ ����������? (y/n)";
		par = checkparam();
	}
	return 0;
}