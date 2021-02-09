/*
1.Написать программу, проверяющую что сумма двух чисел лежит в пределах от 10 до 20 (включительно), если да – вывести true, в противном случае – false;
2.Написать программу, проверяющую, является ли некоторое число - натуральным простым.Простое число - это число, которое делится 
без остатка только на единицу и себя само.
3.Написать программу, выводящую на экран “истину”, если две целочисленные константы, объявленные в её начале либо равны десяти сами по себе, 
либо их сумма равна десяти.
*/

#include <iostream>

#define START_YEAR	0	/*Стартовый год отчета для задания 4*/

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

/*1.Написать программу, проверяющую что сумма двух чисел лежит в пределах от 10 до 20 (включительно), если да – вывести true, в противном случае – false;*/
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

/*2.Написать программу, проверяющую, является ли некоторое число - натуральным простым.Простое число - это число, которое делится 
без остатка только на единицу и себя само.*/
bool fTask2(unsigned int iNum)
{
	unsigned int iCounter;

	// ноль и единица не являются натуральными числами.
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

/*3.Написать программу, выводящую на экран “истину”, если две целочисленные константы, объявленные в её начале либо равны десяти сами по себе, 
либо их сумма равна десяти.*/
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
