#include <iostream>
#include <math.h>
using namespace std;

double rec_sin1(int n,int k);
double rec_sin2(int n,int k);

int main() {
    int n,k;
    cout << "n=";
    cin >> n;
    k = n;
    cout << "sin1 " << sin(1) << endl << "sin2 " << sin(sin(1)) + sin(2) << endl << "sin3 " << sin(sin(sin(1))) + sin(sin(2)) + sin(3) << endl;
    cout << "sin4 " << sin(sin(sin(sin(1)))) + sin(sin(sin(2))) + sin(sin(3)) + sin(4)<< endl<< "sin5 "<<sin(sin(sin(sin(sin(1)))))+sin(sin(sin(sin(2))))+sin(sin(sin(3)))+sin(sin(4))+sin(5) << endl;
    cout << "rec_sin = " <<rec_sin2(n,k) << endl;
    system("PAUSE");
    return 0;
}

double rec_sin1(int n,int k) {
    if (n == k) return sin(k);
    else {
        k--;
        return sin(rec_sin1(n, k));
    }
}

double rec_sin2(int n,int k) {
    if (n == 0) return 0;
    return rec_sin1(n, k) + rec_sin2(n - 1, k);
}