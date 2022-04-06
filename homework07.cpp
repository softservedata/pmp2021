#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

template<typename Vec>
void input_martix(Vec &arr) {
    for (auto &row: arr)
        for (auto &el: row)
            cin >> el;
}

template<typename Vec>
void output_martix(const Vec &arr) {
    for (const auto &row: arr)
        for (const auto &el: row)
            cout << std::setw(2) << el << (&el == &row.back() ? '\n' : ' ');
}

template<typename T>
auto transpose_martix(const vector<vector<T>> &arr) {
    vector<vector<T>> res(arr.at(0).size(), vector<T>(arr.size()));
    for (int i = 0; i < res.size(); ++i)
        for (int j = 0; j < res[0].size(); ++j)
            res[i][j] = arr[j][i];
    return res;
}

template<typename T>
bool check_if_symmetric(const vector<vector<T>> &arr) {
    for (int i = 0; i < arr.size(); ++i)
        for (int j = i + 1; j < arr.at(0).size(); ++j)
            if (arr[i][j] != arr[j][i])
                return false;
    return true;
}

int main() {
    // Прочитати матрицю A розміром n*n. Знайти транспоновану матрицю A^T.
    int n{};
    cout << "Enter n: ";
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    cout << "Enter square matrix A[n*n]:\n";
    input_martix(a);
    output_martix(a);
    auto aT = transpose_martix(a);
    cout << "\nA^T:\n";
    output_martix(aT);
    // Прочитати матрицю A розміром n*n. Перевірити, чи матриця симетрична відносно основної діагоналі.
    cout << boolalpha << "\nA is symmetric: " << check_if_symmetric(a) << endl;
    return 0;
}