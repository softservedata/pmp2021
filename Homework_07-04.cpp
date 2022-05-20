//Порівняти вміст двох дійсних масивів. Використати за основу код із заняття. Створити hash функцію для дійсних чисел.
#include<iostream>

#define d 100003
using namespace std;

double *CreateArray(int n) {
    auto array = new double [n];
    return array;
}

double* ReadArray(double *array, int &n) {
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }
    return array;
}

double ObtainingMinimumValue(double* array, int n) { //мінімальний елемент
    int min = array[0];
    for (int i = 0; i < n; i++) {
        if (min > array[i]) {
            min = array[i];
        }
    }
    return min;
}

double ObtainingMaximumValue(double* array, int n) { //максимальний елемент
    int max = array[0];
    for (int i = 0; i < n; i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }
    return max;
}


double GetMaxTwo(double arg0, double arg1) {
    return arg0 > arg1 ? arg0 : arg1;
}

double GetMinTwo(double arg0, double arg1) {
    return arg0 < arg1 ? arg0 : arg1;
}
unsigned long long HashCode(auto arg, auto delta) {
    return arg + delta;
}

unsigned long long HashSize(double arg0, double arg1, auto delta){
    return GetMinTwo(static_cast<unsigned long long>(HashCode(GetMaxTwo(arg0, arg1),delta) + 1),  static_cast<unsigned long long>(d));
}

int GetDelta(double arg0, double arg1) {
    return -GetMinTwo(arg0, arg1);
}


auto* CreateHash(auto hashSize, int n, auto delta, double* arr){
    auto *hash = new double[hashSize];
    for (int i = 0; i < hashSize; i++) {
        hash[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        hash[(HashCode(arr[i], delta)) % d] = arr[i];
    }
    return hash;
}

bool IsEqual(double* hash1, double* hash2, double hashSize) {
    bool res = true;
    for (int i = 0; res && (i < hashSize); i++) {
        res = hash1[i] == hash2[i];
    }
    return res;
}

int Cin(){
    int n;
    cout << "Введіть кількість елементів в масиві: ";
    cin >> n;
    return n;
}

int main() {

    int n1 = Cin();
    auto arr1 = CreateArray(n1);
    cout << "Введіть елементи першого масиву: " << endl;
    ReadArray(arr1, n1); //7.2 12.9 2.3 1.3 4.9 11.1 1.3 2.9 ; 8
    int n2 = Cin();
    auto arr2 = CreateArray(n2);
    cout << "Введіть елементи другого масиву: " << endl;
    ReadArray(arr2, n2); //7.2 2.3 4.9 11.1 2.9 1.3 12.9 ; 7

    auto delta = GetDelta(ObtainingMinimumValue(arr1, n1), ObtainingMinimumValue(arr2, n2));
    auto hashSize = HashSize(ObtainingMaximumValue(arr1, n1), ObtainingMaximumValue(arr2, n2), delta);

    double* hash1 = CreateHash(hashSize, n1, delta, arr1);
    double* hash2 = CreateHash(hashSize, n2, delta, arr2);

    cout << "Рівність вмісту масивів: " << boolalpha << IsEqual(hash1, hash2, hashSize) << endl;

    delete[]arr1;
    delete[]arr2;
    delete[]hash1;
    delete[]hash2;
    return 0;
}