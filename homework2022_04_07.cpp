#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void cin_array(vector<int> &arr) {
    for (auto &a: arr) {
        cin >> a;
    }
}

void cout_array(vector<int> &arr) {
    for (auto &a: arr) {
        cout << a << " ";
    }
    cout << "\n";
}

vector<int> init_array(){
    int n;
    cout << "n=";
    cin >> n;
    vector<int> arr(n);
    cout << "arr:\n";
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    return arr;
}

int mn_in_array(vector<int> &a){
    int mn = a[0];
    for(int e : a){
        mn = min(e, mn);
    }
    return mn;
}

int find_delta(vector<int> &a, vector<int> &b) {
    return -min(mn_in_array(a), mn_in_array(b));
}

int generate_hash_code(int val, int delta) {
    return val + delta;
}

int mx_in_array(vector<int> &a){
    int mx = a[0];
    for(int e : a){
        mx = max(e, mx);
    }
    return mx;
}

int generate_hash_size(vector<int> &a, vector<int> &b, int delta) {
    return generate_hash_code(max(mx_in_array(a), mx_in_array(b)), delta) + 1;
}

vector<bool> generate_hash_array(vector<int> &a, int delta, int hash_size) {
    vector<bool> hash_array(hash_size);
    for (auto e: a) {
        hash_array[generate_hash_code(e, delta)] = true;
    }
    return hash_array;
}

vector<bool> and_funciton(const vector<bool> &a, const vector<bool> &b) {
    vector<bool> c(min(a.size(), b.size()));
    for (size_t i = 0; i < min(a.size(), b.size()); ++i) {
        c[i] = a[i] & b[i];
    }
    return c;
}

vector<bool> or_function(vector<bool> &a, vector<bool> &b) {
    vector<bool> c(min(a.size(), b.size()));
    for (size_t i = 0; i < min(a.size(), b.size()); ++i) {
        c[i] = a[i] | b[i];
    }
    return c;
}

vector<int> generate_array_from_hash(vector<bool> &hash_array, int delta) {
    vector<int> new_array;
    new_array.reserve(hash_array.size());
    for (size_t i = 0; i < hash_array.size(); ++i) {
        if (hash_array[i]) {
            new_array.emplace_back(i - delta);
        }
    }
    return new_array;
}

bool is_equal(vector<int> &a, vector<int> &b){
    int delta = find_delta(a, b);
    int hash_size = generate_hash_size(a, b, delta);
    vector<bool> hash1 = generate_hash_array(a, delta, hash_size), hash2 = generate_hash_array(b, delta, hash_size);
    vector<bool> or_res = or_function(hash1, hash2);
    vector<int> arr_un = generate_array_from_hash(or_res, delta);
    if(arr_un == a){
        return true;
    } else{
        return false;
    }
}

int main() {
    vector<int> a = init_array(), b = init_array();
    cout << boolalpha << is_equal(a, b);
    return 0;
}