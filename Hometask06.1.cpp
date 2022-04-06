#include <iostream>
using namespace std;

void delete_matr(int** matr, int n) {
    for (int i = 0; i < n; i++)
        delete[] matr[i];
    delete[] matr;
}

void create_matr(int** matrix, int n) {
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];
}

void fill_matr(int** matrix, int n) {
    unsigned int k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> k;
            matrix[i][j] = k;
        }
    cout << "\n\n";
}

void print_matr(int** matr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void diff_matr(int** matr1, int** matr2, int** matr3, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matr3[i][j] = matr1[i][j] - matr2[i][j];
        }
    }

}

void square_matr(int** matr1, int** matr2, int n) {
    int sum;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum = 0;
            for (int k = 0; k < n; k++) {
                sum += matr1[i][k] * matr1[k][j];
            }
            matr2[i][j] = sum;
        }
    }
}

int main() {
    int n;
    cout << "n=";
    cin >> n;
    int** A = new int* [n];
    int** B = new int* [n];
    int** C = new int* [n];
    int** D = new int* [n];
    create_matr(A, n); cout << "Matrix A:" << endl; fill_matr(A, n);
    create_matr(B, n); cout << "Matrix B:" << endl; fill_matr(B, n);
    create_matr(C, n);
    create_matr(D, n);
    diff_matr(A, B, C, n);
    cout << "Matrix C:" << endl;
    print_matr(C, n);
    square_matr(C, D, n);
    cout << "Matrix C^2:" << endl;
    print_matr(D, n);
    delete_matr(A, n);
    delete_matr(B, n);
    delete_matr(C, n);
    delete_matr(D, n);
    system("PAUSE");
    return 0;
}

