#include<iostream>
using namespace std;

void read_len (int& n, const char* message) {
    do {
        cout << "n" << message << "=";
        cin >> n;
    } while (n <= 0);
}

void read_arr (int*& arr, int n, const char* message) {
    arr = new int[n];
    cout << "Enter array " << message << endl;
    for (int i = 0; i < n; i++) {
        cout << message << "[" << i + 1 << "]=";
        cin >> arr[i];
    }
    cout << endl;
}

void create(int*& arr1, int*& arr2, int n) {
    arr1 = new int[n];
    arr2 = new int[n];
    for (int j = 0; j < n; j++) {
        arr1[j] = 0;
        arr2[j] = 0;
    }
}

int max_elem (int* arr, int n) {
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int min_elem (int* arr, int n) {
    int min = arr[0];
    for (int i = 0; i < n; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    return min;
}

int max2(int arg0, int arg1) {
    if (arg0 > arg1) return arg0;
    else return arg1;
}

int min2(int arg0, int arg1) {
    if (arg0 < arg1) return arg0;
    else return arg1;
}

int size_of_hash(int* arr1, int* arr2, int n1, int n2) {
    return max2(max_elem(arr1, n1), max_elem(arr2, n2)) - min2(min_elem(arr1, n1), min_elem(arr2, n2)) + 1;
}

int delta(int arg0, int arg1)
{
    return -(min2(arg0, arg1));
}

int hash_elem(int arg, int delta) {
    return arg + delta;
}

void hash_with_elems(int*& hash, int*& arr, int n, int delta) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            hash[hash_elem(arr[i], delta)] = 1;
        }
        else {
            hash[hash_elem(arr[i], delta)] = arr[i];
        }

    }
}

void unioni(int*& hash1, int*& hash2, int n, int& s, int delta, int*& uni) {
    for (int i = 0; i < n; i++) {
        if ((hash1[i] != 0) || (hash2[i] != 0)) {
            s += 1;
            uni[s - 1] = i - delta;
        }
    }
}

void inter_sectionity(int*& hash1, int*& hash2, int n, int& s, int delta, int*& inter) {
    for (int i = 0; i < n; i++) {
        if ((hash1[i] != 0) && (hash2[i] != 0)) {
            s += 1;
            inter[s - 1] = i - delta;
        }
    }
}

void print(int*& matr, int n, const char* message) {
    cout << message << endl;
    for (int i = 0; i < n; i++) {
        cout << matr[i] << "\t";
    }
    cout << endl;
}

int main011()
{
    int n1, n2;
    read_len(n1, "1");
    int* arr1;
    read_arr(arr1, n1, "A");
    read_len(n2, "2");
    int* arr2;
    read_arr(arr2, n2, "B");
    int delt = delta(min_elem(arr1, n1), min_elem(arr2, n2));
    int n = size_of_hash(arr1, arr2, n1, n2);
    int* hash1;
    int* hash2;
    create(hash1, hash2, n);
    cout << "delta = " << delta << ", hash length=" << n << endl;
    int* uni;
    int* inter;
    uni = new int[n];
    inter = new int[n];
    int p1 = 0;
    int p2 = 0;
    hash_with_elems(hash1, arr1, n1, delt);
    hash_with_elems(hash2, arr2, n2, delt);
    unioni(hash1, hash2, n, p1, delt, uni);
    inter_sectionity(hash1, hash2, n, p2, delt, inter);
    cout << endl;
    print(uni, p1, "union");
    print(inter, p2, "intersection");
    delete[] arr1;
    delete[] arr2;
    delete[] hash1;
    delete[] hash2;
    delete[] uni;
    delete[] inter;
    return 0;
}
