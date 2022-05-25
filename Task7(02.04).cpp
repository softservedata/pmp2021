#include<iostream>
using namespace std;


// Прочитати матрицю A розміром n*n. Знайти транспоновану матрицю AT. 
// Прочитати матрицю A розміром n*n. Перевірити, чи матриця симетрична відносно основної діагоналі.


// Part 1 . Прочитати матрицю A розміром n*n. Знайти транспоновану матрицю AT. 



/*

int** reading (int n)
{
    int** array = new int* [n];
    for (int i = 0; i < n; i++)
        array[i] = new int[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "[" << i << "]" << "[" << j << "] = ";
            cin >> array[i][j];
        }
    }
    return array;
}

void printing (int** Arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << Arr[i][j] << '\t';
        cout << endl;
    }
    cout << endl;
}

void deleting (int** Arr, int n)
{
    for (int i = 0; i < n; i++)
        delete[] Arr[i];
    delete[] Arr;
}

bool checkingForSymmetric (int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != matrix[j][i])
                return false;
        }
    }
    return true;
}


int main()
{
    int n;
    cout << "Please,enter matrix size : ";
    cin >> n;
    int** matrix1 = reading(n);

    printing(matrix1, n);

    if (checkingForSymmetric(matrix1, n))
        cout << "Symmetric\n";
    else
        cout << "Not Symmetric\n";

    deleting(matrix1, n);

    system("pause");
    return 0;
}

*/

// Part 2 . Прочитати матрицю A розміром n*n. Перевірити, чи матриця симетрична відносно основної діагоналі.

int** reading(int k)
{
    int** array = new int* [k];
    for (int i = 0; i < k; i++)
        array[i] = new int[k];
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << "Matr" << "[" << i << "]" << "[" << j << "] = ";
            cin >> array[i][j];
        }
    }
    return array;
}

void printing(int** array, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << array[i][j] << '\t';
        cout << endl;
    }
    cout << endl;
}

void deleting(int** array, int n)
{
    for (int i = 0; i < n; i++)
        delete[] array[i];
    delete[] array;
}


int main()
{
    int k;
    cout << " Please,enter matrix size : ";
    cin >> k;
    int** matrixA = reading(k);

    printing(matrixA, k);

    int** transpose = new int* [k];

    for (int i = 0; i < k; i++)
        transpose[i] = new int[k];

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            transpose[i][j] = matrixA[j][i];
        }
    }

    printing(transpose, k);
    deleting(matrixA, k);
    deleting(transpose, k);

    system("pause");
    return 0;
}