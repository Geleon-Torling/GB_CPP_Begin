/*
1.Описать макрокоманду, проверяющую, входит ли переданное ей число в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно)
2.Описать макрокоманду, получающую доступ к элементу двумерного массива (организованного динамически) посредством разыменования указателей
3*. Описать макрокоманду, возвращающую количество элементов локального массива, принимающую на вход ссылку на массив и его тип
*/

#include <iostream>

using namespace std;

// task 1
#define CHECK_INTERVAL(x,max) ( (((x) >= 0) && ((x) < (max))) ? (true) : (false))

// task 2
#define ARRAY_ACCESS(pointer, pos) (*(&pointer[pos]))

// task 3
#define ARRAY_COUNT(array,type) (sizeof(array) / sizeof(type))


void fPrintArray(int *p_array, int i_size);

int main()
{

    // task 1
    cout << CHECK_INTERVAL(5,6) << endl;

    // task 2
    int *p_array = new int[5];

    ARRAY_ACCESS(p_array,0) = 0;
    ARRAY_ACCESS(p_array,1) = 1;
    ARRAY_ACCESS(p_array,2) = 2;
    ARRAY_ACCESS(p_array,3) = 3;
    ARRAY_ACCESS(p_array,4) = 4;

    fPrintArray(p_array,5);

    delete [] p_array;

    // task 3
    long long array[5] = {1,2,3,4,5};

    cout << ARRAY_COUNT(array,long long) << endl;

    return 0;
}

void fPrintArray(int *p_array, int i_size)
{
    if((p_array == nullptr) || i_size < 1)
        return;

    for(int i = 0; i < i_size; i ++)
        cout << "{" << p_array[i] << "} ";

    cout << endl;
}
