#include <iostream>

using namespace std;

struct MyMatrix{
    int ** arr2D;
    int n;

    ~MyMatrix(){
        for (int i = 0; i < n; ++i){
            delete [] arr2D[i];
        }
        delete [] arr2D;
    }
};

void matrix_read_struct(MyMatrix *&matrix, int n = 0) {
    matrix = new MyMatrix();
    cout << "\nInput new Matrix\n";
    if (n <= 0) {
        do {
            cout << "n=";
            cin >> matrix->n;
        } while (matrix->n < 1);
    }else matrix->n = n;
    cout << "Input Matrix with " << matrix->n << " rows and columns\n";
    matrix -> arr2D = new int *[matrix -> n];
    for (int i = 0; i < matrix->n; ++i){
        matrix->arr2D[i] = new int[matrix->n];
        for (int j = 0; j < matrix->n; ++j){
            cin >> matrix -> arr2D[i][j];
        }
    }
}

void matrix_delete_struct(MyMatrix *&matrix) {
    delete matrix;
}

void matrix_print_struct(MyMatrix *&matrix, const string &message) {
    cout << "\nMatrix " << message << endl;
    for (int i = 0; i < matrix->n; ++i) {
        for (int j = 0; j < matrix->n; ++j) {
            cout << matrix->arr2D[i][j] << '\t';
        }
        cout << endl;
    }
}

void transpose_matrix(MyMatrix *&a, MyMatrix *&b){
    b = new MyMatrix();
    b->arr2D = new int*[a->n];
    for (int i = 0; i < a->n; ++i){
        b->arr2D[i] = new int[a->n];
        for (int j = 0; j < a->n; ++j){
            b->arr2D[i][j] = a->arr2D[j][i];
        }
    }
    b->n = a->n;
}

bool is_symmetrical_matrix(MyMatrix *& matrix){
    for (int i = 0; i < matrix->n; ++i){
        for (int j = 0; j < matrix->n; ++j){
            if ((matrix->arr2D[i][j]) != (matrix->arr2D[j][i])) return false;
        }
    }
    return true;
}

int main(){
    MyMatrix* a = NULL;
    MyMatrix* b = NULL;

    matrix_read_struct(a);
    matrix_print_struct(a, "A");
    transpose_matrix(a, b);
    matrix_print_struct(b, "Transposed A");

    matrix_delete_struct(a);
    matrix_delete_struct(b);

    MyMatrix* A = NULL;

    matrix_read_struct(A);
    matrix_print_struct(A, "A");
    if(is_symmetrical_matrix(A)) cout << "This is symmetrical matrix\n" << is_symmetrical_matrix(A);
    else cout << "This is not symmetrical matrix\n";

    matrix_delete_struct(A);

    return 0;
}