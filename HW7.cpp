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
void delete_matr(int** matr, int row, int column) {
    for (int i = 0; i < row; i++) {
        delete[]matr[i];
    }
    delete[] matr;
}
int** transposed_matrix(int**& A, int& n) {
    int** transp = new int*[n];
    for (int i = 0; i < n; i++)
    {
        transp[i] = new int[n];
        for (int j = 0; j < n; j++) {
            transp[i][j] = A[j][i];
        }
    }
    return transp;
}
bool Symetric(int**& matr, int n) {
    int** tr = transposed_matrix(matr, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matr[i][j] != tr[i][j])return false;
        }
    }
    return true;
}
int main() {
	cout << "homework 04-02" << endl;
	cout << "Task 1" << endl;
	int n;
	cout << "n = ";
	cin >> n;
    cout << "\nA matrix : " << endl;
    int** A = read_matrix(n, n);
    cout << "A matrix:\n";
    print(A, n);
    cout << "Result transposed matrix" << endl;
    int** tr = transposed_matrix(A, n);
    print(tr, n);
    delete_matr(A, n, n);
    delete_matr(tr, n, n);
    cout << "Task 2" << endl;
    int m;
    cout << "m = ";
    cin >> m;
    cout << "\nB matrix : " << endl;
    int** B= read_matrix(m, m);
    cout << "B matrix:\n";
    print(B, m);
    cout << "Result " << endl;
    if (Symetric(B,m))cout << "True, matrix is symetric" << endl;
    else cout << "false, matrix not symetric" << endl;
delete_matr(B, m, m);
}
