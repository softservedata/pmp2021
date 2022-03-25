#include <iostream>

using namespace std;
typedef unsigned long long ull;

int main() {
    ull p = 1, n;
    cout << "n = ";
    cin >> n;
    cout << "1 * (2 + 3) * (4 + 5 + 6) * ... * (... + n) = ";
    for (ull i = 1, k = 1, t = 1, s = 0; i <= k; ++i) {
        s += i;
        if (i == k) {
            k = min(k + ++t, n);
            p *= s;
            s = 0;
        }
    }
    cout << p << '\n';
    //------------------------------------------------
    cout << "1 + (1 * 2) + (1 * 2 * 3) + ... + (1 * 2 * ... * n) = ";
    ull s = 0;
    for (ull i = 1, f = 1; i <= n; ++i) {
        f *= i;
        s += f;
    }
    cout << s << '\n';
    //-----------------------------------------------
    cout << "1 + (2 * 3 * 4) + (3 * 4 * 5 * 6 * 7 * 8 * 9) + ... + (n * ... * n^2) = ";
    s = 0;
    for (ull i = 1; i <= n; ++i) {
        p = 1;
        for (ull j = i; j <= i * i; ++j) p *= j;
        s += p;
    }
    cout << s << endl;
    return 0;
}