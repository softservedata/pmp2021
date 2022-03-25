#include <iostream>
#include <cmath>

long double sum_of_sin_loop(int arg) {
    long double s{};
    for (int sinDepth = 0; sinDepth < arg; ++sinDepth) {
        long double sin_n = std::sin(arg - sinDepth);
        for (int currentDepth = 0; currentDepth < sinDepth; ++currentDepth)
            sin_n = std::sin(sin_n);
        s += sin_n;
    }
    return s;
}

long double sum_of_sin_recursion(int arg, int sinDepth = 1, int currentDepth = 0, bool calculation = false) {
    if (calculation) {
        if (currentDepth == 1)
            return std::sin(arg);
        return std::sin(sum_of_sin_recursion(arg, sinDepth, currentDepth - 1, true));
    }
    if (arg == 1)
        return sum_of_sin_recursion(arg, sinDepth, sinDepth, true);
    return sum_of_sin_recursion(arg, sinDepth, sinDepth, true) + sum_of_sin_recursion(arg - 1, sinDepth + 1, 0, false);
}

unsigned long long recursive_sum(unsigned long long x) {
    if (x <= 1)
        return x;
    return x + recursive_sum(x - 2);
}


int main() {
    // sin(n) + sin(sin(n - 1)) + sin(sin(sin(n - 2))) + ... + sin(sin(...sin(1)))
    int n{};
    std::cout << "sin(n) + sin(sin(n - 1)) + sin(sin(sin(n - 2))) + ... + sin(sin(...sin(1)))\n(n >= 1) n = ";
    std::cin >> n;
    std::cout << "with loop: " << sum_of_sin_loop(n) << "\t\twith recursion: " << sum_of_sin_recursion(n) << '\n';
    // ----------------------------------------------------------------------------------------------------------------
    // n + (n - 2) + (n - 4) + ... + 0
    unsigned long long m{};
    std::cout << "n + (n - 2) + (n - 4) + ... + 0 or 1\n(n >= 0) n = ";
    std::cin >> m;
    std::cout << recursive_sum(m) << std::endl;
    return 0;
}