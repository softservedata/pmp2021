//Написати код обчислення виразу S=sin(n)+sin(sin(n-1))+ sin(sin(sin(n-2)))+…+ sin(sin( … sin(1))).
//Використовуючи рекурентні вкладення; За допомогою рекурсії.
//Написати код обчислення суми S=n+(n-2)+(n-4)+..+0 за допомогою рекурсії.
#include <iostream>
#include <cmath>

using namespace std;

long double RecurrentAmount(int n) {
    long double SumForTask1 = 0;
    long double InternalSinus;
    for( int i = 1; i <= n; i++ ) {
        InternalSinus = sin(i);
        for( int j = 1; j <= n-i; j++ ) {
            InternalSinus = sin(InternalSinus);
        }
        SumForTask1+= InternalSinus ;
    }
    return SumForTask1;
}
long double RecursiveAmount(int n, int Count) {
    if (n == 1) {
        long double m;
        m = sin(1);
        for( int i = 1; i <= Count; i++ ) {
            m = sin(m);
        }
        return m ;
    }
    else {
        long double InternalSinus;
        InternalSinus = sin(n);
        for ( int j = 1; j <= Count; j++) {
            InternalSinus = sin(InternalSinus);
        }
        return InternalSinus + RecursiveAmount(n - 1, Count + 1);
    }
}
int SumOfTask2(int m) {
    if ( m <= 0 ) {
        return 0;
    }
    return m + SumOfTask2( m - 2 );
}

long double RecurrentAmount(int n);
long double RecursiveAmount(int n, int Count);
int main() {
    int n;
    int Count = 0;
    cout << "Введіть n для Task1: ";
    cin >> n;
    cout << "Результат, використовуючи рекурентні вкладення: " << RecurrentAmount(n) << endl;
    cout << "Результат, використовуючи рекурсію: " << RecursiveAmount(n, Count) << endl;
    int m;
    int SForTask2;
    cout << "Введіть n для Task2: ";
    cin >> m;
    SForTask2 = SumOfTask2(m);
    cout << SForTask2;
}
