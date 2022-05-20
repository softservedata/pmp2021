#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void matrix_cin(vector<vector<T>> &matr) {
    for (auto &row: matr) {
        for (auto &a: row) {
            cin >> a;
        }
    }
}

template<typename T>
void matrix_cout(vector<vector<T>> &matr) {
    for (auto &row: matr) {
        for (auto &a: row) {
            cout << a << " ";
        }
        cout << "\n";
    }
}

template<typename T>
vector<vector<T>> init_matrix(){
    int n;
    cout << "n=";
    cin >> n;
    vector<vector<T>> a(n, vector<T>(n, 0));
    cout << "enter matrix:\n";
    matrix_cin(a);
    return a;
}

template <typename T>
void merge(vector<T> &row, int left, int mid, int right)
{
    int size_array_one = mid - left + 1, size_array_two = right - mid;

    vector<T> left_array(size_array_one), right_array(size_array_two);

    for (auto i = 0; i < size_array_one; i++) {
        left_array[i] = row[left + i];
    }
    for (auto j = 0; j < size_array_two; j++) {
        right_array[j] = row[mid + 1 + j];
    }

    int index_sub_array_one = 0, index_sub_array_two = 0, index_merged = left;

    while (index_sub_array_one < size_array_one && index_sub_array_two < size_array_two) {
        if (left_array[index_sub_array_one] <= right_array[index_sub_array_two]) {
            row[index_merged] = left_array[index_sub_array_one];
            index_sub_array_one++;
        }
        else {
            row[index_merged] = right_array[index_sub_array_two];
            index_sub_array_two++;
        }
        index_merged++;
    }

    while (index_sub_array_one < size_array_one) {
        row[index_merged] = left_array[index_sub_array_one];
        index_merged++, index_sub_array_one++;
    }

    while (index_sub_array_two < size_array_two) {
        row[index_merged] = right_array[index_sub_array_two];
        index_merged++, index_sub_array_two++;
    }
}

template <typename T>
void merge_sort(vector<T> &row, int begin, int end)
{
    if (begin >= end){
        return;
    }

    int mid = begin + (end - begin) / 2;
    merge_sort(row, begin, mid);
    merge_sort(row, mid + 1, end);
    merge(row, begin, mid, end);
}

template <typename T>
void sort_rows(vector<vector<T>> &a){
    for (vector<T> &row : a){
        merge_sort(row, 0, row.size() - 1);
    }
}

int main(){
    vector<vector<int>> matrix = init_matrix<int>();
    sort_rows(matrix);
    cout << "Sorted matrix:\n";
    matrix_cout(matrix);
}