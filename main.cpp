/*
1.�������� ���������, ����������� ��� ����� ���� ����� ����� � �������� �� 10 �� 20 (������������), ���� �� � ������� true, � ��������� ������ � false;
2.�������� ���������, �����������, �������� �� ��������� ����� - ����������� �������.������� ����� - ��� �����, ������� ������� 
��� ������� ������ �� ������� � ���� ����.
3.�������� ���������, ��������� �� ����� �������, ���� ��� ������������� ���������, ����������� � � ������ ���� ����� ������ ���� �� ����, 
���� �� ����� ����� ������.
*/

#include <iostream>

#define START_YEAR	0	/*��������� ��� ������ ��� ������� 4*/

using namespace std;

bool fTask1(int iNum_a,int iNum_b);
bool fTask2(unsigned int iNum);
bool fTask3(void);


int main(void)
{
	// task 1
	cout << "Task 1 : Result : ";
	fTask1(5, 7);

	// task 2
	cout << "Task 2 : Result : ";
	fTask2(9);

	// task 3
	cout << "Task 3 : Result : ";
	fTask3();

	return 0;
}

/*1.�������� ���������, ����������� ��� ����� ���� ����� ����� � �������� �� 10 �� 20 (������������), ���� �� � ������� true, � ��������� ������ � false;*/
bool fTask1(int iNum_a, int iNum_b)
{
	int iRes;
	
	iRes = iNum_a + iNum_b;

	if ((iRes >= 10) && (iRes <= 20))
	{
		cout << "true" << endl;
		return true;
	}
	else
	{
		cout << "false" << endl;
		return false;
	}
}

/*2.�������� ���������, �����������, �������� �� ��������� ����� - ����������� �������.������� ����� - ��� �����, ������� ������� 
��� ������� ������ �� ������� � ���� ����.*/
bool fTask2(unsigned int iNum)
{
	unsigned int iCounter;

	// ���� � ������� �� �������� ������������ �������.
	if (iNum == 0 || iNum == 1)
	{
		cout << "false" << endl;
		return false;
	}

	iCounter = 2;
	while (iNum != iCounter)
	{
		if ((iNum % iCounter) == 0)
		{
			cout << "false" << endl;
			return false;
		}

		iCounter++;
	}

	cout << "true" << endl;

	return true;
}

/*3.�������� ���������, ��������� �� ����� �������, ���� ��� ������������� ���������, ����������� � � ������ ���� ����� ������ ���� �� ����, 
���� �� ����� ����� ������.*/
bool fTask3(void)
{
	const int a = 3;
	const int b = 7;

	if (((a == b) && (a == 10)) || ((a + b) == 10))
	{
		cout << "true" << endl;
		return true;
	}
	else
	{
		cout << "false" << endl;
		return false;
	}
}
