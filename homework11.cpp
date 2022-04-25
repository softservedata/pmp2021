#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;

void enterArray(vector<int> &arr) {
    for (auto &el: arr)
        cin >> el;
}

void printArray(const vector<int> &arr) {
    for (auto &el: arr)
        cout << el << (&el == &arr.back() ? '\n' : ' ');
}

auto getArray() {
    size_t n{};
    cout << "Enter size of array (>0): ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array: ";
    enterArray(arr);
    printArray(arr);
    return arr;
}

int getDelta(const vector<int> &a, const vector<int> &b) {
    return -min(*ranges::min_element(a), *ranges::min_element(b));
}

size_t hashCode(const int arg, const int delta) {
    return arg + delta;
}

size_t getHashSize(const vector<int> &a, const vector<int> &b, const int delta) {
    auto max_el = max(*ranges::max_element(a), *ranges::max_element(b));
    return hashCode(max_el, delta) + 1;
}

auto getHashArray(const vector<int> &arr, const int delta, const size_t hash_size) {
    vector<bool> hash(hash_size);
    for (auto &el: arr)
        hash[hashCode(el, delta)] = true;
    cout << "hash array:\n";
    for (const auto el: hash)
        cout << el;
    cout << '\n';
    return hash;
}

auto operator&(const vector<bool> &a, const vector<bool> &b) {
    vector<bool> c(a.size());
    for (size_t i = 0; i < a.size(); ++i)
        c[i] = a[i] & b[i];
    return c;
}

auto operator|(const vector<bool> &a, const vector<bool> &b) {
    vector<bool> c(a.size());
    for (size_t i = 0; i < a.size(); ++i)
        c[i] = a[i] | b[i];
    return c;
}

auto getNewArray(const vector<bool> &hash, const int delta) {
    vector<int> arr;
    arr.reserve(hash.size()); // резервую місце в пам'яті про запас
    for (size_t i = 0; i < hash.size(); ++i)
        if (hash[i])
            arr.emplace_back(i - delta); // push_back з конструктором
    return arr;
}

// Написати методи для об’єднання та перетину множин. Реалізувати алгоритми зі складністю O(n).

int main() {
    auto arr1 = getArray(), arr2 = getArray();
    auto delta = getDelta(arr1, arr2);
    auto hash_size = getHashSize(arr1, arr2, delta);
    auto hash1 = getHashArray(arr1, delta, hash_size), hash2 = getHashArray(arr2, delta, hash_size);
    auto intersection_arr = getNewArray(hash1 & hash2, delta), union_arr = getNewArray(hash1 | hash2, delta);
    cout << "union: ";
    printArray(union_arr);
    cout << "intersection: ";
    printArray(intersection_arr);
    cout << endl;
    return 0;
}