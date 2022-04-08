
#include <iostream>
#include <math.h>
using namespace std;

void read_matr(int** &matr, int n, const char*message)
{
    cout << "Input elements of matrix " << message<<endl;
    matr = new int* [n];
    for (int i = 0; i < n; i++)
    {
        matr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> matr[i][j];
        }
    }
}

void print(int** matr, int n, const char*message)
{
    cout << "Matrix " << message << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<< matr[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
    
}



void del(int** matr, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[]matr[i];
    }
    delete[]matr;
}

void subMatr(int** matr1, int** matr2, int** &matr3, int n)
{
    matr3 = new int* [n];

    for (int i = 0; i < n; i++)
    {
        matr3[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            matr3[i][j] = matr1[i][j] - matr2[i][j];
        }
    }
}

void pow2(int** &matr3, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            matr3[i][j] = pow(matr3[i][j], 2);
        }
    }
}

bool isDiagonal(int** matr, int n)
{
    int diagonal;
    bool res = true;
    for (int i = 0; i < n; i++)
    {
        diagonal = matr[i][i];

        for (int k = 0; k < n; k++)
        {
            if (abs(diagonal) < abs(matr[i][k]))
            {
                res = false;
                break;
            }
        }
    }
    return res;
}


int main()
{
    //Task1
    /*int n;
    cout << "n=";
    cin >> n;

    int** matr1;
    int** matr2;
    int** matr3;
    read_matr(matr1, n,"A");
    read_matr(matr2, n,"B");

    print(matr1, n,"A");
    print(matr2, n,"B");
    //
    subMatr(matr1, matr2, matr3, n);
    pow2(matr3, n);
    print(matr3, n, "C");
    //
    del(matr1, n);
    del(matr2, n);
    del(matr3, n);*/


    //Task2
    
    int n;
    cout << "n=";
    cin >> n;

    int** matr;
    read_matr(matr, n, "A");
    print(matr, n, "A");


    if (isDiagonal(matr,n))
    {
        cout << "diagonal element overweight " << endl;;
    }
    else
    {
        cout << "diagonal element doesn't overweight " << endl;;
    }

    del(matr, n);

    return 0;
}

