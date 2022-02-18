#include <iostream>

using namespace std;

int main() {
    int year;
    cin >> year;
    cout << year;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                cout << " високосний";
            } else cout << " не високосний";
        } else cout << " високосний";
    } else cout << " не високосний";
    cout << endl;
    return 0;
}