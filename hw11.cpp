#include <iostream>
using namespace std;
void length(int& b, const char* message) {
    do {
        cout << "b " << message <<  "=";
        cin >> b;
    } while (b <= 0);
}
void creat_set(int*& arr, int b, const char* message) {
    arr = new int[b];
    cout << message << endl;
    for (int i = 0; i < b; i++) {
        cout << "[" << i + 1 << "]=";
        cin >> arr[i];
    }
    cout << endl;
}
int max(int* arr, int b) {
    int max = arr[0];
    for (int i = 0; i < b; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int min(int* arr, int b) {
    int min = arr[0];
    for (int i = 0; i < b; i++) {
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



int hash_size(int* arr1, int* arr2, int b1, int b2) {
    return max_of_two(max(arr1, b1), max(arr2, b2)) - min_of_two(min(arr1, b1), min(arr2, b2)) + 1;
}


void simplecreating0(int*& arr1, int b) {
    arr1 = new int[b];
}

void simplecreating(int*& arr1, int*& arr2, int b) {
    arr1 = new int[b];
    arr2 = new int[b];
    for (int j = 0; j < b; j++) {
        arr1[j] = 0;
        arr2[j] = 0;
    }
}


int make_hash_elem(int arg, int delta) {
    return arg + delta;
}

void make_hash(int*& hash, int*& arr, int b, int delta) {
    for (int i = 0; i < b; i++) {
        if (arr[i] == 0) {
            hash[make_hash_elem(arr[i], delta)] = 1;
        }
        else {
            hash[make_hash_elem(arr[i], delta)] = arr[i];
        }

    }
}


void unionity(int*& hash1, int*& hash2, int b, int& p, int delta, int*& first) {
    for (int i = 0; i < b; i++) {
        if ((hash1[i] != 0) || (hash2[i] != 0)) {
            p += 1;
            first[p - 1] = i - delta;
        }
    }
}

void intersectionity(int*& hash1, int*& hash2, int b, int& p, int delta, int*& second) {
    for (int i = 0; i < b; i++) {
        if ((hash1[i] != 0) && (hash2[i] != 0)) {
            p += 1;
            second[p - 1] = i - delta;
        }
    }
}


void print(int*& matr, int b, const char* message) {
    cout << message << endl;
    for (int i = 0; i < b; i++) {
        cout << matr[i] << "\t";
    }
    cout << endl;
}



int main()
{
    int b1, b2;
    length(b1, "first");
    int* arr1;
    creat_set(arr1, b1, "FIRST");
    length(b2, "second");
    int* arr2;
    creat_set(arr2, b2, "SECOND");
    int our_delta = delta(min(arr1, b1), min(arr2, b2));
    int b = hash_size(arr1, arr2, b1, b2);
    int* hash1;
    int* hash2;
    simplecreating(hash1, hash2, b);
    
    int* first;
    int* second;
    simplecreating0(first, b);
    simplecreating0(second, b);
    int p1 = 0;
    int p2 = 0;
    make_hash(hash1, arr1, b1, our_delta);
    make_hash(hash2, arr2, b2, our_delta);
    unionity(hash1, hash2, b, p1, our_delta, first);
    intersectionity(hash1, hash2, b, p2, our_delta, second);
    cout << endl;
    print(first, p1, "union");
    print(second, p2, "intersection");
    return 0;
}