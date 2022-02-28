#include <iostream>

using namespace std;

int main() {
    unsigned long long s, d, n, k;
    cout << "1 * (2 + 3) * (4 + 5 + 6) * ... * (... + n)\nn = ";
    cin >> n;
    d = 1, k = 0;
    for (int j = 1; k < n; ++j) {
        s = 0;
        for (int i = 0; i < j && k < n; ++i) s += ++k;
        d *= s;
    }
    cout << d << endl;
    //------------------------------------------------
    cout << "1 + (1 * 2) + (1 * 2 * 3) + ... + (1 * 2 * ... * n)\nn = ";
    cin >> n;
    s = 0;
    for (int j = 1; j <= n; ++j) {
        d = 1;
        for (int i = 1; i <= j; ++i) d *= i;
        s += d;
    }
    cout << s << endl;
    //-----------------------------------------------
    cout << "1 + (2 * 3 * 4) + (3 * 4 * 5 * 6 * 7 * 8 * 9) + ... + (n * ... * n^2)\nn = ";
    cin >> n;
    s = 0;
    for (int j = 1; j <= n; ++j) {
        d = 1;
        for (int i = j; i <= j * j; ++i) d *= i;
        s += d;
    }
    cout << s << endl;
    return 0;
}