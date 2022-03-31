#include <iostream>
#include <cmath>

using namespace std;

//task 1 b
double sum(int n, int started_n){
    double tmp = sin(n);
    for(int i = n; i < started_n; ++i){
        tmp = sin(tmp);
    }
    if(n == 1){
        return tmp;
    }
    return tmp + sum(n - 1, started_n);
}

//task 1 a
double suma(int & n) {
    double sum = 0, tmp;
    for (int i = n; i >= 1; --i) {
        tmp = sin(i);
        for (int j = i; j < n; ++j) {
            tmp = sin(tmp);
        }
        sum += tmp;
    }
    return sum;
}

//task 2
int second_sum(int n){
    if(n <= 0){
        return 0;
    }
    return n + second_sum(n - 2);
}

int main () {
    int n;
    double ans;
    cin >> n;
    ans = suma(n);
    cout << ans << "\n";
    return 0;
}
