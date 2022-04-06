#include <iostream>
using namespace std;

void create_matr(int** matrix, int n);
void fill_matr(int** matrix, int n);
bool diagonal_matr(int** matrix, int n);

int main() {
    int n;
    cout << "n=";
    cin >> n;
    int** A = new int* [n];
    create_matr(A, n); fill_matr(A, n);
    if (diagonal_matr(A, n)) cout << "Yes" << endl;
    else cout << "No" << endl;
    system("PAUSE");
    return 0;
}

bool diagonal_matr(int** matrix, int n) {
    int count = 0, J = 0;
    int abs_sum;
    for (int i = 0; i < n; i++) {
        abs_sum = 0;
        for (int j = 0; j < n; j++) {
            if (j != i) abs_sum += matrix[i][j];
        }
        if (matrix[i][J] >= abs_sum) count++;
        J++;
    }
    cout << "count = " << count << endl;
    if (count == n) return true;
    return false;
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