#include<iostream>
#include<stdlib.h>
#include <ctime>

using namespace std;

void square(int s, int *pole);
void makeShip1(int s,int *pole);
void makeShip2(int s,int *pole);
void makeShip3(int s,int *pole);
void makeShip4(int s,int *pole);


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int a = 0;
    int pole[10][10] = {0};
    square(a, *pole); // поле
    makeShip4(a, *pole); // положение 4-палубных кораблей
    makeShip3(a, *pole); // положение 3-палубного корабля
    makeShip2(a, *pole); // положение 2-палубных кораблей
    makeShip1(a, *pole); // положение 1-палубных кораблей

    int four = 0;
    int three = 0;
    int two = 0;
    int one = 0;



    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (pole[i][j] == 1)
                one++;
            if (pole[i][j] == 2)
                two++;
            if (pole[i][j] == 3)
                three++;
            if (pole[i][j] == 4)
                four++;
        }
    }


    int qll;
    char qtt;



    shag:

    cout << "Выберете клетку: строка(буква), затем столбец(цифра) через пробел" << endl;
    cin >> qtt >> qll;
    int ql = qll - 1;
    int iqt = (int)qtt;
    int qt = iqt - 65;
    cout << "1" << endl;

    if (pole[qt][ql] == 1 or pole[qt][ql] == 2 or pole[qt][ql] == 3 or pole[qt][ql] == 4)
    {
        cout << "Попадание" << endl;
        pole[qt][ql] = 8;
    }
    else{
        cout << "Промах" << endl;
        pole[qt][ql] = 9;
        }

    int yyy = 0;
    square(a, *pole);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(pole[i][j] == 4)
                yyy++;
        }
    }

    if(yyy > 0)
        goto shag;
    else
        cout << "WIN";


}

void square(int s, int *pole)
{
    setlocale(LC_ALL, "Russian");
    int ar[10][10];                    //
    int w = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ar[i][j] = pole[w];
            w++;
        }                               // новый массив
    }
    s = 9;
    char q = 'A';
    char u = 0;
    cout << " ";
    for (int i = 0; i < 10; i++)
        cout << " " << i + 1;
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        printf("%c", q + u);
        cout << "|";
        for (int j = 0; j < 10; j++)
        {
            if(ar[i][j] == 8)
                cout << "X|";
            else{
                if (ar[i][j] == 9)
                    cout << ".|";
                else
                    cout << " |";
            }
        }
        cout << endl;
        u++;
    }
}

void makeShip1(int s, int *pole)
{
    int ar[10][10];                    //
    int w = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ar[i][j] = pole[w];
            w++;
        }                               // новый массив
    }

    for (int j = 0; j < 4; j++)
    {

        rett:
        srand(time(NULL));
        int ch = (rand()) % 10;
        int cc = (rand()) % 10;


        if (ar[ch][cc] == 0)
        {
            ar[ch][cc] = 1;
            if (ch - 1 >= 0)
                ar[ch - 1][cc] = 5;
            if (ch + 1 < 10)
                ar[ch + 1][cc] = 5;
            if (cc - 1 >= 0)
                ar[ch][cc - 1] = 5;
            if (cc + 1 < 10)
                ar[ch][cc + 1] = 5;
        }
        else goto rett;

    }


    w = 0;
    for (int i = 0; i < 10; i++)    // в старый
    {
        for (int j = 0; j < 10; j++)
        {
            pole[w] = ar[i][j];
            w++;
        }
    }
}

void makeShip2(int s,int *pole)
{
    int ar[10][10];                    //
    int w = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ar[i][j] = pole[w];
            w++;
        }                               // новый массив
    }

    for (int j = 0; j < 3; j++)
    {

        rett:
        srand(time(NULL));
        int ch = (rand()) % 10;
        int cc = (rand()) % 10;
        int n = (rand()) % 2;

        switch (n) {
            case 0:
                if (ar[ch][cc] == 0 and ar[ch + 1][cc] == 0  and ch + 1 < 10)
                {
                    ar[ch][cc] = 2;
                    ar[ch + 1][cc] = 2;
                    if (ch - 1 >= 0)
                        ar[ch - 1][cc] = 5;
                    if (ch + 2 < 10)
                        ar[ch + 2][cc] = 5;
                    int mm = ch - 1;
                    for (int i = 0; i < 4; i++) {
                        if (cc - 1 >= 0 and mm + i < 10 and mm + i >= 0)
                            ar[mm + i][cc - 1] = 5;
                    }
                    for (int i = 0; i < 4; i++) {
                        if (cc + 1 < 10 and mm + i < 10 and mm + i >= 0)
                            ar[mm + i][cc + 1] = 5;
                    }
                }
                else goto rett;
                break;
            case 1:
                if (ar[ch][cc] == 0 and ar[ch][cc + 1] == 0 and cc + 1 < 10)
                {
                    ar[ch][cc] = 2;
                    ar[ch][cc + 1] = 2;
                    if (cc - 1 >= 0)
                        ar[ch][cc - 1] = 5;
                    if (cc + 2 < 10)
                        ar[ch][cc + 2] = 5;
                    int mm = cc - 1;
                    for (int i = 0; i < 4; i++) {
                        if (ch - 1 >= 0 and mm + i < 10 and mm + i >= 0)
                            ar[ch - 1][mm + i] = 5;
                    }
                    for (int i = 0; i < 4; i++) {
                        if (ch + 1 < 10 and mm + i < 10 and mm + i >= 0)
                            ar[ch + 1][mm + i] = 5;
                    }
                }
                else goto rett;
                break;

        }
    }



    w = 0;
    for (int i = 0; i < 10; i++)    // в старый
    {
        for (int j = 0; j < 10; j++)
        {
            pole[w] = ar[i][j];
            w++;
        }
    }
}







