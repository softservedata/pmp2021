#include <iostream>
#include <iomanip>
#include <vector>

template<typename Vec>
Vec operator+(const Vec &matrixA, const Vec &matrixB) {
    Vec matrixC(matrixA);
    for (int i = 0; i < matrixC.size(); ++i)
        for (int j = 0; j < matrixC[0].size(); ++j)
            matrixC[i][j] += matrixB[i][j];
    return matrixC;
}

template<typename Vec>
void enter_matrix(Vec &arr) {
    for (auto &row: arr)
        for (auto &el: row)
            std::cin >> el;
}

template<typename Vec>
void print_matrix(const Vec &arr) {
    for (const auto &row: arr)
        for (const auto &el: row)
            std::cout << std::setw(3) << el << (&el == &row.back() ? '\n' : ' ');
}

template<class Vec, class ...T>
Vec evaluate_sum_of_matrices(const Vec &first_matrix, const T &...Args) {
    if constexpr(sizeof ...(Args) > 0)
        return first_matrix + evaluate_sum_of_matrices(Args...);
    return first_matrix;
}

int main() {
    int m{}, n{};
    std::cout << "Сума матриць A, B, C [m*n]\nВведіть m і n: ";
    std::cin >> m >> n;
    std::vector<std::vector<int>> // int або double, всі функції перегружені
            a(m, std::vector<int>(n)),
            b(m, std::vector<int>(n)),
            c(m, std::vector<int>(n));
    for (char i = 'A'; auto pMatrix: {&a, &b, &c}) { // since C++20
        std::cout << "\nВведіть матрицю " << i++ << ":\n";
        enter_matrix(*pMatrix);
        print_matrix(*pMatrix);
    }
    auto res = evaluate_sum_of_matrices(a, b, c); // приймає будь-яку кількість матриць
    std::cout << "\nМатриця D:\n";
    print_matrix(res);
    return 0;
}