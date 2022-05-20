// Прочитати матриці A та B розміром n´n. Обчислити величину (A – B)^2.
// Прочитати дійсну матрицю розміром n´n. Виявити, чи задана матриця володіє діагональною перевагою
// (діагональні елементи по модулю переважають інших у своїх стрічці).

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

template<class T>
void inputMatrix(vector<vector<T>> &arr) {
    for (auto &row: arr)
        for (auto &el: row)
            cin >> el;
}

template<class T>
void outputMatrix(const vector<vector<T>> &arr) {
    for (auto &row: arr)
        for (auto &el: row)
            cout << setw(3) << el << (&el == &row.back() ? '\n' : ' ');
}

template<class T>
vector<vector<T>> operator+(const vector<vector<T>> &arr1, const vector<vector<T>> &arr2) {
    auto res(arr1);
    for (int i = 0; i < res.size(); ++i)
        for (int j = 0; j < res[0].size(); ++j)
            res[i][j] += arr2[i][j];
    return res;
}

template<class T>
vector<vector<T>> operator-(const vector<vector<T>> &arr1, const vector<vector<T>> &arr2) {
    auto res(arr1);
    for (int i = 0; i < res.size(); ++i)
        for (int j = 0; j < res[0].size(); ++j)
            res[i][j] -= arr2[i][j];
    return res;
}

template<class T>
vector<vector<T>> operator*(const vector<vector<T>> &arr1, const vector<vector<T>> &arr2) {
    vector<vector<T>> res(arr1.size(), vector<T>(arr2[0].size(), 0));
    for (int i = 0; i < res.size(); ++i)
        for (int j = 0; j < res[0].size(); ++j)
            for (int k = 0; k < arr2.size(); ++k)
                res[i][j] += arr1[i][k] * arr2[k][j];
    return res;
}

template<class T>
bool checkIfDiagonallyDominant(const vector<vector<T>> &matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        double sum_of_abs_row = 0, abs_diagonal_entry = abs(matrix[i][i]);
        for (int j = 0; j < matrix[0].size(); ++j)
            if (i != j)
                sum_of_abs_row += abs(matrix[i][j]);
        if (abs_diagonal_entry - sum_of_abs_row < +2e-16) // strict diagonal dominance, if weak -2e-16
            return false;
    }
    return true;
}

int main() {
    size_t n{};
    cout << "Прочитати матриці A та B розміром n*n. Обчислити величину (A – B)^2.\ninput n: ";
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n)); // тип матриці (int, double)
    for (char i = 'A'; auto pMatrix: {&a, &b}) { // since C++20
        cout << "\ninput matrix " << i++ << ":\n";
        inputMatrix(*pMatrix);
        outputMatrix(*pMatrix);
    }
    cout << "\n(A - B) ^ 2 =\n";
    auto result = (a - b) * (a - b);
    outputMatrix(result);
    //-----------------------------------------------------------------------------------------------------------------
    cout << "\nПрочитати дійсну матрицю розміром n*n. Виявити, чи задана матриця володіє діагональною перевагою\n"
            "(діагональні елементи по модулю переважають інших у своїх стрічці).\ninput n: ";
    cin >> n;
    vector<vector<double>> diag_matrix(n, vector<double>(n));
    cout << "\ninput matrix:\n";
    inputMatrix(diag_matrix);
    outputMatrix(diag_matrix);
    cout << boolalpha << "\nМатриця володіє діагональною перевагою: " << checkIfDiagonallyDominant(diag_matrix) << endl;
    return 0;
}
// -4 2 1 1 6 2 1 -2 5
// .3 .1 .2 .1 .3 .2 .1 .2 .3