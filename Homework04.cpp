#include <iostream>

using namespace std;

double** zero_matrix(int n){
    double** matrix = new double*[n];
    for (int i = 0; i < n; ++i){
        matrix[i] = new double[n];
        for (int j = 0; j < n; ++j){
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void matrix_delete(double** matrix, int n){
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

double** read_matrix(int n){
    double** matrix = new double*[n];
    for (int i = 0; i < n; ++i){
        matrix[i] = new double[n];
        for (int j = 0; j < n; ++j){
            cin >> matrix[i][j];
        }
    }
    cout << endl;
    return matrix;
}

double** sum_matrices(double** matrix1, double** matrix2, double** matrix3, int n){
    double** matrix = zero_matrix(n);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            matrix[i][j] = matrix1[i][j] + matrix2[i][j] + matrix3[i][j];
        }
    }
    return matrix;
}

void print_matrix(double** matrix, int n){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter quantity of rows and columns:";
    cin >> n;
    double** matrix1 = read_matrix(n);
    double** matrix2 = read_matrix(n);
    double** matrix3 = read_matrix(n);
    double** result = sum_matrices(matrix1, matrix2, matrix3, n);
    cout << "Sum of three matrices:" << endl;
    print_matrix(result, n);
    matrix_delete(matrix1, n);
    matrix_delete(matrix2, n);
    matrix_delete(matrix3, n);
    matrix_delete(result, n);

    return 0;
}