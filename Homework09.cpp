#include <iostream>

using namespace std;

int** read_matrix(int &n){
    cout << "\nInput new Matrix:\n";
    do {
        cout << "n =";
        cin >> n;
    } while (n < 1);

    cout << "Input Matrix with n = " << n << endl;
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i){
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j){
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

void print_matrix(int** &matrix, int &n){
    cout << "\nSorted Matrix:\n";
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void array_delete(int *arr){
    delete[] arr;
}

void matrix_delete(int** &matrix, int &n){
    for (int i = 0; i < n; ++i){
        delete [] matrix[i];
    }
    delete [] matrix;
}

int* first_column(int** &matrix, int &n){
    int* array = new int[n];
    for (int i = 0; i < n; ++i){
        array[i] = matrix[i][0];
    }
    return array;
}

int* sort_by_bubble(int *&arr, int &n){
    int temp1 = 0, temp2 = 0;
    bool is_sorted = false;
    int* i_arr = new int[n];

    for (int i = 0; i < n; ++i){
        i_arr[i] = i;
    }

    for (int i = 0; !is_sorted && (i < n - 1); ++i){
        is_sorted = true;
        for (int j = 0; j < n - i - 1; ++j){
            if (arr[j] > arr[j + 1]){
                temp1 = arr[j];
                temp2 = i_arr[j];
                arr[j] = arr[j + 1];
                i_arr[j] = i_arr[j + 1];
                arr[j + 1] = temp1;
                i_arr[j + 1] = temp2;
                is_sorted = false;
            }
        }
    }
    return i_arr;
}

int** matrix_sorted_by_columns(int** matrix, int &n){

    int* first_colum = first_column(matrix, n);
    int* i_arr =  sort_by_bubble(first_colum, n);

    int** new_matrix = new int*[n];
    for (int i = 0; i < n; ++i){
        new_matrix[i] = new int[n];
        for (int j = 0; j < n; ++j){
            new_matrix[i][j] = matrix[i_arr[i]][j];
        }
    }

    array_delete(first_colum);
    array_delete(i_arr);

    return new_matrix;
}

int main(){
    int n;
    int** matrix = read_matrix(n);
    int** matrix_sorted = matrix_sorted_by_columns(matrix, n);

    matrix_delete(matrix, n);

    print_matrix(matrix_sorted, n);

    matrix_delete(matrix_sorted, n);

    return 0;
}

