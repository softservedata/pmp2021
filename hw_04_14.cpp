#include <iostream>

using namespace std;

int* firstColumn(int**& matrix, int& n);
void MergeSort(int* arr, int* i_arr, int p, int q, int r);
int** sortedByColumns(int** matrix, int& n);
int** readMatrix(int& n);
void sortByMerge(int* arr, int* i_arr, int p, int r);
void printMatrix(int**& matrix, int& n);
void arrayDelete(int* arr);
void matrixDelete(int**& matrix, int& n);
int main() {
    int n;
    int** matrix = readMatrix(n);
    int** matrix_sorted = sortedByColumns(matrix, n);
    matrixDelete(matrix, n);
    printMatrix(matrix_sorted, n);
    matrixDelete(matrix_sorted, n);
    return 0;
}
int** sortedByColumns(int** matrix, int& n) {

    int* first_colum = firstColumn(matrix, n);
    int* i_arr = new int[n];
    for (int i = 0; i < n; ++i) {
        i_arr[i] = i;
    }

    sortByMerge(first_colum, i_arr, 0, n - 1);

    int** new_matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        new_matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            new_matrix[i][j] = matrix[i_arr[i]][j];
        }
    }

    arrayDelete(first_colum);
    arrayDelete(i_arr);

    return new_matrix;
}
int** readMatrix(int& n) {
    cout << "\nInput new Matrix:\n";
    do {
        cout << "n =";
        cin >> n;
    } while (n < 1);

    cout << "Input Matrix with n = " << n << endl;
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}
void sortByMerge(int* arr, int* i_arr, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        //cout << "start index = " << p << " middle index = " << q << " last index = " << r << endl;
        sortByMerge(arr, i_arr, p, q);
        sortByMerge(arr, i_arr, q + 1, r);
        //
        MergeSort(arr, i_arr, p, q, r);
    } //else cout << "\tstart index = " << p << " last index = " << r << " element = " << arr[p] << endl;
}
void printMatrix(int**& matrix, int& n) {
    cout << "\nSorted Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}
void MergeSort(int* arr, int* i_arr, int p, int q, int r) {
    int n = r - p + 1;
    int* arr_temp = new int[n];
    int* i_arr_temp = new int[n];

    int ip = p, iq = q + 1;
    int current1 = 0, current2 = 0;

    for (int i = 0; i < n; ++i) {
        if (ip <= q && iq <= r) {
            if (arr[ip] < arr[iq]) {
                current1 = arr[ip];
                current2 = i_arr[ip];
                ip++;
            }
            else {
                current1 = arr[iq];
                current2 = i_arr[iq];
                iq++;
            }
        }
        else if (ip <= q) {
            current1 = arr[ip];
            current2 = i_arr[ip];
            ip++;
        }
        else {
            current1 = arr[iq];
            current2 = i_arr[iq];
            iq++;
        }
        arr_temp[i] = current1; // O(n)
        i_arr_temp[i] = current2;
    }

    for (int i = 0; i < n; ++i) {
        arr[p + i] = arr_temp[i]; // O(n)
        i_arr[p + i] = i_arr_temp[i];
    }
    delete[] arr_temp;
    delete[] i_arr_temp;
}
int* firstColumn(int**& matrix, int& n) {
    int* array = new int[n];
    for (int i = 0; i < n; ++i) {
        array[i] = matrix[i][0];
    }
    return array;
}
void arrayDelete(int* arr) {
    delete[] arr;
}
void matrixDelete(int**& matrix, int& n) {
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
