//Прочитати матриці A та B розміром n*n. Обчислити величину (A – B)^2.
//Прочитати дійсну матрицю розміром n*n. Вияснити, чи задана матриця володіє діагональною перевагою
// (діагональні елементи по модулю переважають інших у своїх стрічці).
#include <iostream>

using namespace std;

int **CreateMatrix(int k) { // створення матриці
    int **matrix = new int *[k];
    for (int i = 0; i < k; ++i) {
        matrix[i] = new int[k]{};
    }
    return matrix;
}

void ReadMatrix(int **matrix, int k) { // читання матриць
    for ( int i = 0; i < k; ++i ) {
        for (int j = 0; j < k; ++j) {
            cin >> matrix[i][j];
        }
    }
}
int** PrintMatrix( int **matrix, int k ) { // друк матриць
    for ( int i = 0; i < k; ++i ) {
        for ( int j = 0; j < k; ++j ) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int** DeductionForMatrix( int**& matrixA, int**& matrixB, int& k ) { // віднімання
    int** Result = new int* [k];
    for ( int i = 0; i < k; i++ ) {
        Result[i] = new int[k];
        for ( int j = 0; j < k; j++ ) {
            Result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return Result;
}


int** ElevationToSquare( int**& matrix, int& k ) { // піднесення до квадрату
    int** Result = new int* [k];
    for ( int i = 0; i < k; i++ ) {
        Result[i] = new int[k];
        for ( int j = 0; j < k; j++ ) {
            Result[i][j] = 0;
            for ( int n = 0; n < k; n++ )
                Result[i][j] += matrix[i][n] * matrix[n][j];
        }
    }
    return Result;
}

int** Delete(int **&matrix, int k) { // видалення
    for (int i = 0; i < k; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

bool DiagonalAdvantage(int** matrix, int& m) { //діагональна перевага
    int DiagonalElements = 0;
    for (int i = 0; i < m; i++) {
        DiagonalElements = matrix[i][i];
        for (int j = 0; j < m; j++) {
            if (abs(DiagonalElements) < matrix[i][j]) return false;
        }
    }
    return true;
}
int main() {
    cout << ">> Task 1 <<" << endl;
    int k;
    cout << "Введіть кількість рядків та стовпців: ";
    cin >> k;
    int **matrixA = CreateMatrix(k), **matrixB = CreateMatrix(k);

    cout << "Введіть елементи першої матриці: " << endl;
    ReadMatrix(matrixA, k);
    cout << "Введіть елементи другої матриці: " << endl;
    ReadMatrix(matrixB, k);
    int** C = DeductionForMatrix(matrixA, matrixB, k);
    int** Result = ElevationToSquare(C, k);
    cout << "\n Результат: " << endl;
    PrintMatrix(Result, k);
    Delete(matrixA, k);
    Delete(matrixB, k);
    Delete(C, k);
    Delete(Result, k);
    cout << ">> Task 2 <<" << endl;
    int m;
    cout << "m = ";
    cin >> m;
    int **matrix = CreateMatrix(k);
    cout << "Введіть елементи матриці: " << endl;
    ReadMatrix(matrix, k);
    if (DiagonalAdvantage(matrix, m)) {
        cout << "Результат: Задана матриця володіє діагональною перевагою" << endl;
    }
    else {
        cout << "Результат: Задана матриця не володіє діагональною перевагою" << endl;
    }
    Delete(matrix,m);
}

/*
1 3 2
1 6 5
7 2 4

1 8 5
4 3 6
2 3 8

3 -2 1
1 -3 2
-1 2 4


 -2 2 1
 1 3 2
 1 -2 0
 */
