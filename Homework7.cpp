// Homework7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void read_matr(int**& matr, int n, const char* message)
{
    cout << "Input elements of matrix " << message << endl;
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

void print(int** matr, int n, const char* message)
{
    cout << "Matrix " << message << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matr[i][j] << " ";
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

void  transposed(int** matr,int ** &aT,int n)
{
    aT = new int* [n];
    for (int i = 0; i < n; i++)
    {
        aT[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            aT[i][j] = matr[j][i];
        }
    }  
}

bool symetr(int** matr, int n)
{
    bool symetr = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (matr[i][j] != matr[j][i])
            {
                symetr = false;
                i = n;
                j = n;
            }
        }
    }
    return symetr;
}

int main()
{
    //Task 1 
    /*int n;
    cout << "n=";
    cin >> n;

    int** matr;
    read_matr(matr, n, "A");
    print(matr, n, "A");

    int** aT;
    transposed(matr, aT, n);
    print(aT, n, "aT");

    del(matr, n);
    del(aT, n);*/
    
    ////////////////////////////////////
    //Task 2
    int n;
    cout << "n=";
    cin >> n;

    int** matr;
    read_matr(matr, n, "A");
    print(matr, n, "A");


    if (symetr(matr,n))
    {
        cout << "the matrix is symetrical" << endl;
    }
    else
    {
        cout << "the matrix isn't symetrical" << endl;
    }

    del(matr, n); 

    return 0;
}

