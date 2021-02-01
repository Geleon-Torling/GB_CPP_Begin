/*
1. Создать и инициализировать переменные пройденных типов данных
2. Создать перечисление с возможными вариантами символов для игры в крестики-нолики
3. Создать массив, способный содержать значения такого перечисления и инициализировать его.
4. * Создать структуру данных «Поле для игры в крестики-нолики» и снабдить его всеми необходимыми свойствами
5. ** Создать объединение и структуру с битовыми флагами указывающими какого типа значение в данный момент содержится в объединении
*/


#include <iostream>

using namespace std;

void Task1(void);
void Task234(void);
void Task5(void);


int main()
{

    Task1();

    Task234();

    Task5();

    return 0;
}

void Task1(void)
{
    /*1. Создать и инициализировать переменные пройденных типов данных*/

    char        c = 'a';
    short       s = 5;
    int         i = 10;
    long        l = 20;
    long long   ll = 30;
    double      d = 3.5;
    float       f = 6.4f;

    cout << "char : " << c << " and size is : " << sizeof(char) << endl;
    cout << "short : " << s << " and size is : " << sizeof(short) << endl;
    cout << "int : " << i << " and size is : " << sizeof(int) << endl;
    cout << "long (__int32): " << l << " and size is : " << sizeof(long) << endl;
    cout << "long long (__int64): " << ll << " and size is : " << sizeof(long long) << endl;
    cout << "double : " << d << " and size is : " << sizeof(double) << endl;
    cout << "float : " << f << " and size is : " << sizeof(float) << endl;

    int array[5][5] = {{1,2,3,4,5},
                       {2,3,4,5,6},
                       {3,4,5,6,7},
                       {4,5,6,7,8},
                       {0}};
    for(int countX = 0;countX < 5; countX ++)
    {
        for(int countY = 0;countY < 5; countY ++)
        {
            cout << " " << array[countX][countY];
        }
        cout << endl;
    }

    enum numbers {one,two,free,four,five,six,seven,eight,nine,zero};
    enum numbers ecurrent = one;

    struct Triangle
    {
        float x;
        float y;
        float angle;
    };

    struct Triangle triangle {10,10,60};

    cout << "triangle, size x : " << triangle.x << " and y : " << triangle.y << "and : " << triangle.angle << " degree angle" << endl;

    union num
    {
        int             i;
        unsigned int    ui;
        float           f;
    };

    union num Num = {3};

    cout << "union as int : " << Num.i << endl;
    Num.f = 3.7f;
    cout << "union as float : " << Num.f << endl;
}

void Task234(void)
{
    /*2. Создать перечисление с возможными вариантами символов для игры в крестики-нолики*/

    enum eStatus {Unset, Cross, Zero};

    /*3. Создать массив, способный содержать значения такого перечисления и инициализировать его.*/

    enum eStatus Field[3][3] = {Unset};

    // попробуем вывести поле...
    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            cout << " ";
            if(Field[i][j] == Unset)
                cout << '-';
            else if(Field[i][j] == Cross)
                cout << 'X';
            else if(Field[i][j] == Zero)
                cout << '0';
            else
            {
                cout << "Error: Unknown character, error at i: " << i << " j: " << endl;
                return;
            }
        }
        cout << endl;
    }

    /*4. * Создать структуру данных «Поле для игры в крестики-нолики» и снабдить его всеми необходимыми свойствами*/

    struct sCell
    {
        enum eStatus Status;    // cell status
        bool crossedout;        // crossed out flag
    };
}

void Task5(void)
{
    /*5. ** Создать объединение и структуру с битовыми флагами указывающими какого типа значение в данный момент содержится в объединении*/

    union uNum
    {
        int             i;
        unsigned int    ui;
        float           f;
        double          d;
    };

    struct sUnion
    {
        enum eNumType {IntType,UIntType,FloatType,DoubleType,Unknown};
        union uNum num;
        int i   : 1;
        int ui  : 1;
        int f   : 1;
        int d   : 1;

        void SetType(eNumType type)
        {
            ResetFlags();

            if(type == IntType)
                i = 1;
            else if(type == UIntType)
                ui = 1;
            else if(type == FloatType)
                f = 1;
            else if(type == DoubleType)
                d = 1;
        };

        eNumType GetType(void)
        {
            if(i)
                return IntType;
            else if(ui)
                return UIntType;
            else if(f)
                return FloatType;
            else if(d)
                return DoubleType;
            else
                return Unknown;
        };

        void Prin(void)
        {
            if(i)
                cout << "Type is : int, value is : " << num.i << endl;
            else if(ui)
                cout << "Type is : unsigned int, value is : " << num.ui << endl;
            else if(f)
                cout << "Type is : float, value is : " << num.f << endl;
            else if(d)
                cout << "Type is : double, value is : " << num.d << endl;
            else
                cout << "Type is : Unknown" << endl;
        };

    protected:
        void ResetFlags(void)
        {i = 0; ui = 0; f = 0; d = 0;}
    };

    struct sUnion Number;

    Number.num.i = 100;
    Number.SetType(sUnion::eNumType::IntType);

    Number.Prin();
}
