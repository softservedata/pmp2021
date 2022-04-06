#include<iostream>
using namespace std;
int** read_matrix(int n, int m) {
    int** matr = new int* [n];
    for (int i = 0; i < n; i++) {
        matr[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cout << "[" << i << "][" << j << "] = ";
            cin >> matr[i][j];
        }
    }
    return matr;
}
void print(int** matr, int& n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }
}
int** subtraction(int**& A, int**& B, int& n) {
    int** res = new int* [n];
    for (int i = 0; i < n; i++) {
        res[i] = new int[n];
        for (int j = 0; j < n; j++) {
            res[i][j] = A[i][j] - B[i][j];
        }
    }
    return res;
}


int** squared_matrix(int**& matrix, int& n) {
    int** res = new int* [n];
    for (int i = 0; i < n; i++) {
        res[i] = new int[n];
        for (int j = 0; j < n; j++) {
            res[i][j] = 0;
            for (int k = 0; k < n; k++)
                res[i][j] += matrix[i][k] * matrix[k][j];
        }
    }
    return res;
}
void delete_matr(int** matr, int row, int column) {
    for (int i = 0; i < row; i++) {
        delete[]matr[i];
    }
    delete[] matr;
}
bool Task2(int** matr, int& n) {
    int diagEl = 0;
    for (int i = 0; i < n; i++) {
        diagEl = matr[i][i];
        for (int j = 0; j < n; j++) {
            if (abs(diagEl) < matr[i][j]) return false;
        }
    }
    return true;
}
int main() {
    cout << "homework 03-31" << endl;
    cout << "Task 1" << endl;
    int n;
    cout << "n = ";
    cin >> n;
    cout << "A matrix :" << endl;
    int** A = read_matrix(n, n);
    cout << "\nB matrix :" << endl;
    int** B = read_matrix(n, n);
    int** C = subtraction(A, B, n);
    int** Result = squared_matrix(C, n);
    cout << "\n Result" << endl;
    print(Result, n);
    delete_matr(A, n, n);
    delete_matr(B, n, n);
    delete_matr(C, n, n);
    delete_matr(Result, n, n);
    cout << "Task 2" << endl;
    int m;
    cout << "m = ";
    cin >> m;
    int** matr = read_matrix(m, m);
    print(matr, m);
    cout << "Result:" << endl;
    if (Task2(matr, m))cout << "true abs diagonal elem is bigger" << endl;
    else cout << "false " << endl;
    delete_matr(matr, m, m);
}