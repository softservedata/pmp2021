#include <iostream>
using namespace std;
int main() {
    unsigned long long int n, sum = 0, r = 1, k = 1, p= 1, s, d;
    cout << "1 * (2 + 3) * (4 + 5 + 6) * ... * (... + n)" << endl;
    cout << "Enter n >> ";
    cin >> n;
    for (int i = 1;i <= n;i++) {
        if (i - p == 0) {
            sum = sum + i;
            r = r * sum;
            sum = 0;
            k = k + 1;
            p = p + k;
        }
        else if (i == n) {
            sum = sum + i;
            r = r * sum;
        }
        else {
            sum += i;
        }
    }

    cout << "The result = " << r << endl;



    cout << "1 + (1 * 2) + (1 * 2 * 3) + ... + (1 * 2 * ... * n)"<< endl;
    cout << "Enter n >> ";
    cin >> n;
    s = 0;
    for (int j = 1; j <= n; ++j) {
        d = 1;
    for (int i = 1; i <= j; ++i) d *= i;
        s += d;
    }

    cout <<"The result = " << s << endl;
    
    
    
    cout << "1 + (2 * 3 * 4) + (3 * 4 * 5 * 6 * 7 * 8 * 9) + ... + (n * ... * n^2)" << endl;
    cout << "Enter n >> ";
    cin >> n;
    
    for (int i = 1;i <= n;i++) {
        for (int j = i;j <= i * i;j++) {
            r *= j;
        }
        sum += r;
        r = 1;
    }

    cout << "The result = " << sum << endl;

    return 0;

}
