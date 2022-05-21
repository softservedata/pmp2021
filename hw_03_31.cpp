#include <iostream>
using namespace std;
int main() {
    cout << "Enter size matrix 1: " << endl;
    int n;
    cin >> n;
    cout << "Enter numbers for matrix 1: " << endl;
    int **matrix01 = new int *[n];
    for (int i = 0; i < n; ++i) {
        matrix01[i] = new int[n]{};
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix01[i][j];
        }
    }

    cout << "Enter numbers for matrix 2: " << endl;
    int **matrix02 = new int *[n];
    for (int i = 0; i < n; ++i) {
        matrix02[i] = new int[n]{};
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix02[i][j];
        }
    }
    int **matrix_res = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix_res[i] = new int[n]{};
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix_res[i][j] = matrix01[i][j]-matrix02[i][j];
        }
    }
    int **matrix03 = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix03[i] = new int[n]{};
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int s = 0; s < n; ++s) {
                matrix03[i][j] += matrix_res[i][s] * matrix_res[s][j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix03[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix01[i][i]<matrix01[i][j]){
                cout << "NO"<< endl;
                break;
            }
        }
        cout << "\n";
    }
}
