#include <iostream>
#include <cmath>

using namespace std;

int Cin(){
    int n;
    cout << "Enter n number:";
    cin >> n;
    return n;
}

double my_sin(double x,double e = 0.0000001){
    double result = 0.0, add = x;
    int n = 1;
    do {
        result += add;
        n += 2;
        add = ((add * x * x) * (-1)) / (n*(n-1));
    } while (fabs(add) > e);

    return result;
}

double SinSum1a(int n){
    double sum = 0;
    double s;
    for (int i = 0; i < n; ++i) {
        s = my_sin(n - i);
        for (int j = 0; j < i; ++j){
            s = my_sin(s);
        }
        sum += s;
    }
    return sum;
}

double SinSum1b(int n, int i = 1, int j = 0, bool calc = false) {
    if (calc) {
        if (j == 1)
            return my_sin(n);
        return my_sin(SinSum1b(n, i, j - 1, true));
    }
    if (n == 1)
        return SinSum1b(n, i, i, true);
    return SinSum1b(n, i, i, true) + SinSum1b(n - 1, i + 1, 0, false);
}

double recursiveSum2(int n){
    if (n < 1) return 0;
    else return n + recursiveSum2(n - 2);
}

int main(){
    int n = Cin();
    cout << "For loop sin sum = " << SinSum1a(n) << endl;
    cout << "Recursive sin sum = " << SinSum1b(n) << endl;
    cout << "Recursive sum = " << recursiveSum2(n) << endl;

    return 0;
}

