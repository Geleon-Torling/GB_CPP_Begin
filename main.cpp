/*
1. Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [1, 1, 0, 0, 1, 0, 1, 1, 0, 0] .Написать функцию, 
	заменяющую в принятом массиве 0 на 1, 1 на 0;
2. Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22;
3*.Написать функцию, в которую передается не пустой одномерный целочисленный массив, метод должен вернуть истину если в массиве есть место, 
	в котором сумма левой и правой части массива равны.Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, 
	checkBalance([2, 1, 1, 2, 1]) → false, checkBalance([10, || 1, 2, 3, 4]) → true.Абстрактная граница показана символами || , 
	эти символы в массив не входят.
4*. Написать функцию, которой на вход подаётся одномерный массив и число n(может быть положительным, или отрицательным),
	при этом метод должен циклически сместить все элементы массива на n позиций.
5**. Написать функцию из первого задания так, чтобы она работала с аргументом переменной длины.
6**. Написать все функции в отдельных файлах в одном пространстве имён, вызвать их на исполнение в основном файле программы используя указатели на функции.
*/

#include <iostream>
#include "Lesson5.h"



int main(int argc, const char **argv)
{
	/*6**. Написать все функции в отдельных файлах в одном пространстве имён, вызвать их на исполнение в основном файле программы используя указатели на функции.*/
	void (*p_fChange)(int iSize, int array[]);
	void (*p_fArrayCreate)(int iSize, int array[]);
	void (*p_fChangeM)(int iSize, int array[], ...);
	void (*p_fPrintArray)(int iSize, int array[]);

	p_fChange = cppLesson5::fChange;
	p_fArrayCreate = cppLesson5::fArrayCreate;
	p_fChangeM = cppLesson5::fChangeM;
	p_fPrintArray = cppLesson5::fPrintArray;

	// task 1
	std::cout << "task1" << std::endl;
	int iTestArray[] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };
	p_fPrintArray(10, iTestArray);
	p_fChange(sizeof(iTestArray) / sizeof(int), iTestArray);
	p_fPrintArray(10, iTestArray);

	// task 2
	std::cout << "task2" << std::endl;
	int iTestArray2[8] = { 0 };
	p_fPrintArray(8, iTestArray2);
	p_fArrayCreate(8, iTestArray2);
	p_fPrintArray(8, iTestArray2);


	// task 5
	std::cout << "task5" << std::endl;
	int iTestArray5[10] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };
	p_fPrintArray(10, iTestArray5);
	p_fChangeM(10, iTestArray5, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0);
	p_fPrintArray(10, iTestArray5);

	return 0;
}