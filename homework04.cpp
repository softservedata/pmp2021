#include <iostream>
#include <vector>

template<typename T>
std::vector<std::vector<T>> operator+(const std::vector<std::vector<T>> &matrix_a,
                                      const std::vector<std::vector<T>> &matrix_b) {
    std::vector<std::vector<T>> matrix_c(matrix_a);
    for (int i = 0; i < matrix_b.size(); ++i)
        for (int j = 0; j < matrix_b[0].size(); ++j)
            matrix_c[i][j] += matrix_b[i][j];
    return matrix_c;
}

template<typename T>
void enter_matrix(std::vector<std::vector<T>> &arr) {
    for (auto &row: arr)
        for (auto &el: row)
            std::cin >> el;
}

template<typename T>
void print_matrix(const std::vector<std::vector<T>> &arr) {
    for (const auto &row: arr)
        for (const auto &el: row)
            std::cout << el << (&el == &row.back() ? '\n' : ' ');
}

template<class T1, class ...T>
T1 evaluate_sum_of_matrices(const T1 &first_matrix, const T &...Args) {
    if constexpr(sizeof ...(Args) > 0)
        return first_matrix + evaluate_sum_of_matrices(Args...);
    return first_matrix;
}

template<typename T>
void input_matrix(std::vector<std::vector<T>> &arr) {
    std::cout << "Введіть матрицю:\n";
    enter_matrix(arr);
    print_matrix(arr);
}

int main() {
    int m{}, n{};
    std::cout << "Сума матриць A, B, C [m*n]\nВведіть m і n: ";
    std::cin >> m >> n;
    std::vector<std::vector<int>> // int або double, всі функції перегружені
            a(m, std::vector<int>(n)),
            b(m, std::vector<int>(n)),
            c(m, std::vector<int>(n));
    input_matrix(a);
    input_matrix(b);
    input_matrix(c);
    auto res = evaluate_sum_of_matrices(a, b, c); // приймає будь-яку кількість матриць
    std::cout << "Матриця D:\n";
    print_matrix(res);
    return 0;
}