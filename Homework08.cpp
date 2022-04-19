#include <iostream>

#define d 100003 // For hash division method, in fact that is hash table size. It must be any prime
// number, but taking into account the collisions which depends on k and numbers input.
#define k 1e3 // For independent and uniform distribution of numbers

using namespace std;

double get_max(double *arr, int n){
    auto max = *arr;
    for (int i = 0; i < n; ++i){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

double get_min(double *arr, int n){
    auto min = *arr;
    for (int i = 0; i < n; ++i){
        if (min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}

double get_max_two(double arg0, double arg1){
    return arg0 > arg1 ? arg0 : arg1;
}

double get_min_two(double arg0, double arg1){
    return arg0 < arg1 ? arg0 : arg1;
}

auto get_delta(double arg0, double arg1){
    return -get_min_two(arg0, arg1);
}

unsigned long long  hash_code(auto arg, auto delta){
    return static_cast<unsigned long long>((arg + delta) * static_cast<unsigned long long>(k));
}

unsigned long long get_hash_size(double arg0, double arg1, auto delta){
    return get_min_two(static_cast<unsigned long long>(hash_code(get_max_two(arg0, arg1),delta) + 1),  static_cast<unsigned long long>(d));
}

auto* create_hash(auto hash_size, int n, auto delta, double* arr){
    auto *hash = new double[hash_size];
    for (int i = 0; i < hash_size; ++i) hash[i] = 0;
    for (int i = 0; i < n; ++i){
        hash[(hash_code(arr[i], delta)) % d] = arr[i];
    }
    return hash;
}

bool is_Equal(auto* hash0, auto* hash1, auto hash_size){
    bool result = true;
    for (int i = 0; result && (i < hash_size); ++i){
        result = hash0[i] == hash1[i];
    }
    return result;
}

double* read_array(int &n){
    cout << "Enter array:\n";
    auto arr = new double[n];
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    return arr;
}

int Cin(){
    int n;
    cout << "Enter n:";
    cin >> n;
    return n;
}

int main08(){
    int n1 = Cin();
    auto *arr1 = read_array(n1);
    int n2 = Cin();
    auto *arr2 = read_array(n2);

    auto delta = get_delta(get_min(arr1, n1), get_min(arr2, n2));
    auto hash_size = get_hash_size(get_max(arr1, n1), get_max(arr2, n2), delta);

    double *hash1 = create_hash(hash_size, n1, delta, arr1);
    double *hash2 = create_hash(hash_size, n2, delta, arr2);

    cout << "Is equal: " << boolalpha << is_Equal(hash1, hash2, hash_size) << endl;

    delete [] arr1; delete [] arr2; delete [] hash1; delete [] hash2;

    return 0;
}