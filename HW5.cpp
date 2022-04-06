#include<iostream>
using namespace std;

double sin_recursion(int n, int c) {
    double m;
    if (n == 1) {
        m = sin(1);
        for (int j = 1; j <= c; j++)
            m = sin(m);
        return m;
    }
    else {
        m = sin(n);
        for (int j = 1; j <= c; j++)
            m = sin(m);
        return m + sin_recursion(n - 1, c + 1);
    }
}
double sin_loop(int n) {
    double sum = 0, h;
    for (int i = 1; i <= n; i++) {
        h = sin(i);
        for (int j = 1; j <= n - i; j++)
            h = sin(h);
        sum += h;
    }
    return sum;
}
int sum(int n) {
    if (n <= 1)
        return n;
    return n + sum(n - 2);
}
int main() {
    cout << "homework 03-24" << endl;
    cout << "Task 1 " << endl;
    int n;
	cout << "n = ";
	cin >> n;
    cout << "a)" << endl;
    cout << "sum of sin with loop  " << sin_loop(n) << endl;
    cout << "b)" << endl;
    cout << "sum of sin with recursion  " << sin_recursion(n, 0) << endl;
    cout << "Task 2" << endl;
    int m;
    cout << "m = ";
    cin >> m;
    cout << "sum recursion:  "<< sum(m) << endl;   
}