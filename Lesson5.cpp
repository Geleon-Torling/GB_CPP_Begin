#include "Lesson5.h"
#include <iostream>
#include <cstdarg>

namespace cppLesson5
{

	void fChange(int iSize, int array[])
	{
		/*1. Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [1, 1, 0, 0, 1, 0, 1, 1, 0, 0] .Написать функцию,
			заменяющую в принятом массиве 0 на 1, 1 на 0;*/

		if ((array == nullptr) || (iSize <= 0))
			return;

		for (int i = 0; i < iSize; i++)
		{
			if (array[i] == 1)
				array[i] = 0;
			else
				array[i] = 1;
		}
	}

	void fArrayCreate(int iSize, int array[])
	{
		/*2. Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22;*/

		int iCounter = 1;

		if ((array == nullptr) || (iSize <= 0))
			return;

		for (int i = 0; i < iSize; i++)
		{
			array[i] = iCounter;
			iCounter = iCounter + 3;
		}
	}

	void fChangeM(int iSize, int array[], ...)
	{
		/*5**. Написать функцию из первого задания так, чтобы она работала с аргументом переменной длины.*/

		va_list lst;
		va_start(lst, iSize);
		va_arg(lst, int);	// пропускаем первый элемент, так как переменные аргументы начинаются со второго...
		for (int i = 0; i < iSize; i++)
		{
			array[i] = (va_arg(lst, int) == 0) ? 1 : 0;
		}
		va_end(lst);
	}


	void fPrintArray(int iSize, int array[])
	{
		if ((iSize <= 0) || (array == nullptr))
		{
			std::cout << "ERROR : parametr is not correct" << std::endl;
			return;
		}

		for (int i = 0; i < iSize; i++)
		{
			std::cout << " " << array[i] << " ";
		}
		std::cout << std::endl;

	}
}