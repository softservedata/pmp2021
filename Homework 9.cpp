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

void sorting(int**& matr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (matr[j][0] > matr[j + 1][0])
            {
                for (int k = 0; k < n; k++)
                {
                    int buf = matr[j][k];
                    matr[j][k] = matr[j + 1][k];
                    matr[j + 1][k] = buf;
                }
            }
        }
    }

}




int main()
{
    int n;
    cout << "n = ";
    cin >> n;

    int** matr;

    read_matr(matr, n, "A");
    print(matr, n, "A");


    sorting(matr, n);
    print(matr, n, "sorted");

    del(matr, n);

    return 0;
}

