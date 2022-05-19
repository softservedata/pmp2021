#include <iostream>

using namespace std;

int **CreateMatrix(int k) {
    int **matrix = new int *[k];
    for (int i = 0; i < k; ++i) {
        matrix[i] = new int[k]{};
    }
    return matrix;
}


void Delete(int **&matrix, int k) { //видалення
    for (int i = 0; i < k; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
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

int **SumOfMatrix(int **matrix1, int **matrix2, int **matrix3, int k) { //сума матриць
    int **matrix = CreateMatrix(k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            matrix[i][j] = matrix1[i][j] + matrix2[i][j] + matrix3[i][j];
        }
    }
    return matrix;
}


int main() {
    int k;
    cout << "Введіть кількість рядків та стовпців: ";
    cin >> k;
    int **matrix1 = CreateMatrix(k), **matrix2 = CreateMatrix(k), **matrix3 = CreateMatrix(k);

    cout << "Введіть елементи першої матриці: " << endl;
    ReadMatrix(matrix1, k);
    cout << "Введіть елементи другої матриці: " << endl;
    ReadMatrix(matrix2, k);
    cout << "Введіть елементи третьої матриці:" << endl;
    ReadMatrix(matrix3, k);

    int **sum = SumOfMatrix(matrix1, matrix2, matrix3, k);
    cout << "Сума трьох матриць: " << endl;
    PrintMatrix(sum, k);

    Delete(matrix1, k);
    Delete(matrix2, k);
    Delete(matrix3, k);
    Delete(sum, k);
    return 0;
}