#include <iostream>
#include <algorithm>
using namespace std;

int** read_matrix(int& n) {
    cout << "\nInput new Matrix:\n";
    do {
        cout << "n =";
        cin >> n;
    } while (n < 1);

    cout << "Input Matrix with n = " << n << endl;
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

void print_matrix(int**& matrix, int& n) {
    cout << "\nSorted Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}


void matrix_delete(int**& matrix, int& n) {
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void transpose(int** mat, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
}

void sortByRow(int** mat, int n, bool ascending)
{
    for (int i = 0; i < n; i++)
    {
        if (ascending)
            sort(mat[i], mat[i] + n);
        else
            sort(mat[i], mat[i] + n, greater<int>());
    }
}
void sortMatColWise(int** mat, int n) {
    //sortByRow(mat, n, true);
    transpose(mat, n);
    sortByRow(mat, n, false);
    transpose(mat, n);
}
int main() {
    int n;
    int** matrix = read_matrix(n);

    //int** transposematr = transpose(matrix, n);
    sortMatColWise(matrix, n);
    //print_matrix(matrix, n);
    print_matrix(matrix, n);

    matrix_delete(matrix, n);
    //matrix_delete(transposematr, n);
 

    return 0;
}
