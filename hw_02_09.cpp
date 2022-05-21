#include <iostream>

using namespace std;

int main() {
    int a, b;
    cout << "a,b:";
    cin >> a;
    cin >> b;
    int c = a;
    a = b;
    b = c;
    cout << "+c: " << a << " " << b;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "\n+/-: " << a << " " << b;
    a = a * b;
    b = a / b;
    a = a / b;
    cout << "\n* and /: " << a << " " << b;
    a = (a & ~b) | (~a & b);
    b = (a & ~b) | (~a & b);
    a = (a & ~b) | (~a & b);
    cout << "\n^ and v: " << a << " " << b;
    long long int d = a << 16 | b;
    d = static_cast<int>(d << 16 | d >> 16);
    a = static_cast<int>(d >> 16);
    b = static_cast<short>(d);
    cout << "\n-->: " << a << " " << b;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "\nmod2: " << a << " " << b;
    return 0;
}