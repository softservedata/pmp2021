/*#include <iostream>
using namespace std;
int main() {
    cout << "Enter size matrix 1: " << endl;
    int n;
    cin >> n;
    cout << "Enter numbers for matrix 1: " << endl;
    int **matrix01 = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix01[i] = new int[n]{};
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix01[i][j];
        }
    }
    int **matrix_T = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix_T[i] = new int[n]{};
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix_T[i][j]=matrix01[j][i];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix_T[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
        {
            if (matrix_T[i][j]!=matrix01[i][j])
            {
                cout << 'NO';
                break;
            }
        }
    }
}*/