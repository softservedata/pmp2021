#include <iostream>
#include <vector>

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

template<typename T>
auto matrix_trans(const vector<vector<T>> &matr) {
    vector<vector<T>> res(matr[0].size(), vector<T>(matr.size()));
    for (int i = 0; i < matr.size(); ++i) {
        for (int j = 0; j < matr[0].size(); ++j) {
            res[i][j] = matr[j][i];
        }
    }
    return res;
}

template<typename T>
bool is_symmetric(const vector<vector<T>> &matr) {
    for (int i = 0; i < matr.size(); ++i) {
        for (int j = i + 1; j < matr[0].size(); ++j) {
            if (matr[i][j] != matr[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    //PART1
    int n;
    cout << "PART1\nn=";
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    cout << "Enter a matrix:\n";
    matrix_cin(a);
    auto aT = matrix_trans(a);
    cout << "\nResult:\n";
    matrix_cout(aT);
    //PART2
    cout << "PART2\nn=";
    cin >> n;
    vector<vector<int>> b(n, vector<int>(n));
    cout << "Enter matrix:\n";
    matrix_cin(b);
    cout << boolalpha << "\nResult: " << is_symmetric(b) << "\n";
    return 0;
}