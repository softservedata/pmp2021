#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

#define eps 0.000000000000000001

using namespace std;

template<typename matr_type>
void matrix_cin(matr_type &matr) {
    for (auto &row: matr) {
        for (auto &a: row) {
            cin >> a;
        }
    }
}

template<typename matr_type>
void matrix_cout(matr_type &matr) {
    for (auto &row: matr) {
        for (auto &a: row) {
            cout << a << " ";
        }
        cout << "\n";
    }
}

bool check_matrix(const vector<vector<double>> &matr) {
    bool dominant = true;
    for (int i = 0; i < matr.size(); ++i) {
        double s_row = 0, diagonal = abs(matr[i][i]);
        for (int j = 0; j < matr[0].size(); ++j) {
            if (i != j) {
                s_row += abs(matr[i][j]);
            }
        }
        if (s_row - diagonal >= eps) {
            dominant = false;
            break;
        }
    }
    return dominant;
}

template<typename matr_type>
matr_type matrix_minus(matr_type &matr1, matr_type &matr2) {
    matr_type res(matr1);
    for (int i = 0; i < res.size(); ++i)
        for (int j = 0; j < res[0].size(); ++j)
            res[i][j] -= matr2[i][j];
    return res;
}

template<typename matr_type>
matr_type matrix_mulpitply(matr_type &matr1, matr_type &matr2) {
    matr_type res(int(matr1.size()), vector<int>(int(matr1.size()), 0));
    for (int i = 0; i < matr1.size(); ++i)
        for (int j = 0; j < matr2.size(); ++j)
            for (int k = 0; k < matr1.size(); ++k)
                res[i][j] += matr1[i][k] * matr2[k][j];
    return res;
}


int main() {
    //PART1
    cout << "PART1\nn=";
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
    cout << "enter a matrix:\n";
    matrix_cin(a);
    cout << "enter b matrix:\n";
    matrix_cin(b);
    auto matr_diff = matrix_minus(a, b);
    auto res = matrix_mulpitply(matr_diff, matr_diff);
    cout << "Result:\n";
    matrix_cout(res);
    //PART2
    cout << "PART2\nn=";
    cin >> n;
    vector<vector<double>> c(n, vector<double>(n));
    cout << "enter matrix:\n";
    matrix_cin(c);
    bool ans = check_matrix(c);
    cout << boolalpha << "Result=" << ans << "\n";
    return 0;
}