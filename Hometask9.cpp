#include <iostream>

using namespace std;

int** read_matrix(int& n) {
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

void print_matrix(int**& matrix, int& n) {
    cout << "\nSorted Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void array_delete(int* arr) {
    delete[] arr;
}

void matrix_delete(int**& matrix, int& n) {
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int* first_column(int**& matrix, int& n) {
    int* array = new int[n];
    for (int i = 0; i < n; ++i) {
        array[i] = matrix[i][0];
    }
    return array;
}

void merge(int* arr, int* i_arr, int p, int q, int r) {
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

void sort_by_merge(int* arr, int* i_arr, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        //cout << "start index = " << p << " middle index = " << q << " last index = " << r << endl;
        sort_by_merge(arr, i_arr, p, q);
        sort_by_merge(arr, i_arr, q + 1, r);
        //
        merge(arr, i_arr, p, q, r);
    } //else cout << "\tstart index = " << p << " last index = " << r << " element = " << arr[p] << endl;
}

int** matrix_sorted_by_columns(int** matrix, int& n) {

    int* first_colum = first_column(matrix, n);
    int* i_arr = new int[n];
    for (int i = 0; i < n; ++i) {
        i_arr[i] = i;
    }

    sort_by_merge(first_colum, i_arr, 0, n - 1);

    int** new_matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        new_matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            new_matrix[i][j] = matrix[i_arr[i]][j];
        }
    }

    array_delete(first_colum);
    array_delete(i_arr);

    return new_matrix;
}

int main() {
    int n;
    int** matrix = read_matrix(n);
    int** matrix_sorted = matrix_sorted_by_columns(matrix, n);

    matrix_delete(matrix, n);

    print_matrix(matrix_sorted, n);

    matrix_delete(matrix_sorted, n);

    return 0;
}
