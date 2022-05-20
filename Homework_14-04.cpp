//Прочитати з клавіатури квадратну матрицю.
// Посортувати рядки матриці по зростанню на основі значень елементів першого стовпчика
#include <iostream>
using namespace std;

int **CreateMatrix(int k) {
    int **matrix = new int *[k];
    for (int i = 0; i < k; ++i) {
        matrix[i] = new int[k]{};
    }
    return matrix;
}

void ReadMatrix(int **matrix, int k) { //читання матриць
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> matrix[i][j];
        }
    }
}

void PrintMatrix(int **matrix, int k) { //друк матриць
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Delete(int **&matrix, int k) { //видалення
    for (int i = 0; i < k; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void SortedMatrix(int** matrix, int n)
{
    int MaxValueI;
    int max;
    for ( int i = 0; i < n - 1; i++ ) {
        MaxValueI = 0;
        max = matrix[MaxValueI][0];
        for ( int j = 0; j < n - i; j++ ) {
            if ( max < matrix[j][0] ) {
                MaxValueI = j;
                max = matrix[MaxValueI][0];
            }
        }
        matrix[MaxValueI][0] = matrix[n - i - 1][0];
        matrix[n - i - 1][0] = max;
        for ( int k = 1; k < n; k++ ) {
            int a = matrix[MaxValueI][k];
            matrix[MaxValueI] [k] = matrix[n - i - 1][k];
            matrix[n - i - 1][k] = a;
        }
    }
}

int main()
{
    int k;
    cout << "Введіть кількість рядків та стовпців (n): ";
    cin >> k;
    int **matrix1 = CreateMatrix(k);

    cout << "Введіть елементи матриці: " << endl;
    ReadMatrix(matrix1, k);
    cout << "Посортована матриця: " << endl;
    SortedMatrix(matrix1, k);
    PrintMatrix(matrix1, k);
    Delete(matrix1, k);
    return 0;
}

/*
6 7 8
4 9 3
9 3 1

4 9 3
6 7 8
9 3 1
*/
