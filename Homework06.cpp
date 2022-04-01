#include <iostream>
#include <cmath>

using namespace std;

int Cin(){
    int n;
    cout << "Enter quantity of rows and columns:";
    cin >> n;
    return n;
}

double** read_matrix(int &n){
    double** matrix = new double*[n];
    for (int i = 0; i < n; ++i){
        *(matrix + i) = new double[n];
        for (int j = 0; j < n; ++j){
            cin >> *(*(matrix + i) + j);
        }
    }
    cout << endl;
    return matrix;
}

void print_matrix(double **matrix, int &n){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

double **subtraction_matrices(double **matrix1, double **matrix2, int &n){
    double** matrix = new double*[n];
    for (int i = 0; i < n; ++i){
        *(matrix + i) = new double[n];
        for (int j = 0; j < n; ++j){
            *(*(matrix + i) + j) = *(*(matrix1 + i) + j) - *(*(matrix2 + i) + j);
        }
    }
    return matrix;
}

double **multiply_matrices(double **matrix1, double **matrix2, int &n){
    double **matrix = new double*[n], sum = 0;
    for (int i = 0; i < n; ++i){
        *(matrix + i) = new double[n];
        for (int j = 0; j < n; ++j){
            for (int l = 0; l < n; ++l){
                sum += matrix1[i][l] * matrix2[l][j];
            }
            matrix[i][j] = sum;
            sum = 0;
        }
    }
    return matrix;
}

bool diagonal_advantage(double **matrix, int &n){
    double d, sum = 0;
    for (int i = 0; i < n; ++i){
        d = *(*(matrix + i) + i);
        for (int j = 0; j < n; ++j){
            if (j == i) ++j;
            sum += fabs(*(*(matrix + i) + j));
        }
        if (fabs(d) < sum) return false;
        sum = 0;
    }
    return true;
}

void matrix_delete(double **matrix, int &n){
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main(){
    // Task 1
    int n = Cin();
    double **A = read_matrix(n), **B = read_matrix(n);
    double **C = subtraction_matrices(A, B, n);
    double **P = multiply_matrices(C, C, n);
    print_matrix(P, n);
    matrix_delete(A, n);
    matrix_delete(B, n);
    matrix_delete(C, n);
    matrix_delete(P, n);

    // Task 2
    int n1 = Cin();
    double **matrix = read_matrix(n1);
    cout << "Your result: " << diagonal_advantage(matrix, n1);
    matrix_delete(matrix, n1);

    return 0;
}
