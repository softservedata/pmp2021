#include <iostream>
using namespace std;

void create_matr(int n, int** matrix);
void print_matr(int n, int** matrix);
void sum_matr(int** matr1, int** matr2, int** matr3, int** matr_result, int n);
void fill_matr(int n, int** matrix);

int main05()
{
    int n;
    cout << "n=";
    cin >> n;
    int** A = new int* [n];
    int** B = new int* [n];
    int** C = new int* [n];
    int** D = new int* [n];
    create_matr(n, A); cout << "Matrix A:" << endl; fill_matr(n, A);
    create_matr(n, B); cout << "Matrix B:" << endl; fill_matr(n, B);
    create_matr(n, C); cout << "Matrix C:" << endl; fill_matr(n, C);
    create_matr(n, D);
    sum_matr(A, B, C, D, n);
    cout << "Matrix D:" << endl;
    print_matr(n,D);

    return 0;
}

void create_matr(int n, int** matrix) {
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];
}

void fill_matr(int n, int** matrix) {
    unsigned int k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> k;
            matrix[i][j] = k;
        }
    cout << "\n\n";
}


void print_matr(int n, int** matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\n\n";
}

void sum_matr(int** matr1, int** matr2,int** matr3,int**matr_result,int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matr_result[i][j] = matr1[i][j] + matr2[i][j] + matr3[i][j];
        }
    }

}
