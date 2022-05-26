//a - s=1*(2+3)*(4+5+6)*…*(…+n);
//b - s=1+(1*2)+(1*2*3)+⋯+(1*2*…*n);
//c - s=∑_(k=1)^n  k*(k+1)*…*k^2;
#include <iostream>

using namespace std;

int main() {
    int n;
    int m;
    int l;
    int d;
    int sum = 0;
    int sum1 = 0;
    int s = 1;
    int s1 = 1;
    int s2 = 1;
    int p = 1;
    int k = 1;
    cout << "Обчислення виразу а: " << endl;
    cout << "n = ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i - p == 0) {
            sum+= i;
            s*= sum;
            sum = 0;
            k+= 1;
            p+= k;
        }
        else if (i == n) {
            sum+= i;
            s*= sum;
        }
        else {
            sum += i;
        }
    }
    cout << "s = " << s << endl;


    cout << "Обчислення виразу b: " << endl;
    cout << "n = ";
    cin >> m;
    s1 = 0;
    for (int i = 1; i <= m; ++i) {
        d = 1;
        for (int j = 1; j <= i; ++j) {
            d *= j;
        }
        s1 += d;
    }
    cout << "s = " << s1 << endl;


    cout << "Обчислення виразу c: " << endl;
    cout << "n = ";
    cin >> l;
    for (int i = 1;i <= l;i++) {
        for (int j = i;j <= i * i; j++) {
            s2 *= j;
        }
        sum1 += s2;
        s2 = 1;
    }
    cout << "s = " << sum1 << endl;
    return 0;
}