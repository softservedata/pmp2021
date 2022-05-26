#include<iostream>
#include <iomanip>
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
            cout << setw(2) << el << (&el == &row.back() ? '\n' : ' ');
}

template<class T>
auto transposeMatrix(const vector<vector<T>> &arr) {
    vector<vector<T>> res(arr.at(0).size(), vector<T>(arr.size()));
    for (int i = 0; i < res.size(); ++i)
        for (int j = 0; j < res[0].size(); ++j)
            res[i][j] = arr[j][i];
    return res;
}

template<class T>
bool check_if_symmetric(const vector<vector<T>> &arr) {
    for (int i = 0; i < arr.size(); ++i)
        for (int j = i + 1; j < arr.at(0).size(); ++j)
            if (arr[i][j] != arr[j][i])
                return false;
    return true;
}

int main() {
    int n{};
    cout << "Enter n: ";
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    cout << "Enter square matrix A[n*n]:\n";
    inputMatrix(a);
    outputMatrix(a);
    auto aT = transposeMatrix(a);
    cout << "\nA^T:\n";
    outputMatrix(aT);
    cout << boolalpha << "\nA is symmetric: " << check_if_symmetric(a) << endl;
    return 0;
}