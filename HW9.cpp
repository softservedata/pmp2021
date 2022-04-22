#include <iostream>
#include <algorithm>
using namespace std;

int** read(int n, int m) {
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> arr[i][j];
        }
        cout << endl;
    }
    return arr;
}


void print(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
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


void sort(int** arr, int n)
{
    int imax = 0;
    int max = 0;
    for (int i = 0; i < n - 1; i++)
    {
        imax = 0;
        max = arr[imax][0];
        for (int j = 0; j < n - i; j++)
        {
            if (max < arr[j][0])
            {
                imax = j;
                max = arr[imax][0];
            }
        }
        arr[imax][0] = arr[n - i - 1][0];
        arr[n - i - 1][0] = max;
        for (int k = 1; k < n; k++) {
            int a = arr[imax][k];
            arr[imax] [k] = arr[n - i - 1][k];
            arr[n - i - 1][k] = a;
        }
    }
}


int main() {
    int n; 
    cout << " n = ";
    cin >> n;
    int** matrix = read(n,n);
    cout << "Before sorting" << endl;
    print(matrix, n);
    sort(matrix, n);
    cout << "\nSorted" << endl;
    print(matrix, n);
    delete_matr(matrix, n, n);
}