#include <iostream>
using namespace std;
void length(int& n, const char* message) {
    do {
        cout << "n " << message <<  "=";
        cin >> n;
    } while (n <= 0);
}
void creat_set(int*& arr, int n, const char* message) {
    arr = new int[n];
    cout << message << endl;
    for (int i = 0; i < n; i++) {
        cout << "[" << i + 1 << "]=";
        cin >> arr[i];
    }
    cout << endl;
}
int max(int* arr, int n) {
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int min(int* arr, int n) {
    int min = arr[0];
    for (int i = 0; i < n; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    return min;
}


int max_of_two(int arg0, int arg1) {
    return arg0 > arg1 ? arg0 : arg1;
}

int min_of_two(int arg0, int arg1) {
    return arg0 < arg1 ? arg0 : arg1;
}

int delta(int arg0, int arg1)
{
    return -(min_of_two(arg0, arg1));
}



int hash_size(int* arr1, int* arr2, int n1, int n2) {
    return max_of_two(max(arr1, n1), max(arr2, n2)) - min_of_two(min(arr1, n1), min(arr2, n2)) + 1;
}


void simplecreating0(int*& arr1, int n) {
    arr1 = new int[n];
}

void simplecreating(int*& arr1, int*& arr2, int n) {
    arr1 = new int[n];
    arr2 = new int[n];
    for (int j = 0; j < n; j++) {
        arr1[j] = 0;
        arr2[j] = 0;
    }
}


int make_hash_elem(int arg, int delta) {
    return arg + delta;
}

void make_hash(int*& hash, int*& arr, int n, int delta) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            hash[make_hash_elem(arr[i], delta)] = 1;
        }
        else {
            hash[make_hash_elem(arr[i], delta)] = arr[i];
        }

    }
}


void unionity(int*& hash1, int*& hash2, int n, int& p, int delta, int*& first) {
    for (int i = 0; i < n; i++) {
        if ((hash1[i] != 0) || (hash2[i] != 0)) {
            p += 1;
            first[p - 1] = i - delta;
        }
    }
}

void intersectionity(int*& hash1, int*& hash2, int n, int& p, int delta, int*& second) {
    for (int i = 0; i < n; i++) {
        if ((hash1[i] != 0) && (hash2[i] != 0)) {
            p += 1;
            second[p - 1] = i - delta;
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



int main()
{
    int n1, n2;
    length(n1, "first");
    int* arr1;
    creat_set(arr1, n1, "FIRST");
    length(n2, "second");
    int* arr2;
    creat_set(arr2, n2, "SECOND");
    int our_delta = delta(min(arr1, n1), min(arr2, n2));
    int n = hash_size(arr1, arr2, n1, n2);
    int* hash1;
    int* hash2;
    simplecreating(hash1, hash2, n);
    
    int* first;
    int* second;
    simplecreating0(first, n);
    simplecreating0(second, n);
    int p1 = 0;
    int p2 = 0;
    make_hash(hash1, arr1, n1, our_delta);
    make_hash(hash2, arr2, n2, our_delta);
    unionity(hash1, hash2, n, p1, our_delta, first);
    intersectionity(hash1, hash2, n, p2, our_delta, second);
    cout << endl;
    print(first, p1, "union");
    print(second, p2, "intersection");
    return 0;
}











