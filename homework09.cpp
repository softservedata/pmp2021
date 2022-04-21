#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ranges>
#include <random>
#include <chrono>
#include <format> // MVS C++20 ++
#include <bitset>

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

template<typename Vec>
void mergeSort(Vec &a) { // loop, not recursion
    size_t block_size, block_it, l_it, r_it, l_border, r_border, m_border, i;
    Vec sort_block(a.size());
    for (block_size = 1; block_size < a.size(); block_size *= 2)
        for (block_it = 0; block_it < a.size() - block_size; block_it += 2 * block_size) {
            l_it = 0, r_it = 0; // sort_block is correctly reused without clearing
            l_border = block_it, m_border = block_it + block_size, r_border = min(block_it + 2 * block_size, a.size());
            while (l_border + l_it < m_border && m_border + r_it < r_border) {
                if (a[l_border + l_it] < a[m_border + r_it]) {
                    sort_block[l_it + r_it] = a[l_border + l_it];
                    l_it++;
                } else {
                    sort_block[l_it + r_it] = a[m_border + r_it];
                    r_it++;
                }
            }
            for (; l_border + l_it < m_border; ++l_it)
                sort_block[l_it + r_it] = a[l_border + l_it];
            for (; m_border + r_it < r_border; ++r_it)
                sort_block[l_it + r_it] = a[m_border + r_it];
            for (i = 0; i < l_it + r_it; ++i)
                a[l_border + i] = sort_block[i];
        }
}

void test_mergeSort() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<size_t> size_dist(1, 1'000); // на 10'000'000 працює швидше за встроєний на ~20%
    uniform_int_distribution<int> el_dist(-1'000, 1'000);
    const int n = 100;
    bitset<n> tests;
    for (int i = 0; i < n; ++i) {
        vector<int> arr(size_dist(gen));
        for (auto &el: arr)
            el = el_dist(gen);
        auto arr_manual(arr), arr_auto(arr);

        cout << boolalpha << format("test: {}\ninput array (size = {}): ", i + 1, arr.size()); // visual studio c++20
        ranges::copy(arr, ostream_iterator<int>(cout, " "));

        auto start = chrono::steady_clock::now();
        ranges::sort(arr_auto);
        auto end = chrono::steady_clock::now();
        chrono::duration<double> time1 = end - start;
        start = chrono::steady_clock::now();
        mergeSort(arr_manual);
        end = chrono::steady_clock::now();
        chrono::duration<double> time2 = end - start;

        cout << "\noutput auto array:\t\t";
        ranges::copy(arr_auto, ostream_iterator<int>(cout, " "));
        cout << "\noutput manual array:\t";
        ranges::copy(arr_manual, ostream_iterator<int>(cout, " "));
        cout << format("\ncorrectly sorted: {:<10}build-in time, s: {:<20}my time, s: {}\n\n",
                       arr_auto == arr_manual, time1.count(), time2.count());
        tests[i] = arr_auto == arr_manual;
    }
    cout << "all tests are good: " << tests.all() << "\n";
}

// Прочитати з клавіатури квадратну матрицю.
// Посортувати рядки матриці по зростанню на основі значень елементів першого стовпчика
int main() {
    size_t n{};
    cout << "Enter n: ";
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    cout << "Enter square matrix A[n*n]:\n";
    input_matrix(a);
    output_matrix(a);
    bool manual = true;
    if (manual)
        mergeSort(a);
    else
        ranges::sort(a); // C++20
    cout << "Matrix A sorted by first column:\n";
    output_matrix(a);
    // test_mergeSort();
    return 0;
}