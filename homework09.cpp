#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ranges>

using namespace std;

template<typename Vec>
void input_matrix(Vec &arr) {
    for (auto &row: arr)
        for (auto &el: row)
            cin >> el;
}

template<typename Vec>
void output_matrix(const Vec &arr) {
    for (const auto &row: arr)
        for (const auto &el: row)
            cout << setw(2) << el << (&el == &row.back() ? '\n' : ' ');
}

// Прочитати з клавіатури квадратну матрицю.
// Посортувати рядки матриці по зростанню на основі значень елементів першого стовпчика
int main() {
    int n{};
    cout << "Enter n: ";
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    cout << "Enter square matrix A[n*n]:\n";
    input_matrix(a);
    output_matrix(a);
    ranges::sort(a); // C++20
    cout << "Matrix A sorted by first column:\n";
    output_matrix(a);
    return 0;
}