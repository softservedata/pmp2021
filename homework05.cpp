// Написати код обчислення виразу S=sin(n)+sin(sin(n-1))+ sin(sin(sin(n-2)))+…+ sin(sin( … sin(1))).
// Використовуючи рекурентні вкладення;
// За допомогою рекурсії.
// Написати код обчислення суми S=n+(n-2)+(n-4)+..+0 за допомогою рекурсії.

#include <iostream>
#include <cmath>

using namespace std;
using ld = long double;

ld sum_of_sin_loop(int arg) {
    ld s{};
    for (int sinDepth = 0; sinDepth < arg; ++sinDepth) {
        ld sin_n = sin(arg - sinDepth);
        for (int currentDepth = 0; currentDepth < sinDepth; ++currentDepth)
            sin_n = sin(sin_n);
        s += sin_n;
    }
    return s;
}

ld sum_of_sin_recursion(int arg, int sinDepth = 1, int currentDepth = 0, bool calculation = false) {
    if (calculation)
        return currentDepth == 1 ? sin(arg) : sin(sum_of_sin_recursion(arg, sinDepth, currentDepth - 1, true));
    if (arg == 1)
        return sum_of_sin_recursion(arg, sinDepth, sinDepth, true);
    return sum_of_sin_recursion(arg, sinDepth, sinDepth, true) + sum_of_sin_recursion(arg - 1, sinDepth + 1, 0, false);
}

uint64_t recursive_sum(uint64_t x) {
    return (x <= 1) ? x : x + recursive_sum(x - 2);
}


int main() {
    // sin(n) + sin(sin(n - 1)) + sin(sin(sin(n - 2))) + ... + sin(sin(...sin(1)))
    int n{};
    cout << "sin(n) + sin(sin(n - 1)) + sin(sin(sin(n - 2))) + ... + sin(sin(...sin(1)))\n(n >= 1) n = ";
    cin >> n;
    cout << "with loop: " << sum_of_sin_loop(n) << "\t\twith recursion: " << sum_of_sin_recursion(n) << '\n';
    // n + (n - 2) + (n - 4) + ... + 0
    uint64_t m{};
    cout << "n + (n - 2) + (n - 4) + ... + (0 or 1)\n(n >= 0) n = ";
    cin >> m;
    cout << recursive_sum(m) << endl;
    return 0;
}