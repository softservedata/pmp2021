//Прочитати матрицю A розміром n*n. Знайти транспоновану матрицю A^T.
//Прочитати матрицю A розміром n*n. Перевірити, чи матриця симетрична відносно основної діагоналі.
#include <iostream>
using namespace std;


double** CreateMatrix( int k ) {
    auto** matrix = new double *[k];
    for ( int i = 0; i < k; ++i ) {
        matrix[i] = new double[k]{};
    }
    return matrix;
}
void ReadMatrix( double **matrix, int k ) { //читання матриць
    for ( int i = 0; i < k; ++i ) {
        for ( int j = 0; j < k; ++j ) {
            cin >> matrix[i][j];
        }
    }
}
void Delete( double **&matrix, int k ) { //видалення
    for ( int i = 0; i < k; ++i ) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
void PrintMatrix( double **matrix, int k ) { //друк матриць
    for ( int i = 0; i < k; ++i ) {
        for ( int j = 0; j < k; ++j ) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

double** TransposedMatrix( double** matrix1, int k )
{
    double **matrix = CreateMatrix(k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            matrix[i][j] = matrix1[j][i];
        }
    }
    return matrix;
}

bool SymmetryOfTheMatrix(double** matrix, int k)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    int k;
    cout << ">> Task 1 <<" << endl;
    cout << "Введіть кількість рядків та стовпців (n): ";
    cin >> k;
    double **matrix1 = CreateMatrix(k);
    cout << "Введіть елементи матриці: " << endl;
    ReadMatrix(matrix1, k);

    cout << "Транспонована матриця: " << endl;
    double** TransposedMatrix_a = TransposedMatrix(matrix1, k);
    PrintMatrix(TransposedMatrix_a,k);
    Delete(TransposedMatrix_a, k);

    cout << "\n" << endl;
    cout << ">> Task 2 <<" << endl;
    int m;
    cout << "Введіть кількість стовпців та рядків: ";
    cin >> m;
    double **matrixA = CreateMatrix(k);
    cout << "Введіть елементи матриці: " << endl;
    ReadMatrix(matrixA, k);
    if (SymmetryOfTheMatrix(matrixA, m)) {
        cout << "Результат: матриця симетрична відносно основної діагоналі" << endl;
    }
    else {
        cout << "Результат: матриця не є симетрична відносно основної діагоналі" << endl;
    }
    Delete(matrix1, k);

}

/*
1 2 5
6 -2 3
5 -3 -7

1 0 0
0 1 0
0 0 1
 */
