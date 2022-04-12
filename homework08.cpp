#include <iostream>
#include <vector>
#include <algorithm>

#define p 100043 // max hash array size, period of collisions
#define precision 1e3 // distance between 2 neighbouring real numbers, minimal step of distinguishing

using namespace std;

template<typename T>
auto enter_array(vector<T> &arr) {
    for (auto &el: arr)
        cin >> el;
}

template<typename T>
auto print_array(const vector<T> &arr) {
    for (const auto &el: arr)
        cout << el << (&el == &arr.back() ? '\n' : ' ');
}

template<typename T>
auto getArray() {
    size_t n{};
    cout << "Enter size of array: ";
    cin >> n;
    vector<T> arr(n);
    cout << "Enter array: ";
    enter_array(arr);
    print_array(arr);
    return arr;
}

template<typename T>
auto get_delta(const vector<T> &a, const vector<T> &b) {
    return -min(*min_element(a.begin(), a.end()), *min_element(b.begin(), b.end()));
}

template<typename T>
auto hashCode(const T arg, const T delta) {
    return static_cast<size_t>((arg + delta) * precision);
}

template<typename T>
auto get_hash_size(const vector<T> &a, const vector<T> &b, const T delta) {
    auto max_el = max(*max_element(a.begin(), a.end()), *max_element(b.begin(), b.end()));
    return min(hashCode(max_el, delta) + 1, static_cast<size_t>(p));
}

template<typename T>
auto get_hash_array(const vector<T> &arr, const T delta, const size_t hash_size, bool out = false) {
    vector<bool> hash(hash_size); // optimization , 1 bit not byte per element
    for (const auto &el: arr)
        hash.at(hashCode(el, delta) % p) = true; // collisions are possible
    if (out) {
        cout << "hash array:\n";
        for (const auto &el: hash) // function print_array not possible because of vector<bool> 1 bit optimization
            cout << el;
        cout << '\n';
    }
    return hash;
}

// Порівняти вміст двох дійсних масивів. Використати за основу код із заняття. Створити hash функцію для дійсних чисел.

int main() {
    auto arr1 = getArray<double>(), arr2 = getArray<double>();
    auto delta = get_delta(arr1, arr2);
    auto hash_size = get_hash_size(arr1, arr2, delta);
    cout << "delta = " << delta << "\thash size = " << hash_size << '\n';
    auto hash1 = get_hash_array(arr1, delta, hash_size), hash2 = get_hash_array(arr2, delta, hash_size);
    cout << "Sets of elements in arrays are equal: " << boolalpha << (hash1 == hash2) << endl;
    return 0;
}