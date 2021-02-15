/*
1.Написать программу, которая создаст два текстовых файла, примерно по 50-100 символов в каждом (особого значения не имеет);
2.Написать функцию, «склеивающую» эти файлы, предварительно буферизуя их содержимое в динамически выделенный сегмент памяти нужного размера.
*/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>

using namespace std;

bool fCreateFiles(int size = 100, string fName1 = "file1.txt", string fName2 = "file2.txt");
bool fCatFiles(string fName1 = "file1.txt", string fName2 = "file2.txt", string fOutName = "SumFile.txt");
bool fSearch(void);

int main(int argc, char **argv)
{
    cout << "Task 1" << endl;
    fCreateFiles();

    cout << "Task 2" << endl;
    fCatFiles();

    return 0;
}


bool fCreateFiles(int size, string fName1, string fName2)
{
    /*1.Написать программу, которая создаст два текстовых файла, примерно по 50-100 символов в каждом (особого значения не имеет);*/

    fstream file;
    char * pBuffer = nullptr;

    // файл текстовой, нужен посоледний символ,равный нулю для корректной записи
    pBuffer = (char*)calloc(size + 1,sizeof(char));

    // подготовка генератора "случайных" чисел
    srand((unsigned)time(0));

    // подготовка буфера для записи
    for(int i = 0; i < size; i ++)
    {
        // символы из диапазона от 65 до 90 по ASCII (A-Z)
        pBuffer[i] = (char)((rand() % (90 - 65)) + 65);
    }

    // пишем первый
    file.open(fName1,ios::out);
    if(!file.is_open())     // открываем
    {
        free (pBuffer);
        cout << "Error : cannot open file : " << fName1 << endl;
        return false;
    }

    // ставлю метку чтоб файлы отличались (имеет смысл если файл больше 5 байт)
    if(size > 5)
        memcpy(pBuffer,"File1",5);
    file << pBuffer;        // пишем
    file.flush();           // сбрасываем буфер
    file.close();           // закрываем

    // пишем второй
    file.open(fName2,ios::out);
    if(!file.is_open())
    {
        free (pBuffer);
        cout << "Error : cannot open file : " << fName2 << endl;
        return false;
    }

    // ставлю метку чтоб файлы отличались (имеет смысл если файл больше 5 байт)
    if(size > 5)
        memcpy(pBuffer,"File2",5);
    file << pBuffer;
    file.flush();
    file.close();

    free (pBuffer);

    return true;
}

bool fCatFiles(string fName1, string fName2, string fOutName)
{
    /*2.Написать функцию, «склеивающую» эти файлы, предварительно буферизуя их содержимое в динамически выделенный сегмент памяти нужного размера.*/

    int     iFSize1 = 0, iFSize2 = 0;
    fstream infile1,infile2, outfile;
    char * pBuffer = nullptr;

    // для разнообразия работаем с файлами как с двоичными

    // открываем первый файл
    infile1.open(fName1,ios::in | ios::binary | ios::ate);
    if(!infile1.is_open())     // открываем
    {
        cout << "Error : cannot open first file : " << fName1 << endl;
        return false;
    }

    // открываем второй файл
    infile2.open(fName2,ios::in | ios::binary | ios::ate);
    if(!infile2.is_open())     // открываем
    {
        cout << "Error : cannot open second file : " << fName1 << endl;
        return false;
    }

    // открываем выходной файл
    outfile.open(fOutName,ios::out | ios::binary);
    if(!outfile.is_open())     // открываем
    {
        cout << "Error : cannot open output file : " << fName1 << endl;
        return false;
    }

    // считаем размер и пишем в буффер
//    infile1.seekg(0,ios::end);        // если всетаки файл онкрыт сначала
//    infile2.seekg(0,ios::end);
    iFSize1 = infile1.tellg();
    iFSize2= infile2.tellg();
    pBuffer = (char*)malloc(iFSize1 + iFSize2);

    // читаем первый, потом второй
    infile1.seekg(0, ios::beg);
    infile1 >> pBuffer;
    infile2.seekg(0, ios::beg);
    infile2 >> &pBuffer[iFSize1];

    infile1.close();
    infile2.close();

    outfile << pBuffer;        // пишем
    if(outfile.fail())
    {
        // совсем по хорошему, здесь надо обработать ошибку записи, но я ограничусь выводом сообщения
        cout << "Error write output file : " << fOutName << endl;

        outfile.close();           // закрываем ..
        free(pBuffer);

        return false;
    }

    outfile.flush();           // сбрасываем буфер
    outfile.close();           // закрываем ..
    free(pBuffer);

    return true;
}


bool fSearch(void)
{
    /*3* Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово в указанном пользователем
        файле (для простоты работаем только с латиницей).
    */

    return false;
}
