#include <iostream>
using namespace std;

int fact(int n);

int main04()
{
    int n, sum = 0, factor_sum, count = 0, l = 1;
    cout << "n=";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        factor_sum = fact(i);
        sum += factor_sum;
    }
    cout << "sum=" << sum;
 
}

int fact(int n) {
    int fact_sum = 1;
    for (int i = 1; i <= n; i++) {
        fact_sum *= i;
    }
    return fact_sum;

}