void makeShip3(int s,int *pole)
{
    int ar[10][10];                    //
    int w = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ar[i][j] = pole[w];
            w++;
        }                               // новый массив
    }

    for (int j = 0; j < 2; j++)
    {

        rett:
        srand(time(NULL));
        int ch = (rand()) % 10;
        int cc = (rand()) % 10;
        int n = (rand()) % 2;

        switch (n) {
            case 0:
                if (ar[ch][cc] == 0 and ar[ch + 1][cc] == 0 and ar[ch + 2][cc] == 0 and ch + 2 < 10)
                {
                    ar[ch][cc] = 3;
                    ar[ch + 1][cc] = 3;
                    ar[ch + 2][cc] = 3;
                    if (ch - 1 >= 0)
                        ar[ch - 1][cc] = 5;
                    if (ch + 3 < 10)
                        ar[ch + 3][cc] = 5;
                    int mm = ch - 1;
                    for (int i = 0; i < 5; i++) {
                        if (cc - 1 >= 0 and mm + i < 10 and mm + i >= 0)
                            ar[mm + i][cc - 1] = 5;
                    }
                    for (int i = 0; i < 5; i++) {
                        if (cc + 1 < 10 and mm + i < 10 and mm + i >= 0)
                            ar[mm + i][cc + 1] = 5;
                    }
                }
                else goto rett;
                break;
            case 1:
                if (ar[ch][cc] == 0 and ar[ch][cc + 1] == 0 and ar[ch][cc + 2] == 0 and cc + 2 < 10)
                {
                    ar[ch][cc] = 3;
                    ar[ch][cc + 1] = 3;
                    ar[ch][cc + 2] = 3;
                    if (cc - 1 >= 0)
                        ar[ch][cc - 1] = 5;
                    if (cc + 3 < 10)
                        ar[ch][cc + 3] = 5;
                    int mm = cc - 1;
                    for (int i = 0; i < 5; i++) {
                        if (ch - 1 >= 0 and mm + i < 10 and mm + i >= 0)
                            ar[ch - 1][mm + i] = 5;
                    }
                    for (int i = 0; i < 5; i++) {
                        if (ch + 1 < 10 and mm + i < 10 and mm + i >= 0)
                            ar[ch + 1][mm + i] = 5;
                    }
                }
                else goto rett;
                break;

        }
    }



    w = 0;
    for (int i = 0; i < 10; i++)    // в старый
    {
        for (int j = 0; j < 10; j++)
        {
            pole[w] = ar[i][j];
            w++;
        }
    }
}






void makeShip4(int s,int *pole)
{
    int ar[10][10];                    //
    int w = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ar[i][j] = pole[w];
            w++;
        }                               // новый массив
    }



    rett:
    srand(time(NULL));
    int ch = (rand()) % 10;
    int cc = (rand()) % 10;
    int n = (rand()) % 2;


    switch (n) {
        case 0:
            if (ar[ch][cc] == 0 and ar[ch + 1][cc] == 0 and ar[ch + 2][cc] == 0  and ar [ch + 3][cc] == 0 and ch + 3 < 10)
            {
                ar[ch][cc] = 4;
                ar[ch + 1][cc] = 4;
                ar[ch + 2][cc] = 4;
                ar[ch + 3][cc] = 4;
                if (ch - 1 >= 0)
                    ar[ch - 1][cc] = 5;
                if (ch + 4 < 10)
                    ar[ch + 4][cc] = 5;
                int mm = ch - 1;
                for (int i = 0; i < 6; i++) {
                    if (cc - 1 >= 0 and mm + i < 10 and mm + i >= 0)
                        ar[mm + i][cc - 1] = 5;
                }
                for (int i = 0; i < 6; i++) {
                    if (cc + 1 < 10 and mm + i < 10 and mm + i >= 0)
                        ar[mm + i][cc + 1] = 5;
                }
            }
            else goto rett;
            break;
        case 1:
            if (ar[ch][cc] == 0 and ar[ch][cc + 1] == 0 and ar[ch][cc + 2] == 0 and ar[ch][cc + 3] and cc + 3 < 10)
            {
                ar[ch][cc] = 4;
                ar[ch][cc + 1] = 4;
                ar[ch][cc + 2] = 4;
                ar[ch][cc + 3] = 4;
                if (cc - 1 >= 0)
                    ar[ch][cc - 1] = 5;
                if (cc + 4 < 10)
                    ar[ch][cc + 4] = 5;
                int mm = cc - 1;
                for (int i = 0; i < 6; i++) {
                    if (ch - 1 >= 0 and mm + i < 10 and mm + i >= 0)
                        ar[ch - 1][mm + i] = 5;
                }
                for (int i = 0; i < 6; i++) {
                    if (ch + 1 < 10 and mm + i < 10 and mm + i >= 0)
                        ar[ch + 1][mm + i] = 5;
                }
            }
            else goto rett;
            break;

    }


    w = 0;
    for (int i = 0; i < 10; i++)    // в старый
    {
        for (int j = 0; j < 10; j++)
        {
            pole[w] = ar[i][j];
            w++;
        }
    }
}
