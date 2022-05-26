#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

#define p 100043
#define precision 1e3

using namespace std;

template<class T>
void enterArray(vector<T> &arr) {
    for (auto &el: arr)
        cin >> el;
}

template<class T>
void printArray(const vector<T> &arr) {
    for (auto &el: arr)
        cout << el << (&el == &arr.back() ? '\n' : ' ');
}

template<class T>
vector<T> getArray() {
    size_t n{};
    cout << "Enter size of array (>0): ";
    cin >> n;
    vector<T> arr(n);
    cout << "Enter array: ";
    enterArray(arr);
    printArray(arr);
    return arr;
}

template<class T>
T getDelta(const vector<T> &a, const vector<T> &b) {
    return -min(*ranges::min_element(a), *ranges::min_element(b));
}

template<class T>
size_t hashCode(const T arg, const T delta) {
    return static_cast<size_t>((arg + delta) * static_cast<size_t>(precision));
}

template<class T>
size_t getHashSize(const vector<T> &a, const vector<T> &b, const T delta) {
    auto max_el = max(*ranges::max_element(a), *ranges::max_element(b));
    return min(hashCode(max_el, delta) + 1, static_cast<size_t>(p));
}

template<typename T>
vector<bool> getHashArray(const vector<T> &arr, const T delta, const size_t hash_size, bool out = false) {
    vector<bool> hash(hash_size);
    for (auto &el: arr)
        hash.at(hashCode(el, delta) % p) = true;
    if (out) {
        cout << "hash array:\n";
        for (auto &&el: hash)
            cout << el;
        cout << '\n';
    }
    return hash;
}

int main() {
    auto arr1 = getArray<double>(), arr2 = getArray<double>();
    auto delta = getDelta(arr1, arr2);
    auto hash_size = getHashSize(arr1, arr2, delta);
    cout << "delta = " << delta << "\thash size = " << hash_size << '\n';
    auto hash1 = getHashArray(arr1, delta, hash_size), hash2 = getHashArray(arr2, delta, hash_size);
    cout << "Sets of elements in arrays are equal: " << boolalpha << (hash1 == hash2) << endl;
    return 0;
}