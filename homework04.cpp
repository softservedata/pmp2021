// Засобами C++ написати код для обчислення суми трьох матриць A, B, C однакового розміру.

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
using T = int; // int або double, всі функції перегружені

template<class T>
vector<vector<T>> operator+(const vector<vector<T>> &matrixA, const vector<vector<T>> &matrixB) {
    auto matrixC(matrixA);
    for (int i = 0; i < matrixC.size(); ++i)
        for (int j = 0; j < matrixC[0].size(); ++j)
            matrixC[i][j] += matrixB[i][j];
    return matrixC;
}

template<class T>
void enter_matrix(vector<vector<T>> &arr) {
    for (auto &row: arr)
        for (auto &el: row)
            cin >> el;
}

template<class T>
void print_matrix(const vector<vector<T>> &arr) {
    for (auto &row: arr)
        for (auto &el: row)
            cout << setw(3) << el << (&el == &row.back() ? '\n' : ' ');
}

template<class ...Args>
auto evaluate_sum_of_matrices(Args &&...args) {
    return (args + ...);
}

int main() {
    size_t m, n;
    cout << "Сума матриць A, B, C [m*n]\nВведіть m і n: ";
    cin >> m >> n;
    vector<vector<T>> a(m, vector<T>(n)), b(m, vector<T>(n)), c(m, vector<T>(n));
    for (char i = 'A'; auto pMatrix: {&a, &b, &c}) { // since C++20
        cout << "\nВведіть матрицю " << i++ << ":\n";
        enter_matrix<T>(*pMatrix);
        print_matrix<T>(*pMatrix);
    }
    auto res = evaluate_sum_of_matrices(a, b, c); // приймає будь-яку кількість матриць
    cout << "\nМатриця D:\n";
    print_matrix(res);
    return 0;
}