#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    // додаткова змінна
    a = 2, b = 3;
    int c = a;
    a = b;
    b = c;
    cout << "додаткова змінна: " << a << " " << b << endl;
    // додавання та віднімання
    a = 2, b = 3;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "додавання та віднімання: " << a << " " << b << endl;
    // множення та ділення
    a = 2, b = 3;
    a = a * b;
    b = a / b;
    a = a / b;
    cout << "множення та ділення: " << a << " " << b << endl;
    // кон’юнкція та диз’юнкція
    a = 2, b = 3;
    a = (a & ~b) | (~a & b);
    b = (a & ~b) | (~a & b);
    a = (a & ~b) | (~a & b);
    cout << "кон’юнкція та диз’юнкція: " << a << " " << b << endl;
    // зсув
    a = 2, b = 3;
    long long int d = a << 16 | b;
    d = (int) d << 16 | d >> 16;
    a = d >> 16;
    b = (short int) d;
    cout << "зсув: " << a << " " << b << endl;
    // додавання по модулю 2
    a = 2, b = 3;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "додавання по модулю 2: " << a << " " << b << endl;
    return 0;
}
