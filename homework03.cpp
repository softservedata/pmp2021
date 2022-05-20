// Засобами C++ написати код для обчислення виразів

#include <iostream>

using namespace std;

int main() {
    uint64_t p = 1, n;
    cout << "n = ";
    cin >> n;
    cout << "1 * (2 + 3) * (4 + 5 + 6) * ... * (... + n) = ";
    for (uint64_t i = 1, k = 1, t = 1, s = 0; i <= k; ++i) {
        s += i;
        if (i == k) {
            k = min(k + ++t, n);
            p *= s;
            s = 0;
        }
    }
    cout << p;
    //------------------------------------------------
    cout << "\n1 + (1 * 2) + (1 * 2 * 3) + ... + (1 * 2 * ... * n) = ";
    uint64_t s{};
    for (uint64_t i = 1, f = 1; i <= n; ++i) {
        f *= i;
        s += f;
    }
    cout << s;
    //-----------------------------------------------
    cout << "\n1 + (2 * 3 * 4) + (3 * 4 * 5 * 6 * 7 * 8 * 9) + ... + (n * ... * n^2) = ";
    s = 0;
    for (uint64_t i = 1; i <= n; ++i) {
        p = 1;
        for (uint64_t j = i; j <= i * i; ++j)
            p *= j;
        s += p;
    }
    cout << s << endl;
    return 0;
}