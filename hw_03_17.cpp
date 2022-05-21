#include <iostream>
using namespace std;
int main() {
    cout << "Enter size matrix 1: " << endl;
    int n;
    cin >> n;
    int m;
    cin >> m;
    cout << "Enter numbers for matrix 1: " << endl;
    int **matrix01 = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix01[i] = new int[m]{};
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix01[i][j];
        }
    }
    cout << "Enter numbers for matrix 2: " << endl;
    int **matrix02 = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix02[i] = new int[m]{};
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix02[i][j];
        }
    }

    cout << "Enter numbers for matrix 3: " << endl;
    int **matrix03 = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix03[i] = new int[m]{};
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix03[i][j];
        }
    }
    int **matrix_res = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix_res[i] = new int[m]{};
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix_res[i][j] = matrix01[i][j]+matrix02[i][j]+matrix03[i][j];
            cout << matrix_res[i][j]<<'\t';
        }
        cout <<'\t';
    }

    return 0;
}
