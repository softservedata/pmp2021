#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Введіть рік: ";
    cin >> n;

    if (n % 4 == 0) {
        if (n % 100 == 0) {
            if (n % 400 == 0)
                cout << n << " - Високосний рік";
            else
                cout << n << " - Не високосний рік";
        }
        else
            cout << n << " - Високосний рік";
    }
    else
        cout << n << " - Не високосний рік";

    return 0;
}
