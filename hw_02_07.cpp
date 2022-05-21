#include <iostream>
using namespace std;
int main() {
    int a;
    cout << "Year:";
    cin >> a;
    if ((a % 4 == 0) or (a % 400 == 0) and (a % 100 != 0)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
