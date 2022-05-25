#include <iostream>
#include <math.h>
using namespace std;

double rec_vkl(int n);

int main() {
    int n;
    cout << "n=";
    cin >> n;
    cout << "sin1 " << sin(1) << endl << "sin2 " << sin(sin(1)) + sin(2) << endl << "sin3 " << sin(sin(sin(1))) + sin(sin(2)) + sin(3) << endl;
    cout << "sin4 " << sin(sin(sin(sin(1)))) + sin(sin(sin(2))) + sin(sin(3)) + sin(4) <<endl << "sin5 "<<sin(sin(sin(sin(sin(1)))))+sin(sin(sin(sin(2))))+sin(sin(sin(3)))+sin(sin(4))+sin(5) << endl;
    cout << "rec_sin = " <<rec_vkl(n) << endl;
    system("PAUSE");
    return 0;
}

double rec_vkl(int n) {
    int l = n;
    double sum = 0;
    double k;
    for (int i = 1; i <= l; i++) {
        k=i;
        for (int j = n; j >=1;j--) {
            k = sin(k);
        }
        n--;
        sum += k;
    }
    return sum;
}

