#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

template<typename Vec>
auto input_martix(Vec &arr) {
    for (auto &row: arr)
        for (auto &el: row)
            std::cin >> el;
}

template<typename Vec>
auto output_martix(const Vec &arr) {
    for (const auto &row: arr)
        for (const auto &el: row)
            std::cout << std::setw(3) << el << (&el == &row.back() ? '\n' : ' ');
}

template<typename Vec>
auto operator+(const Vec &arr1, const Vec &arr2) {
    Vec res(arr1);
    for (int i = 0; i < res.size(); ++i)
        for (int j = 0; j < res[0].size(); ++j)
            res[i][j] += arr2[i][j];
    return res;
}

template<typename Vec>
auto operator-(const Vec &arr1, const Vec &arr2) {
    Vec res(arr1);
    for (int i = 0; i < res.size(); ++i)
        for (int j = 0; j < res[0].size(); ++j)
            res[i][j] -= arr2[i][j];
    return res;
}

template<typename Row>
auto operator*(const std::vector<Row> &arr1, const std::vector<Row> &arr2) {
    std::vector<Row> res(arr1.size(), Row(arr2[0].size(), 0));
    for (int i = 0; i < res.size(); ++i)
        for (int j = 0; j < res[0].size(); ++j)
            for (int k = 0; k < arr2.size(); ++k)
                res[i][j] += arr1[i][k] * arr2[k][j];
    return res;
}

template<typename Vec>
auto check_if_diagonally_dominant(const Vec &matrix) {
    bool flag = true;
    for (int i = 0; i < matrix.size(); ++i) {
        double sum_of_abs_row{}, abs_diagonal_entry{};
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (i == j)
                abs_diagonal_entry = std::abs(matrix[i][j]);
            else
                sum_of_abs_row += std::abs(matrix[i][j]);
        }
        if (abs_diagonal_entry <= sum_of_abs_row) { // strict diagonal dominance, if weak <
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    int n{};
    std::cout << "Прочитати матриці A та B розміром n*n. Обчислити величину (A – B)^2.\ninput n: ";
    std::cin >> n;
    std::vector<std::vector<int>>       // тип матриці (int, double etc.)
    a(n, std::vector<int>(n)),
            b(n, std::vector<int>(n));
    for (char i = 'A'; auto pMatrix: {&a, &b}) { // since C++20
        std::cout << "\ninput matrix " << i++ << ":\n";
        input_martix(*pMatrix);
        output_martix(*pMatrix);
    }
    std::cout << "\n(A - B) ^ 2 =\n";
    auto result = (a - b) * (a - b);
    output_martix(result);
    //-----------------------------------------------------------------------------------------------------------------
    std::cout << "\nПрочитати дійсну матрицю розміром n*n. Виявити, чи задана матриця володіє діагональною перевагою\n"
                 "(діагональні елементи по модулю переважають інших у своїх стрічці).\ninput n: ";
    std::cin >> n;
    std::vector<std::vector<double>> diag_matrix(n, std::vector<double>(n));
    std::cout << "\ninput matrix:\n";
    input_martix(diag_matrix);
    output_martix(diag_matrix);
    std::cout << std::boolalpha << "\nМатриця володіє діагональною перевагою: "
              << check_if_diagonally_dominant(diag_matrix) << std::endl;
    return 0;
}
// -4 2 1 1 6 2 1 -2 5