#include <iostream>
#include <vector>

using namespace std;

auto read_array() {
    size_t n{};
    cout << "Enter size of array (>0):";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array:\n";
    for (auto &el: arr)
        cin >> el;
    return arr;
}

void print_array(const vector<int> &arr) {
    for (auto &el: arr)
        cout << el << (&el == &arr.back() ? '\n' : ' ');
}

auto get_max(vector<int> arr){
    int max = arr[0];
    for (int i = 0; i < arr.size(); ++i){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

auto get_min(vector<int> arr){
    int min = arr[0];
    for (int i = 0; i < arr.size(); ++i){
        if (min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}

auto get_delta(const vector<int> &a, const vector<int> &b) {
    return -min(get_min(a), get_min(b));
}

size_t hash_code(const int arg, const int delta) {
    return arg + delta;
}

size_t get_hash_size(const vector<int> &a, const vector<int> &b, const int delta) {
    auto max_el = max(get_max(a), get_max(b));
    return hash_code(max_el, delta) + 1;
}

auto create_hash_array(const size_t hash_size, const int delta, const vector<int> &arr){
    vector<bool> hash(hash_size);
    for (auto &el: arr)
        hash[hash_code(el, delta)] = true;
    return hash;
}

auto my_union(const vector<bool> &a, const vector<bool> &b) {
    vector<bool> c(a.size());
    for (size_t i = 0; i < a.size(); ++i)
        c[i] = a[i] | b[i];
    return c;
}

auto my_intersection(const vector<bool> &a, const vector<bool> &b) {
    vector<bool> c(a.size());
    for (size_t i = 0; i < a.size(); ++i)
        c[i] = a[i] & b[i];
    return c;
}

auto get_new_array(const vector<bool> &hash, const int delta) {
    vector<int> arr;
    for (size_t i = 0; i < hash.size(); ++i)
        if (hash[i])
            arr.push_back(i - delta);
    return arr;
}

int main() {
    auto arr1 = read_array(), arr2 = read_array();
    auto delta = get_delta(arr1, arr2);
    auto hash_size = get_hash_size(arr1, arr2, delta);
    auto hash1 = create_hash_array(hash_size, delta, arr1), hash2 = create_hash_array(hash_size, delta, arr2);
    auto union_arr = get_new_array(my_union(hash1, hash2), delta), intersection_arr = get_new_array(my_intersection(hash1, hash2), delta);
    cout << "Union: "; print_array(union_arr);
    cout << "Intersection: "; print_array(intersection_arr);
    cout << endl;
    return 0;
}
