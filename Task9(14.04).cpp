#include <iostream>
using namespace std;

// Прочитати з клавіатури квадратну матрицю.
// Посортувати рядки матриці по зростанню на основі значень елементів першого стовпчика

void reading(int** matrix, int k)
{
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            cin >> matrix[i][j];
        }
    }
}


void printing(int** matrix, int k)
{
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void deleting(int**& matrix, int k)
{
    for (int i = 0; i < k; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int** matrixForming (int k) 
{
    int** matrix = new int* [k];
    for (int i = 0; i < k; ++i) 
    {
        matrix[i] = new int[k] {};
    }
    return matrix;
}


void sorting(int** matrix, int n)
{
    int maxJ;
    int temporaryMaximum;
    for (int i = 0; i < n - 1; i++) 
    {
        maxJ = 0;
        temporaryMaximum = matrix[maxJ][0];
        for (int j = 0; j < n - i; j++) 
        {
            if (temporaryMaximum < matrix[j][0]) 
            {
                maxJ = j;
                temporaryMaximum = matrix[maxJ][0];
            }
        }
        matrix[maxJ][0] = matrix[n - i - 1][0];
        matrix[n - i - 1][0] = temporaryMaximum;
        for (int k = 1; k < n; k++) 
        {
            int a = matrix[maxJ][k];
            matrix[maxJ][k] = matrix[n - i - 1][k];
            matrix[n - i - 1][k] = a;
        }
    }
}

int main()
{
    int k;
    cout << "Enter size of colums and rows (n*n) : ";
    cin >> k;
    int** matrixA = matrixForming(k);

    cout << "Fill matrix by your elements : " << endl;
    reading(matrixA, k);
    cout << "Sorted matrix : " << endl;

    sorting(matrixA, k);
    printing(matrixA, k);
    deleting(matrixA, k);

    return 0;
}